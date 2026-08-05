// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00973690
// -----------------------------------------------------------------------------
// Stable ID: aa_00973690
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli
// Address:   0x00973690  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00973590, FUN_00973690.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00973690(float param_1,uint param_2,uint param_3)



{

  float fVar1;

  float *pfVar2;

  uint uVar3;

  uint uVar4;

  float local_8;

  float local_4;

  

  pfVar2 = &local_8;

  local_4 = g_flOne;

  local_8 = 0.0;

  if ((0.0 <= param_1) && (pfVar2 = &local_4, param_1 <= g_flOne)) {

    pfVar2 = &param_1;

  }

  fVar1 = *pfVar2;

  uVar4 = param_2 >> 8 & 0xff;

  uVar3 = param_2 >> 0x10 & 0xff;

  FUN_00973590((float)(int)((param_3 >> 0x10 & 0xff) - uVar3) * fVar1 + (float)uVar3,

               (float)(int)((param_3 >> 8 & 0xff) - uVar4) * fVar1 + (float)uVar4,

               (float)(int)((param_3 & 0xff) - (param_2 & 0xff)) * fVar1 + (float)(param_2 & 0xff),

               (float)(int)((param_3 >> 0x18) - (param_2 >> 0x18)) * fVar1 +

               (float)(param_2 >> 0x18));

  return;

}
