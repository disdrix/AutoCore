// =============================================================================
// FUN_00627be0
// -----------------------------------------------------------------------------
// Stable ID: aa_00627be0
// Address:   0x00627be0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00627be0 @ 0x00627be0
// Stable ID: aa_00627be0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~100 non-empty decompiler lines.
//  - Control keywords: if×15, while×5, do×4, return×1, goto×1.
//  - Notable callees: FUN_00627be0.
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

uint __fastcall FUN_00627be0(int param_1)



{

  int iVar1;

  short *psVar2;

  float *pfVar3;

  uint uVar4;

  

  uVar4 = 0;

  iVar1 = 0;

  psVar2 = (short *)(param_1 + 0x60);

  do {

    if (*psVar2 != 0) {

      uVar4 = 1;

      break;

    }

    iVar1 = iVar1 + 1;

    psVar2 = psVar2 + 1;

  } while (iVar1 < 6);

  iVar1 = 0;

  psVar2 = (short *)(param_1 + 0x6c);

  do {

    if (*psVar2 != 0) {

      uVar4 = uVar4 | 8;

      break;

    }

    iVar1 = iVar1 + 1;

    psVar2 = psVar2 + 1;

  } while (iVar1 < 6);

  iVar1 = 0;

  pfVar3 = (float *)(param_1 + 0xa8);

  do {

    if (*pfVar3 != 0.0) {

      uVar4 = uVar4 | 0x80;

      break;

    }

    iVar1 = iVar1 + 1;

    pfVar3 = pfVar3 + 1;

  } while (iVar1 < 6);

  iVar1 = 0;

  psVar2 = (short *)(param_1 + 0x78);

  do {

    if ((psVar2[0xc] != 0) || (*psVar2 != 0)) {

      uVar4 = uVar4 | 0x100;

      break;

    }

    iVar1 = iVar1 + 1;

    psVar2 = psVar2 + 1;

  } while (iVar1 < 6);

  iVar1 = 0;

  psVar2 = (short *)(param_1 + 0x84);

  while ((psVar2[0xc] == 0 && (*psVar2 == 0))) {

    iVar1 = iVar1 + 1;

    psVar2 = psVar2 + 1;

    if (5 < iVar1) {

LAB_00627c98:

      if ((((((*(float *)(param_1 + 0x4c) != 0.0) || (*(float *)(param_1 + 0xc4) != 0.0)) ||

            (*(float *)(param_1 + 0xc0) != 0.0)) ||

           ((*(float *)(param_1 + 0xcc) != 0.0 || (*(float *)(param_1 + 200) != 0.0)))) ||

          (*(float *)(param_1 + 0x44) != 0.0)) ||

         (((*(float *)(param_1 + 0x48) != 0.0 || (*(float *)(param_1 + 0x24) != 0.0)) ||

          ((*(float *)(param_1 + 0xf8) != 0.0 ||

           (((*(float *)(param_1 + 0xfc) != 0.0 || (*(float *)(param_1 + 0x104) != 0.0)) ||

            (*(float *)(param_1 + 0x100) != 0.0)))))))) {

        uVar4 = uVar4 | 0x400;

      }

      if (((*(short *)(param_1 + 0xd0) != 0) || (*(short *)(param_1 + 0xd2) != 0)) ||

         ((*(short *)(param_1 + 0xd4) != 0 ||

          ((*(short *)(param_1 + 0xd6) != 0 || (*(short *)(param_1 + 0xd8) != 0)))))) {

        uVar4 = uVar4 | 0x40;

      }

      if ((*(float *)(param_1 + 0x38) != 0.0) || (*(float *)(param_1 + 0x13c) != 0.0)) {

        uVar4 = uVar4 | 0x20;

      }

      if (*(char *)(param_1 + 0xda) != '\0') {

        uVar4 = uVar4 | 0x10;

      }

      if (*(float *)(param_1 + 0x3c) != 0.0) {

        uVar4 = uVar4 | 2;

      }

      if (*(float *)(param_1 + 0x40) != 0.0) {

        uVar4 = uVar4 | 0x8000;

      }

      if ((((*(float *)(param_1 + 0x110) != 0.0) || (*(float *)(param_1 + 0x114) != 0.0)) ||

          (*(float *)(param_1 + 0x118) != 0.0)) || (*(float *)(param_1 + 0x10c) != 0.0)) {

        uVar4 = uVar4 | 0x10000;

      }

      if ((*(float *)(param_1 + 0x124) != 0.0) || (*(float *)(param_1 + 0x128) != 0.0)) {

        uVar4 = uVar4 | 0x20000;

      }

      if ((*(float *)(param_1 + 300) != 0.0) || (*(float *)(param_1 + 0x130) != 0.0)) {

        uVar4 = uVar4 | 0x400;

      }

      if ((*(int *)(param_1 + 0x134) != 0) && (*(float *)(param_1 + 0x138) != 0.0)) {

        uVar4 = uVar4 | 0x20000;

      }

      return *(uint *)(param_1 + 0xc) | uVar4;

    }

  }

  uVar4 = uVar4 | 0x200;

  goto LAB_00627c98;

}
