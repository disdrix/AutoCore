// =============================================================================
// Named_CalleeOf_CVOGTacArc_InitializeMesh_009701d0
// -----------------------------------------------------------------------------
// Stable ID: aa_009701d0
// Callee of CVOGTacArc_InitializeMesh
// Address:   0x009701d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGTacArc_InitializeMesh: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: FUN_0073e1e0, FUN_00744ea0, FUN_00965600, FUN_009701d0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of CVOGTacArc_InitializeMesh
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_CVOGTacArc_InitializeMesh_009701d0(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  int *piVar1;

  int *piVar2;

  int *piVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ uVar5;

  int *piStack_4;

  

  uVar4 = param_2;

  piStack_4 = param_1;

  piVar3 = (int *)FUN_0073e1e0(DAT_00d1f61c,param_2,&param_2);

  if (piVar3 == (int *)0x0) {

    return 0xffffffff;

  }

  piVar3[1] = piVar3[1] + 1;

  if (piVar3[1] == 1) {

    (**(code **)(*piVar3 + 4))();

  }

  piVar2 = (int *)*param_1;

  if (piVar2 != (int *)0x0) {

    piVar1 = piVar2 + 1;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar2 + 8))();

    }

  }

  *param_1 = (int)piVar3;

  if (*(char *)(DAT_00d1f050 + 0x68) != '\0') {

    uVar5 = 1;

    uVar4 = FUN_00965600(&piStack_4,uVar4,1);

    FUN_00744ea0(uVar4,uVar5);

  }

  return param_2;

}
