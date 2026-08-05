// =============================================================================
// FUN_00502590
// -----------------------------------------------------------------------------
// Stable ID: aa_00502590
// Address:   0x00502590  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00502590 @ 0x00502590
// Stable ID: aa_00502590
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~173 non-empty decompiler lines.
//  - Control keywords: if×14, while×7, return×7, do×5, for×1.
//  - Notable callees: FUN_0040f2a0×2, CVOGReaction_RemoveInventoryItem, FUN_0040ed60, FUN_0040f400, FUN_0040fb90, FUN_004f5880, FUN_00502590, FUN_005711c0.
//  - Return sites: 7.

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

uint __thiscall FUN_00502590(int param_1,uint *param_2,char param_3)



{

  char cVar1;

  int iVar2;

  int *piVar3;

  int *piVar4;

  byte bVar5;

  int *piVar6;

  uint uVar7;

  int iVar8;

  int *extraout_EAX;

  int iVar9;

  uint32_t /* width from decompiler */ *puVar10;

  uint *puVar11;

  int *unaff_EDI;

  uint8_t local_cc [4];

  uint32_t /* width from decompiler */ *local_c8;

  int local_c4;

  uint8_t local_c0 [4];

  int *local_bc;

  uint32_t /* width from decompiler */ local_b8;

  uint8_t local_b4 [4];

  int local_b0;

  uint32_t /* width from decompiler */ local_ac;

  int local_a8;

  uint32_t /* width from decompiler */ local_a4 [2];

  int local_9c [36];

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a2eff;

  local_c = ExceptionList;

  piVar6 = local_9c;

  for (iVar9 = 0x24; iVar9 != 0; iVar9 = iVar9 + -1) {

    *piVar6 = 0;

    piVar6 = piVar6 + 1;

  }

  puVar11 = (uint *)(param_1 + 0x28c);

  iVar9 = 8;

  ExceptionList = &local_c;

  local_b0 = param_1;

  do {

    piVar6 = (int *)*param_2;

    if (((((int *)*puVar11 != piVar6) && (piVar6 != (int *)0xffffffff)) &&

        (piVar6 = (int *)FUN_004f5880(piVar6), piVar6 != (int *)0x0)) &&

       (*(byte *)((int)piVar6 + 9) < 0x24)) {

      bVar5 = *(byte *)((int)piVar6 + 9);

      local_9c[bVar5] = local_9c[bVar5] + 1;

      piVar6 = local_9c + bVar5;

    }

    puVar11 = puVar11 + 1;

    param_2 = param_2 + 1;

    iVar9 = iVar9 + -1;

  } while (iVar9 != 0);

  if (*(int *)(param_1 + 0x2b0) == 0) {

    ExceptionList = local_c;

    return (uint)piVar6 & 0xffffff00;

  }

  local_c8 = (uint32_t /* width from decompiler */ *)FUN_0040fb90();

  local_c4 = 0;

  local_4 = 0;

  FUN_00572110(0x10,local_cc);

  if (local_c4 != 0) {

    local_bc = (int *)FUN_0040f400();

    *(uint8_t *)((int)local_bc + 0x15) = 1;

    local_bc[1] = (int)local_bc;

    *local_bc = (int)local_bc;

    local_bc[2] = (int)local_bc;

    local_b8 = 0;

    puVar10 = (uint32_t /* width from decompiler */ *)*local_c8;

    local_4._0_1_ = 1;

    if (puVar10 != local_c8) {

      do {

        iVar9 = *(int *)(*(int *)(*(int *)(puVar10[2] + 0xa8) + 0x3c) + 0x3d4);

        iVar2 = local_9c[iVar9];

        if (0 < iVar2) {

          iVar8 = FUN_005711c0(*(uint32_t /* width from decompiler */ *)(*(int *)(puVar10[2] + 0xa8) + 0x34),1);

          if (iVar2 < iVar8) {

            local_9c[iVar9] = 0;

            iVar8 = iVar2;

          }

          else {

            local_9c[iVar9] = iVar2 - iVar8;

          }

          iVar9 = puVar10[2];

          local_a4[0] = *(uint32_t /* width from decompiler */ *)(*(int *)(iVar9 + 0xa8) + 0x34);

          Map_LowerBoundFindByIntKey(local_c0,local_b4,local_a4,unaff_EDI);

          if ((int *)*extraout_EAX == local_bc) {

            local_ac = *(uint32_t /* width from decompiler */ *)(*(int *)(iVar9 + 0xa8) + 0x34);

            local_a8 = iVar8;

            FUN_0040ed60(local_a4,&local_ac);

          }

          else {

            piVar6 = (int *)*extraout_EAX + 4;

            *piVar6 = *piVar6 + iVar8;

          }

        }

        puVar10 = (uint32_t /* width from decompiler */ *)*puVar10;

      } while (puVar10 != local_c8);

    }

    uVar7 = 0;

    do {

      if (0 < local_9c[uVar7]) {

        local_4 = (uint)local_4._1_3_ << 8;

        FUN_0040f2a0(local_b4,*local_bc,local_bc);

                    /* WARNING: Subroutine does not return */

        operator_delete(local_bc);

      }

      bVar5 = (char)uVar7 + 1;

      uVar7 = (uint)bVar5;

    } while (bVar5 < 0x24);

    if ((param_3 != '\0') && (piVar6 = (int *)*local_bc, piVar6 != local_bc)) {

      do {

        CVOGReaction_RemoveInventoryItem(piVar6[3],piVar6[4]);

        if (*(char *)((int)piVar6 + 0x15) == '\0') {

          piVar3 = (int *)piVar6[2];

          if (*(char *)((int)piVar3 + 0x15) == '\0') {

            cVar1 = *(char *)(*piVar3 + 0x15);

            piVar6 = piVar3;

            piVar3 = (int *)*piVar3;

            while (cVar1 == '\0') {

              cVar1 = *(char *)(*piVar3 + 0x15);

              piVar6 = piVar3;

              piVar3 = (int *)*piVar3;

            }

          }

          else {

            cVar1 = *(char *)(piVar6[1] + 0x15);

            piVar4 = (int *)piVar6[1];

            piVar3 = piVar6;

            while ((piVar6 = piVar4, cVar1 == '\0' && (piVar3 == (int *)piVar6[2]))) {

              cVar1 = *(char *)(piVar6[1] + 0x15);

              piVar4 = (int *)piVar6[1];

              piVar3 = piVar6;

            }

          }

        }

      } while (piVar6 != local_bc);

    }

    local_4 = (uint)local_4._1_3_ << 8;

    FUN_0040f2a0(local_b4,*local_bc,local_bc);

                    /* WARNING: Subroutine does not return */

    operator_delete(local_bc);

  }

  uVar7 = 0;

  do {

    if (0 < local_9c[uVar7]) {

      puVar10 = (uint32_t /* width from decompiler */ *)*local_c8;

      *local_c8 = local_c8;

      local_c8[1] = local_c8;

      local_c4 = 0;

      if (puVar10 == local_c8) {

                    /* WARNING: Subroutine does not return */

        operator_delete(local_c8);

      }

                    /* WARNING: Subroutine does not return */

      operator_delete(puVar10);

    }

    bVar5 = (char)uVar7 + 1;

    uVar7 = (uint)bVar5;

  } while (bVar5 < 0x24);

  puVar10 = (uint32_t /* width from decompiler */ *)*local_c8;

  *local_c8 = local_c8;

  local_c8[1] = local_c8;

  local_c4 = 0;

  if (puVar10 == local_c8) {

                    /* WARNING: Subroutine does not return */

    operator_delete(local_c8);

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(puVar10);

}
