// =============================================================================
// FUN_0051b5d0  (scaffold alias → StdTree_Min_Isnil29)
// -----------------------------------------------------------------------------
// Stable ID: aa_0051b5d0
// Address:   0x0051b5d0  (autoassault.exe, image base 0x400000)
// Body:      0x0051b5d0 – 0x0051b5ea inclusive (27 B)
// System:    MSVC std::_Tree min / leftmost (isnil @ +0x29)
// Generated: 2026-08-04 WQ9D-B dual seal (supersedes 2026-07-23 scaffold paste)
// Exactness: Behavior-preserving; prefer named clean StdTree_Min_Isnil29.cpp
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// See: docs/reconstruction/reconstructed-exact/StdTree_Min_Isnil29.cpp

#include <cstdint>

// Ghidra decompile showed void + walk-into-nil; bytes return EAX = leftmost.
extern "C" int *FUN_0051b5d0(int *param_1)
{
  char cVar1;
  int *left;

  left = (int *)*param_1;
  cVar1 = *(char *)((int)left + 0x29);
  if (cVar1 != '\0') {
    return param_1;
  }
  do {
    param_1 = left;
    left = (int *)*param_1;
    cVar1 = *(char *)((int)left + 0x29);
  } while (cVar1 == '\0');
  return param_1;
}
