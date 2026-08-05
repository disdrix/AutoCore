// =============================================================================
// FUN_00702ea0
// -----------------------------------------------------------------------------
// Stable ID: aa_00702ea0
// Address:   0x00702ea0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00702ea0 @ 0x00702ea0
// Stable ID: aa_00702ea0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_00702e60, FUN_00702ea0.
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

void FUN_00702ea0(int *param_1,int param_2,int param_3)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  

  iVar4 = param_1[3];

  iVar1 = param_1[2];

  iVar2 = param_1[1];

  FUN_00702e60(param_1);

  iVar3 = iVar2 + 7 >> 3;

  param_1[3] = iVar4;

  param_1[2] = iVar1;

  param_1[1] = iVar2;

  if (iVar3 < param_3) {

    param_3 = iVar3;

  }

  if (0 < param_3) {

    iVar4 = 0;

    do {

      *(uint8_t *)(iVar4 + param_2) = *(uint8_t *)(iVar4 + *param_1);

      iVar4 = iVar4 + 1;

    } while (iVar4 < param_3);

  }

  return;

}
