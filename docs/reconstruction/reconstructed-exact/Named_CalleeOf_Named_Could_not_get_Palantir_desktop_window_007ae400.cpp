// =============================================================================
// Named_CalleeOf_Named_Could_not_get_Palantir_desktop_window_007ae400
// -----------------------------------------------------------------------------
// Stable ID: aa_007ae400
// Callee of Named_Could_not_get_Palantir_desktop_window
// Address:   0x007ae400  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Could_not_get_Palantir_desktop_window: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0076f5f0, FUN_007aa3e0, FUN_007aac90, FUN_007ae400.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_Could_not_get_Palantir_desktop_window
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

void Named_CalleeOf_Named_Could_not_get_Palantir_desktop_window_007ae400(void)



{

  uint32_t /* width from decompiler */ *puVar1;

  int unaff_ESI;

  

  DAT_00d17944 = unaff_ESI;

  FUN_0076f5f0(&DAT_00afdb80,&DAT_00afdb80);

  FUN_007aac90();

  if (unaff_ESI != 0) {

    puVar1 = (uint32_t /* width from decompiler */ *)FUN_007aa3e0();

    DAT_00d1e818 = *puVar1;

    DAT_00d1e81c = puVar1[1];

  }

  return;

}
