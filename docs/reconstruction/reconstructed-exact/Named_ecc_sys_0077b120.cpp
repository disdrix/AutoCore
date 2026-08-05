// READABILITY (auto CF):
//  - Body size: ~110 non-empty decompiler lines.
//  - Control keywords: if×18, return×8, goto×1, do×1, while×1.
//  - Notable callees: fprintf×4, raise×4, free×3, FUN_00778980×2, malloc×2, FUN_00770170, FUN_0077a180, FUN_0077a370.
//  - Strings: "LTC_ARGCHK \'%s\' failure on line %d of file %s\n"; "in != NULL"; "out != NULL"; "outlen != NULL".
//  - Return sites: 8.

// =============================================================================
// Named_ecc_sys_0077b120
// -----------------------------------------------------------------------------
// Stable ID: aa_0077b120
// Address:   0x0077b120  (autoassault.exe, image base 0x400000)
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

int Named_ecc_sys_0077b120(int param_1,uint param_2,byte *param_3,uint *param_4,int *param_5)



{

  uint uVar1;

  int *piVar2;

  int iVar3;

  void *_Memory;

  void *_Memory_00;

  byte *pbVar4;

  byte *pbVar5;

  uint uVar6;

  uint32_t /* width from decompiler */ local_54;

  int local_50;

  void *local_4c;

  uint8_t local_48 [72];

  

  if (param_1 == 0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "in != NULL",0xa5,

            "c:\\vog\\1_code\\torquenetworklibrary\\libtomcrypt\\pk\\ecc\\ecc_sys.c");

    raise(0x16);

  }

  if (param_3 == (byte *)0x0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "out != NULL",0xa6,

            "c:\\vog\\1_code\\torquenetworklibrary\\libtomcrypt\\pk\\ecc\\ecc_sys.c");

    raise(0x16);

  }

  if (param_4 == (uint *)0x0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "outlen != NULL",0xa7,

            "c:\\vog\\1_code\\torquenetworklibrary\\libtomcrypt\\pk\\ecc\\ecc_sys.c");

    raise(0x16);

  }

  piVar2 = param_5;

  if (param_5 == (int *)0x0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "key != NULL",0xa8,

            "c:\\vog\\1_code\\torquenetworklibrary\\libtomcrypt\\pk\\ecc\\ecc_sys.c");

    raise(0x16);

  }

  if (*piVar2 != 0) {

    return 0xf;

  }

  if (param_2 < 0xd) {

    return 7;

  }

  iVar3 = FUN_009738d0(2,3);

  if (iVar3 != 0) {

    return iVar3;

  }

  local_50 = FUN_00770170();

  if (local_50 == -1) {

    return 0xb;

  }

  uVar6 = *(uint *)(param_1 + 5);

  if (param_2 - 0xd < uVar6) {

    return 7;

  }

  iVar3 = FUN_0077a370(uVar6,local_48);

  if (iVar3 != 0) {

    return iVar3;

  }

  _Memory = malloc(0xa0);

  local_4c = _Memory;

  _Memory_00 = malloc(0x80);

  if (_Memory == (void *)0x0) {

    _Memory = _Memory_00;

    if (_Memory_00 == (void *)0x0) goto LAB_0077b379;

  }

  else if (_Memory_00 != (void *)0x0) {

    local_54 = 0xa0;

    iVar3 = FUN_0077a180(param_5,local_48,_Memory,&local_54);

    FUN_00778980();

    if (iVar3 == 0) {

      param_5 = (int *)0x80;

      iVar3 = FUN_00973930(_Memory,local_54,_Memory_00,&param_5);

      if (iVar3 == 0) {

        uVar1 = *(uint *)(uVar6 + 9 + param_1);

        if ((param_2 - 0xd) - uVar6 < uVar1) {

          iVar3 = 7;

        }

        else if (*param_4 < uVar1) {

          iVar3 = 6;

        }

        else {

          if (uVar1 != 0) {

            pbVar5 = (byte *)(param_1 + uVar6 + 0xd);

            pbVar4 = param_3;

            uVar6 = uVar1;

            do {

              *pbVar4 = pbVar4[(int)_Memory_00 - (int)param_3] ^ *pbVar5;

              pbVar5 = pbVar5 + 1;

              uVar6 = uVar6 - 1;

              pbVar4 = pbVar4 + 1;

              _Memory = local_4c;

            } while (uVar6 != 0);

          }

          *param_4 = uVar1;

          iVar3 = 0;

        }

      }

    }

    free(_Memory_00);

    free(_Memory);

    return iVar3;

  }

  free(_Memory);

LAB_0077b379:

  FUN_00778980();

  return 0xd;

}
