// =============================================================================
// Mem_MoveDwordRange_ToExclusiveEnd
// -----------------------------------------------------------------------------
// Stable ID: aa_004e24d0
// Address:   0x004e24d0  (autoassault.exe, image base 0x400000)
// System:    stl-helpers
// Generated: 2026-07-29 W20-H dual seal (raw + live decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Move dword-aligned half-open range [srcBegin, srcEnd) so it ends at
//   exclusive end pointer destEndExcl:
//     size = ((srcEnd - srcBegin) >> 2) * 4;
//     memmove(destEndExcl - size, srcBegin, size);
//
// ABI: cdecl (bare ret), three stack args. Distinct from aa_004e2e80
//      (Mem_MoveDwordRange_ReturnEnd: stdcall ret 0xC, dest=param3, returns end).
// CALLEE: memmove (IAT @ 0x009c652c)
//
// Body: 004e24d0–004e24f3 (35 B through bare ret)

#include <cstring>
#include <cstddef>

void Mem_MoveDwordRange_ToExclusiveEnd(void *srcBegin, int srcEnd, int destEndExcl)
{
  int count = (srcEnd - reinterpret_cast<int>(srcBegin)) >> 2;
  memmove(reinterpret_cast<void *>(destEndExcl + count * -4),
          srcBegin,
          static_cast<size_t>(count) * 4u);
}
