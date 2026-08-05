// =============================================================================
// FUN_0044a380  — clean twin of StdVector_DwordResize_EaxCount_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0044a380
// Address:   0x0044a380  (autoassault.exe, image base 0x400000)
// W37-Z:     2026-08-04 — see StdVector_DwordResize_EaxCount_Inferred.cpp
// =============================================================================
// ABI (bytes): ECX=vec*, EAX=newCount, stack fill dword, RET 4.
// Decompiler formals incomplete (missing fill + RET 4) — bytes win.
// =============================================================================

#include <cstdint>

struct VecDwordControl {
  uint32_t reserved0;
  uint32_t* begin;
  uint32_t* end;
};

extern "C" void __thiscall FUN_00463e30(VecDwordControl* vec,
                                        uint32_t* where_end,
                                        uint32_t count,
                                        const uint32_t* fill);
extern "C" void FUN_00469f10(uint32_t* first, uint32_t* last);

extern "C" void FUN_0044a380(VecDwordControl* vec,
                             uint32_t new_count,
                             uint32_t fill)
{
  uint32_t* begin = vec->begin;
  uint32_t size = 0;
  if (begin != nullptr) {
    size = static_cast<uint32_t>(
        (reinterpret_cast<uint8_t*>(vec->end) -
         reinterpret_cast<uint8_t*>(begin)) >> 2);
  }

  if (size < new_count) {
    FUN_00463e30(vec, vec->end, new_count - size, &fill);
    return;
  }
  if (begin != nullptr && new_count < size) {
    FUN_00469f10(begin + new_count, vec->end);
  }
}
