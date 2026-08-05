// READABILITY (auto CF):
//  - Body size: ~502 non-empty decompiler lines.
//  - Control keywords: if×32, return×8, goto×5, for×3, do×2, while×2.
//  - Notable callees: _fpclass×15, FUN_00499a70×2, free×2, FUN_0040dab0, FUN_0049a240, FUN_0049aa60, FUN_005b8190, FUN_005b81b0.
//  - Strings: "INITIALIZE: NO MAXPARTICLES ON MASTER FLUID".
//  - Return sites: 8.

// =============================================================================
// Named_INITIALIZE_NO_MAXPARTICLES_ON_MASTER_FLUID_0049aa60
// -----------------------------------------------------------------------------
// Stable ID: aa_0049aa60
// Address:   0x0049aa60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "INITIALIZE: NO MAXPARTICLES ON MASTER FLUID"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ __fastcall Named_INITIALIZE_NO_MAXPARTICLES_ON_MASTER_FLUID_0049aa60(uint32_t /* width from decompiler */ *param_1)



{

  void *pvVar1;

  char cVar2;

  uint uVar3;

  int iVar4;

  int *piVar5;

  int *piVar6;

  uint32_t /* width from decompiler */ uVar7;

  uint32_t /* width from decompiler */ *puVar8;

  int iVar9;

  int *piVar10;

  undefined ***pppuVar11;

  float *pfVar12;

  bool bVar13;

  bool bVar14;

  float fVar15;

  float fVar16;

  uint32_t /* width from decompiler */ *local_188;

  uint32_t /* width from decompiler */ *local_184;

  uint32_t /* width from decompiler */ local_17c;

  uint32_t /* width from decompiler */ local_174;

  float afStack_170 [5];

  uint32_t /* width from decompiler */ uStack_15c;

  uint32_t /* width from decompiler */ uStack_158;

  uint32_t /* width from decompiler */ uStack_154;

  float fStack_150;

  uint32_t /* width from decompiler */ uStack_14c;

  uint32_t /* width from decompiler */ uStack_148;

  uint32_t /* width from decompiler */ uStack_144;

  float *pfStack_140;

  uint32_t /* width from decompiler */ uStack_13c;

  uint32_t /* width from decompiler */ uStack_138;

  uint16_t uStack_134;

  uint32_t /* width from decompiler */ uStack_130;

  uint32_t /* width from decompiler */ uStack_12c;

  uint32_t /* width from decompiler */ uStack_128;

  uint32_t /* width from decompiler */ uStack_124;

  int *piStack_120;

  int *piStack_11c;

  int *piStack_118;

  undefined **local_110 [2];

  float fStack_108;

  uint32_t /* width from decompiler */ local_104;

  uint32_t /* width from decompiler */ local_100;

  uint32_t /* width from decompiler */ uStack_fc;

  float local_f8;

  uint32_t /* width from decompiler */ local_f4;

  uint32_t /* width from decompiler */ uStack_f0;

  uint32_t /* width from decompiler */ local_ec;

  float local_e8;

  uint32_t /* width from decompiler */ uStack_e4;

  uint32_t /* width from decompiler */ local_e0;

  uint32_t /* width from decompiler */ local_dc;

  uint32_t /* width from decompiler */ local_d8;

  uint16_t uStack_d4;

  uint16_t uStack_d2;

  uint32_t /* width from decompiler */ uStack_d0;

  float fStack_cc;

  uint32_t /* width from decompiler */ uStack_c8;

  uint32_t /* width from decompiler */ uStack_c4;

  uint32_t /* width from decompiler */ uStack_c0;

  uint32_t /* width from decompiler */ uStack_bc;

  uint32_t /* width from decompiler */ uStack_b8;

  uint32_t /* width from decompiler */ uStack_b4;

  uint32_t /* width from decompiler */ uStack_b0;

  uint32_t /* width from decompiler */ uStack_ac;

  uint32_t /* width from decompiler */ uStack_a8;

  float afStack_a0 [5];

  uint32_t /* width from decompiler */ uStack_8c;

  uint32_t /* width from decompiler */ uStack_88;

  uint32_t /* width from decompiler */ uStack_84;

  float fStack_80;

  uint32_t /* width from decompiler */ uStack_7c;

  uint32_t /* width from decompiler */ uStack_78;

  uint32_t /* width from decompiler */ uStack_74;

  uint32_t /* width from decompiler */ uStack_70;

  uint32_t /* width from decompiler */ uStack_6c;

  uint32_t /* width from decompiler */ uStack_68;

  float fStack_64;

  uint32_t /* width from decompiler */ uStack_60;

  uint32_t /* width from decompiler */ uStack_5c;

  uint32_t /* width from decompiler */ uStack_58;

  uint32_t /* width from decompiler */ uStack_54;

  uint32_t /* width from decompiler */ uStack_50;

  uint32_t /* width from decompiler */ uStack_4c;

  uint32_t /* width from decompiler */ uStack_48;

  uint32_t /* width from decompiler */ uStack_44;

  uint32_t /* width from decompiler */ uStack_40;

  uint32_t /* width from decompiler */ uStack_3c;

  uint32_t /* width from decompiler */ uStack_38;

  uint32_t /* width from decompiler */ uStack_34;

  uint32_t /* width from decompiler */ uStack_30;

  uint32_t /* width from decompiler */ uStack_2c;

  uint32_t /* width from decompiler */ uStack_28;

  uint32_t /* width from decompiler */ uStack_24;

  uint32_t /* width from decompiler */ uStack_20;

  void *pvStack_18;

  void *local_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ uStack_c;

  

  pvVar1 = ExceptionList;

  uStack_c = 0xffffffff;

  puStack_10 = &LAB_009a0f23;

  local_14 = ExceptionList;

  ExceptionList = &local_14;

  param_1[0x71] = *(uint32_t /* width from decompiler */ *)(DAT_00b037f0 + 4);

  fVar15 = g_flOne;

  if (*(int *)(param_1[0x67] + 0x19c) != 0) {

    param_1[99] = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1[0x67] + 0x19c) + 0x18c);

    goto LAB_0049aabe;

  }

  if (param_1[0x72] == 0) {

    ExceptionList = pvVar1;

    return 0;

  }

  if (*(int *)(param_1[0x72] + 0x2c) == 0) {

    ExceptionList = pvVar1;

    return 0;

  }

  if (DAT_00b037f0 == 0) {

    ExceptionList = pvVar1;

    return 0;

  }

  if (*(int *)(DAT_00b037f0 + 4) == 0) {

    ExceptionList = pvVar1;

    return 0;

  }

  FUN_00499a70();

  *(uint32_t /* width from decompiler */ **)(param_1[0x67] + 0x19c) = param_1;

  uVar3 = FUN_0040dab0();

  param_1[0x68] = uVar3;

  if (uVar3 < 100) {

    param_1[0x68] = 100;

  }

  if (32000 < (uint)param_1[0x68]) {

    param_1[0x68] = 32000;

  }

  FUN_005b82b0();

  *(uint32_t /* width from decompiler */ *)param_1[2] = 0;

  local_110[0] = (undefined **)param_1[0x68];

  local_110[1] = (undefined **)param_1[2];

  local_104 = 0;

  local_100 = 0;

  local_f8 = 0.0;

  local_f4 = 0;

  local_ec = 0;

  local_e8 = 0.0;

  local_e0 = 0;

  local_dc = 0;

  local_d8 = 0;

  iVar9 = (**(code **)*param_1)();

  fStack_108 = *(float *)(iVar9 + 4);

  uStack_f0 = 0xc;

  if (*(char *)((int)param_1 + 0x179) != '\0') {

    FUN_005b8190();

    iVar9 = (**(code **)*param_1)();

    local_100 = *(uint32_t /* width from decompiler */ *)(iVar9 + 0x1c);

    local_e8 = 5.60519e-45;

  }

  FUN_005b81b0();

  iVar4 = (**(code **)*param_1)();

  fVar15 = g_flOne;

  iVar9 = param_1[0x71];

  uVar7 = param_1[0x68];

  uStack_fc = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x24);

  uStack_e4 = 4;

  pppuVar11 = local_110;

  puVar8 = param_1 + 0x3a;

  for (iVar4 = 0xf; iVar4 != 0; iVar4 = iVar4 + -1) {

    *puVar8 = *pppuVar11;

    pppuVar11 = pppuVar11 + 1;

    puVar8 = puVar8 + 1;

  }

  param_1[0x33] = 4;

  param_1[0x53] = 0x18;

  *(uint16_t *)(param_1 + 0x35) = 3;

  param_1[0x21] = uVar7;

  if (((((iVar9 != 0) && (fVar15 < (float)param_1[0x24] || fVar15 == (float)param_1[0x24])) &&

       (0.0 < (float)param_1[0x23])) &&

      ((0.0 < (float)param_1[0x22] && (uVar3 = param_1[0x27], 3 < uVar3)))) &&

     (((uVar3 & uVar3 - 1) == 0 && (0.0 < (float)param_1[0x25])))) {

    fVar16 = (float)(int)uVar3;

    if ((int)uVar3 < 0) {

      fVar16 = fVar16 + _DAT_00aaa5dc;

    }

    if ((((float)param_1[0x25] <= fVar16 * (float)param_1[0x24]) && (0.0 < (float)param_1[0x26])) &&

       (((float)param_1[0x26] <= fVar16 * (float)param_1[0x24] &&

        ((0.0 < (float)param_1[0x28] && (0.0 < (float)param_1[0x29])))))) {

      uVar3 = param_1[0x33];

      bVar13 = (uVar3 & 1) != 0;

      bVar14 = (uVar3 & 4) == 0;

      if ((uVar3 & 2) == 0) {

        if (bVar13) {

joined_r0x0049ada5:

          if (!bVar14) goto LAB_0049b330;

        }

        else if (bVar14) goto LAB_0049b330;

        if (((((((((0.0 < (float)param_1[0x2a] || (float)param_1[0x2a] == 0.0) &&

                  (0.0 < (float)param_1[0x31] || (float)param_1[0x31] == 0.0)) &&

                 ((float)param_1[0x31] <= fVar15)) &&

                ((0.0 < (float)param_1[0x30] || (float)param_1[0x30] == 0.0 &&

                 ((float)param_1[0x30] <= fVar15)))) &&

               (((0.0 < (float)param_1[0x2f] || (float)param_1[0x2f] == 0.0 &&

                 (((float)param_1[0x2f] <= fVar15 &&

                  (0.0 < (float)param_1[0x2e] || (float)param_1[0x2e] == 0.0)))) &&

                ((float)param_1[0x2e] <= fVar15)))) &&

              (0.0 < (float)param_1[0x32] || (float)param_1[0x32] == 0.0)) &&

             ((((param_1[0x13] == 0 || (param_1[0x14] != 0)) || (param_1[0x15] != 0)) ||

              (((param_1[0x16] != 0 || (param_1[0x17] != 0)) || (param_1[0x18] != 0)))))) &&

            ((((((param_1[0x14] == 0 && (param_1[0x15] == 0)) &&

                ((param_1[0x16] == 0 && ((param_1[0x17] == 0 && (param_1[0x18] == 0)))))) ||

               (param_1[0x13] != 0)) &&

              (((param_1[0x14] == 0 || (param_1[0x1a] != 0)) &&

               ((((param_1[0x15] == 0 || (param_1[0x1b] != 0)) &&

                 (((param_1[0x16] == 0 || (param_1[0x1c] != 0)) &&

                  ((param_1[0x17] == 0 || (param_1[0x1d] != 0)))))) &&

                ((((param_1[0x18] == 0 || (param_1[0x1e] != 0)) &&

                  ((param_1[0x19] == 0 || (param_1[0x1f] != 0)))) &&

                 (((((param_1[0x3b] == 0 || (param_1[0x3c] != 0)) || (param_1[0x3d] != 0)) ||

                   ((param_1[0x3e] != 0 || (param_1[0x3f] != 0)))) || (param_1[0x40] != 0))))))))))

             && (((((param_1[0x3c] == 0 && (param_1[0x3d] == 0)) &&

                   ((param_1[0x3e] == 0 && ((param_1[0x3f] == 0 && (param_1[0x40] == 0)))))) ||

                  (param_1[0x3b] != 0)) &&

                 ((((param_1[0x3c] == 0 || (param_1[0x42] != 0)) &&

                   ((param_1[0x3d] == 0 || (param_1[0x43] != 0)))) &&

                  (((param_1[0x3e] == 0 || (param_1[0x44] != 0)) &&

                   ((param_1[0x3f] == 0 || (param_1[0x45] != 0)))))))))))) &&

           (((((((param_1[0x40] == 0 || (param_1[0x46] != 0)) &&

                ((param_1[0x41] == 0 || (param_1[0x47] != 0)))) &&

               ((param_1[0x4a] == 0 || (param_1[0x4b] != 0)))) &&

              ((param_1[0x4b] == 0 ||

               ((param_1[0x4a] != 0 && ((param_1[0x4b] == 0 || (param_1[0x4c] != 0)))))))) &&

             (((param_1[0x4f] == 0 || (param_1[0x50] != 0)) &&

              ((param_1[0x50] == 0 ||

               ((param_1[0x4f] != 0 && ((param_1[0x50] == 0 || (param_1[0x51] != 0)))))))))) &&

            ((((param_1[0x3b] == 0 || ((uint)param_1[0x21] <= (uint)param_1[0x3a])) &&

              (((param_1[0x4a] == 0 || ((uint)param_1[0x21] <= (uint)param_1[0x49])) &&

               ((param_1[0x4f] == 0 || ((uint)param_1[0x21] <= (uint)param_1[0x4e])))))) &&

             (((((uint)param_1[0x21] < 0x8000 && (param_1[0x21] != 0)) &&

               (*(ushort *)(param_1 + 0x35) < 0x20)) &&

              ((uint)((int)(param_1[0x59] - param_1[0x58]) / 0x70) < 0x10000)))))))) {

          iVar9 = (int)(param_1[0x59] - param_1[0x58]) >> 0x1f;

          local_184 = (uint32_t /* width from decompiler */ *)0x0;

          if ((int)(param_1[0x59] - param_1[0x58]) / 0x70 + iVar9 != iVar9) {

            local_188 = (uint32_t /* width from decompiler */ *)0x0;

            do {

              pfVar12 = (float *)(param_1[0x58] + (int)local_188);

              uVar3 = _fpclass((double)*pfVar12);

              fVar15 = g_flOne;

              if (((((uVar3 & 0x207) != 0) ||

                   (uVar3 = _fpclass((double)pfVar12[1]), fVar15 = g_flOne, (uVar3 & 0x207) != 0))

                  || (((uVar3 = _fpclass((double)pfVar12[2]), fVar15 = g_flOne, (uVar3 & 0x207) != 0

                       || ((uVar3 = _fpclass((double)pfVar12[3]), fVar15 = g_flOne,

                           (uVar3 & 0x207) != 0 ||

                           (uVar3 = _fpclass((double)pfVar12[4]), fVar15 = g_flOne,

                           (uVar3 & 0x207) != 0)))) ||

                      (uVar3 = _fpclass((double)pfVar12[5]), fVar15 = g_flOne, (uVar3 & 0x207) != 0)

                      ))) ||

                 (((((((uVar3 = _fpclass((double)pfVar12[6]), fVar15 = g_flOne, (uVar3 & 0x207) != 0

                       || (uVar3 = _fpclass((double)pfVar12[7]), fVar15 = g_flOne,

                          (uVar3 & 0x207) != 0)) ||

                      (uVar3 = _fpclass((double)pfVar12[8]), fVar15 = g_flOne, (uVar3 & 0x207) != 0)

                      ) || (((uVar3 = _fpclass((double)pfVar12[9]), fVar15 = g_flOne,

                             (uVar3 & 0x207) != 0 ||

                             (uVar3 = _fpclass((double)pfVar12[10]), fVar15 = g_flOne,

                             (uVar3 & 0x207) != 0)) ||

                            ((uVar3 = _fpclass((double)pfVar12[0xb]), fVar15 = g_flOne,

                             (uVar3 & 0x207) != 0 ||

                             ((pfVar12[0x10] <= 0.0 && pfVar12[0x10] != 0.0 ||

                              (pfVar12[0x11] <= 0.0 && pfVar12[0x11] != 0.0)))))))) ||

                    (pfVar12[0x12] <= 0.0 && pfVar12[0x12] != 0.0)) ||

                   (((((pfVar12[0x13] <= 0.0 && pfVar12[0x13] != 0.0 ||

                       (pfVar12[0x14] <= 0.0 && pfVar12[0x14] != 0.0)) ||

                      (uVar3 = _fpclass((double)pfVar12[0x12]), fVar15 = g_flOne,

                      (uVar3 & 0x207) != 0)) ||

                     ((uVar3 = _fpclass((double)pfVar12[0x13]), fVar15 = g_flOne,

                      (uVar3 & 0x207) != 0 ||

                      (uVar3 = _fpclass((double)pfVar12[0x14]), fVar15 = g_flOne,

                      (uVar3 & 0x207) != 0)))) || (pfVar12[0x15] <= 0.0 && pfVar12[0x15] != 0.0))))

                  || (((((uint)pfVar12[0xf] & 3) == 0 || (((uint)pfVar12[0xd] & 3) == 0)) ||

                      ((pfVar12[0x17] <= 0.0 && pfVar12[0x17] != 0.0 ||

                       ((pfVar12[0x16] <= 0.0 && pfVar12[0x16] != 0.0 ||

                        (pfVar12[0x18] <= 0.0 && pfVar12[0x18] != 0.0)))))))))) goto LAB_0049b330;

              local_188 = (uint32_t /* width from decompiler */ *)((int)local_188 + 0x70);

              local_184 = (uint32_t /* width from decompiler */ *)((int)local_184 + 1);

            } while (local_184 < (uint)((int)(param_1[0x59] - param_1[0x58]) / 0x70));

          }

          uVar7 = (**(code **)(*(int *)param_1[0x71] + 0x164))();

          param_1[99] = uVar7;

          fVar15 = g_flOne;

        }

      }

      else if (!bVar13) goto joined_r0x0049ada5;

    }

  }

