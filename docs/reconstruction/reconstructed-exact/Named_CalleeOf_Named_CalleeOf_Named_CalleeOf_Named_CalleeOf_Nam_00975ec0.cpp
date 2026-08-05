// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00975ec0
// -----------------------------------------------------------------------------
// Stable ID: aa_00975ec0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x00975ec0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_004250a0, FUN_00975ec0.
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00975ec0(void)



{

  float fVar1;

  uint32_t /* width from decompiler */ *in_EAX;

  

  FUN_004250a0();

  fVar1 = g_flOne;

  in_EAX[0x79] = 0;

  in_EAX[0x74] = 0;

  in_EAX[0x75] = 0;

  in_EAX[0x76] = 0;

  in_EAX[0x77] = 0;

  in_EAX[0x78] = 0;

  in_EAX[0x7a] = 0;

  in_EAX[0x7b] = 0;

  in_EAX[0x7e] = 0;

  in_EAX[0x7f] = 0;

  in_EAX[0x81] = 0;

  *in_EAX = &PTR_LAB_00a9ba4c;

  in_EAX[0x7c] = 0xffffffff;

  in_EAX[0x7d] = fVar1;

  return;

}
