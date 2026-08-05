// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_Server_needs_an_update_009306d0
// -----------------------------------------------------------------------------
// Stable ID: aa_009306d0
// Callee of Named_CalleeOf_Named_Server_needs_an_update
// Address:   0x009306d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_Server_needs_an_update: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×6, return×3, do×1, while×1.
//  - Notable callees: FUN_00756be0, FUN_009306d0.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_Server_needs_an_update
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

void Named_CalleeOf_Named_CalleeOf_Named_Server_needs_an_update_009306d0(void)



{

  int iVar1;

  int unaff_EBX;

  int *piVar2;

  int *piVar3;

  

  piVar2 = (int *)**(int **)(unaff_EBX + 0xef4);

  if (piVar2 != *(int **)(unaff_EBX + 0xef4)) {

    do {

      piVar3 = piVar2;

      if ((int *)piVar2[2] != (int *)0x0) {

        iVar1 = *(int *)piVar2[2];

        if (iVar1 != 0) {

          FUN_00756be0(iVar1);

        }

        if (*(uint32_t /* width from decompiler */ **)piVar2[2] != (uint32_t /* width from decompiler */ *)0x0) {

          (**(code **)**(uint32_t /* width from decompiler */ **)piVar2[2])(1);

        }

        *(uint32_t /* width from decompiler */ *)piVar2[2] = 0;

        if ((void *)piVar2[2] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

          operator_delete((void *)piVar2[2]);

        }

        piVar2[2] = 0;

        piVar3 = (int *)*piVar2;

        if (piVar2 != *(int **)(unaff_EBX + 0xef4)) {

          *(int **)piVar2[1] = piVar3;

          *(int *)(*piVar2 + 4) = piVar2[1];

                    /* WARNING: Subroutine does not return */

          operator_delete(piVar2);

        }

      }

      piVar2 = piVar3;

    } while (piVar3 != *(int **)(unaff_EBX + 0xef4));

  }

  return;

}
