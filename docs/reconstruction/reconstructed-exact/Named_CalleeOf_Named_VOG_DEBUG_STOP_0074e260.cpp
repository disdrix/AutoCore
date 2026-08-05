// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_0074e260
// -----------------------------------------------------------------------------
// Stable ID: aa_0074e260
// Callee of Named_VOG_DEBUG_STOP (+1 other named callers)
// Address:   0x0074e260  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_VOG_DEBUG_STOP (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×4, do×1, while×1, return×1.
//  - Notable callees: FUN_00449460, FUN_004494f0, FUN_0074e260.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP (+1 other named callers)
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

void __thiscall Named_CalleeOf_Named_VOG_DEBUG_STOP_0074e260(int param_1,int *param_2)



{

  int *piVar1;

  int *piVar2;

  int *piVar3;

  

  piVar1 = param_2;

  piVar2 = (int *)FUN_004494f0(&param_2);

  piVar3 = *(int **)(param_1 + 8);

  if (piVar3 != *(int **)(param_1 + 0xc)) {

    do {

      if (*piVar3 == *piVar2) break;

      piVar3 = piVar3 + 1;

    } while (piVar3 != *(int **)(param_1 + 0xc));

  }

  if ((param_2 != (int *)0x0) && (param_2[1] = param_2[1] + -1, param_2[1] == 0)) {

    (**(code **)(*param_2 + 8))();

  }

  if (piVar3 != *(int **)(param_1 + 0xc)) {

    piVar1[0x37] = piVar1[0x37] + 1;

    FUN_00449460(&param_2,piVar3);

  }

  return;

}
