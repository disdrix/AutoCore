// =============================================================================
// FUN_004d3310
// -----------------------------------------------------------------------------
// Stable ID: aa_004d3310
// Address:   0x004d3310  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004d3310 @ 0x004d3310
// Stable ID: aa_004d3310
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_004d28c0, FUN_004d3310.
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

int __thiscall FUN_004d3310(int param_1,int param_2,char param_3)



{

  int *piVar1;

  uint uVar2;

  

  *(int *)(param_1 + 0xe818) = *(int *)(param_1 + 0xe818) + -1;

  if (param_3 != '\0') {

    FUN_004d28c0(*(int *)(param_1 + 0xe818) + 1,*(int *)(param_1 + 0xe818));

  }

  uVar2 = (uint)*(byte *)(*(int *)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 0xac + param_2) +

                                  0x3c) + 0x532);

  piVar1 = (int *)(param_1 + 0xe81c + uVar2 * 4);

  *piVar1 = *piVar1 + -1;

  return param_1 + 0xe81c + uVar2 * 4;

}
