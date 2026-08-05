// =============================================================================
// FUN_00893a40
// -----------------------------------------------------------------------------
// Stable ID: aa_00893a40
// Address:   0x00893a40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00893a40 @ 0x00893a40
// Stable ID: aa_00893a40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_007916e0, FUN_00893a40.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall FUN_00893a40(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int *piVar1;

  

  FUN_007916e0(param_2);

  if ((((char)param_2 != '\0') && (piVar1 = *(int **)(param_1 + 0x54c), piVar1 != (int *)0x0)) &&

     (piVar1[0x146] == 0)) {

    (**(code **)(*piVar1 + 0xcc))(0);

  }

  return;

}
