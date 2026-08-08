// =============================================================================
// FUN_00409f70  (= StdVector_PodCopyElement_0x10_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00409f70
// Address:   0x00409f70–0x00409f8a inclusive (27 B / 0x1B)
// System:    MSVC-style POD element copy for vector elem stride 0x10
// Dual A/B:  2026-08-05 R10-023
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed ABI bytes.
// Bit-for-bit / runtime / diff: OPEN
// =============================================================================
// Canonical clean name lives in:
//   StdVector_PodCopyElement_0x10_Inferred.cpp
// This twin keeps the Ghidra FUN_* path stable for inventory links.
// =============================================================================

#include <cstdint>
#include <cstring>

// ABI: EAX = dest, ECX = src; plain RET (C3). Null dest → no-op.
// Four dword stores (0x10 bytes). Leaf; no callees.
extern "C" void FUN_00409f70(
    /*EAX*/ void* dest,
    /*ECX*/ const void* src)
{
  if (dest == nullptr)
    return;
  std::memcpy(dest, src, 0x10);
}
