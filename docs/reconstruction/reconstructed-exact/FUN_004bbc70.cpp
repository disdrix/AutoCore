// =============================================================================
// FUN_004bbc70  (scaffold twin of COList_Destructor)
// -----------------------------------------------------------------------------
// Stable ID: aa_004bbc70
// Address:   0x004bbc70–0x004bbea4  (565 B, autoassault.exe base 0x400000)
// System:    client / COList
// Generated: 2026-07-29 W26-J dual A/B
// Canonical: COList_Destructor.cpp
// =============================================================================

#include <cstdint>
#include <windows.h>

extern void* PTR_FUN_009cb448;
extern void* PTR_FUN_009cb368;

extern "C" uint32_t __thiscall FUN_004024d0(void* list, void* payload);
extern "C" void* __fastcall FUN_0040b020(void* list);
extern "C" int __thiscall FUN_004bb970(void* self, uint32_t mode, uint32_t a, uint32_t b);
extern "C" void __fastcall FUN_004bcbf0(void* list);
extern "C" void FUN_007a4480(int level, const char* msg);
extern "C" void operator_delete(void* p);

static void vdel(uint32_t* slot) {
  if (*slot != 0) {
    uint32_t* obj = reinterpret_cast<uint32_t*>(*slot);
    (**(void(__thiscall***)(uint32_t*, int))*obj)(obj, 1);
    *slot = 0;
  }
}

static void free3(uint32_t* s) {
  if (s[0] != 0) operator_delete(reinterpret_cast<void*>(s[0]));
  s[0] = s[1] = s[2] = 0;
}

static void traverse_hash(uint32_t* hash_slot, uint32_t* stackList) {
  uint8_t* h = reinterpret_cast<uint8_t*>(*hash_slot);
  if (h[0x1d] != 0) {
    FUN_007a4480(0, "HashError:TraversalLock, already locked for traversal");
    FUN_007a4480(0, "VOG_DEBUG_STOP");
  }
  h[0x1d] = 1;
  int node = 0;
  for (;;) {
    h = reinterpret_cast<uint8_t*>(*hash_slot);
    if (h[0x1d] == 0) {
      FUN_007a4480(0, "HashError:TraverseToNext, not locked for traversal");
      FUN_007a4480(0, "VOG_DEBUG_STOP");
    }
    node = (node == 0) ? *reinterpret_cast<int*>(h + 0x14)
                       : *reinterpret_cast<int*>(node + 0x20);
    int obj = (node == 0) ? 0 : *reinterpret_cast<int*>(node + 0x0C);
    if (obj == 0) break;
    if (*reinterpret_cast<int*>(obj + 0xac) != 0) {
      FUN_004024d0(stackList, reinterpret_cast<void*>(obj));
    }
  }
  reinterpret_cast<uint8_t*>(*hash_slot)[0x1d] = 0;
}

void __fastcall FUN_004bbc70(uint32_t* param_1)
{
  *param_1 = (uint32_t)(uintptr_t)&PTR_FUN_009cb448;

  // Stack ThreadSafeObjectList (layout twin of aa_0040b020 / aa_004bcbf0)
  alignas(8) uint8_t stackListRaw[0x40];
  uint32_t* stackList = reinterpret_cast<uint32_t*>(stackListRaw);
  stackList[0] = (uint32_t)(uintptr_t)&PTR_FUN_009cb368;
  stackList[1] = 0;
  stackList[2] = 0;
  stackList[3] = 0;
  InitializeCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(stackList + 4));   // +0x10
  InitializeCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(stackList + 10));  // +0x28

  traverse_hash(&param_1[1], stackList);
  traverse_hash(&param_1[2], stackList);

  void* payload = FUN_0040b020(stackList);
  while (payload != nullptr) {
    uint8_t* p = reinterpret_cast<uint8_t*>(payload);
    FUN_004bb970(
        param_1,
        p[0x168],
        *reinterpret_cast<uint32_t*>(p + 0x160),
        *reinterpret_cast<uint32_t*>(p + 0x164));
    payload = FUN_0040b020(stackList);
  }

  vdel(&param_1[6]);
  vdel(&param_1[7]);
  vdel(&param_1[8]);
  vdel(&param_1[9]);
  vdel(&param_1[1]);
  vdel(&param_1[2]);

  FUN_004bcbf0(stackList);

  free3(&param_1[0x13]);
  free3(&param_1[0x0f]);
  free3(&param_1[0x0b]);
}
