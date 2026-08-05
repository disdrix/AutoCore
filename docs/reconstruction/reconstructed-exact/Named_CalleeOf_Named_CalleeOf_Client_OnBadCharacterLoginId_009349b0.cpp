// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_OnBadCharacterLoginId_009349b0
// -----------------------------------------------------------------------------
// Stable ID: aa_009349b0
// Callee of Named_CalleeOf_Client_OnBadCharacterLoginId
// Address:   0x009349b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_OnBadCharacterLoginId: auth/session helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~159 non-empty decompiler lines.
//  - Control keywords: if×36, return×2, do×1, while×1.
//  - Notable callees: FUN_00756be0, FUN_007fc360, FUN_007fca10, FUN_007fdc60, FUN_007fdcc0, FUN_007fddd0, FUN_007fe640, FUN_009349b0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_OnBadCharacterLoginId
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

void Named_CalleeOf_Named_CalleeOf_Client_OnBadCharacterLoginId_009349b0(void)



{

  int iVar1;

  char cVar2;

  int in_EAX;

  int *piVar3;

  int iStack_4;

  

  if (*(int *)(in_EAX + 0xf40) != 0) {

    FUN_007fdc60();

    FUN_007fdcc0(in_EAX);

    FUN_007fddd0();

    FUN_007fe640(in_EAX);

    iVar1 = *(int *)(in_EAX + 0x1144);

    if ((iVar1 != 0) && (*(int *)(iVar1 + 0x2b0) != 0)) {

      (**(code **)(**(int **)(iVar1 + 0x2b0) + 0xb0))(iVar1);

      *(uint32_t /* width from decompiler */ *)(*(int *)(in_EAX + 0x1144) + 0x2b0) = 0;

    }

    iVar1 = *(int *)(in_EAX + 0x1148);

    if ((iVar1 != 0) && (*(int *)(iVar1 + 0x2b0) != 0)) {

      (**(code **)(**(int **)(iVar1 + 0x2b0) + 0xb0))(iVar1);

      *(uint32_t /* width from decompiler */ *)(*(int *)(in_EAX + 0x1148) + 0x2b0) = 0;

    }

    iVar1 = *(int *)(in_EAX + 0x9b8);

    if ((iVar1 != 0) && (*(int *)(iVar1 + 0x2b0) != 0)) {

      (**(code **)(**(int **)(iVar1 + 0x2b0) + 0xb0))(iVar1);

    }

    iVar1 = *(int *)(in_EAX + 0x1158);

    if ((iVar1 != 0) && (*(int *)(iVar1 + 0x2b0) != 0)) {

      (**(code **)(**(int **)(iVar1 + 0x2b0) + 0xb0))(iVar1);

    }

    iVar1 = *(int *)(in_EAX + 0x1150);

    if ((iVar1 != 0) && (*(int *)(iVar1 + 0x2b0) != 0)) {

      (**(code **)(**(int **)(iVar1 + 0x2b0) + 0xb0))(iVar1);

    }

    iVar1 = *(int *)(in_EAX + 0x1154);

    if ((iVar1 != 0) && (*(int *)(iVar1 + 0x2b0) != 0)) {

      (**(code **)(**(int **)(iVar1 + 0x2b0) + 0xb0))(iVar1);

    }

    iVar1 = *(int *)(in_EAX + 0x114c);

    if ((iVar1 != 0) && (*(int *)(iVar1 + 0x2b0) != 0)) {

      (**(code **)(**(int **)(iVar1 + 0x2b0) + 0xb0))(iVar1);

    }

    iVar1 = *(int *)(in_EAX + 0x115c);

    if ((iVar1 != 0) && (*(int *)(iVar1 + 0x2b0) != 0)) {

      (**(code **)(**(int **)(iVar1 + 0x2b0) + 0xb0))(iVar1);

    }

    iVar1 = *(int *)(in_EAX + 0x1160);

    if ((iVar1 != 0) && (*(int *)(iVar1 + 0x2b0) != 0)) {

      (**(code **)(**(int **)(iVar1 + 0x2b0) + 0xb0))(iVar1);

    }

    piVar3 = *(int **)(in_EAX + 0x1164);

    if ((piVar3 != (int *)0x0) && (piVar3[0xac] != 0)) {

      cVar2 = (**(code **)(*piVar3 + 0x3d8))();

      if (cVar2 != '\0') {

        (**(code **)(**(int **)(in_EAX + 0x1164) + 0x440))();

      }

      (**(code **)(**(int **)(*(int *)(in_EAX + 0x1164) + 0x2b0) + 0xb0))(*(int *)(in_EAX + 0x1164))

      ;

    }

    piVar3 = (int *)(in_EAX + 0x1030);

    iStack_4 = 0x3a;

    do {

      if ((int *)*piVar3 != (int *)0x0) {

        cVar2 = (**(code **)(*(int *)*piVar3 + 0x3d8))();

        if (cVar2 != '\0') {

          FUN_007fca10();

        }

      }

      piVar3 = piVar3 + 1;

      iStack_4 = iStack_4 + -1;

    } while (iStack_4 != 0);

    piVar3 = *(int **)(in_EAX + 0x1120);

    if ((piVar3 != (int *)0x0) && (piVar3[0xac] != 0)) {

      cVar2 = (**(code **)(*piVar3 + 0x3d8))();

      if (cVar2 != '\0') {

        (**(code **)(**(int **)(in_EAX + 0x1120) + 0x440))();

      }

      (**(code **)(**(int **)(*(int *)(in_EAX + 0x1120) + 0x2b0) + 0xb0))(*(int *)(in_EAX + 0x1120))

      ;

    }

    piVar3 = *(int **)(in_EAX + 0x1118);

    if ((piVar3 != (int *)0x0) && (piVar3[0xac] != 0)) {

      cVar2 = (**(code **)(*piVar3 + 0x3d8))();

      if (cVar2 != '\0') {

        (**(code **)(**(int **)(in_EAX + 0x1118) + 0x440))();

      }

      (**(code **)(**(int **)(*(int *)(in_EAX + 0x1118) + 0x2b0) + 0xb0))(*(int *)(in_EAX + 0x1118))

      ;

    }

    piVar3 = *(int **)(in_EAX + 0x111c);

    if ((piVar3 != (int *)0x0) && (piVar3[0xac] != 0)) {

      cVar2 = (**(code **)(*piVar3 + 0x3d8))();

      if (cVar2 != '\0') {

        (**(code **)(**(int **)(in_EAX + 0x111c) + 0x440))();

      }

      (**(code **)(**(int **)(*(int *)(in_EAX + 0x111c) + 0x2b0) + 0xb0))(*(int *)(in_EAX + 0x111c))

      ;

    }

    if (**(int **)(in_EAX + 0xf40) != 0) {

      FUN_007fc360();

      piVar3 = *(int **)(in_EAX + 0x1124);

      if ((*(int *)(in_EAX + 0xf40) != 0) && (piVar3 != (int *)0x0)) {

        cVar2 = (**(code **)(*piVar3 + 0x3d8))();

        if (cVar2 != '\0') {

          (**(code **)(*piVar3 + 0x440))();

          if (**(int **)(in_EAX + 0xf40) != 0) {

            (**(code **)(*(int *)**(int **)(in_EAX + 0xf40) + 0xb0))(piVar3);

          }

        }

      }

      piVar3 = *(int **)(in_EAX + 0x1128);

      if ((*(int *)(in_EAX + 0xf40) != 0) && (piVar3 != (int *)0x0)) {

        cVar2 = (**(code **)(*piVar3 + 0x3d8))();

        if (cVar2 != '\0') {

          (**(code **)(*piVar3 + 0x440))();

          if (**(int **)(in_EAX + 0xf40) != 0) {

            (**(code **)(*(int *)**(int **)(in_EAX + 0xf40) + 0xb0))(piVar3);

          }

        }

      }

      piVar3 = *(int **)(in_EAX + 0x112c);

      if ((*(int *)(in_EAX + 0xf40) != 0) && (piVar3 != (int *)0x0)) {

        cVar2 = (**(code **)(*piVar3 + 0x3d8))();

        if (cVar2 != '\0') {

          (**(code **)(*piVar3 + 0x440))();

          if (**(int **)(in_EAX + 0xf40) != 0) {

            (**(code **)(*(int *)**(int **)(in_EAX + 0xf40) + 0xb0))(piVar3);

          }

        }

      }

      piVar3 = *(int **)(in_EAX + 0x1130);

      if ((*(int *)(in_EAX + 0xf40) != 0) && (piVar3 != (int *)0x0)) {

        cVar2 = (**(code **)(*piVar3 + 0x3d8))();

        if (cVar2 != '\0') {

          (**(code **)(*piVar3 + 0x440))();

          if (**(int **)(in_EAX + 0xf40) != 0) {

            (**(code **)(*(int *)**(int **)(in_EAX + 0xf40) + 0xb0))(piVar3);

          }

        }

      }

      piVar3 = *(int **)(in_EAX + 0x1134);

      if ((*(int *)(in_EAX + 0xf40) != 0) && (piVar3 != (int *)0x0)) {

        cVar2 = (**(code **)(*piVar3 + 0x3d8))();

        if (cVar2 != '\0') {

          (**(code **)(*piVar3 + 0x440))();

          if (**(int **)(in_EAX + 0xf40) != 0) {

            (**(code **)(*(int *)**(int **)(in_EAX + 0xf40) + 0xb0))(piVar3);

          }

        }

      }

      FUN_00756be0(**(uint32_t /* width from decompiler */ **)(in_EAX + 0xf40));

                    /* WARNING: Could not recover jumptable at 0x00934df1. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(in_EAX + 0xf40) + 0x440))();

      return;

    }

  }

  return;

}
