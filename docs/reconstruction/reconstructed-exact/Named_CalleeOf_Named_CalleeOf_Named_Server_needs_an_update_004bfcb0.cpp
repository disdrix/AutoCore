// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_Server_needs_an_update_004bfcb0
// -----------------------------------------------------------------------------
// Stable ID: aa_004bfcb0
// Callee of Named_CalleeOf_Named_Server_needs_an_update
// Address:   0x004bfcb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_Server_needs_an_update: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×4, while×2, return×2, do×1.
//  - Notable callees: FUN_004bfcb0.
//  - Return sites: 2.

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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_Server_needs_an_update_004bfcb0(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  void *pvVar2;

  int iVar3;

  int *piVar4;

  int *piVar5;

  

  piVar4 = (int *)(param_1 + 8);

  iVar3 = 9;

  while( true ) {

    piVar5 = *(int **)*piVar4;

    if (piVar5 != (int *)*piVar4) {

      do {

        if ((uint32_t /* width from decompiler */ *)piVar5[2] != (uint32_t /* width from decompiler */ *)0x0) {

          (*(code *)**(uint32_t /* width from decompiler */ **)piVar5[2])(1);

        }

        piVar5 = (int *)*piVar5;

      } while (piVar5 != (int *)*piVar4);

    }

    puVar1 = (uint32_t /* width from decompiler */ *)*piVar4;

    pvVar2 = (void *)*puVar1;

    *puVar1 = puVar1;

    *(int *)(*piVar4 + 4) = *piVar4;

    piVar4[1] = 0;

    if (pvVar2 != (void *)*piVar4) break;

    piVar4 = piVar4 + 3;

    iVar3 = iVar3 + -1;

    if (iVar3 == 0) {

      return;

    }

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(pvVar2);

}
