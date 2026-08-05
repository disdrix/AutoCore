// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: if×4, return×3.
//  - Notable callees: _CxxThrowException×2, EnterCriticalSection, FUN_00411500, FUN_007a4480, LeaveCriticalSection.
//  - Strings: "VOG_DEBUG_STOP".
//  - Return sites: 3.

// =============================================================================
// Named_VOG_DEBUG_STOP_00411500
// -----------------------------------------------------------------------------
// Stable ID: aa_00411500
// Address:   0x00411500  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOG_DEBUG_STOP"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ Named_VOG_DEBUG_STOP_00411500(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009bd8a0;

  local_10 = ExceptionList;

  local_14 = &stack0xffffffc8;

  ExceptionList = &local_10;

  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));

  local_8 = 0;

  if ((char)param_1[10] != '\0') {

    FUN_007a4480(0,"VOG_DEBUG_STOP");

    local_18 = 0x80070005;

                    /* WARNING: Subroutine does not return */

    _CxxThrowException(&local_18,(ThrowInfo *)&DAT_00acc430);

  }

  iVar1 = (**(code **)(*param_1 + 4))(0);

  if (iVar1 == 0) {

    local_1c = 0x8007000e;

                    /* WARNING: Subroutine does not return */

    _CxxThrowException(&local_1c,(ThrowInfo *)&DAT_00acc430);

  }

  if (param_1[7] == 0) {

    param_1[7] = iVar1;

  }

  *(int *)(iVar1 + 0xc) = param_1[8];

  if (param_1[8] != 0) {

    *(int *)(param_1[8] + 8) = iVar1;

  }

  *(uint32_t /* width from decompiler */ *)(iVar1 + 4) = param_2;

  param_1[8] = iVar1;

  local_8 = 0xffffffff;

  param_1[9] = param_1[9] + 1;

  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));

  ExceptionList = local_10;

  return 0;

}
