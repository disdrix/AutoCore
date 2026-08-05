// =============================================================================
// Named_CalleeOf_Named_effEffectImpl_00445050
// -----------------------------------------------------------------------------
// Stable ID: aa_00445050
// Callee of Named_effEffectImpl (+1 other named callers)
// Address:   0x00445050  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_effEffectImpl: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_effEffectImpl (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: CONCAT31, FUN_00445050.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_effEffectImpl (+1 other named callers)
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_effEffectImpl_00445050(void)



{

  int in_EAX;

  int iVar1;

  

  if (*(int *)(in_EAX + 4) == 0) {

    return 1;

  }

  iVar1 = *(int *)(in_EAX + 8) - *(int *)(in_EAX + 4);

  return CONCAT31((int3)(iVar1 >> 10),iVar1 >> 2 == 0);

}
