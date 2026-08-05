// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxBody_00465160
// -----------------------------------------------------------------------------
// Stable ID: aa_00465160
// Callee of Named_CalleeOf_Named_CalleeOf_Named_gfxBody
// Address:   0x00465160  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_gfxBody: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×4, for×1, return×1.
//  - Notable callees: FUN_00465160.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_gfxBody
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

int __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxBody_00465160(int param_1,int param_2)



{

  int *piVar1;

  int *piVar2;

  int in_EAX;

  int *piVar3;

  

  for (; param_1 != param_2; param_1 = param_1 + 8) {

    if (param_1 == 0) {

      piVar3 = (int *)0x0;

    }

    else {

      piVar3 = (int *)(param_1 + 4);

    }

    piVar3 = (int *)*piVar3;

    if ((piVar3 != (int *)0x0) && (piVar3[1] = piVar3[1] + 1, piVar3[1] == 1)) {

      (**(code **)(*piVar3 + 4))();

    }

    piVar2 = *(int **)(in_EAX + 4);

    if (piVar2 != (int *)0x0) {

      piVar1 = piVar2 + 1;

      *piVar1 = *piVar1 + -1;

      if (*piVar1 == 0) {

        (**(code **)(*piVar2 + 8))();

      }

    }

    *(int **)(in_EAX + 4) = piVar3;

    in_EAX = in_EAX + 8;

  }

  return in_EAX;

}
