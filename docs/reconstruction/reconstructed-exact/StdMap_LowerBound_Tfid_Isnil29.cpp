// =============================================================================
// StdMap_LowerBound_Tfid_Isnil29  (aa_004cb4b0)
// -----------------------------------------------------------------------------
// Address:   0x004cb4b0  (autoassault.exe, image base 0x400000)
// Wave:      W31-N OWN-ONLY dual 2026-07-29
// Exactness: Behavior-preserving rewrite from decompile + full-body read_memory.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

struct KeyU32I32 {
  uint32_t lo; // [0]
  int32_t  hi; // [1] — compared signed
};

struct Node_Isnil29 {
  Node_Isnil29* left;    // +0x00
  Node_Isnil29* parent;  // +0x04
  Node_Isnil29* right;   // +0x08
  // +0x0C .. color / padding
  uint32_t key_lo;       // +0x10  [4]
  int32_t  key_hi;       // +0x14  [5]
  // ... payload (consumers read +0x20) ...
  // isnil at +0x29
};

struct MapHost_Head4 {
  uint32_t _pad0;
  Node_Isnil29* head; // +0x04  _Myhead
};

// ECX = map host (head @ +4). Stack pKey. RET 4. Returns lower_bound node*
// (may be head/end). Equality gating is the caller's job.
extern "C" Node_Isnil29* __fastcall StdMap_LowerBound_Tfid_Isnil29(
    MapHost_Head4* self, const KeyU32I32* pKey)
{
  Node_Isnil29* head = self->head;
  Node_Isnil29* cand = head;
  Node_Isnil29* node = head->parent; // root

  if (*reinterpret_cast<uint8_t*>(reinterpret_cast<char*>(node) + 0x29) != 0)
    return head;

  do {
    const int32_t node_hi = *reinterpret_cast<int32_t*>(reinterpret_cast<char*>(node) + 0x14);
    const uint32_t node_lo = *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(node) + 0x10);

    if (pKey->hi < node_hi || (pKey->hi <= node_hi && pKey->lo <= node_lo)) {
      cand = node;
      node = node->left;
    } else {
      node = node->right;
    }
  } while (*reinterpret_cast<uint8_t*>(reinterpret_cast<char*>(node) + 0x29) == 0);

  return cand;
}

// Scaffold alias
extern "C" Node_Isnil29* __fastcall FUN_004cb4b0(
    MapHost_Head4* self, const KeyU32I32* pKey)
{
  return StdMap_LowerBound_Tfid_Isnil29(self, pKey);
}
