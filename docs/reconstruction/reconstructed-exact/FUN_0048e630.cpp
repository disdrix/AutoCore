// =============================================================================
// FUN_0048e630
// -----------------------------------------------------------------------------
// Stable ID: aa_0048e630
// Address:   0x0048e630  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0048e630 @ 0x0048e630
// Stable ID: aa_0048e630
// Embedded strings (evidence for future rename):
//   - "<?xml"
//   - "version"
//   - "encoding"
//   - "standalone"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~105 non-empty decompiler lines.
//  - Control keywords: if×9, while×6, do×4, return×3, goto×2.
//  - Notable callees: FUN_0048a940×7, FUN_0048cff0×4, FUN_0048e2c0×3, FUN_0048cea0×2, FUN_0048af60, FUN_0048b300, FUN_0048cca0, FUN_0048e630.
//  - Strings: "<?xml"; "version"; "encoding"; "standalone".
//  - Return sites: 3.

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

byte * __thiscall FUN_0048e630(int param_1,uint32_t /* width from decompiler */ param_2,int param_3,uint32_t /* width from decompiler */ param_4)



{

  byte bVar1;

  char cVar2;

  char *pcVar3;

  int iVar4;

  char *pcVar5;

  uint32_t /* width from decompiler */ *extraout_ECX;

  byte *pbVar6;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a07b8;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  pcVar3 = (char *)FUN_0048cea0(param_2,param_4);

  iVar4 = FUN_0048af60();

  if (((pcVar3 == (char *)0x0) || (*pcVar3 == '\0')) ||

     (cVar2 = FUN_0048cff0(pcVar3,"<?xml",1,param_4), cVar2 == '\0')) {

    if ((iVar4 != 0) && (*(char *)(iVar4 + 0x2c) == '\0')) {

      *(uint8_t *)(iVar4 + 0x2c) = 1;

      *(uint32_t /* width from decompiler */ *)(iVar4 + 0x30) = 0xc;

      pcVar3 = PTR_s_Error_parsing_Declaration__00aef938;

      do {

        cVar2 = *pcVar3;

        pcVar3 = pcVar3 + 1;

      } while (cVar2 != '\0');

      FUN_0048a940(PTR_s_Error_parsing_Declaration__00aef938,

                   (int)pcVar3 - (int)(PTR_s_Error_parsing_Declaration__00aef938 + 1));

      *(uint32_t /* width from decompiler */ *)(iVar4 + 0x40) = 0xffffffff;

      *(uint32_t /* width from decompiler */ *)(iVar4 + 0x3c) = 0xffffffff;

    }

  }

  else {

    if (param_3 != 0) {

      FUN_0048cca0(pcVar3,param_4);

      *(uint32_t /* width from decompiler */ *)(param_1 + 4) = *extraout_ECX;

      *(uint32_t /* width from decompiler */ *)(param_1 + 8) = extraout_ECX[1];

    }

    pbVar6 = (byte *)(pcVar3 + 5);

    FUN_0048a940(&DAT_00a1419b,0);

    FUN_0048a940(&DAT_00a1419b,0);

    FUN_0048a940(&DAT_00a1419b,0);

    while ((pbVar6 != (byte *)0x0 && (*pbVar6 != 0))) {

      if (*pbVar6 == 0x3e) {

        ExceptionList = local_c;

        return pbVar6 + 1;

      }

      pbVar6 = (byte *)FUN_0048cea0(pbVar6,param_4);

      cVar2 = FUN_0048cff0(pbVar6,"version",1,param_4);

      if (cVar2 == '\0') {

        cVar2 = FUN_0048cff0(pbVar6,"encoding",1,param_4);

        if (cVar2 != '\0') {

          local_4 = 1;

          pbVar6 = (byte *)FUN_0048e2c0(pbVar6,param_3,param_4);

          pcVar3 = (char *)&DAT_00b0350c;

          do {

            pcVar5 = pcVar3;

            pcVar3 = pcVar5 + 1;

          } while (*pcVar5 != '\0');

          FUN_0048a940(&DAT_00b0350c,pcVar5 + -0xb0350c);

          goto LAB_0048e7b3;

        }

        cVar2 = FUN_0048cff0(pbVar6,"standalone",1,param_4);

        if (cVar2 != '\0') {

          local_4 = 2;

          pbVar6 = (byte *)FUN_0048e2c0(pbVar6,param_3,param_4);

          pcVar3 = (char *)&DAT_00b0350c;

          do {

            pcVar5 = pcVar3;

            pcVar3 = pcVar5 + 1;

          } while (*pcVar5 != '\0');

          FUN_0048a940(&DAT_00b0350c,pcVar5 + -0xb0350c);

          goto LAB_0048e7b3;

        }

        while( true ) {

          if (pbVar6 == (byte *)0x0) {

            ExceptionList = local_c;

            return (byte *)0x0;

          }

          bVar1 = *pbVar6;

          if ((((bVar1 == 0) || (bVar1 == 0x3e)) || (iVar4 = isspace((uint)bVar1), iVar4 != 0)) ||

             ((bVar1 == 10 || (bVar1 == 0xd)))) break;

          pbVar6 = pbVar6 + 1;

        }

      }

      else {

        local_4 = 0;

        pbVar6 = (byte *)FUN_0048e2c0(pbVar6,param_3,param_4);

        pcVar3 = (char *)&DAT_00b0350c;

        do {

          pcVar5 = pcVar3;

          pcVar3 = pcVar5 + 1;

        } while (*pcVar5 != '\0');

        FUN_0048a940(&DAT_00b0350c,pcVar5 + -0xb0350c);

LAB_0048e7b3:

        local_4 = 0xffffffff;

        FUN_0048b300();

      }

    }

  }

  ExceptionList = local_c;

  return (byte *)0x0;

}
