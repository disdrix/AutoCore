// =============================================================================
// FUN_00687660
// -----------------------------------------------------------------------------
// Stable ID: aa_00687660
// Address:   0x00687660  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00687660 @ 0x00687660
// Stable ID: aa_00687660
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_006a3db0×2, _CIpow×2, ABS, FUN_00687660.
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

void FUN_00687660(float param_1,short param_2,float param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ param_5,

                 float param_6,float *param_7,float *param_8,short *param_9,short *param_10)



{

  float fVar1;

  short sVar2;

  uint uVar3;

  float10 extraout_ST0;

  float10 fVar4;

  float10 extraout_ST1;

  

  param_1 = g_flOne - param_1;

  uVar3 = FUN_006a3db0();

  if ((float10)DAT_00a0f298 <= extraout_ST0 - (float10)(int)uVar3) {

    uVar3 = uVar3 + 1;

  }

  sVar2 = (short)uVar3;

  if (((sVar2 != 0) && (sVar2 != param_2)) &&

     (ABS((float)((float10)param_1 - (float10)(uVar3 & 0xffff) * extraout_ST1)) <= param_3)) {

    fVar1 = DAT_00aaa6f8 - param_6;

    *param_9 = sVar2 + -1;

    fVar4 = (float10)_CIpow();

    *param_7 = (float)(fVar4 * (float10)fVar1 + (float10)param_6);

    *param_10 = sVar2;

    fVar4 = (float10)_CIpow();

    *param_8 = (float)(fVar4 * (float10)fVar1 + (float10)param_6);

    return;

  }

  *param_7 = param_6;

  sVar2 = FUN_006a3db0();

  *param_9 = sVar2;

  if ((short)(param_2 + -1) <= sVar2) {

    sVar2 = param_2 + -1;

  }

  *param_9 = sVar2;

  *param_8 = 255.0;

  *param_10 = -1;

  return;

}
