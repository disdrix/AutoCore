// =============================================================================
// PodU32U8_CopyIfNonNull
// -----------------------------------------------------------------------------
// Stable ID: aa_0043ecf0
// Address:   0x0043ecf0–0x0043ecfe  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_0043ecf0
// System:    STL / guarded ring-deque POD store helper
// Dual:      W32-N 2026-07-29
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Retail ABI: EAX = dest (nullable); ECX = const PodU32U8* src; RET (no stack).
// Twin of FUN_0043ece0 (u32×2) with second field width = byte.
// Sole caller: GuardedVector_PushBack_Stride2_U32U8 (W31-J) after LEA slot.
// =============================================================================

#include <cstdint>

struct PodU32U8 {
  uint32_t key;
  uint8_t  flag;
  // 3 bytes padding in 8-byte container slot (not written here)
};

// EAX = dest; ECX = src; pure register dual; void
extern "C" void PodU32U8_CopyIfNonNull(uint8_t* dest /*EAX*/,
                                       const PodU32U8* src /*ECX*/)
{
  if (dest != nullptr) {
    *reinterpret_cast<uint32_t*>(dest) = src->key;
    dest[4] = src->flag;
  }
}
