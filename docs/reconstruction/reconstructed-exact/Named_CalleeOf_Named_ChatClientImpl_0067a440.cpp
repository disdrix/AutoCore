// =============================================================================
// Named_CalleeOf_Named_ChatClientImpl_0067a440
// -----------------------------------------------------------------------------
// Stable ID: aa_0067a440
// Callee of Named_ChatClientImpl
// Address:   0x0067a440  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_ChatClientImpl: social/chat helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×9, return×1.
//  - Notable callees: FUN_00680c80×9, FUN_0067a440, FUN_006811a0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_ChatClientImpl
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

void Named_CalleeOf_Named_ChatClientImpl_0067a440(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,

                 int param_7,int param_8,int param_9,int param_10,uint32_t /* width from decompiler */ param_11)



{

  if ((param_2 != 0) && (*(int *)(param_1 + 0xc) != 0)) {

    FUN_00680c80(param_2,1);

  }

  if ((param_3 != 0) && (3 < *(uint *)(param_1 + 0xc))) {

    FUN_00680c80(param_3,4);

  }

  if ((param_4 != 0) && (*(int *)(param_1 + 0xc) != 0)) {

    FUN_00680c80(param_4,1);

  }

  if ((param_5 != 0) && (*(int *)(param_1 + 0xc) != 0)) {

    FUN_00680c80(param_5,1);

  }

  if ((param_6 != 0) && (*(int *)(param_1 + 0xc) != 0)) {

    FUN_00680c80(param_6,1);

  }

  if ((param_7 != 0) && (*(int *)(param_1 + 0xc) != 0)) {

    FUN_00680c80(param_7,1);

  }

  if ((param_8 != 0) && (3 < *(uint *)(param_1 + 0xc))) {

    FUN_00680c80(param_8,4);

  }

  if ((param_9 != 0) && (3 < *(uint *)(param_1 + 0xc))) {

    FUN_00680c80(param_9,4);

  }

  if ((param_10 != 0) && (*(int *)(param_1 + 0xc) != 0)) {

    FUN_00680c80(param_10,1);

  }

  FUN_006811a0(param_11);

  return;

}
