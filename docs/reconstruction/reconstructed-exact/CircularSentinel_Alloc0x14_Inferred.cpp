// =============================================================================
// CircularSentinel_Alloc0x14_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0043c460
// Address:   0x0043c460–0x0043c479  (26 B / 0x1A; autoassault.exe base 0x400000)
// System:    shared circular-list / hash-bucket sentinel factory
// Generated: 2026-07-23 scaffold as FUN_0043c460; dual A/B seal 2026-07-29 (W35-B)
// Exactness: Behavior-preserving rewrite of decompiler + full-body bytes.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE:
//   Allocate a 0x14-byte node and install circular next/prev self-links.
//   Used as empty-list / NestedHash / HeadBag sentinel (node size 0x14 family).
//
// ABI:
//   No formals; bare RET; returns node* in EAX.
//   Family twins: CircularSentinel_Alloc0x28 (0x00423d60), StdList_AllocSentinel_0xC
//   (0x004933f0) — same 26 B CF, different size immediate.
//
// REJECT: scaffold Named_CalleeOf_*VOG_DEBUG* product aliases.
//

#include <cstdint>

// Retail CRT
extern "C" void* __cdecl operator_new(uint32_t size);

// Node layout (only +0/+4 written here; remaining 0x0C payload unowned)
struct CircularSentinelNode0x14 {
  CircularSentinelNode0x14* next; // +0x00
  CircularSentinelNode0x14* prev; // +0x04
  uint8_t payload[0x0C];          // +0x08 .. +0x13 (not written by this factory)
};

extern "C" CircularSentinelNode0x14* CircularSentinel_Alloc0x14_Inferred(void)
{
  auto* node = static_cast<CircularSentinelNode0x14*>(operator_new(0x14));
  if (node != nullptr) {
    node->next = node;
  }
  // Retail: lea ecx,[eax+4]; test ecx,ecx; jz; mov [ecx],eax
  // When node==null, ecx becomes 4 and the store is still gated only on ecx!=0 —
  // same MSVC shape as 0xC / 0x28 twins; callers assume new succeeds or accept path.
  if (reinterpret_cast<uint32_t*>(
          reinterpret_cast<uint8_t*>(node) + 4) != nullptr) {
    *reinterpret_cast<CircularSentinelNode0x14**>(
        reinterpret_cast<uint8_t*>(node) + 4) = node;
  }
  return node;
}

// Ghidra twin symbol
extern "C" CircularSentinelNode0x14* FUN_0043c460(void)
{
  return CircularSentinel_Alloc0x14_Inferred();
}
