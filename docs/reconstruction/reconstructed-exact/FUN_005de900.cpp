// =============================================================================
// FUN_005de900
// -----------------------------------------------------------------------------
// Stable ID: aa_005de900
// Address:   0x005de900  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005de900 @ 0x005de900
// Stable ID: aa_005de900
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~168 non-empty decompiler lines.
//  - Control keywords: if×32, do×3, while×3, return×1.
//  - Notable callees: FUN_005a4e40, FUN_005de900.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ * __fastcall FUN_005de900(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  int iVar3;

  int *piVar4;

  

  param_1[1] = 1;

  param_1[5] = 0xffffffff;

  param_1[2] = 0;

  param_1[3] = 0;

  param_1[4] = 0;

  *param_1 = &PTR_LAB_009db9e0;

  param_1[0xbb] = 0;

  param_1[0xbc] = 0;

  param_1[0xbd] = 0;

  param_1[0xbe] = 0;

  param_1[0xbf] = 0;

  param_1[0xc0] = 0;

  param_1[0xc1] = 0;

  param_1[0xc2] = 0;

  param_1[0xc3] = 0;

  param_1[0xc4] = 0;

  param_1[0xc5] = 0;

  param_1[0xc6] = 0;

  param_1[199] = 0;

  param_1[200] = 0;

  param_1[0xc9] = 0;

  param_1[0xca] = 0;

  param_1[0xcb] = 0;

  param_1[7] = 0;

  param_1[8] = 0;

  param_1[9] = 0;

  param_1[6] = 0;

  puVar1 = param_1 + 0x1a;

  iVar3 = 0x11;

  do {

    *puVar1 = 0;

    puVar1 = puVar1 + -1;

    iVar3 = iVar3 + -1;

  } while (iVar3 != 0);

  iVar3 = 0;

  do {

    if (iVar3 < 9) {

      iVar2 = 1;

    }

    else if (iVar3 < 0x11) {

      iVar2 = 2;

    }

    else if (iVar3 < 0x21) {

      iVar2 = 3;

    }

    else if (iVar3 < 0x31) {

      iVar2 = 4;

    }

    else if (iVar3 < 0x41) {

      iVar2 = 5;

    }

    else if (iVar3 < 0x61) {

      iVar2 = 6;

    }

    else if (iVar3 < 0x81) {

      iVar2 = 7;

    }

    else if (iVar3 < 0xa1) {

      iVar2 = 8;

    }

    else if (iVar3 < 0xc1) {

      iVar2 = 9;

    }

    else if (iVar3 < 0x101) {

      iVar2 = 10;

    }

    else if (iVar3 < 0x141) {

      iVar2 = 0xb;

    }

    else if (iVar3 < 0x201) {

      iVar2 = 0xc;

    }

    else if (iVar3 < 0x401) {

      iVar2 = 0xd;

    }

    else if (iVar3 < 0x801) {

      iVar2 = 0xe;

    }

    else if (iVar3 < 0x1001) {

      iVar2 = 0xf;

    }

    else if (iVar3 < 0x2001) {

      iVar2 = 0x10;

    }

    else {

      _DAT_00000000 = 0;

      iVar2 = -1;

    }

    *(char *)((int)param_1 + iVar3 + 0xb0) = (char)iVar2;

    param_1[iVar2 + 0x1b] = iVar3;

    iVar3 = iVar3 + 1;

  } while (iVar3 < 0x201);

  iVar3 = 0x400;

  piVar4 = param_1 + 0xad;

  do {

    if (iVar3 < 9) {

      iVar2 = 1;

    }

    else if (iVar3 < 0x11) {

      iVar2 = 2;

    }

    else if (iVar3 < 0x21) {

      iVar2 = 3;

    }

    else if (iVar3 < 0x31) {

      iVar2 = 4;

    }

    else if (iVar3 < 0x41) {

      iVar2 = 5;

    }

    else if (iVar3 < 0x61) {

      iVar2 = 6;

    }

    else if (iVar3 < 0x81) {

      iVar2 = 7;

    }

    else if (iVar3 < 0xa1) {

      iVar2 = 8;

    }

    else if (iVar3 < 0xc1) {

      iVar2 = 9;

    }

    else if (iVar3 < 0x101) {

      iVar2 = 10;

    }

    else if (iVar3 < 0x141) {

      iVar2 = 0xb;

    }

    else if (iVar3 < 0x201) {

      iVar2 = 0xc;

    }

    else if (iVar3 < 0x401) {

      iVar2 = 0xd;

    }

    else if (iVar3 < 0x801) {

      iVar2 = 0xe;

    }

    else if (iVar3 < 0x1001) {

      iVar2 = 0xf;

    }

    else if (iVar3 < 0x2001) {

      iVar2 = 0x10;

    }

    else {

      _DAT_00000000 = 0;

      iVar2 = -1;

    }

    *piVar4 = iVar2;

    param_1[iVar2 + 0x1b] = iVar3;

    iVar3 = iVar3 + 0x400;

    piVar4 = piVar4 + 1;

  } while (iVar3 < 0x2400);

  param_1[0xb5] = 0;

  param_1[0xb6] = 0;

  param_1[0xb7] = 0;

  param_1[0xb8] = 0;

  param_1[0xb9] = 0x2000;

  param_1[0xba] = 0x40;

  FUN_005a4e40((int)param_1 + 0x33fU & 0xfffffff0,0x4000);

  return param_1;

}
