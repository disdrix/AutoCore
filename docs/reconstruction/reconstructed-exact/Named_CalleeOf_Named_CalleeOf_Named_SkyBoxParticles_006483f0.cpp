// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_SkyBoxParticles_006483f0
// -----------------------------------------------------------------------------
// Stable ID: aa_006483f0
// Callee of Named_CalleeOf_Named_SkyBoxParticles
// Address:   0x006483f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_SkyBoxParticles: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_006483f0, FUN_006503e0, FUN_0065aec0.
//  - Return sites: 2.

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

uint32_t /* width from decompiler */ * __fastcall Named_CalleeOf_Named_CalleeOf_Named_SkyBoxParticles_006483f0(uint32_t /* width from decompiler */ *param_1)



{

  int iVar1;

  

  *(uint16_t *)((int)param_1 + 6) = 1;

  *param_1 = &PTR_FUN_009e4730;

  iVar1 = (**(code **)(*DAT_00b05060 + 0x10))(0x18,0x17);

  if (iVar1 != 0) {

    FUN_0065aec0();

    FUN_006503e0();

    param_1[2] = iVar1;

    return param_1;

  }

  param_1[2] = 0;

  return param_1;

}
