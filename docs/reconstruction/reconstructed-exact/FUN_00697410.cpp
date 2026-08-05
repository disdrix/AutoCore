// =============================================================================
// FUN_00697410
// -----------------------------------------------------------------------------
// Stable ID: aa_00697410
// Address:   0x00697410  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00697410 @ 0x00697410
// Stable ID: aa_00697410
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_00697410.
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

float10 __fastcall FUN_00697410(int param_1)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  

  fVar4 = g_flOne;

  fVar1 = *(float *)(param_1 + 0xc) - DAT_00d08eb8;

  fVar3 = *(float *)(param_1 + 8) - DAT_00d08eb4;

  fVar2 = *(float *)(param_1 + 4) - DAT_00d08eb0;

  fVar1 = g_flOne - ((float)(((int)(fVar1 * fVar1 + fVar3 * fVar3 + fVar2 * fVar2) >> 1) +

                            0x1fc00000) - *(float *)(param_1 + 0x44)) /

                    (*(float *)(param_1 + 0x40) - *(float *)(param_1 + 0x44));

  *(float *)(param_1 + 0x14) = fVar1;

  if (fVar4 < fVar1) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = 0x3f800000;

    return (float10)*(float *)(param_1 + 0x14);

  }

  if (fVar1 < g_flZero) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = 0;

  }

  return (float10)*(float *)(param_1 + 0x14);

}
