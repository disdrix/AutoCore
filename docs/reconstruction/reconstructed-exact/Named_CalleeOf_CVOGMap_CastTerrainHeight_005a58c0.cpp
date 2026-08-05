// =============================================================================
// Named_CalleeOf_CVOGMap_CastTerrainHeight_005a58c0
// -----------------------------------------------------------------------------
// Stable ID: aa_005a58c0
// Callee of CVOGMap_CastTerrainHeight
// Address:   0x005a58c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGMap_CastTerrainHeight: skill/cast helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_005a5810, FUN_005a58c0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of CVOGMap_CastTerrainHeight
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

float10 __thiscall Named_CalleeOf_CVOGMap_CastTerrainHeight_005a58c0(int param_1,float param_2,float param_3)



{

  uint uVar1;

  uint uVar2;

  uint uVar3;

  float10 fVar4;

  

  param_2 = *(float *)(param_1 + 0x30) * param_2;

  param_3 = *(float *)(param_1 + 0x38) * param_3;

  uVar1 = (uint)param_2;

  uVar2 = *(int *)(param_1 + 0xc) - 2;

  if ((int)(((int)uVar1 < 1) - 1 & uVar1) < (int)uVar2) {

    uVar2 = ((int)uVar1 < 1) - 1 & uVar1;

  }

  uVar1 = (uint)param_3;

  uVar3 = *(int *)(param_1 + 0x10) - 2;

  if ((int)(((int)uVar1 < 1) - 1 & uVar1) < (int)uVar3) {

    uVar3 = ((int)uVar1 < 1) - 1 & uVar1;

  }

  fVar4 = (float10)FUN_005a5810(uVar2,uVar3,param_2 - (float)(int)uVar2,param_3 - (float)(int)uVar3)

  ;

  return fVar4 / (float10)*(float *)(param_1 + 0x34);

}
