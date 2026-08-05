// =============================================================================
// Named_CalleeOf_Client_RecvNpcMissionDialog_0052d8b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0052d8b0
// Callee of Client_RecvNpcMissionDialog (+3 other named callers)
// Address:   0x0052d8b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_RecvNpcMissionDialog: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Client_RecvNpcMissionDialog (+3 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~82 non-empty decompiler lines.
//  - Control keywords: if×8, while×4, return×3, do×2, goto×1.
//  - Notable callees: CVOGReaction_ResolveObjectTarget, FUN_004d4790, FUN_0052d8b0, FUN_00537ef0, FUN_00538780, FUN_00538a40, FUN_005875c0.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Client_RecvNpcMissionDialog (+3 other named callers)
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

void __thiscall Named_CalleeOf_Client_RecvNpcMissionDialog_0052d8b0(int param_1,char param_2,int param_3)



{

  char cVar1;

  void *pvVar2;

  int *piVar3;

  int *piVar4;

  int iVar5;

  int *piVar6;

  int local_c;

  int local_8;

  uint8_t local_4 [4];

  

  iVar5 = param_3;

  if (param_3 == -1) {

    piVar4 = *(int **)(param_1 + 0x50c);

  }

  else {

    piVar4 = (int *)FUN_00538a40(local_4,&param_3);

  }

  piVar4 = (int *)*piVar4;

  if (piVar4 == *(int **)(param_1 + 0x50c)) {

LAB_0052d9d1:

    if (iVar5 != -1) {

      return;

    }

  }

  else {

    do {

      piVar6 = piVar4 + 6;

      local_c = 4;

      do {

        if (((param_2 != '\0') &&

            (*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1) != 0)) &&

           (iVar5 = CVOGReaction_ResolveObjectTarget(1,*piVar6,piVar6[1]), iVar5 != 0)) {

          local_8 = iVar5;

          FUN_005875c0(&local_8);

          FUN_004d4790(iVar5);

        }

        iVar5 = param_3;

        piVar6 = piVar6 + 2;

        local_c = local_c + -1;

      } while (local_c != 0);

      if (param_3 != -1) {

        FUN_00538780(&param_2,piVar4);

        goto LAB_0052d9d1;

      }

      if (*(char *)((int)piVar4 + 0x49) == '\0') {

        piVar6 = (int *)piVar4[2];

        if (*(char *)((int)piVar6 + 0x49) == '\0') {

          cVar1 = *(char *)(*piVar6 + 0x49);

          piVar4 = piVar6;

          piVar6 = (int *)*piVar6;

          while (cVar1 == '\0') {

            cVar1 = *(char *)(*piVar6 + 0x49);

            piVar4 = piVar6;

            piVar6 = (int *)*piVar6;

          }

        }

        else {

          cVar1 = *(char *)(piVar4[1] + 0x49);

          piVar3 = (int *)piVar4[1];

          piVar6 = piVar4;

          while ((piVar4 = piVar3, cVar1 == '\0' && (piVar6 == (int *)piVar4[2]))) {

            cVar1 = *(char *)(piVar4[1] + 0x49);

            piVar3 = (int *)piVar4[1];

            piVar6 = piVar4;

          }

        }

      }

    } while (piVar4 != *(int **)(param_1 + 0x50c));

  }

  pvVar2 = *(void **)(*(int *)(param_1 + 0x50c) + 4);

  if (*(char *)((int)pvVar2 + 0x49) != '\0') {

    *(int *)(*(int *)(param_1 + 0x50c) + 4) = *(int *)(param_1 + 0x50c);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x510) = 0;

    *(uint32_t /* width from decompiler */ *)*(uint32_t /* width from decompiler */ *)(param_1 + 0x50c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x50c);

    *(int *)(*(int *)(param_1 + 0x50c) + 8) = *(int *)(param_1 + 0x50c);

    return;

  }

  FUN_00537ef0(*(uint32_t /* width from decompiler */ *)((int)pvVar2 + 8));

                    /* WARNING: Subroutine does not return */

  operator_delete(pvVar2);

}