LAB_0049b330:

  if (param_1[99] == 0) {

    *(uint32_t /* width from decompiler */ *)(param_1[0x67] + 0x19c) = 0;

    ExceptionList = local_14;

    return 0;

  }

LAB_0049aabe:

  if (*(int **)(param_1[0x72] + 0x10) == (int *)0x0) {

    local_17c = param_1[0xb];

    local_174 = param_1[0xd];

    fVar16 = (float)param_1[0xc];

  }

  else {

    (**(code **)(**(int **)(param_1[0x72] + 0x10) + 0x144))();

    iVar9 = *(int *)(param_1[0x72] + 0x10);

    local_174 = *(uint32_t /* width from decompiler */ *)(iVar9 + 0x88);

    local_17c = *(uint32_t /* width from decompiler */ *)(iVar9 + 0x80);

    fVar16 = *(float *)(iVar9 + 0x84);

    fVar15 = g_flOne;

  }

  local_188 = (uint32_t /* width from decompiler */ *)param_1[0x74];

  fVar16 = fVar16 + DAT_00a110d8;

  local_184 = local_188;

  if (local_188 != (uint32_t /* width from decompiler */ *)param_1[0x75]) {

    do {

      local_184 = local_184 + 1;

      pvVar1 = (void *)*local_188;

      if (*(char *)((int)pvVar1 + 0x7c) == '\0') {

        *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 0x24) = local_17c;

        *(float *)((int)pvVar1 + 0x28) = fVar16;

        *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 0x2c) = local_174;

      }

      else {

        if (param_1[0x65] == 0) {

          piStack_120 = (int *)0x0;

          piStack_118 = (int *)0x0;

          pfVar12 = afStack_170;

          for (iVar9 = 0x18; iVar9 != 0; iVar9 = iVar9 + -1) {

            *pfVar12 = 0.0;

            pfVar12 = pfVar12 + 1;

          }

          pfStack_140 = (float *)0x0;

          uStack_13c = 0;

          afStack_170[1] = 0.0;

          afStack_170[2] = 0.0;

          afStack_170[3] = 0.0;

          uStack_15c = 0;

          uStack_158 = 0;

          uStack_154 = 0;

          uStack_144 = 0;

          uStack_148 = 0;

          uStack_14c = 0;

          uStack_138 = 0;

          uStack_130 = 0;

          uStack_12c = 0;

          uStack_134 = 0;

          uStack_128 = 0;

          piStack_11c = piStack_120;

          uStack_124 = 1;

          uStack_48 = DAT_009c7b84;

          afStack_a0[1] = 0.0;

          afStack_a0[2] = 0.0;

          afStack_a0[3] = 0.0;

          uStack_8c = 0;

          uStack_88 = 0;

          uStack_84 = 0;

          uStack_74 = 0;

          uStack_78 = 0;

          uStack_7c = 0;

          uStack_68 = 0;

          uStack_6c = 0;

          uStack_70 = 0;

          uStack_58 = 0;

          uStack_5c = 0;

          uStack_60 = 0;

          uStack_4c = 0;

          uStack_50 = 0;

          uStack_54 = 0;

          fStack_64 = 0.0;

          uStack_44 = 0;

          uStack_40 = DAT_00a10e78;

          uStack_3c = DAT_00aaa668;

          uStack_30 = DAT_00aaa668;

          uStack_2c = DAT_00aaa668;

          uStack_38 = 0;

          uStack_28 = 4;

          uStack_34 = 0x900;

          uStack_24 = DAT_00aaa668;

          uStack_20 = 0;

          local_110[1] = (undefined **)0x1;

          local_110[0] = &PTR_FUN_009c7bb4;

          local_104 = 0;

          local_100 = 0;

          uStack_fc = 0;

          local_f4 = 0;

          uStack_f0 = 0;

          local_ec = 0;

          local_dc = 0;

          local_e0 = 0;

          uStack_e4 = 0;

          local_d8 = 8;

          uStack_d2 = 0;

          uStack_d0 = 0;

          uStack_c4 = DAT_00aaa668;

          uStack_c8 = DAT_00aaa668;

          uStack_c0 = 0;

          uStack_bc = 0;

          uStack_b8 = 0;

          uStack_b4 = 0;

          uStack_b0 = 0;

          uStack_ac = 0;

          uStack_c = 1;

          uStack_d4 = 1;

          uStack_a8 = DAT_00a10e78;

          afStack_170[0] = fVar15;

          afStack_170[4] = fVar15;

          fStack_150 = fVar15;

          fStack_108 = fVar15;

          local_f8 = fVar15;

          local_e8 = fVar15;

          fStack_cc = fVar15;

          afStack_a0[0] = fVar15;

          afStack_a0[4] = fVar15;

          fStack_80 = fVar15;

          if ((piStack_118 <= piStack_120) &&

             ((piStack_120 == (int *)0x0 || ((uint)((int)piStack_118 - (int)piStack_120 >> 2) < 2)))

             ) {

            piVar5 = malloc(8);

            piVar10 = piVar5;

            for (piVar6 = piStack_120; piVar6 != piStack_11c; piVar6 = piVar6 + 1) {

              *piVar10 = *piVar6;

              piVar10 = piVar10 + 1;

            }

            if (piStack_120 != (int *)0x0) {

              free(piStack_120);

            }

            piStack_118 = piVar5 + 2;

            piStack_11c = piVar5 + ((int)piStack_11c - (int)piStack_120 >> 2);

            piStack_120 = piVar5;

          }

          fStack_64 = g_flMultiKillCountBlend;

          *piStack_11c = (int)local_110;

          piStack_11c = piStack_11c + 1;

          pfStack_140 = afStack_a0;

          uStack_34 = 0x80;

          uStack_28 = 1;

          uStack_144 = 0;

          uStack_148 = 0;

          uStack_14c = 0;

          uVar7 = (**(code **)(*(int *)param_1[0x71] + 0x18))();

          param_1[0x65] = uVar7;

          local_110[0] = &PTR_FUN_009c7b8c;

          uStack_c = 0xffffffff;

          if (piStack_120 != (int *)0x0) {

            free(piStack_120);

          }

          piStack_120 = (int *)0x0;

          piStack_11c = (int *)0x0;

          piStack_118 = (int *)0x0;

        }

        puVar8 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)param_1[0x65] + 0x50))();

        *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 0x30) = *puVar8;

      }

      param_1[8] = *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 0x60);

      iVar9 = (**(code **)(*(int *)param_1[99] + 4))();

      *(int *)((int)pvVar1 + 0x70) = iVar9;

      if (iVar9 == 0) {

        if (*(int **)((int)pvVar1 + 0x30) != (int *)0x0) {

          iVar9 = *(int *)param_1[0x71];

          (**(code **)(**(int **)((int)pvVar1 + 0x30) + 4))();

          (**(code **)(iVar9 + 0x1c))();

        }

        memmove(local_188,local_184,(param_1[0x75] - (int)local_184 >> 2) * 4);

        param_1[0x75] = param_1[0x75] + -4;

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar1);

      }

      *(uint32_t /* width from decompiler */ **)(iVar9 + 4) = param_1;

      local_188 = local_188 + 1;

      fVar15 = g_flOne;

    } while (local_188 != (uint32_t /* width from decompiler */ *)param_1[0x75]);

  }

  puVar8 = operator_new(8);

  if (puVar8 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar8 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    *puVar8 = 0;

    puVar8[1] = 0;

  }

  param_1[0x66] = puVar8;

  uVar7 = (**(code **)(*(int *)param_1[99] + 0x30))();

  cVar2 = FUN_0049a240(uVar7);

  if (cVar2 == '\0') {

    FUN_00499a70();

    ExceptionList = pvStack_18;

    return 0;

  }

  *(uint8_t *)(param_1 + 0x77) = 1;

  if (*(int *)(*(int *)(param_1[0x67] + 0x19c) + 0xc) == 0) {

    FUN_007a4480(0,"INITIALIZE: NO MAXPARTICLES ON MASTER FLUID");

  }

  ExceptionList = pvStack_18;

  return 1;

}
