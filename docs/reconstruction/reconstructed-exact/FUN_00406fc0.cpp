// =============================================================================
// FUN_00406fc0  (clean twin → CNDHash_DestroyBucketTable_00a2c2e4)
// -----------------------------------------------------------------------------
// Stable ID: aa_00406fc0
// Address:   0x00406fc0–0x00406ff3  (autoassault.exe, image base 0x400000)
// System:    container / CNDHash
// Generated: 2026-08-04 WQ9G-J dual seal (supersedes 2026-07-23 scaffold paste)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
// Prefer named clean: CNDHash_DestroyBucketTable_00a2c2e4.cpp
// =============================================================================

#include <cstdint>
#include <cstdlib>

extern void FUN_004085e0(void);
extern void operator delete[](void *p);

// EAX = hash* (in_EAX); EBX = hash after entry
void FUN_00406fc0_Eax(int in_EAX)
{
  *reinterpret_cast<uint32_t *>(in_EAX + 0xc) = 0;
  FUN_004085e0();
  void **table = *reinterpret_cast<void ***>(in_EAX + 0x10);
  if (table != nullptr) {
    std::free(*table);
    operator delete[](table);
    *reinterpret_cast<uint32_t *>(in_EAX + 0x10) = 0;
  }
  return;
}
