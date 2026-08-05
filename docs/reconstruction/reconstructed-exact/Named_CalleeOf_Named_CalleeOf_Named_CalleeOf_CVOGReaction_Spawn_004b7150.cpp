// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGReaction_Spawn_004b7150
// -----------------------------------------------------------------------------
// Stable ID: aa_004b7150
// Callee of Named_CalleeOf_Named_CalleeOf_CVOGReaction_SpawnObject
// Address:   0x004b7150  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_CVOGReaction_SpawnObject: spawn/transfer helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~80 non-empty decompiler lines.
//  - Control keywords: if×10, return×5, do×4, while×4.
//  - Notable callees: FUN_00498a90, FUN_00498ab0, FUN_004b6980, FUN_004b6e00, FUN_004b7150, FUN_0058e300, FUN_00590f00, FUN_007203b0.
//  - Return sites: 5.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_CVOGReaction_SpawnObject
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGReaction_Spawn_004b7150(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  void *pvVar2;

  int iVar3;

  int *piVar4;

  uint32_t /* width from decompiler */ uVar5;

  

  if (*(int *)(param_1 + 0x3c) != 0) {

    FUN_004b6980();

  }

  if ((((*(int **)(param_1 + 0x10) != (int *)0x0) &&

       (iVar3 = (**(code **)(**(int **)(param_1 + 0x10) + 0x1cc))(), iVar3 != 0)) &&

      (iVar3 = *(int *)(iVar3 + 8), iVar3 != 0)) &&

     (piVar4 = (int *)**(int **)(param_1 + 0x204), piVar4 != *(int **)(param_1 + 0x204))) {

    do {

      if ((*(byte *)(piVar4[2] + 0x90e) & 0x80) != 0) {

        FUN_0058e300(0,iVar3);

      }

      piVar4 = (int *)*piVar4;

    } while (piVar4 != (int *)*(int *)(param_1 + 0x204));

  }

  piVar4 = (int *)**(int **)(param_1 + 0x204);

  if (piVar4 != *(int **)(param_1 + 0x204)) {

    do {

      *(byte *)(piVar4[2] + 0x90e) = *(byte *)(piVar4[2] + 0x90e) | 1;

      iVar3 = piVar4[2];

      FUN_00590f00(*(uint32_t /* width from decompiler */ *)(param_1 + 0x2c),*(uint32_t /* width from decompiler */ *)(param_1 + 0x10));

      *(uint32_t /* width from decompiler */ *)(iVar3 + 0x14) = 0;

      piVar4 = (int *)*piVar4;

    } while (piVar4 != (int *)*(int *)(param_1 + 0x204));

  }

  FUN_004b6e00(0);

  piVar4 = (int *)**(int **)(param_1 + 0x1ec);

  if (piVar4 != *(int **)(param_1 + 0x1ec)) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)piVar4[2]);

  }

  puVar1 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x1ec);

  pvVar2 = (void *)*puVar1;

  *puVar1 = puVar1;

  *(int *)(*(int *)(param_1 + 0x1ec) + 4) = *(int *)(param_1 + 0x1ec);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1f0) = 0;

  if (pvVar2 != *(void **)(param_1 + 0x1ec)) {

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar2);

  }

  if ((*(int *)(param_1 + 0x1fc) != 0) &&

     (piVar4 = (int *)**(int **)(param_1 + 0x1f8), piVar4 != *(int **)(param_1 + 0x1f8))) {

    do {

      iVar3 = piVar4[2];

      uVar5 = 1;

      FUN_00720d40(iVar3,1);

      FUN_007203b0(iVar3,uVar5);

      piVar4 = (int *)*piVar4;

    } while (piVar4 != (int *)*(int *)(param_1 + 0x1f8));

  }

  piVar4 = (int *)**(int **)(param_1 + 0x1f8);

  if (piVar4 == *(int **)(param_1 + 0x1f8)) {

    puVar1 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x1f8);

    pvVar2 = (void *)*puVar1;

    *puVar1 = puVar1;

    *(int *)(*(int *)(param_1 + 0x1f8) + 4) = *(int *)(param_1 + 0x1f8);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x1fc) = 0;

    if (pvVar2 == *(void **)(param_1 + 0x1f8)) {

      piVar4 = (int *)**(int **)(param_1 + 0x21c);

      if (piVar4 != *(int **)(param_1 + 0x21c)) {

        do {

          FUN_00498a90();

          FUN_00498ab0(0);

          piVar4 = (int *)*piVar4;

        } while (piVar4 != (int *)*(int *)(param_1 + 0x21c));

      }

      return;

    }

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar2);

  }

                    /* WARNING: Subroutine does not return */

  operator_delete((void *)piVar4[2]);

}
