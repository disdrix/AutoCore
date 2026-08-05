// =============================================================================
// Named_CalleeOf_Named_anmAnimMaster_00439a50
// -----------------------------------------------------------------------------
// Stable ID: aa_00439a50
// Callee of Named_anmAnimMaster
// Address:   0x00439a50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_anmAnimMaster: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00437000, FUN_00439a50, FUN_00769660.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_anmAnimMaster
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

void __fastcall Named_CalleeOf_Named_anmAnimMaster_00439a50(uint32_t /* width from decompiler */ param_1)



{

  int in_EAX;

  

  if (*(int *)(in_EAX + 0x4044) == 0) {

    FUN_00437000();

    return;

  }

  FUN_00769660(param_1);

  return;

}
