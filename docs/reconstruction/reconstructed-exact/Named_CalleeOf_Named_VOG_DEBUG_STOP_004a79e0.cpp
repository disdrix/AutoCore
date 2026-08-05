// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_004a79e0
// -----------------------------------------------------------------------------
// Stable ID: aa_004a79e0
// Callee of Named_VOG_DEBUG_STOP (+1 other named callers)
// Address:   0x004a79e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_VOG_DEBUG_STOP (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_004a6be0, FUN_004a79e0, FUN_006759b0.
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

void __thiscall Named_CalleeOf_Named_VOG_DEBUG_STOP_004a79e0(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  int iVar2;

  

  iVar1 = *(int *)(param_1 + 4);

  iVar2 = FUN_006759b0(iVar1,*(uint32_t /* width from decompiler */ *)(iVar1 + 4),param_2);

  FUN_004a6be0(1);

  *(int *)(iVar1 + 4) = iVar2;

  **(int **)(iVar2 + 4) = iVar2;

  return;

}
