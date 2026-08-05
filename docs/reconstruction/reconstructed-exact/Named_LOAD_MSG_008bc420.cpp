// =============================================================================
// Named_LOAD_MSG_008bc420
// -----------------------------------------------------------------------------
// Stable ID: aa_008bc420
// Address:   0x008bc420  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_LOAD_MSG_008bc420 @ 0x008bc420
// Stable ID: aa_008bc420
// Embedded strings (evidence for future rename):
//   - "LOAD_MSG"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~55 non-empty decompiler lines.
//  - Control keywords: if×4, do×1, while×1, return×1.
//  - Notable callees: SysFreeString×2, FUN_00402d50, FUN_00410c30, FUN_007933a0, FUN_008bc420, SysStringLen, _wcsicmp, free.
//  - Strings: "LOAD_MSG".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * String-driven rename evidence: "LOAD_MSG"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_LOAD_MSG_008bc420(int *param_1,int param_2)



{

  char cVar1;

  int iVar2;

  UINT UVar3;

  char *pcVar4;

  uint32_t /* width from decompiler */ *puVar5;

  char *pcVar6;

  char *pcVar7;

  wchar_t *local_94;

  uint8_t *puStack_90;

  uint8_t auStack_8c [128];

  void *pvStack_c;

  uint8_t *puStack_8;

  uint local_4;

  

  puStack_8 = &LAB_009b9c91;

  pvStack_c = ExceptionList;

  local_94 = (wchar_t *)0x0;

  local_4 = 0;

  ExceptionList = &pvStack_c;

  if ((param_1 != (int *)0x0) && (ExceptionList = &pvStack_c, param_2 != 0)) {

    ExceptionList = &pvStack_c;

    (**(code **)(*param_1 + 0x1c))(param_1,&local_94);

    iVar2 = _wcsicmp(L"LOAD_MSG",local_94);

    if (iVar2 == 0) {

      SysFreeString(local_94);

      local_94 = (BSTR)0x0;

      (**(code **)(*param_1 + 0x68))(param_1,&local_94);

      if ((local_94 != (BSTR)0x0) && (UVar3 = SysStringLen(local_94), UVar3 != 0)) {

        pcVar4 = operator_new__(UVar3 + 1);

        puVar5 = (uint32_t /* width from decompiler */ *)FUN_00402d50(local_94);

        pcVar6 = (char *)*puVar5;

        pcVar7 = pcVar4;

        do {

          cVar1 = *pcVar6;

          *pcVar7 = cVar1;

          pcVar6 = pcVar6 + 1;

          pcVar7 = pcVar7 + 1;

        } while (cVar1 != '\0');

        local_4 = local_4 & 0xffffff00;

        if (puStack_90 != auStack_8c) {

          free(puStack_90);

        }

        FUN_00410c30(pcVar4);

      }

    }

    else {

      FUN_007933a0(param_1,param_2);

    }

  }

  local_4 = 0xffffffff;

  SysFreeString(local_94);

  ExceptionList = pvStack_c;

  return;

}
