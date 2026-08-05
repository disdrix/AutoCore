// =============================================================================
// ObjectMotion_SlotListTick_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_005bb5e0
// Address:   0x005bb5e0 – 0x005bb666  (autoassault.exe, image base 0x400000)
// System:    client object motion / reaction slot list
// Generated: 2026-07-29 W27-D dual seal (decompile + read_memory)
// Exactness: Behavior-preserving CF with byte-sealed post-delete count decrement.
//            Twin FUN_005bb5e0.cpp mirrors decompiler (notes the gap).
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Walk motion host list at +0xA24; tick each slot via ObjectMotion_SlotTick;
//   on return 0: teardown payload, unlink node, delete node, decrement +0xA28;
//   return remaining count.
//
// ABI:
//   __thiscall (ECX = motion host); stack (float *dt, uint32_t flag);
//   epilogue ret 8 (C2 08 00). EAX = *(host+0xA28).
//
// GLOBAL:
//   DAT_00af3f68 = *dt (movss); image default ≈ 0.1f
//
// RELATED:
//   FUN_004b4620 = ObjectMotion_SlotTick_Inferred (W26-H)
//   Caller FUN_004b8ed0 = NDSpecialFX_HostTick_Inferred (W24-C) @ 0x004b9103
// =============================================================================

#include <cstdint>

extern float DAT_00af3f68;
uint8_t __thiscall FUN_004b4620(void *slot, uint32_t flag, float dt);
void FUN_005be2b0(void *payload);
void operator_delete(void *p);

struct ListNode {
  ListNode *next;
  ListNode *prev;
  void *value;
};

uint32_t __thiscall ObjectMotion_SlotListTick_Inferred(void *motion_host, float *dt, uint32_t flag)
{
  auto *base = static_cast<uint8_t *>(motion_host);
  DAT_00af3f68 = *dt;

  auto *head = *reinterpret_cast<ListNode **>(base + 0xa24);
  ListNode *node = head->next;
  if (node != head) {
    do {
      void *payload = node->value;
      uint8_t keep = FUN_004b4620(payload, flag, *dt);
      ListNode *next;
      if (keep == 0) {
        FUN_005be2b0(payload);
        next = node->next;
        if (node != head) {
          node->prev->next = next;
          node->next->prev = node->prev;
          operator_delete(node);
          *reinterpret_cast<int *>(base + 0xa28) -= 1; // sealed by read_memory
        }
      }
      else {
        next = node->next;
      }
      node = next;
    } while (node != head);
  }
  return *reinterpret_cast<uint32_t *>(base + 0xa28);
}
