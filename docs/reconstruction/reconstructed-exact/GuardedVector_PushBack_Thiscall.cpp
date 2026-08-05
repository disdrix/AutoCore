// =============================================================================
// GuardedVector_PushBack_Thiscall
// -----------------------------------------------------------------------------
// Stable ID: aa_0043d670
// Address:   0x0043d670–0x0043d6e6  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_0043d670
// System:    STL / guarded ring-deque container
// Dual:      W31-I 2026-07-29
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Retail ABI: ECX = container; stdcall 1 stack formal (const uint32_t* value);
//             RET 0x4. Entry MOV ESI,ECX; grow reloads MOV ECX,ESI.
// Map grow when (begin+size) is page-aligned and capacity is tight vs (size+4)>>2.
// Write at absolute begin+size with page wrap; begin unchanged; size++.
// Twin of W29-B GuardedVector_PushBack (EAX + EBX grow); uses thiscall grow.
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

// Sealed W30-A: ECX=container; stdcall 1; RET 0x4.
extern "C" void __thiscall GuardedVector_GrowBlockMap_Thiscall(
    GuardedVectorHeader* self /*ECX*/, uint32_t min_grow /*stack*/);

// Sealed helper: if dest != nullptr then *dest = *src.
extern "C" void FUN_0043d420(uint32_t* dest, const uint32_t* src);

// Clean signature: container explicit (retail keeps it in ECX).
void GuardedVector_PushBack_Thiscall(GuardedVectorHeader* container /*ECX*/,
                                     const uint32_t* value /*stack*/)
{
  // Map grow gate: end index page-aligned and need another page slot.
  const uint32_t end_probe =
      static_cast<uint32_t>(container->begin) +
      static_cast<uint32_t>(container->size);
  if ((end_probe & 3u) == 0 &&
      static_cast<uint32_t>(container->capacity) <=
          (static_cast<uint32_t>(container->size) + 4u) >> 2) {
    GuardedVector_GrowBlockMap_Thiscall(container, 1);
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
  FUN_0043d420(slot, value);

  container->size += 1;
  // begin unchanged
}
