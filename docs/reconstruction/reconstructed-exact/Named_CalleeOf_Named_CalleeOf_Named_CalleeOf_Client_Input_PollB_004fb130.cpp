// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_Input_PollB_004fb130
// -----------------------------------------------------------------------------
// Stable ID: aa_004fb130
// Callee of Named_CalleeOf_Named_CalleeOf_Client_Input_PollBoundActions
// Address:   0x004fb130  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_Input_PollBoundActions: input/binding helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~71 non-empty decompiler lines.
//  - Control keywords: if×7, return×3, do×1, while×1.
//  - Notable callees: FUN_004cd220, FUN_004f6ee0, FUN_004faf80, FUN_004fb130, SQRT.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Client_Input_PollBoundActions
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_Input_PollB_004fb130(int param_1,float param_2)



{

  int *piVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  bool bVar5;

  bool bVar6;

  byte bVar7;

  char cVar8;

  int iVar9;

  float10 fVar10;

  

  iVar9 = *(int *)(param_1 + 600);

  bVar5 = false;

  if ((iVar9 != 0) && (*(int *)(param_1 + 0x1a4) != 0)) {

    bVar7 = 0;

    bVar6 = false;

    if (0 < *(char *)(iVar9 + 0xb0)) {

      do {

        bVar5 = bVar6;

        if (*(char *)((char)bVar7 + 0xf4 + iVar9) != '\0') {

          bVar5 = true;

        }

        bVar7 = bVar7 + 1;

        bVar6 = bVar5;

      } while ((int)(uint)bVar7 < (int)*(char *)(iVar9 + 0xb0));

    }

    if (*(int *)(param_1 + 0x118) == 1) {

      if ((((!bVar5) &&

           (cVar8 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x198

                                ))(), cVar8 == '\0')) && (*(char *)(param_1 + 0x101) == '\0')) &&

         (((piVar1 = *(int **)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1),

           piVar1 == (int *)0x0 || (iVar9 = (**(code **)(*piVar1 + 0x1dc))(), iVar9 == 0)) ||

          (iVar9 = (**(code **)(**(int **)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1) +

                               0x1dc))(), *(char *)(iVar9 + 0x4f1) == '\0')))) {

        iVar9 = *(int *)(*(int *)(param_1 + 8) + 0x3c);

        fVar2 = *(float *)(iVar9 + 0xb0);

        fVar3 = *(float *)(iVar9 + 0xb4);

        fVar4 = *(float *)(iVar9 + 0xb8);

        fVar10 = (float10)FUN_004cd220(fVar2,fVar4);

        fVar3 = (float)((float10)fVar3 - fVar10);

        if (*(float *)(*(int *)(param_1 + 0x1a4) + 0x80) < fVar3) {

          *(float *)(*(int *)(param_1 + 0x1a4) + 0x80) = fVar3;

        }

        iVar9 = *(int *)(param_1 + 0x1a4);

        fVar2 = fVar2 - *(float *)(iVar9 + 0x10);

        fVar3 = *(float *)(iVar9 + 0x14);

        fVar4 = fVar4 - *(float *)(iVar9 + 0x18);

        *(float *)(*(int *)(param_1 + 0x1a4) + 0x84) =

             *(float *)(*(int *)(param_1 + 0x1a4) + 0x84) + param_2;

        *(float *)(*(int *)(param_1 + 0x1a4) + 0x7c) =

             SQRT(fVar2 * fVar2 + -fVar3 * -fVar3 + fVar4 * fVar4);

        return;

      }

      FUN_004faf80();

      return;

    }

    if (((!bVar5) &&

        (cVar8 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x198))

                           (), cVar8 == '\0')) &&

       ((*(char *)(param_1 + 0x101) == '\0' &&

        ((((piVar1 = *(int **)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1),

           piVar1 == (int *)0x0 || (iVar9 = (**(code **)(*piVar1 + 0x1dc))(), iVar9 == 0)) ||

          (iVar9 = (**(code **)(**(int **)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1) +

                               0x1dc))(), *(char *)(iVar9 + 0x4f1) == '\0')) &&

         ((*(int *)(param_1 + 0x118) != 1 && (**(char **)(param_1 + 0x1a4) == '\0')))))))) {

      FUN_004f6ee0();

    }

  }

  return;

}
