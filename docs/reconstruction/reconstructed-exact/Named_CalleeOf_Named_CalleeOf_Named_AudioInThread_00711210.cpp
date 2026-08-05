// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_AudioInThread_00711210
// -----------------------------------------------------------------------------
// Stable ID: aa_00711210
// Callee of Named_CalleeOf_Named_AudioInThread
// Address:   0x00711210  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_AudioInThread: presentation/world helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_00711210, FUN_00711d00.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_AudioInThread
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_CalleeOf_Named_AudioInThread_00711210(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  if ((param_1 != (int *)0x0) && (*param_1 == 0xface)) {

    if ((char)param_1[3] != '\n') {

      return 0x17de;

    }

    FUN_00711d00(param_1[4],param_2);

    return 0;

  }

  return 0x17d4;

}
