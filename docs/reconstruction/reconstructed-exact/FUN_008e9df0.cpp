// =============================================================================
// FUN_008e9df0
// -----------------------------------------------------------------------------
// Stable ID: aa_008e9df0
// Address:   0x008e9df0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008e9df0 @ 0x008e9df0
// Stable ID: aa_008e9df0
// Embedded strings (evidence for future rename):
//   - "i_d_con_2d_wnd_shields.xml"
//   - "i_d_con_2d_btn_portrait.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~237 non-empty decompiler lines.
//  - Control keywords: if×13, do×6, while×6, return×1.
//  - Notable callees: FUN_0079c860×2, FUN_0097ffa0×2, FUN_0040cf90, FUN_007b5dd0, FUN_00856490, FUN_00865870, FUN_008e9df0.
//  - Strings: "i_d_con_2d_wnd_shields.xml"; "i_d_con_2d_btn_portrait.xml".
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

void FUN_008e9df0(void)



{

  int *piVar1;

  void *pvVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int *piVar6;

  int *unaff_EDI;

  float fVar7;

  int iStack_40;

  int local_30;

  uint8_t auStack_24 [4];

  uint32_t /* width from decompiler */ uStack_20;

  uint32_t /* width from decompiler */ uStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  uint32_t /* width from decompiler */ uStack_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009b74bd;

  local_c = ExceptionList;

  if (unaff_EDI[0x130] != 0) {

    ExceptionList = &local_c;

    *(uint8_t *)(unaff_EDI + 0x14f) = 1;

    piVar6 = unaff_EDI + 0x16e;

    local_30 = 4;

    do {

      iStack_40 = *piVar6;

      (**(code **)(*unaff_EDI + 0xbc))();

      pvVar2 = operator_new(0x520);

      puStack_8 = (uint8_t *)0x0;

      if (pvVar2 == (void *)0x0) {

        iVar3 = 0;

      }

      else {

        iVar3 = FUN_00865870();

      }

      puStack_8 = (uint8_t *)0xffffffff;

      *piVar6 = iVar3;

      (**(code **)(*unaff_EDI + 0xa8))();

      (**(code **)(*(int *)*piVar6 + 0x43c))();

      (**(code **)(*(int *)*piVar6 + 0x118))();

      (**(code **)(*(int *)*piVar6 + 0xcc))();

      piVar1 = (int *)*piVar6;

      *(uint8_t *)(piVar1 + 0x13f) = 0;

      piVar1[0x141] = 0;

      (**(code **)(*piVar1 + 0x444))();

      (**(code **)(*piVar1 + 0x34c))();

      piVar6 = piVar6 + 1;

      local_30 = local_30 + -1;

    } while (local_30 != 0);

    iVar3 = unaff_EDI[0x1a] + 1;

    unaff_EDI[0x1a] = iVar3;

    unaff_EDI[0x1d] = (int)(float)-iVar3;

    if (unaff_EDI[0x1c] < iVar3) {

      unaff_EDI[0x1c] = iVar3;

    }

    iStack_40 = 1;

    (**(code **)(*unaff_EDI + 0x3f4))();

    iVar5 = 0;

    piVar6 = unaff_EDI + 0x176;

    iVar3 = 4;

    do {

      (**(code **)(*unaff_EDI + 0xbc))();

      pvVar2 = operator_new(0x520);

      local_c = (void *)0x1;

      if (pvVar2 == (void *)0x0) {

        iVar4 = 0;

      }

      else {

        iVar4 = FUN_00856490();

      }

      local_c = (void *)0xffffffff;

      *piVar6 = iVar4;

      (**(code **)(*unaff_EDI + 0xa8))();

      (**(code **)(*(int *)*piVar6 + 0x28))();

      (**(code **)(*(int *)*piVar6 + 8))();

      iVar4 = *piVar6;

      *(int *)(iVar4 + 0x234) = unaff_EDI[0x157];

      *(int *)(iVar4 + 0x238) = unaff_EDI[0x158];

      *(int *)(iVar4 + 0x23c) = unaff_EDI[0x159];

      *(int *)(*piVar6 + 0x138) = unaff_EDI[0x154];

      iStack_40 = (int)((float)DAT_00d1e81c *

                        (float)((unaff_EDI[0x165] + unaff_EDI[0x167]) * iVar5 + unaff_EDI[0x163]) *

                       DAT_00aaa678);

      (**(code **)(*(int *)*piVar6 + 0x118))();

      (**(code **)(*(int *)*piVar6 + 0x1a0))();

      FUN_0040cf90();

      iVar4 = *piVar6;

      iVar5 = iVar5 + 1;

      piVar6 = piVar6 + 1;

      iVar3 = iVar3 + -1;

      *(uint32_t /* width from decompiler */ *)(iVar4 + 0x488) = 0;

    } while (iVar3 != 0);

    iVar3 = unaff_EDI[0x1a] + 1;

    unaff_EDI[0x1a] = iVar3;

    unaff_EDI[0x1d] = (int)(float)-iVar3;

    if (unaff_EDI[0x1c] < iVar3) {

      unaff_EDI[0x1c] = iVar3;

    }

    (**(code **)(*unaff_EDI + 0x3f4))();

    piVar6 = unaff_EDI + 0x18a;

    do {

      (**(code **)(*unaff_EDI + 0xbc))();

      pvVar2 = operator_new(0x4f8);

      uStack_10 = 2;

      if (pvVar2 == (void *)0x0) {

        iVar3 = 0;

      }

      else {

        iVar3 = FUN_0097ffa0();

      }

      uStack_10 = 0xffffffff;

      piVar6[-8] = iVar3;

      (**(code **)(*unaff_EDI + 0xa8))();

      (**(code **)(*(int *)piVar6[-8] + 0x28))();

      fVar7 = (float)DAT_00d1e818 * (float)(unaff_EDI[0x162] + unaff_EDI[0x15a]) * DAT_00aaa67c;

      (**(code **)(*(int *)piVar6[-8] + 0x118))();

      (**(code **)(*unaff_EDI + 0xbc))(*piVar6);

      pvVar2 = operator_new(0x488);

      uStack_20 = 3;

      if (pvVar2 == (void *)0x0) {

        iVar3 = 0;

      }

      else {

        iVar3 = FUN_007b5dd0(pvVar2,0);

      }

      uStack_20 = 0xffffffff;

      *piVar6 = iVar3;

      (**(code **)(*unaff_EDI + 0xa8))(iVar3);

      (**(code **)(*(int *)*piVar6 + 0x28))("i_d_con_2d_wnd_shields.xml");

      iStack_40 = (int)((float)DAT_00d1e818 * (float)(unaff_EDI[0x162] + unaff_EDI[0x15c]) *

                       DAT_00aaa67c);

      (**(code **)(*(int *)*piVar6 + 0x118))(&iStack_40);

      piVar6 = piVar6 + 1;

    } while ((int)fVar7 != 1);

    iVar3 = unaff_EDI[0x1a] + 1;

    unaff_EDI[0x1a] = iVar3;

    unaff_EDI[0x1d] = (int)(float)-iVar3;

    if (unaff_EDI[0x1c] < iVar3) {

      unaff_EDI[0x1c] = iVar3;

    }

    (**(code **)(*unaff_EDI + 0x3f4))();

    piVar6 = unaff_EDI + 0x186;

    iVar3 = 4;

    do {

      (**(code **)(*unaff_EDI + 0xbc))();

      pvVar2 = operator_new(0x4f8);

      uStack_14 = 4;

      if (pvVar2 == (void *)0x0) {

        iVar5 = 0;

      }

      else {

        iVar5 = FUN_0097ffa0();

      }

      uStack_14 = 0xffffffff;

      *piVar6 = iVar5;

      (**(code **)(*unaff_EDI + 0xa8))();

      (**(code **)(*(int *)*piVar6 + 0x28))();

      (**(code **)(*(int *)*piVar6 + 0x118))(&stack0xffffffcc);

      piVar6 = piVar6 + 1;

      iVar3 = iVar3 + -1;

    } while (iVar3 != 0);

    iVar3 = unaff_EDI[0x1a] + 1;

    unaff_EDI[0x1a] = iVar3;

    unaff_EDI[0x1d] = (int)(float)-iVar3;

    if (unaff_EDI[0x1c] < iVar3) {

      unaff_EDI[0x1c] = iVar3;

    }

    (**(code **)(*unaff_EDI + 0x3f4))();

    iVar3 = 0;

    piVar6 = unaff_EDI + 0x17a;

    iStack_40 = 4;

    do {

      (**(code **)(*unaff_EDI + 0xbc))();

      *piVar6 = 0;

      pvVar2 = operator_new(0x4cc);

      uStack_18 = 5;

      iVar5 = 0;

      if (pvVar2 != (void *)0x0) {

        iVar5 = FUN_0079c860();

      }

      uStack_18 = 0xffffffff;

      *piVar6 = iVar5;

      (**(code **)(*unaff_EDI + 0xa8))();

      (**(code **)(*(int *)*piVar6 + 0x28))("i_d_con_2d_btn_portrait.xml");

      (**(code **)(*(int *)*piVar6 + 0x74))(iVar3 + 0x9c46);

      (**(code **)(*(int *)*piVar6 + 0x120))(&stack0xffffffbc,0,0);

      (**(code **)(*(int *)*piVar6 + 0x120))(&iStack_40,0,0);

      (**(code **)(*(int *)*piVar6 + 0x118))(&stack0xffffffac);

      iVar3 = iVar3 + 1;

      piVar6 = piVar6 + 1;

      iStack_40 = iStack_40 + -1;

    } while (iStack_40 != 0);

    iVar3 = unaff_EDI[0x1a] + 1;

    unaff_EDI[0x1a] = iVar3;

    unaff_EDI[0x1d] = (int)(float)-iVar3;

    if (unaff_EDI[0x1c] < iVar3) {

      unaff_EDI[0x1c] = iVar3;

    }

    (**(code **)(*unaff_EDI + 0x3f4))();

    iVar3 = 0;

    piVar6 = unaff_EDI + 0x17e;

    local_30 = 4;

    do {

      iStack_40 = *piVar6;

      (**(code **)(*unaff_EDI + 0xbc))();

      *piVar6 = 0;

      pvVar2 = operator_new(0x4cc);

      puStack_8 = (uint8_t *)0x6;

      iVar5 = 0;

      if (pvVar2 != (void *)0x0) {

        iVar5 = FUN_0079c860();

      }

      puStack_8 = (uint8_t *)0xffffffff;

      *piVar6 = iVar5;

      (**(code **)(*unaff_EDI + 0xa8))();

      (**(code **)(*(int *)*piVar6 + 0x28))();

      (**(code **)(*(int *)*piVar6 + 0x74))();

      (**(code **)(*(int *)*piVar6 + 0x120))(auStack_24);

      iVar5 = (**(code **)(*(int *)*piVar6 + 0x120))(&iStack_40,0,0);

      iStack_40 = (int)((float)DAT_00d1e81c *

                        (float)(*(int *)(iVar5 + 4) + (unaff_EDI[0x165] + unaff_EDI[0x167]) * iVar3

                               + unaff_EDI[0x163]) * DAT_00aaa678);

      (**(code **)(*(int *)*piVar6 + 0x118))(&stack0xffffffbc);

      (**(code **)(*(int *)*piVar6 + 0xcc))(0);

      iVar3 = iVar3 + 1;

      piVar6 = piVar6 + 1;

      local_30 = local_30 + -1;

      *(uint8_t *)(unaff_EDI + 0x14f) = 0;

    } while (local_30 != 0);

  }

  ExceptionList = local_c;

  return;

}
