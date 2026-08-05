// =============================================================================
// Named_CalleeOf_Client_Input_PollBoundActions_009329c0
// -----------------------------------------------------------------------------
// Stable ID: aa_009329c0
// Callee of Client_Input_PollBoundActions
// Address:   0x009329c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_Input_PollBoundActions: input/binding helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~55 non-empty decompiler lines.
//  - Control keywords: if×6, return×4, do×2, while×2.
//  - Notable callees: FUN_00418700, FUN_00418790, FUN_005149d0, FUN_009329c0.
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Client_Input_PollBoundActions
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

void Named_CalleeOf_Client_Input_PollBoundActions_009329c0(int param_1)



{

  int iVar1;

  char *pcVar2;

  int iVar3;

  int *piVar4;

  int *piVar5;

  int local_8;

  int *local_4;

  

  piVar4 = (int *)**(int **)(param_1 + 0xab8);

  if (piVar4 != *(int **)(param_1 + 0xab8)) {

    do {

      if (*(void **)piVar4[2] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(*(void **)piVar4[2]);

      }

      *(uint32_t /* width from decompiler */ *)piVar4[2] = 0;

      if ((void *)piVar4[2] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete((void *)piVar4[2]);

      }

      piVar4[2] = 0;

      piVar5 = (int *)*piVar4;

      if (piVar4 != *(int **)(param_1 + 0xab8)) {

        *(int **)piVar4[1] = piVar5;

        *(int *)(*piVar4 + 4) = piVar4[1];

                    /* WARNING: Subroutine does not return */

        operator_delete(piVar4);

      }

      piVar4 = piVar5;

    } while (piVar5 != (int *)*(int *)(param_1 + 0xab8));

  }

  iVar1 = *(int *)(*(int *)(param_1 + 0xe04) + 0xe898);

  piVar4 = *(int **)(iVar1 + 0xac);

  piVar5 = *(int **)(iVar1 + 0xb0);

  local_4 = piVar5;

  if (piVar4 != piVar5) {

    do {

      pcVar2 = *(char **)(*piVar4 + 0x78);

      if ((((pcVar2 != (char *)0x0) && (*pcVar2 == '\x01')) &&

          (*(char *)(*(int *)(param_1 + 0xe98) + 0x4f1) == '\0')) &&

         ((*(int *)(pcVar2 + 4) != 0 && (local_8 = FUN_005149d0(0x3f800000), local_8 != 0)))) {

        iVar1 = *(int *)(param_1 + 0xab8);

        iVar3 = FUN_00418700(iVar1,*(uint32_t /* width from decompiler */ *)(iVar1 + 4),&local_8);

        FUN_00418790();

        *(int *)(iVar1 + 4) = iVar3;

        **(int **)(iVar3 + 4) = iVar3;

        piVar5 = local_4;

      }

      piVar4 = piVar4 + 1;

    } while (piVar4 != piVar5);

  }

  *(uint8_t *)(param_1 + 0x1f) = 0;

  return;

}
