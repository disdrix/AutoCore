// =============================================================================
// Pod8_CopyIfNonNull
// -----------------------------------------------------------------------------
// Stable ID: aa_0043ece0
// Address:   0x0043ece0–0x0043ecee  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_0043ece0
// System:    POD store helper (GuardedVector stride-2 / 8-byte slots)
// Dual:      W32-M 2026-07-29
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Retail ABI: EAX = dest (nullable); ECX = const PodU32x2* src; bare RET.
// Null dest → no write. Copies exactly two dwords (8 bytes).
// Name is structural (Pod8_* / family W31-J PushBack store); product/PDB open.
// =============================================================================

#include <cstdint>

struct PodU32x2 {
  uint32_t a;
  uint32_t b;
};

// Clean signature: dest explicit (retail keeps it in EAX).
void Pod8_CopyIfNonNull(PodU32x2* dest /*EAX*/, const PodU32x2* src /*ECX*/)
{
  if (dest != nullptr) {
    dest->a = src->a;
    dest->b = src->b;
  }
}
