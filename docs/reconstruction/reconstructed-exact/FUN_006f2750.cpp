// =============================================================================
// FUN_006f2750
// -----------------------------------------------------------------------------
// Stable ID: aa_006f2750
// Address:   0x006f2750  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f2750 @ 0x006f2750
// Stable ID: aa_006f2750
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: if×5, return×3.
//  - Notable callees: FUN_006f39a0×14, FUN_006f2130×4, FUN_006f2750.
//  - Return sites: 3.

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

void __thiscall

FUN_006f2750(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)



{

  int iVar1;

  uint uVar2;

  uint uVar3;

  

  iVar1 = *(int *)(*(int *)(param_1 + 0x10) + 0xc);

  uVar3 = iVar1 - param_6;

  if (param_4 < 3) {

    uVar2 = iVar1 - param_5;

    if ((((0 < (int)uVar2) || (0xf8 < (int)uVar3)) && ((int)uVar2 < 0x10000)) &&

       ((int)uVar3 < 0x10000)) {

      FUN_006f39a0(uVar3 & 0xff);

      FUN_006f39a0(uVar3 >> 8 & 0xff);

      FUN_006f39a0(uVar2 & 0xff);

      FUN_006f39a0(uVar2 >> 8 & 0xff);

      FUN_006f39a0(param_2);

      FUN_006f39a0(param_3);

      FUN_006f39a0(param_4 + 0x23);

      return;

    }

    if (param_3 - param_2 == 1) {

      if (0xfb < (int)uVar3) {

        FUN_006f2130(param_6);

        param_6 = *(int *)(*(int *)(param_1 + 0x10) + 0xc);

      }

      FUN_006f2130(param_5);

      FUN_006f39a0(*(int *)(*(int *)(param_1 + 0x10) + 0xc) - param_6);

      FUN_006f39a0(param_2);

      FUN_006f39a0(param_4 + 0x20);

      return;

    }

  }

  if (0xfb < (int)uVar3) {

    FUN_006f2130(param_6);

    param_6 = *(int *)(*(int *)(param_1 + 0x10) + 0xc);

  }

  FUN_006f2130(param_5);

  FUN_006f39a0(*(int *)(*(int *)(param_1 + 0x10) + 0xc) - param_6);

  FUN_006f39a0(param_2);

  FUN_006f39a0(param_3);

  FUN_006f39a0(param_4 + 0x10);

  return;

}
