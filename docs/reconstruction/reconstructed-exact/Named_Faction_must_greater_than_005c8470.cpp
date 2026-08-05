// =============================================================================
// Named_Faction_must_greater_than_005c8470
// -----------------------------------------------------------------------------
// Stable ID: aa_005c8470
// Address:   0x005c8470  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_Faction_must_greater_than_005c8470 @ 0x005c8470
// Stable ID: aa_005c8470
// Embedded strings (evidence for future rename):
//   - "Faction must be greater than %d. %d.\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: Named_Faction_must_greater_than_005c8470, FUN_007a4480.
//  - Strings: "Faction must be greater than %d. %d.\n".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "Faction must be greater than %d. %d.
"
 * Domain alias of FUN_005c8470 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Named_Faction_must_greater_than_005c8470(int param_1,int param_2,uint32_t /* width from decompiler */ param_3)



{

  int iVar1;

  

  if (((((char)param_3 != '\0') &&

       (*(int *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + -0x60 + param_1) == 0)) &&

      (param_2 != 0)) && (param_2 < 10000)) {

    FUN_007a4480(1,"Faction must be greater than %d. %d.\n",9999,param_2);

  }

  *(int *)(param_1 + -0x34) = param_2;

  iVar1 = *(int *)(*(int *)(param_1 + -0x10c) + 4);

  if (*(int *)(param_1 + -0x60 + iVar1) != 0) {

    (**(code **)(**(int **)(param_1 + -0x60 + iVar1) + 0x288))(param_2,param_3);

  }

  return;

}
