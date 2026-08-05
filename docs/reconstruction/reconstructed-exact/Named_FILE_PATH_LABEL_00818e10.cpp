// =============================================================================
// Named_FILE_PATH_LABEL_00818e10
// -----------------------------------------------------------------------------
// Stable ID: aa_00818e10
// Address:   0x00818e10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_FILE_PATH_LABEL_00818e10 @ 0x00818e10
// Stable ID: aa_00818e10
// Embedded strings (evidence for future rename):
//   - "FILE_PATH_LABEL"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: SysFreeString×2, FUN_00403450, FUN_007933a0, FUN_00818e10, _wcsicmp, free.
//  - Strings: "FILE_PATH_LABEL".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * String-driven rename evidence: "FILE_PATH_LABEL"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Named_FILE_PATH_LABEL_00818e10(int param_1,int *param_2,int param_3)



{

  char cVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  char *pcVar4;

  uint32_t /* width from decompiler */ unaff_EBP;

  wchar_t *local_94;

  char *pcStack_90;

  char acStack_8c [128];

  void *pvStack_c;

  uint8_t *puStack_8;

  uint local_4;

  

  puStack_8 = &LAB_009b834d;

  pvStack_c = ExceptionList;

  local_94 = (wchar_t *)0x0;

  local_4 = 0;

  ExceptionList = &pvStack_c;

  if ((param_2 != (int *)0x0) && (ExceptionList = &pvStack_c, param_3 != 0)) {

    ExceptionList = &pvStack_c;

    (**(code **)(*param_2 + 0x1c))(param_2,&local_94);

    iVar2 = _wcsicmp(L"FILE_PATH_LABEL",local_94);

    if (iVar2 == 0) {

      SysFreeString(local_94);

      local_94 = (BSTR)0x0;

      (**(code **)(*param_2 + 0x68))(param_2,&local_94);

      *(uint8_t *)(param_1 + 0x4fc) = 0;

      uVar3 = (*(code *)PTR_FUN_00af8c9c)();

      FUN_00403450(unaff_EBP,uVar3);

      pcVar4 = pcStack_90;

      do {

        cVar1 = *pcVar4;

        pcVar4[(param_1 + 0x4fc) - (int)pcStack_90] = cVar1;

        pcVar4 = pcVar4 + 1;

      } while (cVar1 != '\0');

      local_4 = local_4 & 0xffffff00;

      if (pcStack_90 != acStack_8c) {

        free(pcStack_90);

      }

    }

    else {

      FUN_007933a0(param_2,param_3);

    }

  }

  local_4 = 0xffffffff;

  SysFreeString(local_94);

  ExceptionList = pvStack_c;

  return;

}
