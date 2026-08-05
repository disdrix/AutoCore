// =============================================================================
// ParticleFluidLiquidChild_HostLink_Ctor_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004c17b0
// Address:   0x004c17b0  (autoassault.exe, image base 0x400000)
// System:    particle / fluid liquid-child host-link subobject
// Wave:      W38-L OWN-ONLY dual (2026-08-04)
// Exactness: Behavior-preserving rewrite of decompiler + sealed bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE: Construct the 8-byte host-link subobject embedded at liquid-child +0x18.
//   *this = vtbl 009cb7a4; *(this+4) = host.
//   If host non-null: push_back `this` onto host's 0xC-node list (head @ host+8,
//   size @ host+0xC) via buynode FUN_006759b0 + incsize FUN_004c20b0.
//
// ABI: __thiscall; ECX = HostLink*; stack host*; returns this; RET 4.
// Sole caller: ParticleFluidLiquidChild_Ctor_Inferred (0x004c1800, W37-G).
//
// Reject: Named_CalleeOf_*Drive_NDRiver_fx scaffold product alias.

#include <cstdint>

struct ListNode0C {
  ListNode0C* next;   // +0
  ListNode0C* prev;   // +4
  void* value;        // +8  (HostLink*)
};

// External (unOWN): allocate 0xC list node {next, prev, *value_slot}
extern "C" ListNode0C* FUN_006759b0(ListNode0C* next, ListNode0C* prev, void** value_slot);

// External (unOWN): list size += delta; throw "list<T> too long" if overflow.
// thiscall: ECX points such that size dword is at ECX+8 (for liquid child: ECX=host+4 → size@host+0xC).
extern "C" void __thiscall FUN_004c20b0(void* list_size_base, uint32_t delta);

// vtbl first slot → 0x004c09c0 (unOWN method; touches host+0x20 path)
extern "C" void* PTR_LAB_009cb7a4[];

struct HostLink {
  void** vtbl;   // +0 = &PTR_LAB_009cb7a4
  void* host;    // +4 liquid-child (or null)
};

extern "C" HostLink* __thiscall ParticleFluidLiquidChild_HostLink_Ctor_Inferred(
    HostLink* self,
    void* host)
{
  self->vtbl = PTR_LAB_009cb7a4;
  self->host = host;

  if (host != nullptr) {
    // head sentinel pointer at host+8; size at host+0xC
    ListNode0C* head = *reinterpret_cast<ListNode0C**>(reinterpret_cast<uint8_t*>(host) + 8);
    ListNode0C* old_prev = head->prev;

    // Stack slot reused: value written as `self` before buynode reads it
    void* value = self;
    ListNode0C* node = FUN_006759b0(head, old_prev, &value);

    // IncSize: ECX = host+4 so +(8) hits host+0xC
    void* size_base = reinterpret_cast<uint8_t*>(host) + 4;
    FUN_004c20b0(size_base, 1);

    // splice as push_back (insert before sentinel)
    head->prev = node;
    node->prev->next = node; // old_prev->next = node (buynode set node->prev = old_prev)
  }

  return self;
}

// Ghidra twin
extern "C" HostLink* __thiscall FUN_004c17b0(HostLink* self, void* host)
{
  return ParticleFluidLiquidChild_HostLink_Ctor_Inferred(self, host);
}
