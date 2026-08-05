// =============================================================================
// Named_CalleeOf_Named_SkyBoxParticles_004b6750
// -----------------------------------------------------------------------------
// Stable ID: aa_004b6750
// Callee of Named_SkyBoxParticles
// Address:   0x004b6750  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_SkyBoxParticles: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_004b6750, FUN_004ebe50.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_SkyBoxParticles
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

uint8_t * __fastcall Named_CalleeOf_Named_SkyBoxParticles_004b6750(uint8_t *param_1)



{

  float fVar1;

  

  FUN_004ebe50();

  fVar1 = g_flOne;

  *param_1 = 0;

  *(float *)(param_1 + 0x170) = fVar1;

  return param_1;

}
