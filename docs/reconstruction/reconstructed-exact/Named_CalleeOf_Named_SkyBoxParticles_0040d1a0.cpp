// =============================================================================
// Named_CalleeOf_Named_SkyBoxParticles_0040d1a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0040d1a0
// Callee of Named_SkyBoxParticles (+2 other named callers)
// Address:   0x0040d1a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_SkyBoxParticles: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_SkyBoxParticles (+2 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0040d1a0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_SkyBoxParticles (+2 other named callers)
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

void __thiscall Named_CalleeOf_Named_SkyBoxParticles_0040d1a0(int param_1,float *param_2)



{

  if ((((*param_2 != *(float *)(param_1 + 0x80)) || (param_2[1] != *(float *)(param_1 + 0x84))) ||

      (param_2[2] != *(float *)(param_1 + 0x88))) || (param_2[3] != *(float *)(param_1 + 0x8c))) {

    *(float *)(param_1 + 0x80) = *param_2;

    *(float *)(param_1 + 0x84) = param_2[1];

    *(float *)(param_1 + 0x88) = param_2[2];

    *(float *)(param_1 + 0x8c) = param_2[3];

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xbc) = 0xffffffff;

    *(int *)(param_1 + 0xb4) = *(int *)(param_1 + 0xb4) + 1;

  }

  return;

}
