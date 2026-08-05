// =============================================================================
// FUN_0081f380
// -----------------------------------------------------------------------------
// Stable ID: aa_0081f380
// Address:   0x0081f380  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0081f380 @ 0x0081f380
// Stable ID: aa_0081f380
// Embedded strings (evidence for future rename):
//   - "i_o_controls_2d_btn_cancel.xml"
//   - "Network Settings:"
//   - "Use this box to select your network type"
//   - "Reset Key Bindings:"
//   - "Reset"
//   - "This option restores all of the key bindings to the default settings"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~252 non-empty decompiler lines.
//  - Control keywords: if×26, do×2, while×2, return×1.
//  - Notable callees: FUN_007b5dd0×4, FUN_008176d0×4, FUN_0079c860×3, FUN_00792600, FUN_00816570, FUN_00816860, FUN_00816940, FUN_00816eb0.
//  - Strings: "i_o_controls_2d_btn_cancel.xml"; "Network Settings:"; "Use this box to select your network type"; "Reset Key Bindings:".
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

void __fastcall FUN_0081f380(int *param_1)



{

  uint16_t uVar1;

  int iVar2;

  int iVar3;

  char cVar4;

  void *pvVar5;

  int iVar6;

  void *pvVar7;

  int *piVar8;

  uint32_t /* width from decompiler */ uVar9;

  uint uVar10;

  int *piVar11;

  int *unaff_EBX;

  int *unaff_EBP;

  int unaff_EDI;

  int *piVar12;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009bb841;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_00792600();

  pvVar5 = operator_new(0x488);

  local_4 = 0;

  if (pvVar5 != (void *)0x0) {

    FUN_007b5dd0();

  }

  local_4 = 0xffffffff;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*unaff_EBX + 0x28))();

  (**(code **)(*unaff_EBP + 0xfc))();

  param_1[0x39c] = unaff_EDI;

  iVar6 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar6;

  param_1[0x1d] = (int)(float)-iVar6;

  if (param_1[0x1c] < iVar6) {

    param_1[0x1c] = iVar6;

  }

  (**(code **)(*param_1 + 0x3f4))();

  pvVar5 = operator_new(0x4bc);

  if (pvVar5 != (void *)0x0) {

    FUN_00864f20();

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(s_i_o_controls_2d_wnd_bg_fill_xml_00a78198._0_4_ + 0x28))();

  (**(code **)(iRam3f000000 + 0xfc))();

  param_1[0x39d] = 1;

  iVar6 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar6;

  param_1[0x1d] = (int)(float)-iVar6;

  if (param_1[0x1c] < iVar6) {

    param_1[0x1c] = iVar6;

  }

  (**(code **)(*param_1 + 0x3f4))();

  pvVar5 = operator_new(0x488);

  if (pvVar5 != (void *)0x0) {

    FUN_007b5dd0();

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(s_i_o_controls_2d_wnd_fx_xml_00a7817c._0_4_ + 0x28))();

  (**(code **)(iRam3f000000 + 0xfc))();

  param_1[0x39e] = 1;

  iVar6 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar6;

  param_1[0x1d] = (int)(float)-iVar6;

  if (param_1[0x1c] < iVar6) {

    param_1[0x1c] = iVar6;

  }

  (**(code **)(*param_1 + 0x3f4))();

  pvVar5 = operator_new(0x488);

  if (pvVar5 != (void *)0x0) {

    FUN_007b5dd0();

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(s_i_o_controls_2d_wnd_bg_texture_x_00a78158._0_4_ + 0x28))();

  param_1[0x39f] = 0x3f000000;

  pvVar5 = operator_new(0x488);

  if (pvVar5 == (void *)0x0) {

    pvVar5 = (void *)0x0;

  }

  else {

    pvVar5 = (void *)FUN_007b5dd0();

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(iRam00000001 + 0x28))();

  param_1[0x39f] = 1;

  (**(code **)(*param_1 + 0x404))();

  pvVar7 = operator_new(0x4cc);

  if (pvVar7 == (void *)0x0) {

    piVar8 = (int *)0x0;

  }

  else {

    piVar8 = (int *)FUN_0079c860();

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*piVar8 + 0x28))();

  (**(code **)(*piVar8 + 0x74))();

  (**(code **)(*piVar8 + 0xfc))();

  param_1[0x141] = (int)piVar8;

  pvVar7 = operator_new(0x4cc);

  if (pvVar7 == (void *)0x0) {

    piVar8 = (int *)0x0;

  }

  else {

    piVar8 = (int *)FUN_0079c860();

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*piVar8 + 0x28))();

  (**(code **)(*piVar8 + 0x74))();

  (**(code **)(*piVar8 + 0xfc))();

  param_1[0x3a1] = (int)piVar8;

  pvVar7 = operator_new(0x4cc);

  if (pvVar7 == (void *)0x0) {

    piVar8 = (int *)0x0;

  }

  else {

    piVar8 = (int *)FUN_0079c860();

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*piVar8 + 0x28))("i_o_controls_2d_btn_cancel.xml");

  (**(code **)(*piVar8 + 0x74))(0x9c42);

  iVar6 = 0x3f000000;

  (**(code **)(*piVar8 + 0xfc))(1,0x3f000000);

  param_1[0x3a2] = (int)piVar8;

  pvVar7 = operator_new(0x70c);

  if (pvVar7 == (void *)0x0) {

    piVar8 = (int *)0x0;

  }

  else {

    piVar8 = (int *)FUN_00818a50(pvVar7);

  }

  (**(code **)(*piVar8 + 0x28))(param_1 + 599);

  FUN_008176d0(piVar8);

  param_1[0x3a6] = (int)piVar8;

  if (piVar8[0x180] != 0) {

    (**(code **)(*(int *)piVar8[0x180] + 0x1d8))("Network Settings:",1,1);

    (**(code **)(*(int *)piVar8[0x180] + 0x34c))();

  }

  if (*(int *)(param_1[0x3a6] + 0x600) != 0) {

    (**(code **)(**(int **)(param_1[0x3a6] + 0x600) + 0x308))

              ("Use this box to select your network type");

  }

  FUN_0081e650(param_1);

  pvVar7 = operator_new(0x71c);

  if (pvVar7 == (void *)0x0) {

    piVar8 = (int *)0x0;

  }

  else {

    piVar8 = (int *)FUN_00818d90(pvVar7);

  }

  (**(code **)(*piVar8 + 0x28))(param_1 + 0x153);

  FUN_008176d0(piVar8);

  param_1[0x3a7] = (int)piVar8;

  (**(code **)(*piVar8 + 0x74))(0x9c43);

  iVar2 = param_1[0x3a7];

  if (*(int *)(iVar2 + 0x600) != 0) {

    (**(code **)(**(int **)(iVar2 + 0x600) + 0x1d8))("Reset Key Bindings:",1,1);

    (**(code **)(**(int **)(iVar2 + 0x600) + 0x34c))();

  }

  FUN_00817140(param_1[0x3a7],"Reset",0);

  iVar2 = param_1[0x3a7];

  *(uint32_t /* width from decompiler */ *)(iVar2 + 0x70c) = 0;

  if (*(int **)(iVar2 + 0x708) != (int *)0x0) {

    iVar3 = **(int **)(iVar2 + 0x708);

    uVar9 = FUN_00816eb0(1,1);

    (**(code **)(iVar3 + 0x1d8))(uVar9);

    (**(code **)(**(int **)(iVar2 + 0x708) + 0x34c))();

  }

  if (*(int *)(param_1[0x3a7] + 0x600) != 0) {

    (**(code **)(**(int **)(param_1[0x3a7] + 0x600) + 0x308))

              ("This option restores all of the key bindings to the default settings");

  }

  piVar8 = param_1 + 0x3a8;

  piVar12 = (int *)0x0;

  do {

    if ((byte)piVar12 < 0x78) {

      uVar10 = (uint)piVar12 & 0xff;

      iVar2 = uVar10 * 0x34;

      if (((&DAT_00d1bbee + uVar10 * 0x1a != (uint16_t *)0x0) && ((&DAT_00d1bbf5)[iVar2] != '\0'))

         && ((&DAT_00d1bbf4)[iVar2] == '\0')) {

        pvVar7 = operator_new(0x820);

        if (pvVar7 == (void *)0x0) {

          piVar11 = (int *)0x0;

        }

        else {

          piVar11 = (int *)FUN_008188e0(pvVar7);

        }

        (**(code **)(*piVar11 + 0x28))(param_1 + 0x298);

        FUN_008176d0(piVar11);

        *piVar8 = (int)piVar11;

        if (piVar11[0x180] != 0) {

          (**(code **)(*(int *)piVar11[0x180] + 0x1d8))(&DAT_00d1bbf5 + iVar2,1,1);

          (**(code **)(*(int *)piVar11[0x180] + 0x34c))();

        }

        piVar11 = (int *)*piVar8;

        uVar1 = (&DAT_00d1bc18)[uVar10 * 0x1a];

        *(uint16_t *)(piVar11 + 0x206) = (&DAT_00d1bbee)[uVar10 * 0x1a];

        *(uint16_t *)((int)piVar11 + 0x81a) = uVar1;

        cVar4 = (**(code **)(*piVar11 + 0x3d8))();

        if (cVar4 != '\0') {

          piVar8 = piVar12;

          FUN_00816940();

          piVar12 = piVar8;

        }

        piVar11 = (int *)*piVar8;

        uVar1 = (&DAT_00d1bbf0)[uVar10 * 0x1a];

        *(uint16_t *)((int)piVar11 + 0x81e) = (&DAT_00d1bc1a)[uVar10 * 0x1a];

        *(uint16_t *)(piVar11 + 0x207) = uVar1;

        cVar4 = (**(code **)(*piVar11 + 0x3d8))();

        if (cVar4 != '\0') {

          piVar8 = piVar12;

          FUN_00816860();

          piVar12 = piVar8;

        }

        (**(code **)(*(int *)*piVar8 + 0x74))(iVar6 + 0x9c44);

      }

    }

    piVar12 = (int *)((int)piVar12 + 1);

    piVar8 = piVar8 + 1;

  } while ((int)piVar12 < 0x78);

  iVar6 = 0;

  piVar8 = param_1 + 0x422;

  do {

    pvVar7 = operator_new(0x820);

    if (pvVar7 == (void *)0x0) {

      piVar12 = (int *)0x0;

    }

    else {

      piVar12 = (int *)FUN_00816570(pvVar7,iVar6);

    }

    (**(code **)(*piVar12 + 0x28))(param_1 + 0x298);

    FUN_008176d0(piVar12);

    *piVar8 = (int)piVar12;

    if (piVar12[0x180] != 0) {

      (**(code **)(*(int *)piVar12[0x180] + 0x1d8))

                (*(uint32_t /* width from decompiler */ *)(&stack0xffffff04 + iVar6 * 4),1,1);

      (**(code **)(*(int *)piVar12[0x180] + 0x34c))();

    }

    (**(code **)(*(int *)*piVar8 + 0x74))(iVar6 + 0x9cbf);

    iVar6 = iVar6 + 1;

    piVar8 = piVar8 + 1;

  } while (iVar6 < 0x13);

  FUN_0081e9c0(param_1);

  FUN_00817eb0();

  FUN_00816ee0();

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = pvVar5;

  return;

}
