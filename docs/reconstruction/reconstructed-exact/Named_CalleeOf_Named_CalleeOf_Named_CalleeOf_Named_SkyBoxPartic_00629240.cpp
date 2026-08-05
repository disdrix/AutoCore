// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_SkyBoxPartic_00629240
// -----------------------------------------------------------------------------
// Stable ID: aa_00629240
// Callee of Named_CalleeOf_Named_CalleeOf_Named_SkyBoxParticles
// Address:   0x00629240  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_SkyBoxParticles: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_005b3370, FUN_00629240.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_SkyBoxParticles
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_SkyBoxPartic_00629240(int *param_1,int *param_2)



{

  uint8_t local_10 [16];

  

  if (param_1[0x17] == (param_1[0x18] & 0x7fffffffU)) {

    FUN_005b3370(param_1 + 0x16,4);

  }

  *(int **)(param_1[0x16] + param_1[0x17] * 4) = param_2;

  param_1[0x17] = param_1[0x17] + 1;

  (**(code **)(*param_2 + 0x28))(local_10);

  (**(code **)(*param_1 + 8))(param_2,&stack0xffffffec);

  *(short *)((int)param_2 + 6) = *(short *)((int)param_2 + 6) + 1;

  param_2[5] = (int)param_1;

  return;

}
