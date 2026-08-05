// =============================================================================
// Named_CalleeOf_Client_BuildInterfaceOptionsDialog_00816ee0
// -----------------------------------------------------------------------------
// Stable ID: aa_00816ee0
// Callee of Client_BuildInterfaceOptionsDialog
// Address:   0x00816ee0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_BuildInterfaceOptionsDialog: UI/dialog helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~57 non-empty decompiler lines.
//  - Control keywords: if×8, do×3, while×3, return×1.
//  - Notable callees: FUN_00816ee0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Client_BuildInterfaceOptionsDialog
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

void Named_CalleeOf_Client_BuildInterfaceOptionsDialog_00816ee0(void)



{

  int *piVar1;

  char cVar2;

  int *piVar3;

  int iVar4;

  int unaff_ESI;

  

  piVar3 = (int *)**(int **)(unaff_ESI + 0x510);

  iVar4 = 0;

  if (piVar3 != *(int **)(unaff_ESI + 0x510)) {

    do {

      piVar1 = (int *)piVar3[2];

      if (piVar1 != (int *)0x0) {

        if ((iVar4 < *(int *)(unaff_ESI + 0x53c)) ||

           (*(int *)(unaff_ESI + 0x540) + *(int *)(unaff_ESI + 0x53c) <= iVar4)) {

          (**(code **)(*piVar1 + 4))(0);

        }

        else {

          (**(code **)(*piVar1 + 4))(1);

          (**(code **)(*piVar1 + 0x110))(&stack0xfffffff4);

        }

      }

      piVar3 = (int *)*piVar3;

      iVar4 = iVar4 + 1;

    } while (piVar3 != (int *)*(int *)(unaff_ESI + 0x510));

  }

  if ((*(int *)(unaff_ESI + 0x514) != 0) &&

     (piVar3 = *(int **)(unaff_ESI + 0x510), piVar3 != (int *)*piVar3)) {

    do {

      piVar3 = (int *)piVar3[1];

      piVar1 = (int *)piVar3[2];

      if ((piVar1 != (int *)0x0) && (cVar2 = (**(code **)(*piVar1 + 0xd0))(), cVar2 != '\0')) {

        (**(code **)(*piVar1 + 0x94))();

      }

    } while (piVar3 != (int *)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x510));

  }

  piVar3 = (int *)**(int **)(unaff_ESI + 0x51c);

  iVar4 = 0;

  if (piVar3 != *(int **)(unaff_ESI + 0x51c)) {

    do {

      piVar1 = (int *)piVar3[2];

      if (piVar1 != (int *)0x0) {

        if ((iVar4 < *(int *)(unaff_ESI + 0x53c)) ||

           (*(int *)(unaff_ESI + 0x540) + *(int *)(unaff_ESI + 0x53c) <= iVar4)) {

          (**(code **)(*piVar1 + 4))(0);

        }

        else {

          (**(code **)(*piVar1 + 4))(1);

          (**(code **)(*piVar1 + 0x110))(&stack0xfffffff4);

        }

      }

      piVar3 = (int *)*piVar3;

      iVar4 = iVar4 + 1;

    } while (piVar3 != (int *)*(int *)(unaff_ESI + 0x51c));

  }

  return;

}
