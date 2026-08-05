// =============================================================================
// CircularSentinel_Alloc0x28_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00423d60
// Address:   0x00423d60–0x00423d79  (26 B / 0x1A; autoassault.exe base 0x400000)
// System:    shared circular-list / hash-bucket sentinel factory
// Generated: 2026-07-23 scaffold as FUN_00423d60; dual A/B seal 2026-07-29 (W33-B)
// Exactness: Behavior-preserving rewrite of decompiler + full-body bytes.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE:
//   Allocate a 0x28-byte node and install circular next/prev self-links.
//   Used as the empty-list / hash-bucket sentinel by AssResolver nested bag ctors
//   (FUN_00423cf0, FUN_00469db0, FUN_0044a0d0).
//
// ABI:
//   No formals; bare RET; returns node* in EAX.
//   Family twin: StdList_AllocSentinel_0xC_Inferred (0x004933f0) with size 0xC.
//
// REJECT: scaffold Named_CalleeOf_* product aliases.
//

#include <cstdint>

// Retail CRT
extern "C" void* __cdecl operator_new(uint32_t size);

// Node layout (only +0/+4 written here; remaining 0x20 payload unowned)
struct CircularSentinelNode0x28 {
  CircularSentinelNode0x28* next; // +0x00
  CircularSentinelNode0x28* prev; // +0x04
  uint8_t payload[0x20];          // +0x08 .. +0x27 (not written by this factory)
};

extern "C" CircularSentinelNode0x28* CircularSentinel_Alloc0x28_Inferred(void)
{
  auto* node = static_cast<CircularSentinelNode0x28*>(operator_new(0x28));
  if (node != nullptr) {
    node->next = node;
  }
  // Retail: lea ecx,[eax+4]; test ecx,ecx; jz; mov [ecx],eax
  // When node==null, ecx becomes 4 and the store is still gated only on ecx!=0 —
  // same MSVC shape as 0xC twin; callers assume new succeeds or accept path.
  if (reinterpret_cast<uint32_t*>(
          reinterpret_cast<uint8_t*>(node) + 4) != nullptr) {
    *reinterpret_cast<CircularSentinelNode0x28**>(
        reinterpret_cast<uint8_t*>(node) + 4) = node;
  }
  return node;
}

// Ghidra twin symbol
extern "C" CircularSentinelNode0x28* FUN_00423d60(void)
{
  return CircularSentinel_Alloc0x28_Inferred();
}
