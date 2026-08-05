// READABILITY (auto CF):
//  - Body size: ~919 non-empty decompiler lines.
//  - Control keywords: if×106, goto×7, return×5, while×5, do×4, for×3.
//  - Notable callees: CVOGReaction_RandomUnitScalar×25, CONCAT31×9, FUN_004e9530×7, FUN_0076cef0×6, FUN_0076cf00×5, FUN_004f2e20×4, FUN_004f2e70×3, FUN_0058fd30×3.
//  - Strings: "Just created"; "skyboxphase"; "SkyBoxParticles"; "ragdoll".
//  - Return sites: 5.

// =============================================================================
// Named_SkyBoxParticles_005911b0
// -----------------------------------------------------------------------------
// Stable ID: aa_005911b0
// Address:   0x005911b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "SkyBoxParticles"
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



uint32_t /* width from decompiler */ __thiscall Named_SkyBoxParticles_005911b0(int *param_1,char param_2)



{

  float *pfVar1;

  ushort uVar2;

  ushort uVar3;

  uint32_t /* width from decompiler */ *puVar4;

  char cVar5;

  byte bVar6;

  int iVar7;

  int *piVar8;

  int *piVar9;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar10;

  void *pvVar11;

  void *pvVar12;

  char *pcVar13;

  float *pfVar14;

  char *pcVar15;

  int *extraout_ECX;

  uint extraout_ECX_00;

  uint extraout_ECX_01;

  uint uVar16;

  uint32_t /* width from decompiler */ extraout_EDX;

  int iVar17;

  float fVar18;

  float fVar19;

  float fVar20;

  uint64_t uVar21;

  int iVar22;

  uint32_t /* width from decompiler */ uVar23;

  int *local_4f8;

  int *piStack_4f4;

  float local_4f0;

  float local_4ec;

  float local_4e8;

  int *piStack_4e4;

  float local_4e0;

  float fStack_4dc;

  float fStack_4d8;

  float fStack_4d4;

  float fStack_4cc;

  float fStack_4c8;

  uint32_t /* width from decompiler */ uStack_4c4;

  uint8_t uStack_4bd;

  float fStack_4bc;

  float fStack_4b8;

  float fStack_4b4;

  float local_4b0;

  float local_4ac;

  float local_4a8;

  float local_4a4;

  float fStack_4a0;

  float fStack_49c;

  float fStack_498;

  float fStack_494;

  float local_490;

  float fStack_48c;

  float fStack_488;

  float fStack_474;

  float fStack_470;

  float fStack_46c;

  float fStack_468;

  float fStack_464;

  float fStack_460;

  int *piStack_458;

  int *local_454;

  uint8_t local_450 [12];

  uint8_t auStack_444 [4];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_440 [8];

  float fStack_438;

  void *local_1c;

  uint8_t *puStack_18;

  uint local_14;

  

  local_14 = 0xffffffff;

  puStack_18 = &LAB_009a595f;

  local_1c = ExceptionList;

  local_454 = DAT_00d1f040;

  ExceptionList = &local_1c;

  FUN_0076cf00("Just created");

  local_14 = 0;

  if ((*(byte *)(param_1 + 0x244) & 1) != 0) goto LAB_0059320b;

  if ((param_2 == '\0') &&

     (((*(byte *)((int)param_1 + 0x90d) & 1) != 0 ||

      ((((*(byte *)(param_1 + 0x243) & 0x80) != 0 && (DAT_00b036d4 != (int *)0x0)) &&

       (*DAT_00b036d4 != 0)))))) {

    local_4f8 = param_1;

    FUN_004a7a20(&local_4f8);

    local_14 = 0xffffffff;

    FUN_0076cef0();

    ExceptionList = local_1c;

    return 0;

  }

  param_1[0x206] = param_1[0x209];

  param_1[0x207] = param_1[0x20a];

  param_1[0x208] = param_1[0x20b];

  if (param_1[0x245] != 0) {

    FUN_004e9530(local_450,param_1 + 0x206);

    if ((*(byte *)((int)param_1 + 0x90d) & 0x20) == 0) {

      if ((char)param_1[0x237] == '\0') {

        param_1[0x231] = param_1[0x225];

        param_1[0x232] = param_1[0x226];

        param_1[0x233] = param_1[0x227];

        param_1[0x234] = param_1[0x228];

      }

      else {

        param_1[0x231] = 0;

        param_1[0x232] = 0;

        param_1[0x233] = 0;

        param_1[0x234] = (int)g_flOne;

      }

    }

    else {

      if ((*(byte *)((int)param_1 + 0x90d) & 0x40) == 0) {

        local_4f0 = (float)param_1[0x229];

        local_4ec = (float)param_1[0x22a];

        local_4e8 = (float)param_1[0x22b];

      }

      else {

        local_4f0 = (float)param_1[0x22c];

        local_4ec = (float)param_1[0x22d];

        local_4e8 = (float)param_1[0x22e];

        iVar7 = CVOGReaction_RandomUnitScalar();

        if (0xfffff < *(int *)(iVar7 + 0xc)) {

          *(uint32_t /* width from decompiler */ *)(iVar7 + 0xc) = 0;

        }

        uVar2 = *(ushort *)(*(int *)(iVar7 + 8) + *(int *)(iVar7 + 0xc) * 2);

        *(int *)(iVar7 + 0xc) = *(int *)(iVar7 + 0xc) + 1;

        local_4f0 = (float)uVar2 * local_4f0 * DAT_00aaa638;

        iVar7 = CVOGReaction_RandomUnitScalar();

        if (0xfffff < *(int *)(iVar7 + 0xc)) {

          *(uint32_t /* width from decompiler */ *)(iVar7 + 0xc) = 0;

        }

        uVar2 = *(ushort *)(*(int *)(iVar7 + 8) + *(int *)(iVar7 + 0xc) * 2);

        *(int *)(iVar7 + 0xc) = *(int *)(iVar7 + 0xc) + 1;

        local_4ec = (float)uVar2 * local_4ec * DAT_00aaa638;

        iVar7 = CVOGReaction_RandomUnitScalar();

        if (0xfffff < *(int *)(iVar7 + 0xc)) {

          *(uint32_t /* width from decompiler */ *)(iVar7 + 0xc) = 0;

        }

        uVar2 = *(ushort *)(*(int *)(iVar7 + 8) + *(int *)(iVar7 + 0xc) * 2);

        *(int *)(iVar7 + 0xc) = *(int *)(iVar7 + 0xc) + 1;

        local_4f0 = (float)param_1[0x229] + local_4f0;

        local_4ec = (float)param_1[0x22a] + local_4ec;

        local_4e8 = (float)param_1[0x22b] + (float)uVar2 * local_4e8 * DAT_00aaa638;

      }

      if (local_4e8 * local_4e8 + local_4ec * local_4ec + local_4f0 * local_4f0 <

          g_flMsToSeconds_Inferred) {

        local_4f0 = 0.0;

        local_4ec = g_flOne;

        local_4e8 = 0.0;

      }

      FUN_0076f5f0(&local_4f0,&local_4f0);

      if ((*(byte *)((int)param_1 + 0x90d) & 0x80) == 0) {

        fVar18 = (float)param_1[0x22f];

      }

      else {

        iVar7 = CVOGReaction_RandomUnitScalar();

        if (0xfffff < *(int *)(iVar7 + 0xc)) {

          *(uint32_t /* width from decompiler */ *)(iVar7 + 0xc) = 0;

        }

        uVar2 = *(ushort *)(*(int *)(iVar7 + 8) + *(int *)(iVar7 + 0xc) * 2);

        *(int *)(iVar7 + 0xc) = *(int *)(iVar7 + 0xc) + 1;

        fVar18 = (float)uVar2 * (float)param_1[0x230] * DAT_00aaa638 + (float)param_1[0x22f];

      }

      local_4f8 = (int *)(fVar18 * DAT_009cb158);

      piVar9 = param_1 + 0x231;

      FUN_0076f900(piVar9,&local_4f0,local_4f8);

      if ((char)param_1[0x237] == '\0') {

        FUN_0076df50(piVar9,piVar9,param_1 + 0x225);

      }

    }

    FUN_004e8860(param_1 + 0x231,local_440);

    FUN_004e9530(&local_4b0,param_1 + 0x218);

    if ((char)param_1[0x21e] != '\0') {

      iVar7 = CVOGReaction_RandomUnitScalar();

      if (0xfffff < *(int *)(iVar7 + 0xc)) {

        *(uint32_t /* width from decompiler */ *)(iVar7 + 0xc) = 0;

      }

      local_4f8 = (int *)CONCAT22(local_4f8._2_2_,

                                  *(uint16_t *)(*(int *)(iVar7 + 8) + *(int *)(iVar7 + 0xc) * 2));

      *(int *)(iVar7 + 0xc) = *(int *)(iVar7 + 0xc) + 1;

      iVar7 = CVOGReaction_RandomUnitScalar();

      if (0xfffff < *(int *)(iVar7 + 0xc)) {

        *(uint32_t /* width from decompiler */ *)(iVar7 + 0xc) = 0;

      }

      uVar2 = *(ushort *)(*(int *)(iVar7 + 8) + *(int *)(iVar7 + 0xc) * 2);

      *(int *)(iVar7 + 0xc) = *(int *)(iVar7 + 0xc) + 1;

      iVar7 = CVOGReaction_RandomUnitScalar();

      if (0xfffff < *(int *)(iVar7 + 0xc)) {

        *(uint32_t /* width from decompiler */ *)(iVar7 + 0xc) = 0;

      }

      fVar18 = DAT_00aaa638;

      uVar3 = *(ushort *)(*(int *)(iVar7 + 8) + *(int *)(iVar7 + 0xc) * 2);

      *(int *)(iVar7 + 0xc) = *(int *)(iVar7 + 0xc) + 1;

      local_4a8 = (float)((uint)local_4f8 & 0xffff) * (float)param_1[0x21d] * fVar18 + local_4a8;

      local_4ac = (float)uVar2 * (float)param_1[0x21c] * fVar18 + local_4ac;

      local_4b0 = local_4b0 + (float)uVar3 * (float)param_1[0x21b] * fVar18;

    }

    FUN_004e8bf0(local_450,local_440,&local_4b0,&local_490);

    piVar8 = (int *)FUN_004e88e0(&local_4e0,&local_490);

    piVar9 = param_1 + 0x206;

    *piVar9 = *piVar8;

    param_1[0x207] = piVar8[1];

    param_1[0x208] = piVar8[2];

    uVar23 = 3;

    (**(code **)(*(int *)param_1[0x245] + 0x10))(3,piVar9);

    FUN_0040cf90(uVar23);

    (**(code **)(*(int *)param_1[0x245] + 0x10))(3,param_1 + 0x231);

    FUN_0040d1a0(piVar9);

    iVar7 = *(int *)(param_1[0x245] + 0xc0);

    if ((iVar7 != 0) && (iVar7 = *(int *)(param_1[0x245] + 0xc4) - iVar7 >> 2, 0 < iVar7)) {

      piStack_4e4 = DAT_00d1f040;

      FUN_0076cf00("skyboxphase");

      local_14 = CONCAT31(local_14._1_3_,1);

      FUN_005972d0(iVar7);

      iVar17 = 0;

      if (0 < iVar7) {

        do {

          local_4f8 = (int *)(*(int *)(*(int *)(param_1[0x245] + 0xc0) + iVar17 * 4) + 0x20);

          if ((local_4f8 != (int *)0x0) && (local_4f8 != *(int **)(param_1[2] + -4 + iVar17 * 4))) {

            if ((*(byte *)(param_1 + 0x243) & 2) != 0) {

              FUN_0096ff50("SkyBoxParticles");

            }

            FUN_00597280(&local_4f8);

          }

          iVar17 = iVar17 + 1;

        } while (iVar17 < iVar7);

      }

      local_14 = local_14 & 0xffffff00;

      FUN_0076cef0();

    }

    if (((((*(byte *)((int)param_1 + 0x90e) & 0x80) != 0) && (param_1[5] != 0)) &&

        (piVar9 = *(int **)(param_1[5] + 0x10), piVar9 != (int *)0x0)) &&

       ((((uint)piVar9[0x5f] >> 6 & 1) != 0 && ((*(byte *)((int)param_1 + 0x90f) & 1) == 0)))) {

      if (param_1[0x97] < 0) {

        iVar7 = (**(code **)(*piVar9 + 0x1cc))();

        if (*(int *)(iVar7 + 8) == 0) goto LAB_00591885;

        iVar7 = param_1[0x95];

        iVar17 = param_1[0x245];

        iVar22 = param_1[0x96];

      }

      else {

        iVar7 = (**(code **)(*piVar9 + 0x1d4))();

        if ((iVar7 == 0) || (*(int *)(iVar7 + 0x340 + (char)param_1[0x97] * 4) == 0)) {

          iVar7 = (**(code **)(**(int **)(param_1[5] + 0x10) + 0x214))();

          if ((iVar7 == 0) ||

             (iVar7 = (**(code **)(**(int **)(param_1[5] + 0x10) + 0x214))(),

             *(int *)(iVar7 + 0x284) == 0)) goto LAB_00591885;

          (**(code **)(**(int **)(param_1[5] + 0x10) + 0x214))();

          iVar7 = param_1[0x95];

          iVar17 = param_1[0x245];

          iVar22 = param_1[0x96];

        }

        else {

          iVar7 = param_1[0x95];

          iVar17 = param_1[0x245];

          iVar22 = param_1[0x96];

        }

      }

      FUN_0096dc80(iVar22,iVar17,iVar7);

      *(byte *)((int)param_1 + 0x90f) = *(byte *)((int)param_1 + 0x90f) | 1;

    }

  }

LAB_00591885:

  iVar7 = param_1[10];

  if ((iVar7 != 0) && ((*(uint *)(iVar7 + 0x3c8) & 0x200) != 0)) {

    if ((*(uint *)(iVar7 + 0x3c8) & 0x400) == 0) {

      param_1[0xa2] = *(int *)(iVar7 + 800);

    }

    else {

      iVar7 = CVOGReaction_RandomUnitScalar();

      if (0xfffff < *(int *)(iVar7 + 0xc)) {

        *(uint32_t /* width from decompiler */ *)(iVar7 + 0xc) = 0;

      }

      uVar2 = *(ushort *)(*(int *)(iVar7 + 8) + *(int *)(iVar7 + 0xc) * 2);

      *(int *)(iVar7 + 0xc) = *(int *)(iVar7 + 0xc) + 1;

      param_1[0xa2] =

           (int)((float)uVar2 * *(float *)(param_1[10] + 0x324) * DAT_00aaa638 +

                *(float *)(param_1[10] + 800));

    }

  }

  if (((*(byte *)((int)param_1 + 0x90d) & 4) != 0) && ((*(byte *)((int)param_1 + 0x90d) & 8) == 0))

  {

    local_4f8 = DAT_00d1f040;

    FUN_0076cf00("ragdoll");

    *(byte *)((int)param_1 + 0x90d) = *(byte *)((int)param_1 + 0x90d) | 8;

    piVar9 = param_1 + 0x74;

    local_14._0_1_ = 2;

    FUN_007b6a20(piVar9);

    piVar9 = (int *)FUN_007b7420(piVar9);

    if (piVar9 != (int *)0x0) {

      iVar7 = piVar9[1];

      uVar23 = (**(code **)(*piVar9 + 0x1c))(param_1);

      cVar5 = FUN_005f44c0(iVar7,uVar23);

      piVar8 = (int *)param_1[0x245];

      *(byte *)((int)param_1 + 0x90d) =

           *(byte *)((int)param_1 + 0x90d) ^ (cVar5 * '\x04' ^ *(byte *)((int)param_1 + 0x90d)) & 4;

      if ((*(byte *)((int)param_1 + 0x90d) & 4) == 0) {

        pcVar15 = "Unknown";

        if (piVar8 != (int *)0x0) {

          pbVar10 = local_440;

          FUN_005961b0(pbVar10);

          pbVar10 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

                    FUN_0096a630(pbVar10);

          local_14._0_1_ = 3;

          pcVar15 = std::

                    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

                    c_str(pbVar10);

          local_14._0_1_ = 2;

          std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

          ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_440);

        }

        FUN_007a4480(0xffffffff,

                     "RagDoll file read error for <%s>, matching it up with gfxBody <%s>.",

                     param_1 + 0x74,pcVar15);

      }

      else if ((piVar8 != (int *)0x0) &&

              (iVar7 = (**(code **)(*piVar8 + 0xc))(), *(float *)(iVar7 + 0x9c) != g_flOne)) {

        param_1[0x236] = (int)g_flOne;

        (**(code **)(*(int *)param_1[0x245] + 0x1c))(0x3f800000);

      }

      (**(code **)*piVar9)(1);

    }

    local_14 = (uint)local_14._1_3_ << 8;

    FUN_0076cef0();

  }

  if (((((*(byte *)(param_1 + 0x243) & 0x80) == 0) && ((*(byte *)((int)param_1 + 0x90d) & 1) == 0))

      || (param_1[5] == 0)) || (*(int *)(param_1[5] + 0x2c) == 0)) goto LAB_0059320b;

  piStack_458 = DAT_00d1f040;

  FUN_0076cf00("rigidbody");

  piStack_4e4 = (int *)param_1[0x236];

  local_14 = CONCAT31(local_14._1_3_,4);

  if ((param_1[10] != 0) && ((*(byte *)(param_1[10] + 0x3c9) & 2) != 0)) {

    piStack_4e4 = (int *)((float)param_1[0xa2] * (float)piStack_4e4);

  }

  if ((float)piStack_4e4 == g_flZero) {

    piStack_4e4 = (int *)g_flOne;

  }

  piVar9 = piStack_4e4;

  if (((char)param_1[0x243] < '\0') || ((*(byte *)((int)param_1 + 0x90d) & 1) != 0)) {

    uVar23 = extraout_EDX;

    if ((char)param_1[0x243] < '\0') {

      uVar21 = FUN_00590cb0((int)param_1 + 0x2be,piStack_4e4,param_1[0x2d],param_1[0x2e],

                            param_1[0xa1]);

      uVar23 = (uint32_t /* width from decompiler */)((ulonglong)uVar21 >> 0x20);

      param_1[0x98] = (int)uVar21;

    }

    if ((((DAT_00b036d4 != (int *)0x0) && (*DAT_00b036d4 != 0)) && (param_1[5] != 0)) &&

       (iVar7 = *(int *)(param_1[5] + 0x2c), iVar7 != 0)) {

      local_4f8 = (int *)FUN_0058fd30((int)param_1 + 0x2be,piVar9,param_1[0x2d],param_1[0x2e],

                                      param_1[0xa1],

                                      CONCAT31((int3)((uint)uVar23 >> 8),

                                               *(uint8_t *)((int)param_1 + 0x90d)) & 0xffffff01,

                                      iVar7);

      if (local_4f8 != (int *)0x0) {

        FUN_00597230(&local_4f8);

        FUN_005971e0(&piStack_4e4);

        iVar7 = 0;

        if ((short)param_1[0xaf] != 1 && -1 < (short)param_1[0xaf] + -1) {

          do {

            iVar17 = CVOGReaction_RandomUnitScalar();

            if (0xfffff < *(int *)(iVar17 + 0xc)) {

              *(uint32_t /* width from decompiler */ *)(iVar17 + 0xc) = 0;

            }

            uVar2 = *(ushort *)(*(int *)(iVar17 + 8) + *(int *)(iVar17 + 0xc) * 2);

            *(int *)(iVar17 + 0xc) = *(int *)(iVar17 + 0xc) + 1;

            local_4f8 = (int *)(uint)uVar2;

            piStack_4e4 = (int *)((float)(int)local_4f8 * *(float *)(param_1[10] + 0x324) *

                                  DAT_00aaa638 + *(float *)(param_1[10] + 800));

            local_4f8 = (int *)FUN_0058fd30((int)param_1 + 0x2be,piStack_4e4,param_1[0x2d],

                                            param_1[0x2e],param_1[0xa1],

                                            CONCAT31((int3)((uint)*(uint32_t /* width from decompiler */ *)(param_1[5] + 0x2c)

                                                           >> 8),

                                                     *(uint8_t *)((int)param_1 + 0x90d)) &

                                            0xffffff01,*(uint32_t /* width from decompiler */ *)(param_1[5] + 0x2c));

            if (local_4f8 != (int *)0x0) {

              FUN_00597230(&local_4f8);

              piStack_4f4 = (int *)((float)param_1[0x236] * (float)piStack_4e4);

              FUN_005971e0(&piStack_4f4);

            }

            iVar7 = iVar7 + 1;

          } while (iVar7 < (short)param_1[0xaf] + -1);

        }

      }

    }

    if (param_1[0x98] == 0) {

      if ((param_1[0x9a] == 0) ||

         (piStack_4f4 = (int *)(param_1[0x9b] - param_1[0x9a] >> 2), piStack_4f4 == (int *)0x0)) {

        piStack_4f4 = operator_new(0x180);

        local_14._0_1_ = 5;

        if (piStack_4f4 == (int *)0x0) {

          pvVar11 = (void *)0x0;

        }

        else {

          pvVar11 = (void *)FUN_004b6750();

        }

        local_14 = CONCAT31(local_14._1_3_,4);

        cVar5 = FUN_004a6910();

        if (cVar5 == '\0') {

          *(uint32_t /* width from decompiler */ *)((int)pvVar11 + 0x100) = 0;

          piVar9 = extraout_ECX;

        }

        else {

          pvVar12 = operator_new(100);

          if (pvVar12 == (void *)0x0) {

            iVar7 = 0;

          }

          else {

            iVar7 = FUN_004f32d0();

          }

          piVar9 = (int *)((int)pvVar11 + 0x100);

          *piVar9 = iVar7;

          if ((*(byte *)((int)param_1 + 0x90d) & 1) != 0) {

            *(uint16_t *)(iVar7 + 0x3c) = 4;

          }

        }

        local_4f8 = (int *)((int)pvVar11 + 0x100);

        if (((float)param_1[0xa1] <= _DAT_00aaa940) ||

           (DAT_00aaa620 < (float)param_1[0xa1] || DAT_00aaa620 == (float)param_1[0xa1])) {

          uVar23 = 0;

        }

        else {

          uVar23 = 1;

        }

        pcVar15 = (char *)((int)param_1 + 0x2be);

        uVar23 = FUN_004ee080(pcVar15,param_1[0xa1],0x3f800000,local_4f8,1,uVar23,1,

                              CONCAT31((int3)((uint)piVar9 >> 8),

                                       *(uint8_t *)((int)param_1 + 0x90d)) & 0xffffff01,

                              0x3f800000,0x3f000000,0,0);

        fVar18 = g_flOne;

        *(uint32_t /* width from decompiler */ *)((int)pvVar11 + 0x108) = uVar23;

        *(float *)((int)pvVar11 + 0x170) = fVar18;

        pcVar13 = pcVar15;

        do {

          cVar5 = *pcVar13;

          pcVar13[(int)pvVar11 - (int)pcVar15] = cVar5;

          pcVar13 = pcVar13 + 1;

        } while (cVar5 != '\0');

        if ((*(int *)((int)pvVar11 + 0x108) == 0) && (*local_4f8 == 0)) {

          FUN_004ebee0();

                    /* WARNING: Subroutine does not return */

          operator_delete(pvVar11);

        }

        cVar5 = FUN_00590190(pvVar11);

        if (cVar5 == '\0') {

          puVar4 = *(uint32_t /* width from decompiler */ **)((int)pvVar11 + 0x108);

          if ((puVar4 != (uint32_t /* width from decompiler */ *)0x0) &&

             (*(short *)((int)puVar4 + 6) = *(short *)((int)puVar4 + 6) + -1,

             *(short *)((int)puVar4 + 6) == 0)) {

            (**(code **)*puVar4)(1);

          }

          piStack_4f4 = (int *)*local_4f8;

          if (piStack_4f4 == (int *)0x0) {

            *local_4f8 = 0;

            FUN_004ebee0();

                    /* WARNING: Subroutine does not return */

            operator_delete(pvVar11);

          }

          FUN_004b55e0();

                    /* WARNING: Subroutine does not return */

          operator_delete(piStack_4f4);

        }

        if ((param_1[0x240] != 0) && (*(int *)((int)pvVar11 + 0x108) != 0)) {

          *(int *)(*(int *)((int)pvVar11 + 0x108) + 0x28) = param_1[0x240];

        }

        uVar16 = extraout_ECX_00;

        if ((*(byte *)(param_1 + 0x243) & 0x80) != 0) {

          iVar7 = FUN_00590cb0(pcVar15,piStack_4e4,param_1[0x2d],param_1[0x2e],param_1[0xa1]);

          param_1[0x98] = iVar7;

          uVar16 = extraout_ECX_01;

        }

        if ((((*local_4f8 != 0) && (param_1[5] != 0)) && (*(int *)(param_1[5] + 0x2c) != 0)) &&

           (iVar7 = 0, 0 < (short)param_1[0xaf])) {

          do {

            piStack_4f4 = (int *)FUN_0058fd30(pcVar15,piStack_4e4,param_1[0x2d],param_1[0x2e],

                                              param_1[0xa1],

                                              CONCAT31((int3)(uVar16 >> 8),

                                                       *(uint8_t *)((int)param_1 + 0x90d)) &

                                              0xffffff01,*(uint32_t /* width from decompiler */ *)(param_1[5] + 0x2c));

            if (piStack_4f4 != (int *)0x0) {

              FUN_005971e0(&piStack_4e4);

              FUN_00597230(&piStack_4f4);

            }

            iVar17 = CVOGReaction_RandomUnitScalar();

            if (0xfffff < *(int *)(iVar17 + 0xc)) {

              *(uint32_t /* width from decompiler */ *)(iVar17 + 0xc) = 0;

            }

            uVar2 = *(ushort *)(*(int *)(iVar17 + 8) + *(int *)(iVar17 + 0xc) * 2);

            *(int *)(iVar17 + 0xc) = *(int *)(iVar17 + 0xc) + 1;

            uVar16 = (uint)uVar2;

            piStack_4e4 = (int *)((float)uVar16 * *(float *)(param_1[10] + 0x324) * DAT_00aaa638 +

                                 *(float *)(param_1[10] + 800));

            iVar7 = iVar7 + 1;

          } while (iVar7 < (short)param_1[0xaf]);

        }

      }

      goto LAB_00591fbf;

    }

LAB_00591feb:

    local_4f0 = 0.0;

    local_4ec = 0.0;

    local_4e8 = 0.0;

    if ((*(byte *)((int)param_1 + 0x90f) & 0x20) == 0) {

      if (param_1[0x245] != 0) {

        local_4f0 = (float)param_1[0x206];

        local_4ec = (float)param_1[0x207];

        local_4e8 = (float)param_1[0x208];

      }

    }

    else {

      FUN_004e9530(&local_490,param_1 + 0x218);

      if ((int *)param_1[0x245] == (int *)0x0) {

        fStack_4d8 = 0.0;

        fStack_4dc = 0.0;

        local_4e0 = 0.0;

        fStack_4d4 = g_flOne;

      }

      else {

        iVar7 = (**(code **)(*(int *)param_1[0x245] + 0xc))();

        pfVar14 = (float *)FUN_004e96e0(local_440,iVar7 + 0x80);

        local_4e0 = *pfVar14;

        fStack_4dc = pfVar14[1];

        fStack_4d8 = pfVar14[2];

        fStack_4d4 = pfVar14[3];

      }

      FUN_004249f0(&local_4e0,&local_490);

      pfVar14 = (float *)FUN_004e88e0(&local_4e0,&local_490);

      local_4e8 = (float)param_1[0x20b] + pfVar14[2];

      local_4ec = (float)param_1[0x20a] + pfVar14[1];

      local_4f0 = *pfVar14 + (float)param_1[0x209];

      fStack_4bc = local_4f0;

      fStack_4b8 = local_4ec;

      fStack_4b4 = local_4e8;

    }

    FUN_004e9530(&local_4b0,&local_4f0);

    FUN_004e96e0(local_450,param_1 + 0x231);

    if ((param_1[0x9a] != 0) &&

       (piStack_4f4 = (int *)(param_1[0x9b] - param_1[0x9a] >> 2), piStack_4f4 != (int *)0x0)) {

      if (param_1[0x37] == 0) {

        iVar7 = **(int **)param_1[0x9a];

        uVar23 = FUN_004f2e20(&local_4b0);

        (**(code **)(iVar7 + 0x18))(uVar23);

        iVar7 = **(int **)param_1[0x9a];

        uVar23 = FUN_004f2e70(&local_454);

        (**(code **)(iVar7 + 0x20))(uVar23);

        piVar9 = (int *)0x1;

        while ((local_4f8 = piVar9, param_1[0x9a] != 0 &&

               (piVar9 < (int *)(param_1[0x9b] - param_1[0x9a] >> 2)))) {

          if ((char)param_1[0x21e] != '\0') {

            local_4f0 = (float)param_1[0x209];

            local_4ec = (float)param_1[0x20a];

            local_4e8 = (float)param_1[0x20b];

            iVar7 = CVOGReaction_RandomUnitScalar();

            if (0xfffff < *(int *)(iVar7 + 0xc)) {

              *(uint32_t /* width from decompiler */ *)(iVar7 + 0xc) = 0;

            }

            uVar2 = *(ushort *)(*(int *)(iVar7 + 8) + *(int *)(iVar7 + 0xc) * 2);

            *(int *)(iVar7 + 0xc) = *(int *)(iVar7 + 0xc) + 1;

            local_4f0 = (float)uVar2 * (float)param_1[0x21b] * DAT_00aaa638 + (float)param_1[0x218]

                        + local_4f0;

            iVar7 = CVOGReaction_RandomUnitScalar();

            if (0xfffff < *(int *)(iVar7 + 0xc)) {

              *(uint32_t /* width from decompiler */ *)(iVar7 + 0xc) = 0;

            }

            uVar2 = *(ushort *)(*(int *)(iVar7 + 8) + *(int *)(iVar7 + 0xc) * 2);

            *(int *)(iVar7 + 0xc) = *(int *)(iVar7 + 0xc) + 1;

            local_4ec = (float)uVar2 * (float)param_1[0x21c] * DAT_00aaa638 + (float)param_1[0x219]

                        + local_4ec;

            iVar7 = CVOGReaction_RandomUnitScalar();

            if (0xfffff < *(int *)(iVar7 + 0xc)) {

              *(uint32_t /* width from decompiler */ *)(iVar7 + 0xc) = 0;

            }

            uVar2 = *(ushort *)(*(int *)(iVar7 + 8) + *(int *)(iVar7 + 0xc) * 2);

            *(int *)(iVar7 + 0xc) = *(int *)(iVar7 + 0xc) + 1;

            local_4e8 = (float)uVar2 * (float)param_1[0x21d] * DAT_00aaa638 + (float)param_1[0x21a]

                        + local_4e8;

            pfVar14 = (float *)FUN_004e9530(local_440,&local_4f0);

            local_4b0 = *pfVar14;

            local_4ac = pfVar14[1];

            local_4a8 = pfVar14[2];

            local_4a4 = pfVar14[3];

          }

          if ((_DAT_00b03e74 & 1) == 0) {

            _DAT_00b03e74 = _DAT_00b03e74 | 1;

          }

          _DAT_00b03e68 = local_4b0;

          _DAT_00b03e6c = local_4ac;

          _DAT_00b03e70 = local_4a8;

          (**(code **)(**(int **)(param_1[0x9a] + (int)piVar9 * 4) + 0x18))(&DAT_00b03e68);

          iVar7 = **(int **)(param_1[0x9a] + (int)piVar9 * 4);

          uVar23 = FUN_004f2e70(&local_454);

          (**(code **)(iVar7 + 0x20))(uVar23);

          piVar9 = (int *)((int)local_4f8 + 1);

        }

      }

      else {

        pfVar14 = (float *)FUN_004f2e20(&local_4b0);

        fStack_4cc = *pfVar14;

        fStack_4c8 = pfVar14[1];

        uStack_4c4 = pfVar14[2];

        pfVar14 = (float *)FUN_004f2e70(local_450);

        local_4e0 = *pfVar14;

        fStack_4dc = pfVar14[1];

        fStack_4d8 = pfVar14[2];

        fStack_4d4 = pfVar14[3];

        for (uVar16 = 0;

            (param_1[0x9a] != 0 && (uVar16 < (uint)(param_1[0x9b] - param_1[0x9a] >> 2)));

            uVar16 = uVar16 + 1) {

          FUN_0055a360(uVar16,&fStack_4bc,&fStack_468);

          fVar18 = (float)param_1[0x236];

          fStack_4b8 = fStack_4b8 * fVar18;

          fStack_4bc = fStack_4bc * fVar18;

          fStack_4b4 = fStack_4b4 * fVar18;

          fStack_4a0 = 0.0 - local_4e0;

          fStack_49c = 0.0 - fStack_4dc;

          fStack_498 = 0.0 - fStack_4d8;

          fVar18 = ((0.0 - local_4e0 * fStack_4bc) - fStack_4b8 * fStack_4dc) -

                   fStack_4b4 * fStack_4d8;

          fVar19 = (fStack_4d4 * fStack_4bc + fStack_4b4 * fStack_4dc) - fStack_4b8 * fStack_4d8;

          fVar20 = (fStack_4d8 * fStack_4bc + fStack_4b8 * fStack_4d4) - local_4e0 * fStack_4b4;

          fStack_438 = (fStack_4b4 * fStack_4d4 + local_4e0 * fStack_4b8) - fStack_4dc * fStack_4bc;

          fStack_4bc = (fStack_4d4 * fVar19 + fVar20 * fStack_498 + fVar18 * fStack_4a0) -

                       fStack_438 * fStack_49c;

          fStack_474 = fStack_4bc + fStack_4cc;

          fStack_4b8 = (fStack_4d4 * fVar20 + fStack_438 * fStack_4a0 + fVar18 * fStack_49c) -

                       fVar19 * fStack_498;

          fStack_470 = fStack_4b8 + fStack_4c8;

          fStack_4b4 = (fStack_4d4 * fStack_438 + fVar18 * fStack_498 + fVar19 * fStack_49c) -

                       fVar20 * fStack_4a0;

          fStack_46c = fStack_4b4 + uStack_4c4;

          (**(code **)(**(int **)(param_1[0x9a] + uVar16 * 4) + 0x18))(&fStack_474);

          fStack_494 = (fStack_4d8 * fStack_46c + fStack_464 * local_4e0 +

                       (float)piStack_4e4 * fStack_460) - fStack_468 * fStack_4dc;

          local_490 = (fStack_4dc * fStack_46c + fStack_468 * fStack_4d8 + fStack_460 * local_4e0) -

                      (float)piStack_4e4 * fStack_464;

          fStack_48c = (fStack_464 * fStack_4d8 + fStack_460 * fStack_4dc +

                       (float)piStack_4e4 * fStack_468) - local_4e0 * fStack_46c;

          fStack_488 = ((fStack_460 * fStack_4d8 - (float)piStack_4e4 * fStack_46c) -

                       fStack_468 * local_4e0) - fStack_464 * fStack_4dc;

          (**(code **)(**(int **)(param_1[0x9a] + uVar16 * 4) + 0x20))(&fStack_494);

        }

      }

    }

    if (param_1[0x98] == 0) {

LAB_005927a4:

      pfVar14 = (float *)(param_1 + 0xa3);

      fStack_4bc = *pfVar14;

      fStack_4b8 = (float)param_1[0xa4];

      fStack_4b4 = (float)param_1[0xa5];

      pfVar1 = (float *)(param_1 + 0xa9);

      fStack_468 = *pfVar1;

      fStack_464 = (float)param_1[0xaa];

      fStack_460 = (float)param_1[0xab];

      if ((*(byte *)(param_1 + 0x243) & 8) != 0) {

        iVar7 = CVOGReaction_RandomUnitScalar();

        if (0xfffff < *(int *)(iVar7 + 0xc)) {

          *(uint32_t /* width from decompiler */ *)(iVar7 + 0xc) = 0;

        }

        uVar2 = *(ushort *)(*(int *)(iVar7 + 8) + *(int *)(iVar7 + 0xc) * 2);

        *(int *)(iVar7 + 0xc) = *(int *)(iVar7 + 0xc) + 1;

        *pfVar14 = (float)uVar2 * (float)param_1[0xa6] * DAT_00aaa638 + *pfVar14;

        iVar7 = CVOGReaction_RandomUnitScalar();

        if (0xfffff < *(int *)(iVar7 + 0xc)) {

          *(uint32_t /* width from decompiler */ *)(iVar7 + 0xc) = 0;

        }

        uVar2 = *(ushort *)(*(int *)(iVar7 + 8) + *(int *)(iVar7 + 0xc) * 2);

        *(int *)(iVar7 + 0xc) = *(int *)(iVar7 + 0xc) + 1;

        param_1[0xa4] =

             (int)((float)uVar2 * (float)param_1[0xa7] * DAT_00aaa638 + (float)param_1[0xa4]);

        iVar7 = CVOGReaction_RandomUnitScalar();

        if (0xfffff < *(int *)(iVar7 + 0xc)) {

          *(uint32_t /* width from decompiler */ *)(iVar7 + 0xc) = 0;

        }

        uVar2 = *(ushort *)(*(int *)(iVar7 + 8) + *(int *)(iVar7 + 0xc) * 2);

        *(int *)(iVar7 + 0xc) = *(int *)(iVar7 + 0xc) + 1;

        param_1[0xa5] =

             (int)((float)uVar2 * (float)param_1[0xa8] * DAT_00aaa638 + (float)param_1[0xa5]);

      }

      if ((*(byte *)(param_1 + 0x243) & 4) != 0) {

        iVar7 = CVOGReaction_RandomUnitScalar();

        if (0xfffff < *(int *)(iVar7 + 0xc)) {

          *(uint32_t /* width from decompiler */ *)(iVar7 + 0xc) = 0;

        }

        uVar2 = *(ushort *)(*(int *)(iVar7 + 8) + *(int *)(iVar7 + 0xc) * 2);

        *(int *)(iVar7 + 0xc) = *(int *)(iVar7 + 0xc) + 1;

        *pfVar1 = (float)uVar2 * (float)param_1[0xac] * DAT_00aaa638 + *pfVar1;

        iVar7 = CVOGReaction_RandomUnitScalar();

        if (0xfffff < *(int *)(iVar7 + 0xc)) {

          *(uint32_t /* width from decompiler */ *)(iVar7 + 0xc) = 0;

        }

        uVar2 = *(ushort *)(*(int *)(iVar7 + 8) + *(int *)(iVar7 + 0xc) * 2);

        *(int *)(iVar7 + 0xc) = *(int *)(iVar7 + 0xc) + 1;

        param_1[0xaa] =

             (int)((float)uVar2 * (float)param_1[0xad] * DAT_00aaa638 + (float)param_1[0xaa]);

        iVar7 = CVOGReaction_RandomUnitScalar();

        if (0xfffff < *(int *)(iVar7 + 0xc)) {

          *(uint32_t /* width from decompiler */ *)(iVar7 + 0xc) = 0;

        }

        uVar2 = *(ushort *)(*(int *)(iVar7 + 8) + *(int *)(iVar7 + 0xc) * 2);

        *(int *)(iVar7 + 0xc) = *(int *)(iVar7 + 0xc) + 1;

        param_1[0xab] =

             (int)((float)uVar2 * (float)param_1[0xae] * DAT_00aaa638 + (float)param_1[0xab]);

      }

      bVar6 = *(byte *)(param_1 + 0x243);

      if ((bVar6 & 0x10) != 0) {

        if ((bVar6 & 0x20) != 0) {

          fVar18 = (float)param_1[0xa5];

          fVar19 = (float)param_1[0xa4];

          piStack_4f4 = (int *)((float)param_1[0x213] * fVar19);

          local_4e0 = fVar19 * (float)param_1[0x212];

          fVar20 = *pfVar14;

          fStack_4cc = (float)param_1[0x20f] * fVar20 + local_4e0 + (float)param_1[0x20c] * fVar18;

          *pfVar14 = fStack_4cc;

          fStack_4c8 = (float)param_1[0x210] * fVar20 + (float)piStack_4f4 +

                       (float)param_1[0x20d] * fVar18;

          uStack_4c4 = (float)param_1[0x211] * fVar20 + (float)param_1[0x214] * fVar19 +

                       (float)param_1[0x20e] * fVar18;

          param_1[0xa4] = (int)fStack_4c8;

          param_1[0xa5] = (int)uStack_4c4;

        }

        if ((bVar6 & 0x40) != 0) {

          fVar18 = (float)param_1[0xab];

          fVar19 = (float)param_1[0xaa];

          piStack_4f4 = (int *)((float)param_1[0x213] * fVar19);

          local_4e0 = fVar19 * (float)param_1[0x212];

          fVar20 = *pfVar1;

          fStack_4cc = (float)param_1[0x20f] * fVar20 + local_4e0 + (float)param_1[0x20c] * fVar18;

          fStack_4c8 = (float)param_1[0x210] * fVar20 + (float)piStack_4f4 +

                       (float)param_1[0x20d] * fVar18;

          *pfVar1 = fStack_4cc;

          uStack_4c4 = (float)param_1[0x211] * fVar20 + (float)param_1[0x214] * fVar19 +

                       (float)param_1[0x20e] * fVar18;

          param_1[0xaa] = (int)fStack_4c8;

          param_1[0xab] = (int)uStack_4c4;

        }

      }

      FUN_004e9530(&local_490,pfVar14);

      FUN_004e9530(local_440,pfVar1);

      if (param_1[0x98] == 0) {

        puVar4 = (uint32_t /* width from decompiler */ *)param_1[0x9a];

        if ((puVar4 != (uint32_t /* width from decompiler */ *)0x0) &&

           (piStack_4f4 = (int *)(param_1[0x9b] - (int)puVar4 >> 2), piStack_4f4 != (int *)0x0)) {

          piStack_4f4 = (int *)*puVar4;

          iVar7 = *piStack_4f4;

          uVar23 = FUN_004f2e20(&local_490);

          (**(code **)(iVar7 + 0xd4))(uVar23);

          local_4f8 = *(int **)param_1[0x9a];

          iVar7 = *local_4f8;

          uVar23 = FUN_004f2e20(auStack_444);

          (**(code **)(iVar7 + 0xd8))(uVar23);

        }

        for (local_4f8 = (int *)0x1;

            (param_1[0x9a] != 0 && (local_4f8 < (int *)(param_1[0x9b] - param_1[0x9a] >> 2)));

            local_4f8 = (int *)((int)local_4f8 + 1)) {

          bVar6 = *(byte *)(param_1 + 0x243) >> 3 & 1;

          if ((bVar6 != 0) || ((*(byte *)(param_1 + 0x243) & 4) != 0)) {

            if (bVar6 != 0) {

              *pfVar14 = fStack_4bc;

              param_1[0xa4] = (int)fStack_4b8;

              param_1[0xa5] = (int)fStack_4b4;

              iVar7 = CVOGReaction_RandomUnitScalar();

              if (0xfffff < *(int *)(iVar7 + 0xc)) {

                *(uint32_t /* width from decompiler */ *)(iVar7 + 0xc) = 0;

              }

              uVar2 = *(ushort *)(*(int *)(iVar7 + 8) + *(int *)(iVar7 + 0xc) * 2);

              *(int *)(iVar7 + 0xc) = *(int *)(iVar7 + 0xc) + 1;

              *pfVar14 = (float)uVar2 * (float)param_1[0xa6] * DAT_00aaa638 + *pfVar14;

              iVar7 = CVOGReaction_RandomUnitScalar();

              if (0xfffff < *(int *)(iVar7 + 0xc)) {

                *(uint32_t /* width from decompiler */ *)(iVar7 + 0xc) = 0;

              }

              uVar2 = *(ushort *)(*(int *)(iVar7 + 8) + *(int *)(iVar7 + 0xc) * 2);

              *(int *)(iVar7 + 0xc) = *(int *)(iVar7 + 0xc) + 1;

              param_1[0xa4] =

                   (int)((float)uVar2 * (float)param_1[0xa7] * DAT_00aaa638 + (float)param_1[0xa4]);

              iVar7 = CVOGReaction_RandomUnitScalar();

              if (0xfffff < *(int *)(iVar7 + 0xc)) {

                *(uint32_t /* width from decompiler */ *)(iVar7 + 0xc) = 0;

              }

              uVar2 = *(ushort *)(*(int *)(iVar7 + 8) + *(int *)(iVar7 + 0xc) * 2);

              *(int *)(iVar7 + 0xc) = *(int *)(iVar7 + 0xc) + 1;

              param_1[0xa5] =

                   (int)((float)uVar2 * (float)param_1[0xa8] * DAT_00aaa638 + (float)param_1[0xa5]);

            }

            if ((*(byte *)(param_1 + 0x243) & 4) != 0) {

              pfVar1 = (float *)(param_1 + 0xa9);

              *pfVar1 = fStack_468;

              param_1[0xaa] = (int)fStack_464;

              param_1[0xab] = (int)fStack_460;

              iVar7 = CVOGReaction_RandomUnitScalar();

              if (0xfffff < *(int *)(iVar7 + 0xc)) {

                *(uint32_t /* width from decompiler */ *)(iVar7 + 0xc) = 0;

              }

              uVar2 = *(ushort *)(*(int *)(iVar7 + 8) + *(int *)(iVar7 + 0xc) * 2);

              *(int *)(iVar7 + 0xc) = *(int *)(iVar7 + 0xc) + 1;

              *pfVar1 = (float)uVar2 * (float)param_1[0xac] * DAT_00aaa638 + *pfVar1;

              iVar7 = CVOGReaction_RandomUnitScalar();

              if (0xfffff < *(int *)(iVar7 + 0xc)) {

                *(uint32_t /* width from decompiler */ *)(iVar7 + 0xc) = 0;

              }

              uVar2 = *(ushort *)(*(int *)(iVar7 + 8) + *(int *)(iVar7 + 0xc) * 2);

              *(int *)(iVar7 + 0xc) = *(int *)(iVar7 + 0xc) + 1;

              param_1[0xaa] =

                   (int)((float)uVar2 * (float)param_1[0xad] * DAT_00aaa638 + (float)param_1[0xaa]);

              iVar7 = CVOGReaction_RandomUnitScalar();

              if (0xfffff < *(int *)(iVar7 + 0xc)) {

                *(uint32_t /* width from decompiler */ *)(iVar7 + 0xc) = 0;

              }

              uVar2 = *(ushort *)(*(int *)(iVar7 + 8) + *(int *)(iVar7 + 0xc) * 2);

              *(int *)(iVar7 + 0xc) = *(int *)(iVar7 + 0xc) + 1;

              param_1[0xab] =

                   (int)((float)uVar2 * (float)param_1[0xae] * DAT_00aaa638 + (float)param_1[0xab]);

            }

            bVar6 = *(byte *)(param_1 + 0x243);

            if ((bVar6 & 0x10) != 0) {

              if ((bVar6 & 0x20) != 0) {

                fVar18 = (float)param_1[0xa5];

                fVar19 = *pfVar14;

                fVar20 = (float)param_1[0xa4];

                fStack_49c = (float)param_1[0x213] * fVar20;

                fStack_498 = (float)param_1[0x214] * fVar20;

                fStack_4cc = (float)param_1[0x20f] * fVar19 + (float)param_1[0x212] * fVar20 +

                             (float)param_1[0x20c] * fVar18;

                *pfVar14 = fStack_4cc;

                fStack_4c8 = (float)param_1[0x210] * fVar19 + fStack_49c +

                             (float)param_1[0x20d] * fVar18;

                uStack_4c4 = (float)param_1[0x211] * fVar19 + fStack_498 +

                             (float)param_1[0x20e] * fVar18;

                param_1[0xa4] = (int)fStack_4c8;

                param_1[0xa5] = (int)uStack_4c4;

              }

              if ((bVar6 & 0x40) != 0) {

                fVar18 = (float)param_1[0xab];

                fVar19 = (float)param_1[0xa9];

                fVar20 = (float)param_1[0xaa];

                fStack_4dc = (float)param_1[0x213] * fVar20;

                fStack_4d8 = (float)param_1[0x214] * fVar20;

                fStack_474 = fVar19 * (float)param_1[0x20f] + fVar20 * (float)param_1[0x212] +

                             fVar18 * (float)param_1[0x20c];

                fStack_470 = (float)param_1[0x210] * fVar19 + fStack_4dc +

                             (float)param_1[0x20d] * fVar18;

                param_1[0xa9] = (int)fStack_474;

                fStack_46c = (float)param_1[0x211] * fVar19 + fStack_4d8 +

                             (float)param_1[0x20e] * fVar18;

                param_1[0xaa] = (int)fStack_470;

                param_1[0xab] = (int)fStack_46c;

              }

            }

          }

          iVar7 = (int)local_4f8 * 4;

          if ((_DAT_00b03624 & 1) == 0) {

            _DAT_00b03624 = _DAT_00b03624 | 1;

          }

          _DAT_00b03620 = param_1[0xa5];

          _DAT_00b0361c = param_1[0xa4];

          _DAT_00b03618 = *pfVar14;

          (**(code **)(**(int **)(param_1[0x9a] + iVar7) + 0xd4))(&DAT_00b03618);

          if ((_DAT_00b03624 & 1) == 0) {

            _DAT_00b03624 = _DAT_00b03624 | 1;

          }

          _DAT_00b03620 = param_1[0xab];

          _DAT_00b0361c = param_1[0xaa];

          _DAT_00b03618 = (float)param_1[0xa9];

          (**(code **)(**(int **)(param_1[0x9a] + iVar7) + 0xd8))(&DAT_00b03618);

        }

      }

      iVar7 = param_1[0x98];

      if (iVar7 != 0) {

        pcVar15 = (char *)FUN_005070b0(&uStack_4bd);

        if ((*pcVar15 == '\0') && (*(int *)(iVar7 + 0x44) != 0)) {

          FUN_005070d0();

        }

        (**(code **)(**(int **)(iVar7 + 0x3c) + 0x50))(&local_490);

        iVar7 = param_1[0x98];

        pcVar15 = (char *)FUN_005070b0((int)&uStack_4c4 + 3);

        if ((*pcVar15 == '\0') && (*(int *)(iVar7 + 0x44) != 0)) {

          FUN_005070d0();

        }

        (**(code **)(**(int **)(iVar7 + 0x3c) + 0x54))(auStack_444);

      }

    }

    else {

      FUN_0040d2a0(&local_4b0);

      FUN_00404dc0(local_450);

      if (*(char *)(param_1[0x98] + 0x40) == '\0') goto LAB_005927a4;

    }

    if (param_1[0x98] != 0) {

      piVar9 = (int *)FUN_0040afb0(&piStack_4f4,3);

      if ((*piVar9 == 0) && (param_1[0xb] != 0)) {

        FUN_005f5700(3,param_1[0xb]);

        FUN_005f5700(4,(char)param_1[0xc]);

      }

      piStack_4f4 = DAT_00d1f040;

      FUN_0076cf00("addEntity");

      local_14 = CONCAT31(local_14._1_3_,6);

      FUN_00560ec0(param_1[0x98]);

      if ((*(char *)(param_1[0x98] + 0x40) == '\0') &&

         ((*(byte *)((int)param_1 + 0x90d) & 0x10) != 0)) {

        FUN_00590450();

      }

      local_14 = CONCAT31(local_14._1_3_,4);

      FUN_0076cef0();

    }

  }

  else {

LAB_00591fbf:

    if ((param_1[0x98] != 0) ||

       ((param_1[0x9a] != 0 &&

        (piStack_4f4 = (int *)(param_1[0x9b] - param_1[0x9a] >> 2), piStack_4f4 != (int *)0x0))))

    goto LAB_00591feb;

  }

  local_14 = local_14 & 0xffffff00;

  FUN_0076cef0();

LAB_0059320b:

  local_14 = 0xffffffff;

  FUN_0076cef0();

  ExceptionList = local_1c;

  return 1;

}
