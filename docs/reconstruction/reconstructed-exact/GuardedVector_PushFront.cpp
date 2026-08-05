// =============================================================================
// GuardedVector_PushFront
// -----------------------------------------------------------------------------
// Stable ID: aa_0043ce10
// Address:   0x0043ce10–0x0043ce85  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_0043ce10
// System:    STL / guarded ring-deque container
// Dual:      W29-B 2026-07-29
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Retail ABI: EAX = container; stdcall 1 stack formal (const uint32_t* value);
//             RET 0x4. Entry MOV EBX,EAX so GrowBlockMap (EBX this) works.
// Map grow when begin is page-aligned and capacity is tight vs (size+4)>>2.
// When begin==0, wrap to capacity*4 then step back one element.
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
void GuardedVector_PushFront(GuardedVectorHeader* container /*EAX*/,
                             const uint32_t* value /*stack*/)
{
  // Map grow gate: begin page-aligned and need another page slot.
  if ((static_cast<uint32_t>(container->begin) & 3u) == 0 &&
      static_cast<uint32_t>(container->capacity) <=
          (static_cast<uint32_t>(container->size) + 4u) >> 2) {
    GuardedVector_GrowBlockMap(1);
  }

  int32_t begin = container->begin;
  if (begin == 0) {
    begin = container->capacity * 4;
  }
  const uint32_t new_begin = static_cast<uint32_t>(begin - 1);
  const uint32_t page = new_begin >> 2;

  if (container->pages[page] == nullptr) {
    container->pages[page] =
        static_cast<uint32_t*>(::operator new(0x10));
  }

  uint32_t* slot = container->pages[page] + (new_begin & 3u);
  if (slot != nullptr) {
    *slot = *value;
  }

  container->size += 1;
  container->begin = static_cast<int32_t>(new_begin);
}
