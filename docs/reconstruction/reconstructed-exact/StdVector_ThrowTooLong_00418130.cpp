// =============================================================================
// StdVector_ThrowTooLong_00418130
// -----------------------------------------------------------------------------
// Purpose:  MSVC STL vector length-overflow throw helper (vector::_Xlen class).
//           Builds a C++ exception whose message is the plate string
//           "vector<T> too long" and throws via _CxxThrowException. Noreturn.
//
// Address:  0x00418130  (autoassault.exe, image base 0x400000)
// Body:     0x00418130–0x0041817a (75 bytes)
// Stable:   aa_00418130
// System:   containers / MSVC STL vector
// Ghidra:   FUN_00418130
//
// ABI:      no formals; installs SEH frame; does not return
// Strings:  "vector<T> too long" @ 0x00a15830
// ThrowInfo: DAT_00acc388
// Callees:  basic_string ctor (IAT [0x009c62f8]), FUN_00401a40, _CxxThrowException
// Sibling:  StdVector_ThrowTooLong @ 0x004540b0 (same plate/ThrowInfo; minor insn order)
//
// Exactness: CF mirrors raw + read_memory bytes; names cleaned.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept (2026-07-29 W20-G seal).
// =============================================================================

/* StdVector_ThrowTooLong_00418130 — shared vector size-overflow throw (noreturn).

   Algorithm:
     1. Install SEH frame (handler LAB_009bc919).
     2. Construct std::basic_string with "vector<T> too long" (0x00a15830).
     3. FUN_00401a40(&exception_object, &message) — typed exception ctor.
     4. _CxxThrowException(&exception_object, &DAT_00acc388).

   Returns: never.

   Callers: many vector grow/insert overflow sites including UiToastVector_InsertN
   (0x00403980), CombatFloater insert family, and dword insert helpers. */

#include <stdint.h>
#include <string>

struct ThrowInfo;

extern "C" void __stdcall _CxxThrowException(void *exception_object,
                                             ThrowInfo *throw_info);

/* FUN_00401a40 — exception object from message string (__thiscall on object). */
extern void *__thiscall ExceptionFromString_00401a40(void *exception_this,
                                                     void *message_string);

void __cdecl StdVector_ThrowTooLong_00418130(void)
{
  std::string message;           /* local_50 region — basic_string storage */
  uint8_t exception_object[40];  /* local_34[40] — exception blob for throw */
  uint32_t eh_state;

  /* SEH: push -1 / push LAB_009bc919 / link FS:[0] / sub esp,0x44 — omitted
     as compiler frame; behavior is identical: frame active through throw. */

  eh_state = 0xffffffffu;
  message = "vector<T> too long"; /* plate @ 0x00a15830 */
  eh_state = 0;
  (void)eh_state;

  ExceptionFromString_00401a40(exception_object, &message);

  /* WARNING: Subroutine does not return */
  _CxxThrowException(exception_object, (ThrowInfo *)0x00acc388);
}
