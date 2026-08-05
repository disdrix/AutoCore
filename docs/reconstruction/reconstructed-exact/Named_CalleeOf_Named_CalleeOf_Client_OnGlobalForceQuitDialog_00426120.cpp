// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_OnGlobalForceQuitDialog_00426120
// -----------------------------------------------------------------------------
// Stable ID: aa_00426120
// Callee of Named_CalleeOf_Client_OnGlobalForceQuitDialog
// Address:   0x00426120  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_OnGlobalForceQuitDialog: UI/dialog helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00426120.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_OnGlobalForceQuitDialog
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Client_OnGlobalForceQuitDialog_00426120(int *param_1,int param_2,int param_3,uint param_4,uint param_5)



{

  param_1[0x2d] = param_1[0x2d] & 0xfffffffb;

  if (0xffff < param_5) {

    param_5 = 0xffff;

  }

  if (0xffff < param_4) {

    param_4 = 0xffff;

  }

  param_1[0x35] = param_4;

  param_1[0x36] = param_5;

  param_1[0x34] = param_3;

  param_1[0x33] = param_2;

  *(uint8_t *)(param_1 + 0x3b) = 1;

  (**(code **)(*param_1 + 0x4c))();

  return;

}
