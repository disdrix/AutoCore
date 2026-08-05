// =============================================================================
// Named_CalleeOf_Mission_You_do_not_have_permission_to_do_that_004c22a0
// -----------------------------------------------------------------------------
// Stable ID: aa_004c22a0
// Callee of Mission_You_do_not_have_permission_to_do_that
// Address:   0x004c22a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_You_do_not_have_permission_to_do_that: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, while×1.
//  - Notable callees: FUN_004c22a0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Mission_You_do_not_have_permission_to_do_that
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Mission_You_do_not_have_permission_to_do_that_004c22a0(int param_1,int param_2,int param_3)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  

  iVar3 = 0;

  while( true ) {

    if (*(int *)(param_1 + 0x1e4) == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = *(int *)(param_1 + 0x1e8) - *(int *)(param_1 + 0x1e4) >> 2;

    }

    if (iVar2 <= iVar3) break;

    piVar1 = *(int **)(*(int *)(param_1 + 0x1e4) + iVar3 * 4);

    if ((*piVar1 == param_2) && (piVar1[1] == param_3)) {

      return *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x1e4) + iVar3 * 4);

    }

    iVar3 = iVar3 + 1;

  }

  return 0;

}
