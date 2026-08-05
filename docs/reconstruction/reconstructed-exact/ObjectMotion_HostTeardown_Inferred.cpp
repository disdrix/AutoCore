// =============================================================================
// ObjectMotion_HostTeardown_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_005bbc50
// Address:   0x005bbc50  (Ghidra body end 0x005bbd96 exclusive; true ret c3 ~0x005bbdc0)
// Module:    autoassault.exe  image base 0x400000
// System:    client object motion / reaction host teardown
// Ghidra:    FUN_005bbc50
// Generated: 2026-07-29 W30-S dual seal (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B:  accept-with-gaps (W30-S).
// =============================================================================
//
// PURPOSE:
//   Tear down a motion/FX host object:
//     1. Clear/free primary buffer (+0x308 vs inline +0x14) via FUN_005b8340 + delete.
//     2. If flag +0x7fc: clear/free secondary buffer (+0x6ec vs inline +0x3f8).
//     3. Walk list at +0xa24; freelist-release each slot payload (node[+0x8]) through
//        ObjectMotion_SlotReleaseToFreelist_Inferred with global head DAT_00b036c0.
//     4. Empty list nodes, free sentinel, null +0xa24 / count +0xa28.
//
// ABI:
//   __thiscall  ECX = host*
//   stack:      none
//   epilogue:   ret (c3) after SEH cleanup  [Ghidra truncates on noreturn delete]
//
// CALLER:
//   FUN_005be310 @ 0x005be310 (W30-R) — calls this then optional freelist push
//
// RELATED:
//   ObjectMotion_SlotReleaseToFreelist_Inferred (0x005be2b0, W28-I)
//   FUN_005b8340 — buffer/list clear helper
//   DAT_00b036c0 — global slot freelist head
// =============================================================================

#include <cstdint>

struct SlotNode;
struct ListNode {
  ListNode *next;      // +0x0
  ListNode *prev;      // +0x4
  SlotNode *payload;   // +0x8  (released via freelist helper)
};

// Buffer/list clear helper (not OWN this unit). ECX targets sub-objects in retail.
extern "C" void __fastcall FUN_005b8340(void *ctrl_ecx);

// W28-I sealed.
extern "C" void __thiscall ObjectMotion_SlotReleaseToFreelist_Inferred(
    SlotNode **freelist_head /* ECX */,
    SlotNode *node /* stack */);

extern "C" void operator_delete(void *p);

// Global freelist head used by retail call sites.
static SlotNode **const kSlotFreelistHead =
    reinterpret_cast<SlotNode **>(static_cast<uintptr_t>(0x00B036C0));

void __thiscall ObjectMotion_HostTeardown_Inferred(uint8_t *host /* ECX */)
{
  // --- primary buffer (+0x308 heap vs +0x14 inline) ---
  // FUN_005b8340 ECX values follow retail call sites (buffer headers); scaffold uses host.
  FUN_005b8340(host);
  void *primary = *reinterpret_cast<void **>(host + 0x308);
  if (primary != static_cast<void *>(host + 0x14)) {
    FUN_005b8340(host);
    operator_delete(primary);
  }
  FUN_005b8340(host);

  // --- optional secondary buffer when +0x7fc ---
  if (*reinterpret_cast<char *>(host + 0x7fc) != 0) {
    void *secondary = *reinterpret_cast<void **>(host + 0x6ec);
    if (secondary != static_cast<void *>(host + 0x3f8)) {
      FUN_005b8340(host);
      operator_delete(secondary);
    }
    FUN_005b8340(host);
  }

  // --- slot list +0xa24: freelist-release each payload @ node[+0x8] ---
  ListNode *sentinel = *reinterpret_cast<ListNode **>(host + 0xa24);
  ListNode *it = sentinel->next;
  if (it != sentinel) {
    do {
      ObjectMotion_SlotReleaseToFreelist_Inferred(kSlotFreelistHead, it->payload);
      it = it->next;
    } while (it != *reinterpret_cast<ListNode **>(host + 0xa24));
  }

  // --- empty list + free sentinel ---
  // Decompiler shows two reset blocks + single delete (operator_delete noreturn artifact).
  // Bytes include jnz free-loop; staged clean walks all nodes then frees sentinel.
  ListNode *sent = *reinterpret_cast<ListNode **>(host + 0xa24);
  ListNode *node = sent->next;
  sent->next = sent;
  sent->prev = sent;
  *reinterpret_cast<uint32_t *>(host + 0xa28) = 0;
  while (node != sent) {
    ListNode *next = node->next;
    operator_delete(node);
    node = next;
  }
  operator_delete(sent);
  *reinterpret_cast<ListNode **>(host + 0xa24) = nullptr;

  // SEH epilog → ret (c3) — omitted
}
