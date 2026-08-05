// =============================================================================
// GuardedVector_PushBack
// -----------------------------------------------------------------------------
// Stable ID: aa_0043c830
// Address:   0x0043c830–0x0043c8a2  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_0043c830
// System:    STL / guarded ring-deque container
// Dual:      W29-B 2026-07-29
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Retail ABI: EAX = container; stdcall 1 stack formal (const uint32_t* value);
//             RET 0x4. Entry MOV EBX,EAX so GrowBlockMap (EBX this) works.
// Map grow when (begin+size) is page-aligned and capacity is tight vs (size+4)>>2.
// Write at absolute begin+size with page wrap; begin unchanged; size++.
// Name is structural (GuardedVector_* family); product/PDB open.
// =============================================================================

#include <cstdint>
#include <new>

struct GuardedVectorHeader {
  uint32_t _unk00;
  uint32_t** pages;   // +0x04  array of page pointers (each page 4 dwords)
  int32_t  capacity;  // +0x08  page count
  int32_t  begin;     // +0x0c  absolute element index of front
  int32_t  size;      // +0x10  element count
};

// Sealed W28-B: EBX=container; stdcall 1; RET 0x4.
extern "C" void GuardedVector_GrowBlockMap(uint32_t min_grow /*stack; EBX=this*/);

// Clean signature: container explicit (retail keeps it in EAX).
void GuardedVector_PushBack(GuardedVectorHeader* container /*EAX*/,
                            const uint32_t* value /*stack*/)
{
  // Map grow gate: end index page-aligned and need another page slot.
  const uint32_t end_probe =
      static_cast<uint32_t>(container->begin) +
      static_cast<uint32_t>(container->size);
  if ((end_probe & 3u) == 0 &&
      static_cast<uint32_t>(container->capacity) <=
          (static_cast<uint32_t>(container->size) + 4u) >> 2) {
    GuardedVector_GrowBlockMap(1);
  }

  uint32_t abs =
      static_cast<uint32_t>(container->begin) +
      static_cast<uint32_t>(container->size);
  uint32_t page = abs >> 2;
  if (static_cast<uint32_t>(container->capacity) <= page) {
    page -= static_cast<uint32_t>(container->capacity);
  }

  if (container->pages[page] == nullptr) {
    container->pages[page] =
        static_cast<uint32_t*>(::operator new(0x10));
  }

  uint32_t* slot = container->pages[page] + (abs & 3u);
  if (slot != nullptr) {
    *slot = *value;
  }

  container->size += 1;
  // begin unchanged
}
