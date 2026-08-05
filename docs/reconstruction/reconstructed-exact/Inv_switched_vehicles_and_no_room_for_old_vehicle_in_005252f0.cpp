// READABILITY (auto CF):
//  - Body size: ~333 non-empty decompiler lines.
//  - Control keywords: if×25, return×5, for×1.
//  - Notable callees: FUN_00572360×3, FUN_00512670×2, FUN_005714e0×2, FUN_00571620×2, FUN_00571b80×2, FUN_007a4480×2, FUN_004c49d0, FUN_004f39c0.
//  - Strings: "VOG_DEBUG_STOP".
//  - Return sites: 5.

// =============================================================================
// Inv_switched_vehicles_and_no_room_for_old_vehicle_in_005252f0
// -----------------------------------------------------------------------------
// Stable ID: aa_005252f0
// Address:   0x005252f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "switched vehicles, and no room for old vehicle in either inventory"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __thiscall

Inv_switched_vehicles_and_no_room_for_old_vehicle_in_005252f0(int param_1,uint32_t /* width from decompiler */ *param_2,int *param_3,uint param_4,uint param_5)



{

  int *piVar1;

  uint *puVar2;

  short sVar3;

  uint uVar4;

  int *piVar5;

  float fVar6;

  char cVar7;

  void *pvVar8;

  uint32_t /* width from decompiler */ *puVar9;

  int iVar10;

  int iVar11;

  uint32_t /* width from decompiler */ unaff_ESI;

  uint32_t /* width from decompiler */ unaff_EDI;

  uint32_t /* width from decompiler */ uStack_c4;

  uint32_t /* width from decompiler */ uStack_c0;

  int iStack_bc;

  uint32_t /* width from decompiler */ *puStack_b8;

  char *pcStack_b4;

  uint32_t /* width from decompiler */ uStack_b0;

  char *pcStack_ac;

  uint32_t /* width from decompiler */ uStack_a8;

  uint32_t /* width from decompiler */ uStack_a4;

  uint32_t /* width from decompiler */ uStack_a0;

  uint32_t /* width from decompiler */ uStack_9c;

  uint32_t /* width from decompiler */ uStack_98;

  uint32_t /* width from decompiler */ uStack_94;

  uint32_t /* width from decompiler */ uStack_90;

  int iStack_8c;

  int *piStack_88;

  uint32_t /* width from decompiler */ *puStack_84;

  int iStack_80;

  uint32_t /* width from decompiler */ uVar12;

  int aiStack_4c [3];

  uint32_t /* width from decompiler */ uStack_40;

  uint32_t /* width from decompiler */ uStack_3c;

  uint32_t /* width from decompiler */ uStack_38;

  uint32_t /* width from decompiler */ uStack_34;

  uint32_t /* width from decompiler */ uStack_30;

  uint32_t /* width from decompiler */ uStack_2c;

  uint32_t /* width from decompiler */ uStack_28;

  uint32_t /* width from decompiler */ uStack_24;

  void *local_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ local_14;

  

  local_14 = 0xffffffff;

  puStack_18 = &LAB_009a384e;

  local_1c = ExceptionList;

  if (param_2 == (uint32_t /* width from decompiler */ *)0x0) {

    return 0x80070057;

  }

  ExceptionList = &local_1c;

  if (param_3 != (int *)0x0) {

    ExceptionList = &local_1c;

    *param_3 = *(int *)(param_1 + 0x250);

  }

  sVar3 = *(short *)((int)param_2 + 0x1e6);

  if (sVar3 < *(short *)(*(int *)(param_1 + 0x250) + 0x1e6)) {

    pvVar8 = operator_new(0x68);

    local_14 = 0;

    if (pvVar8 == (void *)0x0) {

      puVar9 = (uint32_t /* width from decompiler */ *)0x0;

    }

    else {

      iStack_80 = 0x5253aa;

      puVar9 = InventoryGrid_ctor_Inferred(pvVar8,6,sVar3 * 0xd,(int)sVar3);

    }

    local_14 = 0xffffffff;

    cVar7 = FUN_00572360();

    if (cVar7 == '\0') {

      if (puVar9 == (uint32_t /* width from decompiler */ *)0x0) {

        ExceptionList = local_1c;

        return 0x80004005;

      }

      (**(code **)*puVar9)();

      ExceptionList = local_1c;

      return 0x80004005;

    }

    FUN_00572360();

    if (puVar9 != (uint32_t /* width from decompiler */ *)0x0) {

      (**(code **)*puVar9)();

    }

  }

  iVar10 = (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x250) + 4) + 4) + 4 +

                                *(int *)(param_1 + 0x250)) + 0x1c8))();

  if (*(int *)(iVar10 + 8) == 0) {

    puVar9 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar10 + 4) + 4) + 0x84 + iVar10);

  }

  else {

    puVar9 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar10 + 8) + 0x3c) + 0xb0);

  }

  uStack_40 = *puVar9;

  uStack_3c = puVar9[1];

  uStack_38 = puVar9[2];

  uStack_34 = puVar9[3];

  if (*(int *)(iVar10 + 8) == 0) {

    puVar9 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar10 + 4) + 4) + 0x94 + iVar10);

  }

  else {

    puVar9 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar10 + 8) + 0x3c) + 0x30);

  }

  uStack_30 = *puVar9;

  uStack_2c = puVar9[1];

  uStack_28 = puVar9[2];

  uStack_24 = puVar9[3];

  puVar2 = (uint *)(*(int *)(*(int *)(*(int *)(param_1 + 0x250) + 4) + 4) +

                    *(int *)(param_1 + 0x250) + 0x180);

  *puVar2 = *puVar2 | 0x10;

  FUN_00512670();

  uVar12 = 1;

  (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x250) + 4) + 4) + 4 +

                       *(int *)(param_1 + 0x250)) + 0x40))();

  iStack_80 = *(int *)(param_2[1] + 4) + 4 + (int)param_2;

  puStack_84 = (uint32_t /* width from decompiler */ *)0x525517;

  FUN_00571b80();

  iStack_80 = *(int *)(param_2[1] + 4) + 4 + (int)param_2;

  puStack_84 = (uint32_t /* width from decompiler */ *)0x525531;

  FUN_00571b80();

  (**(code **)(**(int **)(param_1 + 0x250) + 4))();

  (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x250) + 4) + 4) + 4 +

                       *(int *)(param_1 + 0x250)) + 0xfc))();

  (**(code **)(*(int *)(*(int *)(param_1 + 0x250) + 0x40) + 0x18))();

  FUN_004f4eb0();

  *(uint8_t *)(param_2 + 0xab) = 0;

  iStack_80 = 0x525586;

  Vehicle_CreateCargoInventoryFromPageCount(param_2,*(short *)((int)param_2 + 0x1e6));

  *(uint8_t *)(*(int *)(param_1 + 0x250) + 0x2ac) = 1;

  iStack_80 = param_2[0xac];

  puStack_84 = (uint32_t /* width from decompiler */ *)0x5255ad;

  FUN_00572360();

  puVar2 = (uint *)(*(int *)(*(int *)(*(int *)(param_1 + 0x250) + 4) + 4) + 0x180 +

                   *(int *)(param_1 + 0x250));

  *puVar2 = *puVar2 | 0x10;

  FUN_00512670();

  if (param_2[0x96] == 0) {

    iStack_80 = 0x5255e0;

    pvVar8 = operator_new(0x2f0);

    if (pvVar8 == (void *)0x0) {

      iVar10 = 0;

    }

    else {

      iStack_80 = 0x5255f0;

      iVar10 = FUN_005a84f0();

    }

    puStack_84 = *(uint32_t /* width from decompiler */ **)

                  (*(int *)(*(int *)(*(int *)(param_2[1] + 4) + 0xac + (int)param_2) + 0x3c) + 0x6f4

                  );

    iStack_80 = *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1);

    piStack_88 = (int *)0x525636;

    iVar11 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar10 + 4) + 4) + 4 + iVar10) + 8))();

    if (iVar11 < 0) {

      ExceptionList = local_1c;

      return 0x80004005;

    }

    if ((param_4 & param_5) == 0xffffffff) {

      iVar11 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1);

      uVar4 = *(uint *)(iVar11 + 0xe6e0);

      aiStack_4c[0] = *(int *)(iVar11 + 0xe6e4);

      *(uint *)(iVar11 + 0xe6e0) = uVar4 + 1;

      *(uint *)(iVar11 + 0xe6e4) = aiStack_4c[0] + (uint)(0xfffffffe < uVar4);

    }

    iStack_80 = 0x5256ad;

    FUN_00512160();

    *(uint8_t *)(iVar10 + 0xcc) = 1;

    uVar12 = *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1);

    (**(code **)(*(int *)(*(int *)(*(int *)(iVar10 + 4) + 4) + 4 + iVar10) + 0x218))();

    iStack_80 = 0x5256dc;

    Vehicle_SetWheelset();

  }

  FUN_004f7690();

  FUN_004f7830();

  *(uint8_t *)(*(int *)(param_1 + 0x250) + 0x114) = 0;

  *(uint8_t *)((int)param_2 + 0x101) =

       *(uint8_t *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1) + 0xf5);

  iStack_80 = 0x52571c;

  FUN_004c49d0();

  iStack_80 = 0x52573e;

  (**(code **)(*(int *)(*(int *)(param_2[1] + 4) + 4 + (int)param_2) + 0x218))();

  *(bool *)(param_2 + 0x45) =

       *(char *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1) + 0xf5) == '\0';

  iVar10 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1);

  if (*(char *)(iVar10 + 0xf5) == '\0') {

    iStack_80 = 1;

    puStack_84 = &uStack_3c;

    piStack_88 = aiStack_4c;

    uStack_90 = 0x525784;

    iStack_8c = iVar10;

    (**(code **)*param_2)();

  }

  iStack_80 = *(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1;

  puStack_84 = (uint32_t /* width from decompiler */ *)0x5257a1;

  (**(code **)(*(int *)(*(int *)(param_2[1] + 4) + 4 + (int)param_2) + 0x158))();

  piVar1 = param_2 + 0x10;

  puStack_84 = (uint32_t /* width from decompiler */ *)0x5257ac;

  (**(code **)(param_2[0x10] + 4))();

  fVar6 = g_flOne;

  puStack_84 = (uint32_t /* width from decompiler */ *)0x0;

  uStack_94 = 0;

  uStack_90 = 0;

  iStack_8c = 0;

  piStack_88 = (int *)g_flOne;

  uStack_a0 = 0;

  uStack_9c = 0;

  uStack_98 = 0;

  uStack_a4 = 1;

  uStack_a8 = 0x525810;

  (**(code **)*piVar1)();

  piVar5 = (int *)param_2[0x96];

  if (piVar5 != (int *)0x0) {

    if (piVar5[2] == 0) {

      uStack_a8 = 0;

      puStack_b8 = (uint32_t /* width from decompiler */ *)0x0;

      iStack_80 = 0;

      pcStack_b4 = (char *)0x0;

      uStack_b0 = 0;

      puStack_84 = &uStack_c4;

      pcStack_ac = (char *)g_flOne;

      uStack_c4 = 0;

      uStack_c0 = 0;

      iStack_bc = 0;

      (**(code **)*piVar5)(1);

    }

    else {

      uStack_a8 = 1;

      pcStack_ac = (char *)0x525827;

      (**(code **)(*piVar5 + 0x18))();

    }

  }

  piVar5 = (int *)param_2[0x9b];

  if (piVar5 != (int *)0x0) {

    if (piVar5[2] == 0) {

      uStack_a8 = 0;

      puStack_b8 = (uint32_t /* width from decompiler */ *)0x0;

      iStack_80 = 0;

      pcStack_b4 = (char *)0x0;

      uStack_b0 = 0;

      puStack_84 = &uStack_c4;

      pcStack_ac = (char *)g_flOne;

      uStack_c4 = 0;

      uStack_c0 = 0;

      iStack_bc = 0;

      (**(code **)*piVar5)(1);

    }

    else {

      uStack_a8 = 1;

      pcStack_ac = (char *)0x5258a2;

      (**(code **)(*piVar5 + 0x18))();

    }

  }

  if (param_2[0x12] == 0) {

    uStack_a8 = 0;

    puStack_b8 = (uint32_t /* width from decompiler */ *)0x0;

    iStack_80 = 0;

    pcStack_b4 = (char *)0x0;

    uStack_b0 = 0;

    puStack_84 = &uStack_c4;

    pcStack_ac = (char *)g_flOne;

    uStack_c4 = uVar12;

    uStack_c0 = unaff_EDI;

    iStack_bc = unaff_ESI;

    (**(code **)*piVar1)(1);

  }

  else {

    uStack_a8 = 1;

    pcStack_ac = (char *)0x525915;

    (**(code **)(*piVar1 + 0x18))();

  }

  pcStack_ac = (char *)0x525994;

  FUN_004f39c0();

  *(uint32_t /* width from decompiler */ *)(param_2[0xa1] + 0x5c) = DAT_00a0f704;

  pcStack_ac = (char *)0x5259b2;

  FUN_004f4f00();

  iStack_bc = *param_3;

  if (iStack_bc != 0) {

    iStack_bc = *(int *)(*(int *)(iStack_bc + 4) + 4) + 4 + iStack_bc;

  }

  pcStack_ac = (char *)0xffffffff;

  uStack_b0 = 1;

  pcStack_b4 = (char *)&uStack_98;

  puStack_b8 = &uStack_94;

  uStack_c0 = 0x5259df;

  cVar7 = FUN_005714e0();

  iVar10 = *param_3;

  if (cVar7 == '\0') {

    if (iVar10 != 0) {

      iVar10 = *(int *)(*(int *)(iVar10 + 4) + 4) + 4 + iVar10;

    }

    pcStack_ac = (char *)0xffffffff;

    uStack_b0 = 1;

    pcStack_b4 = (char *)&uStack_98;

    puStack_b8 = &uStack_94;

    uStack_c0 = 0x525a35;

    iStack_bc = iVar10;

    cVar7 = FUN_005714e0();

    if (cVar7 == '\0') {

      pcStack_ac = "switched vehicles, and no room for old vehicle in either inventory";

      uStack_b0 = 1;

      pcStack_b4 = (char *)0x525a6f;

      FUN_007a4480();

      pcStack_b4 = "VOG_DEBUG_STOP";

      puStack_b8 = (uint32_t /* width from decompiler */ *)0x0;

      iStack_bc = 0x525a7b;

      FUN_007a4480();

    }

    else {

      puStack_b8 = (uint32_t /* width from decompiler */ *)*param_3;

      if (puStack_b8 != (uint32_t /* width from decompiler */ *)0x0) {

        puStack_b8 = (uint32_t /* width from decompiler */ *)

                     (*(int *)(*(int *)((int)puStack_b8 + 4) + 4) + 4 + (int)puStack_b8);

      }

      pcStack_ac = (char *)0x1;

      uStack_b0 = uStack_98;

      pcStack_b4 = (char *)uStack_94;

      iStack_bc = 0x525a61;

      FUN_00571620();

    }

  }

  else {

    if (iVar10 != 0) {

      iVar10 = *(int *)(*(int *)(iVar10 + 4) + 4) + 4 + iVar10;

    }

    pcStack_ac = (char *)0x1;

    uStack_b0 = uStack_98;

    pcStack_b4 = (char *)uStack_94;

    iStack_bc = 0x525a0b;

    puStack_b8 = (uint32_t /* width from decompiler */ *)iVar10;

    FUN_00571620();

  }

  ExceptionList = (void *)fVar6;

  return 0;

}
