// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_00404d10
// -----------------------------------------------------------------------------
// Stable ID: aa_00404d10
// Callee of Named_VOG_DEBUG_STOP
// Address:   0x00404d10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00404d10.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP
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

float10 __fastcall Named_CalleeOf_Named_VOG_DEBUG_STOP_00404d10(int param_1)



{

  float fVar1;

  float fVar2;

  

  fVar1 = *(float *)(*(int *)(param_1 + 0x3c) + 0x2c);

  fVar2 = 0.0;

  if (fVar1 != 0.0) {

    fVar2 = g_flOne / fVar1;

  }

  return (float10)fVar2;

}
