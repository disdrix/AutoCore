// =============================================================================
// ThreadSafeObjectList_Dtor
// -----------------------------------------------------------------------------
// Stable ID: aa_004bcbf0
// Address:   0x004bcbf0  (autoassault.exe, image base 0x400000)
// Body:      0x004bcbf0 – 0x004bcc31  (66 B, ret)
// System:    client::util / lock-protected object list
// Generated: 2026-07-29 W25-C dual A/B seal (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra:    FUN_004bcbf0
// =============================================================================
//
// PURPOSE:
//   Destructor body for the dual-critical-section object list:
//     1) reinstall list vtbl PTR_FUN_009cb368
//     2) drain all nodes via ThreadSafeObjectList_PopFront (nodes freed inside pop)
//     3) delete each returned payload via (*vtbl)(payload, 1)
//     4) zero count; DeleteCriticalSection on inner (+0x10) and outer (+0x28)
//
// ABI: __thiscall/__fastcall — ECX = list*; no stack formals; ret.
//
// TWINS:
//   FUN_0040b020  — ThreadSafeObjectList_PopFront
//   FUN_004024d0  — push/append
//   FUN_004bcc40  — scalar-deleting dtor wrapper (calls this, optional operator_delete)
//
// CALLERS (sample): FUN_004bcc40, FUN_0058c850, FUN_004bbc70, FUN_004d64d0, Unwind@009a5750
// =============================================================================

#include <cstdint>
#include <windows.h>

struct ThreadSafeObjectListNode {
  void* vtbl;                      // +0
  void* payload;                   // +4
  ThreadSafeObjectListNode* next;  // +8
};

struct ThreadSafeObjectList {
  void* vtbl;                    // +0x00  PTR_FUN_009cb368
  ThreadSafeObjectListNode* head; // +0x04
  ThreadSafeObjectListNode* tail; // +0x08
  volatile LONG count;           // +0x0C
  CRITICAL_SECTION csInner;      // +0x10
  CRITICAL_SECTION csOuter;      // +0x28
};

extern "C" void* __fastcall ThreadSafeObjectList_PopFront(ThreadSafeObjectList* list);
// FUN_0040b020

// Clean plate — CF matches FUN_004bcbf0 raw/live (no SEH in this unit).
void __fastcall ThreadSafeObjectList_Dtor(ThreadSafeObjectList* list)
{
  // *list = &PTR_FUN_009cb368
  list->vtbl = reinterpret_cast<void*>(0x009cb368);

  void* payload = ThreadSafeObjectList_PopFront(list);
  while (payload != nullptr) {
    // (*payload->vtbl)(payload, 1)
    auto** vtbl = *reinterpret_cast<void***>(payload);
    auto dtor = reinterpret_cast<void(__thiscall*)(void*, int)>(vtbl[0]);
    dtor(payload, 1);
    payload = ThreadSafeObjectList_PopFront(list);
  }

  list->count = 0;
  DeleteCriticalSection(&list->csInner);
  DeleteCriticalSection(&list->csOuter);
}

void __fastcall FUN_004bcbf0(ThreadSafeObjectList* list)
{
  ThreadSafeObjectList_Dtor(list);
}
