// =============================================================================
// Named_CalleeOf_CVOGHBAIDriver_DoLogic_005d6de0
// -----------------------------------------------------------------------------
// Stable ID: aa_005d6de0
// Callee of CVOGHBAIDriver_DoLogic (+1 other named callers)
// Address:   0x005d6de0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGHBAIDriver_DoLogic: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. CVOGHBAIDriver_DoLogic (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_004fc650, FUN_005d6de0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of CVOGHBAIDriver_DoLogic (+1 other named callers)
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

void __thiscall Named_CalleeOf_CVOGHBAIDriver_DoLogic_005d6de0(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  if (*(char *)(param_1 + 0xb2) != '\0') {

    *(uint8_t *)(param_1 + 0xb2) = 0;

    FUN_004fc650(param_2,param_3,param_4,*(uint8_t *)(param_1 + 0xb3));

    *(uint8_t *)(param_1 + 0xb3) = 0;

  }

  return;

}
