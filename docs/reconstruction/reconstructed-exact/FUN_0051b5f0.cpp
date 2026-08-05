// =============================================================================
// FUN_0051b5f0  (alias of StdDeque_ThrowTooLong_0051b5f0)
// -----------------------------------------------------------------------------
// Stable ID: aa_0051b5f0
// Address:   0x0051b5f0  (autoassault.exe, image base 0x400000)
// System:    containers / MSVC STL deque
// Generated: 2026-07-29 W21-E dual seal (refined from 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Dual A/B: accept — see StdDeque_ThrowTooLong_0051b5f0.cpp for named clean.
// =============================================================================

#include <stdint.h>
#include <string>

struct ThrowInfo;

extern "C" void __stdcall _CxxThrowException(void *exception_object,
                                             ThrowInfo *throw_info);

extern void __thiscall exception_exception(void *exception_this);

void FUN_0051b5f0(void)
{
  std::string local_50;
  void *local_34[3];
  std::string local_28;
  uint32_t local_4;

  local_4 = 0xffffffffu;
  /* SEH: puStack_8 = &LAB_009a3502; ExceptionList link — omitted */
  local_50 = "deque<T> too long";
  local_4 = 0;
  exception_exception(local_34);
  local_34[0] = (void *)0x009c7628; /* PTR_FUN_009c7628 */
  local_28 = local_50;
  local_4 = 0;
  (void)local_4;
  local_34[0] = (void *)0x009c7634; /* PTR_FUN_009c7634 */
  /* WARNING: Subroutine does not return */
  _CxxThrowException(local_34, (ThrowInfo *)0x00acc388);
}
