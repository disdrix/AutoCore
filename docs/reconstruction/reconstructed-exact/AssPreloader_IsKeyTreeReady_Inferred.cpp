// =============================================================================
// AssPreloader_IsKeyTreeReady_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00971a20
// Address:   0x00971a20–0x00971b74  (341 B / 0x155; autoassault.exe base 0x400000)
// Ghidra:    FUN_00971a20
// System:    AssPreloader / preload key tree readiness
// Dual:      W36-E 2026-07-29
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Return whether a preload key is known in AssPreloader's tree (map@+0x10).
//   When recurse!=0 and cache@+0x110 has field+0x64 set, also require every
//   dependency (FUN_00744360 fill) to be tree-known (shallow) OR cache-present.
//   Entry always runs FUN_00971480 drain (assPreloader.cpp side-effect).
//
// ABI:
//   thiscall ECX = AssPreloader*; stack (key*, char recurse); RET 8; AL 0/1.
//
// REJECT: scaffold Named_CalleeOf_Named_assManager_* product aliases.
//

#include <cstdint>

struct GuardedVectorHeader {
  uint32_t  _unk00;
  uint32_t** pages;   // +0x04
  uint32_t  capacity; // +0x08
  int32_t   begin;    // +0x0c
  int32_t   size;     // +0x10
};

struct NestedHashMapHead {
  uint32_t _pad00[2];
  void*    end; // +0x08
};

struct HashMapNode {
  void*    next;
  uint32_t _pad04;
  uint32_t key;
  void*    value; // +0x0C
};

// Nested (unowned here)
extern "C" void   AssPreloader_DrainPending_Inferred(void* self /*ECX?*/); // FUN_00971480
// ECX=map(this+0x10), EBX=key*, EAX=out_it* — lower_bound exact write
extern "C" void   Map_LowerBoundExact_WriteOut_Inferred(void);             // FUN_0043d5e0
extern "C" void   FillPreloadDeps_Inferred(const void* key, GuardedVectorHeader* out); // FUN_00744360
extern "C" void** __stdcall HashMap_FindIterator_Inferred(void** out_it); // FUN_0044e8c0
extern "C" void   __fastcall GuardedVector_Dtor_Inferred(GuardedVectorHeader* v /*ECX*/); // FUN_005b2ba0

struct AssPreloader {
  uint8_t  _pad00[0x10];
  // +0x10 map header; +0x14 = end sentinel (map+4)
  uint8_t  map_region[0x100]; // through +0x10F
  NestedHashMapHead* cache;   // +0x110  NDResourceCache* (NestedHash head)
  // ... remainder open
};

static const void* ResolveSlot(GuardedVectorHeader* c, uint32_t abs_idx)
{
  uint32_t page = abs_idx >> 2;
  const uint32_t sub = abs_idx + page * static_cast<uint32_t>(-4);
  if (c->capacity <= page) {
    page -= c->capacity;
  }
  return reinterpret_cast<const void*>(&c->pages[page][sub]);
}

// Forward for self-recursion
extern "C" uint8_t __fastcall AssPreloader_IsKeyTreeReady_Inferred(
    AssPreloader* self /*ECX*/,
    const void* key,
    char recurse);

extern "C" uint8_t __fastcall AssPreloader_IsKeyTreeReady_Inferred(
    AssPreloader* self /*ECX*/,
    const void* key,
    char recurse)
{
  // SEH LAB_009b09e1 omitted in clean (present in retail body)

  AssPreloader_DrainPending_Inferred(self); // FUN_00971480(this)

  // Tree find @ this+0x10; overwrites local with node* (machine: EBX=key*, EAX=&out)
  void* node = const_cast<void*>(key);
  // ECX = self+0x10, EBX = key*, EAX = &node
  Map_LowerBoundExact_WriteOut_Inferred();

  void* end = *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(self) + 0x14);
  if (node == end) {
    return 0;
  }

  NestedHashMapHead* cache =
      *reinterpret_cast<NestedHashMapHead**>(reinterpret_cast<uint8_t*>(self) + 0x110);

  if (recurse != 0 && cache != nullptr &&
      *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(cache) + 0x64) != 0) {
    GuardedVectorHeader deps{};
    // zero begin/size/pages/capacity as sealed; FUN_00744360 fills
    FillPreloadDeps_Inferred(key, &deps);

    const uint32_t abs_begin = static_cast<uint32_t>(deps.begin);
    const uint32_t abs_end =
        static_cast<uint32_t>(deps.begin) + static_cast<uint32_t>(deps.size);

    for (uint32_t abs = abs_begin; abs != abs_end; ++abs) {
      const void* dep = ResolveSlot(&deps, abs);

      const uint8_t dep_tree =
          AssPreloader_IsKeyTreeReady_Inferred(self, dep, /*recurse=*/0);

      if (dep_tree == 0) {
        // Inlined NDResourceCache present-check on cache@+0x110
        void* it = const_cast<void*>(dep);
        // EDI=cache, EBX=dep* for FindIterator
        HashMap_FindIterator_Inferred(&it);
        if (it == cache->end ||
            static_cast<HashMapNode*>(it)->value == nullptr) {
          GuardedVector_Dtor_Inferred(&deps);
          return 0;
        }
      }
    }

    GuardedVector_Dtor_Inferred(&deps);
  }

  return 1;
}
