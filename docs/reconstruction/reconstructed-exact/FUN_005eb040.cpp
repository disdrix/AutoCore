// =============================================================================
// FUN_005eb040  (twin of PodCopyBlock_0x40_Thiscall_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_005eb040
// Address:   0x005eb040  (autoassault.exe, image base 0x400000)
// Range:     0x005eb040–0x005eb0a6 inclusive (103 B / 0x67); pad CC after
// System:    interaction-activation
// Generated: 2026-08-05 R12-036 dual seal (from live Ghidra re-verify)
// Exactness: Behavior-preserving rewrite of decompiler/assembly control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// Runtime Confirmed: OPEN (no Launcher this wave).
// Preferred name: PodCopyBlock_0x40_Thiscall_Inferred
// =============================================================================

#include <cstdint>

// Leaf thiscall POD copy: 16 dwords / 0x40 bytes.
// ECX = dest, stack = src, RET 4, EAX = dest.
uint32_t * __thiscall FUN_005eb040(uint32_t *dest /* ECX */,
                                   const uint32_t *src /* stack */)
{
  dest[0]  = src[0];
  dest[1]  = src[1];
  dest[2]  = src[2];
  dest[3]  = src[3];
  dest[4]  = src[4];
  dest[5]  = src[5];
  dest[6]  = src[6];
  dest[7]  = src[7];
  dest[8]  = src[8];
  dest[9]  = src[9];
  dest[10] = src[10];
  dest[11] = src[11];
  dest[12] = src[12];
  dest[13] = src[13];
  dest[14] = src[14];
  dest[15] = src[15];
  return dest;
}
