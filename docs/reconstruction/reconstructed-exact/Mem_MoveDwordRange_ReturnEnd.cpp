// =============================================================================
// Mem_MoveDwordRange_ReturnEnd
// -----------------------------------------------------------------------------
// Stable ID: aa_004e2e80
// Address:   0x004e2e80  (autoassault.exe, image base 0x400000)
// System:    stl-helpers
// Generated: 2026-07-29 W19-C dual seal (from raw + live decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Move dword-aligned half-open range [srcBegin, srcEnd) into dest via memmove.
//   Size = ((srcEnd - srcBegin) >> 2) * 4. Return dest + size.
//
// ABI: __stdcall, ret 0xC  (three stack args)
// CALLEE: memmove (IAT)
//
// Body: 004e2e80–004e2eaa (42 B through ret 0xC)

#include <cstring>
#include <cstddef>

void * __stdcall Mem_MoveDwordRange_ReturnEnd(void *srcBegin, int srcEnd, void *dest)
{
  size_t size = (static_cast<size_t>(srcEnd - reinterpret_cast<int>(srcBegin)) >> 2) * 4;
  void *p = memmove(dest, srcBegin, size);
  return reinterpret_cast<void *>(reinterpret_cast<int>(p) + static_cast<int>(size));
}
