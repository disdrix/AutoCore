// READABILITY (auto CF):
//  - Body size: ~126 non-empty decompiler lines.
//  - Control keywords: if×12, return×2, do×1, while×1.
//  - Notable callees: FUN_00402c40, FUN_00411900, FUN_007b5dd0, FUN_00824410, FUN_00895e90, FUN_00896b20.
//  - Strings: "i_d_s_2d_btn_skill_points_current.xml".
//  - Return sites: 2.

// =============================================================================
// Skill_i_d_s_2d_btn_skill_points_current_xml_00896b20
// -----------------------------------------------------------------------------
// Stable ID: aa_00896b20
// Address:   0x00896b20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "i_d_s_2d_btn_skill_points_current.xml"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Skill_i_d_s_2d_btn_skill_points_current_xml_00896b20(int *param_1)



{

  int *piVar1;

  char cVar2;

  int iVar3;

  void *pvVar4;

  int iVar5;

  uint uVar6;

  int *piVar7;

  int unaff_EDI;

  int local_68;

  int iStack_4c;

  int iStack_48;

  int iStack_44;

  uint32_t /* width from decompiler */ uStack_14;

  void *pvStack_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b5dba;

  local_c = ExceptionList;

  if (((DAT_00d1b6d8 != 0) && (param_1[0x130] != 0)) &&

     (iVar5 = *(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0x74 + DAT_00d1b6d8), iVar5 != 0))

  {

    ExceptionList = &local_c;

    *(uint8_t *)(param_1 + 0x146) = 1;

    FUN_00895e90();

    param_1[0x144] = 0;

    local_68 = 0;

    FUN_00402c40();

    piVar7 = param_1 + 0x199;

    do {

      iVar3 = FUN_00411900();

      if (iVar3 == 0) break;

      if ((*(char *)(iVar3 + 0x5f9) != '\x04') && ((uint)*(byte *)(iVar3 + 0x5f8) == param_1[0x147])

         ) {

        uVar6 = *(byte *)(iVar3 + 0x5fb) / 5;

        if (param_1[0x144] < (int)(uVar6 + 1)) {

          param_1[0x144] = uVar6 + 1;

        }

        pvVar4 = operator_new(0x638);

        local_4 = 0;

        if (pvVar4 == (void *)0x0) {

          iVar5 = 0;

        }

        else {

          iVar5 = FUN_00824410();

        }

        local_4 = 0xffffffff;

        *piVar7 = iVar5;

        (**(code **)(*param_1 + 0xa8))();

        (**(code **)(*(int *)*piVar7 + 0x74))();

        iStack_4c = (int)((float)param_1[0x14a] * (float)DAT_00d1e818 * DAT_00aaa67c);

        iStack_48 = (int)((float)param_1[0x14b] * (float)DAT_00d1e81c * DAT_00aaa678);

        (**(code **)(*(int *)*piVar7 + 8))();

        (**(code **)(*(int *)*piVar7 + 0x43c))();

        iVar5 = (param_1[0x14d] + param_1[0x14b]) * (uVar6 - param_1[0x143]) + param_1[0x149];

        iStack_48 = (int)((float)DAT_00d1e818 *

                          (float)(int)((param_1[0x14c] + param_1[0x14a]) *

                                       (*(byte *)(iVar3 + 0x5f9) - 1) + param_1[0x148]) *

                         DAT_00aaa67c);

        iStack_44 = (int)((float)DAT_00d1e81c * (float)iVar5 * DAT_00aaa678);

        (**(code **)(*(int *)*piVar7 + 0x118))();

        piVar1 = (int *)*piVar7;

        piVar1[0x183] = unaff_EDI;

        *(uint8_t *)(piVar1 + 0x13f) = 0;

        (**(code **)(*piVar1 + 0x444))();

        (**(code **)(*piVar1 + 0x34c))();

        pvVar4 = operator_new(0x488);

        uStack_14 = 1;

        if (pvVar4 == (void *)0x0) {

          iVar3 = 0;

        }

        else {

          iVar3 = FUN_007b5dd0(pvVar4);

        }

        uStack_14 = 0xffffffff;

        piVar7[-0x36] = iVar3;

        (**(code **)(*param_1 + 0xa8))();

        (**(code **)(*(int *)piVar7[-0x36] + 0x28))("i_d_s_2d_btn_skill_points_current.xml");

        (**(code **)(*(int *)piVar7[-0x36] + 0x124))(&iStack_4c);

        (**(code **)(*(int *)*piVar7 + 0x120))(&iStack_48,1,0);

        (**(code **)(*(int *)*piVar7 + 0x140))(&iStack_4c,1);

        (**(code **)(*(int *)piVar7[-0x36] + 0x124))(&iStack_4c);

        (**(code **)(*(int *)*piVar7 + 0x120))(&iStack_48,1,0);

        (**(code **)(*(int *)piVar7[-0x36] + 0x118))(&stack0xffffff74);

        if (((int)uVar6 < param_1[0x143]) || (param_1[0x145] <= (int)(uVar6 - param_1[0x143]))) {

          (**(code **)(*(int *)*piVar7 + 4))();

          (**(code **)(*(int *)piVar7[-0x36] + 4))();

        }

        local_68 = local_68 + 1;

        piVar7 = piVar7 + 1;

      }

    } while (local_68 < 0x36);

    *(uint8_t *)(iVar5 + 0x1d) = 0;

    piVar7 = (int *)param_1[0x1d4];

    *(uint8_t *)(param_1 + 0x146) = 0;

    if (piVar7 != (int *)0x0) {

      uVar6 = param_1[0x144] - param_1[0x145] & (param_1[0x144] - param_1[0x145] < 0) - 1;

      param_1[0x1d5] = uVar6;

      if (((int)uVar6 < 1) && (param_1[0x143] == 0)) {

        cVar2 = (**(code **)(*piVar7 + 0xd8))();

        if (cVar2 != '\0') {

          (**(code **)(*(int *)param_1[0x1d4] + 0xd4))();

          (**(code **)(*(int *)param_1[0x1d4] + 0x34c))();

        }

      }

      else {

        cVar2 = (**(code **)(*piVar7 + 0xd8))();

        if (cVar2 == '\0') {

          (**(code **)(*(int *)param_1[0x1d4] + 0xd4))();

          (**(code **)(*(int *)param_1[0x1d4] + 0x34c))();

        }

      }

      if (0 < param_1[0x1d5]) {

        (**(code **)(*(int *)param_1[0x1d4] + 0x460))();

        ExceptionList = pvStack_10;

        return;

      }

      (**(code **)(*(int *)param_1[0x1d4] + 0x460))();

    }

  }

  ExceptionList = local_c;

  return;

}
