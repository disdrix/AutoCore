// =============================================================================
// OwningSList_ClearDestroy_ScalarDtor_Inferred  (FUN_004bf740)
// -----------------------------------------------------------------------------
// Stable ID: aa_004bf740
// Address:   0x004bf740–0x004bf76f exclusive (47 B / 0x2F)
// Module:    autoassault.exe (image base 0x400000)
// System:    owning singly-linked list clear / ListTrackedObj list region
// Generated: 2026-07-29 W31-B dual seal (prior scaffold 2026-07-23)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================
//
// PURPOSE: Destroy every node in an owning singly-linked list whose head sits at
// host+0x04 and count at host+0x0c. Each node is polymorphic: vtbl[0] is invoked
// as MSVC scalar-deleting destructor with flags=1 (dtor + operator_delete).
// Does not free the list host object itself.
//
// ABI: thiscall ECX=host; bare ret (C3); void.
//
// RELATED (context, not this unit):
//   - Sole CALL: ListTrackedObj_CompleteDtor (0x004be2a0) @ 0x004be321
//     → FUN_004bf740(this+0x10) when flag@this+0x5D0
//   - Reject scaffold Named_CalleeOf_*_VOG_DEBUG_ST_004bf740
//

#include <cstdint>

struct OwningSListNode_Inferred {
  void** vtbl;                     // +0x00; [0] = scalar deleting dtor
  OwningSListNode_Inferred* next;  // +0x04
};

struct OwningSListHost_Inferred {
  // +0x00: unused by this unit
  uint32_t _pad00;
  OwningSListNode_Inferred* head;  // +0x04
  // +0x08: unused by this unit
  uint32_t _pad08;
  int32_t count;                   // +0x0c
};

using ScalarDeletingDtor_Fn = void(__fastcall*)(OwningSListNode_Inferred* self, int flags);
// Note: retail uses thiscall (ECX=self) + stack arg flags; modeled as call [vtbl] after push 1.

void __fastcall OwningSList_ClearDestroy_ScalarDtor_Inferred(OwningSListHost_Inferred* host)
{
  while (host->head != nullptr) {
    OwningSListNode_Inferred* node = host->head;
    if (node != nullptr) {
      host->head = node->next;
      // push 1; call dword ptr [node->vtbl]  — scalar deleting dtor
      auto* dtor = reinterpret_cast<ScalarDeletingDtor_Fn>(node->vtbl[0]);
      dtor(node, 1);
      host->count = host->count - 1;
    }
  }
}

// Ghidra alias
void __fastcall FUN_004bf740(OwningSListHost_Inferred* host)
{
  OwningSList_ClearDestroy_ScalarDtor_Inferred(host);
}
