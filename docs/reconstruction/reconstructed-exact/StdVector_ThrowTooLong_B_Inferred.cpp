// =============================================================================
// StdVector_ThrowTooLong_B_Inferred  (aa_004a6820)
// -----------------------------------------------------------------------------
// Purpose:  MSVC STL vector length-overflow throw helper (vector::_Xlen class).
//           B-path twin of StdVector_ThrowTooLong (0x004540b0 / W19-B): same
//           plate string and ThrowInfo, different exception object construction
//           (IAT exception::exception + string copy + vtbls vs FUN_00401a40).
//
// Address:  0x004a6820–0x004a6890 exclusive (112 B)
// Stable:   aa_004a6820
// System:   containers / MSVC STL vector
// Ghidra:   FUN_004a6820
// Wave:     W36-Q OWN-ONLY 2026-07-29
//
// ABI:      no formals; installs SEH frame; does not return
// Strings:  "vector<T> too long" @ 0x00a15830
// ThrowInfo: DAT_00acc388
// Callees:  basic_string ctor/copy IAT, exception::exception IAT, _CxxThrowException
//
// Exactness: CF mirrors raw + read_memory bytes; names cleaned.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// =============================================================================

#include <cstdint>
#include <string>

struct ThrowInfo;

extern "C" void __stdcall _CxxThrowException(void* exception_object,
                                             ThrowInfo* throw_info);

/* Noreturn vector max-size overflow throw (004a* cluster / wstring insert path).

   Algorithm:
     1. Install SEH frame (handler LAB_009a11a2).
     2. Construct std::basic_string with "vector<T> too long" (0x00a15830).
     3. exception::exception() on exception object; set vtbl PTR_FUN_009c7628.
     4. Copy message string into exception payload; set vtbl PTR_FUN_009c7634.
     5. _CxxThrowException(&exception_object, &DAT_00acc388).

   Returns: never.

   Callers: FUN_004a69f0, FUN_004a6f70, FUN_004a76e0,
            StdVector_InsertN_BasicStringW (0x004a7ad0) overflow arm. */

void __cdecl StdVector_ThrowTooLong_B_Inferred(void)
{
    std::string message;          /* local_50 — basic_string storage */
    uint8_t exception_object[40]; /* local_34 region */
    uint32_t eh_state;

    /* SEH: push -1 / push LAB_009a11a2 / link FS:[0] / sub esp,0x44 — omitted
       as compiler frame; behavior identical through throw. */

    eh_state = 0xffffffffu;
    message = "vector<T> too long"; /* plate @ 0x00a15830 */
    eh_state = 0;
    (void)eh_state;
    (void)exception_object;

    /* exception::exception + string copy + vtbl writes — see annotated raw */

    /* WARNING: Subroutine does not return */
    _CxxThrowException(exception_object, (ThrowInfo*)0x00acc388);
}
