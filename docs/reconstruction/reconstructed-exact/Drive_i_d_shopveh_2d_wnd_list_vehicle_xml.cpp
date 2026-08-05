// READABILITY (auto CF):
//  - Body size: ~115 non-empty decompiler lines.
//  - Control keywords: if×6, do×1, while×1, return×1.
//  - Notable callees: FUN_0078bde0, FUN_008345c0, FUN_0083aa50, FUN_0083ac90, FUN_0083aff0.
//  - Strings: "i_d_shopveh_2d_wnd_list_vehicle.xml".
//  - Return sites: 1.

// =============================================================================
// Drive_i_d_shopveh_2d_wnd_list_vehicle_xml
// -----------------------------------------------------------------------------
// Stable ID: aa_0083aff0
// Address:   0x0083aff0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "i_d_shopveh_2d_wnd_list_vehicle.xml"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Drive_i_d_shopveh_2d_wnd_list_vehicle_xml(int *param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  float fVar4;

  char cVar5;

  int *piVar6;

  int iVar7;

  int iVar8;

  int *piVar9;

  int *piVar10;

  int *piStack_90;

  int iStack_8c;

  uint8_t auStack_88 [4];

  uint8_t auStack_84 [4];

  void *pvStack_80;

  int aiStack_7c [17];

  float fStack_38;

  float fStack_34;

  float fStack_30;

  float fStack_2c;

  void *pvStack_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ uStack_c;

  

  uStack_c = 0xffffffff;

  puStack_10 = &LAB_009b45dd;

  pvStack_14 = ExceptionList;

  ExceptionList = &pvStack_14;

  cVar5 = (**(code **)(*param_1 + 0x3d8))();

  if (((cVar5 != '\0') && (param_1[0x142] != 0)) &&

     (aiStack_7c[0] = param_1[0x142] + 0x2c, aiStack_7c[0] != 0)) {

    piStack_90 = param_1 + 0x143;

    iStack_8c = 0;

    do {

      iVar8 = iStack_8c;

      if (*piStack_90 == 0) {

        pvStack_80 = operator_new(0x5f0);

        uStack_c = 0;

        if (pvStack_80 == (void *)0x0) {

          piVar6 = (int *)0x0;

        }

        else {

          piVar6 = (int *)FUN_008345c0(pvStack_80,0);

        }

        uStack_c = 0xffffffff;

        piVar9 = piVar6;

        (**(code **)(*param_1 + 0xa8))();

        (**(code **)(*piVar6 + 0x28))("i_d_shopveh_2d_wnd_list_vehicle.xml");

        (**(code **)(*piVar6 + 0x24))(1);

        *(uint8_t *)(piVar6 + 0x36) = 1;

        iVar7 = (**(code **)(*piVar6 + 0x1a8))();

        *(uint8_t *)(iVar7 + 0x78) = 0;

        piVar6[0x122] = 1;

        *(uint8_t *)(piVar6 + 0x174) = 0;

        if ((iVar8 == 0) || (iVar8 == 4)) {

          (**(code **)(*piVar6 + 0xcc))(0);

        }

        else {

          (**(code **)(*piVar6 + 0xcc))(1);

        }

        fVar4 = g_flOne;

        fStack_38 = g_flOne;

        piVar6[0x12e] = (int)g_flOne;

        fStack_34 = fVar4;

        piVar6[0x12f] = (int)fVar4;

        fStack_30 = fVar4;

        piVar6[0x130] = (int)fVar4;

        fStack_2c = fVar4;

        piVar6[0x131] = (int)fVar4;

        FUN_0078bde0();

        piVar6[0x132] = (int)fVar4;

        piVar6[0x133] = (int)fVar4;

        piVar6[0x134] = (int)fStack_30;

        piVar6[0x135] = (int)fStack_2c;

        (**(code **)(*piVar6 + 0x74))(0xffffffff);

        *piVar9 = (int)piVar6;

        (**(code **)(*piVar6 + 0x124))(auStack_84);

        (**(code **)(*piVar6 + 0x124))(&pvStack_80);

        (**(code **)(*piVar6 + 0x140))(aiStack_7c,1);

        (**(code **)(*piVar6 + 0x110))(&stack0xffffff64);

        piVar10 = (int *)0x1;

        iVar7 = (**(code **)(*piVar6 + 0x120))(&pvStack_80,1,0);

        iVar8 = (**(code **)(*param_1 + 0x140))(auStack_84,1);

        iVar8 = *(int *)(iVar8 + 4);

        iVar7 = *(int *)(iVar7 + 4);

        (**(code **)(*piVar6 + 0x120))(auStack_84,1,0);

        piVar9 = (int *)(**(code **)(*param_1 + 0x140))(auStack_88,1);

        iVar1 = *piVar9;

        iVar2 = *piVar10;

        (**(code **)(*piVar6 + 0x120))(auStack_88,1,0);

        piVar9 = (int *)(**(code **)(*piVar6 + 0x120))(&iStack_8c,1,0);

        iVar3 = *piVar9;

        piVar6[0x66] = iVar1 - iVar2;

        piVar6[100] = -iVar3;

        piVar6[0x65] = (int)pvStack_80;

        piVar6[0x67] = iVar8 - iVar7;

      }

      piStack_90 = piStack_90 + 1;

      iStack_8c = iStack_8c + 1;

    } while (iStack_8c < 5);

    if (param_1[0x13f] != *(int *)(aiStack_7c[0] + 0x24)) {

      param_1[0x13f] = *(int *)(aiStack_7c[0] + 0x24);

      FUN_0083aa50();

      piVar6 = (int *)param_1[0xac];

      if (piVar6 != (int *)0x0) {

        FUN_0083ac90(param_1);

        piVar6[0x157] = *(int *)(param_1[0x142] + 0x50);

        (**(code **)(*piVar6 + 0x460))();

      }

    }

  }

  ExceptionList = pvStack_14;

  return;

}
