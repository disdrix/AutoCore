// =============================================================================
// UI_AppendCraftRequirements_Inferred  (named twin of FUN_00846820)
// -----------------------------------------------------------------------------
// Stable ID: aa_00846820
// Address:   0x00846820  (autoassault.exe, image base 0x400000)
// Body:      0x00846820 – 0x00847232 (4115 B; SEH + sub esp,0x19c; plain ret)
// System:    skills-abilities — client craft/recipe requirements UI formatter
// Dual wave: R11-028 OWN-ONLY 2026-08-05
// Twin:      FUN_00846820.cpp
// Rejected:  Named_Required_Combat_00846820
// =============================================================================

// ROLE (High — product strings + sealed CF):
//   Build the multi-section requirements / ingredients block for a craftable
//   item or recipe row on a UI text object. Not a server authority check.
//
// ABI:
//   ESI  = UIText*  (vfuncs +0x224 colored append, +0x250 plain, +0x22c discipline)
//   arg0 = ItemOrCraft*  (stack)
//   returns int lineCount; 0 if g_localPlayer null.
//
// Sections (in order):
//   1. \nINGREDIENTS\n           (def slots +0x498..+0x4a8)
//   2. \nENHANCEMENT INGREDIENTS\n  (vfunc +0x60 / +0x5c → recipe row)
//   3. Discipline: name - n
//   4. Required Faction / Class / Combat / Perception / Tech / Theory / Level
//
// Sibling: UI_AppendItemRequirements (0x00845360) — item "Requires:" without
// ingredients; uses item-root stat shorts (+0xec..) instead of def +0x3fe..

#include <cstdint>

// Opaque retail types — layout notes only.
struct UIText;
struct ItemOrCraft;
struct ItemDef;

extern void *g_localPlayer; // DAT_00d1b6d8

// Callees (Ghidra names kept where not dual-named):
//   FUN_00599dd0  CountIngredientSlots(def)
//   FUN_005097b0  GetTypelessRecipe / recipe row by prefix
//   FUN_0051f8e0  race display name
//   FUN_0051f940  LookupClassDisplayName_Inferred
//   FUN_004c4070  Combat, FUN_004c41c0 Perception,
//   Character_GetTechForPoolCalcs Tech, FUN_004c4140 Theory
//   FUN_0052b040 / FUN_0052ada0 discipline name + balance

int UI_AppendCraftRequirements_Inferred(ItemOrCraft *item /* stack */,
                                        UIText *text /* ESI */)
{
  if (g_localPlayer == nullptr) {
    return 0;
  }

  // SEH LAB_009ac516 — omitted.

  // def = item[+0xa8]→[+0x3c]
  // int lines = 0;
  //
  // if (CountIngredientSlots(def) > 0) {
  //   AppendColored(text, "\nINGREDIENTS\n", 0xff20ff20);
  //   for each non-(-1) slot at def+0x498 step 4:
  //     resolve CND object; Append "   " + name [+ " %i" if debug qty flag];
  //     lines++;
  //   if (item->EnhancementCount() > 0) {
  //     AppendColored(text, "\nENHANCEMENT INGREDIENTS\n", 0xff20ff20);
  //     for each enhancement index / 5 recipe dword IDs:
  //       resolve; append; lines++;
  //   }
  // }
  //
  // AppendNewline(text); lines++;
  //
  // if (def->disciplineType >= 0) { ... "Discipline: "; lines++; }
  // if (raceId != -1)  { "Required Faction: %s\n"; color by player race; lines++; }
  // if (classId != -1) { "Required Class: %s\n";  color by player class; lines++; }
  // for each stat short > 0 on def: "Required X: %i\n"; color by getter; lines++;
  // if (levelSum = item.e8 + item.ea; levelSum >= 1) {
  //   cap = min(levelSum, 80); "Required Level: %i\n"; color by player level; lines++;
  // }
  // return lines;

  (void)item;
  (void)text;
  return 0; // structural stub — see FUN_00846820.cpp + raw for full CF
}
