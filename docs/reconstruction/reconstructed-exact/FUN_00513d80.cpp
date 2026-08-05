// =============================================================================
// FUN_00513d80
// -----------------------------------------------------------------------------
// Stable ID: aa_00513d80
// Address:   0x00513d80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00513d80 @ 0x00513d80
// Stable ID: aa_00513d80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00513d80.
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

void __thiscall FUN_00513d80(int *param_1,uint32_t /* width from decompiler */ *param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  

  *param_2 = 0x2007;

  param_2[0xc] = param_1[0x2d];

  *(char *)(param_2 + 4) = (char)param_1[0x5a];

  param_2[2] = param_1[0x58];

  param_2[3] = param_1[0x59];

  uVar1 = (**(code **)(*param_1 + 0x23c))();

  param_2[6] = uVar1;

  uVar1 = (**(code **)(*param_1 + 0x244))();

  param_2[7] = uVar1;

  return;

}
