// =============================================================================
// Named_CalleeOf_Named_gfxDeviceVB_00972f10
// -----------------------------------------------------------------------------
// Stable ID: aa_00972f10
// Callee of Named_gfxDeviceVB (+1 other named callers)
// Address:   0x00972f10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxDeviceVB: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_gfxDeviceVB (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_009728e0, FUN_00972b20, FUN_00972e50, FUN_00972f10.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_gfxDeviceVB (+1 other named callers)
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

void __thiscall Named_CalleeOf_Named_gfxDeviceVB_00972f10(int param_1,float *param_2)



{

  float fVar1;

  float fVar2;

  float *pfVar3;

  float local_c;

  float local_8;

  float local_4;

  

  if ((*(byte *)(param_1 + 0xbc) & 1) != 0) {

    FUN_00972e50();

  }

  FUN_009728e0(&local_c);

  if ((*(uint *)(param_1 + 0xbc) >> 2 & 1) == 0) {

    pfVar3 = (float *)(param_1 + 0xa8);

  }

  else {

    pfVar3 = (float *)FUN_00972b20();

  }

  fVar1 = pfVar3[1];

  fVar2 = pfVar3[2];

  *param_2 = local_c * *pfVar3;

  param_2[1] = fVar1 * local_8;

  param_2[2] = fVar2 * local_4;

  return;

}
