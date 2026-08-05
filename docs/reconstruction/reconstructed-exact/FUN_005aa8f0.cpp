// =============================================================================
// FUN_005aa8f0
// -----------------------------------------------------------------------------
// Stable ID: aa_005aa8f0
// Address:   0x005aa8f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005aa8f0 @ 0x005aa8f0
// Stable ID: aa_005aa8f0
// Embedded strings (evidence for future rename):
//   - "Couldn\'t open %s for writing, failing mission xml save."
//   - "C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGMapText.cpp"
//   - "<?xml version=\"1.0\" encoding=\"iso-8859-1\" ?>\r\n"
//   - "<Map name=\"%s\" continentObjectID=\"%d\"> <!-- don\'t ever edit this -->\r\n"
//   - "\t<Description>%s</Description>\r\n"
//   - "\t<Name>%s</Name> <!-- don\'t ever edit this -->\r\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~278 non-empty decompiler lines.
//  - Control keywords: if×19, while×14, do×12, for×3, return×2, goto×2.
//  - Notable callees: fprintf×5, FUN_007a4480×4, c_str×4, CONCAT44×3, _snprintf×2, FUN_00403450, FUN_0053fff0, FUN_005aa670.
//  - Strings: "Couldn\'t open %s for writing, failing mission xml save."; "C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGMapText.cpp"; "<?xml version=\"1.0\" encoding=\"iso-8859-1\" ?>\r\n"; "%s\" continentObjectID=\"%d\"> <!-- don\'t ever edit this -->\r\n".
//  - Return sites: 2.

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

void __fastcall FUN_005aa8f0(int param_1)



