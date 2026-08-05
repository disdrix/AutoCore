// =============================================================================
// Inv_FILE_BTN_DROP_ELEMENT_0078e380
// -----------------------------------------------------------------------------
// Stable ID: aa_0078e380
// Address:   0x0078e380  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Inv_FILE_BTN_DROP_ELEMENT_0078e380 @ 0x0078e380
// Stable ID: aa_0078e380
// Embedded strings (evidence for future rename):
//   - "DYNAMIC_RESIZE"
//   - "true"
//   - "FILE_WND_BG_TEXTURE"
//   - "FILE_WND_EDIT"
//   - "FILE_BTN_DROP_DOWN"
//   - "FILE_BTN_DROP_ELEMENT"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~130 non-empty decompiler lines.
//  - Control keywords: if×9, return×6, do×4, while×4, goto×1.
//  - Notable callees: SysFreeString×8, _wcsicmp×8, FUN_00402d50×4, FUN_0040d230×3, FUN_007a8b00×2, FUN_0078e380, FUN_007933a0, free.
//  - Strings: "DYNAMIC_RESIZE"; "true"; "FILE_WND_BG_TEXTURE"; "FILE_WND_EDIT".
//  - Return sites: 6.

/*
 * Behavioral notes:
 * String-driven rename evidence: "FILE_BTN_DROP_ELEMENT"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Inv_FILE_BTN_DROP_ELEMENT_0078e380(int param_1,int *param_2,int param_3)



{

  char cVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  char *pcVar4;

  char *pcVar5;

  wchar_t *local_94;

  uint8_t *puStack_90;

  uint8_t auStack_8c [128];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009bb466;

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

  iVar2 = _wcsicmp(local_94,L"DYNAMIC_RESIZE");

  if (iVar2 == 0) {

    SysFreeString(local_94);

    local_94 = (wchar_t *)0x0;

    (**(code **)(*param_2 + 0x68))(param_2,&local_94);

    iVar2 = _wcsicmp(local_94,L"true");

    *(bool *)(param_1 + 0x4fc) = iVar2 == 0;

    SysFreeString(local_94);

    ExceptionList = local_c;

    return;

  }

  iVar2 = _wcsicmp(local_94,L"FILE_WND_BG_TEXTURE");

  if (iVar2 == 0) {

    SysFreeString(local_94);

    local_94 = (BSTR)0x0;

    (**(code **)(*param_2 + 0x68))(param_2,&local_94);

    pcVar5 = (char *)(param_1 + 0x4ff);

    *pcVar5 = '\0';

    puVar3 = (uint32_t /* width from decompiler */ *)FUN_00402d50(local_94);

    pcVar4 = (char *)*puVar3;

    do {

      cVar1 = *pcVar4;

      *pcVar5 = cVar1;

      pcVar4 = pcVar4 + 1;

      pcVar5 = pcVar5 + 1;

    } while (cVar1 != '\0');

  }

  else {

    iVar2 = _wcsicmp(local_94,L"FILE_WND_EDIT");

    if (iVar2 == 0) {

      FUN_0040d230();

      (**(code **)(*param_2 + 0x68))(param_2,&local_94);

      pcVar5 = (char *)(param_1 + 0x603);

      *pcVar5 = '\0';

      puVar3 = (uint32_t /* width from decompiler */ *)FUN_00402d50(local_94);

      pcVar4 = (char *)*puVar3;

      do {

        cVar1 = *pcVar4;

        *pcVar5 = cVar1;

        pcVar4 = pcVar4 + 1;

        pcVar5 = pcVar5 + 1;

      } while (cVar1 != '\0');

    }

    else {

      iVar2 = _wcsicmp(local_94,L"FILE_BTN_DROP_DOWN");

      if (iVar2 == 0) {

        FUN_0040d230();

        (**(code **)(*param_2 + 0x68))(param_2,&local_94);

        pcVar5 = (char *)(param_1 + 0x707);

        *pcVar5 = '\0';

        puVar3 = (uint32_t /* width from decompiler */ *)FUN_00402d50(local_94);

        pcVar4 = (char *)*puVar3;

        do {

          cVar1 = *pcVar4;

          *pcVar5 = cVar1;

          pcVar4 = pcVar4 + 1;

          pcVar5 = pcVar5 + 1;

        } while (cVar1 != '\0');

      }

      else {

        iVar2 = _wcsicmp(local_94,L"FILE_BTN_DROP_ELEMENT");

        if (iVar2 != 0) {

          iVar2 = _wcsicmp(local_94,L"START_LIST");

          if (iVar2 == 0) {

            FUN_007a8b00(param_2,param_1 + 0x918,param_1 + 0x91c,0);

            SysFreeString(local_94);

            ExceptionList = local_c;

            return;

          }

          iVar2 = _wcsicmp(local_94,L"SPACING_LIST");

          if (iVar2 == 0) {

            FUN_007a8b00(param_2,param_1 + 0x920,param_1 + 0x924,0);

            SysFreeString(local_94);

            ExceptionList = local_c;

            return;

          }

          FUN_007933a0(param_2,param_3);

          goto LAB_0078e637;

        }

        FUN_0040d230();

        (**(code **)(*param_2 + 0x68))(param_2,&local_94);

        pcVar5 = (char *)(param_1 + 0x80b);

        *pcVar5 = '\0';

        puVar3 = (uint32_t /* width from decompiler */ *)FUN_00402d50(local_94);

        pcVar4 = (char *)*puVar3;

        do {

          cVar1 = *pcVar4;

          *pcVar5 = cVar1;

          pcVar4 = pcVar4 + 1;

          pcVar5 = pcVar5 + 1;

        } while (cVar1 != '\0');

      }

    }

  }

  if (puStack_90 != auStack_8c) {

    free(puStack_90);

    SysFreeString(local_94);

    ExceptionList = local_c;

    return;

  }

LAB_0078e637:

  SysFreeString(local_94);

  ExceptionList = local_c;

  return;

}
