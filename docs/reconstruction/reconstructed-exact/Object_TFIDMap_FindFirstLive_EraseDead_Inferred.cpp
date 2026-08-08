// =============================================================================
// Object_TFIDMap_FindFirstLive_EraseDead_Inferred  (FUN_004c8780)
// -----------------------------------------------------------------------------
// Stable ID: aa_004c8780
// Address:   0x004c8780 – 0x004c8963 exclusive (483 B / 0x1E3)
//            Ghidra body end 0x004c8962
// System:    creature/object TFID map scrub + first-live resolve
// Generated: 2026-08-04 WQ9F-C dual seal (raw 2026-07-23 re-verified live)
// Exactness: Behavior-preserving rewrite of decompiler control flow + sealed ABI.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE
//   Walk the host's embedded TFID map (shell @ this+0x154, head @ +0x158).
//   For each node (isnil@+0x29, TFID value @ +0x10):
//     - Resolve TFID → object.
//     - Dead (null): if TFID matches selected target (MI +0x44/+0x48/+0x4c),
//       clear via host vtbl+0x258 with null TFID DAT_009cb8c0..; erase node
//       via StdTree_EraseAndRebalance_Isnil29 (ECX = this+0x154).
//     - Live: if obj->vtbl+0x210(0) != 0 return obj; else if related via
//       vtbl+0x214 + Object_ResolveTfIdVtbl1dc on blob @+0x228 return obj;
//       else successor only.
//   Exhaust → return 0.
//
// ABI
//   __thiscall; ECX = host*; no stack args; bare ret; return object* / 0
//   Frame: sub esp,0x24; epilogue add esp,0x24; ret
//
// CALLERS
//   Ghidra xrefs: 0 this pass (vtable / reachability open). Sibling scrub
//   FUN_004c8610 called from FUN_00638ac0 (AI tick path).
//
// CALLEES
//   Object_ResolveFromTFID
//   StdTree_EraseAndRebalance_Isnil29_Inferred (0x004cb740) — lea ecx,[this+0x154]
//   Object_ResolveTfIdVtbl1dc_Inferred (0x004bb0d0)
//   indirect vtbl+0x210 / +0x214 / host +0x258
// =============================================================================

#include <cstdint>

struct TFID_16 {
  uint32_t dwCoidLo;
  uint32_t dwCoidHi;
  uint8_t  bGlobal;
  // pad
};

struct MapNode_Isnil29 {
  MapNode_Isnil29 *left;    // +0x00
  MapNode_Isnil29 *parent;  // +0x04
  MapNode_Isnil29 *right;   // +0x08
  // +0x0C
  TFID_16 tfid;             // +0x10 (value; exact width product-open)
  // more value dwords ...
  uint8_t color;            // +0x28
  uint8_t isnil;            // +0x29
};

struct MapShell_Isnil29 {
  void *proxy;                 // +0x00
  MapNode_Isnil29 *head;       // +0x04
  uint32_t size;               // +0x08
};

// Null / cleared TFID blob (read_memory: ffff...ffff, 0, 0)
extern uint32_t DAT_009cb8c0, DAT_009cb8c4, DAT_009cb8c8, DAT_009cb8cc;

extern "C" void *Object_ResolveFromTFID(TFID_16 *p);
extern "C" void *__thiscall Object_ResolveTfIdVtbl1dc_Inferred(void *ctx, void *blob);
extern "C" void __thiscall StdTree_EraseAndRebalance_Isnil29_Inferred(
    MapShell_Isnil29 *map, MapNode_Isnil29 **outIt, MapNode_Isnil29 *node);

static MapNode_Isnil29 *tree_successor_isnil29(MapNode_Isnil29 *node)
{
  MapNode_Isnil29 *succ = node;
  if (node->isnil != 0)
    return succ;

  MapNode_Isnil29 *right = node->right;
  if (right->isnil == 0) {
    succ = right;
    MapNode_Isnil29 *left = right->left;
    while (left->isnil == 0) {
      succ = left;
      left = left->left;
    }
    return succ;
  }

  MapNode_Isnil29 *parent = node->parent;
  MapNode_Isnil29 *cur = node;
  while (parent->isnil == 0 && cur == parent->right) {
    cur = parent;
    parent = parent->parent;
  }
  return parent;
}

