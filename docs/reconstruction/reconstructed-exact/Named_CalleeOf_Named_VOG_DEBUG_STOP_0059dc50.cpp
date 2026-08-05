// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_0059dc50
// -----------------------------------------------------------------------------
// Stable ID: aa_0059dc50
// Callee of Named_VOG_DEBUG_STOP (+1 other named callers)
// Address:   0x0059dc50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_VOG_DEBUG_STOP (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_0059db80, FUN_0059dc50.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP (+1 other named callers)
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_VOG_DEBUG_STOP_0059dc50(int param_1,int param_2)



{

  int iVar1;

  

  if ((param_2 == 0) ||

     (((*(short *)(*(int *)(param_1 + 0x14c) + 0xf8) != 0 && (*(char *)(param_1 + 0x14) == '\0')) ||

      (iVar1 = FUN_0059db80(param_2), iVar1 == -1)))) {

    return 0;

  }

  if (((0xdfc < **(int **)(param_1 + 0x14c)) && (**(int **)(param_1 + 0x14c) < 0xe03)) &&

     (iVar1 = (**(code **)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 4 + param_2) + 0x27c))(),

     iVar1 < 5)) {

    return 0;

  }

  return 1;

}
