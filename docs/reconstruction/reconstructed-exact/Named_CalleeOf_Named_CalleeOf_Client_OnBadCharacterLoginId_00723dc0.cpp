// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_OnBadCharacterLoginId_00723dc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00723dc0
// Callee of Named_CalleeOf_Client_OnBadCharacterLoginId
// Address:   0x00723dc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_OnBadCharacterLoginId: auth/session helper. Evidence string: "Soundqueue wiping all %d soundreqs". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "Soundqueue wiping all %d soundreqs"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~48 non-empty decompiler lines.
//  - Control keywords: if×6, do×2, while×2, return×2.
//  - Notable callees: FUN_0071f810, FUN_00723dc0, FUN_007a4480.
//  - Strings: "Soundqueue wiping all %d soundreqs".
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_CalleeOf_Client_OnBadCharacterLoginId_00723dc0(int param_1)



{

  int *piVar1;

  uint32_t /* width from decompiler */ *puVar2;

  void *pvVar3;

  int *piVar4;

  int *piVar5;

  int iVar6;

  

  if ((*(char *)(param_1 + 600) != '\0') && (iVar6 = 0, 0 < *(int *)(param_1 + 0x210))) {

    piVar4 = (int *)(param_1 + 0x31c);

    do {

      if (*piVar4 != 0) {

        *(uint8_t *)(*piVar4 + 0x38) = 1;

        FUN_0071f810();

        if ((uint32_t /* width from decompiler */ *)*piVar4 != (uint32_t /* width from decompiler */ *)0x0) {

          (*(code *)**(uint32_t /* width from decompiler */ **)*piVar4)(1);

        }

        *piVar4 = 0;

      }

      iVar6 = iVar6 + 1;

      piVar4 = piVar4 + 1;

    } while (iVar6 < *(int *)(param_1 + 0x210));

  }

  FUN_007a4480(0,"Soundqueue wiping all %d soundreqs",*(uint32_t /* width from decompiler */ *)(param_1 + 0x318));

  piVar4 = (int *)**(int **)(param_1 + 0x314);

  piVar5 = DAT_00d219e8;

  if (piVar4 != *(int **)(param_1 + 0x314)) {

    do {

      piVar1 = (int *)piVar4[2];

      if (piVar1 != (int *)0x0) {

        *piVar1 = (int)piVar5;

        piVar5 = piVar1;

        DAT_00d219e8 = piVar1;

      }

      piVar4 = (int *)*piVar4;

    } while (piVar4 != (int *)*(int *)(param_1 + 0x314));

  }

  puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x314);

  pvVar3 = (void *)*puVar2;

  *puVar2 = puVar2;

  *(int *)(*(int *)(param_1 + 0x314) + 4) = *(int *)(param_1 + 0x314);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x318) = 0;

  if (pvVar3 == *(void **)(param_1 + 0x314)) {

    return 0;

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(pvVar3);

}
