// =============================================================================
// FUN_005a6f90
// -----------------------------------------------------------------------------
// Stable ID: aa_005a6f90
// Address:   0x005a6f90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005a6f90 @ 0x005a6f90
// Stable ID: aa_005a6f90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_005a6f90, FUN_005c88b0.
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

void __fastcall FUN_005a6f90(int param_1)



{

  int iVar1;

  

  FUN_005c88b0();

  iVar1 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0x15c) + 4) + -0xb4 + param_1) + 0x3c);

  *(char *)(param_1 + -0xb0) = *(char *)(iVar1 + 0x4cd) + *(char *)(iVar1 + 0x4cc);

  *(float *)(param_1 + -0xac) =

       (float)(int)*(char *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0x15c) + 4) + -0xb4 +

                                              param_1) + 0x3c) + 0x4c0);

  *(float *)(param_1 + -0xa8) =

       (float)(int)*(char *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0x15c) + 4) + -0xb4 +

                                              param_1) + 0x3c) + 0x4c2);

  *(float *)(param_1 + -0xa4) =

       (float)(int)*(char *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0x15c) + 4) + -0xb4 +

                                              param_1) + 0x3c) + 0x4c4);

  *(float *)(param_1 + -0xa0) =

       (float)(int)*(char *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0x15c) + 4) + -0xb4 +

                                              param_1) + 0x3c) + 0x4c6);

  *(float *)(param_1 + -0x9c) =

       (float)(int)*(char *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0x15c) + 4) + -0xb4 +

                                              param_1) + 0x3c) + 0x4c8);

  *(float *)(param_1 + -0x98) =

       (float)(int)*(char *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0x15c) + 4) + -0xb4 +

                                              param_1) + 0x3c) + 0x4ca);

  return;

}
