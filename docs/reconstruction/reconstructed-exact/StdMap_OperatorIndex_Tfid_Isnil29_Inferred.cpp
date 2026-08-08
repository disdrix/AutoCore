// =============================================================================
// StdMap_OperatorIndex_Tfid_Isnil29_Inferred  (Ghidra FUN_004cc400)
// -----------------------------------------------------------------------------
// Stable ID: aa_004cc400
// Address:   0x004cc400  (autoassault.exe, image base 0x400000)
// Body:      0x004cc400–0x004cc469 exclusive (105 B / 0x69)
// System:    MSVC std::map operator[] — TFID pair key, isnil@+0x29
// Agent:     WQ9G-C OWN-ONLY dual 2026-08-04
// Exactness: Behavior-preserving; meaningful names. Not modernization.
// Terminal:  false (no runtime Confirmed)
// =============================================================================

// PURPOSE:
// Get-or-insert mapped for unique TFID-shaped pair-key maps.
// lower_bound (dualed) + equality gate → hit returns node+0x20;
// miss stages {key16, mapped=0} and insert-with-hint (dualed sole caller path).

#include <cstdint>

struct MapNode_Isnil29 {
  MapNode_Isnil29 *left;    // +0x00
  MapNode_Isnil29 *parent;  // +0x04
  MapNode_Isnil29 *right;   // +0x08
  // +0x0C
  uint32_t key_lo;          // +0x10  unsigned secondary
  int32_t  key_hi;          // +0x14  signed primary
  uint32_t key_ext0;        // +0x18  remaining TFID storage
  uint32_t key_ext1;        // +0x1C
  int32_t  mapped;          // +0x20  (aggro score on object map)
  uint8_t  color;           // +0x28
  uint8_t  isnil;           // +0x29
};

struct MapShell_Isnil29 {
  // +0x00
  MapNode_Isnil29 *head;    // +0x04
  uint32_t size;            // +0x08
};

struct Val_TfidPair_Isnil29 {
  uint32_t key_lo;          // +0x00 → node+0x10
  int32_t  key_hi;          // +0x04 → node+0x14
  uint32_t key_ext0;        // +0x08 → node+0x18
  uint32_t key_ext1;        // +0x0C → node+0x1C
  int32_t  mapped;          // +0x10 → node+0x20  (0 on insert)
  // buynode copies Val24 (6 dwords) into node+0x10
};

// Dualed W31-N
extern "C" MapNode_Isnil29 *__thiscall
StdMap_LowerBound_Tfid_Isnil29(MapShell_Isnil29 *map, const uint32_t *key16);

// Dualed WQ9F-E — sole caller is this function
extern "C" MapNode_Isnil29 **__thiscall
StdTree_InsertHint_Isnil29_Inferred(
    MapShell_Isnil29 *map,
    MapNode_Isnil29 **outIt,
    MapNode_Isnil29 *hint,
    const Val_TfidPair_Isnil29 *value);

// key < node ? (hi signed primary, lo unsigned secondary)
static inline bool TfidKeyLess(const uint32_t *key, const MapNode_Isnil29 *node)
{
  const int32_t key_hi = (int32_t)key[1];
  if (key_hi < node->key_hi) return true;
  if (key_hi > node->key_hi) return false;
  return key[0] < node->key_lo;
}

int32_t *__thiscall StdMap_OperatorIndex_Tfid_Isnil29_Inferred(
    MapShell_Isnil29 *map,     // ECX
    const uint32_t *key16)     // stack +4  (4 dwords)
// RET 4
{
  MapNode_Isnil29 *it = StdMap_LowerBound_Tfid_Isnil29(map, key16);

  if (it == map->head || TfidKeyLess(key16, it)) {
    Val_TfidPair_Isnil29 staged;
    staged.key_lo   = key16[0];
    staged.key_hi   = (int32_t)key16[1];
    staged.key_ext0 = key16[2];
    staged.key_ext1 = key16[3];
    staged.mapped   = 0;

    MapNode_Isnil29 *outStorage = nullptr; // decomp reuses stack slot
    MapNode_Isnil29 **pair =
        StdTree_InsertHint_Isnil29_Inferred(map, &outStorage, it, &staged);
    it = *pair;
  }

  return &it->mapped; // node + 0x20
}
