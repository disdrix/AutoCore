// =============================================================================
// GuardedVector_PushBack_Stride2_U32U8
// -----------------------------------------------------------------------------
// Stable ID: aa_0043e9e0
// Address:   0x0043e9e0–0x0043ea4d  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_0043e9e0
// System:    STL / guarded ring-deque container (stride-2 / 8-byte slots, 5-byte POD)
// Dual:      W31-J 2026-07-29
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Retail ABI: EAX = container; stdcall 1 stack formal (const PodU32U8* value);
//             RET 0x4. Twin of aa_0043e970 with dword+byte store (FUN_0043ecf0).
// Storage slots remain 8 bytes (LEA *8); write width is u32 + u8.
// =============================================================================

#include <cstdint>
#include <new>

struct GuardedVectorHeader {
  uint32_t _unk00;
  uint8_t** pages;    // +0x04
  int32_t  capacity;  // +0x08
  int32_t  begin;     // +0x0c
  int32_t  size;      // +0x10
};

struct PodU32U8 {
  uint32_t key;
  uint8_t  flag;
  // 3 bytes padding in 8-byte slot (not written by store helper)
};

extern "C" void GuardedVector_GrowBlockMap_Stride2(uint32_t min_grow /*stack; EBX=this*/);

// Nested helper FUN_0043ecf0 (not owned): null-safe dword+byte copy ECX→EAX.
static void Pod5_CopyIfNonNull(uint8_t* dest /*EAX*/, const PodU32U8* src /*ECX*/)
{
  if (dest != nullptr) {
    *reinterpret_cast<uint32_t*>(dest) = src->key;
    dest[4] = src->flag;
  }
}

void GuardedVector_PushBack_Stride2_U32U8(GuardedVectorHeader* container /*EAX*/,
                                          const PodU32U8* value /*stack*/)
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

  uint8_t* slot = container->pages[page] + (abs & 1u) * 8u;
  Pod5_CopyIfNonNull(slot, value);

  container->size += 1;
  // begin unchanged
}
