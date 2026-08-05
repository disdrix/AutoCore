// =============================================================================
// Named_CalleeOf_CVOGHBAIBase_FindTargetToAttack_004bb0d0
// -----------------------------------------------------------------------------
// Stable ID: aa_004bb0d0
// Callee of CVOGHBAIBase_FindTargetToAttack
// Address:   0x004bb0d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGHBAIBase_FindTargetToAttack: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: CVOGReaction_ResolveObjectTarget, FUN_004bb0d0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of CVOGHBAIBase_FindTargetToAttack
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

uint32_t /* width from decompiler */ Named_CalleeOf_CVOGHBAIBase_FindTargetToAttack_004bb0d0(uint32_t /* width from decompiler */ *param_1)



{

  int *piVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  piVar1 = (int *)CVOGReaction_ResolveObjectTarget(*(uint8_t *)(param_1 + 2),*param_1,param_1[1])

  ;

  if (piVar1 != (int *)0x0) {

    uVar2 = (**(code **)(*piVar1 + 0x1dc))();

    return uVar2;

  }

  return 0;

}
