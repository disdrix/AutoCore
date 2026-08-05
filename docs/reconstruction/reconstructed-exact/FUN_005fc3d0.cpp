// =============================================================================
// FUN_005fc3d0
// -----------------------------------------------------------------------------
// Stable ID: aa_005fc3d0
// Address:   0x005fc3d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005fc3d0 @ 0x005fc3d0
// Stable ID: aa_005fc3d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_005fc3d0.
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

void FUN_005fc3d0(int param_1,uint32_t /* width from decompiler */ param_2,float *param_3)



{

  *param_3 = *(float *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) +

                                0x3c) + 0x6a8) * *(float *)(param_1 + 0x1fc);

  param_3[1] = *(float *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) +

                                  0x3c) + 0x6ac) * *(float *)(param_1 + 0x1fc);

  param_3[2] = *(float *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) +

                                  0x3c) + 0x6b4) * *(float *)(param_1 + 0x1fc);

  param_3[9] = *param_3;

  param_3[3] = (float)((int)*(short *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac

                                                        + param_1) + 0x3c) + 0x69a) +

                      *(int *)(param_1 + 0x218));

  param_3[4] = *(float *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) +

                                  0x3c) + 0x6a0);

  param_3[5] = *(float *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) +

                                  0x3c) + 0x6a4);

  param_3[6] = *(float *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) +

                                  0x3c) + 0x6b8);

  param_3[7] = *(float *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) +

                                  0x3c) + 0x6bc);

  param_3[8] = *(float *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) +

                                  0x3c) + 0x6c0);

  return;

}