// Host layout (partial; sealed uses only)
//   +0x04  MI/adjust chain
//   +0x154 MapShell_Isnil29 tfidMap
//   +0x158 head (map+4)

void *__thiscall Object_TFIDMap_FindFirstLive_EraseDead_Inferred(void *self)
{
  MapShell_Isnil29 *map =
      reinterpret_cast<MapShell_Isnil29 *>(
          reinterpret_cast<char *>(self) + 0x154);
  MapNode_Isnil29 *head = map->head;
  MapNode_Isnil29 *it = head->left; // begin == *head in MSVC layout

  if (it == head)
    return nullptr;

  do {
    void *obj = Object_ResolveFromTFID(
        reinterpret_cast<TFID_16 *>(
            reinterpret_cast<char *>(it) + 0x10));
    MapNode_Isnil29 *succ = it;

    if (obj == nullptr) {
      // MI base: *( *(self+4) + 4 ) + self
      int mi_off = *reinterpret_cast<int *>(
          *reinterpret_cast<int *>(reinterpret_cast<char *>(self) + 4) + 4);
      char *mi = reinterpret_cast<char *>(self) + mi_off;

      // decomp also loads *(mi+0x50) into a local (dead for CF; preserve read)
      volatile uint32_t dead = *reinterpret_cast<uint32_t *>(mi + 0x50);
      (void)dead;

      auto *node_tfid = reinterpret_cast<TFID_16 *>(
          reinterpret_cast<char *>(it) + 0x10);
      if (node_tfid->dwCoidLo == *reinterpret_cast<uint32_t *>(mi + 0x44)
          && *reinterpret_cast<int *>(reinterpret_cast<char *>(it) + 0x14)
                 == *reinterpret_cast<int *>(mi + 0x48)
          && *reinterpret_cast<char *>(reinterpret_cast<char *>(it) + 0x18)
                 == static_cast<char>(*reinterpret_cast<uint32_t *>(mi + 0x4c))) {
        // host vtbl+0x258 (decimal 600) with null TFID — clear selection
        void **vtbl = *reinterpret_cast<void ***>(
            *reinterpret_cast<int *>(
                *reinterpret_cast<int *>(reinterpret_cast<char *>(self) + 4) + 4)
            + 4 + reinterpret_cast<int>(self));
        auto clear_sel = reinterpret_cast<void (*)(uint32_t, uint32_t, uint32_t, uint32_t)>(
            vtbl[600 / 4]);
        clear_sel(DAT_009cb8c0, DAT_009cb8c4, DAT_009cb8c8, DAT_009cb8cc);
      }

      succ = tree_successor_isnil29(it);
      MapNode_Isnil29 *tmpIt = nullptr;
      // bytes @ 0x004c893e: lea ecx,[ebp+0x154]; call StdTree_EraseAndRebalance
      StdTree_EraseAndRebalance_Isnil29_Inferred(map, &tmpIt, it);
    } else {
      void **ovtbl = *reinterpret_cast<void ***>(obj);
      auto v210 = reinterpret_cast<void *(*)(void *, int)>(ovtbl[0x210 / 4]);
      if (v210(obj, 0) != nullptr)
        return obj;

      auto v214 = reinterpret_cast<void *(*)(void *)>(ovtbl[0x214 / 4]);
      void *related = v214(obj);
      if (related != nullptr) {
        uint32_t blob[4];
        blob[0] = *reinterpret_cast<uint32_t *>(
            reinterpret_cast<char *>(related) + 0x228);
        blob[1] = *reinterpret_cast<uint32_t *>(
            reinterpret_cast<char *>(related) + 0x22c);
        blob[2] = *reinterpret_cast<uint32_t *>(
            reinterpret_cast<char *>(related) + 0x230);
        blob[3] = *reinterpret_cast<uint32_t *>(
            reinterpret_cast<char *>(related) + 0x234);
        if (Object_ResolveTfIdVtbl1dc_Inferred(self, blob) != nullptr)
          return obj;
      }
      succ = tree_successor_isnil29(it);
    }

    it = succ;
  } while (it != head);

  return nullptr;
}
