// =============================================================================
// FUN_00703a60
// -----------------------------------------------------------------------------
// Stable ID: aa_00703a60
// Address:   0x00703a60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00703a60 @ 0x00703a60
// Stable ID: aa_00703a60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~162 non-empty decompiler lines.
//  - Control keywords: if×3, do×3, while×3, return×1.
//  - Notable callees: fcos×2, FUN_00702f30, FUN_00702f90, FUN_00702fa0, FUN_00703130, FUN_00703a60, ROUND, f2xm1.
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



uint32_t /* width from decompiler */ * FUN_00703a60(int *param_1)



{

  int *piVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ uVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  int iVar10;

  float10 fVar11;

  float10 fVar12;

  int iStack_8;

  int iStack_4;

  

  puVar4 = (uint32_t /* width from decompiler */ *)FUN_00703130(0x9d38);

  *puVar4 = param_1;

  puVar2 = (uint32_t /* width from decompiler */ *)*param_1;

  puVar4[0xe] = puVar4 + 0x3e;

  uVar5 = FUN_00702f30(*puVar2);

  puVar4[1] = uVar5;

  puVar4[2] = puVar2[1] << 1;

  puVar4[3] = puVar2[1];

  puVar4[4] = puVar2[2];

  puVar4[5] = (int)puVar2[1] / (int)puVar2[2];

  puVar4[6] = (puVar4[3] * 3) / 2;

  puVar4[7] = puVar2[3];

  puVar4[8] = puVar2[4];

  puVar4[0x38] = 1;

  puVar4[0x39] = puVar2 + 10;

  uVar5 = puVar2[0x12];

  puVar4[0x3a] = uVar5;

  puVar4[0x3b] = uVar5;

  iStack_8 = 9;

  FUN_00702f90(puVar4[1],4,&iStack_8);

  puVar4[10] = puVar2[7];

  puVar4[0xb] = puVar2[8];

  puVar4[0xc] = puVar2[5];

  iVar9 = puVar4[3];

  puVar4[0xd] = puVar2[6];

  iVar6 = iVar9 * 4;

  iVar7 = puVar4[0xe] + (-puVar4[0xe] & 3) + iVar6;

  puVar4[0xf] = iVar7 + iVar9 * -4;

  iVar7 = (-iVar7 & 3U) + iVar7 + iVar6;

  puVar4[0x10] = iVar7 + iVar9 * -4;

  iVar3 = puVar4[2];

  puVar4[9] = 1;

  iVar8 = iVar3 * 4;

  iVar7 = (-iVar7 & 3U) + iVar7 + iVar8;

  puVar4[0x11] = iVar7 + iVar3 * -4;

  iVar7 = (-iVar7 & 3U) + iVar7 + iVar8;

  puVar4[0x12] = iVar7 + iVar3 * -4;

  iVar8 = (-iVar7 & 3U) + iVar7 + iVar8;

  iVar7 = (-iVar8 & 3U) + 0x100 + iVar8;

  puVar4[0x14] = iVar7 + -0x100;

  iVar7 = (-iVar7 & 3U) + 0x100 + iVar7;

  puVar4[0x15] = iVar7 + -0x100;

  iVar7 = (-iVar7 & 3U) + 0x100 + iVar7;

  puVar4[0x16] = iVar7 + -0x100;

  iVar7 = (-iVar7 & 3U) + 0x100 + iVar7;

  puVar4[0x13] = iVar8 + iVar3 * -4;

  puVar4[0x17] = iVar7 + -0x100;

  iVar8 = puVar4[6];

  iVar7 = (-iVar7 & 3U) + iVar7 + iVar8 * 4;

  puVar4[0x1a] = iVar7 + iVar8 * -4;

  iVar3 = puVar4[8];

  iVar7 = (-iVar7 & 3U) + iVar7 + iVar3 * 4;

  iVar10 = iVar7 + iVar3 * -4;

  puVar4[0x19] = iVar10 + (iVar3 - puVar4[6]) * 4;

  iVar7 = (-iVar7 & 3U) + iVar7 + iVar6;

  puVar4[0x18] = iVar10;

  puVar4[0x1b] = iVar7 + iVar9 * -4;

  iVar7 = (-iVar7 & 3U) + iVar7 + iVar6;

  puVar4[0x1c] = iVar7 + iVar9 * -4;

  iVar6 = (-iVar7 & 3U) + iVar7 + iVar6;

  puVar4[0x1d] = iVar6 + iVar9 * -4;

  iVar7 = (-iVar6 & 3U) + iVar6 + iVar8 * 4;

  puVar4[0xe] = iVar7;

  iVar6 = (puVar4[4] * 7) / 2;

  iStack_4 = (puVar4[4] * 5) / 2;

  puVar4[0x1e] = iVar7 + iVar8 * -4;

  iStack_8 = 0;

  if (0 < iVar6) {

    do {

      fVar11 = (float10)fcos(((float10)iStack_8 * (float10)_DAT_00a0f190) / (float10)iVar6);

      *(float *)(puVar4[0x1e] + iStack_8 * 4) =

           (float)((float10)_DAT_00a0f180 - fVar11 * (float10)_DAT_00a0f188);

      iStack_8 = iStack_8 + 1;

    } while (iStack_8 < iVar6);

  }

  iStack_8 = 0;

  if (0 < iStack_4) {

    do {

      fVar11 = (float10)fcos(((float10)iStack_8 * (float10)_DAT_00a0f190) / (float10)iStack_4);

      *(float *)(puVar4[0x1e] + (iStack_8 + iVar6) * 4) =

           (float)(fVar11 * (float10)_DAT_00a0f188 + (float10)_DAT_00a0f180);

      iStack_8 = iStack_8 + 1;

    } while (iStack_8 < iStack_4);

  }

  iVar7 = (-puVar4[0xe] & 3) + puVar4[7] * 4 + 4 + puVar4[0xe];

  puVar4[0xe] = iVar7;

  puVar4[0x1f] = iVar7 + puVar4[7] * -4 + -4;

  iStack_8 = 0;

  if (puVar4[7] != -1 && -1 < puVar4[7] + 1) {

    do {

      fVar11 = (float10)(float)puVar4[10] * (float10)iStack_8 * (float10)_DAT_00a0f178;

      fVar12 = (float10)1.4426950408889634 * fVar11 * fVar11 * (float10)_DAT_00a0f170;

      fVar11 = ROUND(fVar12);

      fVar12 = (float10)f2xm1(fVar12 - fVar11);

      fVar11 = (float10)fscale((float10)1 + fVar12,fVar11);

      *(float *)(puVar4[0x1f] + iStack_8 * 4) = (float)(fVar11 * (float10)_DAT_00a0f168);

      iStack_8 = iStack_8 + 1;

    } while (iStack_8 < puVar4[7] + 1);

  }

  iVar8 = puVar4[7];

  iVar6 = iVar8 * 4;

  iVar7 = (-puVar4[0xe] & 3) + iVar6 + 4 + puVar4[0xe];

  puVar4[0x20] = iVar7 + iVar8 * -4 + -4;

  iVar7 = (-iVar7 & 3U) + iVar7 + 4 + iVar6;

  puVar4[0x21] = iVar7 + iVar8 * -4 + -4;

  iVar7 = (-iVar7 & 3U) + iVar7 + 4 + iVar6;

  puVar4[0x2a] = iVar7 + iVar8 * -4 + -4;

  iVar7 = (-iVar7 & 3U) + iVar7 + 4 + iVar6;

  puVar4[0x2b] = iVar7 + iVar8 * -4 + -4;

  iVar7 = (-iVar7 & 3U) + iVar7 + iVar6;

  puVar4[0x22] = iVar7 + iVar8 * -4;

  iVar7 = (-iVar7 & 3U) + iVar7 + iVar6;

  puVar4[0x23] = iVar7 + iVar8 * -4;

  iVar7 = (-iVar7 & 3U) + iVar7 + iVar6;

  puVar4[0x24] = iVar7 + iVar8 * -4;

  iVar7 = (-iVar7 & 3U) + iVar7 + iVar6;

  puVar4[0x25] = iVar7 + iVar8 * -4;

  iVar7 = (-iVar7 & 3U) + iVar7 + iVar6;

  puVar4[0x26] = iVar7 + iVar8 * -4;

  iVar7 = (-iVar7 & 3U) + iVar7 + iVar6;

  puVar4[0x27] = iVar7 + iVar8 * -4;

  iVar7 = (-iVar7 & 3U) + iVar7 + 4 + iVar6;

  puVar4[0x28] = iVar7 + iVar8 * -4 + -4;

  iVar7 = (-iVar7 & 3U) + iVar7 + 4 + iVar6;

  puVar4[0x29] = iVar7 + iVar8 * -4 + -4;

  iVar7 = iVar7 + (-iVar7 & 3U) + puVar4[5] * 4;

  iVar9 = (-iVar7 & 3U) + iVar6 + iVar7;

  puVar4[0x2c] = iVar9 + iVar8 * -4;

  iVar9 = iVar9 + (-iVar9 & 3U) + iVar6;

  puVar4[0x2d] = iVar9 + iVar8 * -4;

  puVar4[0x2f] = iVar7 + puVar4[5] * -4;

  iVar9 = iVar9 + (-iVar9 & 3U) + iVar6;

  piVar1 = puVar4 + 0x3d;

  puVar4[0xe] = iVar9;

  puVar4[0x2e] = iVar9 + iVar8 * -4;

  puVar4[0x30] = 0x41000000;

  puVar4[0x31] = 0;

  puVar4[0x36] = 0;

  puVar4[0x32] = 0;

  puVar4[0x37] = 0;

  puVar4[0x3c] = 2;

  FUN_00702fa0(puVar4[1],0x19,piVar1);

  *piVar1 = *piVar1 << 1;

  return puVar4;

}
