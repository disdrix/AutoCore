// =============================================================================
// ThreadSafeObjectList_PopFront
// -----------------------------------------------------------------------------
// Stable ID: aa_0040b020
// Address:   0x0040b020  (autoassault.exe, image base 0x400000)
// Body:      0x0040b020 – 0x0040b136  (ret / SEH)
// System:    client::util / lock-protected object list
// Generated: 2026-07-29 W24-S dual A/B seal (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra:    FUN_0040b020
// =============================================================================
//
// PURPOSE:
//   Pop the head node of a dual-critical-section object list, destroy the node
//   (vtbl delete with flag 1), InterlockedDecrement the count, and return the
//   payload pointer (object*). Empty list returns NULL without locking.
//
// ABI: __thiscall/__fastcall — ECX = list*; no stack formals; ret.
//
// TWINS:
//   FUN_004024d0  — push/append object (new 0xC node)
//   FUN_004bcbf0  — dtor: drain via PopFront + DeleteCriticalSection ×2
//
// CALLERS (sample): FUN_0058c850 (multi-target skill iterate), FUN_004bcbf0,
//   Client_NotifyActiveMissionChanged path, FUN_004bbc70, FUN_004e0ad0, …
//
// SEALED: head+4 / tail+8 / count+0xC / CS+0x10 / CS+0x28; node payload+4 next+8.
// =============================================================================

#include <cstdint>
#include <windows.h>

struct ThreadSafeObjectListNode {
  void* vtbl;     // +0  dtor at vtbl[0](this, 1)
  void* payload;  // +4  returned to caller
  ThreadSafeObjectListNode* next;  // +8
};

struct ThreadSafeObjectList {
  void* vtbl;                          // +0x00  (PTR_FUN_009cb368 when full-constructed)
  ThreadSafeObjectListNode* head;      // +0x04
  ThreadSafeObjectListNode* tail;      // +0x08
  volatile LONG count;                 // +0x0C
  CRITICAL_SECTION csInner;            // +0x10  (entered when count < 2)
  // CRITICAL_SECTION spans 0x18 bytes on x86 → outer at +0x28
  CRITICAL_SECTION csOuter;            // +0x28
};

// Clean plate — CF matches FUN_0040b020 raw (SEH omitted).
void* __fastcall ThreadSafeObjectList_PopFront(ThreadSafeObjectList* list)
{
  if (list->head == nullptr) {
    return nullptr;
  }

  EnterCriticalSection(&list->csOuter);
  ThreadSafeObjectListNode* node = list->head;
  bool takeInner = (list->count < 2);
  if (takeInner) {
    EnterCriticalSection(&list->csInner);
  }

  void* payload = node->payload;
  ThreadSafeObjectListNode* next = node->next;
  list->head = next;
  if (next == nullptr) {
    list->tail = nullptr;
  }

  node->payload = nullptr;
  // (*node->vtbl)(node, 1) — MSVC thiscall dtor/delete
  (*(void(__thiscall**)(ThreadSafeObjectListNode*, int))node->vtbl)(node, 1);

  if (takeInner) {
    LeaveCriticalSection(&list->csInner);
  }
  LeaveCriticalSection(&list->csOuter);
  InterlockedDecrement(&list->count);
  return payload;
}

void* __fastcall FUN_0040b020(ThreadSafeObjectList* list)
{
  return ThreadSafeObjectList_PopFront(list);
}
