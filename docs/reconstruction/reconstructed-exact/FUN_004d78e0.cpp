// =============================================================================
// FUN_004d78e0
// -----------------------------------------------------------------------------
// Stable ID: aa_004d78e0
// Address:   0x004d78e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004d78e0 @ 0x004d78e0
// Stable ID: aa_004d78e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~235 non-empty decompiler lines.
//  - Control keywords: if×26, goto×6, return×3.
//  - Notable callees: Client_EnqueueCombatFloater_INFERRED×2, FUN_0040da70×2, CONCAT31, FUN_004d78e0, FUN_00513b00, FUN_0058c3b0, Vehicle_SetCurrentShield.
//  - Return sites: 3.

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

uint8_t __thiscall

FUN_004d78e0(int param_1,uint8_t param_2,int param_3,int *param_4,int *param_5,char param_6,

            char param_7,uint param_8,uint param_9,char param_10,uint32_t /* width from decompiler */ param_11,int param_12)



{

  char cVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int *piVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint32_t /* width from decompiler */ unaff_EDI;

  float fVar7;

  uint64_t uVar8;

  uint32_t /* width from decompiler */ uStack_b4;

  int iStack_b0;

  int iStack_a8;

  int iStack_a4;

  int local_a0;

  int local_9c;

  float local_98;

  int local_94;

  int local_90;

  int local_8c;

  int local_88;

  int local_84;

  int local_80;

  uint8_t uStack_7c;

  uint8_t uStack_7b;

  uint8_t uStack_7a;

  uint8_t uStack_79;

  uint8_t local_78;

  uint8_t local_77;

  uint8_t uStack_76;

  char local_75;

  uint local_74;

  uint32_t /* width from decompiler */ uStack_70;

  uint32_t /* width from decompiler */ uStack_6c;

  float fStack_68;

  uint32_t /* width from decompiler */ uStack_64;

  uint32_t /* width from decompiler */ auStack_60 [4];

  float afStack_50 [6];

  uint32_t /* width from decompiler */ uStack_38;

  uint32_t /* width from decompiler */ uStack_34;

  uint32_t /* width from decompiler */ uStack_30;

  uint32_t /* width from decompiler */ uStack_2c;

  float fStack_28;

  uint32_t /* width from decompiler */ uStack_24;

  uint32_t /* width from decompiler */ uStack_20;

  uint32_t /* width from decompiler */ uStack_1c;

  uint32_t /* width from decompiler */ uStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  

  uStack_b4 = 0;

  if (param_3 == 0) {

    if ((((param_6 == '\0') && (*(char *)(param_1 + 0x7e) == '\0')) ||

        ((param_8 & param_9) != 0xffffffff)) || (param_10 != '\0')) goto LAB_004d7e20;

    piVar5 = param_4 + 0x58;

    if (param_4 == (int *)0x0) {

      piVar5 = &DAT_009cbf68;

    }

    local_a0 = *piVar5;

    local_9c = piVar5[1];

    local_98 = (float)piVar5[2];

    local_94 = piVar5[3];

    local_90 = param_5[0x58];

    local_8c = param_5[0x59];

    local_88 = param_5[0x5a];

    local_84 = param_5[0x5b];

    local_77 = param_2;

    local_80 = 0;

    if (param_4 == (int *)0x0) {

LAB_004d7dc9:

      local_78 = 0;

    }

    else {

      iVar2 = (**(code **)(*param_4 + 0x1d4))();

      if (iVar2 == 0) {

        iVar2 = (**(code **)(*param_4 + 0x1e0))();

        if (iVar2 != 0) {

          (**(code **)(*param_4 + 0x1e0))();

          iVar2 = FUN_0040da70();

          if (*(char *)(iVar2 + 0x3f4) == '\t') goto LAB_004d7dc2;

        }

        goto LAB_004d7dc9;

      }

LAB_004d7dc2:

      local_78 = 1;

    }

    if (param_12 == 0) {

      local_74 = (uint)local_74._1_3_ << 8;

      local_75 = '\0';

    }

    else {

      local_75 = *(char *)(param_12 + 6);

      local_74 = CONCAT31(local_74._1_3_,*(char *)(param_12 + 7));

      if (((local_75 == '\0') && (*(char *)(param_12 + 7) == '\0')) &&

         (*(char *)(param_12 + 8) == '\0')) {

        return 0;

      }

      uStack_76 = *(uint8_t *)(param_12 + 8);

    }

    uStack_70 = 0;

    Client_EnqueueCombatFloater_INFERRED(&local_a0);

    goto LAB_004d7e20;

  }

  iVar2 = (**(code **)(*param_5 + 0x23c))();

  iStack_a8 = 0;

  iStack_a4 = 0;

  iVar3 = (**(code **)(*param_5 + 0x1d4))();

  if (iVar3 != 0) {

    iVar3 = (**(code **)(*param_5 + 0x1d4))();

    iStack_a8 = *(int *)(iVar3 + 0x144);

  }

  if (*(char *)(param_1 + 0x7e) == '\0') {

    (**(code **)(*param_5 + 0x44))(param_3);

    uStack_b4 = (**(code **)(*param_5 + 0x23c))();

    iVar3 = iStack_a8;

  }

  else {

    uStack_b4 = iVar2 - param_3;

    iVar4 = (**(code **)(*param_5 + 0x244))();

    iVar3 = param_1;

    if (iVar4 < uStack_b4) {

      uStack_b4 = (**(code **)(*param_5 + 0x244))();

    }

  }

  uStack_b4 = iVar2 - uStack_b4;

  iVar4 = (**(code **)(*param_5 + 0x1d4))();

  if (iVar4 != 0) {

    iVar4 = (**(code **)(*param_5 + 0x1d4))();

    iStack_a8 = *(int *)(iVar4 + 0x144);

  }

  if (param_7 == '\0') {

    (**(code **)(*param_5 + 0x240))(iVar2);

    iVar2 = (**(code **)(*param_5 + 0x1d4))();

    if (iVar2 != 0) {

      uVar8 = (**(code **)(*param_5 + 0x1d4))(iVar3);

      Vehicle_SetCurrentShield((VehicleCombatPools_Inferred *)uVar8,(int)((ulonglong)uVar8 >> 0x20))

      ;

    }

  }

  if ((((param_8 & param_9) == 0xffffffff) && (param_10 == '\0')) &&

     ((param_6 != '\0' || (*(char *)(iStack_b0 + 0x7e) != '\0')))) {

    piVar5 = param_4 + 0x58;

    if (param_4 == (int *)0x0) {

      piVar5 = &DAT_009cbf68;

    }

    iStack_a4 = *piVar5;

    local_a0 = piVar5[1];

    local_9c = piVar5[2];

    local_98 = (float)piVar5[3];

    local_94 = param_5[0x58];

    local_90 = param_5[0x59];

    local_8c = param_5[0x5a];

    local_88 = param_5[0x5b];

    uStack_7b = param_2;

    local_84 = param_3;

    local_80 = iVar3 - iStack_a8;

    if (param_4 == (int *)0x0) {

LAB_004d7ab7:

      uStack_7c = 0;

    }

    else {

      iVar2 = (**(code **)(*param_4 + 0x1d4))();

      if (iVar2 == 0) {

        iVar2 = (**(code **)(*param_4 + 0x1e0))();

        if (iVar2 != 0) {

          (**(code **)(*param_4 + 0x1e0))();

          iVar2 = FUN_0040da70();

          if (*(char *)(iVar2 + 0x3f4) == '\t') goto LAB_004d7ab0;

        }

        goto LAB_004d7ab7;

      }

LAB_004d7ab0:

      uStack_7c = 1;

    }

    if (param_12 == 0) {

      local_78 = 0;

      uStack_7a = 0;

      uStack_79 = 0;

    }

    else {

      local_78 = *(uint8_t *)(param_12 + 7);

      uStack_7a = *(uint8_t *)(param_12 + 8);

      uStack_79 = *(uint8_t *)(param_12 + 6);

    }

    local_74 = (uint)(param_3 < 0);

    if ((-1 < param_3) || (uStack_b4 != 0)) {

      Client_EnqueueCombatFloater_INFERRED(&iStack_a4);

    }

  }

  piVar5 = (int *)(**(code **)(*param_5 + 0x214))();

  if (((piVar5 != (int *)0x0) && (param_4 != (int *)0x0)) &&

     (cVar1 = (**(code **)(*(int *)(*(int *)(piVar5[1] + 4) + 4 + (int)piVar5) + 0x298))(param_4),

     cVar1 != '\0')) {

    puVar6 = (uint32_t /* width from decompiler */ *)FUN_00513b00(auStack_60);

    (**(code **)(*piVar5 + 0x88))(param_3,*puVar6,puVar6[1],puVar6[2],puVar6[3]);

  }

  if ((((*(char *)(param_1 + 0x7e) != '\0') || (param_7 != '\0')) &&

      ((0 < param_3 &&

       ((*(int *)(param_5[0x2a] + 0x38) == 3 &&

        (iVar2 = (**(code **)(*param_5 + 0x1c8))(), iVar2 != 0)))))) && (*(int *)(iVar2 + 8) != 0))

  {

    afStack_50[3] = 0.0;

    afStack_50[2] = 0.0;

    afStack_50[1] = 0.0;

    uStack_34 = 0;

    uStack_38 = 0;

    afStack_50[4] = 0.0;

    uStack_24 = 0;

    uStack_2c = 0;

    uStack_30 = 0;

    afStack_50[0] = g_flOne;

    afStack_50[5] = g_flOne;

    fStack_28 = g_flOne;

    uStack_14 = 0;

    uStack_18 = 0;

    uStack_1c = 0;

    uStack_20 = 0;

    (**(code **)(**(int **)(*(int *)(iVar2 + 8) + 0xc) + 0x18))(afStack_50,0x3dcccccd,&local_a0);

    fStack_68 = local_98 * DAT_00a0f734;

    uStack_6c = 0;

    uStack_64 = 0;

    auStack_60[0] = 0;

    iVar2 = (**(code **)(*param_5 + 0x244))();

    fVar7 = g_flOne;

    if (g_flOne < (float)param_3 / (float)iVar2) {

      iVar2 = (**(code **)(*param_5 + 0x244))();

      fVar7 = (float)param_3 / (float)iVar2;

    }

    FUN_0058c3b0(param_4,param_5,fVar7,&uStack_6c);

    return (char)((uint)unaff_EDI >> 0x18);

  }

LAB_004d7e20:

  return uStack_b4._3_1_;

}
