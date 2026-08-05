// =============================================================================
// Named_CalleeOf_Named_ecc_sys_0077a590
// -----------------------------------------------------------------------------
// Stable ID: aa_0077a590
// Callee of Named_ecc_sys (+1 other named callers)
// Address:   0x0077a590  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_ecc_sys: callee helper. Evidence string: "LTC_ARGCHK \'%s\' failure on line %d of file %s\n". Supports parent flow (not a free-standing entry point). Named_ecc_sys (+1 other named callers).
// Embedded strings (evidence):
//   - "LTC_ARGCHK \'%s\' failure on line %d of file %s\n"
//   - "out != NULL"
//   - "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\pk\\ecc\\ecc.c"
//   - "outlen != NULL"
//   - "key != NULL"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~70 non-empty decompiler lines.
//  - Control keywords: if×13, return×6, goto×1.
//  - Notable callees: fprintf×3, raise×3, FUN_007715b0×2, FUN_007726e0×2, FUN_00770120, FUN_007799d0, FUN_0077a590, FUN_00973a80.
//  - Strings: "LTC_ARGCHK \'%s\' failure on line %d of file %s\n"; "out != NULL"; "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\pk\\ecc\\ecc.c"; "outlen != NULL".
//  - Return sites: 6.

/*
 * Behavioral notes:
 * Callee of Named_ecc_sys (+1 other named callers)
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int Named_CalleeOf_Named_ecc_sys_0077a590(uint *param_1,int param_2,int *param_3)



{

  uint uVar1;

  int in_EAX;

  int iVar2;

  int iVar3;

  uint uVar4;

  uint8_t local_4 [4];

  

  if (in_EAX == 0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "out != NULL",0x3df,"C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\pk\\ecc\\ecc.c"

           );

    raise(0x16);

  }

  if (param_1 == (uint *)0x0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "outlen != NULL",0x3e0,

            "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\pk\\ecc\\ecc.c");

    raise(0x16);

  }

  if (param_3 == (int *)0x0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "key != NULL",0x3e1,"C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\pk\\ecc\\ecc.c"

           );

    raise(0x16);

  }

  if (6 < *param_1) {

    if ((*param_3 != 0) && (param_2 == 0)) {

      return 0xe;

    }

    *(uint8_t *)(in_EAX + 4) = (uint8_t)param_2;

    *(uint8_t *)(in_EAX + 5) = *(uint8_t *)(&DAT_00a23878 + param_3[1] * 7);

    if (9 < *param_1) {

      iVar2 = FUN_007715b0();

      *(int *)(in_EAX + 6) = iVar2;

      if (iVar2 + 10U <= *param_1) {

        iVar3 = FUN_007726e0(param_3 + 2,in_EAX + 10);

        if (iVar3 == 0) {

          iVar3 = FUN_007799d0(param_3 + 2,param_3[1],local_4);

          if (iVar3 == 0) {

            *(uint8_t *)(iVar2 + 10U + in_EAX) = local_4[0];

            uVar4 = iVar2 + 0xb;

            if (param_2 == 0) {

              uVar1 = iVar2 + 0xf;

              if (*param_1 < uVar1) {

                return 6;

              }

              iVar2 = FUN_007715b0();

              *(int *)(uVar4 + in_EAX) = iVar2;

              uVar4 = iVar2 + uVar1;

              if (*param_1 < uVar4) {

                return 6;

              }

              iVar2 = FUN_007726e0(param_3 + 0xe,uVar1 + in_EAX);

              if (iVar2 != 0) goto LAB_0077a702;

            }

            FUN_00973a80(2,0);

            *param_1 = uVar4;

            iVar3 = 0;

          }

          return iVar3;

        }

LAB_0077a702:

        iVar2 = FUN_00770120();

        return iVar2;

      }

    }

  }

  return 6;

}
