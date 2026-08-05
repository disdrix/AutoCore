// =============================================================================
// Named_CRITICAL_ERROR_Ran_out_memory_allocating
// -----------------------------------------------------------------------------
// Stable ID: aa_00576580
// Address:   0x00576580  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_CRITICAL_ERROR_Ran_out_memory_allocating @ 0x00576580
// Stable ID: aa_00576580
// Embedded strings (evidence for future rename):
//   - "CRITICAL ERROR: Ran out of memory allocating %d"
//   - "Memory Allocation Failure"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~6 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_005762c0, Named_CRITICAL_ERROR_Ran_out_memory_allocating, FUN_007a4480.
//  - Strings: "CRITICAL ERROR: Ran out of memory allocating %d"; "Memory Allocation Failure".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "CRITICAL ERROR: Ran out of memory allocating %d"
 * Domain alias of FUN_00576580 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ Named_CRITICAL_ERROR_Ran_out_memory_allocating(uint32_t /* width from decompiler */ param_1)



{

  FUN_007a4480(1,"CRITICAL ERROR: Ran out of memory allocating %d",param_1);

  FUN_005762c0(0,0,"Memory Allocation Failure",0,param_1,0);

  return 0;

}
