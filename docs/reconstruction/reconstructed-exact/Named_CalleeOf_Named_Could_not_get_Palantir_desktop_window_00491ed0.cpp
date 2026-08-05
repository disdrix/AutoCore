// =============================================================================
// Named_CalleeOf_Named_Could_not_get_Palantir_desktop_window_00491ed0
// -----------------------------------------------------------------------------
// Stable ID: aa_00491ed0
// Callee of Named_Could_not_get_Palantir_desktop_window
// Address:   0x00491ed0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Could_not_get_Palantir_desktop_window: callee helper. Evidence string: "v2NormalMapExtents". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "v2NormalMapExtents"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00491ed0, FUN_00493550, FUN_007a2580.
//  - Strings: "v2NormalMapExtents".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_Could_not_get_Palantir_desktop_window
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

void __fastcall Named_CalleeOf_Named_Could_not_get_Palantir_desktop_window_00491ed0(int param_1)



{

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  if (*(int *)(param_1 + 200) != 0) {

    FUN_007a2580(*(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 0xb8) + 0xe894) + 0xdc),

                 *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 200) + 0x8c));

    local_8 = *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 200) + 0x90) + 0x188);

    local_4 = *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 200) + 0x90) + 0x18c);

    FUN_00493550("v2NormalMapExtents",&local_8);

  }

  return;

}
