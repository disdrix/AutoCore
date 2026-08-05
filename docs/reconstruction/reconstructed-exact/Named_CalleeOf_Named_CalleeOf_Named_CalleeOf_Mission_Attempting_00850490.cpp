// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_Attempting_00850490
// -----------------------------------------------------------------------------
// Stable ID: aa_00850490
// Callee of Named_CalleeOf_Named_CalleeOf_Mission_Attempting_to_open_null_d
// Address:   0x00850490  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Mission_Attempting_to_open_null_d: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~134 non-empty decompiler lines.
//  - Control keywords: if×13, return×2, do×2, while×2, goto×1.
//  - Notable callees: block×4, FUN_0096f0e0×2, ROUND×2, FUN_0040ead0, FUN_00850490, FUN_0096be60, FUN_0096efd0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Mission_Attempting_to_open_null_d
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

/* WARNING: Removing unreachable block (ram,0x00850619) */

/* WARNING: Removing unreachable block (ram,0x0085066b) */

/* WARNING: Removing unreachable block (ram,0x00850620) */

/* WARNING: Removing unreachable block (ram,0x00850672) */



void __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_Attempting_00850490(int *param_1)



{

  void *pvVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  int *piVar5;

  int *piVar6;

  uint32_t /* width from decompiler */ uVar7;

  uint uVar8;

  uint8_t *puVar9;

  uint8_t *puVar10;

  int iVar11;

  uint32_t /* width from decompiler */ uVar12;

  uint32_t /* width from decompiler */ uVar13;

  int iStack_28;

  int iStack_20;

  uint32_t /* width from decompiler */ *local_14;

  void *pvStack_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b0fa2;

  pvStack_c = ExceptionList;

  pvVar1 = (void *)param_1[0x167];

  if (pvVar1 != (void *)0x0) {

    ExceptionList = &pvStack_c;

    FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  ExceptionList = &pvStack_c;

  param_1[0x167] = 0;

  local_14 = operator_new(4);

  if (local_14 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar3 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    *local_14 = 0;

    puVar3 = local_14;

  }

  local_4 = 0xffffffff;

  param_1[0x167] = (int)puVar3;

  puVar3 = *(uint32_t /* width from decompiler */ **)(*(int *)(DAT_00d1b644 + 0xe4f8) + 0x10);

  pvVar1 = *(void **)(*(int *)(DAT_00d1b644 + 0xe4f8) + 0x14);

  iVar4 = (**(code **)(*param_1 + 700))();

  if (iVar4 != 0) {

    piVar5 = (int *)(**(code **)(*param_1 + 700))();

    iVar4 = (**(code **)(*param_1 + 0x2dc))(*(uint32_t /* width from decompiler */ *)(*piVar5 + 0x24));

    if (iVar4 != 0) {

      piVar5 = (int *)(**(code **)(*param_1 + 700))();

      piVar5 = *(int **)(*piVar5 + 0x10);

      piVar6 = (int *)(**(code **)(*param_1 + 700))();

      iVar4 = *piVar6;

      uVar13 = 1;

      uVar12 = 1;

      uVar7 = (**(code **)(*piVar5 + 0x34))(piVar5,1,1,0);

      FUN_0096f0e0(0x15,iVar4 + 0x1c,uVar7,piVar5,uVar12,uVar13);

      (**(code **)(*param_1 + 700))();

      goto LAB_0085059c;

    }

  }

  local_14 = puVar3;

  pvStack_10 = pvVar1;

  FUN_0096f0e0(0x15,&local_14,1,1,1,0);

LAB_0085059c:

  iVar4 = (**(code **)(*param_1 + 700))();

  if (iVar4 == 0) {

    piVar5 = (int *)param_1[0x167];

  }

  else {

    piVar5 = (int *)(**(code **)(*param_1 + 700))();

  }

  (**(code **)(**(int **)(*piVar5 + 0x10) + 0x34))(*(int **)(*piVar5 + 0x10));

  if ((*(int *)param_1[0x167] != 0) &&

     (iVar4 = FUN_0096be60(0,0,0,(*(uint *)(*(int *)param_1[0x167] + 0x2c) & 0x80) != 0), iVar4 != 0

     )) {

    iVar2 = *(int *)param_1[0x167];

    iStack_20 = (int)(longlong)ROUND((float10)*(int *)(iVar2 + 0x1c) / (float10)1);

    iStack_28 = (int)(longlong)ROUND((float10)*(int *)(iVar2 + 0x20) / (float10)1);

    iVar11 = *(int *)param_1[0x167];

    if (iVar11 == 0) {

      iVar11 = 0;

    }

    else {

      iVar11 = *(int *)(iVar11 + 0x40);

    }

    uVar8 = FUN_0040ead0(*(uint32_t /* width from decompiler */ *)(iVar2 + 0x24));

    if (0 < iStack_20) {

      puVar10 = (uint8_t *)(iVar4 + 1);

      do {

        puVar9 = puVar10;

        iVar4 = iStack_28;

        if (0 < iStack_28) {

          do {

            puVar9[1] = 0;

            *puVar9 = 0;

            puVar9[-1] = 0;

            puVar9[2] = 0xff;

            iVar4 = iVar4 + -1;

            puVar9 = puVar9 + iVar11;

          } while (iVar4 != 0);

        }

        puVar10 = puVar10 + (uVar8 >> 3);

        iStack_20 = iStack_20 + -1;

      } while (iStack_20 != 0);

    }

  }

  iVar4 = *(int *)param_1[0x167];

  if (iVar4 != 0) {

    uVar8 = *(uint *)(iVar4 + 0x2c) & 0xf;

    if (uVar8 == 1) {

      (**(code **)(**(int **)(iVar4 + 0x10) + 0x50))(*(int **)(iVar4 + 0x10),0);

    }

    else if (uVar8 == 2) {

      (**(code **)(**(int **)(iVar4 + 0x10) + 0x50))

                (*(int **)(iVar4 + 0x10),*(uint32_t /* width from decompiler */ *)(iVar4 + 0x3c),0);

    }

    else if (uVar8 == 4) {

      (**(code **)(**(int **)(iVar4 + 0x10) + 0x50))(*(int **)(iVar4 + 0x10),0);

    }

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x38) = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x3c) = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x40) = 0;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x44) = 0;

  }

  ExceptionList = pvStack_10;

  return;

}
