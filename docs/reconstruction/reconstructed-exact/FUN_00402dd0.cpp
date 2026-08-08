// =============================================================================
// FUN_00402dd0  — clean twin of StdList_Resize_EsiList_EaxCount_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00402dd0
// Address:   0x00402dd0  (autoassault.exe, image base 0x400000)
// Body:      0x00402dd0–0x00402e1f inclusive (80 B / 0x50)
// Prefer:    StdList_Resize_EsiList_EaxCount_Inferred.cpp (named clean)
// Generated: 2026-08-05 MEGA-127 (replaces 2026-07-23 scaffold)
// Exactness: Behavior-preserving; twin keeps Ghidra symbol as filename.
// =============================================================================
//
// ABI (machine): ESI = list* (+4 head, +8 size); EAX = new_size;
//                stack fill; RET 4. Decompiler shows void()/unaff_ESI/in_EAX.
// =============================================================================

#include <cstdint>

struct ListNode_00402dd0 {
  ListNode_00402dd0* next;  // +0
  ListNode_00402dd0* prev;  // +4
};

struct ListShell_00402dd0 {
  uint32_t reserved0;
  ListNode_00402dd0* head;  // +4
  uint32_t size;            // +8
};

extern "C" void __thiscall FUN_004034c0(void* list, void* head, uint32_t count);
extern "C" void operator_delete(void* p);

// Documentary — real ABI is ESI/EAX/stack (see named clean plate).
extern "C" void FUN_00402dd0(ListShell_00402dd0* list /*esi*/,
                             uint32_t new_size /*eax*/,
                             uint32_t fill /*stack*/)
{
  uint32_t cur = list->size;
  if (cur < new_size) {
    (void)fill;
    FUN_004034c0(list, list->head, new_size - cur);
    return;  // RET 4
  }

  while (new_size < list->size) {
    ListNode_00402dd0* head = list->head;
    ListNode_00402dd0* node = head->prev;
    if (node != head) {
      node->prev->next = node->next;
      node->next->prev = node->prev;
      operator_delete(node);
      list->size--;
    }
  }
  // RET 4
}
