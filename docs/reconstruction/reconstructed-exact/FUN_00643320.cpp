// =============================================================================
// FUN_00643320
// -----------------------------------------------------------------------------
// Stable ID: aa_00643320
// Address:   0x00643320  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00643320 @ 0x00643320
// Stable ID: aa_00643320
// Embedded strings (evidence for future rename):
//   - "WinMain"
//   - "%s(%i):\'%s\'\n"
//   - "-------------------------------------------------------------------\n\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~86 non-empty decompiler lines.
//  - Control keywords: if×4, do×2, while×2, return×1.
//  - Notable callees: FUN_00643320, GetCurrentProcess, _snprintf, s.
//  - Strings: "WinMain"; "%s(%i):\'%s\'\n".
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

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



void FUN_00643320(int param_1,int param_2,code *param_3,uint32_t /* width from decompiler */ param_4)



{

  uint32_t /* width from decompiler */ uVar1;

  HANDLE pvVar2;

  int iVar3;

  int iVar4;

  char *pcVar5;

  char *pcVar6;

  bool bVar7;

  uint32_t /* width from decompiler */ unaff_retaddr;

  uint32_t /* width from decompiler */ local_101c;

  HANDLE local_1018;

  uint32_t /* width from decompiler */ uStack_1014;

  uint32_t /* width from decompiler */ uStack_1010;

  uint32_t /* width from decompiler */ uStack_100c;

  uint32_t /* width from decompiler */ uStack_1008;

  uint32_t /* width from decompiler */ uStack_1004;

  uint32_t /* width from decompiler */ local_1000;

  uint32_t /* width from decompiler */ local_ffc;

  uint32_t /* width from decompiler */ local_ff8;

  uint32_t /* width from decompiler */ local_ff4;

  uint32_t /* width from decompiler */ local_ff0;

  char local_fec [8];

  char acStack_fe4 [2004];

  char acStack_810 [2060];

  code *pcStack_4;

  

  pcStack_4 = (code *)0x64332a;

  pvVar2 = GetCurrentProcess();

  iVar4 = 0;

  local_1018 = pvVar2;

  if (0 < param_2) {

    do {

      uVar1 = *(uint32_t /* width from decompiler */ *)(param_1 + iVar4 * 4);

      local_ffc = 0;

      local_ff8 = 0;

      local_ff4 = 0;

      local_fec[0] = '\0';

      local_fec[1] = '\0';

      local_fec[2] = '\0';

      local_fec[3] = '\0';

      local_1000 = 0x18;

      local_ff0 = 0x7e8;

      local_101c = 0;

      iVar3 = (*DAT_00d03104)(pvVar2,uVar1,&local_101c,&local_1000);

      if (iVar3 == 0) {

        local_fec[0] = s__unknown__009e44e8[0];

        local_fec[1] = s__unknown__009e44e8[1];

        local_fec[2] = s__unknown__009e44e8[2];

        local_fec[3] = s__unknown__009e44e8[3];

        local_fec[4] = s__unknown__009e44e8[4];

        local_fec[5] = s__unknown__009e44e8[5];

        local_fec[6] = s__unknown__009e44e8[6];

        local_fec[7] = s__unknown__009e44e8[7];

        acStack_fe4[0] = s__unknown__009e44e8[8];

        acStack_fe4[1] = s__unknown__009e44e8[9];

      }

      else {

        iVar3 = 8;

        bVar7 = true;

        pcVar5 = local_fec;

        pcVar6 = "WinMain";

        do {

          if (iVar3 == 0) break;

          iVar3 = iVar3 + -1;

          bVar7 = *pcVar5 == *pcVar6;

          pcVar5 = pcVar5 + 1;

          pcVar6 = pcVar6 + 1;

        } while (bVar7);

        pvVar2 = local_1018;

        if (bVar7) break;

      }

      uStack_1010 = 0;

      uStack_100c = 0;

      uStack_1008 = 0;

      uStack_1004 = 0;

      uStack_1014 = 0x14;

      (*DAT_00d030f4)(pvVar2,uVar1,&local_101c,&uStack_1014);

      _snprintf(acStack_810,0x800,"%s(%i):\'%s\'\n",local_1018,local_101c,&local_ffc);

      (*pcStack_4)(acStack_810,unaff_retaddr);

      iVar4 = iVar4 + 1;

    } while (iVar4 < param_2);

  }

  (*param_3)("-------------------------------------------------------------------\n\n",param_4);

  return;

}
