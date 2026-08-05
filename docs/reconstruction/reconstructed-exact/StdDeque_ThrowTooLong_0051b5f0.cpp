// =============================================================================
// StdDeque_ThrowTooLong_0051b5f0
// -----------------------------------------------------------------------------
// Purpose:  MSVC STL deque length-overflow throw helper (deque::_Xlen class).
//           Builds a C++ exception whose message is the plate string
//           "deque<T> too long" and throws via _CxxThrowException. Noreturn.
//
// Address:  0x0051b5f0  (autoassault.exe, image base 0x400000)
// Body:     0x0051b5f0–0x0051b65f (112 bytes)
// Stable:   aa_0051b5f0
// System:   containers / MSVC STL deque
// Ghidra:   FUN_0051b5f0
//
// ABI:      no formals; installs SEH frame; does not return
// Strings:  "deque<T> too long" @ 0x00a31520
// ThrowInfo: DAT_00acc388
// Vftables: PTR_FUN_009c7628 (after exception::exception),
//           PTR_FUN_009c7634 (after message copy-construct)
// Callees:  basic_string ctor/copy (IAT), exception::exception, _CxxThrowException
// Sibling clones (role-only, not byte-merged): FUN_0040ff30, FUN_00436860, FUN_005b2a80
//
// Exactness: CF mirrors raw + read_memory bytes; names cleaned.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept (2026-07-29 W21-E seal).
// =============================================================================

/* StdDeque_ThrowTooLong_0051b5f0 — shared deque size-overflow throw (noreturn).

   Algorithm:
     1. Install SEH frame (handler LAB_009a3502).
     2. Construct std::basic_string with "deque<T> too long" (0x00a31520).
     3. exception::exception on throw object; vftable = PTR_FUN_009c7628.
     4. Copy-construct message into exception; vftable = PTR_FUN_009c7634.
     5. _CxxThrowException(&exception_object, &DAT_00acc388).

   Returns: never.

   Callers: deque map-grow overflow sites; dual-sealed sample FUN_0051c3b0
   (skill deferred-cast id deque map grow). */

#include <stdint.h>
#include <string>

struct ThrowInfo;

extern "C" void __stdcall _CxxThrowException(void *exception_object,
                                             ThrowInfo *throw_info);

/* CRT / MSVC exception base ctor (IAT). */
extern void __thiscall exception_exception(void *exception_this);

void __cdecl StdDeque_ThrowTooLong_0051b5f0(void)
{
  std::string message;            /* local_50 — plate message */
  void *exception_object[3];      /* local_34 — throw blob + vftable slot */
  std::string embedded_message;   /* local_28 — copy into exception */
  uint32_t eh_state;

  /* SEH: push -1 / push LAB_009a3502 / link FS:[0] / sub esp,0x44 — omitted
     as compiler frame; behavior is identical: frame active through throw. */

  eh_state = 0xffffffffu;
  message = "deque<T> too long"; /* plate @ 0x00a31520 */
  eh_state = 0;
  (void)eh_state;

  exception_exception(exception_object);
  exception_object[0] = (void *)0x009c7628; /* PTR_FUN_009c7628 */

  embedded_message = message;
  exception_object[0] = (void *)0x009c7634; /* PTR_FUN_009c7634 */

  /* WARNING: Subroutine does not return */
  _CxxThrowException(exception_object, (ThrowInfo *)0x00acc388);
}
