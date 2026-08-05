// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_00404dc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00404dc0
// Callee of Named_VOG_DEBUG_STOP (+4 other named callers)
// Address:   0x00404dc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_VOG_DEBUG_STOP (+4 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00404dc0, FUN_005070b0, FUN_005070d0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP (+4 other named callers)
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

void __thiscall Named_CalleeOf_Named_VOG_DEBUG_STOP_00404dc0(int param_1,uint32_t /* width from decompiler */ param_2)



{

  char *pcVar1;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = param_1;

  pcVar1 = (char *)FUN_005070b0((int)&uStack_4 + 3);

  if ((*pcVar1 == '\0') && (*(int *)(param_1 + 0x44) != 0)) {

    FUN_005070d0();

  }

  if ((*(char *)(param_1 + 0x40) == '\0') || (*(int *)(param_1 + 8) == 0)) {

    (**(code **)(**(int **)(param_1 + 0x3c) + 0x44))(param_2);

  }

  return;

}
