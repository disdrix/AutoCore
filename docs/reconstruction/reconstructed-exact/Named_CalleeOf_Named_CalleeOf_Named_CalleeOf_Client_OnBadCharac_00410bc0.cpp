// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_OnBadCharac_00410bc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00410bc0
// Callee of Named_CalleeOf_Named_CalleeOf_Client_OnBadCharacterLoginId
// Address:   0x00410bc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_OnBadCharacterLoginId: auth/session helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00410bc0, InitializeCriticalSection.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Client_OnBadCharacterLoginId
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

uint32_t /* width from decompiler */ * __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_OnBadCharac_00410bc0(uint32_t /* width from decompiler */ *param_1)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009be288;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_1 = &PTR_FUN_009ccc2c;

  param_1[8] = 0;

  param_1[7] = 0;

  param_1[9] = 0;

  *(uint8_t *)(param_1 + 10) = 0;

  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));

  *param_1 = &PTR_FUN_009cccfc;

  ExceptionList = local_c;

  return param_1;

}
