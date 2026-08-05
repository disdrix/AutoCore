// READABILITY (auto CF):
//  - Body size: ~103 non-empty decompiler lines.
//  - Control keywords: if×15, do×4, while×4, return×3, goto×2.
//  - Notable callees: fprintf×3, raise×3, FUN_00973d30.
//  - Strings: "LTC_ARGCHK \'%s\' failure on line %d of file %s\n"; "pt != NULL"; "ct != NULL"; "ctr != NULL".
//  - Return sites: 3.

// =============================================================================
// Named_ctr_encrypt_00973d30
// -----------------------------------------------------------------------------
// Stable ID: aa_00973d30
// Address:   0x00973d30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "ctr_encrypt"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ Named_ctr_encrypt_00973d30(byte *param_1,uint *param_2,uint param_3)



{

  char *pcVar1;

  byte bVar2;

  uint uVar3;

  uint uVar4;

  int iVar5;

  int *piVar6;

  uint *puVar7;

  int iVar8;

  int *unaff_ESI;

  

  if (param_1 == (byte *)0x0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "pt != NULL",0x21,

            "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\modes\\ctr\\ctr_encrypt.c");

    raise(0x16);

  }

  if (param_2 == (uint *)0x0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "ct != NULL",0x22,

            "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\modes\\ctr\\ctr_encrypt.c");

    raise(0x16);

  }

  if (unaff_ESI == (int *)0x0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "ctr != NULL",0x23,

            "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\modes\\ctr\\ctr_encrypt.c");

    raise(0x16);

  }

  iVar8 = *unaff_ESI;

  if (((iVar8 < 0) || (0x1f < iVar8)) || ((&DAT_00d17a30)[iVar8 * 0x13] == 0)) {

    return 10;

  }

  uVar3 = unaff_ESI[1];

  if ((((int)uVar3 < 0) || (0x80 < (int)uVar3)) ||

     ((uVar4 = unaff_ESI[2], (int)uVar4 < 0 || ((0x80 < (int)uVar4 || ((uVar3 & 3) != 0)))))) {

    return 0x10;

  }

  if (((uVar4 == uVar3) && (*(code **)(&DAT_00d17a70 + iVar8 * 0x4c) != (code *)0x0)) &&

     (uVar3 <= param_3)) {

    (**(code **)(&DAT_00d17a70 + iVar8 * 0x4c))

              (param_1,param_2,param_3 / uVar3,unaff_ESI + 4,unaff_ESI[3],unaff_ESI + 0x44);

    param_3 = param_3 % (uint)unaff_ESI[1];

  }

  do {

    if (param_3 == 0) {

      return 0;

    }

    iVar8 = unaff_ESI[1];

    if (unaff_ESI[2] == iVar8) {

      if (unaff_ESI[3] == 0) {

        if (0 < iVar8) {

          piVar6 = unaff_ESI + 4;

          do {

            *(char *)piVar6 = (char)*piVar6 + '\x01';

            if ((char)*piVar6 != '\0') break;

            piVar6 = (int *)((int)piVar6 + 1);

          } while ((int)((-0x10 - (int)unaff_ESI) + (int)piVar6) < unaff_ESI[1]);

        }

      }

      else {

        do {

          if (iVar8 + -1 < 0) break;

          pcVar1 = (char *)((int)unaff_ESI + iVar8 + 0xf);

          *pcVar1 = *pcVar1 + '\x01';

          iVar8 = iVar8 + -1;

        } while (*pcVar1 == '\0');

      }

      (**(code **)(&DAT_00d17a4c + *unaff_ESI * 0x4c))

                (unaff_ESI + 4,unaff_ESI + 0x24,unaff_ESI + 0x44);

      unaff_ESI[2] = 0;

LAB_00973ee8:

      if (param_3 < (uint)unaff_ESI[1]) goto LAB_00973f27;

      if (0 < unaff_ESI[1]) {

        iVar8 = 0;

        puVar7 = param_2;

        do {

          iVar5 = iVar8 + 0x90;

          iVar8 = iVar8 + 4;

          *puVar7 = *(uint *)(((int)param_1 - (int)param_2) + (int)puVar7) ^

                    *(uint *)((int)unaff_ESI + iVar5);

          puVar7 = puVar7 + 1;

        } while (iVar8 < unaff_ESI[1]);

      }

      iVar5 = unaff_ESI[1];

      param_1 = param_1 + iVar5;

      param_2 = (uint *)((int)param_2 + iVar5);

      iVar8 = -iVar5;

      unaff_ESI[2] = iVar5;

    }

    else {

      if (unaff_ESI[2] == 0) goto LAB_00973ee8;

LAB_00973f27:

      bVar2 = *param_1;

      param_1 = param_1 + 1;

      *(byte *)param_2 = *(byte *)(unaff_ESI[2] + 0x90 + (int)unaff_ESI) ^ bVar2;

      unaff_ESI[2] = unaff_ESI[2] + 1;

      param_2 = (uint *)((int)param_2 + 1);

      iVar8 = -1;

    }

    param_3 = param_3 + iVar8;

  } while( true );

}
