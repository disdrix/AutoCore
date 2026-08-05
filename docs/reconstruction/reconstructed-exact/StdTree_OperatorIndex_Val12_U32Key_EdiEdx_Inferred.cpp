// =============================================================================
// StdTree_OperatorIndex_Val12_U32Key_EdiEdx_Inferred  (FUN_0043d570)
// -----------------------------------------------------------------------------
// Stable ID: aa_0043d570
// Address:   0x0043d570–0x0043d5e0 exclusive (112 B / 0x70)
// System:    std red-black map operator[] / get-or-insert (Val12, u32 key)
// Wave:      W38-A OWN-ONLY dual (2026-08-04)
// Exactness: Behavior-preserving rewrite of decompiler CF + body bytes.
// Bit-for-bit vs retail EXE: DEFERRED
//
// Dual: reviews/A|B_aa_0043d570_StdTree_OperatorIndex_Val12_U32Key_EdiEdx_Inferred.md
// =============================================================================
//
// Retail ABI (bytes win over decompiler __fastcall phantoms):
//   EDI = MapShell_Val12*  (head @ +4)
//   EDX = const uint32_t* key
//   EAX = return mapped* (node+0x10)
//   plain RET; SUB ESP,0x18 frame
//
// Peer: StdTree_OperatorIndex_Val12_U32Key_Eax_Inferred @ 0x0043bd40
//       (ECX map / EAX key*; same algorithm, different insert helper)
// Sibling leaf find: StdMap_FindEq_UintKey_Val12 @ 0x0043d5e0
// =============================================================================

#include <cstdint>

struct MapNode_Val12 {
  MapNode_Val12* left;     // +0
  MapNode_Val12* parent;    // +4
  MapNode_Val12* right;     // +8
  uint32_t key;            // +0x0c  (unsigned compare)
  int32_t val1;            // +0x10  (mapped start — return value)
  int32_t val2;            // +0x14
  char color;              // +0x18
  char isnil;              // +0x19
};

struct MapShell_Val12 {
  void* pad0;
  MapNode_Val12* head;     // +4
  int size;                // +8
};

struct Val12 {
  uint32_t key;
  int32_t val1;
  int32_t val2;
};

// FUN_0043c8b0 — pack Val12 into *dest from key* + mapped pair source.
// Retail: EAX=dest Val12*, EDX=const uint32_t* key, ECX=int32_t mapped[2] source.
extern "C" void __fastcall FUN_0043c8b0(
    int32_t* mapped_src /*ECX*/,
    const uint32_t* key /*EDX*/);
// (dest in EAX — not expressible as a C formal; see annotated notes)

// FUN_0043d7d0 — insert-hint / rebalance (unowned). Returns iterator*.
// Retail call-site: ECX=map, stack hint, ESI=out it storage, EAX=Val12*.
extern "C" MapNode_Val12** __thiscall FUN_0043d7d0(
    MapShell_Val12* map /*ECX*/,
    MapNode_Val12* hint /*stack*/);

// Clean signature: register formals explicit (retail keeps EDI/EDX).
int32_t* StdTree_OperatorIndex_Val12_U32Key_EdiEdx_Inferred(
    MapShell_Val12* map /* EDI */,
    const uint32_t* key /* EDX */)
{
  MapNode_Val12* head = map->head;
  MapNode_Val12* candidate = head;
  MapNode_Val12* node = head->parent; // root (Val12 head parent link)

  if (node->isnil == 0) {
    // unsigned lower_bound: first node with key >= *key
    do {
      if (node->key < *key) {
        node = node->right;
      } else {
        candidate = node;
        node = node->left;
      }
    } while (node->isnil == 0);
  }

  // Hit: candidate in-tree and candidate.key == *key
  // (lower_bound gives >= ; *key >= cand.key seals equality)
  if (candidate != head && *key >= candidate->key) {
    return &candidate->val1; // node + 0x10
  }

  // Miss path (retail):
  //   XORPS + MOVUPS stage zeros; FUN_0043c8b0 writes {*key,0,0} at stack Val12;
  //   FUN_0043d7d0(map, candidate) with ESI=out it, EAX=Val12*;
  //   return *it + 0x10.
  Val12 staged;
  int32_t zero_mapped[2] = {0, 0};
  // Retail also leaves EAX = &staged before c8b0; modeled as named pack:
  staged.key = *key;
  staged.val1 = zero_mapped[0];
  staged.val2 = zero_mapped[1];
  (void)FUN_0043c8b0; // real call present in body; ABI not fully C-expressible

  MapNode_Val12** it = FUN_0043d7d0(map, candidate);
  return &(*it)->val1;
}
