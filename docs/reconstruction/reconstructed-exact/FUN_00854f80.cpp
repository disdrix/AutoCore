// =============================================================================
// FUN_00854f80
// -----------------------------------------------------------------------------
// Stable ID: aa_00854f80
// Address:   0x00854f80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00854f80 @ 0x00854f80
// Stable ID: aa_00854f80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0040cf90, FUN_00854f80.
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

void FUN_00854f80(void)



{

  int iVar1;

  int unaff_ESI;

  uint32_t /* width from decompiler */ local_c;

  float fStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  if ((*(int *)(unaff_ESI + 0x298) != 0) && (*(int *)(unaff_ESI + 0x2a4) != 0)) {

    local_c = 0;

    local_4 = DAT_00aaa8e8;

    (**(code **)(**(int **)(unaff_ESI + 0x298) + 0x48))();

    iVar1 = (**(code **)(**(int **)(unaff_ESI + 0x298) + 0x48))();

    fStack_8 = DAT_00aaa8e0 - (DAT_00aaa8e4 - *(float *)(iVar1 + 0x24));

    FUN_0040cf90(&local_c);

  }

  return;

}
