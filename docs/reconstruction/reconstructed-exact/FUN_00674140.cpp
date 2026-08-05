// =============================================================================
// FUN_00674140
// -----------------------------------------------------------------------------
// Stable ID: aa_00674140
// Address:   0x00674140  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00674140 @ 0x00674140
// Stable ID: aa_00674140
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00674140, FUN_00679320.
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

uint32_t /* width from decompiler */ __fastcall FUN_00674140(int param_1)



{

  int *piVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  piVar1 = *(int **)(param_1 + 0x128);

  if (((piVar1 != (int *)0x0) && (*(int *)(param_1 + 300) - (int)piVar1 >> 2 != 0)) &&

     (*piVar1 != 0)) {

    uVar2 = FUN_00679320();

    return uVar2;

  }

  return 0;

}
