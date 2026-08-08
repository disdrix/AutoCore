// =============================================================================
// Item_PatenteeMatchesCharacterOrEmpty_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00522950
// Address:   0x00522950  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer / Reverse-Engineer patentee gate
// Wave:      MEGA-108 (2026-08-05)
// Exactness: Behavior-preserving rewrite of decompiler control flow + sealed ABI.
// Bit-for-bit vs retail EXE: DEFERRED. Runtime / differential: OPEN.
// =============================================================================
//
// PURPOSE:
//   Predicate used by item-hover RE status and Inv Reverse-Engineer action:
//   return true if the item has an empty "Patented By" C-string at +0x101, or
//   if that string matches the character name from MI-adjusted vtbl+0x160
//   (case-insensitive via _stricmp). Null item → false.
//
// ABI (sealed):
//   thiscall  ECX = Character*
//   stack     Item* item
//   return    AL bool (0/1)
//   cleanup   RET 4  (C2 04 00) at all three exits
//
// Body: 0x00522950–0x005229b1 inclusive (98 B / 0x62)
// Full hex: see raw MEGA-108 re-verify append
//
// Does NOT: broken-bit check, stack gate, recipe lookup, craft-material type,
// cargo ownership — parents (FUN_0085ce20 / FUN_0093d110 / …) own those.
// =============================================================================

#include <cstdint>
#include <cstring>

// Forward shapes — product types open
struct Character;
struct Item;

// Character MI path → secondary base; virtual at +0x160 returns char* name.
// Product English open → treated as GetName-class accessor.
typedef char *(__thiscall *Character_GetName_Vtbl160_fn)(void *adjustedThis);

static char *Character_CallGetName_Vtbl160(Character *character)
{
  // Matches retail:
  //   mov eax,[ecx+4]; mov edx,[eax+4];
  //   mov eax,[edx+ecx+4]; lea ecx,[edx+ecx+4]; call [eax+0x160]
  auto *asBytes = reinterpret_cast<uint8_t *>(character);
  auto *vb = *reinterpret_cast<uint8_t **>(asBytes + 4);
  auto *adjBase = *reinterpret_cast<uint8_t **>(vb + 4);
  auto *adjusted = adjBase + reinterpret_cast<uintptr_t>(character) + 4;
  auto **vtbl = *reinterpret_cast<void ***>(adjusted);
  auto fn = reinterpret_cast<Character_GetName_Vtbl160_fn>(vtbl[0x160 / 4]);
  return fn(adjusted);
}

// item+0x101 : patented-by C-string (UI: "Patented By: " in FUN_00847240)
bool __thiscall Item_PatenteeMatchesCharacterOrEmpty_Inferred(
    Character *character,
    Item *item)
{
  if (item == nullptr) {
    return false;
  }

  char *patentee = reinterpret_cast<char *>(item) + 0x101;
  char *scan = patentee;
  char c;
  do {
    c = *scan;
    scan = scan + 1;
  } while (c != '\0');

  // Empty string: scan == patentee+1 == item+0x102 → skip compare, allow.
  if (scan != reinterpret_cast<char *>(item) + 0x102) {
    char *characterName = Character_CallGetName_Vtbl160(character);
    int cmp = _stricmp(patentee, characterName);
    if (cmp != 0) {
      return false;
    }
  }

  return true;
}
