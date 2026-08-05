// READABILITY (auto CF):
//  - Body size: ~191 non-empty decompiler lines.
//  - Control keywords: if×8, return×2, for×1.
//  - Notable callees: FUN_005828b0×3, FUN_0040d4b0×2, FUN_0044af00×2, FUN_007a4480×2, CVOGReaction_GiveItemByCbid, CVOGReaction_RandomUnitScalar, ClientSpecialEvent_TeleportIn_ctor, FUN_00439a80.
//  - Strings: "obj_f_inc_mov_01_airlift_at.anm"; "obj_f_inc_mov_01_airlift_aut.anm"; "obj_f_inc_mov_01_airlift_at2.anm"; "cptest.geo".
//  - Return sites: 2.

// =============================================================================
// Named_ClientSpecialEvent_TeleportIn_00978d20
// -----------------------------------------------------------------------------
// Stable ID: aa_00978d20
// Address:   0x00978d20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "ClientSpecialEvent_TeleportIn"
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

/* ClientSpecialEvent_TeleportIn_ctor — INC airlift arrive animation.

   SpecialEvent type 2. Pair with TeleportOut for cross-map style transfers. */



uint32_t /* width from decompiler */ * __thiscall ClientSpecialEvent_TeleportIn_ctor(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  int *piVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint extraout_EDX;

  float10 fVar6;

  float10 fVar7;

  char *pcStack_70;

  uint64_t uStack_6c;

  float *pfStack_64;

  uint32_t /* width from decompiler */ uStack_60;

  uint32_t /* width from decompiler */ uStack_40;

  int *piStack_3c;

  int *piStack_38;

  float fStack_34;

  char *pcStack_30;

  char *pcStack_2c;

  float fStack_28;

  float fStack_24;

  float fStack_20;

  float fStack_1c;

  void *local_c;

  uint8_t *puStack_8;

  uint local_4;

  

  puStack_8 = &LAB_009b294a;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_2 = &PTR_LAB_00a766f8;

  *(uint8_t *)(param_2 + 1) = 0;

  local_4 = 0;

  *param_2 = &PTR_FUN_00a76800;

  *(uint8_t *)(param_2 + 2) = 0;

  param_2[9] = 0;

  param_2[10] = 0;

  param_2[0xe] = param_1;

  param_2[0xf] = 0;

  param_2[0x11] = 0;

  *(uint8_t *)(param_2 + 0x12) = 0;

  *(uint8_t *)((int)param_2 + 0x49) = 0;

  uStack_60 = 0x978d83;

  piVar2 = (int *)CVOGReaction_GiveItemByCbid(0xadc);

  if (piVar2 == (int *)0x0) {

    uStack_60 = 1;

    pfStack_64 = (float *)0x978d9d;

    FUN_007a4480();

  }

  else {

    uStack_60 = 0xadc;

    pfStack_64 = (float *)0x978dc1;

    (**(code **)(*piVar2 + 8))();

    pfStack_64 = (float *)0x0;

    uStack_6c._4_4_ = (float *)0x978dcc;

    uStack_6c = FUN_0092c760();

    pcStack_70 = (char *)0x978dd5;

    FUN_00512160();

    uStack_6c._4_4_ = (float *)0x978de6;

    pfStack_64 = (float *)piVar2;

    FUN_004bc180();

    pfStack_64 = (float *)0x978df0;

    uVar3 = (**(code **)(*piVar2 + 0x1cc))();

    param_2[9] = uVar3;

    pfStack_64 = (float *)0x978df8;

    iVar4 = CVOGReaction_RandomUnitScalar();

    if (0xfffff < *(int *)(iVar4 + 0xc)) {

      *(uint32_t /* width from decompiler */ *)(iVar4 + 0xc) = 0;

    }

    pcStack_30 = (char *)g_flOne;

    *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + 1;

    pfStack_64 = &fStack_34;

    uStack_6c._4_4_ = &fStack_24;

    fStack_34 = 0.0;

    pcStack_2c = (char *)0x0;

    uStack_6c._0_4_ = (char *)0x978e40;

    FUN_0076f5f0();

    fVar6 = (float10)(extraout_EDX & 0xffff) * (float10)_DAT_00aaaa84;

    fVar7 = (float10)fsin(fVar6);

    fStack_34 = (float)((float10)fStack_24 * fVar7);

    pcStack_30 = (char *)(float)((float10)fStack_20 * fVar7);

    pcStack_2c = (char *)(float)((float10)fStack_1c * fVar7);

    fVar6 = (float10)fcos(fVar6);

    fStack_28 = (float)fVar6;

    pfStack_64 = (float *)0x978e92;

    puVar5 = (uint32_t /* width from decompiler */ *)

             (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x1a0))();

    pfStack_64 = (float *)(param_2 + 4);

    *pfStack_64 = (float)*puVar5;

    param_2[5] = puVar5[1];

    param_2[6] = puVar5[2];

    param_2[7] = puVar5[3];

    uStack_6c._4_4_ = (float *)&uStack_40;

    uStack_6c._0_4_ = (char *)0x978eb6;

    FUN_004e88e0();

    pfStack_64 = (float *)0x0;

    pcStack_70 = pcStack_30;

    uStack_6c._0_4_ = pcStack_2c;

    uStack_6c._4_4_ = (float *)fStack_28;

    (*(code *)**(uint32_t /* width from decompiler */ **)param_2[9])(1);

    (**(code **)(*(int *)param_2[9] + 0x20))();

    (**(code **)(*(int *)(*(int *)(*(int *)(param_2[9] + 4) + 4) + 4 + param_2[9]) + 0x100))();

    FUN_005828b0(1,"obj_f_inc_mov_01_airlift_at.anm",0);

    FUN_005828b0(2,"obj_f_inc_mov_01_airlift_aut.anm",0);

    FUN_005828b0(3,"obj_f_inc_mov_01_airlift_at2.anm",0);

    FUN_005816a0(1,0);

    *(uint8_t *)(param_2 + 0x12) = 1;

    uStack_6c._4_4_ = operator_new(0x14c);

    fStack_34._0_1_ = 1;

    if (uStack_6c._4_4_ == (void *)0x0) {

      uVar3 = 0;

    }

    else {

      uVar3 = FUN_00764030();

    }

    fStack_34 = (float)((uint)fStack_34._1_3_ << 8);

    param_2[10] = uVar3;

    FUN_00989e00(&pcStack_70,"cptest.geo");

    (**(code **)(*(int *)param_2[10] + 0x5c))(&pcStack_70);

    piVar2 = *(int **)(param_2[9] + 8);

    uStack_40 = param_2[10];

    piStack_3c = piVar2;

    iVar4 = FUN_0040d4b0();

    if ((iVar4 == 0) || (iVar4 = FUN_0040d4b0(), iVar4 == 0)) {

      uStack_60 = 0x9790b5;

      uStack_60 = FUN_0076cec0();

      pfStack_64 = (float *)0x3;

      uStack_6c._4_4_ = (void *)0x36;

      uStack_6c._0_4_ =

           "C:\\vog\\1_code\\vog_14_117_branch\\appClient\\ClientSpecialEvent_TeleportIn.cpp";

      pcStack_70 = (char *)0x9790c4;

      vog_LogMessage();

      pcStack_70 = "VOG_DEBUG_STOP";

      FUN_007a4480();

      if ((uint32_t /* width from decompiler */ *)param_2[10] != (uint32_t /* width from decompiler */ *)0x0) {

        (*(code *)**(uint32_t /* width from decompiler */ **)param_2[10])();

      }

      param_2[10] = 0;

    }

    else {

      puVar5 = operator_new(0x10);

      if (puVar5 != (uint32_t /* width from decompiler */ *)0x0) {

        *puVar5 = 0;

        puVar5[1] = 0;

        puVar5[2] = 0;

        puVar5[3] = 0;

      }

      local_4 = local_4 & 0xffffff00;

      piStack_38 = piVar2 + 0x1a;

      FUN_004406e0();

      piVar1 = piStack_3c;

      piVar2 = *(int **)(piVar2[0x1c] + -4);

      piStack_3c = (int *)FUN_0044af00();

      iVar4 = FUN_0044af00();

      if ((piStack_3c != (int *)0x0) || (iVar4 != 0)) {

        piVar2[2] = 0;

        FUN_0044adc0();

                    /* WARNING: Subroutine does not return */

        operator_delete(piVar2);

      }

      (**(code **)(*piVar1 + 0x30))();

      (**(code **)(*piVar1 + 0x34))();

      FUN_00439a80();

      (**(code **)(*piVar2 + 0xc))();

      uStack_60 = (**(code **)(*piVar2 + 0x48))();

      pfStack_64 = (float *)0x9791ab;

      uStack_60 = (**(code **)(*piVar1 + 0xc))();

      pfStack_64 = (float *)0x9791b4;

      FUN_0074c9c0();

    }

    if (param_2[0xe] == DAT_00d1b6d8) {

      param_2[8] = *(uint32_t /* width from decompiler */ *)(DAT_00d1b778 + 0x60c);

      *(uint32_t /* width from decompiler */ *)(DAT_00d1b778 + 0x60c) = 4;

      FUN_0090dd50();

      iVar4 = DAT_00d1b778;

      *(float *)(DAT_00d1b778 + 0xce4) = fStack_34;

      *(char **)(iVar4 + 0xce8) = pcStack_30;

      *(char **)(iVar4 + 0xcec) = pcStack_2c;

      *(float *)(iVar4 + 0xcf0) = fStack_28;

      *(float *)(iVar4 + 0xcf4) = fStack_24;

      *(float *)(iVar4 + 0xcf8) = fStack_20;

      *(float *)(iVar4 + 0xcfc) = fStack_1c;

    }

    FUN_00978990();

  }

  ExceptionList = local_c;

  return param_2;

}
