// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_SendLogicUi_0040a6e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0040a6e0
// Callee of Named_CalleeOf_Named_CalleeOf_Client_SendLogicUiPacket
// Address:   0x0040a6e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_SendLogicUiPacket: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00408880, FUN_0040a6e0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Client_SendLogicUiPacket
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_SendLogicUi_0040a6e0(int param_1,uint32_t /* width from decompiler */ param_2)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009bdcb1;

  local_c = ExceptionList;

  local_4 = 0;

  if (param_1 != 0) {

    ExceptionList = &local_c;

    FUN_00408880(param_2);

  }

  ExceptionList = local_c;

  return;

}
