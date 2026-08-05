// =============================================================================
// FUN_007481a0
// -----------------------------------------------------------------------------
// Stable ID: aa_007481a0
// Address:   0x007481a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007481a0 @ 0x007481a0
// Stable ID: aa_007481a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_007481a0.
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

void __thiscall FUN_007481a0(int *param_1,int *param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  (**(code **)(*param_1 + 0x24))(param_2 + 0x26);

  if (param_1[0x16] == 0) {

    iVar1 = (**(code **)(*param_2 + 0xc))();

    param_1[0x19] = iVar1;

  }

  else {

    (**(code **)(*param_1 + 0x80))();

  }

  iVar1 = *param_1;

  uVar2 = (**(code **)(*param_2 + 100))();

  (**(code **)(iVar1 + 0x34))(uVar2);

  return;

}
