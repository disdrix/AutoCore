// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Mission_Requesting_PlayBackground_0071fad0
// -----------------------------------------------------------------------------
// Stable ID: aa_0071fad0
// Callee of Named_CalleeOf_Mission_Requesting_PlayBackgroundMusic_on_s
// Address:   0x0071fad0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Mission_Requesting_PlayBackgroundMusic_on_s: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0071f0f0, FUN_0071fad0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Mission_Requesting_PlayBackgroundMusic_on_s
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_CalleeOf_Mission_Requesting_PlayBackground_0071fad0(void)



{

  int in_EAX;

  uint32_t /* width from decompiler */ uVar1;

  

  if (*(int *)(in_EAX + 0x14) != 0) {

    uVar1 = FUN_0071f0f0();

    return uVar1;

  }

  return 0x80004005;

}
