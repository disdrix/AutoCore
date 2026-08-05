// =============================================================================
// Named_CalleeOf_CVOGHBAIDriver_DoLogic_00540890
// -----------------------------------------------------------------------------
// Stable ID: aa_00540890
// Callee of CVOGHBAIDriver_DoLogic
// Address:   0x00540890  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGHBAIDriver_DoLogic: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00540890, FUN_005436c0, FUN_007c3b80.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of CVOGHBAIDriver_DoLogic
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

int __thiscall Named_CalleeOf_CVOGHBAIDriver_DoLogic_00540890(int param_1,char param_2)



{

  if ((*(int *)(param_1 + 0xf08) == 0) || (param_2 != '\0')) {

    FUN_005436c0(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xf04) + 4));

    *(int *)(*(int *)(param_1 + 0xf04) + 4) = *(int *)(param_1 + 0xf04);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xf08) = 0;

    *(uint32_t /* width from decompiler */ *)*(uint32_t /* width from decompiler */ *)(param_1 + 0xf04) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xf04);

    *(int *)(*(int *)(param_1 + 0xf04) + 8) = *(int *)(param_1 + 0xf04);

    FUN_007c3b80(param_1 + 0xf00);

  }

  return param_1 + 0xf00;

}
