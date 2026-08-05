// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOGClient_0040f400
// -----------------------------------------------------------------------------
// Stable ID: aa_0040f400
// Callee of Named_CalleeOf_Named_VOGClient
// Address:   0x0040f400  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOGClient: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_0040f400.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_VOGClient
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

void Named_CalleeOf_Named_CalleeOf_Named_VOGClient_0040f400(void)



{

  uint32_t /* width from decompiler */ *puVar1;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009bc440;

  local_10 = ExceptionList;

  ExceptionList = &local_10;

  puVar1 = operator_new(0x18);

  if (puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

    *puVar1 = 0;

  }

  if (puVar1 + 1 != (uint32_t /* width from decompiler */ *)0x0) {

    puVar1[1] = 0;

  }

  if (puVar1 + 2 != (uint32_t /* width from decompiler */ *)0x0) {

    puVar1[2] = 0;

  }

  *(uint8_t *)(puVar1 + 5) = 1;

  *(uint8_t *)((int)puVar1 + 0x15) = 0;

  ExceptionList = local_10;

  return;

}
