// =============================================================================
// Named_CalleeOf_Named_Client_InitInstance_007b8010
// -----------------------------------------------------------------------------
// Stable ID: aa_007b8010
// Callee of Named_Client_InitInstance
// Address:   0x007b8010  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Client_InitInstance: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00404b30, FUN_007b8010, block, wcscpy.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_Client_InitInstance
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

/* WARNING: Removing unreachable block (ram,0x007b8053) */



void Named_CalleeOf_Named_Client_InitInstance_007b8010(uint32_t /* width from decompiler */ param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  wchar_t local_100 [128];

  

  uVar1 = (*(code *)PTR_FUN_00af8c9c)();

  FUN_00404b30(param_1,uVar1);

  wcscpy((wchar_t *)&DAT_00d09e80,local_100);

  return;

}
