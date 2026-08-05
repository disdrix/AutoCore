// =============================================================================
// Named_FILE_WND_SELECTION_TEXT_0078b830
// -----------------------------------------------------------------------------
// Stable ID: aa_0078b830
// Address:   0x0078b830  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_FILE_WND_SELECTION_TEXT_0078b830 @ 0x0078b830
// Stable ID: aa_0078b830
// Embedded strings (evidence for future rename):
//   - "FILE_WND_BG_TEXTURE"
//   - "FILE_WND_SELECTION_TEXT"
//   - "FILE_BTN_SELECTION"
//   - "FILE_BTN_SELECTION_ALT"
//   - "NUM_VISIBLE_ELEMENTS"
//   - "%d;%d"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~153 non-empty decompiler lines.
//  - Control keywords: if×12, return×8, do×4, while×4, goto×1.
//  - Notable callees: SysFreeString×10, _wcsicmp×9, FUN_0040d230×4, FUN_00402d50×3, FUN_007a8b00×2, free×2, FUN_00403450, FUN_0078b830.
//  - Strings: "FILE_WND_BG_TEXTURE"; "FILE_WND_SELECTION_TEXT"; "FILE_BTN_SELECTION"; "FILE_BTN_SELECTION_ALT".
//  - Return sites: 8.

/*
 * Behavioral notes:
 * String-driven rename evidence: "FILE_WND_SELECTION_TEXT"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __thiscall Named_FILE_WND_SELECTION_TEXT_0078b830(int param_1,int *param_2,int param_3)



{

  char cVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  char *pcVar4;

  uint32_t /* width from decompiler */ *puVar5;

  char *pcVar6;

  uint32_t /* width from decompiler */ unaff_ESI;

  wchar_t *local_94;

  char *pcStack_90;

  char acStack_8c [128];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009bb451;

  local_c = ExceptionList;

  local_94 = (wchar_t *)0x0;

  local_4 = 0;

  if ((param_2 == (int *)0x0) || (param_3 == 0)) {

    ExceptionList = &local_c;

    SysFreeString((BSTR)0x0);

    ExceptionList = local_c;

    return;

  }

  ExceptionList = &local_c;

  (**(code **)(*param_2 + 0x1c))(param_2,&local_94);

  iVar2 = _wcsicmp(local_94,L"FILE_WND_BG_TEXTURE");

  if (iVar2 == 0) {

    SysFreeString(local_94);

    local_94 = (BSTR)0x0;

    (**(code **)(*param_2 + 0x68))(param_2,&local_94);

    *(uint8_t *)(param_1 + 0x570) = 0;

    uVar3 = (*(code *)PTR_FUN_00af8c9c)();

    FUN_00403450(unaff_ESI,uVar3);

    pcVar4 = pcStack_90;

    do {

      cVar1 = *pcVar4;

      pcVar4[(param_1 + 0x570) - (int)pcStack_90] = cVar1;

      pcVar4 = pcVar4 + 1;

    } while (cVar1 != '\0');

    if (pcStack_90 != acStack_8c) {

      free(pcStack_90);

      SysFreeString(local_94);

      ExceptionList = local_c;

      return;

    }

  }

  else {

    iVar2 = _wcsicmp(local_94,L"FILE_WND_SELECTION_TEXT");

    if (iVar2 == 0) {

      SysFreeString(local_94);

      local_94 = (BSTR)0x0;

      (**(code **)(*param_2 + 0x68))(param_2,&local_94);

      pcVar4 = (char *)(param_1 + 0x674);

      *pcVar4 = '\0';

      puVar5 = (uint32_t /* width from decompiler */ *)FUN_00402d50(local_94);

      pcVar6 = (char *)*puVar5;

      do {

        cVar1 = *pcVar6;

        *pcVar4 = cVar1;

        pcVar6 = pcVar6 + 1;

        pcVar4 = pcVar4 + 1;

      } while (cVar1 != '\0');

    }

    else {

      iVar2 = _wcsicmp(local_94,L"FILE_BTN_SELECTION");

      if (iVar2 == 0) {

        FUN_0040d230();

        (**(code **)(*param_2 + 0x68))(param_2,&local_94);

        pcVar4 = (char *)(param_1 + 0x778);

        *pcVar4 = '\0';

        puVar5 = (uint32_t /* width from decompiler */ *)FUN_00402d50(local_94);

        pcVar6 = (char *)*puVar5;

        do {

          cVar1 = *pcVar6;

          *pcVar4 = cVar1;

          pcVar6 = pcVar6 + 1;

          pcVar4 = pcVar4 + 1;

        } while (cVar1 != '\0');

      }

      else {

        iVar2 = _wcsicmp(local_94,L"FILE_BTN_SELECTION_ALT");

        if (iVar2 != 0) {

          iVar2 = _wcsicmp(local_94,L"NUM_VISIBLE_ELEMENTS");

          if (iVar2 == 0) {

            FUN_0040d230();

            (**(code **)(*param_2 + 0x68))(param_2,&local_94);

            iVar2 = swscanf(local_94,L"%d;%d",(int *)(param_1 + 0x56c),0);

            if (iVar2 == 2) {

              iVar2 = *(int *)(param_1 + 0x56c);

              SysFreeString(local_94);

              _DAT_00000000 = _DAT_00000000 - iVar2;

              ExceptionList = local_c;

              return;

            }

          }

          else {

            iVar2 = _wcsicmp(local_94,L"DISABLE_EMPTY_FIELDS");

            if (iVar2 == 0) {

              FUN_0040d230();

              (**(code **)(*param_2 + 0x68))(param_2,&local_94);

              iVar2 = _wcsicmp(local_94,L"true");

              *(bool *)(param_1 + 0x565) = iVar2 == 0;

              SysFreeString(local_94);

              ExceptionList = local_c;

              return;

            }

            iVar2 = _wcsicmp(local_94,L"START_LIST");

            if (iVar2 == 0) {

              FUN_007a8b00(param_2,param_1 + 0x980,param_1 + 0x984,0);

              SysFreeString(local_94);

              ExceptionList = local_c;

              return;

            }

            iVar2 = _wcsicmp(local_94,L"SPACING_LIST");

            if (iVar2 == 0) {

              FUN_007a8b00(param_2,param_1 + 0x988,param_1 + 0x98c,0);

              SysFreeString(local_94);

              ExceptionList = local_c;

              return;

            }

            FUN_007933a0(param_2,param_3);

          }

          goto LAB_0078bb81;

        }

        FUN_0040d230();

        (**(code **)(*param_2 + 0x68))(param_2,&local_94);

        pcVar4 = (char *)(param_1 + 0x87c);

        *pcVar4 = '\0';

        puVar5 = (uint32_t /* width from decompiler */ *)FUN_00402d50(local_94);

        pcVar6 = (char *)*puVar5;

        do {

          cVar1 = *pcVar6;

          *pcVar4 = cVar1;

          pcVar6 = pcVar6 + 1;

          pcVar4 = pcVar4 + 1;

        } while (cVar1 != '\0');

      }

    }

    if (pcStack_90 != acStack_8c) {

      free(pcStack_90);

      SysFreeString(local_94);

      ExceptionList = local_c;

      return;

    }

  }

LAB_0078bb81:

  SysFreeString(local_94);

  ExceptionList = local_c;

  return;

}
