// =============================================================================
// StdList_AllocSentinel_0x30_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_005b43b0
// Address:   0x005b43b0–0x005b43c9 inclusive (26 B / 0x1A)
// Module:    autoassault.exe (image base 0x400000)
// System:    shared std::list-style sentinel factory
// Wave:      W35-G 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler CF + body hex.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Allocate a 0x30-byte circular empty-list sentinel:
//     node->next = node; node->prev = node;
//   Returns node* in EAX. Decompiler wrongly shows void.
//   Sibling of StdList_AllocSentinel_0xC (0x004933f0) and _0x18 (0x00457c60).
//   Differentiator used by NestedHash_Ctor_Sentinel0x30 hosts (vs Ass 0x28).
//
// CALLERS (5): NestedHash_Ctor_Sentinel0x30, NestedHashBag_Ctor_Sentinel0x30,
//   Obj_DefaultCtor list@+0x10, Obj populate ctor, FUN_004d8a10 large host.
//   Typical pair: head = Alloc(); size = 0;
//
// =============================================================================

#include <cstdint>

// MSVC CRT
void* __cdecl operator_new(unsigned int size);

struct ListNode30 {
  ListNode30* next;  // +0x00
  ListNode30* prev;  // +0x04
  // +0x08..+0x2F: payload / unused by this factory (not written)
};

// Ghidra: FUN_005b43b0 / void FUN_005b43b0(void)  — return type WRONG
extern "C" void* StdList_AllocSentinel_0x30_Inferred(void)
{
  void* node = operator_new(0x30);
  if (node != nullptr) {
    *reinterpret_cast<void**>(node) = node; // +0 next = self
  }
  // Matches retail: test (node+4); store prev even when node null would
  // target 0x4 — relies on non-null operator_new.
  if (reinterpret_cast<std::uint32_t*>(static_cast<char*>(node) + 4) != nullptr) {
    *reinterpret_cast<void**>(static_cast<char*>(node) + 4) = node; // +4 prev = self
  }
  return node; // EAX
}
