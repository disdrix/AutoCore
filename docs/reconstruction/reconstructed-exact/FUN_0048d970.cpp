// =============================================================================
// FUN_0048d970
// -----------------------------------------------------------------------------
// Stable ID: aa_0048d970
// Address:   0x0048d970  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0048d970 @ 0x0048d970
// Stable ID: aa_0048d970
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~69 non-empty decompiler lines.
//  - Control keywords: if×4, while×3, do×1, return×1.
//  - Notable callees: FUN_0048aa20×4, FUN_0048cff0×2, FUN_0048d8e0×2, CONCAT31, FUN_0048a940, FUN_0048cea0, FUN_0048d970, isspace.
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

byte * FUN_0048d970(byte *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,char *param_4,

                   uint32_t /* width from decompiler */ param_5,uint32_t /* width from decompiler */ param_6)



{

  char *pcVar1;

  byte bVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  char cVar5;

  byte *pbVar6;

  int iVar7;

  uint8_t local_8;

  uint8_t local_7;

  uint8_t local_6;

  uint8_t local_5;

  int local_4;

  

  FUN_0048a940(&DAT_00a1419b,0);

  uVar4 = param_6;

  uVar3 = param_5;

  pbVar6 = param_1;

  if (((char)param_3 == '\0') || (DAT_00aef8c9 == '\0')) {

    while ((pbVar6 != (byte *)0x0 &&

           ((*pbVar6 != 0 &&

            (param_3._0_1_ = FUN_0048cff0(pbVar6,param_4,uVar3,uVar4), (char)param_3 == '\0'))))) {

      param_3._2_1_ = (char)param_3;

      param_3._1_1_ = (char)param_3;

      param_3._3_1_ = param_3._2_1_;

      pbVar6 = (byte *)FUN_0048d8e0(pbVar6,&param_3,&param_1,uVar4);

      FUN_0048aa20(&param_3,param_1);

    }

  }

  else {

    param_3._0_1_ = '\0';

    pbVar6 = (byte *)FUN_0048cea0(param_1,param_6);

    while (((pbVar6 != (byte *)0x0 && (*pbVar6 != 0)) &&

           (cVar5 = FUN_0048cff0(pbVar6,param_4,param_5,uVar4), cVar5 == '\0'))) {

      bVar2 = *pbVar6;

      if (((bVar2 == 0xd) || (bVar2 == 10)) ||

         ((iVar7 = isspace((uint)bVar2), iVar7 != 0 || ((bVar2 == 10 || (bVar2 == 0xd)))))) {

        param_3._0_1_ = '\x01';

        pbVar6 = pbVar6 + 1;

      }

      else {

        if ((char)param_3 != '\0') {

          param_3._0_1_ = 0x20;

          FUN_0048aa20(&param_3,1);

          param_3._0_1_ = '\0';

        }

        local_8 = 0;

        local_7 = 0;

        local_6 = 0;

        local_5 = 0;

        pbVar6 = (byte *)FUN_0048d8e0(pbVar6,&local_8,&local_4,uVar4);

        if (local_4 == 1) {

          param_1 = (byte *)CONCAT31(param_1._1_3_,local_8);

          FUN_0048aa20(&param_1,1);

        }

        else {

          FUN_0048aa20(&local_8,local_4);

        }

      }

    }

  }

  pcVar1 = param_4 + 1;

  do {

    cVar5 = *param_4;

    param_4 = param_4 + 1;

  } while (cVar5 != '\0');

  return pbVar6 + ((int)param_4 - (int)pcVar1);

}
