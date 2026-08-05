// =============================================================================
// FUN_00957820
// -----------------------------------------------------------------------------
// Stable ID: aa_00957820
// Address:   0x00957820  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00957820 @ 0x00957820
// Stable ID: aa_00957820
// Embedded strings (evidence for future rename):
//   - ": %s\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~104 non-empty decompiler lines.
//  - Control keywords: if×8, return×3, while×2, for×2.
//  - Notable callees: FUN_00800af0×4, FUN_00404000×2, free×2, sprintf×2, FUN_004033e0, FUN_00403c60, FUN_00403d60, FUN_004048e0.
//  - Strings: ": %s\n".
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

uint32_t /* width from decompiler */ __thiscall FUN_00957820(int param_1,uint32_t /* width from decompiler */ param_2,char *param_3)



{

  int *piVar1;

  int *piVar2;

  char *pcVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  uint uVar7;

  uint uVar8;

  LPCSTR lpString;

  CHAR *pCVar9;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_1ac [28];

  CHAR *local_190;

  CHAR local_18c [128];

  char local_10c [256];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009bb410;

  local_c = ExceptionList;

  iVar6 = *(int *)(*(int *)(param_1 + 0xe98) + 0x6b4);

  ExceptionList = &local_c;

  pcVar3 = strtok((char *)0x0,param_3);

  if (pcVar3 == (char *)0x0) {

    piVar1 = *(int **)(param_1 + 8);

    piVar2 = (int *)*piVar1;

    while (piVar2 != piVar1) {

      if ((0 < piVar2[10]) && (piVar2[10] <= iVar6)) {

        local_190 = local_18c;

        FUN_004033e0();

        local_4 = 0;

        FUN_00800af0(param_1,1,0,local_190,&DAT_00afdefc);

        local_4 = 0xffffffff;

        if (local_190 != local_18c) {

          free(local_190);

        }

        sprintf(local_10c,": %s\n",piVar2 + 0xb);

        FUN_00800af0(param_1,1,0,local_10c,&DAT_00afdf0c);

      }

      FUN_00404000();

      piVar1 = *(int **)(param_1 + 8);

    }

  }

  else {

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_1ac,pcVar3);

    local_4 = 1;

    iVar4 = FUN_00403d60(local_1ac);

    iVar5 = FUN_00403c60(local_1ac);

    local_4 = 0xffffffff;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_1ac);

    iVar6 = *(int *)(param_1 + 8);

    while (iVar5 != iVar6) {

      if (*(uint *)(iVar5 + 0x24) < 0x10) {

        lpString = (LPCSTR)(iVar5 + 0x10);

      }

      else {

        lpString = *(LPCSTR *)(iVar5 + 0x10);

      }

      local_190 = local_18c;

      if (lpString == (LPCSTR)0x0) {

        local_190 = (CHAR *)0x0;

      }

      else {

        iVar6 = lstrlenA(lpString);

        uVar8 = iVar6 + 1;

        if ((0x80 < (int)uVar8) && (local_190 = malloc(uVar8), local_190 == (CHAR *)0x0)) {

                    /* WARNING: Subroutine does not return */

          FUN_004048e0(0x8007000e);

        }

        pCVar9 = local_190;

        for (uVar7 = uVar8 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {

          *(uint32_t /* width from decompiler */ *)pCVar9 = *(uint32_t /* width from decompiler */ *)lpString;

          lpString = lpString + 4;

          pCVar9 = pCVar9 + 4;

        }

        for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {

          *pCVar9 = *lpString;

          lpString = lpString + 1;

          pCVar9 = pCVar9 + 1;

        }

      }

      local_4 = 2;

      FUN_00800af0(param_1,1,0,local_190,&DAT_00afdefc);

      local_4 = 0xffffffff;

      if (local_190 != local_18c) {

        free(local_190);

      }

      sprintf(local_10c,": %s\n",iVar5 + 0x2c);

      FUN_00800af0(param_1,1,0,local_10c,&DAT_00afdf0c);

      if (iVar5 == iVar4) {

        ExceptionList = local_c;

        return 1;

      }

      FUN_00404000();

      iVar6 = *(int *)(param_1 + 8);

    }

  }

  ExceptionList = local_c;

  return 1;

}
