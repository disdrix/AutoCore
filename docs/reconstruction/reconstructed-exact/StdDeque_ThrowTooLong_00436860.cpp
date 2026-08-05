// =============================================================================
// StdDeque_ThrowTooLong_00436860
// -----------------------------------------------------------------------------
// Purpose:  MSVC STL deque length-overflow throw helper (deque::_Xlen class).
//           Builds a C++ exception whose message is the plate string
//           "deque<T> too long" via FUN_00401a40, then throws with
//           _CxxThrowException. Noreturn.
//
// Address:  0x00436860  (autoassault.exe, image base 0x400000)
// Body:     0x00436860–0x004368aa (75 bytes)
// Stable:   aa_00436860
// System:   containers / MSVC STL deque
// Ghidra:   FUN_00436860
//
// ABI:      no formals; installs SEH frame; does not return
// Strings:  "deque<T> too long" @ 0x00a31520
// ThrowInfo: DAT_00acc388
// Callees:  basic_string ctor (IAT), FUN_00401a40 (exception+vftable
//           PTR_FUN_009c7634), _CxxThrowException
// Sibling clones (role-only, not byte-merged): FUN_0040ff30,
//           FUN_0051b5f0, FUN_005b2a80
//
// Exactness: CF mirrors raw + read_memory bytes; names cleaned.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept (2026-07-29 W29-C seal).
// =============================================================================

/* StdDeque_ThrowTooLong_00436860 — shared deque size-overflow throw (noreturn).

   Algorithm:
     1. Install SEH frame (handler LAB_009bc919).
     2. Construct std::basic_string with "deque<T> too long" (0x00a31520).
     3. FUN_00401a40(exception_object, &message) — constructs typed exception
        and installs vftable PTR_FUN_009c7634.
     4. _CxxThrowException(&exception_object, &DAT_00acc388).

   Returns: never.

   Callers (4): FUN_00436650 (CircularPtrBuf_Grow), FUN_0043c9b0
   (GuardedVector_GrowBlockMap), FUN_0043d990, FUN_0043ea60 — overflow arms. */

#include <stdint.h>
#include <string>

struct ThrowInfo;

extern "C" void __stdcall _CxxThrowException(void *exception_object,
                                             ThrowInfo *throw_info);

/* MSVC exception construct-from-string; sets *this = PTR_FUN_009c7634. */
extern void *__thiscall FUN_00401a40(void *exception_this, void *message_string);

void __cdecl StdDeque_ThrowTooLong_00436860(void)
{
  std::string message;       /* local_50 — plate message */
  uint8_t exception_object[40]; /* local_34 — throw blob */
  uint32_t eh_state;

  /* SEH: push -1 / push LAB_009bc919 / link FS:[0] / sub esp,0x44 — omitted
     as compiler frame; behavior identical through throw. */

  eh_state = 0xffffffffu;
  message = "deque<T> too long"; /* plate @ 0x00a31520 */
  eh_state = 0;
  (void)eh_state;

  FUN_00401a40(exception_object, &message);

  /* WARNING: Subroutine does not return */
  _CxxThrowException(exception_object, (ThrowInfo *)0x00acc388);
}
