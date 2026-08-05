// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_007b7df0
// -----------------------------------------------------------------------------
// Stable ID: aa_007b7df0
// Callee of Named_VOG_DEBUG_STOP (+3 other named callers)
// Address:   0x007b7df0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_VOG_DEBUG_STOP (+3 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_007b7df0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP (+3 other named callers)
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

uint32_t /* width from decompiler */ __fastcall Named_CalleeOf_Named_VOG_DEBUG_STOP_007b7df0(uint8_t *param_1)



{

  int *piVar1;

  

  piVar1 = (int *)(param_1 + 0x20);

  *piVar1 = *piVar1 + -1;

  if ((*piVar1 == 0) && (DAT_00d1793c == '\0')) {

    piVar1 = *(int **)(param_1 + 0x28);

    if (piVar1 != (int *)0x0) {

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = 0;

      (**(code **)(*piVar1 + 8))(piVar1);

    }

    piVar1 = *(int **)(param_1 + 0x24);

    if (piVar1 != (int *)0x0) {

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = 0;

      (**(code **)(*piVar1 + 8))(piVar1);

    }

    *param_1 = 0;

  }

  return 0;

}
