// =============================================================================
// FUN_008c3e20
// -----------------------------------------------------------------------------
// Stable ID: aa_008c3e20
// Address:   0x008c3e20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008c3e20 @ 0x008c3e20
// Stable ID: aa_008c3e20
// Embedded strings (evidence for future rename):
//   - "GRID_UNIT_SIZE"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_007933a0, FUN_007a8b00, FUN_008c3e20, SysFreeString, _wcsicmp.
//  - Strings: "GRID_UNIT_SIZE".
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

void FUN_008c3e20(int *param_1,int param_2)



{

  int iVar1;

  wchar_t *local_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009b9ebd;

  pvStack_c = ExceptionList;

  local_10 = (wchar_t *)0x0;

  local_4 = 0;

  ExceptionList = &pvStack_c;

  if ((param_1 != (int *)0x0) && (ExceptionList = &pvStack_c, param_2 != 0)) {

    ExceptionList = &pvStack_c;

    (**(code **)(*param_1 + 0x1c))(param_1,&local_10);

    iVar1 = _wcsicmp(L"GRID_UNIT_SIZE",local_10);

    if (iVar1 == 0) {

      FUN_007a8b00(param_1,&DAT_00d1e50c,&DAT_00d1e510,0);

    }

    else {

      FUN_007933a0(param_1,param_2);

    }

  }

  local_4 = 0xffffffff;

  SysFreeString(local_10);

  ExceptionList = pvStack_c;

  return;

}
