// =============================================================================
// Named_CalleeOf_Client_Input_PollBoundActions_007fca10
// -----------------------------------------------------------------------------
// Stable ID: aa_007fca10
// Callee of Client_Input_PollBoundActions (+2 other named callers)
// Address:   0x007fca10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_Input_PollBoundActions: input/binding helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Client_Input_PollBoundActions (+2 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~48 non-empty decompiler lines.
//  - Control keywords: if×8, return×2, do×1, goto×1, while×1.
//  - Notable callees: FUN_007fca10.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Client_Input_PollBoundActions (+2 other named callers)
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

void Named_CalleeOf_Client_Input_PollBoundActions_007fca10(void)



{

  int *piVar1;

  char cVar2;

  int *in_EAX;

  int unaff_EBX;

  int *piVar3;

  int iVar4;

  uint8_t uVar5;

  

  if ((*(int *)(unaff_EBX + 0xf40) != 0) && (in_EAX != (int *)0x0)) {

    cVar2 = (**(code **)(*in_EAX + 0x3d8))();

    if (cVar2 != '\0') {

      (**(code **)(*in_EAX + 0x440))();

      if (**(int **)(unaff_EBX + 0xf40) != 0) {

        (**(code **)(*(int *)**(int **)(unaff_EBX + 0xf40) + 0xb0))();

      }

      iVar4 = 0;

      piVar3 = (int *)(unaff_EBX + 0x1030);

      do {

        if ((iVar4 != 0x16) && (piVar1 = (int *)*piVar3, piVar1 != (int *)0x0)) {

          cVar2 = (**(code **)(*piVar1 + 0x3d8))();

          if ((cVar2 != '\0') && (piVar1[0x140] == 1)) goto LAB_007fcac1;

        }

        iVar4 = iVar4 + 1;

        piVar3 = piVar3 + 1;

      } while (iVar4 < 0x3a);

      if (*(int **)(unaff_EBX + 0xf38) != (int *)0x0) {

        if (*(char *)(unaff_EBX + 0x31d9) == '\0') {

          *(uint8_t *)(unaff_EBX + 0x31d8) = 1;

          uVar5 = 1;

        }

        else {

          uVar5 = *(uint8_t *)(unaff_EBX + 0x31d8);

        }

        (**(code **)(**(int **)(unaff_EBX + 0xf38) + 0x3c4))(uVar5);

      }

LAB_007fcac1:

      iVar4 = *(int *)(unaff_EBX + 0x10b0);

      if ((iVar4 != 0) && (*(int *)(iVar4 + 0x664) != 0)) {

                    /* WARNING: Could not recover jumptable at 0x007fcae1. Too many branches */

                    /* WARNING: Treating indirect jump as call */

        (**(code **)(**(int **)(iVar4 + 0x664) + 0x47c))();

        return;

      }

    }

  }

  return;

}
