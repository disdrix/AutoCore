// =============================================================================
// CNDDoubleList_InsertTail_Inferred  (was FUN_00566f00)
// -----------------------------------------------------------------------------
// Stable ID: aa_00566f00
// Address:   0x00566f00  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer (primary consumer) + generic list utility
// Generated: 2026-07-29 dual A/B (bytes + decompile)
// Exactness: Behavior-preserving; offsets sealed from read_memory.
// Bit-for-bit vs retail EXE: DEFERRED.
// Dual: reviews/A|B_aa_00566f00_CNDDoubleList_InsertTail_Inferred.md
//
// PURPOSE:
//   Append payload as new tail of a CNDDoubleList-shaped host under CS.
//   Inventory PlaceItemFootprint calls with this = grid+0x2c, payload = item*.
//   Does NOT stamp grid cells.
//
// LAYOUT (sealed):
//   list+0x00 vtbl  (+4 = AllocateNode)
//   list+0x04 CRITICAL_SECTION
//   list+0x1c head*
//   list+0x20 tail*
//   list+0x24 count
//   list+0x28 traversal-lock (byte)
//   node+0x04 payload*
//   node+0x08 next*
//   node+0x0c prev*
// =============================================================================

#include <cstdint>
#include <windows.h>

// External retail helpers (symbols unresolved beyond role).
extern "C" void FUN_007a4480(int level, const char* msg);
extern "C" void __stdcall _CxxThrowException(void* pExceptionObject, void* pThrowInfo);
extern "C" void* DAT_00acc430; // ThrowInfo for HRESULT-style throw object

struct CndListNode {
  void* vtbl;           // +0x00 — destroy at vtbl[0] on remove path (sibling)
  void* payload;        // +0x04
  CndListNode* next;    // +0x08
  CndListNode* prev;    // +0x0c
};

struct CndDoubleList {
  void** vtbl;                    // +0x00; [1] @ +4 = AllocateNode(arg)
  CRITICAL_SECTION cs;            // +0x04  (MSVC CS size embeds through ~+0x1c)
  // NOTE: intervening CS bytes occupy +0x04 .. before head.
  // Head/tail/count/lock are absolute from list base (byte-sealed):
  //   +0x1c head, +0x20 tail, +0x24 count, +0x28 lock.
};

// Indexed field accessors matching int* decompiler view (dword indices).
static inline CndListNode*& Head(void* list) {
  return *reinterpret_cast<CndListNode**>(reinterpret_cast<char*>(list) + 0x1c);
}
static inline CndListNode*& Tail(void* list) {
  return *reinterpret_cast<CndListNode**>(reinterpret_cast<char*>(list) + 0x20);
}
static inline int& Count(void* list) {
  return *reinterpret_cast<int*>(reinterpret_cast<char*>(list) + 0x24);
}
static inline char& TraversalLock(void* list) {
  return *reinterpret_cast<char*>(reinterpret_cast<char*>(list) + 0x28);
}

// Allocate: list->vtbl[1](0)  ==  CALL [vtbl+4] with arg 0.
using AllocateNodeFn = CndListNode*(__thiscall*)(void* self, int zero);

// Returns 0 on success. Throws on traversal-lock or OOM (does not return).
std::uint32_t __thiscall CNDDoubleList_InsertTail_Inferred(void* list, void* payload)
{
  LPCRITICAL_SECTION cs =
      reinterpret_cast<LPCRITICAL_SECTION>(reinterpret_cast<char*>(list) + 4);

  EnterCriticalSection(cs);

  if (TraversalLock(list) != '\0') {
    FUN_007a4480(0, "VOG_DEBUG_STOP");
    std::uint32_t hr = 0x80070005; // E_ACCESSDENIED
    _CxxThrowException(&hr, &DAT_00acc430);
    // noreturn
  }

  void** vtbl = *reinterpret_cast<void***>(list);
  auto alloc = reinterpret_cast<AllocateNodeFn>(vtbl[1]); // offset +4
  CndListNode* node = alloc(list, 0);
  if (node == nullptr) {
    std::uint32_t hr = 0x8007000e; // E_OUTOFMEMORY
    _CxxThrowException(&hr, &DAT_00acc430);
    // noreturn
  }

  if (Head(list) == nullptr) {
    Head(list) = node;
  }

  CndListNode* oldTail = Tail(list);
  node->prev = oldTail;           // +0xc
  if (oldTail != nullptr) {
    oldTail->next = node;         // +0x8
  }

  node->payload = payload;        // +0x4
  Count(list) = Count(list) + 1;
  Tail(list) = node;

  LeaveCriticalSection(cs);
  return 0;
}
