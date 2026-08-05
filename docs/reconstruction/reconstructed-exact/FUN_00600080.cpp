// =============================================================================
// FUN_00600080
// -----------------------------------------------------------------------------
// Stable ID: aa_00600080
// Address:   0x00600080  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00600080 @ 0x00600080
// Stable ID: aa_00600080
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: while×1, if×1, return×1.
//  - Notable callees: FUN_005fff20, FUN_00600080.
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

void FUN_00600080(int param_1,int param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  

  *(int *)(param_2 + 0x10) = param_1;

  iVar1 = *(int *)(param_1 + 100);

  while (iVar1 = iVar1 + -1, -1 < iVar1) {

    puVar2 = *(uint32_t /* width from decompiler */ **)(*(int *)(param_1 + 0x60) + iVar1 * 4);

    if (puVar2 != (uint32_t /* width from decompiler */ *)0x0) {

      (**(code **)*puVar2)(param_2);

    }

  }

  FUN_005fff20();

  return;

}
