// =============================================================================
// FUN_005d73f0
// -----------------------------------------------------------------------------
// Stable ID: aa_005d73f0
// Address:   0x005d73f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005d73f0 @ 0x005d73f0
// Stable ID: aa_005d73f0
// Embedded strings (evidence for future rename):
//   - "Flipper"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~121 non-empty decompiler lines.
//  - Control keywords: if×10, goto×1, return×1.
//  - Notable callees: CVOGReaction_RandomUnitScalar×2, SQRT×2, CVOGHBBase_Start, CVOGHBList_Enqueue, FUN_004e8b60, FUN_005070b0, FUN_005070d0, FUN_005075f0.
//  - Strings: "Flipper".
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



void __fastcall FUN_005d73f0(int param_1)



{

  float fVar1;

  ushort uVar2;

  ushort uVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int iVar5;

  char *pcVar6;

  CVOGHBBase *pAction;

  float fVar7;

  float fVar8;

  float fVar9;

  uint8_t local_59;

  void *local_58;

  uint32_t /* width from decompiler */ local_54;

  float local_50;

  float local_4c;

  float local_48;

  float local_44;

  uint32_t /* width from decompiler */ local_40;

  uint32_t /* width from decompiler */ local_3c;

  uint32_t /* width from decompiler */ local_38;

  uint32_t /* width from decompiler */ local_34;

  uint8_t local_30 [4];

  float local_2c;

  void *pvStack_1c;

  uint8_t *puStack_18;

  int local_14;

  

  local_14 = 0xffffffff;

  puStack_18 = &LAB_009a7187;

  pvStack_1c = ExceptionList;

  local_54 = DAT_00d1f040;

  ExceptionList = &pvStack_1c;

  FUN_0076cf00("Flipper");

  iVar5 = *(int *)(param_1 + 0xbc);

  local_14 = 0;

  if (*(int *)(iVar5 + 8) == 0) {

    puVar4 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 0x94 + iVar5);

  }

  else {

    puVar4 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar5 + 8) + 0x3c) + 0x30);

  }

  local_40 = *puVar4;

  local_3c = puVar4[1];

  local_38 = puVar4[2];

  local_34 = puVar4[3];

  FUN_004e8b60(&local_40,local_30);

  if (local_2c < (float)_DAT_009dafc8) {

    iVar5 = *(int *)(*(int *)(*(int *)(param_1 + 0xbc) + 8) + 0x3c);

    local_58 = (void *)(*(float *)(iVar5 + 0x40) * *(float *)(iVar5 + 0x40) +

                        *(float *)(iVar5 + 0x44) * *(float *)(iVar5 + 0x44) +

                       *(float *)(iVar5 + 0x48) * *(float *)(iVar5 + 0x48));

    if (SQRT((float)local_58) < g_flVehicleHpTechCoeff) {

      *(char *)(param_1 + 0xb0) = *(char *)(param_1 + 0xb0) + '\x01';

      goto LAB_005d74fe;

    }

  }

  *(uint8_t *)(param_1 + 0xb0) = 0;

LAB_005d74fe:

  if (*(char *)(param_1 + 0xb1) < *(char *)(param_1 + 0xb0)) {

    *(uint8_t *)(param_1 + 0xb0) = 0;

    iVar5 = CVOGReaction_RandomUnitScalar();

    if (0xfffff < *(int *)(iVar5 + 0xc)) {

      *(uint32_t /* width from decompiler */ *)(iVar5 + 0xc) = 0;

    }

    uVar2 = *(ushort *)(*(int *)(iVar5 + 8) + *(int *)(iVar5 + 0xc) * 2);

    *(int *)(iVar5 + 0xc) = *(int *)(iVar5 + 0xc) + 1;

    iVar5 = CVOGReaction_RandomUnitScalar();

    if (0xfffff < *(int *)(iVar5 + 0xc)) {

      *(uint32_t /* width from decompiler */ *)(iVar5 + 0xc) = 0;

    }

    fVar1 = DAT_00aaa638;

    fVar7 = g_flLevelUpUiBase_Inferred;

    fVar9 = DAT_00a0f298;

    uVar3 = *(ushort *)(*(int *)(iVar5 + 8) + *(int *)(iVar5 + 0xc) * 2);

    local_44 = 0.0;

    *(int *)(iVar5 + 0xc) = *(int *)(iVar5 + 0xc) + 1;

    fVar8 = ((float)uVar3 * fVar1 - fVar9) * fVar7;

    fVar7 = ((float)uVar2 * fVar1 - fVar9) * fVar7;

    local_58 = (void *)(fVar7 * fVar7 + fVar8 * fVar8);

    if ((float)local_58 == 0.0) {

      fVar9 = 0.0;

    }

    else {

      fVar9 = g_flOne / SQRT((float)local_58);

      local_58 = (void *)fVar9;

    }

    fVar1 = *(float *)(*(int *)(*(int *)(*(int *)(param_1 + 0xbc) + 8) + 0x3c) + 0x2c);

    if (fVar1 != 0.0) {

      local_44 = g_flOne / fVar1;

    }

    local_44 = local_44 * DAT_00a110d8;

    local_50 = local_44 * (DAT_00af42c0 + fVar9 * fVar8 * g_flOverheatCoolFrac);

    local_4c = (fVar9 * 0.0 * g_flOverheatCoolFrac + _DAT_00af42c4) * local_44;

    local_48 = (fVar7 * fVar9 * g_flOverheatCoolFrac + _DAT_00af42c8) * local_44;

    local_44 = (fVar9 * 0.0 * g_flOverheatCoolFrac + _DAT_00af42cc) * local_44;

    iVar5 = *(int *)(*(int *)(param_1 + 0xbc) + 8);

    pcVar6 = (char *)FUN_005070b0(&local_59);

    if ((*pcVar6 == '\0') && (*(int *)(iVar5 + 0x44) != 0)) {

      FUN_005070d0();

    }

    (**(code **)(**(int **)(iVar5 + 0x3c) + 0x5c))(&local_50);

    local_58 = operator_new(0x2c);

    local_14._0_1_ = 1;

    if (local_58 == (void *)0x0) {

      pAction = (CVOGHBBase *)0x0;

    }

    else {

      pAction = (CVOGHBBase *)FUN_005075f0(*(uint32_t /* width from decompiler */ *)(param_1 + 0xbc),5000);

    }

    local_14 = (uint)local_14._1_3_ << 8;

    CVOGHBList_Enqueue(*(void **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0xbc) + 4) + 4) +

                                           0xa8 + *(int *)(param_1 + 0xbc)) + 0xe4ec),pAction);

    CVOGHBBase_Start(pAction);

  }

  local_14 = 0xffffffff;

  FUN_0076cef0();

  ExceptionList = pvStack_1c;

  return;

}
