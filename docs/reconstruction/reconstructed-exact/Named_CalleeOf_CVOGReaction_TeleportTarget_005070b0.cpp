// =============================================================================
// Named_CalleeOf_CVOGReaction_TeleportTarget_005070b0
// -----------------------------------------------------------------------------
// Stable ID: aa_005070b0
// Callee of CVOGReaction_TeleportTarget (+2 other named callers)
// Address:   0x005070b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGReaction_TeleportTarget: spawn/transfer helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. CVOGReaction_TeleportTarget (+2 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_005070b0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of CVOGReaction_TeleportTarget (+2 other named callers)
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

void __thiscall Named_CalleeOf_CVOGReaction_TeleportTarget_005070b0(int param_1,uint8_t *param_2)



{

  if (*(int *)(param_1 + 0x44) == 0) {

    *param_2 = 0;

    return;

  }

  *param_2 = *(uint8_t *)(*(int *)(param_1 + 0x44) + 0x29);

  return;

}
