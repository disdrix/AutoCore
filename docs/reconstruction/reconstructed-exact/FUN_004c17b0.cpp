// Twin of ParticleFluidLiquidChild_HostLink_Ctor_Inferred — see that file for sealed port.
// Stable ID: aa_004c17b0  VA: 0x004c17b0  Wave: W38-L

#include <cstdint>

struct ListNode0C {
  ListNode0C* next;
  ListNode0C* prev;
  void* value;
};

extern "C" ListNode0C* FUN_006759b0(ListNode0C* next, ListNode0C* prev, void** value_slot);
extern "C" void __thiscall FUN_004c20b0(void* list_size_base, uint32_t delta);
extern "C" void* PTR_LAB_009cb7a4[];

struct HostLink {
  void** vtbl;
  void* host;
};

extern "C" HostLink* __thiscall FUN_004c17b0(HostLink* self, void* host)
{
  self->vtbl = PTR_LAB_009cb7a4;
  self->host = host;
  if (host != nullptr) {
    ListNode0C* head = *reinterpret_cast<ListNode0C**>(reinterpret_cast<uint8_t*>(host) + 8);
    ListNode0C* old_prev = head->prev;
    void* value = self;
    ListNode0C* node = FUN_006759b0(head, old_prev, &value);
    FUN_004c20b0(reinterpret_cast<uint8_t*>(host) + 4, 1);
    head->prev = node;
    node->prev->next = node;
  }
  return self;
}
