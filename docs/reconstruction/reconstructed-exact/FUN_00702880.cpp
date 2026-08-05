// =============================================================================
// FUN_00702880
// -----------------------------------------------------------------------------
// Stable ID: aa_00702880
// Address:   0x00702880  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00702880 @ 0x00702880
// Stable ID: aa_00702880
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: do×1, while×1, return×1.
//  - Notable callees: FUN_00702880, FUN_00703130.
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

void FUN_00702880(int *param_1)



{

  int iVar1;

  

  iVar1 = FUN_00703130(2000);

  *param_1 = iVar1;

  param_1[6] = 2000;

  iVar1 = 0;

  do {

    *(uint8_t *)(iVar1 + *param_1) = 0;

    iVar1 = iVar1 + 1;

  } while (iVar1 < param_1[6]);

  param_1[1] = 0;

  param_1[2] = 0;

  param_1[3] = 0;

  param_1[4] = 1;

  param_1[5] = 0;

  return;

}
