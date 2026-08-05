// =============================================================================
// FUN_005ff120
// -----------------------------------------------------------------------------
// Stable ID: aa_005ff120
// Address:   0x005ff120  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005ff120 @ 0x005ff120
// Stable ID: aa_005ff120
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_005ff120.
//  - Return sites: 2.

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

uint32_t /* width from decompiler */ __fastcall FUN_005ff120(int param_1)



{

  int *piVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  piVar1 = *(int **)(*(int *)(*(int *)(param_1 + -0xdc) + 4) + -0x30 + param_1);

  if (piVar1 != (int *)0x0) {

                    /* WARNING: Could not recover jumptable at 0x005ff133. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    uVar2 = (**(code **)(*piVar1 + 0x19c))();

    return uVar2;

  }

  return 0;

}
