// READABILITY (auto CF):
//  - Body size: ~55 non-empty decompiler lines.
//  - Control keywords: if×5, do×3, while×3, return×3, for×1.
//  - Notable callees: FUN_007787a0, fprintf, raise.
//  - Strings: "LTC_ARGCHK \'%s\' failure on line %d of file %s\n"; "prng != NULL".
//  - Return sites: 3.

// =============================================================================
// Named_crypt_register_prng_007787a0
// -----------------------------------------------------------------------------
// Stable ID: aa_007787a0
// Address:   0x007787a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "crypt_register_prng"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int Named_crypt_register_prng_007787a0(void)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  int *unaff_EBX;

  int *piVar4;

  int *piVar5;

  bool bVar6;

  

  if (unaff_EBX == (int *)0x0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "prng != NULL",0x1b,

            "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\misc\\crypt\\crypt_register_prng.c"

           );

    raise(0x16);

  }

  iVar1 = 0;

  piVar3 = &DAT_00d19030;

  do {

    iVar2 = 10;

    bVar6 = true;

    piVar4 = piVar3;

    piVar5 = unaff_EBX;

    do {

      if (iVar2 == 0) break;

      iVar2 = iVar2 + -1;

      bVar6 = *piVar4 == *piVar5;

      piVar4 = piVar4 + 1;

      piVar5 = piVar5 + 1;

    } while (bVar6);

    if (bVar6) {

      return iVar1;

    }

    piVar3 = piVar3 + 10;

    iVar1 = iVar1 + 1;

    if (0xd1952f < (int)piVar3) {

      iVar1 = 0;

      piVar3 = &DAT_00d19030;

      do {

        if (*piVar3 == 0) {

          piVar3 = &DAT_00d19030 + iVar1 * 10;

          for (iVar2 = 10; iVar2 != 0; iVar2 = iVar2 + -1) {

            *piVar3 = *unaff_EBX;

            unaff_EBX = unaff_EBX + 1;

            piVar3 = piVar3 + 1;

          }

          return iVar1;

        }

        piVar3 = piVar3 + 10;

        iVar1 = iVar1 + 1;

      } while ((int)piVar3 < 0xd19530);

      return -1;

    }

  } while( true );

}
