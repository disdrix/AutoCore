// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004b0d60
// -----------------------------------------------------------------------------
// Stable ID: aa_004b0d60
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x004b0d60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_004b0d60.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004b0d60(float *param_1,int param_2)



{

  float fVar1;

  int iVar2;

  

  fVar1 = DAT_00a0f298;

  iVar2 = (int)DAT_00a1e8b0;

  if (iVar2 * iVar2 <= param_2) {

    param_2 = param_2 - iVar2 * iVar2;

    *param_1 = DAT_00a1e8b4 * DAT_00a0f298 * (float)(param_2 % (iVar2 * 2));

    param_1[1] = DAT_00a1e8b4 * fVar1 * (float)(param_2 / (DAT_00a1e8b0 * 2));

    param_1[2] = DAT_00a1e8b4 * fVar1 + *param_1;

    param_1[3] = DAT_00a1e8b4 * fVar1 + param_1[1];

    return;

  }

  *param_1 = DAT_00a1e8b4 * (float)(param_2 % iVar2);

  param_1[1] = DAT_00a1e8b4 * (float)(param_2 / (int)DAT_00a1e8b0);

  param_1[2] = *param_1 + DAT_00a1e8b4;

  param_1[3] = param_1[1] + DAT_00a1e8b4;

  return;

}
