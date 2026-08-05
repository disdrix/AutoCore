// =============================================================================
// GuardedVector_PushBack_Stride2_U32x2
// -----------------------------------------------------------------------------
// Stable ID: aa_0043e970
// Address:   0x0043e970–0x0043e9dd  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_0043e970
// System:    STL / guarded ring-deque container (stride-2 / 8-byte elements)
// Dual:      W31-J 2026-07-29
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Retail ABI: EAX = container; stdcall 1 stack formal (const U32x2* value);
//             RET 0x4. Entry MOV EBX,EAX so GrowBlockMap_Stride2 (EBX this) works.
// Map grow when (begin+size) is even and capacity is tight vs (size+2)>>1.
// Write at absolute begin+size with page wrap; begin unchanged; size++.
// Name is structural (GuardedVector_* family); product/PDB open.
// =============================================================================

#include <cstdint>
#include <new>

struct GuardedVectorHeader {
  uint32_t _unk00;
  uint8_t** pages;    // +0x04  array of page pointers (each page 0x10 = 2×8 B)
  int32_t  capacity;  // +0x08  page count
  int32_t  begin;     // +0x0c  absolute element index of front
  int32_t  size;      // +0x10  element count
};

struct PodU32x2 {
  uint32_t a;
  uint32_t b;
};

// Sealed W30-A: EBX=container; stdcall 1; RET 0x4. begin>>1 rebalance.
extern "C" void GuardedVector_GrowBlockMap_Stride2(uint32_t min_grow /*stack; EBX=this*/);

// Nested helper FUN_0043ece0 (not owned): null-safe 8-byte copy ECX→EAX.
static void Pod8_CopyIfNonNull(PodU32x2* dest /*EAX*/, const PodU32x2* src /*ECX*/)
{
  if (dest != nullptr) {
    dest->a = src->a;
    dest->b = src->b;
  }
}

// Clean signature: container explicit (retail keeps it in EAX).
void GuardedVector_PushBack_Stride2_U32x2(GuardedVectorHeader* container /*EAX*/,
                                          const PodU32x2* value /*stack*/)
{
  const uint32_t end_probe =
      static_cast<uint32_t>(container->begin) +
      static_cast<uint32_t>(container->size);
  if ((end_probe & 1u) == 0 &&
      static_cast<uint32_t>(container->capacity) <=
          (static_cast<uint32_t>(container->size) + 2u) >> 1) {
    GuardedVector_GrowBlockMap_Stride2(1);
  }

  uint32_t abs =
      static_cast<uint32_t>(container->begin) +
      static_cast<uint32_t>(container->size);
  uint32_t page = abs >> 1;
  if (static_cast<uint32_t>(container->capacity) <= page) {
    page -= static_cast<uint32_t>(container->capacity);
  }

  if (container->pages[page] == nullptr) {
    container->pages[page] =
        static_cast<uint8_t*>(::operator new(0x10));
  }

  PodU32x2* slot = reinterpret_cast<PodU32x2*>(
      container->pages[page] + (abs & 1u) * 8u);
  Pod8_CopyIfNonNull(slot, value);

  container->size += 1;
  // begin unchanged
}
