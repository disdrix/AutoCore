// =============================================================================
// Named_CalleeOf_Named_assPreloader_0043c5f0
// -----------------------------------------------------------------------------
// Stable ID: aa_0043c5f0
// Callee of Named_assPreloader (+1 other named callers)
// Address:   0x0043c5f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_assPreloader: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_assPreloader (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: EnterCriticalSection, FUN_0043c5f0, FUN_0043c730, LeaveCriticalSection.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_assPreloader (+1 other named callers)
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

void __fastcall Named_CalleeOf_Named_assPreloader_0043c5f0(int param_1)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009be0c8;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  if (*(char *)(param_1 + 0x2c) != '\0') {

    ExceptionList = &local_c;

    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x14));

  }

  local_4 = 0;

  FUN_0043c730();

  if (*(char *)(param_1 + 0x2c) != '\0') {

    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x14));

  }

  ExceptionList = local_c;

  return;

}
