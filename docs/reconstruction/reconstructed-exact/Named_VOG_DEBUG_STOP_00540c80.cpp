// READABILITY (auto CF):
//  - Body size: ~200 non-empty decompiler lines.
//  - Control keywords: if×16, while×5, for×5, do×2, return×2.
//  - Notable callees: fwrite×19, FUN_007a4480×8, CoTaskMemFree×6, FUN_004eb010, FUN_004f1e20, FUN_00540c80, FUN_00546ce0, FUN_007cf0c0.
//  - Strings: ");

  if (_File == (FILE *)0x0) {

    vog_LogMessage("; ",0x300,3,

                   "; "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP".
//  - Return sites: 2.

// =============================================================================
// Named_VOG_DEBUG_STOP_00540c80
// -----------------------------------------------------------------------------
// Stable ID: aa_00540c80
// Address:   0x00540c80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOG_DEBUG_STOP"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Named_VOG_DEBUG_STOP_00540c80(int param_1,char *param_2)



{

  char cVar1;

  uint uVar2;

  FILE *_File;

  int iVar3;

  int iVar4;

  void *_Str;

  size_t sStack_158;

  uint local_154;

  int iStack_150;

  uint32_t /* width from decompiler */ local_14c;

  void *pvStack_148;

  void *apvStack_144 [2];

  void *pvStack_13c;

  void *pvStack_138;

  void *apvStack_134 [2];

  int iStack_12c;

  void *pvStack_128;

  uint32_t /* width from decompiler */ uStack_124;

  uint32_t /* width from decompiler */ uStack_120;

  uint32_t /* width from decompiler */ uStack_11c;

  uint32_t /* width from decompiler */ local_118;

  uint32_t /* width from decompiler */ local_114;

  char local_110 [4];

  char local_10c [4];

  char local_108 [4];

  char local_104 [4];

  char local_100;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009a3fba;

  local_c = ExceptionList;

  if (param_2 == (char *)0x0) {

    local_110 = (char  [4])s____clonebase_wad_009d028c._0_4_;

    local_10c = (char  [4])s____clonebase_wad_009d028c._4_4_;

    local_108 = (char  [4])s____clonebase_wad_009d028c._8_4_;

    local_104 = (char  [4])s____clonebase_wad_009d028c._12_4_;

    local_100 = s____clonebase_wad_009d028c[0x10];

  }

  else {

    iVar4 = -(int)param_2;

    do {

      cVar1 = *param_2;

      param_2[(int)(local_110 + iVar4)] = cVar1;

      param_2 = param_2 + 1;

    } while (cVar1 != '\0');

  }

  ExceptionList = &local_c;

  local_154 = param_1;

  _File = fopen(local_110,"wb");

  if (_File == (FILE *)0x0) {

    vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\CloneBaseList.cpp",0x300,3,

                   "Couldn\'t open clonebase.wad for writing. Please check it out first");

  }

  else {

    local_14c = 0x1b;

    fwrite(&local_14c,4,1,_File);

    local_114 = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xf10) + 0xc);

    fwrite(&local_114,4,1,_File);

    iVar4 = *(int *)(param_1 + 0xf10);

    iVar3 = 0;

    if (*(char *)(iVar4 + 0x1d) != '\0') {

      FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    *(uint8_t *)(iVar4 + 0x1d) = 1;

    while( true ) {

      iVar4 = *(int *)(local_154 + 0xf10);

      if (*(char *)(iVar4 + 0x1d) == '\0') {

        FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

        FUN_007a4480(0,"VOG_DEBUG_STOP");

      }

      uVar2 = local_154;

      if (iVar3 == 0) {

        iVar3 = *(int *)(iVar4 + 0x14);

      }

      else {

        iVar3 = *(int *)(iVar3 + 0x14);

      }

      if (iVar3 == 0) {

        iVar4 = 0;

      }

      else {

        iVar4 = *(int *)(iVar3 + 8);

      }

      if (iVar4 == 0) break;

      local_118 = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x38);

      fwrite(&local_118,4,1,_File);

      FUN_004f1e20(0,1);

      (**(code **)(**(int **)(iVar4 + 0x3c) + 4))(_File);

      FUN_004eb010();

    }

    *(uint8_t *)(*(int *)(local_154 + 0xf10) + 0x1d) = 0;

    uStack_11c = *(uint32_t /* width from decompiler */ *)(**(int **)(local_154 + 0xf18) + 0xc);

    fwrite(&uStack_11c,4,1,_File);

    iVar4 = **(int **)(uVar2 + 0xf18);

    iVar3 = 0;

    if (*(char *)(iVar4 + 0x1d) != '\0') {

      FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    *(uint8_t *)(iVar4 + 0x1d) = 1;

    while( true ) {

      iStack_150 = **(int **)(local_154 + 0xf18);

      if (*(char *)(iStack_150 + 0x1d) == '\0') {

        FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

        FUN_007a4480(0,"VOG_DEBUG_STOP");

      }

      if (iVar3 == 0) {

        iVar3 = *(int *)(iStack_150 + 0x14);

      }

      else {

        iVar3 = *(int *)(iVar3 + 0x14);

      }

      if (iVar3 == 0) {

        iVar4 = 0;

      }

      else {

        iVar4 = *(int *)(iVar3 + 8);

      }

      if (iVar4 == 0) break;

      FUN_00546ce0(_File);

    }

    *(uint8_t *)(**(int **)(local_154 + 0xf18) + 0x1d) = 0;

    pvStack_128 = (void *)0x0;

    uStack_124 = 0;

    uStack_120 = 0;

    uStack_4 = 0;

    FUN_007e34b0(&iStack_12c);

    if (iStack_12c == 0) {

      apvStack_134[0] = (void *)0x0;

    }

    else {

      apvStack_134[0] = (void *)(((int)pvStack_128 - iStack_12c) / 0x934);

    }

    fwrite(apvStack_134,4,1,_File);

    local_154 = 0;

    iStack_150 = 0;

    while( true ) {

      iVar4 = 0;

      if ((iStack_12c == 0) || ((uint)(((int)pvStack_128 - iStack_12c) / 0x934) <= local_154))

      break;

      _Str = (void *)(iStack_12c + iStack_150);

      fwrite(_Str,0x930,1,_File);

      if (0 < *(short *)((int)_Str + 0x92c)) {

        sStack_158 = 0;

        do {

          fwrite((void *)(*(int *)((int)_Str + 0x930) + sStack_158),0x14,1,_File);

          sStack_158 = sStack_158 + 0x14;

          iVar4 = iVar4 + 1;

        } while (iVar4 < *(short *)((int)_Str + 0x92c));

      }

      local_154 = local_154 + 1;

      iStack_150 = iStack_150 + 0x934;

    }

    pvStack_148 = (void *)0x0;

    FUN_007d6e20(&stack0xfffffea4,&pvStack_148);

    fwrite(&stack0xfffffea4,4,1,_File);

    fwrite(pvStack_148,0x11c,0,_File);

    CoTaskMemFree(pvStack_148);

    apvStack_144[0] = (void *)0x0;

    FUN_007d51b0(&stack0xfffffea4,apvStack_144);

    fwrite(&stack0xfffffea4,4,1,_File);

    fwrite(apvStack_144[0],300,0,_File);

    CoTaskMemFree(apvStack_144[0]);

    pvStack_13c = (void *)0x0;

    FUN_007d30c0(&stack0xfffffea4,&pvStack_13c);

    fwrite(&sStack_158,4,1,_File);

    fwrite(pvStack_138,0x178,sStack_158,_File);

    CoTaskMemFree(pvStack_138);

    sStack_158 = 0;

    pvStack_148 = (void *)0x0;

    FUN_007d15c0(&sStack_158,&pvStack_148);

    fwrite(&sStack_158,4,1,_File);

    fwrite(pvStack_148,0x164,sStack_158,_File);

    CoTaskMemFree(pvStack_148);

    sStack_158 = 0;

    pvStack_13c = (void *)0x0;

    FUN_007d0250(&sStack_158,&pvStack_13c);

    fwrite(&sStack_158,4,1,_File);

    fwrite(pvStack_13c,0x120,sStack_158,_File);

    CoTaskMemFree(pvStack_13c);

    sStack_158 = 0;

    apvStack_134[0] = (void *)0x0;

    FUN_007cf0c0(&sStack_158,apvStack_134);

    fwrite(&sStack_158,4,1,_File);

    fwrite(apvStack_134[0],0x118,sStack_158,_File);

    CoTaskMemFree(apvStack_134[0]);

    fclose(_File);

    if (pvStack_128 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(pvStack_128);

    }

  }

  ExceptionList = local_c;

  return;

}
