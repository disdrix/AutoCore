// =============================================================================
// Named_CalleeOf_Client_OnReverseEngineerFailure_00513de0
// -----------------------------------------------------------------------------
// Stable ID: aa_00513de0
// Callee of Client_OnReverseEngineerFailure
// Address:   0x00513de0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_OnReverseEngineerFailure: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_00512670, FUN_00513de0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Client_OnReverseEngineerFailure
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

void __thiscall Named_CalleeOf_Client_OnReverseEngineerFailure_00513de0(int *param_1,uint param_2)



{

  int *extraout_ECX;

  

  if (((uint)param_1[0x5f] >> 0x13 & 1) != (param_2 & 0xff)) {

    FUN_00512670();

    param_1 = extraout_ECX;

  }

  param_1[0x5f] = param_1[0x5f] ^ ((param_2 & 0xff) << 0x13 ^ param_1[0x5f]) & 0x80000;

  if ((*(byte *)((int)param_1 + 0x17e) & 8) != 0) {

                    /* WARNING: Could not recover jumptable at 0x00513e24. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(*param_1 + 0x90))();

    return;

  }

  return;

}
