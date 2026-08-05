// =============================================================================
// FUN_00778540
// -----------------------------------------------------------------------------
// Stable ID: aa_00778540
// Address:   0x00778540  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00778540 @ 0x00778540
// Stable ID: aa_00778540
// Embedded strings (evidence for future rename):
//   - "LTC_ARGCHK \'%s\' failure on line %d of file %s\n"
//   - "md != NULL"
//   - "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\hashes\\md5.c"
//   - "in != NULL"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~66 non-empty decompiler lines.
//  - Control keywords: if×9, return×4, while×2, for×2.
//  - Notable callees: FUN_00777d60×2, fprintf×2, raise×2, FUN_00778540.
//  - Strings: "LTC_ARGCHK \'%s\' failure on line %d of file %s\n"; "md != NULL"; "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\hashes\\md5.c"; "in != NULL".
//  - Return sites: 4.

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

int FUN_00778540(uint *param_1,uint32_t /* width from decompiler */ *param_2,uint param_3)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  uint uVar3;

  uint uVar4;

  uint32_t /* width from decompiler */ *puVar5;

  

  if (param_1 == (uint *)0x0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "md != NULL",0xfd,"C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\hashes\\md5.c");

    raise(0x16);

  }

  if (param_2 == (uint32_t /* width from decompiler */ *)0x0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "in != NULL",0xfd,"C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\hashes\\md5.c");

    raise(0x16);

  }

  if (param_1[6] < 0x41) {

    while( true ) {

      while( true ) {

        if (param_3 == 0) {

          return 0;

        }

        if ((param_1[6] == 0) && (0x3f < param_3)) break;

        uVar3 = 0x40 - param_1[6];

        if (param_3 < uVar3) {

          uVar3 = param_3;

        }

        puVar1 = (uint32_t /* width from decompiler */ *)((int)param_2 + uVar3);

        puVar5 = (uint32_t /* width from decompiler */ *)(param_1[6] + 0x1c + (int)param_1);

        for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {

          *puVar5 = *param_2;

          param_2 = param_2 + 1;

          puVar5 = puVar5 + 1;

        }

        for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

          *(uint8_t *)puVar5 = *(uint8_t *)param_2;

          param_2 = (uint32_t /* width from decompiler */ *)((int)param_2 + 1);

          puVar5 = (uint32_t /* width from decompiler */ *)((int)puVar5 + 1);

        }

        param_1[6] = param_1[6] + uVar3;

        param_3 = param_3 - uVar3;

        param_2 = puVar1;

        if (param_1[6] == 0x40) {

          iVar2 = FUN_00777d60(param_1);

          if (iVar2 != 0) {

            return iVar2;

          }

          uVar3 = *param_1;

          *param_1 = *param_1 + 0x200;

          param_1[6] = 0;

          param_1[1] = param_1[1] + (uint)(0xfffffdff < uVar3);

        }

      }

      iVar2 = FUN_00777d60(param_1);

      if (iVar2 != 0) break;

      uVar3 = *param_1;

      *param_1 = *param_1 + 0x200;

      param_1[1] = param_1[1] + (uint)(0xfffffdff < uVar3);

      param_3 = param_3 - 0x40;

      param_2 = param_2 + 0x10;

    }

    return iVar2;

  }

  return 0x10;

}
