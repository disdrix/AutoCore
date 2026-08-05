// READABILITY (auto CF):
//  - Body size: ~103 non-empty decompiler lines.
//  - Control keywords: if×14, return×8, do×2, goto×2, while×2, for×1.
//  - Notable callees: CNDHash_LookupByKey×2, FUN_007a4480×2, FUN_008ec750×2, FUN_00404840, FUN_00418700, FUN_0053fff0.
//  - Strings: "Mission %d includes itself as a pre-req".
//  - Return sites: 8.

// =============================================================================
// Mission_Mission_d_both_has_a_pre_req_of_and_is_a_pre_req
// -----------------------------------------------------------------------------
// Stable ID: aa_008ec750
// Address:   0x008ec750  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "Mission %d both has a pre-req of and is a pre-req of Mission %d"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

bool Mission_Mission_d_both_has_a_pre_req_of_and_is_a_pre_req(uint *param_1,int param_2)



{

  uint uVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint *puVar3;

  char cVar4;

  int iVar5;

  int iVar6;

  void *pvVar7;

  void *pvVar8;

  int *piVar9;

  int iVar10;

  int local_4;

  

  puVar3 = param_1;

  if (param_1 == (uint *)0x0) {

    return false;

  }

  param_1 = (uint *)*param_1;

  iVar6 = *(int *)(param_2 + 4);

  iVar5 = FUN_00418700(iVar6,*(uint32_t /* width from decompiler */ *)(iVar6 + 4),&param_1);

  FUN_00404840(1);

  *(int *)(iVar6 + 4) = iVar5;

  **(int **)(iVar5 + 4) = iVar5;

  if ((DAT_00d1b6d8 != 0) &&

     ((((*(ushort *)((int)puVar3 + 0x92) != 0xffff &&

        (*(ushort *)((int)puVar3 + 0x92) !=

         (ushort)*(byte *)(*(int *)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0xac +

                                            DAT_00d1b6d8) + 0x3c) + 0x531))) ||

       (((ushort)puVar3[0x24] != 0xffff &&

        ((ushort)puVar3[0x24] !=

         (ushort)*(byte *)(*(int *)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0xac +

                                            DAT_00d1b6d8) + 0x3c) + 0x532))))) ||

      (uVar1 = puVar3[0x26],

      iVar6 = (**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8) +

                          0x27c))(), (int)uVar1 < iVar6)))) {

    return false;

  }

  param_1 = puVar3 + 0x27;

  local_4 = 0;

  iVar6 = DAT_00d1b6d8;

  do {

    uVar1 = *param_1;

    if (((((int)uVar1 < -1) && (iVar6 != 0)) &&

        (pvVar8 = *(void **)(iVar6 + 0x538), pvVar8 != (void *)0x0)) &&

       ((pvVar7 = CNDHash_LookupByKey(pvVar8,*puVar3), pvVar7 == (void *)0x0 &&

        (pvVar8 = CNDHash_LookupByKey(pvVar8,-uVar1), pvVar8 != (void *)0x0)))) {

      return false;

    }

    iVar5 = param_2;

    if (-1 < (int)uVar1) {

      if (uVar1 == *puVar3) {

        FUN_007a4480(0,"Mission %d includes itself as a pre-req",uVar1);

        return false;

      }

      for (puVar2 = (uint32_t /* width from decompiler */ *)**(uint32_t /* width from decompiler */ **)(param_2 + 4);

          puVar2 != *(uint32_t /* width from decompiler */ **)(param_2 + 4); puVar2 = (uint32_t /* width from decompiler */ *)*puVar2) {

        if (uVar1 == puVar2[2]) {

          FUN_007a4480(0,"Mission %d both has a pre-req of and is a pre-req of Mission %d",*puVar3,

                       uVar1);

          return false;

        }

      }

      piVar9 = (int *)FUN_0053fff0();

      iVar6 = *(int *)(*(int *)(*(int *)(*piVar9 + 0x10) + (*(uint *)(*piVar9 + 8) & uVar1) * 4) + 4

                      );

      if (iVar6 == 0) {

LAB_008ec8d2:

        iVar10 = 0;

      }

      else {

        do {

          if (uVar1 == *(uint *)(iVar6 + 0x10)) {

            if (iVar6 == 0) goto LAB_008ec8d2;

            iVar10 = *(int *)(iVar6 + 8);

            goto LAB_008ec8d9;

          }

          iVar6 = *(int *)(iVar6 + 0xc);

        } while (iVar6 != 0);

        iVar10 = 0;

      }

LAB_008ec8d9:

      iVar6 = DAT_00d1b6d8;

      if (iVar10 != 0) {

        uVar1 = puVar3[0x49];

        cVar4 = Mission_Mission_d_both_has_a_pre_req_of_and_is_a_pre_req(iVar10,iVar5);

        iVar6 = DAT_00d1b6d8;

        if ((bool)cVar4 == (uVar1 != 0)) {

          if (puVar3[0x48] == 0) {

            return false;

          }

        }

        else if (puVar3[0x48] != 0) {

          return true;

        }

      }

    }

    param_1 = param_1 + 1;

    local_4 = local_4 + 1;

    if (3 < local_4) {

      return puVar3[0x48] == 0;

    }

  } while( true );

}
