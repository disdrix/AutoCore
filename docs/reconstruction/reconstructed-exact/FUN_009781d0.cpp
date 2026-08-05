// =============================================================================
// FUN_009781d0
// -----------------------------------------------------------------------------
// Stable ID: aa_009781d0
// Address:   0x009781d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009781d0 @ 0x009781d0
// Stable ID: aa_009781d0
// Embedded strings (evidence for future rename):
//   - "obj_f_inc_mov_01_airlift_at.anm"
//   - "obj_f_inc_mov_01_airlift_aut.anm"
//   - "obj_f_inc_mov_01_airlift_at2.anm"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~151 non-empty decompiler lines.
//  - Control keywords: if×4, for×1, return×1.
//  - Notable callees: FUN_005828b0×3, CVOGReaction_GiveItemByCbid, CVOGReaction_RandomUnitScalar, ClientSpecialEvent_TeleportOut_ctor, FUN_004bc180, FUN_004e88e0, FUN_00512160, FUN_005816a0.
//  - Strings: "obj_f_inc_mov_01_airlift_at.anm"; "obj_f_inc_mov_01_airlift_aut.anm"; "obj_f_inc_mov_01_airlift_at2.anm".
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

/* ClientSpecialEvent_TeleportOut_ctor — INC airlift leave animation.

   SpecialEvent type 1. Loads obj_f_inc_mov_01_airlift_*.anm sequences.

   Used for lift-out before map transfer style teleports. */



uint32_t /* width from decompiler */ * ClientSpecialEvent_TeleportOut_ctor(uint32_t /* width from decompiler */ *param_1,int param_2)



