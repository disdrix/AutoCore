// =============================================================================
// FUN_00656150
// -----------------------------------------------------------------------------
// Stable ID: aa_00656150
// Address:   0x00656150  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00656150 @ 0x00656150
// Stable ID: aa_00656150
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×2, do×2, while×2, return×1.
//  - Notable callees: FUN_00641900×5, FUN_00641940, FUN_00656150.
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

void FUN_00656150(int *param_1)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  

  piVar1 = param_1;

  iVar2 = param_1[1];

  FUN_00641900(iVar2);

  if (0 < iVar2) {

    iVar3 = 0;

    do {

      FUN_00641940(*param_1 + iVar3,3);

      iVar3 = iVar3 + 0x10;

      iVar2 = iVar2 + -1;

    } while (iVar2 != 0);

  }

  param_1 = (int *)param_1[4];

  FUN_00641900(param_1);

  if (0 < (int)param_1) {

    iVar2 = 0;

    do {

      iVar3 = piVar1[3] + iVar2;

      FUN_00641900(*(uint32_t /* width from decompiler */ *)(piVar1[3] + iVar2));

      FUN_00641900(*(uint32_t /* width from decompiler */ *)(iVar3 + 4));

      FUN_00641900(*(uint32_t /* width from decompiler */ *)(iVar3 + 8));

      iVar2 = iVar2 + 0xc;

      param_1 = (int *)((int)param_1 + -1);

    } while (param_1 != (int *)0x0);

  }

  return;

}
