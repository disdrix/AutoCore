// =============================================================================
// UI_qb_btn_slot_off
// -----------------------------------------------------------------------------
// Stable ID: aa_008e3cd0
// Address:   0x008e3cd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for UI_qb_btn_slot_off @ 0x008e3cd0
// Stable ID: aa_008e3cd0
// Embedded strings (evidence for future rename):
//   - "i_d_qb_2d_btn_slot_off.dds"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~87 non-empty decompiler lines.
//  - Control keywords: if×6, do×3, while×3, return×1.
//  - Notable callees: FUN_005711c0×2, FUN_0040ed60, FUN_008e3bd0, UI_qb_btn_slot_off, Map_LowerBoundFindByIntKey.
//  - Strings: "i_d_qb_2d_btn_slot_off.dds".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_d_qb_2d_btn_slot_off.dds"
 * Domain alias of FUN_008e3cd0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall UI_qb_btn_slot_off(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  char cVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int in_EAX;

  int iVar4;

  char *pcVar5;

  int *extraout_EAX;

  int iVar6;

  char *pcVar7;

  int *unaff_EDI;

  uint32_t /* width from decompiler */ *puVar8;

  int local_120;

  int iStack_11c;

  uint32_t /* width from decompiler */ auStack_118 [2];

  uint32_t /* width from decompiler */ uStack_110;

  uint32_t /* width from decompiler */ uStack_10c;

  uint8_t auStack_108 [3];

  uint32_t /* width from decompiler */ uStack_105;

  uint8_t auStack_fe [254];

  

  param_1 = param_1 - (int)param_2;

  local_120 = 5;

  do {

    if (*(int *)(param_1 + (int)param_2) == 0) {

      (**(code **)(*(int *)*param_2 + 4))(0);

    }

    else {

      iVar4 = (**(code **)(*(int *)*param_2 + 700))();

      if ((iVar4 == 0) || (*(char *)(in_EAX + 0x7e3) != '\0')) {

        pcVar5 = (char *)(**(code **)(**(int **)(param_1 + (int)param_2) + 0x160))();

        pcVar7 = (char *)((int)&uStack_105 + 1);

        do {

          cVar1 = *pcVar5;

          *pcVar7 = cVar1;

          pcVar5 = pcVar5 + 1;

          pcVar7 = pcVar7 + 1;

        } while (cVar1 != '\0');

        puVar3 = &uStack_105;

        do {

          puVar8 = puVar3;

          puVar3 = (uint32_t /* width from decompiler */ *)((int)puVar8 + 1);

        } while (*(char *)((int)puVar8 + 1) != '\0');

        *(uint32_t /* width from decompiler */ *)((int)puVar8 + 1) = DAT_00a2c534;

        piVar2 = (int *)*param_2;

        *(uint16_t *)((int)puVar8 + 5) = DAT_00a2c538;

        *(uint8_t *)((int)puVar8 + 7) = DAT_00a2c53a;

        iVar4 = (**(code **)(*piVar2 + 0x50))((int)&uStack_105 + 1,1,0);

        if (iVar4 < 0) {

          (**(code **)(*(int *)*param_2 + 0x50))("i_d_qb_2d_btn_slot_off.dds",1,0);

        }

        (**(code **)(*(int *)*param_2 + 0x2c4))();

      }

      auStack_118[0] = *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + (int)param_2) + 0xa8) + 0x34);

      iStack_11c = 0;

      Map_LowerBoundFindByIntKey((void *)(in_EAX + 0x7e8),auStack_108,auStack_118,unaff_EDI);

      iVar4 = *extraout_EAX;

      *(int *)(in_EAX + 0x800) = iVar4;

      if (iVar4 == *(int *)(in_EAX + 0x7ec)) {

        uStack_110 = *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + (int)param_2) + 0xa8) + 0x34);

        uStack_10c = 1;

        FUN_0040ed60(auStack_118,&uStack_110);

      }

      else {

        iStack_11c = *(int *)(iVar4 + 0x10);

        *(int *)(iVar4 + 0x10) = *(int *)(iVar4 + 0x10) + 1;

      }

      FUN_008e3bd0();

      iVar4 = FUN_005711c0(*(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + (int)param_2) + 0xa8) + 0x34)

                           ,0);

      if (*(char *)(DAT_00d1b644 + 0xf5) != '\0') {

        iVar6 = FUN_005711c0(*(uint32_t /* width from decompiler */ *)

                              (*(int *)(*(int *)(param_1 + (int)param_2) + 0xa8) + 0x34),0);

        iVar4 = iVar4 + iVar6;

      }

      if (iVar4 <= iStack_11c) {

        *(uint8_t *)(in_EAX + 0x7d8) = 0;

      }

      (**(code **)(*(int *)*param_2 + 0xcc))(1);

      (**(code **)(*(int *)*param_2 + 0x158))(0,&stack0xfffffecc);

      (**(code **)(*(int *)*param_2 + 0x34c))();

    }

    param_2 = param_2 + 1;

    local_120 = local_120 + -1;

  } while (local_120 != 0);

  return;

}
