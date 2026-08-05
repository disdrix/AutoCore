// =============================================================================
// FUN_0077ad80
// -----------------------------------------------------------------------------
// Stable ID: aa_0077ad80
// Address:   0x0077ad80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0077ad80 @ 0x0077ad80
// Stable ID: aa_0077ad80
// Embedded strings (evidence for future rename):
//   - "LTC_ARGCHK \'%s\' failure on line %d of file %s\n"
//   - "in != NULL"
//   - "c:\\vog\\1_code\\torquenetworklibrary\\libtomcrypt\\pk\\ecc\\ecc_sys.c"
//   - "out != NULL"
//   - "outlen != NULL"
//   - "key != NULL"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~139 non-empty decompiler lines.
//  - Control keywords: if×20, return×6, do×3, while×3, goto×3.
//  - Notable callees: FUN_00778980×4, fprintf×4, raise×4, FUN_00770120×3, free×3, malloc×2, FUN_007715b0, FUN_00771cb0.
//  - Strings: "LTC_ARGCHK \'%s\' failure on line %d of file %s\n"; "in != NULL"; "out != NULL"; "outlen != NULL".
//  - Return sites: 6.

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

int FUN_0077ad80(int param_1,uint32_t /* width from decompiler */ param_2,int param_3,uint *param_4,uint32_t /* width from decompiler */ param_5,

                int param_6)



{

  int *in_EAX;

  int *piVar1;

  void *_Memory;

  void *_Memory_00;

  uint uVar2;

  uint uVar3;

  int iVar4;

  uint uVar5;

  uint local_6c;

  uint8_t local_68 [16];

  uint8_t local_58 [16];

  uint8_t local_48 [56];

  uint8_t local_10 [16];

  

  if (param_1 == 0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "in != NULL",0x124,

            "c:\\vog\\1_code\\torquenetworklibrary\\libtomcrypt\\pk\\ecc\\ecc_sys.c");

    raise(0x16);

  }

  if (param_3 == 0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "out != NULL",0x125,

            "c:\\vog\\1_code\\torquenetworklibrary\\libtomcrypt\\pk\\ecc\\ecc_sys.c");

    raise(0x16);

  }

  if (param_4 == (uint *)0x0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "outlen != NULL",0x126,

            "c:\\vog\\1_code\\torquenetworklibrary\\libtomcrypt\\pk\\ecc\\ecc_sys.c");

    raise(0x16);

  }

  if (in_EAX == (int *)0x0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "key != NULL",0x127,

            "c:\\vog\\1_code\\torquenetworklibrary\\libtomcrypt\\pk\\ecc\\ecc_sys.c");

    raise(0x16);

  }

  if (*in_EAX != 0) {

    return 0xf;

  }

  iVar4 = 0;

  piVar1 = &DAT_00a23878;

  do {

    piVar1 = piVar1 + 7;

    iVar4 = iVar4 + 1;

  } while (*piVar1 != 0);

  if ((in_EAX[1] < 0) || (iVar4 <= in_EAX[1])) {

    return 0x12;

  }

  if (((param_6 < 0) || (0x1f < param_6)) || ((&DAT_00d19030)[param_6 * 10] == 0)) {

    return 0xc;

  }

  FUN_00778910();

  iVar4 = FUN_0077a730(param_5);

  if (iVar4 != 0) {

    return iVar4;

  }

  _Memory = malloc(0xa0);

  _Memory_00 = malloc(0xa0);

  if (_Memory == (void *)0x0) {

    _Memory = _Memory_00;

    if (_Memory_00 == (void *)0x0) goto LAB_0077b105;

  }

  else if (_Memory_00 != (void *)0x0) {

    local_6c = 0xa0;

    iVar4 = FUN_0077a590(&local_6c,1,local_48);

    if (iVar4 == 0) {

      iVar4 = FUN_00771cb0(local_68,local_58,0);

      if (iVar4 == 0) {

        iVar4 = FUN_00772910(0x40);

        if ((iVar4 == 0) && (iVar4 = FUN_00774cc0(), iVar4 == 0)) {

          iVar4 = FUN_00776560();

          if ((iVar4 == 0) &&

             ((iVar4 = FUN_00775dd0(local_68,local_58,local_68), iVar4 == 0 &&

              (iVar4 = FUN_00776340(local_68,local_10,local_58,local_68), iVar4 == 0)))) {

            uVar2 = FUN_007715b0();

            if (0xa0 < uVar2) {

              iVar4 = FUN_00770120();

              goto LAB_0077b0bd;

            }

            iVar4 = FUN_007726e0(local_68,_Memory_00);

            if (iVar4 == 0) {

              if (*param_4 < uVar2 + 0xc + local_6c) {

                iVar4 = 6;

              }

              else {

                uVar3 = 0;

                *(uint *)(param_3 + 4) = local_6c;

                iVar4 = 8;

                if (local_6c != 0) {

                  do {

                    *(uint8_t *)(iVar4 + param_3) = *(uint8_t *)(uVar3 + (int)_Memory);

                    uVar3 = uVar3 + 1;

                    iVar4 = iVar4 + 1;

                  } while (uVar3 < local_6c);

                }

                *(uint *)(iVar4 + param_3) = uVar2;

                uVar5 = iVar4 + 4;

                uVar3 = 0;

                if (uVar2 != 0) {

                  do {

                    *(uint8_t *)(uVar5 + param_3) = *(uint8_t *)(uVar3 + (int)_Memory_00);

                    uVar3 = uVar3 + 1;

                    uVar5 = uVar5 + 1;

                  } while (uVar3 < uVar2);

                }

                FUN_00973a80(2,2);

                *param_4 = uVar5;

                iVar4 = 0;

              }

              goto LAB_0077b0bd;

            }

          }

        }

        iVar4 = FUN_00770120();

      }

      else {

        FUN_00778980();

        iVar4 = FUN_00770120();

      }

    }

    else {

      FUN_00778980();

    }

LAB_0077b0bd:

    FUN_00772250(local_68,local_58,0);

    FUN_00778980();

    free(_Memory);

    free(_Memory_00);

    return iVar4;

  }

  free(_Memory);

LAB_0077b105:

  FUN_00778980();

  return 0xd;

}
