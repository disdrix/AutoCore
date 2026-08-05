// =============================================================================
// FUN_00563a30
// -----------------------------------------------------------------------------
// Stable ID: aa_00563a30
// Address:   0x00563a30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00563a30 @ 0x00563a30
// Stable ID: aa_00563a30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00563a30, FUN_00566f00.
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

void __thiscall FUN_00563a30(uint32_t /* width from decompiler */ param_1,int param_2)



{

  int iVar1;

  

  if (param_2 == 0) {

    iVar1 = 0;

  }

  else {

    iVar1 = *(int *)(*(int *)(param_2 + 4) + 4) + 4 + param_2;

  }

  FUN_00566f00(iVar1);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x280) = param_1;

  return;

}
