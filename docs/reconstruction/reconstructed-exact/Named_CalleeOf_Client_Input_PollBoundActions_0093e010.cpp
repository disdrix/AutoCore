// =============================================================================
// Named_CalleeOf_Client_Input_PollBoundActions_0093e010
// -----------------------------------------------------------------------------
// Stable ID: aa_0093e010
// Callee of Client_Input_PollBoundActions
// Address:   0x0093e010  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_Input_PollBoundActions: input/binding helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×2, for×1, return×1.
//  - Notable callees: CVOGHBList_Tick, FUN_004ba290, FUN_00593b60, FUN_0079e840, FUN_0093da30, FUN_0093e010.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Client_Input_PollBoundActions
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

void Named_CalleeOf_Client_Input_PollBoundActions_0093e010(int param_1)



{

  int iVar1;

  int *piVar2;

  float fVar3;

  int *piVar4;

  int *piVar5;

  uint32_t /* width from decompiler */ unaff_retaddr;

  

  iVar1 = DAT_00d09874;

  fVar3 = DAT_00aaa8fc;

  if (*(char *)(param_1 + 0xa1) != '\0') {

    *(float *)(DAT_00d09874 + 0x238) = *(float *)(DAT_00d09874 + 0x238) + DAT_00aaa8fc;

    *(float *)(param_1 + 0x9b0) = fVar3 / *(float *)(iVar1 + 0x30);

    *(uint8_t *)(*(int *)(param_1 + 0xde8) + 0x2e1) = 1;

    (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(param_1 + 0xf40) + 0x33c))(0x3cf5c28f);

    CVOGHBList_Tick(*(void **)(param_1 + 0xd38),0);

    FUN_0093da30();

    FUN_0079e840(unaff_retaddr);

    iVar1 = *(int *)(*(int *)(param_1 + 0xe04) + 0xe898);

    piVar2 = *(int **)(iVar1 + 0xa0);

    for (piVar5 = *(int **)(iVar1 + 0x9c); piVar5 != piVar2; piVar5 = piVar5 + 1) {

      iVar1 = *piVar5;

      if (iVar1 == 0) {

        piVar4 = (int *)0x0;

      }

      else {

        piVar4 = (int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1);

      }

      (**(code **)(*piVar4 + 0xec))(&stack0x00000000);

    }

    FUN_004ba290(&stack0x00000000);

    FUN_00593b60(unaff_retaddr);

    *(uint8_t *)(*(int *)(param_1 + 0xde8) + 0x2e1) = 0;

  }

  return;

}
