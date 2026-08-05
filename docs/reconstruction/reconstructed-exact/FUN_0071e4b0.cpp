// =============================================================================
// FUN_0071e4b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0071e4b0
// Address:   0x0071e4b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0071e4b0 @ 0x0071e4b0
// Stable ID: aa_0071e4b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×4, do×2, while×2, return×2.
//  - Notable callees: FUN_00435f30×2, FUN_00769160×2, FUN_00437050, FUN_0044cb80, FUN_0071e4b0, FUN_007689e0, FUN_00768ee0.
//  - Return sites: 2.

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

uint32_t /* width from decompiler */ __thiscall FUN_0071e4b0(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  

  iVar2 = param_1 + 0x10;

  if (*(int *)(param_2 + 0x4044) == 0) {

    FUN_00435f30(iVar2,0xe);

  }

  else {

    iVar1 = 0xe;

    do {

      FUN_00769160(iVar2);

      iVar2 = iVar2 + 1;

      iVar1 = iVar1 + -1;

    } while (iVar1 != 0);

  }

  iVar2 = param_1 + 0x1e;

  if (*(int *)(param_2 + 0x4044) == 0) {

    FUN_00435f30(iVar2,0x10);

  }

  else {

    iVar1 = 0x10;

    do {

      FUN_00769160(iVar2);

      iVar2 = iVar2 + 1;

      iVar1 = iVar1 + -1;

    } while (iVar1 != 0);

  }

  if (*(int *)(param_2 + 0x4044) == 0) {

    FUN_00437050(param_1 + 0x30);

  }

  else {

    FUN_007689e0(param_1 + 0x30);

  }

  if (*(int *)(param_2 + 0x4044) == 0) {

    FUN_0044cb80(param_1 + 0x34);

    return 0;

  }

  FUN_00768ee0(param_1 + 0x34);

  return 0;

}
