// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance_00971180
// -----------------------------------------------------------------------------
// Stable ID: aa_00971180
// Callee of Named_CalleeOf_Named_Client_InitInstance
// Address:   0x00971180  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_Client_InitInstance: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00439050, FUN_00971180.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_Client_InitInstance
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

void Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance_00971180(int param_1)



{

  uint8_t local_10 [4];

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009adb59;

  pvStack_c = ExceptionList;

  local_4 = 5;

  ExceptionList = &pvStack_c;

  FUN_00439050(local_10,**(uint32_t /* width from decompiler */ **)(param_1 + 0xe0),*(uint32_t /* width from decompiler */ **)(param_1 + 0xe0));

                    /* WARNING: Subroutine does not return */

  operator_delete(*(void **)(param_1 + 0xe0));

}
