// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_Input_PollBoundActions_0079e840
// -----------------------------------------------------------------------------
// Stable ID: aa_0079e840
// Callee of Named_CalleeOf_Client_Input_PollBoundActions
// Address:   0x0079e840  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_Input_PollBoundActions: input/binding helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~124 non-empty decompiler lines.
//  - Control keywords: if×7, do×2, return×2, while×2, switch×1, goto×1.
//  - Notable callees: ROUND×4, FUN_0079e840, SQRT.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_Input_PollBoundActions
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_CalleeOf_Client_Input_PollBoundActions_0079e840(int param_1,float param_2)



{

  int *piVar1;

  int iVar2;

  int *piVar3;

  int *piVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  char local_28;

  char local_1c;

  char local_10;

  char local_4;

  

  piVar3 = (int *)**(int **)(param_1 + 0x2dc);

  if (piVar3 != *(int **)(param_1 + 0x2dc)) {

    do {

      fVar6 = g_flZero;

      fVar5 = (float)piVar3[0x23];

      piVar3[0x23] = (int)(fVar5 - param_2);

      if (fVar6 < (float)piVar3[0x24]) {

        fVar5 = (((float)piVar3[0x22] - (fVar5 - param_2)) / (float)piVar3[0x22]) *

                (float)piVar3[0x24];

        local_28 = (char)(int)ROUND((float)(int)((uint)*(byte *)((int)piVar3 + 0x12) -

                                                (uint)*(byte *)((int)piVar3 + 0xe)) * fVar5);

        *(char *)((int)piVar3 + 0x16) = *(char *)((int)piVar3 + 0xe) + local_28;

        local_1c = (char)(int)ROUND((float)(int)((uint)*(byte *)((int)piVar3 + 0x11) -

                                                (uint)*(byte *)((int)piVar3 + 0xd)) * fVar5);

        *(char *)((int)piVar3 + 0x15) = *(char *)((int)piVar3 + 0xd) + local_1c;

        local_10 = (char)(int)ROUND((float)(int)((uint)*(byte *)(piVar3 + 4) -

                                                (uint)*(byte *)(piVar3 + 3)) * fVar5);

        *(char *)(piVar3 + 5) = (char)piVar3[3] + local_10;

        local_4 = (char)(int)ROUND((float)(int)((uint)*(byte *)((int)piVar3 + 0x13) -

                                               (uint)*(byte *)((int)piVar3 + 0xf)) * fVar5);

        *(char *)((int)piVar3 + 0x17) = *(char *)((int)piVar3 + 0xf) + local_4;

      }

      if ((((float)piVar3[0x23] <= g_flMsToSeconds_Inferred) &&

          (*(char *)((int)piVar3 + 10) != '\x03')) && (*(char *)((int)piVar3 + 10) != '\x01')) {

        *(int *)piVar3[1] = *piVar3;

        *(int *)(*piVar3 + 4) = piVar3[1];

LAB_0079ec3b:

        if ((void *)piVar3[0x1b] != (void *)0x0) {

          operator_delete__((void *)piVar3[0x1b]);

        }

        piVar3[0x1b] = 0;

                    /* WARNING: Subroutine does not return */

        operator_delete(piVar3);

      }

      switch(*(uint8_t *)((int)piVar3 + 10)) {

      case 3:

        fVar5 = (float)piVar3[0x21] * param_2;

        fVar7 = (float)piVar3[0x16] * fVar5 + (float)piVar3[0x13];

        fVar6 = (float)piVar3[0x15] * fVar5 + (float)piVar3[0x12];

        fVar8 = (float)piVar3[0x17] * fVar5 + (float)piVar3[0x14];

        piVar3[0x13] = (int)fVar7;

        fVar5 = (float)piVar3[0xe] - fVar8;

        piVar3[0x14] = (int)fVar8;

        fVar7 = (float)piVar3[0xd] - fVar7;

        fVar8 = (float)piVar3[0xc] - fVar6;

        piVar3[0x12] = (int)fVar6;

        if (((float)piVar3[0xc] - (float)piVar3[0xf]) * ((float)piVar3[0xc] - (float)piVar3[0xf]) +

            ((float)piVar3[0xd] - (float)piVar3[0x10]) * ((float)piVar3[0xd] - (float)piVar3[0x10])

            + ((float)piVar3[0xe] - (float)piVar3[0x11]) *

              ((float)piVar3[0xe] - (float)piVar3[0x11]) <=

            fVar8 * fVar8 + fVar7 * fVar7 + fVar5 * fVar5) {

          *(int *)piVar3[1] = *piVar3;

          *(int *)(*piVar3 + 4) = piVar3[1];

          goto LAB_0079ec3b;

        }

        break;

      case 4:

      case 7:

        piVar3[0x23] = DAT_00a110dc;

        break;

      case 8:

        piVar3[0x1c] = (int)((float)piVar3[0x1e] * param_2 + (float)piVar3[0x1c]);

        piVar3[0x1d] = (int)((float)piVar3[0x1e] * param_2 + (float)piVar3[0x1d]);

      case 2:

        fVar5 = (float)piVar3[0x21] * param_2;

        piVar3[0x12] = (int)((float)piVar3[0x15] * fVar5 + (float)piVar3[0x12]);

        piVar3[0x13] = (int)((float)piVar3[0x16] * fVar5 + (float)piVar3[0x13]);

        piVar3[0x14] = (int)((float)piVar3[0x17] * fVar5 + (float)piVar3[0x14]);

        break;

      case 9:

        piVar3[0x12] = (int)((float)piVar3[9] * param_2 + (float)piVar3[0x12]);

        piVar3[0x13] = (int)((float)piVar3[10] * param_2 + (float)piVar3[0x13]);

        piVar3[0x14] = (int)((float)piVar3[0xb] * param_2 + (float)piVar3[0x14]);

        piVar3[9] = (int)((float)piVar3[9] + (float)piVar3[6]);

        piVar3[10] = (int)((float)piVar3[7] + (float)piVar3[10]);

        piVar3[0xb] = (int)((float)piVar3[8] + (float)piVar3[0xb]);

        piVar3[0x1c] = (int)((float)piVar3[0x1e] * param_2 + (float)piVar3[0x1c]);

        piVar3[0x1d] = (int)((float)piVar3[0x1e] * param_2 + (float)piVar3[0x1d]);

      }

      fVar5 = (float)piVar3[0x14] - *(float *)(param_1 + 0x230);

      fVar7 = (float)piVar3[0x13] - *(float *)(param_1 + 0x22c);

      fVar6 = (float)piVar3[0x12] - *(float *)(param_1 + 0x228);

      piVar3[0x1f] = (int)SQRT(fVar5 * fVar5 + fVar7 * fVar7 + fVar6 * fVar6);

      piVar3 = (int *)*piVar3;

    } while (piVar3 != *(int **)(param_1 + 0x2dc));

  }

  piVar4 = *(int **)(param_1 + 0x2dc);

  piVar3 = (int *)*piVar4;

  if (piVar3 != piVar4) {

    do {

      piVar1 = (int *)piVar3[1];

      if ((piVar1 == piVar4) ||

         ((float)piVar3[0x1f] < (float)piVar1[0x1f] || (float)piVar3[0x1f] == (float)piVar1[0x1f]))

      {

        piVar3 = (int *)*piVar3;

      }

      else {

        iVar2 = *piVar3;

        *(int **)piVar1[1] = piVar3;

        piVar3[1] = piVar1[1];

        *piVar3 = (int)piVar1;

        piVar1[1] = (int)piVar3;

        *piVar1 = iVar2;

        *(int **)(iVar2 + 4) = piVar1;

      }

      piVar4 = *(int **)(param_1 + 0x2dc);

    } while (piVar3 != piVar4);

  }

  return 1;

}
