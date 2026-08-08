// =============================================================================
// StdList_Resize_EsiList_EaxCount_Inferred  (Ghidra: FUN_00402dd0)
// -----------------------------------------------------------------------------
// Stable ID: aa_00402dd0
// Address:   0x00402dd0  (autoassault.exe, image base 0x400000)
// Body:      0x00402dd0–0x00402e1f inclusive (80 B / 0x50)
// System:    shared MSVC-style std::list resize (missions-progression consumers)
// Generated: 2026-08-05 MEGA-127 OWN-ONLY dual A/B
// Exactness: Behavior-preserving rewrite of decompiler CF + byte ABI.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Resize a circular doubly-linked list shell to EAX element count:
//     ESI = list*   (+4 head/sentinel*, +8 size)
//     EAX = new_size
//     [esp+4] = fill value (used only on grow; address taken into grow helper)
//     RET 4
//   Grow: FUN_004034c0(list, head, n) with ECX=&fill inserts n nodes.
//   Shrink: pop_back loop — unlink head->_Prev, operator_delete, size--.
//
// CALLERS (5 UNCONDITIONAL_CALL; all live sites use EAX=0 = clear):
//   Client_DebugListMissionsStatus  FUN_009572e0 @ 0x00957447
//   FUN_008eca80 @ 0x008ecb86
//   FUN_00801c50 @ 0x00801d84
//   FUN_0080b7f0 @ 0x0080b87f
//   FUN_008a5c90 @ 0x008a5d7c
//
// DISTINCT FROM:
//   StdList_Clear_ESI 0x00415e90 — clear-only, bare RET, no fill/grow
//   StdList_Clear ECX twin 0x00404060
//   Scaffold Named_CalleeOf_Client_DebugListMissionsStatus_00402dd0 (retired)
//
// Dual: accept-with-gaps (element type / runtime open).
// =============================================================================

#include <cstdint>

struct ListNode {
  ListNode* next;  // +0x00
  ListNode* prev;  // +0x04
  // T value follows (width product-open)
};

struct ListShell {
  uint32_t reserved0;  // +0x00 (unused in this unit)
  ListNode* head;      // +0x04 sentinel
  uint32_t size;       // +0x08 _Mysize
};

// Unowned callees — declarations only.
// Grow: inserts `count` copies of *fill_via_ecx before/at head position.
extern "C" void __thiscall FUN_004034c0(ListShell* list,
                                        ListNode* head,
                                        uint32_t count);
// cdecl free
extern "C" void operator_delete(void* p);

// Documentary signature — real ABI is register-heavy (see plate).
// Ports must: ESI=list, EAX=n, push fill, call, expect RET 4.
extern "C" void StdList_Resize_EsiList_EaxCount_Inferred(
    ListShell* list /*esi*/,
    uint32_t new_size /*eax*/,
    uint32_t fill /*stack; element type inferred as dword-class*/)
{
  uint32_t cur = list->size;
  if (cur < new_size) {
    // Bytes: SUB EDI,EAX; PUSH n; PUSH head; PUSH list;
    //        LEA ECX,[ESP+0x14]=&fill; CALL FUN_004034c0; POP EDI; RET 4
    (void)fill;
    FUN_004034c0(list, list->head, new_size - cur);
    return;
  }

  // Equal or shrink. Equal falls through with new_size >= size false on JB.
  while (new_size < list->size) {
    ListNode* head = list->head;
    ListNode* node = head->prev;  // back of list
    if (node != head) {
      // unlink from circular ring
      node->prev->next = node->next;
      node->next->prev = node->prev;
      operator_delete(node);
      list->size--;
    }
    // if empty ring, recheck size vs target (matches JZ recheck path)
  }
  // RET 4
}
