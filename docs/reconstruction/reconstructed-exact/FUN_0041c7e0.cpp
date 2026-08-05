// =============================================================================
// FUN_0041c7e0  /  LockedList_InsertPayloadTail_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0041c7e0
// Address:   0x0041c7e0 – 0x0041c8a2  (autoassault.exe, image base 0x400000)
// System:    skills-abilities / CS-protected locked list insert
// Generated: 2026-07-23 scaffold; dual-refined 2026-07-29 (W16-F)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Convention: __stdcall, ret 8 (list*, payload)
// =============================================================================

// PURPOSE:
//   Insert payload at the TAIL of a 0x2C locked list under CRITICAL_SECTION.
//   Rejects insert when list flag byte at +0x28 is set (VOG_DEBUG_STOP + throw
//   E_ACCESSDENIED / 0x80070005). Allocates node via list vtbl+4; OOM throws
//   E_OUTOFMEMORY / 0x8007000e. Links node doubly: +0x08 next, +0x0C prev;
//   payload at +0x04. Head +0x1C, tail +0x20, count +0x24. Returns 0.
//
// Embedded strings:
//   - "VOG_DEBUG_STOP"
//
// Callees: EnterCriticalSection, LeaveCriticalSection, FUN_007a4480,
//          _CxxThrowException
// Callers include: FUN_0041ac60 (Hash_CollectKeyMatchesToLockedList)

// READABILITY:
//  - Control keywords: if×4; throws×2; return×1 (success)
//  - SEH frame (LAB_009bd7b0) preserves LeaveCS on unwind

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; live re-verify 2026-07-29 ≡ raw.
 * - thiscall for vtbl+4: ECX=list, stack arg 0 (decompiler shows (0) only).
 * - Failure paths do not return (throw).
 */

undefined4 FUN_0041c7e0(int *param_1, undefined4 param_2)
{
  int iVar1;
  undefined4 local_1c;
  undefined4 local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;

  local_8 = 0xffffffff;
  puStack_c = &LAB_009bd7b0;
  local_10 = ExceptionList;
  local_14 = &stack0xffffffd4;
  ExceptionList = &local_10;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
  local_8 = 0;
  if ((char)param_1[10] != '\0') {
    FUN_007a4480(0, "VOG_DEBUG_STOP");
    local_18 = 0x80070005;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(&local_18, (ThrowInfo *)&DAT_00acc430);
  }
  iVar1 = (**(code **)(*param_1 + 4))(0);
  if (iVar1 == 0) {
    local_1c = 0x8007000e;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(&local_1c, (ThrowInfo *)&DAT_00acc430);
  }
  if (param_1[7] == 0) {
    param_1[7] = iVar1;
  }
  *(int *)(iVar1 + 0xc) = param_1[8];
  if (param_1[8] != 0) {
    *(int *)(param_1[8] + 8) = iVar1;
  }
  *(undefined4 *)(iVar1 + 4) = param_2;
  param_1[9] = param_1[9] + 1;
  param_1[8] = iVar1;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
  ExceptionList = local_10;
  return 0;
}
