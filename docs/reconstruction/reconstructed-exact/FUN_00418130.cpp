// =============================================================================
// FUN_00418130  (alias of StdVector_ThrowTooLong_00418130)
// -----------------------------------------------------------------------------
// Stable ID: aa_00418130
// Address:   0x00418130  (autoassault.exe, image base 0x400000)
// System:    containers / MSVC STL vector
// Generated: 2026-07-29 W20-G dual seal (refined from 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Dual A/B: accept — see StdVector_ThrowTooLong_00418130.cpp for named clean.
// =============================================================================

#include <stdint.h>
#include <string>

struct ThrowInfo;

extern "C" void __stdcall _CxxThrowException(void *exception_object,
                                             ThrowInfo *throw_info);

extern void *__thiscall FUN_00401a40(void *exception_this, void *message_string);

void FUN_00418130(void)
{
  std::string local_50;
  uint8_t local_34[40];
  uint32_t local_4;

  local_4 = 0xffffffffu;
  /* SEH: puStack_8 = &LAB_009bc919; ExceptionList link — omitted */
  local_50 = "vector<T> too long";
  local_4 = 0;
  (void)local_4;
  FUN_00401a40(local_34, &local_50);
  /* WARNING: Subroutine does not return */
  _CxxThrowException(local_34, (ThrowInfo *)0x00acc388);
}
