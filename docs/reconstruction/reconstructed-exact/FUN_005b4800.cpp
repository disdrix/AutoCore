// =============================================================================
// FUN_005b4800
// -----------------------------------------------------------------------------
// Stable ID: aa_005b4800
// Address:   0x005b4800  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005b4800 @ 0x005b4800
// Stable ID: aa_005b4800
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~70 non-empty decompiler lines.
//  - Control keywords: if×2, for×1, do×1, while×1, return×1.
//  - Notable callees: fcos×3, fsin×3, FUN_005b4800.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_005b4800(float param_1,float param_2)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  uint uVar5;

  int iVar6;

  float *pfVar7;

  uint uVar8;

  uint32_t /* width from decompiler */ *puVar9;

  float10 fVar10;

  float10 fVar11;

  float10 fVar12;

  float fVar13;

  float fVar14;

  

  fVar13 = param_1 - _DAT_00b05364;

  _DAT_00b05364 = param_1;

  if ((_DAT_00b05360 & 1) == 0) {

    _DAT_00b05360 = _DAT_00b05360 | 1;

    DAT_00b0535c = param_2;

  }

  DAT_00b0534c = DAT_00b0534c + fVar13;

  DAT_00b05350 = DAT_00b05350 + fVar13;

  DAT_00b05354 = DAT_00b05354 + fVar13;

  DAT_00b05358 = DAT_00b05358 + fVar13;

  fVar13 = param_2 * _DAT_009d990c;

  fVar14 = param_2 * (float)g_nInferredThreatDefault;

  puVar9 = &DAT_00b05240;

  for (iVar6 = 0x40; fVar4 = g_flOne, iVar6 != 0; iVar6 = iVar6 + -1) {

    *puVar9 = 0;

    puVar9 = puVar9 + 1;

  }

  uVar8 = 0;

  pfVar7 = (float *)&DAT_00b05248;

  do {

    if (param_2 != 0.0) {

      (&DAT_00b0534c)[uVar8] = ((&DAT_00b0534c)[uVar8] * DAT_00b0535c) / param_2;

    }

    uVar5 = uVar8 & 3;

    fVar1 = (float)(&DAT_00af3f00)[uVar5 * 2];

    fVar2 = (&DAT_00b0534c)[uVar8];

    pfVar7[0xd] = fVar4;

    uVar8 = uVar8 + 1;

    fVar10 = (float10)fsin((float10)fVar1 * (float10)fVar2 * (float10)fVar14);

    fVar11 = (float10)fcos((float10)(float)(&DAT_00af3f04)[uVar5 * 2] *

                           (float10)(float)(&DAT_00b05348)[uVar8] * (float10)fVar14);

    fVar10 = fVar10 * (float10)fVar13 * (float10)DAT_009d9908;

    fVar12 = (float10)fsin(fVar10);

    fVar1 = (float)fVar12;

    pfVar7[7] = 0.0 - fVar1;

    fVar11 = (float10)(float)fVar11 * (float10)fVar13 * (float10)DAT_009d9908;

    fVar12 = (float10)fsin(fVar11);

    fVar2 = (float)fVar12;

    fVar10 = (float10)fcos(fVar10);

    fVar3 = (float)fVar10;

    fVar10 = (float10)fcos(fVar11);

    pfVar7[3] = fVar3;

    pfVar7[-2] = (float)fVar10;

    *pfVar7 = -fVar2;

    pfVar7[2] = fVar2 * fVar1;

    pfVar7[4] = (float)((float10)fVar1 * fVar10);

    pfVar7[6] = fVar3 * fVar2;

    pfVar7[8] = (float)(fVar10 * (float10)fVar3);

    pfVar7 = pfVar7 + 0x10;

  } while ((int)uVar8 < 4);

  DAT_00b0535c = param_2;

  return;

}
