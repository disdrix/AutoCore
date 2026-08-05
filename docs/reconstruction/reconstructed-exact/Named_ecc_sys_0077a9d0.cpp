// READABILITY (auto CF):
//  - Body size: ~99 non-empty decompiler lines.
//  - Control keywords: if×17, return×8, goto×2.
//  - Notable callees: fprintf×4, raise×4, FUN_00772910×3, FUN_00778980×3, FUN_00770120×2, FUN_00770250×2, FUN_007707a0×2, FUN_00772250×2.
//  - Strings: "LTC_ARGCHK \'%s\' failure on line %d of file %s\n"; "sig != NULL"; "hash != NULL"; "stat != NULL".
//  - Return sites: 8.

// =============================================================================
// Named_ecc_sys_0077a9d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0077a9d0
// Address:   0x0077a9d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "ecc_sys"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int Named_ecc_sys_0077a9d0(uint param_1,int param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ *param_4,int param_5)



{

  uint uVar1;

  int in_EAX;

  int iVar2;

  int iVar3;

  uint8_t local_88 [16];

  uint8_t local_78 [16];

  uint8_t local_68 [16];

  uint8_t local_58 [16];

  uint8_t local_48 [8];

  uint8_t local_40 [64];

  

  if (in_EAX == 0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "sig != NULL",0x1bb,

            "c:\\vog\\1_code\\torquenetworklibrary\\libtomcrypt\\pk\\ecc\\ecc_sys.c");

    raise(0x16);

  }

  if (param_2 == 0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "hash != NULL",0x1bc,

            "c:\\vog\\1_code\\torquenetworklibrary\\libtomcrypt\\pk\\ecc\\ecc_sys.c");

    raise(0x16);

  }

  if (param_4 == (uint32_t /* width from decompiler */ *)0x0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "stat != NULL",0x1bd,

            "c:\\vog\\1_code\\torquenetworklibrary\\libtomcrypt\\pk\\ecc\\ecc_sys.c");

    raise(0x16);

  }

  if (param_5 == 0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "key != NULL",0x1be,

            "c:\\vog\\1_code\\torquenetworklibrary\\libtomcrypt\\pk\\ecc\\ecc_sys.c");

    raise(0x16);

  }

  *param_4 = 0;

  if (param_1 < 0xc) {

    return 7;

  }

  iVar2 = FUN_009738d0(2,2);

  if (iVar2 != 0) {

    return iVar2;

  }

  uVar1 = *(uint *)(in_EAX + 4);

  if (param_1 - 0xc < uVar1) {

    return 7;

  }

  iVar2 = FUN_0077a370(uVar1,local_48);

  if (iVar2 != 0) {

    return iVar2;

  }

  if ((param_1 - 0xc) - uVar1 < *(uint *)(uVar1 + 8 + in_EAX)) {

    return 7;

  }

  iVar2 = FUN_00771cb0(local_68,local_58,local_88,local_78,0);

  if (iVar2 != 0) {

    FUN_00778980();

    iVar2 = FUN_00770120();

    return iVar2;

  }

  iVar2 = FUN_00778a00();

  if (iVar2 == 0) {

    FUN_00772250(local_68,local_58,local_88,local_78,0);

    FUN_00778980();

    return 0xd;

  }

  iVar3 = FUN_00774cc0();

  if (((iVar3 == 0) && (iVar3 = FUN_00774cc0(), iVar3 == 0)) &&

     (iVar3 = FUN_00772910(0x40), iVar3 == 0)) {

    FUN_00770250();

    FUN_00771c00();

    iVar3 = FUN_00773600(local_78,local_88,local_78,0);

    if (iVar3 == 0) {

      iVar3 = FUN_00779c60(local_68,local_40,local_40,local_88);

      if (((iVar3 != 0) || (iVar3 = FUN_00778a40(local_40,local_88,local_78), iVar3 != 0)) ||

         (iVar3 = FUN_007795f0(), iVar3 != 0)) goto LAB_0077ad3e;

      iVar3 = FUN_00772910(0x40);

      if ((iVar3 == 0) && (iVar3 = FUN_00772910(0x40), iVar3 == 0)) {

        FUN_00770250();

        iVar3 = FUN_00779c60(local_58,iVar2,iVar2,local_88);

        if (iVar3 == 0) {

          iVar2 = FUN_007707a0();

          if ((iVar2 == 0) && (iVar2 = FUN_007707a0(), iVar2 == 0)) {

            *param_4 = 1;

          }

          iVar3 = 0;

        }

        goto LAB_0077ad3e;

      }

    }

  }

  iVar3 = FUN_00770120();

LAB_0077ad3e:

  FUN_007789e0();

  FUN_00778980();

  FUN_00772250(local_88,local_58,local_68,local_78,0);

  return iVar3;

}
