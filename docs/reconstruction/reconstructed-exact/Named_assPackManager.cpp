// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: FUN_0076cec0×3, vog_LogMessage×3, LeaveCriticalSection×2, EnterCriticalSection, FUN_004406e0, FUN_00719970, FUN_0071a9d0, FUN_00984ee0.
//  - Strings: "Opening pack file %s"; "C:\\vog\\1_code\\palantir\\palantir\\assets\\assPackManager.cpp"; "FAILED - Opening pack file %s"; "SUCCESS - Opening pack file %s".
//  - Return sites: 2.

// =============================================================================
// Named_assPackManager
// -----------------------------------------------------------------------------
// Stable ID: aa_00984ee0
// Address:   0x00984ee0  (autoassault.exe, image base 0x400000)
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

uint32_t /* width from decompiler */ __thiscall Named_assPackManager(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2)



{

  LPCRITICAL_SECTION lpCriticalSection;

  uint32_t /* width from decompiler */ uVar1;

  void *pvVar2;

  int iVar3;

  int unaff_EBX;

  uint32_t /* width from decompiler */ uVar4;

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b1173;

  local_c = ExceptionList;

  lpCriticalSection = (LPCRITICAL_SECTION)(unaff_EBX + 0x38);

  ExceptionList = &local_c;

  if (*(char *)(unaff_EBX + 0x50) != '\0') {

    ExceptionList = &local_c;

    EnterCriticalSection(lpCriticalSection);

  }

  uVar4 = 0;

  local_4 = 0;

  uVar1 = FUN_0076cec0(&param_2,"Opening pack file %s",param_1);

  vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\assets\\assPackManager.cpp",0x75,1,uVar1);

  pvVar2 = operator_new(0x44);

  local_4._0_1_ = 1;

  if (pvVar2 != (void *)0x0) {

    uVar4 = FUN_00719970(pvVar2,param_2);

  }

  local_4 = (uint)local_4._1_3_ << 8;

  param_2 = uVar4;

  iVar3 = FUN_0071a9d0(unaff_EBX);

  if (iVar3 < 0) {

    uVar1 = FUN_0076cec0(&param_2,"FAILED - Opening pack file %s",param_1);

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\assets\\assPackManager.cpp",0x7b,1,uVar1);

    if (*(char *)(unaff_EBX + 0x50) != '\0') {

      LeaveCriticalSection(lpCriticalSection);

    }

    ExceptionList = local_c;

    return 0xffffffff;

  }

  uVar1 = FUN_0076cec0(&param_2,"SUCCESS - Opening pack file %s",param_1);

  vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\assets\\assPackManager.cpp",0x80,1,uVar1);

  FUN_004406e0();

  if (*(char *)(unaff_EBX + 0x50) != '\0') {

    LeaveCriticalSection(lpCriticalSection);

  }

  ExceptionList = local_c;

  return 0;

}
