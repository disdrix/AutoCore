// =============================================================================
// FUN_004a6820 — scaffold twin of StdVector_ThrowTooLong_B_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004a6820
// Address:   0x004a6820–0x004a6890 exclusive (112 B)
// Wave:      W36-Q 2026-07-29
// Prefer named clean: StdVector_ThrowTooLong_B_Inferred.cpp
// Strings:   "vector<T> too long"
// =============================================================================

#include <cstdint>

struct ThrowInfo;
extern "C" void __stdcall _CxxThrowException(void* exception_object,
                                             ThrowInfo* throw_info);

extern "C" void FUN_004a6820(void)
{
    uint8_t exception_object[40];
    /* plate "vector<T> too long" → exception path → throw; noreturn */
    _CxxThrowException(exception_object, (ThrowInfo*)0x00acc388);
}
