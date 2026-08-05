// =============================================================================
// Named_CalleeOf_CVOGReaction_Dispatch_005a5190
// -----------------------------------------------------------------------------
// Stable ID: aa_005a5190
// Callee of CVOGReaction_Dispatch
// Address:   0x005a5190  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGReaction_Dispatch: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_005a5190, QueryPerformanceCounter, QueryPerformanceFrequency.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of CVOGReaction_Dispatch
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

void __thiscall

Named_CalleeOf_CVOGReaction_Dispatch_005a5190(float *param_1,float param_2,uint8_t param_3,float param_4,uint8_t param_5,

            uint8_t param_6,uint8_t param_7)



{

  LARGE_INTEGER local_10;

  LARGE_INTEGER local_8;

  

  if (param_4 == 0.0) {

    QueryPerformanceFrequency(&local_8);

    QueryPerformanceCounter(&local_10);

    *param_1 = (float)((float10)(longlong)local_10 / (float10)(longlong)local_8);

  }

  else {

    *param_1 = param_4;

  }

  *(uint8_t *)(param_1 + 5) = param_3;

  *(uint8_t *)((int)param_1 + 0x15) = param_5;

  *(uint8_t *)((int)param_1 + 0x17) = param_7;

  param_1[1] = param_2 + param_4;

  param_1[2] = param_2;

  param_1[3] = 0.0;

  param_1[4] = param_4;

  *(uint8_t *)((int)param_1 + 0x16) = param_6;

  *(uint8_t *)(param_1 + 6) = 0;

  *(uint8_t *)((int)param_1 + 0x19) = 1;

  *(uint8_t *)((int)param_1 + 0x1a) = 1;

  *(uint8_t *)((int)param_1 + 0x1b) = 0;

  *(bool *)(param_1 + 7) = param_2 < 0.0;

  if (param_2 < 0.0) {

    param_1[2] = param_2 * DAT_00aaa668;

  }

  return;

}
