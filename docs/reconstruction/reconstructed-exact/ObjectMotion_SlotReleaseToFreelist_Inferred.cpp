// =============================================================================
// ObjectMotion_SlotReleaseToFreelist_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_005be2b0
// Address:   0x005be2b0 – 0x005be2e9 exclusive  (57 B / 0x39)
// Module:    autoassault.exe  image base 0x400000
// System:    client object motion / reaction slot freelist
// Ghidra:    FUN_005be2b0
// Generated: 2026-07-29 W28-I dual seal (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B:  accept (W28-I).
// =============================================================================
//
// PURPOSE:
//   Release a motion slot payload onto a singly-linked freelist.
//   If the slot holds a nested child at +0x8, run empty thiscall stub
//   FUN_004b0bd0 on the child, freelist-push the child, then clear +0x8.
//   Then run the stub on the slot itself and freelist-push the slot via dword0.
//
// ABI:
//   __thiscall  ECX = freelist head* (int*)
//   stack:      SlotNode* node
//   epilogue:   ret 4  (C2 04 00)
//
// CALL SITES (both load ECX = DAT_00b036c0 before call):
//   FUN_005bb5e0 ObjectMotion_SlotListTick_Inferred @ 0x005bb624 (remove path)
//   FUN_005bbc50 (motion host teardown walk of +0xA24 payloads) @ 0x005bbd0e
//
// RELATED:
//   FUN_004b0bd0 @ 0x004b0bd0 — empty body (thiscall; ECX = node being cleared)
//   DAT_00b036c0 — global freelist head used by both callers
// =============================================================================

#include <cstdint>

// Empty thiscall stub (decompile is `void FUN_004b0bd0(void){ return; }`).
// Call sites set ECX to the node being released (child, then parent).
extern "C" void __fastcall FUN_004b0bd0(void *node_ecx);

struct SlotNode {
  SlotNode *next;     // +0x0 freelist link
  uint32_t  _pad4;    // +0x4
  SlotNode *child;    // +0x8 nested child to freelist first
};

void __thiscall ObjectMotion_SlotReleaseToFreelist_Inferred(
    SlotNode **freelist_head /* ECX */,
    SlotNode *node /* stack */)
{
  if (node->child != nullptr) {
    FUN_004b0bd0(node->child);
    SlotNode *child = node->child;
    if (child != nullptr) {
      child->next = *freelist_head;
      *freelist_head = child;
    }
    node->child = nullptr;
  }
  FUN_004b0bd0(node);
  node->next = *freelist_head;
  *freelist_head = node;
}
