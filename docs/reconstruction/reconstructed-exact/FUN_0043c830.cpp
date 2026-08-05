// =============================================================================
// FUN_0043c830  (twin of GuardedVector_PushBack)
// -----------------------------------------------------------------------------
// Stable ID: aa_0043c830
// Address:   0x0043c830–0x0043c8a2  (autoassault.exe, image base 0x400000)
// Dual:      W29-B 2026-07-29
// Prefer:    GuardedVector_PushBack.cpp for named plate
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// =============================================================================

#include <cstdint>
#include <new>

// Prefer named clean: docs/reconstruction/reconstructed-exact/GuardedVector_PushBack.cpp
// Retail: EAX=container; stdcall 1 (value*); RET 0x4; EBX:=EAX for GrowBlockMap.

extern "C" void FUN_0043c9b0(uint32_t min_grow /*stack; EBX=container*/);

void FUN_0043c830(uint32_t* value /*stack*/, int container /*EAX*/)
{
  if (((*reinterpret_cast<int32_t*>(container + 0xc) +
        *reinterpret_cast<int32_t*>(container + 0x10) & 3u) == 0) &&
      (*reinterpret_cast<uint32_t*>(container + 8) <=
       (*reinterpret_cast<int32_t*>(container + 0x10) + 4u) >> 2)) {
    FUN_0043c9b0(1);
  }

  uint32_t abs = static_cast<uint32_t>(*reinterpret_cast<int32_t*>(container + 0xc) +
                                       *reinterpret_cast<int32_t*>(container + 0x10));
  uint32_t page = abs >> 2;
  if (*reinterpret_cast<uint32_t*>(container + 8) <= page) {
    page -= *reinterpret_cast<uint32_t*>(container + 8);
  }

  uint32_t** pages = *reinterpret_cast<uint32_t***>(container + 4);
  if (pages[page] == nullptr) {
    pages[page] = static_cast<uint32_t*>(::operator new(0x10));
  }

  uint32_t* slot = pages[page] + (abs & 3u);
  if (slot != nullptr) {
    *slot = *value;
  }

  *reinterpret_cast<int32_t*>(container + 0x10) += 1;
}
