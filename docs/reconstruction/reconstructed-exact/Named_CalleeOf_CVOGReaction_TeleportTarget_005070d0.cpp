// =============================================================================
// Named_CalleeOf_CVOGReaction_TeleportTarget_005070d0
// -----------------------------------------------------------------------------
// Stable ID: aa_005070d0
// Callee of CVOGReaction_TeleportTarget (+3 other named callers)
// Address:   0x005070d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGReaction_TeleportTarget: spawn/transfer helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. CVOGReaction_TeleportTarget (+3 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_005070d0, FUN_0055e490, FUN_0055eb80.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of CVOGReaction_TeleportTarget (+3 other named callers)
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

void __fastcall Named_CalleeOf_CVOGReaction_TeleportTarget_005070d0(int param_1)



{

  int iVar1;

  

  if (*(int *)(param_1 + 8) != 0) {

    FUN_0055e490(param_1);

    iVar1 = *(int *)(param_1 + 0x44);

    if ((*(char *)(iVar1 + 0x29) == '\0') && (*(int *)(iVar1 + 0x24) != -1)) {

      FUN_0055eb80(iVar1);

    }

  }

  return;

}
