// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0043b610
// -----------------------------------------------------------------------------
// Stable ID: aa_0043b610
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxLODHandle
// Address:   0x0043b610  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxLODHandle: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: for×1, return×1.
//  - Notable callees: FUN_0043a090×2, FUN_0043b610.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxLODHandle
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

int __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0043b610(int param_1)



{

  int in_EAX;

  int unaff_EBX;

  

  for (; unaff_EBX != param_1; param_1 = param_1 + -0x28) {

    FUN_0043a090();

    FUN_0043a090();

    *(uint32_t /* width from decompiler */ *)(in_EAX + -8) = *(uint32_t /* width from decompiler */ *)(param_1 + -8);

    *(uint32_t /* width from decompiler */ *)(in_EAX + -4) = *(uint32_t /* width from decompiler */ *)(param_1 + -4);

    in_EAX = in_EAX + -0x28;

  }

  return in_EAX;

}
