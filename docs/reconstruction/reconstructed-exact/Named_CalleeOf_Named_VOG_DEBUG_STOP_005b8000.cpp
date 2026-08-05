// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_005b8000
// -----------------------------------------------------------------------------
// Stable ID: aa_005b8000
// Callee of Named_VOG_DEBUG_STOP
// Address:   0x005b8000  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~68 non-empty decompiler lines.
//  - Control keywords: if×7, return×7, for×1, do×1, while×1.
//  - Notable callees: FUN_004be2a0, FUN_005b8000.
//  - Return sites: 7.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP
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

void __fastcall Named_CalleeOf_Named_VOG_DEBUG_STOP_005b8000(int param_1)



{

  void *pvVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  void *pvVar4;

  int *piVar5;

  int *piVar6;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  pvVar4 = ExceptionList;

  puStack_8 = &LAB_009a6b0a;

  local_c = ExceptionList;

  pvVar1 = *(void **)(param_1 + 0x24);

  local_4 = 1;

  if (pvVar1 != (void *)0x0) {

    ExceptionList = &local_c;

    FUN_004be2a0();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  piVar5 = *(int **)(param_1 + 0x14);

  ExceptionList = &local_c;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = 0;

  for (; piVar5 != *(int **)(param_1 + 0x18); piVar5 = piVar5 + 1) {

    piVar6 = (int *)**(int **)(*piVar5 + 8);

    if (piVar6 != *(int **)(*piVar5 + 8)) {

      do {

        if ((void *)piVar6[2] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

          operator_delete((void *)piVar6[2]);

        }

        piVar6 = (int *)*piVar6;

      } while (piVar6 != (int *)*(int *)(*piVar5 + 8));

    }

    iVar2 = *piVar5;

    if (iVar2 != 0) {

      puVar3 = *(uint32_t /* width from decompiler */ **)(iVar2 + 8);

      pvVar1 = (void *)*puVar3;

      *puVar3 = puVar3;

      *(int *)(*(int *)(iVar2 + 8) + 4) = *(int *)(iVar2 + 8);

      *(uint32_t /* width from decompiler */ *)(iVar2 + 0xc) = 0;

      if (pvVar1 != *(void **)(iVar2 + 8)) {

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar1);

      }

                    /* WARNING: Subroutine does not return */

      operator_delete(*(void **)(iVar2 + 8));

    }

  }

  if (*(void **)(param_1 + 0x14) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 0x14));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = 0;

  if (*(void **)(param_1 + 4) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 4));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

  ExceptionList = pvVar4;

  return;

}
