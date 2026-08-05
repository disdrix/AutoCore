// =============================================================================
// FUN_005994e0
// -----------------------------------------------------------------------------
// Stable ID: aa_005994e0
// Address:   0x005994e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005994e0 @ 0x005994e0
// Stable ID: aa_005994e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_005070b0, FUN_005070d0, FUN_005994e0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall FUN_005994e0(int param_1,uint32_t /* width from decompiler */ param_2)



{

  char *pcVar1;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = param_1;

  pcVar1 = (char *)FUN_005070b0((int)&uStack_4 + 3);

  if ((*pcVar1 == '\0') && (*(int *)(param_1 + 0x44) != 0)) {

    FUN_005070d0();

  }

  (**(code **)(**(int **)(param_1 + 0x3c) + 100))(param_2);

  return;

}
