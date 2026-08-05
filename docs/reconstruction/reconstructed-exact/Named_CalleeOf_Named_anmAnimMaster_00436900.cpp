// =============================================================================
// Named_CalleeOf_Named_anmAnimMaster_00436900
// -----------------------------------------------------------------------------
// Stable ID: aa_00436900
// Callee of Named_anmAnimMaster (+1 other named callers)
// Address:   0x00436900  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_anmAnimMaster: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_anmAnimMaster (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00436900, FUN_00437050, FUN_007689e0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_anmAnimMaster (+1 other named callers)
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

void __fastcall Named_CalleeOf_Named_anmAnimMaster_00436900(uint32_t /* width from decompiler */ param_1)



{

  int in_EAX;

  

  if (*(int *)(in_EAX + 0x4044) == 0) {

    FUN_00437050(param_1);

    return;

  }

  FUN_007689e0(param_1);

  return;

}
