// =============================================================================
// Mem_CopyBytes
// -----------------------------------------------------------------------------
// Stable ID: aa_006380a0
// Address:   0x006380a0  (autoassault.exe, image base 0x400000)
// Body:      0x006380a0–0x006380be (31 B through bare ret)
// System:    util / memory
// Generated: 2026-07-29 W21-K dual seal (raw + live decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (retail uses rep movsd/movsb; CF equivalent).
// Dual A/B: accept (2026-07-29).
// =============================================================================
//
// PURPOSE:
//   Forward-only POD byte copy (memcpy semantics):
//     copy (n >> 2) dwords from src→dst, then (n & 3) residual bytes.
//   Leaf. No overlap handling (not memmove).
//
// ABI: __cdecl
//   stack: dst, src, n
//   epilogue: ret
//
// CALLEES: none
// CALLERS: GrowableArray / HB grow (FUN_005b3300, FUN_005b3370), many buffer paths
//
// Prior auto alias: Named_CalleeOf_Named_CalleeOf_CVOGHBList_Tick_006380a0
//   (one caller family; not exclusive — multi-caller generic)

#include <cstdint>

void __cdecl Mem_CopyBytes(void* dst, const void* src, unsigned n)
{
  auto* d = static_cast<uint32_t*>(dst);
  auto* s = static_cast<const uint32_t*>(src);
  unsigned dwords = n >> 2;
  unsigned rem;

  for (; dwords != 0; dwords = dwords - 1) {
    *d = *s;
    s = s + 1;
    d = d + 1;
  }
  rem = n & 3;
  for (; rem != 0; rem = rem - 1) {
    *reinterpret_cast<uint8_t*>(d) = *reinterpret_cast<const uint8_t*>(s);
    s = reinterpret_cast<const uint32_t*>(reinterpret_cast<const char*>(s) + 1);
    d = reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(d) + 1);
  }
  return;
}
