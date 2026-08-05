// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004663d0
// -----------------------------------------------------------------------------
// Stable ID: aa_004663d0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxAdapter
// Address:   0x004663d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxAdapter: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: for×1, return×1.
//  - Notable callees: FUN_004661e0, FUN_004663d0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxAdapter
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

uint8_t * __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004663d0(int param_1)



{

  uint8_t *in_EAX;

  int unaff_EBX;

  

  for (; unaff_EBX != param_1; param_1 = param_1 + -0x24) {

    in_EAX[-0x24] = *(uint8_t *)(param_1 + -0x24);

    *(uint32_t /* width from decompiler */ *)(in_EAX + -0x20) = *(uint32_t /* width from decompiler */ *)(param_1 + -0x20);

    *(uint32_t /* width from decompiler */ *)(in_EAX + -0x1c) = *(uint32_t /* width from decompiler */ *)(param_1 + -0x1c);

    *(uint32_t /* width from decompiler */ *)(in_EAX + -0x18) = *(uint32_t /* width from decompiler */ *)(param_1 + -0x18);

    in_EAX[-0x14] = *(uint8_t *)(param_1 + -0x14);

    in_EAX[-0x13] = *(uint8_t *)(param_1 + -0x13);

    FUN_004661e0();

    in_EAX = in_EAX + -0x24;

  }

  return in_EAX;

}
