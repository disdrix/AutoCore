// Twin of StdDeque_ThrowTooLong_00436860.cpp — Ghidra FUN_* alias.
// Stable ID: aa_00436860 @ 0x00436860. See named clean for full header.

#include <stdint.h>
#include <string>

struct ThrowInfo;

extern "C" void __stdcall _CxxThrowException(void *exception_object,
                                             ThrowInfo *throw_info);
extern void *__thiscall FUN_00401a40(void *exception_this, void *message_string);

void __cdecl FUN_00436860(void)
{
  std::string message;
  uint8_t exception_object[40];
  uint32_t eh_state;

  eh_state = 0xffffffffu;
  message = "deque<T> too long";
  eh_state = 0;
  (void)eh_state;

  FUN_00401a40(exception_object, &message);
  _CxxThrowException(exception_object, (ThrowInfo *)0x00acc388);
}
