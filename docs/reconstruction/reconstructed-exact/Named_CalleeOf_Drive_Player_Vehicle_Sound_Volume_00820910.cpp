// =============================================================================
// Named_CalleeOf_Drive_Player_Vehicle_Sound_Volume_00820910
// -----------------------------------------------------------------------------
// Stable ID: aa_00820910
// Callee of Drive_Player_Vehicle_Sound_Volume
// Address:   0x00820910  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Drive_Player_Vehicle_Sound_Volume: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_00816be0×3, FUN_00817840, FUN_00819060, FUN_00820910.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Drive_Player_Vehicle_Sound_Volume
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int * Named_CalleeOf_Drive_Player_Vehicle_Sound_Volume_00820910(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2)



{

  int *piVar1;

  

  piVar1 = (int *)FUN_00819060(0xffffffff);

  if (piVar1 == (int *)0x0) {

    return (int *)0x0;

  }

  (**(code **)(*piVar1 + 0x74))(param_1);

  if (piVar1[0x180] != 0) {

    (**(code **)(*(int *)piVar1[0x180] + 0x1d8))(param_1,1,1);

    (**(code **)(*(int *)piVar1[0x180] + 0x34c))();

  }

  FUN_00817840(3);

  FUN_00816be0(&DAT_00a76d20);

  FUN_00816be0(&DAT_00a76d1c);

  FUN_00816be0(&DAT_00a76d14);

  if (piVar1[0x1c2] != 0) {

    (**(code **)(*(int *)piVar1[0x1c2] + 0x454))(param_2,1);

  }

  return piVar1;

}
