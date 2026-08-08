// =============================================================================
// StdMap_Find_Tfid_Isnil29_Inferred  (aa_004cba00)
// -----------------------------------------------------------------------------
// Address:   0x004cba00–0x004cba51  (82 B; autoassault.exe base 0x400000)
// Wave:      WQ9G-G OWN-ONLY dual 2026-08-04
// Exactness: Behavior-preserving from decompile + full-body read_memory.
// Bit-for-bit / runtime / diff: OPEN
// =============================================================================
// PURPOSE
//   MSVC-style map::find for TFID-shaped (u32 lo, i32 hi) keys on isnil@+0x29
//   maps: lower_bound + equality gate; write node* or head(end) to *outIt.
//
// ABI
//   ECX = map host (head @ +4)
//   stack: Node** outIt, const KeyU32I32* pKey
//   RET 8; *outIt written; EAX left as outIt after store
//
// Callee
//   StdMap_LowerBound_Tfid_Isnil29 (0x004cb4b0) — dualed W31-N
//
// Rejected aliases
//   Named_CalleeOf_Named_VOG_DEBUG_STOP_004cba00 (scaffold)
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
  // +0x0C ..
  uint32_t key_lo;       // +0x10
  int32_t  key_hi;       // +0x14
  // payload often @ +0x20 (callers)
  // isnil @ +0x29
};

struct MapHost_Head4 {
  uint32_t _pad0;
  Node_Isnil29* head; // +0x04
};

extern "C" Node_Isnil29* __fastcall StdMap_LowerBound_Tfid_Isnil29(
    MapHost_Head4* self, const KeyU32I32* pKey);

// ECX = map; stack outIt, pKey; RET 8
extern "C" void __fastcall StdMap_Find_Tfid_Isnil29_Inferred(
    MapHost_Head4* self, Node_Isnil29** outIt, const KeyU32I32* pKey)
{
  Node_Isnil29* lb = StdMap_LowerBound_Tfid_Isnil29(self, pKey);
  Node_Isnil29* head = self->head;

  if (lb != head) {
    const int32_t node_hi =
        *reinterpret_cast<int32_t*>(reinterpret_cast<char*>(lb) + 0x14);
    const uint32_t node_lo =
        *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(lb) + 0x10);
    // node.key <= *pKey  (with lower_bound ⇒ equality)
    if (node_hi <= pKey->hi && (node_hi < pKey->hi || node_lo <= pKey->lo)) {
      *outIt = lb;
      return;
    }
  }
  *outIt = head;
}

// Scaffold alias
extern "C" void __fastcall FUN_004cba00(
    MapHost_Head4* self, Node_Isnil29** outIt, const KeyU32I32* pKey)
{
  StdMap_Find_Tfid_Isnil29_Inferred(self, outIt, pKey);
}
