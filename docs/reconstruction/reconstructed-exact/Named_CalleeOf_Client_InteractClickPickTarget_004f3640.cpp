// =============================================================================
// Named_CalleeOf_Client_InteractClickPickTarget_004f3640
// -----------------------------------------------------------------------------
// Stable ID: aa_004f3640
// Callee of Client_InteractClickPickTarget
// Address:   0x004f3640  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_InteractClickPickTarget: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_004f3640, FUN_005a53e0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Client_InteractClickPickTarget
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

void __thiscall Named_CalleeOf_Client_InteractClickPickTarget_004f3640(int param_1,int param_2,char param_3)



{

  if ((*(int *)(param_1 + 0x284) != 0) &&

     ((param_3 != '\0' || (*(int *)(*(int *)(param_1 + 0x284) + 0x10) != param_2)))) {

    FUN_005a53e0(1);

    *(int *)(*(int *)(param_1 + 0x284) + 0x10) = param_2;

  }

  return;

}
