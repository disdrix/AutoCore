// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00971ea0
// -----------------------------------------------------------------------------
// Stable ID: aa_00971ea0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x00971ea0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~122 non-empty decompiler lines.
//  - Control keywords: if×10, for×2, return×2, do×1, while×1.
//  - Notable callees: FUN_0043d5e0×2, FUN_0044e8c0×2, CONCAT31, FUN_0040d9c0, FUN_0043c5f0, FUN_0043d570, FUN_0076c330, FUN_009708b0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00971ea0(int param_1,uint32_t /* width from decompiler */ param_2)



{

  char cVar1;

  int *piVar2;

  uint uVar3;

  uint uVar4;

  int iVar5;

  uint32_t /* width from decompiler */ *puVar6;

  int iVar7;

  void *pvVar8;

  uint uVar9;

  float10 fVar10;

  int local_50;

  int iStack_4c;

  int *local_48;

  uint local_3c;

  float fStack_34;

  uint8_t auStack_30 [4];

  void *pvStack_2c;

  void *pvStack_28;

  uint32_t /* width from decompiler */ uStack_24;

  uint8_t local_20 [4];

  int local_1c;

  uint local_18;

  uint local_14;

  int local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b1c9b;

  local_c = ExceptionList;

  iVar5 = *(int *)(param_1 + 0x110);

  ExceptionList = &local_c;

  FUN_0044e8c0(&local_50);

  if (((local_50 == *(int *)(iVar5 + 8)) || (*(int *)(local_50 + 0xc) == 0)) &&

     (iVar5 = *(int *)(param_1 + 0x14), piVar2 = (int *)FUN_0043d5e0(), *piVar2 == iVar5)) {

    local_1c = 0;

    local_18 = 0;

    local_14 = 0;

    local_10 = 0;

    local_4 = 0;

    FUN_0043c5f0(local_20);

    for (uVar4 = local_14; local_3c = uVar4, uVar4 != local_14 + local_10; uVar4 = uVar4 + 1) {

      uVar9 = uVar4 >> 2;

      uVar3 = uVar9;

      if (local_18 <= uVar9) {

        uVar3 = uVar9 - local_18;

      }

      piVar2 = (int *)(**(code **)(**(int **)(*(int *)(local_1c + uVar3 * 4) +

                                             (uVar4 + uVar9 * -4) * 4) + 0xc))(param_2);

      local_48 = piVar2;

      if (piVar2 != (int *)0x0) {

        local_50 = 0;

        cVar1 = FUN_009708b0();

        if (cVar1 != '\0') {

          pvStack_2c = (void *)0x0;

          pvStack_28 = (void *)0x0;

          uStack_24 = 0;

          local_4 = CONCAT31(local_4._1_3_,1);

          iVar5 = uVar9 * -4;

          if (local_18 <= uVar9) {

            uVar9 = uVar9 - local_18;

          }

          FUN_00971b80(auStack_30,piVar2,local_50,

                       *(uint32_t /* width from decompiler */ *)

                        (*(int *)(*(int *)(local_1c + uVar9 * 4) + (local_3c + iVar5) * 4) + 4));

          pvVar8 = pvStack_2c;

          uVar4 = local_14;

          if (pvStack_2c != pvStack_28) {

            do {

              iVar5 = *(int *)(param_1 + 0x110);

              FUN_0044e8c0(&iStack_4c);

              if (((iStack_4c == *(int *)(iVar5 + 8)) || (*(int *)(iStack_4c + 0xc) == 0)) &&

                 (iVar5 = *(int *)(param_1 + 0x14), piVar2 = (int *)FUN_0043d5e0(), uVar3 = uVar4,

                 *piVar2 == iVar5)) {

                for (; uVar3 != local_10 + uVar4; uVar3 = uVar3 + 1) {

                  uVar4 = uVar3 >> 2;

                  iVar5 = uVar4 * -4;

                  if (local_18 <= uVar4) {

                    uVar4 = uVar4 - local_18;

                  }

                  iVar5 = (**(code **)(**(int **)(*(int *)(local_1c + uVar4 * 4) +

                                                 (uVar3 + iVar5) * 4) + 0xc))(pvVar8);

                  if (iVar5 != 0) {

                    FUN_00970bb0(pvVar8);

                  }

                  uVar4 = local_14;

                }

              }

              pvVar8 = (void *)((int)pvVar8 + 4);

              piVar2 = local_48;

            } while (pvVar8 != pvStack_28);

          }

          local_4 = local_4 & 0xffffff00;

          if (pvStack_2c != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

            operator_delete(pvStack_2c);

          }

          pvStack_2c = (void *)0x0;

          pvStack_28 = (void *)0x0;

          uStack_24 = 0;

        }

        fVar10 = (float10)FUN_0076c330();

        fStack_34 = (float)fVar10;

        puVar6 = (uint32_t /* width from decompiler */ *)FUN_0043d570();

        *puVar6 = piVar2;

        puVar6[1] = fStack_34;

        iVar5 = FUN_00970910(param_2);

        iVar7 = (**(code **)(*piVar2 + 0x1c))();

        piVar2 = (int *)(param_1 + 0xe8 + iVar5 * 4);

        *piVar2 = *piVar2 + iVar7;

        piVar2 = (int *)(param_1 + 0xfc + iVar5 * 4);

        *piVar2 = *piVar2 + 1;

        uVar4 = local_3c;

      }

    }

    FUN_0040d9c0();

  }

  ExceptionList = local_c;

  return;

}
