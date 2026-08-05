// =============================================================================
// Named_CalleeOf_CVOGHBAIDriver_DoLogic_00638cd0
// -----------------------------------------------------------------------------
// Stable ID: aa_00638cd0
// Callee of CVOGHBAIDriver_DoLogic
// Address:   0x00638cd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGHBAIDriver_DoLogic: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~83 non-empty decompiler lines.
//  - Control keywords: if×10, return×2, while×1, goto×1.
//  - Notable callees: FUN_004ea350, FUN_00638cd0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of CVOGHBAIDriver_DoLogic
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

void __thiscall Named_CalleeOf_CVOGHBAIDriver_DoLogic_00638cd0(int param_1,uint32_t /* width from decompiler */ param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  int *piVar3;

  int *piVar4;

  uint32_t /* width from decompiler */ uVar5;

  int iVar6;

  int iVar7;

  int *piVar8;

  uint uVar9;

  bool bVar10;

  uint8_t auStack_1c [4];

  void *pvStack_18;

  int iStack_14;

  uint32_t /* width from decompiler */ uStack_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009a8e3a;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  piVar4 = (int *)(**(code **)(**(int **)(param_1 + 0x18) + 0x214))();

  if (*(int *)(*(int *)(piVar4[1] + 4) + 0xa4 + (int)piVar4) != 0) {

    pvStack_18 = (void *)0x0;

    iStack_14 = 0;

    uStack_10 = 0;

    uVar1 = *(uint32_t /* width from decompiler */ *)(*(int *)(piVar4[1] + 4) + 0xa8 + (int)piVar4);

    uStack_4 = 0;

    uVar5 = (**(code **)(*(int *)((int)piVar4 + *(int *)(piVar4[1] + 4) + 4) + 0x1a0))

                      (param_2,auStack_1c,0,1);

    FUN_004ea350(uVar1,uVar5);

    uVar9 = 0;

    while( true ) {

      iVar7 = 0;

      if (pvStack_18 == (void *)0x0) break;

      if ((uint)(iStack_14 - (int)pvStack_18 >> 2) <= uVar9) {

                    /* WARNING: Subroutine does not return */

        operator_delete(pvStack_18);

      }

      iVar2 = *(int *)((int)pvStack_18 + uVar9 * 4);

      iVar6 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2) + 0x1d8))();

      if (iVar6 != 0) {

        iVar7 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2) + 0x1d8))();

        iVar7 = *(int *)(iVar7 + 600);

      }

      iVar6 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2) + 0x1d4))();

      if (iVar6 != 0) {

        iVar7 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2) + 0x1d4))();

        iVar7 = *(int *)(iVar7 + 0x280);

      }

      if (iVar7 == 0) {

        iVar7 = *(int *)(*(int *)(iVar2 + 4) + 4);

        iVar6 = (**(code **)(*(int *)(*(int *)(piVar4[1] + 4) + 4 + (int)piVar4) + 0x28c))();

        iVar7 = (**(code **)(*(int *)(iVar7 + 4 + iVar2) + 0x28c))();

        bVar10 = iVar7 == iVar6;

      }

      else {

        bVar10 = iVar7 == piVar4[0x96];

      }

      if (bVar10) {

        piVar8 = (int *)(**(code **)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2) + 0x214

                                    ))();

        if ((piVar8 != (int *)0x0) && (piVar8 != piVar4)) {

          piVar3 = *(int **)(*(int *)(piVar8[1] + 4) + 0xa4 + (int)piVar8);

          if (piVar3 != (int *)0x0) {

            iVar7 = (**(code **)(*piVar3 + 0x210))(0);

            if (iVar7 != 0) goto LAB_00638e8f;

          }

          iVar7 = *(int *)(*(int *)(piVar4[1] + 4) + 0xa4 + (int)piVar4);

          (**(code **)(*piVar8 + 0x88))

                    (10,*(uint32_t /* width from decompiler */ *)(iVar7 + 0x160),*(uint32_t /* width from decompiler */ *)(iVar7 + 0x164),

                     *(uint32_t /* width from decompiler */ *)(iVar7 + 0x168),*(uint32_t /* width from decompiler */ *)(iVar7 + 0x16c));

        }

      }

LAB_00638e8f:

      uVar9 = uVar9 + 1;

    }

  }

  ExceptionList = pvStack_c;

  return;

}
