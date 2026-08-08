// =============================================================================
// Mission_FormatDialogTokenValue_Inferred  (Ghidra: FUN_005792d0)
// -----------------------------------------------------------------------------
// Stable ID: aa_005792d0
// Address:   0x005792d0–0x00579584 (autoassault.exe, image base 0x400000)
// Body:      693 B (0x2B5); jump table @ 0x00579588 (7 entries); pad CC
// System:    missions-progression
// Generated: 2026-08-05 R10-014 dual (live Ghidra decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow + byte seals.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Format one mission-dialog token value into a caller out-buffer.
//   Switches on tokenDesc->type (0..6): float/variable, object name, class,
//   race, faction (or stub string), entity display name, class-from-character.
//
// ABI (bytes-sealed):
//   __thiscall  ECX = context*  (TFID compared at context+0x30)
//   5 stack dwords; RET 0x14; returns uint8 success in AL (1/0)
//
// SOLE CALLER:
//   FUN_00579fb0 @ 0x0057a080 — mission dialog token-walk string builder
//
// DUALED CALLEES:
//   Character_GetRaceDisplayName_Inferred  0x00521800
//   Character_GetClassDisplayName_Inferred 0x00521900
//
// EVIDENCE STRING:
//   "!Non-Character Faction not implemented yet!" @ 0x009d4104
//
// Retired scaffolds:
//   Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_Dialog_has_005792d0
//   Named_Non_Character_Faction_not_implemented_yet
// =============================================================================

#include <cstdint>
#include <cstring>
#include <cstdio>

// External / dualed (names from reconstruction registry)
extern "C" void *FUN_007a69d0();
extern "C" char *FUN_007a6de0(const char *src, int maxLen /* often -1 */);
extern "C" char TFID_EqualsObjectId(void *a, void *b);
extern "C" char CVOGMap_LookupVariable(uint32_t varId, float *outValue, void *mapOrChar);
extern "C" char *Character_GetRaceDisplayName_Inferred(void *character /* ECX */);
extern "C" char *Character_GetClassDisplayName_Inferred(void *character /* ECX */);

struct MissionDialogTokenDesc_Inferred {
  uint8_t type;       // +0  (0..6)
  uint8_t _pad[3];
  uint32_t varId;     // +4  case 0 lookup key
  float embeddedFloat;// +8  case 0 when TFID matches
};

// Nested vtbl helpers — offsets sealed; product names open.
static inline char *Object_GetName_vtbl160(void *obj) {
  // decompiler: *( **(obj+4)+4 + obj + 4 )  then call [vtbl+0x160]
  auto *p = reinterpret_cast<uint8_t *>(obj);
  int mid = *reinterpret_cast<int *>(*reinterpret_cast<int *>(p + 4) + 4);
  auto **vtbl = *reinterpret_cast<void ***>(p + mid + 4);
  using Fn = char *(__thiscall *)(void *);
  return reinterpret_cast<Fn>(vtbl[0x160 / 4])(obj);
}

static inline int Character_Query_vtbl210(void *obj, int a = 0, int b = 0) {
  auto **vtbl = *reinterpret_cast<void ***>(obj);
  using Fn = int(__thiscall *)(void *, int, int);
  // call sites push varying arity; model as 0/2-arg gate
  return reinterpret_cast<Fn>(vtbl[0x210 / 4])(obj, a, b);
}

static inline void StrCopyOut(char *dst, const char *src) {
  if (src == nullptr) {
    *dst = '\0';
    return;
  }
  do {
    char c = *src++;
    *dst++ = c;
    if (c == '\0') return;
  } while (true);
}

uint8_t __thiscall Mission_FormatDialogTokenValue_Inferred(
    void *context,
    char *outBuf,
    char *formatOrTokenText,
    MissionDialogTokenDesc_Inferred *tokenDesc,
    void *objectOrFloatSlot,
    void *mapOrCharacter)
{
  void *tlsRing = FUN_007a69d0();
  (void)tlsRing;

  switch (tokenDesc->type) {
  case 0: {
    float value = 0.0f;
    if (mapOrCharacter == nullptr ||
        TFID_EqualsObjectId(
            reinterpret_cast<char *>(mapOrCharacter) + 0x160,
            reinterpret_cast<char *>(context) + 0x30) == 0) {
      if (CVOGMap_LookupVariable(tokenDesc->varId, &value, mapOrCharacter) == 0)
        return 0;
    } else {
      value = tokenDesc->embeddedFloat;
    }
    std::sprintf(outBuf, formatOrTokenText, static_cast<double>(value));
    return 1;
  }

  case 1: {
    if (objectOrFloatSlot == nullptr)
      return 0;
    StrCopyOut(outBuf, Object_GetName_vtbl160(objectOrFloatSlot));
    return 1;
  }

  case 2: {
    if (objectOrFloatSlot == nullptr)
      return 0;
    char *name = Character_GetClassDisplayName_Inferred(objectOrFloatSlot);
    StrCopyOut(outBuf, FUN_007a6de0(name, -1));
    return 1;
  }

  case 3: {
    if (objectOrFloatSlot == nullptr)
      return 0;
    char *name = Character_GetRaceDisplayName_Inferred(objectOrFloatSlot);
    StrCopyOut(outBuf, FUN_007a6de0(name, -1));
    return 1;
  }

  case 4: {
    if (mapOrCharacter != nullptr && Character_Query_vtbl210(mapOrCharacter) != 0) {
      void *ch = reinterpret_cast<void *>(
          Character_Query_vtbl210(mapOrCharacter, 0, -1));
      char *name = Character_GetRaceDisplayName_Inferred(ch);
      StrCopyOut(outBuf, FUN_007a6de0(name, -1));
      return 1;
    }
    StrCopyOut(outBuf,
               FUN_007a6de0("!Non-Character Faction not implemented yet!", -1));
    return 1;
  }

  case 5: {
    if (mapOrCharacter == nullptr)
      return 0;
    if (Character_Query_vtbl210(mapOrCharacter) != 0) {
      void *ch = reinterpret_cast<void *>(
          Character_Query_vtbl210(mapOrCharacter, 0, 0));
      char *name = Object_GetName_vtbl160(ch);
      StrCopyOut(outBuf, FUN_007a6de0(name, -1));
      return 1;
    }
    // non-character: string at *(this+0xA8)+0x40  (index 0x2a of int*)
    auto *asInts = reinterpret_cast<int *>(mapOrCharacter);
    char *fallback = reinterpret_cast<char *>(asInts[0x2a]) + 0x40;
    StrCopyOut(outBuf, FUN_007a6de0(fallback, -1));
    return 1;
  }

  case 6: {
    // Machine seal: on character path, write class name then return 0.
    if (mapOrCharacter != nullptr && Character_Query_vtbl210(mapOrCharacter) != 0) {
      void *ch = reinterpret_cast<void *>(
          Character_Query_vtbl210(mapOrCharacter, 0, -1));
      char *name = Character_GetClassDisplayName_Inferred(ch);
      StrCopyOut(outBuf, FUN_007a6de0(name, -1));
      return 0;
    }
    *outBuf = '\0';
    return 0;
  }

  default:
    return 0;
  }
}

// Ghidra twin export name
uint8_t __thiscall FUN_005792d0(
    void *context,
    char *outBuf,
    char *formatOrTokenText,
    MissionDialogTokenDesc_Inferred *tokenDesc,
    void *objectOrFloatSlot,
    void *mapOrCharacter)
{
  return Mission_FormatDialogTokenValue_Inferred(
      context, outBuf, formatOrTokenText, tokenDesc,
      objectOrFloatSlot, mapOrCharacter);
}
