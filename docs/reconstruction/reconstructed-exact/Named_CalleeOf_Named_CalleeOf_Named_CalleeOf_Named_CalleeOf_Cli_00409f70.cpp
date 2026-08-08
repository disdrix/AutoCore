// RETIRED 2026-08-05 R10-023: use StdVector_PodCopyElement_0x10_Inferred.cpp / FUN_00409f70.cpp
// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_00409f70
// -----------------------------------------------------------------------------
// Stable ID: aa_00409f70
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_Input_PollB
// Address:   0x00409f70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_Input_PollB: input/binding helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: ifÃ—1, returnÃ—1.
//  - Notable callees: FUN_00409f70.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_Input_PollB
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_00409f70(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ *in_EAX;

  

  if (in_EAX != (uint32_t /* width from decompiler */ *)0x0) {

    *in_EAX = *param_1;

    in_EAX[1] = param_1[1];

    in_EAX[2] = param_1[2];

    in_EAX[3] = param_1[3];

  }

  return;

}
