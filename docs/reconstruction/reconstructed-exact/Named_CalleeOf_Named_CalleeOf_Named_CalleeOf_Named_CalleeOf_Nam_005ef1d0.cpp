// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_005ef1d0
// -----------------------------------------------------------------------------
// Stable ID: aa_005ef1d0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x005ef1d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_005ef1d0.
//  - Return sites: 1.

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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_005ef1d0(float *param_1,float param_2,float param_3)



{

  float *in_EAX;

  float fVar1;

  

  fVar1 = g_flOne / DAT_00d027b0;

  *param_1 = fVar1 * DAT_00d02800;

  param_1[1] = fVar1 * DAT_00d02804;

  param_1[2] = fVar1 * DAT_00d02808;

  *in_EAX = (DAT_00d027e0 + DAT_00d027dc) * param_3;

  in_EAX[5] = (DAT_00d027d8 + DAT_00d027e0) * param_3;

  in_EAX[10] = (DAT_00d027d8 + DAT_00d027dc) * param_3;

  fVar1 = 0.0 - DAT_00d027a4 * param_3;

  in_EAX[1] = fVar1;

  in_EAX[4] = fVar1;

  fVar1 = 0.0 - DAT_00d027a8 * param_3;

  in_EAX[6] = fVar1;

  in_EAX[9] = fVar1;

  fVar1 = 0.0 - DAT_00d027ac * param_3;

  in_EAX[8] = fVar1;

  in_EAX[2] = fVar1;

  *in_EAX = *in_EAX - (param_1[1] * param_1[1] + param_1[2] * param_1[2]) * param_2;

  in_EAX[5] = in_EAX[5] - (*param_1 * *param_1 + param_1[2] * param_1[2]) * param_2;

  in_EAX[10] = in_EAX[10] - (*param_1 * *param_1 + param_1[1] * param_1[1]) * param_2;

  fVar1 = *param_1 * param_2 * param_1[1] + in_EAX[1];

  in_EAX[1] = fVar1;

  in_EAX[4] = fVar1;

  fVar1 = param_1[2] * param_2 * param_1[1] + in_EAX[6];

  in_EAX[6] = fVar1;

  in_EAX[9] = fVar1;

  fVar1 = param_1[2] * *param_1 * param_2 + in_EAX[8];

  in_EAX[8] = fVar1;

  in_EAX[2] = fVar1;

  return;

}
