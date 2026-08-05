// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVO_00586950
// -----------------------------------------------------------------------------
// Stable ID: aa_00586950
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGCreature_Setup
// Address:   0x00586950  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGCreature_Setup: creature/setup helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00586950, FUN_0074ba00.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGCreature_Setup
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

int __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVO_00586950(int param_1)



{

  FUN_0074ba00();

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x124) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x114) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x104) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x108) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x110) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x118) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x11c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x120) = 0;

  *(uint8_t *)(param_1 + 300) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x128) = 0;

  return param_1;

}
