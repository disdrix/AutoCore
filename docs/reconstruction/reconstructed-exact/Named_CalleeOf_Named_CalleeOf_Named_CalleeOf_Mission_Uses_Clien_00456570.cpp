// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_Uses_Clien_00456570
// -----------------------------------------------------------------------------
// Stable ID: aa_00456570
// Callee of Named_CalleeOf_Named_CalleeOf_Mission_Uses_Client_GetMissionCom
// Address:   0x00456570  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Mission_Uses_Client_GetMissionCom: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00456570, FUN_00968080, _eh_vector_destructor_iterator_.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Mission_Uses_Client_GetMissionCom
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_Uses_Clien_00456570(int param_1)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009be6e6;

  local_c = ExceptionList;

  local_4 = 0;

  ExceptionList = &local_c;

  FUN_00968080();

  local_4 = 0xffffffff;

  _eh_vector_destructor_iterator_((void *)(param_1 + 4),0x10,4,FUN_00691630);

  ExceptionList = local_c;

  return;

}
