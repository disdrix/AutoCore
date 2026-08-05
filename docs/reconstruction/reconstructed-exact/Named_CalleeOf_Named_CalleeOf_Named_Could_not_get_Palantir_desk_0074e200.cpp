// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_Could_not_get_Palantir_desk_0074e200
// -----------------------------------------------------------------------------
// Stable ID: aa_0074e200
// Callee of Named_CalleeOf_Named_Could_not_get_Palantir_desktop_window
// Address:   0x0074e200  (autoassault.exe, image base 0x400000)
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
//  - Notable callees: FUN_0074e200.
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_Could_not_get_Palantir_desk_0074e200(int param_1,char param_2)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 0x3c);

  if (iVar1 != 0) {

    if ((param_2 != '\0') && (*(char *)(DAT_00d1f048 + 0xf) != '\0')) {

      *(int *)(iVar1 + 0xdc) = *(int *)(iVar1 + 0xdc) + 1;

      *(uint8_t *)(iVar1 + 0xd1) = 1;

      return;

    }

    *(int *)(iVar1 + 0xdc) = *(int *)(iVar1 + 0xdc) + 1;

    *(uint8_t *)(iVar1 + 0xd1) = 0;

  }

  return;

}
