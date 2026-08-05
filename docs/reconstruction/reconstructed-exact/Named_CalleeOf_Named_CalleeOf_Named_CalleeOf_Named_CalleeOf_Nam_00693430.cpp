// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00693430
// -----------------------------------------------------------------------------
// Stable ID: aa_00693430
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x00693430  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: return×2, if×1, do×1, while×1.
//  - Notable callees: FUN_00691d80, FUN_00693430.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
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

int Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00693430(int param_1,int param_2,int param_3)



{

  if (param_1 == param_2) {

    return param_3;

  }

  do {

    FUN_00691d80(param_1);

    *(uint32_t /* width from decompiler */ *)(param_3 + 0x10) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x10);

    *(uint32_t /* width from decompiler */ *)(param_3 + 0x14) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x14);

    *(uint8_t *)(param_3 + 0x18) = *(uint8_t *)(param_1 + 0x18);

    *(uint32_t /* width from decompiler */ *)(param_3 + 0x1c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c);

    *(uint32_t /* width from decompiler */ *)(param_3 + 0x20) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x20);

    *(uint32_t /* width from decompiler */ *)(param_3 + 0x24) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x24);

    *(uint32_t /* width from decompiler */ *)(param_3 + 0x28) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x28);

    *(uint32_t /* width from decompiler */ *)(param_3 + 0x2c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c);

    param_1 = param_1 + 0x30;

    param_3 = param_3 + 0x30;

  } while (param_1 != param_2);

  return param_3;

}
