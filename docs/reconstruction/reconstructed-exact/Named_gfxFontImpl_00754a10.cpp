// READABILITY (auto CF):
//  - Body size: ~234 non-empty decompiler lines.
//  - Control keywords: if×19, goto×2, do×2, while×2, return×2, for×1.
//  - Notable callees: SelectObject×4, vog_LogMessage×3, CreateFontIndirectA×2, FUN_0076cec0×2, GetLastError×2, CreateCompatibleDC, CreateDIBSection, DeleteObject.
//  - Strings: "|Bold"; "|Italic"; "|Shadow"; "|Outline".
//  - Return sites: 2.

// =============================================================================
// Named_gfxFontImpl_00754a10
// -----------------------------------------------------------------------------
// Stable ID: aa_00754a10
// Address:   0x00754a10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "gfxFontImpl"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Type propagation algorithm not settling */



uint32_t /* width from decompiler */ __thiscall Named_gfxFontImpl_00754a10(uint param_1,char *param_2,int param_3)



{

  int iVar1;

  int iVar2;

  uint uVar3;

  HFONT pHVar4;

  HDC hdc;

  DWORD DVar5;

  HGDIOBJ h;

  BOOL BVar6;

  HBITMAP h_00;

  int iVar7;

  int unaff_ESI;

  BITMAPINFO *pBVar8;

  uint32_t /* width from decompiler */ uVar9;

  char *pcVar10;

  uint local_1d4;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_1d0 [4];

  uint32_t /* width from decompiler */ *******local_1cc [4];

  int local_1bc;

  uint local_1b8;

  uint local_1b4;

  LOGFONTA local_1b0;

  BITMAPINFO local_174;

  tagTEXTMETRICW local_148;

  char local_10c [256];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ada75;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  if (DAT_00d1a548 == '\0') {

    ExceptionList = &local_c;

    FUN_00754970();

  }

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_1d0,"");

  local_4 = 0;

  if ((param_1 & 1) != 0) {

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator+=

              (local_1d0,"|Bold");

  }

  if ((param_1 & 2) != 0) {

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator+=

              (local_1d0,"|Italic");

  }

  local_1b4 = param_1 & 4;

  if (local_1b4 != 0) {

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator+=

              (local_1d0,"|Shadow");

  }

  local_1d4 = param_1 & 8;

  if (local_1d4 != 0) {

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator+=

              (local_1d0,"|Outline");

  }

  if (local_1bc == 0) {

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=

              (local_1d0,"Normal");

  }

  else {

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::erase

              (local_1d0,0,1);

  }

  if (local_1b8 < 0x10) {

    local_1cc[0] = local_1cc;

  }

  _snprintf(local_10c,0x100,"%s %i (%s)",param_2,param_3,local_1cc[0]);

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=

            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

             (unaff_ESI + 0x18),local_10c);

  *(uint *)(unaff_ESI + 0x34) = param_1;

  local_1b0.lfItalic = (byte)(param_1 >> 1) & 1;

  local_1b0.lfFaceName[0] = '\0';

  local_1b0.lfFaceName[1] = '\0';

  local_1b0.lfFaceName[2] = '\0';

  local_1b0.lfFaceName[3] = '\0';

  local_1b0.lfFaceName[4] = '\0';

  local_1b0.lfFaceName[5] = '\0';

  local_1b0.lfFaceName[6] = '\0';

  local_1b0.lfFaceName[7] = '\0';

  local_1b0.lfFaceName[8] = '\0';

  local_1b0.lfFaceName[9] = '\0';

  local_1b0.lfFaceName[10] = '\0';

  local_1b0.lfFaceName[0xb] = '\0';

  local_1b0.lfFaceName[0xc] = '\0';

  local_1b0.lfFaceName[0xd] = '\0';

  local_1b0.lfFaceName[0xe] = '\0';

  local_1b0.lfFaceName[0xf] = '\0';

  local_1b0.lfFaceName[0x10] = '\0';

  local_1b0.lfFaceName[0x11] = '\0';

  local_1b0.lfFaceName[0x12] = '\0';

  local_1b0.lfFaceName[0x13] = '\0';

  local_1b0.lfFaceName[0x14] = '\0';

  local_1b0.lfFaceName[0x15] = '\0';

  local_1b0.lfFaceName[0x16] = '\0';

  local_1b0.lfFaceName[0x17] = '\0';

  local_1b0.lfWeight = (-(uint)((param_1 & 1) != 0) & 300) + 400;

  local_1b0.lfFaceName[0x18] = '\0';

  local_1b0.lfFaceName[0x19] = '\0';

  local_1b0.lfFaceName[0x1a] = '\0';

  local_1b0.lfFaceName[0x1b] = '\0';

  local_1b0.lfHeight = param_3;

  local_1b0.lfWidth = 0;

  local_1b0.lfEscapement = 0;

  local_1b0.lfOrientation = 0;

  local_1b0.lfUnderline = '\0';

  local_1b0.lfStrikeOut = '\0';

  local_1b0.lfCharSet = '\x01';

  local_1b0.lfOutPrecision = '\b';

  local_1b0.lfClipPrecision = '\0';

  local_1b0.lfQuality = 5;

  local_1b0.lfPitchAndFamily = '\0';

  local_1b0.lfFaceName[0x1c] = '\0';

  local_1b0.lfFaceName[0x1d] = '\0';

  local_1b0.lfFaceName[0x1e] = '\0';

  local_1b0.lfFaceName[0x1f] = '\0';

  if (param_3 < 0xe) {

    local_1b0.lfQuality = 3;

  }

  strncpy(local_1b0.lfFaceName,param_2,0x20);

  pHVar4 = CreateFontIndirectA(&local_1b0);

  *(HFONT *)(unaff_ESI + 0xa4) = pHVar4;

  if (pHVar4 == (HFONT)0x0) {

    pcVar10 = "Failed CreateFont.";

    uVar9 = 0x8e;

  }

  else {

    hdc = CreateCompatibleDC((HDC)0x0);

    *(HDC *)(unaff_ESI + 0xa8) = hdc;

    if (hdc == (HDC)0x0) {

      DVar5 = GetLastError();

      uVar9 = FUN_0076cec0(&local_1d4,"Failed CreateCompatibleDC %u",DVar5);

      vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxFontImpl.cpp",0x93,3,uVar9);

      goto LAB_00754e53;

    }

    SetMapMode(hdc,1);

    h = SelectObject(*(HDC *)(unaff_ESI + 0xa8),*(HGDIOBJ *)(unaff_ESI + 0xa4));

    BVar6 = GetTextMetricsW(*(HDC *)(unaff_ESI + 0xa8),&local_148);

    if (BVar6 == 0) {

      DVar5 = GetLastError();

      uVar9 = FUN_0076cec0(&local_1d4,"Failed GetTextMetrics %u",DVar5);

      vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxFontImpl.cpp",0x9c,3,uVar9);

      goto LAB_00754e53;

    }

    SelectObject(*(HDC *)(unaff_ESI + 0xa8),h);

    DeleteObject(*(HGDIOBJ *)(unaff_ESI + 0xa4));

    pHVar4 = CreateFontIndirectA(&local_1b0);

    *(HFONT *)(unaff_ESI + 0xa4) = pHVar4;

    if (pHVar4 == (HFONT)0x0) {

      pcVar10 = "Failed CreateFont.";

      uVar9 = 0xa5;

    }

    else {

      SelectObject(*(HDC *)(unaff_ESI + 0xa8),pHVar4);

      *(uint *)(unaff_ESI + 0x6c) = (uint)local_1b0.lfQuality;

      *(LONG *)(unaff_ESI + 0x74) = local_148.tmAscent;

      *(LONG *)(unaff_ESI + 0x78) = local_148.tmDescent;

      *(LONG *)(unaff_ESI + 0x80) = local_148.tmExternalLeading;

      *(WCHAR *)(unaff_ESI + 0x88) = local_148.tmFirstChar;

      *(LONG *)(unaff_ESI + 0x7c) = local_148.tmExternalLeading + local_148.tmHeight;

      *(LONG *)(unaff_ESI + 0x70) = local_148.tmHeight;

      *(LONG *)(unaff_ESI + 0x84) = local_148.tmMaxCharWidth;

      *(WCHAR *)(unaff_ESI + 0x8a) = local_148.tmLastChar;

      if (local_1b4 != 0) {

        *(LONG *)(unaff_ESI + 0x70) = local_148.tmHeight + 1;

        *(LONG *)(unaff_ESI + 0x84) = local_148.tmMaxCharWidth + 2;

      }

      if (local_1d4 != 0) {

        *(int *)(unaff_ESI + 0x70) = *(int *)(unaff_ESI + 0x70) + 2;

        *(int *)(unaff_ESI + 0x84) = *(int *)(unaff_ESI + 0x84) + 3;

      }

      iVar7 = *(int *)(DAT_00d1f044 + 0x70);

      iVar1 = *(int *)(DAT_00d1f044 + 0x6c);

      iVar2 = *(int *)(unaff_ESI + 0x84);

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x38) = 0x100;

      if (0x100 < iVar2 * 2) {

        do {

          if (iVar1 <= *(int *)(unaff_ESI + 0x38)) break;

          *(int *)(unaff_ESI + 0x38) = *(int *)(unaff_ESI + 0x38) * 2;

        } while (*(int *)(unaff_ESI + 0x38) < *(int *)(unaff_ESI + 0x84) * 2);

      }

      uVar3 = *(uint *)(unaff_ESI + 0x70);

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x3c) = 0x100;

      if (0x100 < (int)(uVar3 * 2)) {

        do {

          if (iVar7 <= *(int *)(unaff_ESI + 0x3c)) break;

          iVar1 = *(int *)(unaff_ESI + 0x3c) * 2;

          *(int *)(unaff_ESI + 0x3c) = iVar1;

        } while (iVar1 < *(int *)(unaff_ESI + 0x70) * 2);

      }

      *(uint *)(unaff_ESI + 0xb4) = uVar3;

      *(int *)(unaff_ESI + 0xb0) = iVar2;

      *(uint *)(unaff_ESI + 0x40) = *(uint *)(unaff_ESI + 0x3c) / uVar3;

      pBVar8 = &local_174;

      for (iVar7 = 0xb; iVar7 != 0; iVar7 = iVar7 + -1) {

        (pBVar8->bmiHeader).biSize = 0;

        pBVar8 = (BITMAPINFO *)&(pBVar8->bmiHeader).biWidth;

      }

      local_174.bmiHeader.biCompression = 0;

      local_174.bmiHeader.biSize = 0x28;

      local_174.bmiHeader.biPlanes = 1;

      local_174.bmiHeader.biBitCount = 0x20;

      local_174.bmiHeader.biWidth = iVar2;

      local_174.bmiHeader.biHeight = -uVar3;

      h_00 = CreateDIBSection(*(HDC *)(unaff_ESI + 0xa8),&local_174,0,(void **)(unaff_ESI + 0xac),

                              (HANDLE)0x0,0);

      *(HBITMAP *)(unaff_ESI + 0xa0) = h_00;

      if (h_00 != (HBITMAP)0x0) {

        SelectObject(*(HDC *)(unaff_ESI + 0xa8),h_00);

        SetTextColor(*(HDC *)(unaff_ESI + 0xa8),0xffffff);

        SetBkMode(*(HDC *)(unaff_ESI + 0xa8),1);

        SetTextAlign(*(HDC *)(unaff_ESI + 0xa8),0);

        local_4 = 0xffffffff;

        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

        ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_1d0);

        ExceptionList = local_c;

        return 0;

      }

      pcVar10 = "Failed CreateDIBSection.";

      uVar9 = 0xdc;

    }

  }

  vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxFontImpl.cpp",uVar9,3,pcVar10);

LAB_00754e53:

  local_4 = 0xffffffff;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_1d0);

  ExceptionList = local_c;

  return 0xffffffff;

}
