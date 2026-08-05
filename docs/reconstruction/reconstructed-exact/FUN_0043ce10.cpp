// =============================================================================
// FUN_0043ce10  (twin of GuardedVector_PushFront)
// -----------------------------------------------------------------------------
// Stable ID: aa_0043ce10
// Address:   0x0043ce10–0x0043ce85  (autoassault.exe, image base 0x400000)
// Dual:      W29-B 2026-07-29
// Prefer:    GuardedVector_PushFront.cpp for named plate
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// =============================================================================

#include <cstdint>
#include <new>

// Prefer named clean: docs/reconstruction/reconstructed-exact/GuardedVector_PushFront.cpp
// Retail: EAX=container; stdcall 1 (value*); RET 0x4; EBX:=EAX for GrowBlockMap.

extern "C" void FUN_0043c9b0(uint32_t min_grow /*stack; EBX=container*/);

void FUN_0043ce10(uint32_t* value /*stack*/, int container /*EAX*/)
{
  if (((*reinterpret_cast<uint8_t*>(container + 0xc) & 3) == 0) &&
      (*reinterpret_cast<uint32_t*>(container + 8) <=
       (*reinterpret_cast<int32_t*>(container + 0x10) + 4u) >> 2)) {
    FUN_0043c9b0(1);
  }

  int32_t begin = *reinterpret_cast<int32_t*>(container + 0xc);
  if (begin == 0) {
    begin = *reinterpret_cast<int32_t*>(container + 8) * 4;
  }
  const uint32_t new_begin = static_cast<uint32_t>(begin - 1);
  const uint32_t page = new_begin >> 2;
  uint32_t** pages = *reinterpret_cast<uint32_t***>(container + 4);

  if (pages[page] == nullptr) {
    pages[page] = static_cast<uint32_t*>(::operator new(0x10));
  }

  uint32_t* slot = pages[page] + (new_begin & 3u);
  if (slot != nullptr) {
    *slot = *value;
  }

  *reinterpret_cast<int32_t*>(container + 0x10) += 1;
  *reinterpret_cast<uint32_t*>(container + 0xc) = new_begin;
}