{

  char cVar1;

  int *piVar2;

  int *piVar3;

  char *pcVar4;

  char *pcVar5;

  FILE *_File;

  uint32_t /* width from decompiler */ uVar6;

  wchar_t *pwVar7;

  wchar_t *pwVar8;

  uint uVar9;

  char *pcVar10;

  int iVar11;

  int *piVar12;

  char *pcVar13;

  int iVar14;

  code *pcVar15;

  FILE *pFVar16;

  uint64_t uVar17;

  int local_aac;

  int local_aa8;

  uint local_aa4;

  FILE *local_aa0;

  int local_a9c;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_a98 [28];

  char *local_a7c;

  char local_a78 [127];

  char cStack_9f9;

  uint32_t /* width from decompiler */ local_9f8;

  uint32_t /* width from decompiler */ local_9f4;

  uint8_t local_9f0;

  char local_8f0 [264];

  char acStack_7e8 [2004];

  void *local_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ uStack_c;

  

  uStack_c = 0xffffffff;

  puStack_10 = &LAB_009a64bb;

  local_14 = ExceptionList;

  ExceptionList = &local_14;

  local_aa8 = param_1;

  FUN_005aa670();

  local_9f8 = DAT_00a95f84;

  pcVar4 = (char *)(*(int *)(param_1 + 8) + 0xb4);

  local_9f0 = DAT_00a95f8c;

  local_9f4 = DAT_00a95f88;

  pcVar5 = pcVar4;

  do {

    cVar1 = *pcVar5;

    pcVar5 = pcVar5 + 1;

  } while (cVar1 != '\0');

  pcVar13 = &cStack_9f9;

  do {

    pcVar10 = pcVar13 + 1;

    pcVar13 = pcVar13 + 1;

  } while (*pcVar10 != '\0');

  pcVar10 = pcVar4;

  for (uVar9 = (uint)((int)pcVar5 - (int)pcVar4) >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {

    *(uint32_t /* width from decompiler */ *)pcVar13 = *(uint32_t /* width from decompiler */ *)pcVar10;

    pcVar10 = pcVar10 + 4;

    pcVar13 = pcVar13 + 4;

  }

  for (uVar9 = (int)pcVar5 - (int)pcVar4 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {

    *pcVar13 = *pcVar10;

    pcVar10 = pcVar10 + 1;

    pcVar13 = pcVar13 + 1;

  }

  pcVar5 = &cStack_9f9;

  do {

    pcVar4 = pcVar5;

    pcVar5 = pcVar4 + 1;

  } while (pcVar4[1] != '\0');

  *(uint32_t /* width from decompiler */ *)(pcVar4 + 1) = DAT_00a9eaf0;

  pcVar4[5] = DAT_00a9eaf4;

  _File = fopen((char *)&local_9f8,"wb");

  pcVar15 = fprintf_exref;

  local_aa0 = _File;

  if (_File == (FILE *)0x0) {

    piVar12 = &local_aa8;

    uVar17 = CONCAT44(&local_9f8,"Couldn\'t open %s for writing, failing mission xml save.");

    uVar6 = FUN_0076cec0();

    vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGMapText.cpp",0x227,3,uVar6,

                   piVar12,uVar17);

    ExceptionList = local_14;

    return;

  }

  fprintf(_File,"<?xml version=\"1.0\" encoding=\"iso-8859-1\" ?>\r\n");

  fprintf(_File,"<Map name=\"%s\" continentObjectID=\"%d\"> <!-- don\'t ever edit this -->\r\n",

          *(int *)(param_1 + 8) + 0xb4);

  fprintf(_File,"\t<Description>%s</Description>\r\n",param_1 + 0x10c);

  fprintf(_File,"\t<Name>%s</Name> <!-- don\'t ever edit this -->\r\n",param_1 + 0xc);

  local_aac = param_1 + 0x9dc;

  local_aa4 = 0;

  do {

    local_8f0[0] = '\0';

    if (0 < *(int *)(*(int *)(param_1 + 8) + 0xfc)) {

      iVar14 = 0;

      local_a9c = FUN_0053fff0();

      iVar11 = *(int *)(local_a9c + 4);

      if (*(char *)(iVar11 + 0x1d) != '\0') {

        FUN_007a4480(0);

        FUN_007a4480(0);

      }

      *(uint8_t *)(iVar11 + 0x1d) = 1;

      do {

        iVar11 = *(int *)(local_a9c + 4);

        if (*(char *)(iVar11 + 0x1d) == '\0') {

          FUN_007a4480(0);

          FUN_007a4480(0);

        }

        if (iVar14 == 0) {

          iVar14 = *(int *)(iVar11 + 0x14);

        }

        else {

          iVar14 = *(int *)(iVar14 + 0x14);

        }

        if (iVar14 == 0) {

          iVar11 = 0;

        }

        else {

          iVar11 = *(int *)(iVar14 + 8);

        }

        if (iVar11 == 0) goto LAB_005aab71;

      } while ((*(int *)(iVar11 + 0x120) != *(int *)(*(int *)(param_1 + 8) + 0xfc)) ||

              (*(byte *)(iVar11 + 0x124) != local_aa4));

      local_a7c = local_a78;

      uVar6 = (*(code *)PTR_FUN_00af8c9c)();

      FUN_00403450(iVar11 + 0x16,uVar6);

      pcVar5 = local_a7c;

      do {

        cVar1 = *pcVar5;

        pcVar5[(int)(local_8f0 + -(int)local_a7c)] = cVar1;

        pcVar5 = pcVar5 + 1;

      } while (cVar1 != '\0');

      if (local_a7c != local_a78) {

        free(local_a7c);

      }

LAB_005aab71:

      pcVar15 = fprintf_exref;

      *(uint8_t *)(*(int *)(local_a9c + 4) + 0x1d) = 0;

    }

    uVar9 = local_aa4;

    uVar17 = CONCAT44(local_aa4,

                      "\t<Layer index=\"%d\" objectiveID=\"%d\" objectiveName=\"%s\"> <!-- don\'t ever edit this -->\r\n"

                     );

    pFVar16 = _File;

    (*pcVar15)();

    (*pcVar15)(_File,"\t\t<Name>%s</Name>\r\n",local_aac + -0x100,pFVar16,uVar17);

    (*pcVar15)(_File,"\t\t<Description>%s</Description>\r\n",local_aac);

    (*pcVar15)(_File,"\t</Layer>\r\n");

    local_aac = local_aac + 0x8d0;

    local_aa4 = uVar9 + 1;

  } while ((int)local_aa4 < 8);

  if ((*(int *)(param_1 + 0x50fc) == 0) ||

     ((*(int *)(param_1 + 0x5100) - *(int *)(param_1 + 0x50fc)) / 200 == 0)) {

    pcVar5 = (char *)(param_1 + 0x4f68);

    do {

      cVar1 = *pcVar5;

      pcVar5 = pcVar5 + 1;

    } while (cVar1 != '\0');

    if (pcVar5 == (char *)(param_1 + 0x4f69)) {

      pcVar5 = (char *)(param_1 + 0x5030);

      do {

        cVar1 = *pcVar5;

        pcVar5 = pcVar5 + 1;

      } while (cVar1 != '\0');

      if (pcVar5 == (char *)(param_1 + 0x5031)) goto LAB_005aad7e;

    }

  }

  (*pcVar15)(_File,

             "\t<Music minTransitionDelay=\"%.02f\" maxTransitionDelay=\"%.02f\" CanSelectionRepeat=\"%d\" UseIntensity=\"%d\">\r\n"

             ,(double)*(float *)(param_1 + 0x4f60),(double)*(float *)(param_1 + 0x4f64),

             *(char *)(param_1 + 0x4f5c) == '\x01');

  pcVar5 = (char *)(param_1 + 0x4f68);

  do {

    cVar1 = *pcVar5;

    pcVar5 = pcVar5 + 1;

  } while (cVar1 != '\0');

  if (pcVar5 != (char *)(param_1 + 0x4f69)) {

    (*pcVar15)(_File,

               "\t\t<LoadMusic name=\"%s\" looping=\"%d\" stopOnLoadComplete=\"%d\" fadein=\"%.02f\" fadeout=\"%.02f\"/>\r\n"

               ,(char *)(param_1 + 0x4f68),*(uint8_t *)(param_1 + 0x500d),

               *(uint8_t *)(param_1 + 0x500e),(double)*(float *)(param_1 + 0x4ff4),

               (double)*(float *)(param_1 + 0x4ff8));

  }

  iVar11 = *(int *)(param_1 + 0x50fc);

  if (iVar11 != *(int *)(param_1 + 0x5100)) {

    do {

      (*pcVar15)(_File,

                 "\t\t<BackgroundMusic name=\"%s\" minIntensity=\"%d\" maxIntensity=\"%d\" fadein=\"%.02f\" fadeout=\"%.02f\"/>\r\n"

                 ,iVar11,*(uint32_t /* width from decompiler */ *)(iVar11 + 0xb0),*(uint32_t /* width from decompiler */ *)(iVar11 + 0xb4),

                 (double)*(float *)(iVar11 + 0x8c),(double)*(float *)(iVar11 + 0x90));

      iVar11 = iVar11 + 200;

    } while (iVar11 != *(int *)(param_1 + 0x5100));

  }

  pcVar5 = (char *)(param_1 + 0x5030);

  do {

    cVar1 = *pcVar5;

    pcVar5 = pcVar5 + 1;

  } while (cVar1 != '\0');

  if (pcVar5 != (char *)(param_1 + 0x5031)) {

    (*pcVar15)(_File,

               "\t\t<DefaultMusic name=\"%s\" looping=\"%d\" stopOnLoadComplete=\"%d\" fadein=\"%.02f\" fadeout=\"%.02f\"/>\r\n"

               ,(char *)(param_1 + 0x5030),*(uint8_t *)(param_1 + 0x50d5),

               *(uint8_t *)(param_1 + 0x50d6),(double)*(float *)(param_1 + 0x50bc),

               (double)*(float *)(param_1 + 0x50c0));

  }

  (*pcVar15)(_File);

LAB_005aad7e:

  if ((*(int *)(param_1 + 0x5110) != 0) &&

     (piVar12 = (int *)**(int **)(param_1 + 0x510c), piVar12 != *(int **)(param_1 + 0x510c))) {

    do {

      pwVar7 = std::

               basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

               ::c_str((basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

                        *)(piVar12 + 3));

      pwVar8 = std::

               basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

               ::c_str((basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

                        *)(piVar12[10] + 4));

      iVar11 = *(int *)piVar12[10];

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(abStack_a98,"");

      uStack_c = 0;

      if (iVar11 != -1) {

        _snprintf(acStack_7e8,2000,"index=\"%i\" ");

        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

        operator+=(abStack_a98,acStack_7e8);

      }

      if (*(int *)(piVar12[10] + 0x34) != 0) {

        std::basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>::

        c_str((basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

               *)(piVar12[10] + 0x20));

        _snprintf(acStack_7e8,2000,"description=\"%s\" ");

        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

        operator+=(abStack_a98,acStack_7e8);

      }

      uVar17 = CONCAT44(pwVar7,pwVar8);

      pcVar5 = std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

               c_str(abStack_a98);

      fprintf(local_aa0,"\t<text name=\"%s\" %s>%s</text>\r\n",pwVar7,pcVar5,uVar17);

      if (*(char *)((int)piVar12 + 0x2d) == '\0') {

        piVar2 = (int *)piVar12[2];

        if (*(char *)((int)piVar2 + 0x2d) == '\0') {

          cVar1 = *(char *)(*piVar2 + 0x2d);

          piVar12 = piVar2;

          piVar2 = (int *)*piVar2;

          while (cVar1 == '\0') {

            cVar1 = *(char *)(*piVar2 + 0x2d);

            piVar12 = piVar2;

            piVar2 = (int *)*piVar2;

          }

        }

        else {

          cVar1 = *(char *)(piVar12[1] + 0x2d);

          piVar3 = (int *)piVar12[1];

          piVar2 = piVar12;

          while ((piVar12 = piVar3, cVar1 == '\0' && (piVar2 == (int *)piVar12[2]))) {

            cVar1 = *(char *)(piVar12[1] + 0x2d);

            piVar3 = (int *)piVar12[1];

            piVar2 = piVar12;

          }

        }

      }

      uStack_c = 0xffffffff;

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(abStack_a98);

      _File = local_aa0;

      pcVar15 = fprintf_exref;

    } while (piVar12 != *(int **)(local_aa8 + 0x510c));

  }

  FUN_005aa890();

  (*pcVar15)(_File,"</Map>\r\n");

  fclose(_File);

  ExceptionList = local_14;

  return;

}
