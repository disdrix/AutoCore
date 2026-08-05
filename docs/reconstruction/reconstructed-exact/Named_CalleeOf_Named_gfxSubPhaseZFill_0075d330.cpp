// =============================================================================
// Named_CalleeOf_Named_gfxSubPhaseZFill_0075d330
// -----------------------------------------------------------------------------
// Stable ID: aa_0075d330
// Callee of Named_gfxSubPhaseZFill
// Address:   0x0075d330  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxSubPhaseZFill: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0043d5e0, FUN_00447350, FUN_0075d330.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_gfxSubPhaseZFill
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_gfxSubPhaseZFill_0075d330(void)



{

  uint32_t /* width from decompiler */ uVar1;

  int in_EAX;

  int local_8;

  

  FUN_0043d5e0();

  if (local_8 == *(int *)(in_EAX + 0x5c)) {

    return 0;

  }

  uVar1 = *(uint32_t /* width from decompiler */ *)(local_8 + 0x10);

  FUN_00447350(in_EAX + 0x58,&stack0x00000004,local_8);

  return uVar1;

}
