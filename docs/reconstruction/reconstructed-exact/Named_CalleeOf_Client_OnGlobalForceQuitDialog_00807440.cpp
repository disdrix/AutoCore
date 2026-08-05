// =============================================================================
// Named_CalleeOf_Client_OnGlobalForceQuitDialog_00807440
// -----------------------------------------------------------------------------
// Stable ID: aa_00807440
// Callee of Client_OnGlobalForceQuitDialog (+1 other named callers)
// Address:   0x00807440  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_OnGlobalForceQuitDialog: UI/dialog helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Client_OnGlobalForceQuitDialog (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00807440.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Client_OnGlobalForceQuitDialog (+1 other named callers)
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

uint Named_CalleeOf_Client_OnGlobalForceQuitDialog_00807440(void)



{

  uint in_EAX;

  uint uVar1;

  

  if (*(int *)(in_EAX + 0xc78) != 0) {

                    /* WARNING: Could not recover jumptable at 0x00807451. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    uVar1 = (**(code **)(**(int **)(in_EAX + 0xc78) + 8))();

    return uVar1;

  }

  return in_EAX & 0xffffff00;

}
