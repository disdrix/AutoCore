// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGCharacter_Crea_005c6c70
// -----------------------------------------------------------------------------
// Stable ID: aa_005c6c70
// Callee of Named_CalleeOf_Named_CalleeOf_CVOGCharacter_CreateFromPacket
// Address:   0x005c6c70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_CVOGCharacter_CreateFromPacket: packet/network helper. Evidence string: "CLoadNode::setCreateMsg". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "CLoadNode::setCreateMsg"
//   - "UNKNOWN message format passed to LoadNode::setCreateMsg(), #%d"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~319 non-empty decompiler lines.
//  - Control keywords: for×17, if×13, return×2, switch×1.
//  - Notable callees: FUN_00506ee0×2, FUN_005c67b0, FUN_005c6c70, FUN_0076cef0, FUN_0076cf00, FUN_007a4480, LoadNode::setCreateMsg.
//  - Strings: "CLoadNode::setCreateMsg".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_CVOGCharacter_CreateFromPacket
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall

Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGCharacter_Crea_005c6c70(int param_1,uint32_t /* width from decompiler */ *param_2,int param_3,uint8_t param_4,uint8_t param_5,

            uint8_t param_6)



{

  uint8_t uVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ uVar3;

  void *pvVar4;

  uint uVar5;

  int iVar6;

  uint32_t /* width from decompiler */ *puVar7;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a6df0;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0076cf00("CLoadNode::setCreateMsg");

  local_4 = 0;

  puVar2 = operator_new(0xc);

  *(uint32_t /* width from decompiler */ **)(param_1 + 0x6c) = puVar2;

  *puVar2 = 0;

  puVar2[1] = 0;

  puVar2[2] = 0;

  *(int *)(*(int *)(param_1 + 0x6c) + 4) = param_3;

  *(uint8_t *)(*(int *)(param_1 + 0x6c) + 8) = param_4;

  *(uint8_t *)(*(int *)(param_1 + 0x6c) + 9) = param_5;

  *(uint8_t *)(*(int *)(param_1 + 0x6c) + 10) = param_6;

  *(uint8_t *)(param_1 + 0x60) = param_6;

  *(uint8_t *)(param_1 + 0x67) = param_5;

  switch(*param_2) {

  case 0x2012:

    pvVar4 = operator_new(0xd8);

    if (pvVar4 == (void *)0x0) {

      **(uint32_t /* width from decompiler */ **)(param_1 + 0x6c) = 0;

      puVar2 = (uint32_t /* width from decompiler */ *)**(uint32_t /* width from decompiler */ **)(param_1 + 0x6c);

      for (iVar6 = 0x36; iVar6 != 0; iVar6 = iVar6 + -1) {

        *puVar2 = *param_2;

        param_2 = param_2 + 1;

        puVar2 = puVar2 + 1;

      }

    }

    else {

      *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 0x6c) = 0;

      *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 0x68) = 0;

      *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 100) = 0;

      *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 0x78) = 0;

      *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 0x74) = 0;

      *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 0x70) = 0;

      *(float *)((int)pvVar4 + 0x7c) = g_flMsToSeconds_Inferred;

      **(uint32_t /* width from decompiler */ **)(param_1 + 0x6c) = pvVar4;

      puVar2 = (uint32_t /* width from decompiler */ *)**(uint32_t /* width from decompiler */ **)(param_1 + 0x6c);

      for (iVar6 = 0x36; iVar6 != 0; iVar6 = iVar6 + -1) {

        *puVar2 = *param_2;

        param_2 = param_2 + 1;

        puVar2 = puVar2 + 1;

      }

    }

    break;

  case 0x2013:

    pvVar4 = operator_new(0x930);

    if (pvVar4 == (void *)0x0) {

      pvVar4 = (void *)0x0;

    }

    else {

      *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 0x6c) = 0;

      *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 0x68) = 0;

      *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 100) = 0;

      *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 0x78) = 0;

      *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 0x74) = 0;

      *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 0x70) = 0;

      *(float *)((int)pvVar4 + 0x7c) = g_flMsToSeconds_Inferred;

    }

    **(uint32_t /* width from decompiler */ **)(param_1 + 0x6c) = pvVar4;

    puVar2 = param_2;

    puVar7 = (uint32_t /* width from decompiler */ *)**(uint32_t /* width from decompiler */ **)(param_1 + 0x6c);

    for (uVar5 = (uint)*(byte *)(param_2 + 0x43) * 8 + 0x138 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

      *puVar7 = *puVar2;

      puVar2 = puVar2 + 1;

      puVar7 = puVar7 + 1;

    }

    for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {

      *(uint8_t *)puVar7 = *(uint8_t *)puVar2;

      puVar2 = (uint32_t /* width from decompiler */ *)((int)puVar2 + 1);

      puVar7 = (uint32_t /* width from decompiler */ *)((int)puVar7 + 1);

    }

    FUN_005c67b0(param_2);

    *(uint8_t *)(param_1 + 0x62) = 1;

    break;

  default:

    FUN_007a4480(1,"UNKNOWN message format passed to LoadNode::setCreateMsg(), #%d",*param_2);

    if (*(void **)(param_1 + 0x6c) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(*(void **)(param_1 + 0x6c));

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x6c) = 0;

    break;

  case 0x2015:

    pvVar4 = operator_new(0x1a8);

    if (pvVar4 == (void *)0x0) {

      pvVar4 = (void *)0x0;

    }

    else {

      *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 0x6c) = 0;

      *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 0x68) = 0;

      *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 100) = 0;

      *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 0x78) = 0;

      *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 0x74) = 0;

      *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 0x70) = 0;

      *(float *)((int)pvVar4 + 0x7c) = g_flMsToSeconds_Inferred;

    }

    **(uint32_t /* width from decompiler */ **)(param_1 + 0x6c) = pvVar4;

    puVar2 = param_2;

    puVar7 = (uint32_t /* width from decompiler */ *)**(uint32_t /* width from decompiler */ **)(param_1 + 0x6c);

    for (iVar6 = 0x6a; iVar6 != 0; iVar6 = iVar6 + -1) {

      *puVar7 = *puVar2;

      puVar2 = puVar2 + 1;

      puVar7 = puVar7 + 1;

    }

    if ((param_3 == 2) && ((*(byte *)((int)param_2 + 0x129) & 1) == 0)) {

      *(uint8_t *)(param_1 + 100) = 1;

    }

    else {

      *(uint8_t *)(param_1 + 100) = 0;

    }

    break;

  case 0x2016:

    pvVar4 = operator_new(0x1358);

    if (pvVar4 == (void *)0x0) {

      pvVar4 = (void *)0x0;

    }

    else {

      *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 0x6c) = 0;

      *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 0x68) = 0;

      *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 100) = 0;

      *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 0x78) = 0;

      *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 0x74) = 0;

      *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 0x70) = 0;

      *(float *)((int)pvVar4 + 0x7c) = g_flMsToSeconds_Inferred;

    }

    **(uint32_t /* width from decompiler */ **)(param_1 + 0x6c) = pvVar4;

    puVar2 = param_2;

    puVar7 = (uint32_t /* width from decompiler */ *)**(uint32_t /* width from decompiler */ **)(param_1 + 0x6c);

    for (iVar6 = 0x4d6; iVar6 != 0; iVar6 = iVar6 + -1) {

      *puVar7 = *puVar2;

      puVar2 = puVar2 + 1;

      puVar7 = puVar7 + 1;

    }

    uVar1 = 0;

    *(uint32_t /* width from decompiler */ *)(**(int **)(param_1 + 0x6c) + 0x133c) = 0;

    *(uint32_t /* width from decompiler */ *)(**(int **)(param_1 + 0x6c) + 0x1340) = 0;

    *(uint32_t /* width from decompiler */ *)(**(int **)(param_1 + 0x6c) + 0x1344) = 0;

    *(uint32_t /* width from decompiler */ *)(**(int **)(param_1 + 0x6c) + 0x1348) = 0;

    *(uint32_t /* width from decompiler */ *)(**(int **)(param_1 + 0x6c) + 0x134c) = 0;

    *(uint32_t /* width from decompiler */ *)(**(int **)(param_1 + 0x6c) + 0x1350) = 0;

    *(uint32_t /* width from decompiler */ *)(**(int **)(param_1 + 0x6c) + 0x1354) = 0;

    if ((param_3 == 2) && ((*(byte *)((int)param_2 + 0x129) & 1) == 0)) {

      uVar1 = 1;

    }

    *(uint8_t *)(param_1 + 100) = uVar1;

    break;

  case 0x2018:

    pvVar4 = operator_new(0x150);

    if (pvVar4 == (void *)0x0) {

      **(uint32_t /* width from decompiler */ **)(param_1 + 0x6c) = 0;

      puVar2 = (uint32_t /* width from decompiler */ *)**(uint32_t /* width from decompiler */ **)(param_1 + 0x6c);

      for (iVar6 = 0x54; iVar6 != 0; iVar6 = iVar6 + -1) {

        *puVar2 = *param_2;

        param_2 = param_2 + 1;

        puVar2 = puVar2 + 1;

      }

    }

    else {

      *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 0x6c) = 0;

      *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 0x68) = 0;

      *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 100) = 0;

      *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 0x78) = 0;

      *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 0x74) = 0;

      *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 0x70) = 0;

      *(float *)((int)pvVar4 + 0x7c) = g_flMsToSeconds_Inferred;

      **(uint32_t /* width from decompiler */ **)(param_1 + 0x6c) = pvVar4;

      puVar2 = (uint32_t /* width from decompiler */ *)**(uint32_t /* width from decompiler */ **)(param_1 + 0x6c);

      for (iVar6 = 0x54; iVar6 != 0; iVar6 = iVar6 + -1) {

        *puVar2 = *param_2;

        param_2 = param_2 + 1;

        puVar2 = puVar2 + 1;

      }

    }

    break;

  case 0x2019:

  case 0x201a:

    pvVar4 = operator_new(0xe0);

    if (pvVar4 == (void *)0x0) {

      **(uint32_t /* width from decompiler */ **)(param_1 + 0x6c) = 0;

      puVar2 = (uint32_t /* width from decompiler */ *)**(uint32_t /* width from decompiler */ **)(param_1 + 0x6c);

      for (iVar6 = 0x38; iVar6 != 0; iVar6 = iVar6 + -1) {

        *puVar2 = *param_2;

        param_2 = param_2 + 1;

        puVar2 = puVar2 + 1;

      }

    }

    else {

      *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 0x6c) = 0;

      *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 0x68) = 0;

      *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 100) = 0;

      *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 0x78) = 0;

      *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 0x74) = 0;

      *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 0x70) = 0;

      *(float *)((int)pvVar4 + 0x7c) = g_flMsToSeconds_Inferred;

      **(uint32_t /* width from decompiler */ **)(param_1 + 0x6c) = pvVar4;

      puVar2 = (uint32_t /* width from decompiler */ *)**(uint32_t /* width from decompiler */ **)(param_1 + 0x6c);

      for (iVar6 = 0x38; iVar6 != 0; iVar6 = iVar6 + -1) {

        *puVar2 = *param_2;

        param_2 = param_2 + 1;

        puVar2 = puVar2 + 1;

      }

    }

    break;

  case 0x201b:

  case 0x2060:

    pvVar4 = operator_new(0x158);

    if (pvVar4 == (void *)0x0) {

      pvVar4 = (void *)0x0;

    }

    else {

      *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 0x6c) = 0;

      *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 0x68) = 0;

      *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 100) = 0;

      *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 0x78) = 0;

      *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 0x74) = 0;

      *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 0x70) = 0;

      *(float *)((int)pvVar4 + 0x7c) = g_flMsToSeconds_Inferred;

    }

    **(uint32_t /* width from decompiler */ **)(param_1 + 0x6c) = pvVar4;

    puVar2 = (uint32_t /* width from decompiler */ *)**(uint32_t /* width from decompiler */ **)(param_1 + 0x6c);

    for (iVar6 = 0x56; iVar6 != 0; iVar6 = iVar6 + -1) {

      *puVar2 = *param_2;

      param_2 = param_2 + 1;

      puVar2 = puVar2 + 1;

    }

    break;

  case 0x201c:

    pvVar4 = operator_new(0x188);

    if (pvVar4 == (void *)0x0) {

      **(uint32_t /* width from decompiler */ **)(param_1 + 0x6c) = 0;

      puVar2 = (uint32_t /* width from decompiler */ *)**(uint32_t /* width from decompiler */ **)(param_1 + 0x6c);

      for (iVar6 = 0x62; iVar6 != 0; iVar6 = iVar6 + -1) {

        *puVar2 = *param_2;

        param_2 = param_2 + 1;

        puVar2 = puVar2 + 1;

      }

    }

    else {

      *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 0x6c) = 0;

      *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 0x68) = 0;

      *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 100) = 0;

      *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 0x78) = 0;

      *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 0x74) = 0;

      *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 0x70) = 0;

      *(float *)((int)pvVar4 + 0x7c) = g_flMsToSeconds_Inferred;

      **(uint32_t /* width from decompiler */ **)(param_1 + 0x6c) = pvVar4;

      puVar2 = (uint32_t /* width from decompiler */ *)**(uint32_t /* width from decompiler */ **)(param_1 + 0x6c);

      for (iVar6 = 0x62; iVar6 != 0; iVar6 = iVar6 + -1) {

        *puVar2 = *param_2;

        param_2 = param_2 + 1;

        puVar2 = puVar2 + 1;

      }

    }

    break;

  case 0x201d:

    pvVar4 = operator_new(0xd78);

    if (pvVar4 == (void *)0x0) {

      **(uint32_t /* width from decompiler */ **)(param_1 + 0x6c) = 0;

      puVar2 = (uint32_t /* width from decompiler */ *)**(uint32_t /* width from decompiler */ **)(param_1 + 0x6c);

      for (iVar6 = 0x35e; iVar6 != 0; iVar6 = iVar6 + -1) {

        *puVar2 = *param_2;

        param_2 = param_2 + 1;

        puVar2 = puVar2 + 1;

      }

    }

    else {

      uVar3 = FUN_00506ee0();

      **(uint32_t /* width from decompiler */ **)(param_1 + 0x6c) = uVar3;

      puVar2 = (uint32_t /* width from decompiler */ *)**(uint32_t /* width from decompiler */ **)(param_1 + 0x6c);

      for (iVar6 = 0x35e; iVar6 != 0; iVar6 = iVar6 + -1) {

        *puVar2 = *param_2;

        param_2 = param_2 + 1;

        puVar2 = puVar2 + 1;

      }

    }

    break;

  case 0x201e:

    pvVar4 = operator_new(0x1d80);

    if (pvVar4 == (void *)0x0) {

      pvVar4 = (void *)0x0;

    }

    else {

      FUN_00506ee0();

    }

    **(uint32_t /* width from decompiler */ **)(param_1 + 0x6c) = pvVar4;

    uVar5 = (0x200 - (uint)*(ushort *)((int)param_2 + 0xd7a)) * -8 + 0x1d80 >> 2;

    puVar2 = (uint32_t /* width from decompiler */ *)**(uint32_t /* width from decompiler */ **)(param_1 + 0x6c);

    for (; uVar5 != 0; uVar5 = uVar5 - 1) {

      *puVar2 = *param_2;

      param_2 = param_2 + 1;

      puVar2 = puVar2 + 1;

    }

    for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {

      *(uint8_t *)puVar2 = *(uint8_t *)param_2;

      param_2 = (uint32_t /* width from decompiler */ *)((int)param_2 + 1);

      puVar2 = (uint32_t /* width from decompiler */ *)((int)puVar2 + 1);

    }

  }

  local_4 = 0xffffffff;

  FUN_0076cef0();

  ExceptionList = local_c;

  return;

}
