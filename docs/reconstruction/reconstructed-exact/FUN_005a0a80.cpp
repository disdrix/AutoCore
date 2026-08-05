// =============================================================================
// FUN_005a0a80
// -----------------------------------------------------------------------------
// Stable ID: aa_005a0a80
// Address:   0x005a0a80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005a0a80 @ 0x005a0a80
// Stable ID: aa_005a0a80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_005a0540, FUN_005a0a80, ROUND.
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

void FUN_005a0a80(uint32_t /* width from decompiler */ param_1,int *param_2)



{

  int iVar1;

  

  iVar1 = FUN_005a0540(param_1,0);

  if (iVar1 != 0) {

    *param_2 = (int)ROUND(*(float *)(iVar1 + 0xbc));

    param_2[1] = *(int *)(*(int *)(iVar1 + 0x1a8) + 0x78) - *(int *)(iVar1 + 0x118);

    param_2[2] = *(int *)(iVar1 + 0x204) + *(int *)(iVar1 + 0x11c);

  }

  return;

}
