// =============================================================================
// FUN_00402ae0  — scaffold twin of StdMap_Find_Tfid_Isnil29_EaxMap_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00402ae0
// Address:   0x00402ae0–0x00402b2f  (80 B; autoassault.exe base 0x400000)
// Wave:      MEGA-083 OWN-ONLY dual 2026-08-05
// Canonical: StdMap_Find_Tfid_Isnil29_EaxMap_Inferred.cpp
// Exactness: Behavior-preserving rewrite of decompiler control flow + bytes ABI.
// Bit-for-bit / runtime / diff: OPEN
// =============================================================================

#include <cstdint>

struct KeyU32I32 {
  uint32_t lo;
  int32_t  hi;
};

struct Node_Isnil29 {
  Node_Isnil29* left;
  Node_Isnil29* parent;
  Node_Isnil29* right;
  uint32_t key_lo; // +0x10
  int32_t  key_hi; // +0x14
};

struct MapHost_Head4 {
  uint32_t _pad0;
  Node_Isnil29* head;
};

extern "C" Node_Isnil29* __fastcall FUN_00403e50(
    MapHost_Head4* map, const KeyU32I32* pKey);

// Prefer named unit: StdMap_Find_Tfid_Isnil29_EaxMap_Inferred
// ABI: EAX=map, EDI=pKey, stack outIt, RET 4
extern "C" Node_Isnil29** FUN_00402ae0(
    MapHost_Head4* map /*EAX*/,
    const KeyU32I32* pKey /*EDI*/,
    Node_Isnil29** outIt /*stack*/)
{
  Node_Isnil29* lb = FUN_00403e50(map, pKey);
  Node_Isnil29* head = map->head;

  if (lb != head) {
    const int32_t node_hi =
        *reinterpret_cast<int32_t*>(reinterpret_cast<char*>(lb) + 0x14);
    const uint32_t node_lo =
        *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(lb) + 0x10);
    if (node_hi <= pKey->hi && (node_hi < pKey->hi || node_lo <= pKey->lo)) {
      *outIt = lb;
      return outIt;
    }
  }
  *outIt = head;
  return outIt;
}
