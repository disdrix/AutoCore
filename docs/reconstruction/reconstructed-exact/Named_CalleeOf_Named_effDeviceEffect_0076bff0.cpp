// =============================================================================
// Named_CalleeOf_Named_effDeviceEffect_0076bff0
// -----------------------------------------------------------------------------
// Stable ID: aa_0076bff0
// Callee of Named_effDeviceEffect
// Address:   0x0076bff0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_effDeviceEffect: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0076bff0, free.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_effDeviceEffect
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

void Named_CalleeOf_Named_effDeviceEffect_0076bff0(void)



{

  uint32_t /* width from decompiler */ *unaff_ESI;

  

  *unaff_ESI = &PTR_FUN_00a9d184;

  if (*(char *)(unaff_ESI + 5) != '\0') {

    free((void *)unaff_ESI[1]);

  }

  *unaff_ESI = &PTR_LAB_00a9d774;

  return;

}
