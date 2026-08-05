// =============================================================================
// FUN_0044bc70
// -----------------------------------------------------------------------------
// Stable ID: aa_0044bc70
// Address:   0x0044bc70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0044bc70 @ 0x0044bc70
// Stable ID: aa_0044bc70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_00448fc0, FUN_0044bb80, FUN_0044bc70, FUN_0099a6b0.
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

uint32_t /* width from decompiler */ __thiscall FUN_0044bc70(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 4);

  if ((iVar1 != 0) && (1 < *(int *)(iVar1 + 4))) {

    iVar1 = FUN_0099a6b0(param_2);

    if (iVar1 == 0) {

      return 0xffffffff;

    }

    FUN_0044bb80(*(int *)(param_1 + 4));

    FUN_00448fc0(iVar1);

  }

  return 0;

}
