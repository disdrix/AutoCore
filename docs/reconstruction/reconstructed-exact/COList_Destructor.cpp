// =============================================================================
// COList_Destructor
// -----------------------------------------------------------------------------
// Stable ID: aa_004bbc70
// Address:   0x004bbc70–0x004bbea4  (565 B, autoassault.exe base 0x400000)
// System:    client / COList (cloned-object list host)
// Generated: 2026-07-29 W26-J dual A/B (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler CF + byte-sealed stack list.
// Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra:    FUN_004bbc70
// =============================================================================
//
// PURPOSE:
//   COList C++ destructor body. Product class from vtbl rdata strings
//   "Threw error in COList::Insert" / "Threw HRESULT in COList::Insert".
//   Builds a stack ThreadSafeObjectList, walks two CNDHash members, queues
//   objects with +0xac set, drains via PopFront + ClonedObjectList_TakeByCoid,
//   virtual-deletes owned subobjects, tears down the stack list, frees vectors.
//
// ABI:
//   __thiscall; ECX=this; frame sub/add esp,0x44; bare ret; void.
//   Entry: 83 EC 44 … C7 06 48 B4 9C 00  (*this = PTR_FUN_009cb448)
//   Exit:  5E 5D 5B 83 C4 44 C3
//
// TWINS:
//   FUN_004bd1b0  — scalar-deleting dtor (vtbl[0]; ret 4)
//   FUN_004bbfb0  — constructor (same vtbl; Client_InitInstance → DAT_00b04830)
//   FUN_004bb970  — ClonedObjectList_TakeByCoid_Inferred
//   FUN_004024d0 / FUN_0040b020 / FUN_004bcbf0 — list append/pop/dtor
// =============================================================================

#include <cstdint>
#include <windows.h>

struct ThreadSafeObjectListNode {
  void* vtbl;
  void* payload;
  ThreadSafeObjectListNode* next;
};

struct ThreadSafeObjectList {
  void* vtbl;                      // +0x00 PTR_FUN_009cb368
  ThreadSafeObjectListNode* head;  // +0x04
  ThreadSafeObjectListNode* tail;  // +0x08
  volatile LONG count;             // +0x0C
  CRITICAL_SECTION csInner;        // +0x10
  CRITICAL_SECTION csOuter;        // +0x28
};

// COList host (partial; fields used by this dtor).
struct COList {
  void* vtbl;          // +0x00 → PTR_FUN_009cb448
  void* hashA;         // +0x04  CNDHash*
  void* hashB;         // +0x08  CNDHash*
  uint32_t pad_0c[3];  // +0x0C..
  void* owned6;        // +0x18  dword index 6
  void* owned7;        // +0x1C
  void* owned8;        // +0x20
  void* owned9;        // +0x24
  // ... vectors at dword indices 0x0b, 0x0f, 0x13 (byte +0x2C, +0x3C, +0x4C)
  uint32_t rest[0x20];
};

extern void* PTR_FUN_009cb448;
extern void* PTR_FUN_009cb368;

extern "C" uint32_t __thiscall FUN_004024d0(ThreadSafeObjectList* list, void* payload);
extern "C" void* __fastcall FUN_0040b020(ThreadSafeObjectList* list);
extern "C" int __thiscall FUN_004bb970(COList* self, uint32_t mode, uint32_t coidLo, uint32_t coidHi);
extern "C" void __fastcall FUN_004bcbf0(ThreadSafeObjectList* list);
extern "C" void FUN_007a4480(int level, const char* msg);
extern "C" void operator_delete(void* p);

static void virtual_delete_if(void*& slot) {
  if (slot != nullptr) {
    void** obj = reinterpret_cast<void**>(slot);
    auto fn = *reinterpret_cast<void(__thiscall**)(void*, int)>(*obj);
    fn(obj, 1);
    slot = nullptr;
  }
}

static void free_buffer_triple(uint32_t* slot0) {
  void* p = reinterpret_cast<void*>(slot0[0]);
  if (p != nullptr) {
    operator_delete(p);
  }
  slot0[0] = 0;
  slot0[1] = 0;
  slot0[2] = 0;
}

static void hash_collect_locked(void* hash, ThreadSafeObjectList* outList) {
  if (hash == nullptr) return;
  uint8_t* h = reinterpret_cast<uint8_t*>(hash);
  if (h[0x1d] != 0) {
    FUN_007a4480(0, "HashError:TraversalLock, already locked for traversal");
    FUN_007a4480(0, "VOG_DEBUG_STOP");
  }
  h[0x1d] = 1;

  int node = 0;
  for (;;) {
    h = reinterpret_cast<uint8_t*>(hash);
    if (h[0x1d] == 0) {
      FUN_007a4480(0, "HashError:TraverseToNext, not locked for traversal");
      FUN_007a4480(0, "VOG_DEBUG_STOP");
    }
    if (node == 0) {
      node = *reinterpret_cast<int*>(h + 0x14);
    } else {
      node = *reinterpret_cast<int*>(node + 0x20);
    }
    int obj = (node == 0) ? 0 : *reinterpret_cast<int*>(node + 0x0C);
    if (obj == 0) break;
    if (*reinterpret_cast<int*>(obj + 0xac) != 0) {
      FUN_004024d0(outList, reinterpret_cast<void*>(obj));
    }
  }
  reinterpret_cast<uint8_t*>(hash)[0x1d] = 0;
}

void __fastcall COList_Destructor(COList* self)
{
  self->vtbl = PTR_FUN_009cb448;

  // Stack ThreadSafeObjectList (bytes: vtbl 009cb368, zeros, ICS×2).
  ThreadSafeObjectList stackList;
  stackList.vtbl = PTR_FUN_009cb368;
  stackList.head = nullptr;
  stackList.tail = nullptr;
  stackList.count = 0;
  InitializeCriticalSection(&stackList.csInner);
  InitializeCriticalSection(&stackList.csOuter);

  hash_collect_locked(self->hashA, &stackList);
  hash_collect_locked(self->hashB, &stackList);

  void* payload = FUN_0040b020(&stackList);
  while (payload != nullptr) {
    uint8_t* p = reinterpret_cast<uint8_t*>(payload);
    FUN_004bb970(
        self,
        *reinterpret_cast<uint8_t*>(p + 0x168),
        *reinterpret_cast<uint32_t*>(p + 0x160),
        *reinterpret_cast<uint32_t*>(p + 0x164));
    payload = FUN_0040b020(&stackList);
  }

  // dword indices 6,7,8,9,1,2
  uint32_t* w = reinterpret_cast<uint32_t*>(self);
  virtual_delete_if(reinterpret_cast<void*&>(w[6]));
  virtual_delete_if(reinterpret_cast<void*&>(w[7]));
  virtual_delete_if(reinterpret_cast<void*&>(w[8]));
  virtual_delete_if(reinterpret_cast<void*&>(w[9]));
  virtual_delete_if(reinterpret_cast<void*&>(w[1]));
  virtual_delete_if(reinterpret_cast<void*&>(w[2]));

  FUN_004bcbf0(&stackList); // ThreadSafeObjectList_Dtor (drain residual + DeleteCS×2)

  free_buffer_triple(&w[0x13]);
  free_buffer_triple(&w[0x0f]);
  free_buffer_triple(&w[0x0b]);
}
