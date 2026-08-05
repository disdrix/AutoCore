// READABILITY (auto CF):
//  - Body size: ~54 non-empty decompiler lines.
//  - Control keywords: if×6, return×2.
//  - Notable callees: LeaveCriticalSection×2, CONCAT31, CloseHandle, EnterCriticalSection, FUN_00766750, FUN_007669d0, FUN_0076bd90, FUN_0076cec0.
//  - Strings: "<%s> couldnt be found!"; "C:\\vog\\1_code\\palantir\\palantir\\assets\\assPackManager.cpp".
//  - Return sites: 2.

// =============================================================================
// Named_assPackManager_00984d30
// -----------------------------------------------------------------------------
// Stable ID: aa_00984d30
// Address:   0x00984d30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "assPackManager"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __thiscall Named_assPackManager_00984d30(undefined *param_1,int param_2,uint32_t /* width from decompiler */ param_3)



{

  char cVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  int *piVar4;

  void *lpBuffer;

  void *local_c;

  LPCRITICAL_SECTION p_Stack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  p_Stack_8 = (LPCRITICAL_SECTION)&LAB_009b1156;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  if (*(char *)(param_2 + 0x50) != '\0') {

    ExceptionList = &local_c;

    EnterCriticalSection((LPCRITICAL_SECTION)(param_2 + 0x38));

  }

  local_4 = 0;

  iVar2 = FUN_009835f0();

  if (iVar2 != 0) {

    piVar4 = (int *)FUN_00983d40(param_2);

    lpBuffer = operator_new__(*(int *)(iVar2 + 8) + 1);

    (**(code **)(*piVar4 + 0x14))(lpBuffer,*(uint32_t /* width from decompiler */ *)(iVar2 + 8));

    local_c = (void *)CONCAT31(local_c._1_3_,1);

    if ((param_1 == (undefined *)0x0) &&

       (param_1 = *(undefined **)(iVar2 + 0x10), param_1 == (undefined *)0x0)) {

      param_1 = PTR_DAT_00afa2bc;

    }

    FUN_0076bd90(1);

    FUN_007669d0(param_1,6,0);

    WriteFile((HANDLE)0xffffffff,lpBuffer,*(DWORD *)(iVar2 + 8),(LPDWORD)&stack0x00000000,

              (LPOVERLAPPED)0x0);

    cVar1 = (*(code *)PTR_FUN_00a9d86c)();

    if (cVar1 != '\0') {

      CloseHandle((HANDLE)0xffffffff);

    }

    operator_delete__(lpBuffer);

    (**(code **)*piVar4)(1);

    FUN_00766750();

    if (*(char *)&p_Stack_8[1].DebugInfo != '\0') {

      LeaveCriticalSection(p_Stack_8);

    }

    ExceptionList = (void *)0x0;

    return 0;

  }

  uVar3 = FUN_0076cec0(&param_3,"<%s> couldnt be found!",param_3);

  vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\assets\\assPackManager.cpp",0x20f,3,uVar3);

  if (*(char *)(param_2 + 0x50) != '\0') {

    LeaveCriticalSection((LPCRITICAL_SECTION)(param_2 + 0x38));

  }

  ExceptionList = local_c;

  return 0xffffffff;

}
