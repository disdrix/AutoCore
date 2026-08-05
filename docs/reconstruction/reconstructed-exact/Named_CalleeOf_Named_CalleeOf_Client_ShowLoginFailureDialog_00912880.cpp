// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_ShowLoginFailureDialog_00912880
// -----------------------------------------------------------------------------
// Stable ID: aa_00912880
// Callee of Named_CalleeOf_Client_ShowLoginFailureDialog
// Address:   0x00912880  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_ShowLoginFailureDialog: auth/session helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: return×5, switch×1.
//  - Notable callees: FUN_00912880.
//  - Return sites: 5.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_ShowLoginFailureDialog
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

uint32_t /* width from decompiler */ __fastcall Named_CalleeOf_Named_CalleeOf_Client_ShowLoginFailureDialog_00912880(uint32_t /* width from decompiler */ param_1)



{

  int in_EAX;

  

  switch(param_1) {

  case 0:

    return *(uint32_t /* width from decompiler */ *)(in_EAX + 0xa74);

  case 1:

    return *(uint32_t /* width from decompiler */ *)(in_EAX + 0xa78);

  case 2:

    return *(uint32_t /* width from decompiler */ *)(in_EAX + 0xa7c);

  case 3:

    return *(uint32_t /* width from decompiler */ *)(in_EAX + 0xa80);

  default:

    return 0;

  }

}
