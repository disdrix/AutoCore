// =============================================================================
// Named_TAB_BUTTON_FILE_00823190
// -----------------------------------------------------------------------------
// Stable ID: aa_00823190
// Address:   0x00823190  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_TAB_BUTTON_FILE_00823190 @ 0x00823190
// Stable ID: aa_00823190
// Embedded strings (evidence for future rename):
//   - "TAB_BUTTON_FILE"
//   - "TAB_NAME_FILE"
//   - "TAB_NAME"
//   - "INACTIVE_OFFSET"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~102 non-empty decompiler lines.
//  - Control keywords: if×10, goto×4, do×3, while×3, return×2.
//  - Notable callees: SysFreeString×4, _wcsicmp×4, FUN_00402d50×3, free×2, FUN_0040d230, FUN_007933a0, FUN_007a8b00, FUN_00823190.
//  - Strings: "TAB_BUTTON_FILE"; "TAB_NAME_FILE"; "TAB_NAME"; "INACTIVE_OFFSET".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * String-driven rename evidence: "TAB_BUTTON_FILE"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Named_TAB_BUTTON_FILE_00823190(int param_1,int *param_2,int param_3)



{

  char cVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  char *pcVar4;

  char *pcVar5;

  bool bVar6;

  wchar_t *local_94;

  uint8_t *puStack_90;

  uint8_t auStack_8c [128];

  void *local_c;

  uint8_t *puStack_8;

  uint local_4;

  

  puStack_8 = &LAB_009b84bb;

  local_c = ExceptionList;

  local_94 = (wchar_t *)0x0;

  local_4 = 0;

  if ((param_2 == (int *)0x0) || (param_3 == 0)) {

    local_4 = 0xffffffff;

    ExceptionList = &local_c;

    SysFreeString((BSTR)0x0);

    ExceptionList = local_c;

    return;

  }

  ExceptionList = &local_c;

  (**(code **)(*param_2 + 0x1c))(param_2,&local_94);

  iVar2 = _wcsicmp(L"TAB_BUTTON_FILE",local_94);

  if (iVar2 == 0) {

    SysFreeString(local_94);

    local_94 = (wchar_t *)0x0;

    (**(code **)(*param_2 + 0x68))(param_2,&local_94);

    if (local_94 == (wchar_t *)0x0) goto LAB_008233a7;

    puVar3 = (uint32_t /* width from decompiler */ *)FUN_00402d50(local_94);

    pcVar4 = (char *)*puVar3;

    pcVar5 = (char *)(param_1 + 0x4fe);

    do {

      cVar1 = *pcVar4;

      *pcVar5 = cVar1;

      pcVar4 = pcVar4 + 1;

      pcVar5 = pcVar5 + 1;

    } while (cVar1 != '\0');

    bVar6 = puStack_90 == auStack_8c;

  }

  else {

    iVar2 = _wcsicmp(L"TAB_NAME_FILE",local_94);

    if (iVar2 == 0) {

      SysFreeString(local_94);

      local_94 = (BSTR)0x0;

      (**(code **)(*param_2 + 0x68))(param_2,&local_94);

      if (local_94 != (BSTR)0x0) {

        puVar3 = (uint32_t /* width from decompiler */ *)FUN_00402d50(local_94);

        pcVar4 = (char *)*puVar3;

        pcVar5 = (char *)(param_1 + 0x602);

        do {

          cVar1 = *pcVar4;

          *pcVar5 = cVar1;

          pcVar4 = pcVar4 + 1;

          pcVar5 = pcVar5 + 1;

        } while (cVar1 != '\0');

        local_4 = local_4 & 0xffffff00;

        if (puStack_90 != auStack_8c) {

          free(puStack_90);

        }

      }

      goto LAB_008233a7;

    }

    iVar2 = _wcsicmp(L"TAB_NAME",local_94);

    if (iVar2 != 0) {

      iVar2 = _wcsicmp(L"INACTIVE_OFFSET",local_94);

      if (iVar2 == 0) {

        FUN_007a8b00(param_2,param_1 + 0x80c,param_1 + 0x810,0);

      }

      else {

        FUN_007933a0(param_2,param_3);

      }

      goto LAB_008233a7;

    }

    FUN_0040d230();

    (**(code **)(*param_2 + 0x68))(param_2,&local_94);

    if (local_94 == (wchar_t *)0x0) goto LAB_008233a7;

    puVar3 = (uint32_t /* width from decompiler */ *)FUN_00402d50(local_94);

    pcVar4 = (char *)*puVar3;

    pcVar5 = (char *)(param_1 + 0x706);

    do {

      cVar1 = *pcVar4;

      *pcVar5 = cVar1;

      pcVar4 = pcVar4 + 1;

      pcVar5 = pcVar5 + 1;

    } while (cVar1 != '\0');

    bVar6 = puStack_90 == auStack_8c;

  }

  local_4 = local_4 & 0xffffff00;

  if (!bVar6) {

    free(puStack_90);

  }

LAB_008233a7:

  local_4 = 0xffffffff;

  SysFreeString(local_94);

  ExceptionList = local_c;

  return;

}
