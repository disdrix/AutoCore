// =============================================================================
// PodU32U8_StoreSplit
// -----------------------------------------------------------------------------
// Stable ID: aa_0043ea50
// Address:   0x0043ea50–0x0043ea5f  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_0043ea50
// System:    POD store helper (split-source u32 + u8 into 8-byte slot)
// Dual:      W32-M 2026-07-29
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Retail ABI: EAX = dest (NOT null-checked); ECX = const uint32_t* pU32;
//             stack = const uint8_t* pU8; RET 0x4.
// Writes 5 bytes (u32 @ +0, u8 @ +4); trailing 3 slot bytes untouched.
// Distinct from contiguous null-safe FUN_0043ecf0 (Pod5_CopyIfNonNull).
// Name is structural; product/PDB open.
// =============================================================================

#include <cstdint>

// Clean signature: dest explicit (retail keeps it in EAX).
void PodU32U8_StoreSplit(void* dest /*EAX*/,
                         const uint32_t* pU32 /*ECX*/,
                         const uint8_t* pU8 /*stack*/)
{
  *static_cast<uint32_t*>(dest) = *pU32;
  *(static_cast<uint8_t*>(dest) + 4) = *pU8;
}
