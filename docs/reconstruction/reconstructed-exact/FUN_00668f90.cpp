// =============================================================================
// FUN_00668f90
// -----------------------------------------------------------------------------
// Stable ID: aa_00668f90
// Address:   0x00668f90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00668f90 @ 0x00668f90
// Stable ID: aa_00668f90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~252 non-empty decompiler lines.
//  - Control keywords: if×7, return×1.
//  - Notable callees: FUN_005d6ae0×6, ABS×3, FUN_006c3160×3, FUN_005d68f0×2, FUN_006c35e0×2, FUN_005d69a0, FUN_0063a190, FUN_00668f90.
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

void __thiscall FUN_00668f90(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  float *pfVar1;

  int iVar2;

  bool bVar3;

  float fVar4;

  float fVar5;

  uint uVar6;

  char *pcVar7;

  uint uVar8;

  float unaff_EBX;

  int iVar9;

  float unaff_ESI;

  float unaff_EDI;

  float10 fVar10;

  float fVar11;

  float fVar12;

  float fVar13;

  float fVar14;

  uint8_t *puVar15;

  float *pfStack_174;

  float afStack_164 [4];

  float *pfStack_154;

  float fStack_150;

  float fStack_14c;

  uint8_t auStack_144 [8];

  uint32_t /* width from decompiler */ uStack_13c;

  float fStack_138;

  float fStack_134;

  float fStack_130;

  float fStack_12c;

  float fStack_128;

  float *pfStack_124;

  float fStack_120;

  float fStack_11c;

  float fStack_118;

  float *pfStack_114;

  float fStack_110;

  float fStack_10c;

  float fStack_ec;

  float fStack_e8;

  uint32_t /* width from decompiler */ uStack_d8;

  uint32_t /* width from decompiler */ uStack_d4;

  float local_d0;

  float local_cc;

  float local_c8;

  float local_c4;

  float local_c0;

  float fStack_bc;

  float fStack_b8;

  float fStack_b4;

  float fStack_b0;

  float fStack_ac;

  float fStack_a8;

  uint32_t /* width from decompiler */ uStack_a4;

  uint32_t /* width from decompiler */ uStack_a0;

  uint32_t /* width from decompiler */ uStack_9c;

  uint32_t /* width from decompiler */ uStack_98;

  uint32_t /* width from decompiler */ uStack_94;

  float fStack_90;

  float fStack_8c;

  float fStack_88;

  float *pfStack_84;

  float fStack_80;

  float fStack_7c;

  float fStack_78;

  float fStack_74;

  float fStack_70;

  uint8_t auStack_68 [4];

  uint8_t auStack_64 [8];

  uint8_t auStack_5c [12];

  uint8_t local_50 [48];

  float local_20;

  float local_1c;

  float local_18;

  float local_14;

  

  pfStack_174 = (float *)0x8;

  FUN_006c2fb0(param_2,param_3,param_1 + 0xe4);

  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + 0x3c);

  pfStack_174 = (float *)(param_1 + 0x70);

  iVar9 = *(int *)(*(int *)(param_1 + 0xc) + 0x3c) + 0x80;

  FUN_0063a190(iVar2 + 0x80);

  pfStack_174 = (float *)(param_1 + 0xa0);

  FUN_005d6ae0(iVar2 + 0x80);

  local_d0 = *(float *)(iVar2 + 0xb0) + local_d0;

  local_cc = *(float *)(iVar2 + 0xb4) + local_cc;

  local_c8 = *(float *)(iVar2 + 0xb8) + local_c8;

  local_c4 = *(float *)(iVar2 + 0xbc) + local_c4;

  pfStack_174 = (float *)(param_1 + 0x60);

  pfVar1 = (float *)(param_1 + 0xb0);

  local_20 = local_d0;

  local_1c = local_cc;

  local_18 = local_c8;

  local_14 = local_c4;

  FUN_005d68f0(iVar9);

  pfStack_174 = pfVar1;

  FUN_005d69a0(local_50);

  pfStack_174 = &local_c0;

  fVar10 = (float10)(**(code **)(**(int **)(param_1 + 0x20) + 0x18))

                              (*(uint32_t /* width from decompiler */ *)(param_1 + 0x24),pfStack_174);

  *(float *)(param_1 + 0x24) = (float)fVar10;

  FUN_005d68f0(auStack_5c,&local_cc);

  puVar15 = &stack0xfffffe94;

  fVar14 = *(float *)(param_1 + 0x24);

  (**(code **)(**(int **)(param_1 + 0x20) + 0x1c))(fVar14,puVar15);

  pfStack_174 = (float *)((float)pfStack_174 * DAT_00aaa668);

  fVar4 = unaff_EDI * DAT_00aaa668;

  fVar11 = unaff_EBX * DAT_00aaa668;

  fVar5 = unaff_ESI * DAT_00aaa668;

  FUN_005d6ae0(auStack_64,&pfStack_174);

  fStack_e8 = ABS((float)pfStack_174);

  fStack_ec = ABS(fVar4);

  bVar3 = fStack_e8 <= fStack_ec;

  fVar13 = fStack_e8;

  if (!bVar3) {

    fVar13 = fStack_ec;

  }

  uVar6 = (uint)!bVar3;

  uVar8 = 2;

  if (ABS(fVar5) < fVar13) {

    uVar6 = 2;

    uVar8 = (uint)!bVar3;

  }

  fVar13 = 0.0;

  afStack_164[uVar6] = 0.0;

  afStack_164[bVar3] = (float)(&pfStack_174)[uVar8];

  afStack_164[uVar8] = 0.0 - (float)(&pfStack_174)[bVar3];

  fVar12 = afStack_164[0] * afStack_164[0] + afStack_164[2] * afStack_164[2] +

           afStack_164[1] * afStack_164[1];

  if (fVar12 != 0.0) {

    fVar13 = g_flOne / SQRT(fVar12);

    fVar12 = fVar13;

  }

  afStack_164[0] = fVar13 * afStack_164[0];

  afStack_164[1] = afStack_164[1] * fVar13;

  afStack_164[3] = afStack_164[3] * fVar13;

  afStack_164[2] = afStack_164[2] * fVar13;

  pfStack_154 = (float *)(afStack_164[2] * fVar4 - afStack_164[1] * fVar5);

  fStack_150 = fVar5 * afStack_164[0] - afStack_164[2] * (float)pfStack_174;

  fStack_14c = afStack_164[1] * (float)pfStack_174 - fVar4 * afStack_164[0];

  fVar10 = (float10)(**(code **)(**(int **)(param_1 + 0x20) + 0x28))

                              (*(uint32_t /* width from decompiler */ *)(param_1 + 0x24));

  fVar13 = (float)fVar10;

  local_c8 = *pfVar1 + fVar13 * fVar12;

  local_c4 = *(float *)(param_1 + 0xb4) + (float)pfStack_174 * fVar13;

  local_c0 = *(float *)(param_1 + 0xb8) + fVar4 * fVar13;

  fStack_bc = *(float *)(param_1 + 0xbc) + fVar5 * fVar13;

  if (g_flZero < *(float *)(param_1 + 0x28)) {

    pfStack_114 = (float *)(param_1 + 0xe4);

    fStack_118 = *(float *)(param_1 + 0x28);

    pfStack_124 = pfStack_174;

    fStack_138 = local_c8;

    fStack_134 = local_c4;

    fStack_130 = local_c0;

    fStack_12c = fStack_bc;

    fStack_128 = fVar12;

    fStack_120 = fVar4;

    fStack_11c = fVar5;

    FUN_006c3440(&fStack_138,param_2,param_3);

  }

  fStack_a8 = *pfVar1;

  uStack_a4 = *(uint32_t /* width from decompiler */ *)(param_1 + 0xb4);

  uStack_a0 = *(uint32_t /* width from decompiler */ *)(param_1 + 0xb8);

  uStack_9c = *(uint32_t /* width from decompiler */ *)(param_1 + 0xbc);

  uStack_98 = uStack_d8;

  uStack_94 = uStack_d4;

  fStack_90 = local_d0;

  fStack_8c = local_cc;

  pfStack_84 = (float *)afStack_164[0];

  fStack_80 = afStack_164[1];

  fStack_7c = afStack_164[2];

  fStack_88 = fVar11;

  FUN_006c35e0(&fStack_a8,param_2,param_3);

  fStack_88 = afStack_164[3];

  pfStack_84 = pfStack_154;

  fStack_80 = fStack_150;

  fStack_7c = 0.0;

  FUN_006c35e0(&fStack_a8,param_2,param_3);

  if ('\0' < *(char *)(param_1 + 0xe0)) {

    FUN_005d6ae0(iVar9,param_1 + 0xd0);

    FUN_005d6ae0(iVar9,param_1 + 0xc0);

    afStack_164[3] = fStack_b0 * afStack_164[0] - fStack_b4 * afStack_164[1];

    pfStack_154 = (float *)(afStack_164[1] * fStack_b8 - fStack_b0 * fVar11);

    fStack_150 = fStack_b4 * fVar11 - afStack_164[0] * fStack_b8;

    fStack_12c = afStack_164[2];

    pfStack_124 = pfStack_174;

    fStack_134 = afStack_164[0];

    fStack_130 = afStack_164[1];

    fStack_10c = 0.0;

    fStack_138 = fVar11;

    fStack_128 = fVar12;

    fStack_120 = fVar4;

    fStack_11c = fVar5;

    fStack_118 = afStack_164[3];

    pfStack_114 = pfStack_154;

    fStack_110 = fStack_150;

    FUN_006c3160(&fStack_138,param_2,param_3);

    fStack_138 = 0.0 - afStack_164[3];

    fStack_134 = 0.0 - (float)pfStack_154;

    fStack_12c = 0.0;

    fStack_130 = 0.0 - fStack_150;

    pfStack_114 = (float *)afStack_164[0];

    fStack_110 = afStack_164[1];

    fStack_10c = afStack_164[2];

    fStack_118 = fVar11;

    FUN_006c3160(&fStack_138,param_2,param_3);

    if (*(char *)(param_1 + 0xe0) == '\x03') {

      (**(code **)(**(int **)(param_1 + 0x20) + 0x2c))

                (*(uint32_t /* width from decompiler */ *)(param_1 + 0x24),afStack_164 + 3);

      FUN_005d6ae0(auStack_68,afStack_164 + 3);

      FUN_005d6ae0(iVar9,param_1 + 0xd0);

      fStack_138 = fStack_70 * fStack_b4 - fStack_74 * fStack_b0;

      fStack_130 = fStack_74 * fStack_b8 - fStack_78 * fStack_b4;

      fStack_12c = 0.0;

      fStack_128 = afStack_164[3];

      pfStack_124 = pfStack_154;

      fStack_120 = fStack_150;

      fStack_11c = fStack_14c;

      fStack_134 = fStack_78 * fStack_b0 - fStack_70 * fStack_b8;

      fStack_118 = fStack_b8;

      pfStack_114 = (float *)fStack_b4;

      fStack_110 = fStack_b0;

      fStack_10c = fStack_ac;

      FUN_006c3160(&fStack_138,param_2,param_3);

    }

  }

  pcVar7 = (char *)(**(code **)(**(int **)(param_1 + 0x20) + 0x30))((int)&uStack_13c + 3);

  if (*pcVar7 == '\0') {

    uStack_13c = *pfVar1;

    fStack_138 = *(float *)(param_1 + 0xb4);

    fStack_134 = *(float *)(param_1 + 0xb8);

    fStack_130 = *(float *)(param_1 + 0xbc);

    fStack_12c = local_cc;

    fStack_128 = local_c8;

    pfStack_124 = (float *)local_c4;

    fStack_120 = local_c0;

    iVar2 = **(int **)(param_1 + 0x20);

    fVar10 = (float10)(**(code **)(iVar2 + 0x20))();

    fVar10 = (float10)(**(code **)(iVar2 + 0x28))((float)fVar10);

    fStack_110 = (float)fVar10;

    iVar2 = **(int **)(param_1 + 0x20);

    fVar10 = (float10)(**(code **)(iVar2 + 0x24))();

    fVar10 = (float10)(**(code **)(iVar2 + 0x28))((float)fVar10);

    fStack_110 = (float)fVar10;

    pfStack_124 = (float *)(0.0 - fVar14);

    fStack_120 = 0.0 - (float)puVar15;

    fStack_11c = 0.0 - fVar13;

    fStack_118 = 0.0 - fVar12;

    FUN_006c37c0(auStack_144,param_2,param_3);

  }

  return;

}
