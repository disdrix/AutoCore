// READABILITY (auto CF):
//  - Body size: ~205 non-empty decompiler lines.
//  - Control keywords: if×23, do×2, while×2, return×2, for×1, goto×1.
//  - Notable callees: FUN_00984ee0×33, FUN_0076adc0×3, CONCAT31×2, FUN_0043e5b0×2, FUN_00969830×2, vog_LogMessage×2, CreateDirectoryA, EnterCriticalSection.
//  - Strings: "../effects"; "C:\\vog\\1_code\\vog_14_117_branch\\libND\\NDAssetManager.cpp"; "/precompile"; "C:\\vog\\1_code\\palantir\\palantir\\assets\\assManager.cpp".
//  - Return sites: 2.

// =============================================================================
// Named_assManager
// -----------------------------------------------------------------------------
// Stable ID: aa_007b75b0
// Address:   0x007b75b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "assManager"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_assManager(uint32_t /* width from decompiler */ *param_1,char param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  char cVar2;

  int iVar3;

  BOOL BVar4;

  LPCSTR ***ppppCVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ *puVar7;

  FILE *_File;

  int iVar8;

  undefined *puVar9;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_4c [4];

  LPCSTR **local_48 [5];

  uint local_34;

  uint8_t local_30 [6];

  uint local_2a;

  void *local_c;

  uint8_t *puStack_8;

  uint local_4;

  

  puVar1 = param_1;

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b1489;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

            (local_4c,"../effects");

  iVar8 = 0;

  local_4 = 0;

  do {

    ppppCVar5 = (LPCSTR ***)local_48[0];

    if (local_34 < 0x10) {

      ppppCVar5 = local_48;

    }

    cVar2 = FUN_0076adc0(ppppCVar5);

    if (cVar2 == '\0') {

      ppppCVar5 = (LPCSTR ***)local_48[0];

      if (local_34 < 0x10) {

        ppppCVar5 = local_48;

      }

      cVar2 = FUN_0076adc0(ppppCVar5);

      if (cVar2 == '\0') {

        iVar3 = stat(ppppCVar5,local_30);

        if (iVar3 == 0) {

          param_1 = (uint32_t /* width from decompiler */ *)(CONCAT31(param_1._1_3_,(char)(local_2a >> 0xf)) & 0xffffff01);

          if ((local_2a >> 0xf & 1) != 0) {

            FUN_0076b080(1);

          }

        }

      }

      else {

        FUN_0076ba10(ppppCVar5,1);

      }

      BVar4 = CreateDirectoryA((LPCSTR)ppppCVar5,(LPSECURITY_ATTRIBUTES)0x0);

      if (BVar4 == 0) {

        ppppCVar5 = (LPCSTR ***)local_48[0];

        if (local_34 < 0x10) {

          ppppCVar5 = local_48;

        }

        uVar6 = FUN_0076cec0(&param_2,

                             "Could not create the directory \"%s\", using .exe working directory for precompiled effect storage"

                             ,ppppCVar5);

        vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libND\\NDAssetManager.cpp",0x282,2,uVar6

                      );

        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=

                  (local_4c,".");

        goto LAB_007b76d2;

      }

    }

    if (iVar8 == 0) {

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator+=

                (local_4c,"/precompile");

    }

    iVar8 = iVar8 + 1;

    if (1 < iVar8) {

LAB_007b76d2:

      iVar8 = DAT_00d1f058;

      ppppCVar5 = (LPCSTR ***)local_48[0];

      if (local_34 < 0x10) {

        ppppCVar5 = local_48;

      }

      cVar2 = FUN_0076adc0(ppppCVar5);

      if (cVar2 != '\0') {

        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=

                  ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

                   (iVar8 + 0xb4),(char *)ppppCVar5);

      }

      FUN_00969830(local_4c);

      *(uint8_t *)(DAT_00d1f058 + 0xd0) = 1;

      FUN_00754280();

      FUN_00989ef0(0);

      if ((*(byte *)(puVar1 + 1) & 1) != 0) {

        param_1 = operator_new(0x4c);

        local_4._0_1_ = 1;

        if (param_1 == (void *)0x0) {

          param_1 = (uint32_t /* width from decompiler */ *)0x0;

        }

        else {

          param_1 = (uint32_t /* width from decompiler */ *)FUN_00423be0(param_1);

        }

        local_4 = (uint)local_4._1_3_ << 8;

        puVar1[2] = param_1;

        cVar2 = FUN_0043e5b0(&param_1);

        if (cVar2 == '\0') {

          FUN_0043c4f0(&param_1);

        }

        else {

          vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\assets\\assManager.cpp",0x26d,3,

                         "Adding duplicate resolver");

        }

        puVar9 = &DAT_00d1e570;

        do {

          FUN_00969830(puVar9);

          puVar9 = puVar9 + 0x1c;

        } while ((int)puVar9 < 0xd1e7a0);

      }

      if ((*(byte *)(puVar1 + 1) & 2) != 0) {

        puVar7 = operator_new(0x5c);

        if (puVar7 == (uint32_t /* width from decompiler */ *)0x0) {

          puVar7 = (uint32_t /* width from decompiler */ *)0x0;

        }

        else {

          puVar7[1] = 0;

          local_4 = CONCAT31(local_4._1_3_,3);

          *puVar7 = &PTR_FUN_00aa1f1c;

          param_1 = puVar7;

          FUN_00983940(puVar7 + 2);

        }

        local_4 = local_4 & 0xffffff00;

        puVar1[3] = puVar7;

        iVar8 = DAT_00d1f058;

        param_1 = puVar7;

        cVar2 = FUN_0043e5b0(&param_1);

        if (cVar2 == '\0') {

          if (*(char *)(iVar8 + 0x84) != '\0') {

            EnterCriticalSection((LPCRITICAL_SECTION)(iVar8 + 0x6c));

          }

          local_4._0_1_ = 4;

          FUN_0043c830(&param_1);

          local_4 = (uint)local_4._1_3_ << 8;

          if (*(char *)(iVar8 + 0x84) != '\0') {

            LeaveCriticalSection((LPCRITICAL_SECTION)(iVar8 + 0x6c));

          }

        }

        else {

          iVar8 = FUN_0076d1b0("C:\\vog\\1_code\\palantir\\palantir\\assets\\assManager.cpp",0x26d,

                               "Adding duplicate resolver");

          if (iVar8 == 3) {

            _File = fopen("c:\\VOGCRASH.txt","w");

            if (_File != (FILE *)0x0) {

              fprintf(_File,"errReport::Massive failure EH_Abort: F:%s l:%d s:%d d:%s\n",

                      "C:\\vog\\1_code\\palantir\\palantir\\assets\\assManager.cpp",0x26d,3,

                      "Adding duplicate resolver");

              fclose(_File);

            }

            raise(0x16);

                    /* WARNING: Subroutine does not return */

            ExitProcess(3);

          }

        }

        FUN_00984ee0(1);

        FUN_00984ee0(1);

        FUN_00984ee0(1);

        FUN_00984ee0(1);

        FUN_00984ee0(1);

        if (param_2 == '\0') {

          FUN_00984ee0(1);

          FUN_00984ee0(1);

          FUN_00984ee0(1);

          FUN_00984ee0(1);

          FUN_00984ee0(1);

          FUN_00984ee0(1);

          FUN_00984ee0(1);

          FUN_00984ee0(1);

          FUN_00984ee0(1);

          FUN_00984ee0(1);

          FUN_00984ee0(1);

          FUN_00984ee0(1);

          FUN_00984ee0(1);

          FUN_00984ee0(1);

          FUN_00984ee0(1);

          FUN_00984ee0(1);

          FUN_00984ee0(1);

          FUN_00984ee0(1);

          FUN_00984ee0(1);

          FUN_00984ee0(1);

          FUN_00984ee0(1);

          FUN_00984ee0(1);

          FUN_00984ee0(1);

          FUN_00984ee0(1);

          FUN_00984ee0(1);

          FUN_00984ee0(1);

          FUN_00984ee0(1);

          FUN_00984ee0(1);

        }

      }

      local_4 = 0xffffffff;

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_4c);

      ExceptionList = local_c;

      return;

    }

  } while( true );

}
