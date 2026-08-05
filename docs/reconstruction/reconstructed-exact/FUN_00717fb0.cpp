// =============================================================================
// FUN_00717fb0
// -----------------------------------------------------------------------------
// Stable ID: aa_00717fb0
// Address:   0x00717fb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00717fb0 @ 0x00717fb0
// Stable ID: aa_00717fb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: GetLastError×3, FUN_00717fb0, FUN_00718082, WideCharToMultiByte, _com_issue_error, wcslen.
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

uint32_t /* width from decompiler */ FUN_00717fb0(wchar_t *param_1)



{

  size_t sVar1;

  uint uVar2;

  DWORD DVar3;

  uint32_t /* width from decompiler */ uVar4;

  DWORD local_2c;

  void *pvStack_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009ab480;

  pvStack_10 = ExceptionList;

  if (param_1 != (wchar_t *)0x0) {

    ExceptionList = &pvStack_10;

    sVar1 = wcslen(param_1);

    uVar2 = WideCharToMultiByte(0,0,param_1,sVar1 + 1,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);

    if (uVar2 != 0) {

      local_8 = 0;

      operator_new(uVar2);

      uVar4 = FUN_00718082();

      return uVar4;

    }

    DVar3 = GetLastError();

    if ((int)DVar3 < 1) {

      local_2c = GetLastError();

    }

    else {

      DVar3 = GetLastError();

      local_2c = DVar3 & 0xffff | 0x80070000;

    }

    _com_issue_error(local_2c);

  }

  ExceptionList = pvStack_10;

  return 0;

}