{

  float fVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint extraout_EDX;

  float10 fVar6;

  uint32_t /* width from decompiler */ uStack_9c;

  uint32_t /* width from decompiler */ uStack_98;

  uint32_t /* width from decompiler */ uStack_94;

  float fStack_90;

  float fStack_8c;

  uint64_t uStack_88;

  float *pfStack_80;

  uint32_t /* width from decompiler */ uStack_7c;

  uint32_t /* width from decompiler */ local_60;

  uint32_t /* width from decompiler */ local_5c;

  uint32_t /* width from decompiler */ local_58;

  uint32_t /* width from decompiler */ local_54;

  float local_4c;

  float local_48;

  float local_44;

  float local_40;

  float local_3c;

  float local_38;

  float local_34;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint8_t *local_24;

  uint8_t *puStack_20;

  void *local_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ local_14;

  

  puStack_20 = &stack0xfffffffc;

  puStack_18 = &LAB_009b0291;

  local_1c = ExceptionList;

  ExceptionList = &local_1c;

  *param_1 = &PTR_LAB_00a766f8;

  *(uint8_t *)(param_1 + 1) = 0;

  local_14 = 0;

  *param_1 = &PTR_FUN_00a76860;

  *(uint8_t *)(param_1 + 2) = 0;

  param_1[4] = 0;

  param_1[5] = 0;

  param_1[9] = param_2;

  param_1[10] = 0;

  param_1[0xb] = 0;

  *(uint8_t *)(param_1 + 0xc) = 0;

  *(uint8_t *)((int)param_1 + 0x31) = 0;

  uStack_7c = 0x978245;

  piVar2 = (int *)CVOGReaction_GiveItemByCbid(0xadc);

  if (piVar2 == (int *)0x0) {

    uStack_7c = 1;

    pfStack_80 = (float *)0x97825f;

    FUN_007a4480();

  }

  else {

    uStack_7c = 0xadc;

    pfStack_80 = (float *)0x978286;

    (**(code **)(*piVar2 + 8))();

    pfStack_80 = (float *)0x0;

    uStack_88._4_4_ = (float *)0x978292;

    uStack_88 = FUN_0092c760();

    fStack_8c = 1.3914012e-38;

    FUN_00512160();

    uStack_88._4_4_ = (float *)0x9782ac;

    pfStack_80 = (float *)piVar2;

    FUN_004bc180();

    pfStack_80 = (float *)0x9782b6;

    uVar3 = (**(code **)(*piVar2 + 0x1cc))();

    param_1[4] = uVar3;

    pfStack_80 = (float *)0x9782be;

    iVar4 = CVOGReaction_RandomUnitScalar();

    if (0xfffff < *(int *)(iVar4 + 0xc)) {

      *(uint32_t /* width from decompiler */ *)(iVar4 + 0xc) = 0;

    }

    local_38 = g_flOne;

    *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + 1;

    pfStack_80 = &local_3c;

    uStack_88._4_4_ = &local_4c;

    local_3c = 0.0;

    local_34 = 0.0;

    uStack_88._0_4_ = 1.3914161e-38;

    FUN_0076f5f0();

    local_24 = (uint8_t *)(extraout_EDX & 0xffff);

    fVar6 = (float10)fsin((float10)(int)local_24 * (float10)_DAT_00aaaa84);

    local_40 = (float)((float10)local_4c * fVar6);

    local_3c = (float)((float10)local_48 * fVar6);

    local_38 = (float)((float10)local_44 * fVar6);

    fVar6 = (float10)fcos((float10)(int)local_24 * (float10)_DAT_00aaaa84);

    local_34 = (float)fVar6;

    pfStack_80 = (float *)0x97834f;

    iVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 4 + param_2) + 0x19c))();

    if (*(int *)(iVar4 + 8) == 0) {

      puVar5 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 0x84 + iVar4);

    }

    else {

      puVar5 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar4 + 8) + 0x3c) + 0xb0);

    }

    local_60 = *puVar5;

    local_5c = puVar5[1];

    local_58 = puVar5[2];

    local_54 = puVar5[3];

    pfStack_80 = (float *)&local_60;

    uStack_88._4_4_ = (float *)&local_30;

    uStack_88._0_4_ = 1.3914381e-38;

    FUN_004e88e0();

    fVar1 = local_40;

    pfStack_80 = (float *)0x0;

    fStack_90 = local_40;

    fStack_8c = local_3c;

    uStack_88._0_4_ = local_38;

    local_24 = (uint8_t *)&uStack_9c;

    uStack_88._4_4_ = (float *)local_34;

    uStack_9c = local_30;

    uStack_98 = local_2c;

    uStack_94 = local_28;

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[4])(1);

    (**(code **)(*(int *)param_1[4] + 0x20))();

    (**(code **)(*(int *)(*(int *)(*(int *)(param_1[4] + 4) + 4) + 4 + param_1[4]) + 0x100))();

    FUN_005828b0(1,"obj_f_inc_mov_01_airlift_at.anm",0);

    FUN_005828b0(2,"obj_f_inc_mov_01_airlift_aut.anm",0);

    FUN_005828b0(3,"obj_f_inc_mov_01_airlift_at2.anm",0);

    FUN_005816a0(1,0);

    iVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1[9] + 4) + 4) + 4 + param_1[9]) + 0x210))

                      (0);

    if (iVar4 == DAT_00d1b6d8) {

      param_1[3] = *(uint32_t /* width from decompiler */ *)(DAT_00d1b778 + 0x60c);

      *(uint32_t /* width from decompiler */ *)(DAT_00d1b778 + 0x60c) = 4;

      FUN_0090dd50();

      iVar4 = DAT_00d1b778;

      *(uint32_t /* width from decompiler */ *)(DAT_00d1b778 + 0xce4) = local_30;

      *(uint32_t /* width from decompiler */ *)(iVar4 + 0xce8) = local_2c;

      *(uint32_t /* width from decompiler */ *)(iVar4 + 0xcec) = local_28;

      *(float *)(iVar4 + 0xcf0) = fVar1;

      *(float *)(iVar4 + 0xcf4) = local_3c;

      *(float *)(iVar4 + 0xcf8) = local_38;

      *(float *)(iVar4 + 0xcfc) = local_34;

    }

    FUN_009780c0();

  }

  ExceptionList = local_1c;

  return param_1;

}
