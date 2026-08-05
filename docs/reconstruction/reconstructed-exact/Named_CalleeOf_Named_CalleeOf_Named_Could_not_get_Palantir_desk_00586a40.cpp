// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_Could_not_get_Palantir_desk_00586a40
// -----------------------------------------------------------------------------
// Stable ID: aa_00586a40
// Callee of Named_CalleeOf_Named_Could_not_get_Palantir_desktop_window
// Address:   0x00586a40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_Could_not_get_Palantir_desktop_window: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_007567b0×2, FUN_00586a40, FUN_0075bf40.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_Could_not_get_Palantir_desktop_window
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_Could_not_get_Palantir_desk_00586a40(int param_1,char param_2)



{

  if (*(char *)(param_1 + 0x10) != param_2) {

    if (param_2 != '\0') {

      FUN_0075bf40(0);

      FUN_007567b0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x38),1);

      *(char *)(param_1 + 0x10) = param_2;

      return;

    }

    FUN_007567b0(0,1);

    *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x3c) + 0xc0) = 7;

    *(uint8_t *)(param_1 + 0x10) = 0;

  }

  return;

}
