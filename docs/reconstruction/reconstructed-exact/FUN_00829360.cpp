// =============================================================================
// FUN_00829360
// -----------------------------------------------------------------------------
// Stable ID: aa_00829360
// Address:   0x00829360  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00829360 @ 0x00829360
// Stable ID: aa_00829360
// Embedded strings (evidence for future rename):
//   - "DOWN_SIZE_RATIO"
//   - "%f;%f"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: SysFreeString×2, FUN_007933a0, FUN_00829360, _wcsicmp, swscanf.
//  - Strings: "DOWN_SIZE_RATIO"; "%f;%f".
//  - Return sites: 1.

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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __thiscall FUN_00829360(int param_1,int *param_2,int param_3)



{

  int iVar1;

  wchar_t *local_14;

  float local_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009b8509;

  pvStack_c = ExceptionList;

  local_14 = (wchar_t *)0x0;

  local_4 = 0;

  local_10 = g_flOne;

  ExceptionList = &pvStack_c;

  if ((param_2 != (int *)0x0) && (ExceptionList = &pvStack_c, param_3 != 0)) {

    ExceptionList = &pvStack_c;

    (**(code **)(*param_2 + 0x1c))(param_2,&local_14);

    iVar1 = _wcsicmp(L"DOWN_SIZE_RATIO",local_14);

    if (iVar1 == 0) {

      SysFreeString(local_14);

      local_14 = (wchar_t *)0x0;

      (**(code **)(*param_2 + 0x68))(param_2,&local_14);

      iVar1 = swscanf(local_14,L"%f;%f",&local_10,0);

      if (iVar1 == 2) {

        _DAT_00000000 = _DAT_00000000 - local_10;

      }

      *(float *)(param_1 + 0x50c) = local_10;

      *(float *)(param_1 + 0x508) = local_10;

    }

    else {

      FUN_007933a0(param_2,param_3);

    }

  }

  local_4 = 0xffffffff;

  SysFreeString(local_14);

  ExceptionList = pvStack_c;

  return;

}
