// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_004a8ec0
// -----------------------------------------------------------------------------
// Stable ID: aa_004a8ec0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x004a8ec0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: return×4, if×1, switch×1.
//  - Notable callees: FUN_004a8ec0.
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_004a8ec0(char param_1,char param_2,float *param_3,uint8_t param_4)



{

  uint uVar1;

  uint uVar2;

  float fVar3;

  float fVar4;

  

  uVar1 = (uint)param_2;

  uVar2 = uVar1 & 0x8000000f;

  if ((int)uVar2 < 0) {

    uVar2 = (uVar2 - 1 | 0xfffffff0) + 1;

  }

  fVar4 = (float)(int)uVar2 * DAT_00a14000;

  fVar3 = (float)((int)(uVar1 + ((int)uVar1 >> 0x1f & 0xfU)) >> 4) * DAT_00a14000 +

          (float)(int)param_1 * DAT_00a110c0;

  *param_3 = fVar4;

  param_3[1] = fVar3;

  switch(param_4) {

  case 0:

    fVar3 = fVar3 + DAT_00a0f514;

    *param_3 = fVar4 + DAT_00a0f514;

    param_3[1] = fVar3;

    return;

  case 1:

    fVar3 = fVar3 + DAT_00a0f514;

    *param_3 = fVar4 + _DAT_009cae98;

    param_3[1] = fVar3;

    return;

  case 2:

    fVar3 = fVar3 + _DAT_009cae98;

    *param_3 = fVar4 + DAT_00a0f514;

    param_3[1] = fVar3;

    return;

  case 3:

    fVar3 = fVar3 + _DAT_009cae98;

    *param_3 = fVar4 + _DAT_009cae98;

    param_3[1] = fVar3;

  }

  return;

}
