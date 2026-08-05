// =============================================================================
// FUN_00471820
// -----------------------------------------------------------------------------
// Stable ID: aa_00471820
// Address:   0x00471820  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00471820 @ 0x00471820
// Stable ID: aa_00471820
// Embedded strings (evidence for future rename):
//   - "NULL row buffer for row %ld, pass %d"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~124 non-empty decompiler lines.
//  - Control keywords: if×30, return×5, for×1.
//  - Notable callees: FUN_00476cc0×3, FUN_004724f0×2, CONCAT31, FUN_00471820, FUN_00471c40, FUN_00471d70, FUN_00471f50, FUN_00471fa0.
//  - Strings: "NULL row buffer for row %ld, pass %d".
//  - Return sites: 5.

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

void FUN_00471820(int param_1)



{

  byte bVar1;

  int iVar2;

  uint uVar3;

  int iVar4;

  char local_34 [52];

  

  if (*(int *)(param_1 + 0xec) == 0) {

    sprintf(local_34,"NULL row buffer for row %ld, pass %d",*(uint32_t /* width from decompiler */ *)(param_1 + 0xe4),

            (uint)*(byte *)(param_1 + 0x124));

                    /* WARNING: Subroutine does not return */

    FUN_00476cc0(param_1);

  }

  if ((*(byte *)(param_1 + 0x71) & 0x10) != 0) {

    iVar2 = *(int *)(param_1 + 0xec) + 1;

    if (*(char *)(param_1 + 0x108) == '\x03') {

      FUN_00474030(param_1 + 0x100,iVar2,*(uint32_t /* width from decompiler */ *)(param_1 + 0x114),

                   *(uint32_t /* width from decompiler */ *)(param_1 + 0x188),*(uint16_t *)(param_1 + 0x11a));

    }

    else {

      if (*(short *)(param_1 + 0x11a) == 0) {

        iVar4 = 0;

      }

      else {

        iVar4 = param_1 + 0x18c;

      }

      FUN_00474280(param_1 + 0x100,iVar2,iVar4);

    }

  }

  uVar3 = *(uint *)(param_1 + 0x6c) & 0x400000;

  if (uVar3 != 0) {

    FUN_00477310(param_1 + 0x100,CONCAT31((int3)(uVar3 >> 8),0x80));

  }

  if ((*(byte *)(param_1 + 0x72) & 0x60) != 0) {

    iVar2 = FUN_004726a0(param_1 + 0x100,*(int *)(param_1 + 0xec) + 1);

    if (iVar2 != 0) {

      *(uint8_t *)(param_1 + 0x228) = 1;

      if (*(int *)(param_1 + 0x70) == 0x400000) {

        FUN_00476d60();

      }

      if (*(int *)(param_1 + 0x70) == 0x200000) {

                    /* WARNING: Subroutine does not return */

        FUN_00476cc0(param_1);

      }

    }

  }

  if (((*(byte *)(param_1 + 0x71) & 0x40) != 0) && ((*(byte *)(param_1 + 0x69) & 8) == 0)) {

    FUN_004724f0();

  }

  if (((*(byte *)(param_1 + 0x70) & 0x80) != 0) &&

     ((*(short *)(param_1 + 0x11a) != 0 || ((*(byte *)(param_1 + 0x126) & 4) != 0)))) {

    FUN_00472d10(param_1 + 0x100,param_1 + 0x18c,param_1 + 0x138,param_1 + 0x142,

                 *(uint32_t /* width from decompiler */ *)(param_1 + 0x164),*(uint32_t /* width from decompiler */ *)(param_1 + 0x168),

                 *(uint32_t /* width from decompiler */ *)(param_1 + 0x16c),*(uint32_t /* width from decompiler */ *)(param_1 + 0x170),

                 *(uint32_t /* width from decompiler */ *)(param_1 + 0x174),*(uint32_t /* width from decompiler */ *)(param_1 + 0x178),

                 *(uint32_t /* width from decompiler */ *)(param_1 + 0x158));

  }

  if (((*(uint *)(param_1 + 0x70) & 0x2000) != 0) &&

     (((-1 < (char)*(uint *)(param_1 + 0x70) ||

       ((*(short *)(param_1 + 0x11a) == 0 && ((*(byte *)(param_1 + 0x126) & 4) == 0)))) &&

      (*(char *)(param_1 + 0x126) != '\x03')))) {

    FUN_00473c70(param_1 + 0x100,*(int *)(param_1 + 0xec) + 1,*(uint32_t /* width from decompiler */ *)(param_1 + 0x164),

                 *(uint32_t /* width from decompiler */ *)(param_1 + 0x170),*(uint32_t /* width from decompiler */ *)(param_1 + 0x158));

  }

  if ((*(byte *)(param_1 + 0x71) & 4) != 0) {

    FUN_00471f50();

  }

  if ((*(byte *)(param_1 + 0x70) & 0x40) != 0) {

    FUN_00474670(param_1 + 0x100,*(uint32_t /* width from decompiler */ *)(param_1 + 0x1ec));

    if (*(int *)(param_1 + 0x104) == 0) {

                    /* WARNING: Subroutine does not return */

      FUN_00476cc0(param_1);

    }

  }

  if ((*(byte *)(param_1 + 0x70) & 0x20) != 0) {

    FUN_00477200();

  }

  if ((*(byte *)(param_1 + 0x70) & 8) != 0) {

    FUN_00471d70(*(int *)(param_1 + 0xec) + 1,param_1 + 0x181);

  }

  if ((*(byte *)(param_1 + 0x70) & 4) != 0) {

    FUN_00471c40(param_1 + 0x100);

  }

  if ((*(byte *)(param_1 + 0x70) & 1) != 0) {

    FUN_004775b0();

  }

  if ((*(byte *)(param_1 + 0x72) & 1) != 0) {

    FUN_004772c0();

  }

  if (((*(byte *)(param_1 + 0x71) & 0x40) != 0) && ((*(byte *)(param_1 + 0x69) & 8) != 0)) {

    FUN_004724f0();

  }

  if ((*(byte *)(param_1 + 0x71) & 0x80) != 0) {

    FUN_004721f0(param_1 + 0x100,*(uint32_t /* width from decompiler */ *)(param_1 + 0x6c));

  }

  if ((*(byte *)(param_1 + 0x72) & 8) != 0) {

    FUN_00472120();

  }

  if ((*(byte *)(param_1 + 0x72) & 2) != 0) {

    FUN_00471fa0();

  }

  if ((*(byte *)(param_1 + 0x70) & 0x10) != 0) {

    FUN_00477290();

  }

  if ((*(byte *)(param_1 + 0x72) & 0x10) != 0) {

    if (*(code **)(param_1 + 0x58) != (code *)0x0) {

      (**(code **)(param_1 + 0x58))(param_1,param_1 + 0x100,*(int *)(param_1 + 0xec) + 1);

    }

    if (*(char *)(param_1 + 100) != '\0') {

      *(char *)(param_1 + 0x109) = *(char *)(param_1 + 100);

    }

    if (*(char *)(param_1 + 0x65) != '\0') {

      *(char *)(param_1 + 0x10a) = *(char *)(param_1 + 0x65);

    }

    bVar1 = *(char *)(param_1 + 0x10a) * *(char *)(param_1 + 0x109);

    *(byte *)(param_1 + 0x10b) = bVar1;

    if (7 < bVar1) {

      *(uint *)(param_1 + 0x104) = (uint)(bVar1 >> 3) * *(int *)(param_1 + 0x100);

      return;

    }

    *(uint *)(param_1 + 0x104) = (uint)bVar1 * *(int *)(param_1 + 0x100) + 7 >> 3;

  }

  return;

}
