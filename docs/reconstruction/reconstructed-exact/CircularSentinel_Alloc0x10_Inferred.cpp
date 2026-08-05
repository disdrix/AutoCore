// =============================================================================
// CircularSentinel_Alloc0x10_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004397f0
// Address:   0x004397f0–0x00439809  (26 B / 0x1A; autoassault.exe base 0x400000)
// System:    shared circular-list / hash-bucket sentinel factory
// Generated: 2026-07-23 scaffold as FUN_004397f0; dual A/B seal 2026-07-29 (W35-C)
// Exactness: Behavior-preserving rewrite of decompiler + full-body bytes.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE:
//   Allocate a 0x10-byte node and install circular next/prev self-links.
//   Used as the empty-list / hash-bucket sentinel by NestedHash_Ctor_Sentinel0x10
//   (FUN_00457ac0, W34-E) and several other list-host sites.
//
// ABI:
//   No formals; bare RET; returns node* in EAX.
//   Family twins: CircularSentinel_Alloc0x28 (0x00423d60), StdList_AllocSentinel_0xC
//   (0x004933f0) — same 26 B CF, different size immediate.
//
// REJECT: scaffold Named_CalleeOf_* product aliases.
//

#include <cstdint>

// Retail CRT
extern "C" void* __cdecl operator_new(uint32_t size);

// Node layout (only +0/+4 written here; remaining 0x08 payload unowned)
struct CircularSentinelNode0x10 {
  CircularSentinelNode0x10* next; // +0x00
  CircularSentinelNode0x10* prev; // +0x04
  uint8_t payload[0x08];          // +0x08 .. +0x0f (not written by this factory)
};

extern "C" CircularSentinelNode0x10* CircularSentinel_Alloc0x10_Inferred(void)
{
  auto* node = static_cast<CircularSentinelNode0x10*>(operator_new(0x10));
  if (node != nullptr) {
    node->next = node;
  }
  // Retail: lea ecx,[eax+4]; test ecx,ecx; jz; mov [ecx],eax
  // When node==null, ecx becomes 4 and the store is still gated only on ecx!=0 —
  // same MSVC shape as 0x28 / 0xC twins; callers assume new succeeds or accept path.
  if (reinterpret_cast<uint32_t*>(
          reinterpret_cast<uint8_t*>(node) + 4) != nullptr) {
    *reinterpret_cast<CircularSentinelNode0x10**>(
        reinterpret_cast<uint8_t*>(node) + 4) = node;
  }
  return node;
}

// Ghidra twin symbol
extern "C" CircularSentinelNode0x10* FUN_004397f0(void)
{
  return CircularSentinel_Alloc0x10_Inferred();
}
