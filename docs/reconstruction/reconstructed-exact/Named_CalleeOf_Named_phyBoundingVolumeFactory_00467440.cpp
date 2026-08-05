// =============================================================================
// Named_CalleeOf_Named_phyBoundingVolumeFactory_00467440
// -----------------------------------------------------------------------------
// Stable ID: aa_00467440
// Callee of Named_phyBoundingVolumeFactory
// Address:   0x00467440  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_phyBoundingVolumeFactory: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00467440.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_phyBoundingVolumeFactory
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

void Named_CalleeOf_Named_phyBoundingVolumeFactory_00467440(void)



{

  uint32_t /* width from decompiler */ *in_EAX;

  

  in_EAX[1] = 0;

  *in_EAX = &PTR_FUN_00aa5c24;

  in_EAX[2] = DAT_00d1a6c0;

  in_EAX[3] = DAT_00d1a6c4;

  in_EAX[4] = DAT_00d1a6c8;

  in_EAX[5] = DAT_00d1a6c0;

  in_EAX[6] = DAT_00d1a6c4;

  in_EAX[7] = DAT_00d1a6c8;

  return;

}
