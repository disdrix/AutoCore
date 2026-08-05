// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_AudioOutThread_00674330
// -----------------------------------------------------------------------------
// Stable ID: aa_00674330
// Callee of Named_CalleeOf_Named_AudioOutThread
// Address:   0x00674330  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_AudioOutThread: presentation/world helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00674330, FUN_00675fc0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_AudioOutThread
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

int __fastcall Named_CalleeOf_Named_CalleeOf_Named_AudioOutThread_00674330(int param_1)



{

  int local_4;

  

  local_4 = param_1;

  FUN_00675fc0(&local_4,&stack0x00000004);

  if (local_4 == *(int *)(param_1 + 0x164)) {

    return 0;

  }

  return local_4 + 0x10;

}
