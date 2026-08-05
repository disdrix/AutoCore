// =============================================================================
// Named_CalleeOf_Named_gfxBodyMassageMachine_00449dc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00449dc0
// Callee of Named_gfxBodyMassageMachine
// Address:   0x00449dc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxBodyMassageMachine: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×4, for×1, return×1.
//  - Notable callees: FUN_00449dc0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_gfxBodyMassageMachine
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

void Named_CalleeOf_Named_gfxBodyMassageMachine_00449dc0(void)



{

  float fVar1;

  int *piVar2;

  int iVar3;

  int unaff_EBX;

  int *piVar4;

  int *piVar5;

  

  piVar2 = operator_new(0x90);

  fVar1 = g_flOne;

  if (piVar2 == (int *)0x0) {

    piVar2 = (int *)0x0;

  }

  else {

    piVar2[1] = 0;

    *piVar2 = (int)&PTR_FUN_00aa050c;

    piVar2[2] = DAT_00d1eac0;

    piVar2[3] = 0;

    piVar2[4] = 0;

    piVar2[5] = 0;

    piVar2[6] = (int)fVar1;

    piVar2[7] = 0;

    piVar2[8] = 0;

    piVar2[9] = 0;

    piVar2[10] = (int)fVar1;

    piVar2[0xb] = (int)fVar1;

    piVar2[0xc] = (int)fVar1;

    piVar4 = &DAT_00afdf70;

    piVar5 = piVar2 + 0x10;

    for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {

      *piVar5 = *piVar4;

      piVar4 = piVar4 + 1;

      piVar5 = piVar5 + 1;

    }

    piVar2[0x20] = 0;

  }

  if ((piVar2 != (int *)0x0) && (piVar2[1] = piVar2[1] + 1, piVar2[1] == 1)) {

    (**(code **)(*piVar2 + 4))();

  }

  piVar4 = *(int **)(unaff_EBX + 4);

  if (piVar4 != (int *)0x0) {

    piVar5 = piVar4 + 1;

    *piVar5 = *piVar5 + -1;

    if (*piVar5 == 0) {

      (**(code **)(*piVar4 + 8))();

    }

  }

  *(int **)(unaff_EBX + 4) = piVar2;

  return;

}
