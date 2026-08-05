// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_SkyBoxParticles_006353b0
// -----------------------------------------------------------------------------
// Stable ID: aa_006353b0
// Callee of Named_CalleeOf_Named_SkyBoxParticles
// Address:   0x006353b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_SkyBoxParticles: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00651e90×2, FUN_006353b0, FUN_00651b10, FUN_00651b60.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_SkyBoxParticles
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

uint32_t /* width from decompiler */ * __thiscall Named_CalleeOf_Named_CalleeOf_Named_SkyBoxParticles_006353b0(uint32_t /* width from decompiler */ *param_1,int param_2)



{

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  

  *(uint16_t *)((int)param_1 + 6) = 1;

  param_1[2] = &PTR_LAB_009e3a68;

  param_1[5] = 0;

  param_1[4] = 0;

  param_1[3] = 0;

  param_1[6] = 0;

  *param_1 = &PTR_FUN_009e390c;

  param_1[2] = &PTR_LAB_009e38fc;

  FUN_00651e90();

  param_1[8] = param_2;

  *(short *)(param_2 + 6) = *(short *)(param_2 + 6) + 1;

  FUN_00651b10(*(uint32_t /* width from decompiler */ *)(param_1[8] + 0xc));

  FUN_00651b60(*(uint32_t /* width from decompiler */ *)(param_1[8] + 0x10));

  FUN_00651e90();

  param_1[9] = local_24;

  param_1[10] = local_20;

  return param_1;

}
