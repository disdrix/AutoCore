// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_Server_needs_an_update_00997120
// -----------------------------------------------------------------------------
// Stable ID: aa_00997120
// Callee of Named_CalleeOf_Named_Server_needs_an_update
// Address:   0x00997120  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_Server_needs_an_update: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~86 non-empty decompiler lines.
//  - Control keywords: if×7, while×6, do×2, return×1.
//  - Notable callees: FUN_004010f0, FUN_004014b0, FUN_00401540, FUN_007fe140, FUN_00997120, Object_ResolveFromTFID.
//  - Return sites: 1.

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

void Named_CalleeOf_Named_CalleeOf_Named_Server_needs_an_update_00997120(int param_1)



{

  char cVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int *piVar3;

  int iVar4;

  int *piVar5;

  void *pvVar6;

  int *piVar7;

  

  iVar4 = param_1;

  piVar7 = (int *)**(int **)(param_1 + 0x154);

  if (piVar7 != *(int **)(param_1 + 0x154)) {

    do {

      puVar2 = (uint32_t /* width from decompiler */ *)piVar7[6];

      FUN_007fe140(iVar4);

      if (((*(int *)(iVar4 + 0xe04) == 0) ||

          (pvVar6 = Object_ResolveFromTFID((TFID_16 *)(puVar2 + 0x58)), pvVar6 == (void *)0x0)) &&

         (puVar2 != (uint32_t /* width from decompiler */ *)0x0)) {

        (**(code **)*puVar2)(1);

      }

      if (*(char *)((int)piVar7 + 0x21) == '\0') {

        piVar3 = (int *)piVar7[2];

        if (*(char *)((int)piVar3 + 0x21) == '\0') {

          cVar1 = *(char *)(*piVar3 + 0x21);

          piVar7 = piVar3;

          piVar3 = (int *)*piVar3;

          while (cVar1 == '\0') {

            cVar1 = *(char *)(*piVar3 + 0x21);

            piVar7 = piVar3;

            piVar3 = (int *)*piVar3;

          }

        }

        else {

          cVar1 = *(char *)(piVar7[1] + 0x21);

          piVar5 = (int *)piVar7[1];

          piVar3 = piVar7;

          while ((piVar7 = piVar5, cVar1 == '\0' && (piVar3 == (int *)piVar7[2]))) {

            cVar1 = *(char *)(piVar7[1] + 0x21);

            piVar5 = (int *)piVar7[1];

            piVar3 = piVar7;

          }

        }

      }

    } while (piVar7 != *(int **)(iVar4 + 0x154));

  }

  FUN_004014b0(*(uint32_t /* width from decompiler */ *)(*(int *)(iVar4 + 0x154) + 4));

  *(int *)(*(int *)(iVar4 + 0x154) + 4) = *(int *)(iVar4 + 0x154);

  *(uint32_t /* width from decompiler */ *)(iVar4 + 0x158) = 0;

  *(uint32_t /* width from decompiler */ *)*(uint32_t /* width from decompiler */ *)(iVar4 + 0x154) = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x154);

  *(int *)(*(int *)(iVar4 + 0x154) + 8) = *(int *)(iVar4 + 0x154);

  piVar7 = (int *)**(int **)(iVar4 + 0x3094);

  if (piVar7 != *(int **)(iVar4 + 0x3094)) {

    do {

      FUN_004010f0(iVar4 + 0x3090,&param_1,piVar7);

      if (*(char *)((int)piVar7 + 0x21) == '\0') {

        piVar3 = (int *)piVar7[2];

        if (*(char *)((int)piVar3 + 0x21) == '\0') {

          cVar1 = *(char *)(*piVar3 + 0x21);

          piVar7 = piVar3;

          piVar3 = (int *)*piVar3;

          while (cVar1 == '\0') {

            cVar1 = *(char *)(*piVar3 + 0x21);

            piVar7 = piVar3;

            piVar3 = (int *)*piVar3;

          }

        }

        else {

          cVar1 = *(char *)(piVar7[1] + 0x21);

          piVar5 = (int *)piVar7[1];

          piVar3 = piVar7;

          while ((piVar7 = piVar5, cVar1 == '\0' && (piVar3 == (int *)piVar7[2]))) {

            cVar1 = *(char *)(piVar7[1] + 0x21);

            piVar5 = (int *)piVar7[1];

            piVar3 = piVar7;

          }

        }

      }

    } while (piVar7 != *(int **)(iVar4 + 0x3094));

  }

  FUN_00401540(*(uint32_t /* width from decompiler */ *)(*(int *)(iVar4 + 0x3094) + 4));

  *(int *)(*(int *)(iVar4 + 0x3094) + 4) = *(int *)(iVar4 + 0x3094);

  *(uint32_t /* width from decompiler */ *)(iVar4 + 0x3098) = 0;

  *(uint32_t /* width from decompiler */ *)*(uint32_t /* width from decompiler */ *)(iVar4 + 0x3094) = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x3094);

  *(int *)(*(int *)(iVar4 + 0x3094) + 8) = *(int *)(iVar4 + 0x3094);

  return;

}
