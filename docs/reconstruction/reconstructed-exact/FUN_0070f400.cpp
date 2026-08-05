// =============================================================================
// FUN_0070f400
// -----------------------------------------------------------------------------
// Stable ID: aa_0070f400
// Address:   0x0070f400  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0070f400 @ 0x0070f400
// Stable ID: aa_0070f400
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~65 non-empty decompiler lines.
//  - Control keywords: if×2, do×2, while×2, return×1.
//  - Notable callees: FUN_0070f400.
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

float10 __fastcall FUN_0070f400(uint32_t /* width from decompiler */ param_1,int param_2,int param_3,float param_4)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  int in_EAX;

  float *pfVar6;

  uint32_t /* width from decompiler */ *puVar7;

  float *pfVar8;

  int iVar9;

  int iVar10;

  uint uVar11;

  float10 fVar12;

  float10 fVar13;

  float10 fVar14;

  

  puVar7 = (uint32_t /* width from decompiler */ *)((-in_EAX & 3U) + in_EAX);

  param_2 = param_2 >> 1;

  puVar7[1] = param_4;

  *puVar7 = 0x3f800000;

  fVar12 = (float10)param_4 * (float10)*(float *)(param_3 + -4 + param_2 * 4) +

           (float10)*(float *)(param_3 + param_2 * 4);

  iVar10 = 2;

  param_4 = param_4 + param_4;

  if (3 < param_2 + -1) {

    uVar11 = param_2 - 1U >> 2;

    iVar10 = uVar11 * 4 + 2;

    pfVar6 = (float *)(puVar7 + 1);

    pfVar8 = (float *)(param_3 + -0x10 + param_2 * 4);

    do {

      uVar11 = uVar11 - 1;

      fVar5 = param_4 * *pfVar6 - pfVar6[-1];

      pfVar6[1] = fVar5;

      fVar1 = pfVar8[2];

      fVar13 = (float10)fVar5 * (float10)param_4 - (float10)*pfVar6;

      pfVar6[2] = (float)fVar13;

      fVar2 = pfVar8[1];

      fVar3 = (float)(fVar13 * (float10)param_4 - (float10)fVar5);

      pfVar6[3] = fVar3;

      fVar4 = *pfVar8;

      fVar14 = (float10)fVar3 * (float10)param_4 - fVar13;

      pfVar6[4] = (float)fVar14;

      fVar12 = fVar14 * (float10)pfVar8[-1] +

               (float10)(float)((float10)fVar3 * (float10)fVar4 +

                               fVar13 * (float10)fVar2 + (float10)fVar5 * (float10)fVar1 + fVar12);

      pfVar6 = pfVar6 + 4;

      pfVar8 = pfVar8 + -4;

    } while (uVar11 != 0);

  }

  if (iVar10 <= param_2) {

    iVar9 = (param_2 - iVar10) + 1;

    pfVar6 = (float *)(puVar7 + iVar10 + -2);

    pfVar8 = (float *)(param_3 + (param_2 - iVar10) * 4);

    do {

      iVar9 = iVar9 + -1;

      fVar13 = (float10)param_4 * (float10)pfVar6[1] - (float10)*pfVar6;

      pfVar6[2] = (float)fVar13;

      fVar12 = fVar13 * (float10)*pfVar8 + fVar12;

      pfVar6 = pfVar6 + 1;

      pfVar8 = pfVar8 + -1;

    } while (iVar9 != 0);

  }

  return fVar12;

}
