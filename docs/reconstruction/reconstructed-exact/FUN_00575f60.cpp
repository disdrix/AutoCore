// =============================================================================
// FUN_00575f60
// -----------------------------------------------------------------------------
// Stable ID: aa_00575f60
// Address:   0x00575f60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00575f60 @ 0x00575f60
// Stable ID: aa_00575f60
// Embedded strings (evidence for future rename):
//   - "crashsubmit.inc"
//   - ");

// READABILITY (auto CF):
//  - Body size: ~123 non-empty decompiler lines.
//  - Control keywords: if×6, do×6, while×6, for×3, return×1.
//  - Notable callees: _snprintf×7, fwrite×7, begin×3, CopyFileA×2, SetFileAttributesA×2, FUN_00575f60, GetTempFileNameA, GetTempPathA.
//  - Strings: "AAN"; "crashsubmit.inc"; "<script language=\'Javascript\'>\n"; "document._main.p_icf_24.value = \'%s\';\n".
//  - Return sites: 1.

  if (_File != (FILE *)0x0) {

    _snprintf(local_400,0x400,"
//   - "document._main.p_icf_24.value = \'%s\';\n"
//   - "document._main.p_subject.value = \'[aacrashlog]\';\n"
//   - "document._main.hidden_crashlog.value = \'"
//   - "\';\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

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

void FUN_00575f60(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                  *param_1,int param_2)



{

  char cVar1;

  BOOL BVar2;

  FILE *_File;

  char *pcVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ *puVar5;

  char *pcVar6;

  uint _Count;

  size_t _Size;

  FILE *_File_00;

  CHAR local_608 [260];

  CHAR local_504 [260];

  char local_400 [1024];

  

  GetTempPathA(0x104,local_504);

  GetTempFileNameA(local_504,"AAN",0,local_608);

  BVar2 = CopyFileA("crashsubmit.inc",local_608,0);

  if (BVar2 == 0) {

    SetFileAttributesA(local_608,0x80);

    CopyFileA("crashsubmit.inc",local_608,0);

  }

  SetFileAttributesA(local_608,0x80);

  _File = fopen(local_608,"a+");

  if (_File != (FILE *)0x0) {

    _snprintf(local_400,0x400,"<script language=\'Javascript\'>\n");

    pcVar3 = local_400;

    do {

      cVar1 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    fwrite(local_400,1,(int)pcVar3 - (int)(local_400 + 1),_File);

    if (param_2 != 0) {

      uVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 4 + param_2) + 0x160))();

      _snprintf(local_400,0x400,"document._main.p_icf_24.value = \'%s\';\n",uVar4);

      pcVar3 = local_400;

      do {

        cVar1 = *pcVar3;

        pcVar3 = pcVar3 + 1;

      } while (cVar1 != '\0');

      fwrite(local_400,1,(int)pcVar3 - (int)(local_400 + 1),_File);

    }

    _snprintf(local_400,0x400,"document._main.p_subject.value = \'[aacrashlog]\';\n");

    pcVar3 = local_400;

    do {

      cVar1 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    fwrite(local_400,1,(int)pcVar3 - (int)(local_400 + 1),_File);

    _snprintf(local_400,0x400,"document._main.hidden_crashlog.value = \'");

    pcVar3 = local_400;

    do {

      cVar1 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    fwrite(local_400,1,(int)pcVar3 - (int)(local_400 + 1),_File);

    puVar5 = (uint32_t /* width from decompiler */ *)

             std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::end

                       (param_1);

    pcVar3 = (char *)*puVar5;

    puVar5 = (uint32_t /* width from decompiler */ *)

             std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

             begin(param_1);

    for (pcVar6 = (char *)*puVar5; pcVar6 != pcVar3; pcVar6 = pcVar6 + 1) {

      if (*pcVar6 == '\'') {

        *pcVar6 = ' ';

      }

    }

    puVar5 = (uint32_t /* width from decompiler */ *)

             std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::end

                       (param_1);

    pcVar3 = (char *)*puVar5;

    puVar5 = (uint32_t /* width from decompiler */ *)

             std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

             begin(param_1);

    for (pcVar6 = (char *)*puVar5; pcVar6 != pcVar3; pcVar6 = pcVar6 + 1) {

      if (*pcVar6 == '\\') {

        *pcVar6 = '/';

      }

    }

    puVar5 = (uint32_t /* width from decompiler */ *)

             std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::end

                       (param_1);

    pcVar3 = (char *)*puVar5;

    puVar5 = (uint32_t /* width from decompiler */ *)

             std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

             begin(param_1);

    for (pcVar6 = (char *)*puVar5; pcVar6 != pcVar3; pcVar6 = pcVar6 + 1) {

      if (*pcVar6 == '\r') {

        *pcVar6 = '\\';

      }

    }

    _File_00 = _File;

    _Count = std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::size

                       (param_1);

    _Size = 1;

    pcVar3 = std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

             c_str(param_1);

    fwrite(pcVar3,_Size,_Count,_File_00);

    _snprintf(local_400,0x400,"\';\n");

    pcVar3 = local_400;

    do {

      cVar1 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    fwrite(local_400,1,(int)pcVar3 - (int)(local_400 + 1),_File);

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::clear

              (param_1);

    _snprintf(local_400,0x400,"</script>\n");

    pcVar3 = local_400;

    do {

      cVar1 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    fwrite(local_400,1,(int)pcVar3 - (int)(local_400 + 1),_File);

    fclose(_File);

    _snprintf(local_504,0x104,"%s.html",local_608);

    MoveFileExA(local_608,local_504,9);

    ShellExecuteA((HWND)0x0,(LPCSTR)0x0,local_504,(LPCSTR)0x0,(LPCSTR)0x0,1);

  }

  return;

}
