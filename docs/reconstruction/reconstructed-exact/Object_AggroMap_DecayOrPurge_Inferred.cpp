// =============================================================================
// Object_AggroMap_DecayOrPurge_Inferred  (FUN_004c8610)
// -----------------------------------------------------------------------------
// Stable ID: aa_004c8610
// Address:   0x004c8610–0x004c8779 exclusive (361 B / 0x169)
// System:    Object-hosted isnil29 aggro/threat map @ +0x154
// Generated: 2026-08-04 WQ9F-B dual seal
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Inorder-walk map at this+0x154 (head pointer at this+0x158). Multiply each
//   entry's int score @ node+0x20 by 0.85f (DAT_00aaa680).
//   - forcePurge==0 and score changed → keep entry; advance successor.
//   - forcePurge!=0 OR score unchanged (0 fixed-point) → optional clear-target
//     if TFID key matches host primary, then erase via dualed
//     StdTree_EraseAndRebalance_Isnil29_Inferred.
//
// ABI: __thiscall; ECX=object*; stack char forcePurge; void; RET 4.
// Peer (not OWN): FUN_004c8780 same map + Object_ResolveFromTFID on node+0x10.
// Caller: FUN_00638ac0 AI timer with forcePurge=0.
//
// Dual: reviews/A|B_aa_004c8610_Object_AggroMap_DecayOrPurge_Inferred.md

#include <cstdint>

struct NodeIsnil29 {
  NodeIsnil29* left;       // +0x00
  NodeIsnil29* parent;     // +0x04
  NodeIsnil29* right;      // +0x08
  std::uint32_t _unused0c; // +0x0c
  std::uint32_t tfid0;     // +0x10  (peer: TFID_16*)
  std::uint32_t tfid1;     // +0x14
  std::uint32_t tfid2;     // +0x18  (byte-compared)
  std::uint32_t _unused1c; // +0x1c
  std::int32_t  score;     // +0x20
  std::uint32_t _unused24; // +0x24
  std::uint8_t  color;     // +0x28
  std::uint8_t  isnil;     // +0x29
};

struct MapShellIsnil29 {
  void* proxy;             // object+0x154
  NodeIsnil29* head;       // object+0x158
  std::uint32_t size;      // object+0x15c
};

// Dualed WQ9E-E — Ghidra FUN_004cb740
extern "C" void __thiscall StdTree_EraseAndRebalance_Isnil29_Inferred(
    MapShellIsnil29* map,
    NodeIsnil29** outIt,
    NodeIsnil29* node);

// 0.85f @ 0x00aaa680 (bytes 9A 99 59 3F)
extern "C" float DAT_00aaa680;
// Clear-target TFID payload @ 0x009cb8c0 (FF FF FF FF / FF FF FF FF / 0 / 0)
extern "C" std::uint32_t DAT_009cb8c0;
extern "C" std::uint32_t DAT_009cb8c4;
extern "C" std::uint32_t DAT_009cb8c8;
extern "C" std::uint32_t DAT_009cb8cc;

// Inlined isnil@+0x29 inorder successor (both keep and purge paths).
static NodeIsnil29* Tree_InorderSuccessor_Isnil29(NodeIsnil29* node)
{
  if (node->isnil != 0) {
    return node;
  }
  NodeIsnil29* r = node->right;
  if (r->isnil == 0) {
    NodeIsnil29* x = r;
    while (x->left->isnil == 0) {
      x = x->left;
    }
    return x;
  }
  NodeIsnil29* y = node->parent;
  NodeIsnil29* x = node;
  while (y->isnil == 0 && x == y->right) {
    x = y;
    y = y->parent;
  }
  return y;
}

// __thiscall; RET 4
extern "C" void __thiscall Object_AggroMap_DecayOrPurge_Inferred(
    void* selfObj,
    char forcePurge)
{
  auto* self = reinterpret_cast<std::uint8_t*>(selfObj);
  NodeIsnil29* head = *reinterpret_cast<NodeIsnil29**>(self + 0x158);
  NodeIsnil29* cur = *reinterpret_cast<NodeIsnil29**>(head); // begin
  if (cur == head) {
    return;
  }

  do {
    std::int32_t oldScore = cur->score;
    std::int32_t newScore =
        static_cast<std::int32_t>(static_cast<float>(oldScore) * DAT_00aaa680);
    cur->score = newScore;

    NodeIsnil29* next = cur;
    if (forcePurge == 0 && newScore != oldScore) {
      // Keep: decay applied; advance only.
      next = Tree_InorderSuccessor_Isnil29(cur);
    } else {
      // Purge path: optional clear-selected-target if entry is host identity.
      auto* field4 = *reinterpret_cast<std::uint8_t**>(self + 4);
      std::int32_t adj = *reinterpret_cast<std::int32_t*>(field4 + 4);
      auto* primary = self + adj; // MI-adjusted host
      // Compare node TFID @+0x10 to primary+0x44/+0x48/+0x4c (byte on third).
      if (cur->tfid0 == *reinterpret_cast<std::uint32_t*>(primary + 0x44) &&
          cur->tfid1 == *reinterpret_cast<std::uint32_t*>(primary + 0x48) &&
          static_cast<std::uint8_t>(cur->tfid2) ==
              *reinterpret_cast<std::uint8_t*>(primary + 0x4c)) {
        // this = primary+4; vtbl slot +0x258; stack-copy DAT_009cb8c0..cc
        void** vtbl = *reinterpret_cast<void***>(primary + 4);
        using ClearTargetFn = void(__thiscall*)(
            void* thisPrimaryPlus4,
            std::uint32_t a, std::uint32_t b, std::uint32_t c, std::uint32_t d);
        auto* fn = reinterpret_cast<ClearTargetFn>(vtbl[0x258 / 4]);
        fn(primary + 4, DAT_009cb8c0, DAT_009cb8c4, DAT_009cb8c8, DAT_009cb8cc);
      }

      next = Tree_InorderSuccessor_Isnil29(cur);
      NodeIsnil29* outIt = nullptr;
      auto* map = reinterpret_cast<MapShellIsnil29*>(self + 0x154);
      StdTree_EraseAndRebalance_Isnil29_Inferred(map, &outIt, cur);
      (void)outIt;
    }
    cur = next;
  } while (cur != head);
}

// Scaffold alias
extern "C" void __thiscall FUN_004c8610(void* selfObj, char forcePurge)
{
  Object_AggroMap_DecayOrPurge_Inferred(selfObj, forcePurge);
}
