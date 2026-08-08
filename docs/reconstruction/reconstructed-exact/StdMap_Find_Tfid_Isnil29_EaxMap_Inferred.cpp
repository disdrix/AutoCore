// =============================================================================
// StdMap_Find_Tfid_Isnil29_EaxMap_Inferred  (aa_00402ae0)
// -----------------------------------------------------------------------------
// Address:   0x00402ae0–0x00402b2f  (80 B / 0x50; autoassault.exe base 0x400000)
// Wave:      MEGA-083 OWN-ONLY dual 2026-08-05
// System:    interaction-activation (client map @ +0xd24 neighborhood)
// Exactness: Behavior-preserving from decompile + full-body read_memory +
//            disassemble_function. Not modernization.
// Bit-for-bit / runtime / diff: OPEN (Terminal false; no Launcher)
// =============================================================================
// PURPOSE
//   MSVC-style map::find for TFID-shaped (u32 lo, i32 hi) keys on isnil@+0x29
//   maps: lower_bound (FUN_00403e50) + equality gate; write node* or head(end)
//   to *outIt.
//
// ABI (custom — NOT thiscall twin 004cba00)
//   EAX = map host (head @ +4)
//   EDI = const KeyU32I32* pKey
//   stack: Node** outIt
//   RET 4; *outIt written; EAX left as outIt after store
//
// Callee
//   FUN_00403e50 — residual lower_bound isnil29 / TFID pair key (not dualled MEGA-083)
//
// Rejected aliases
//   Named_CalleeOf_Client_SendRespawnInSector_00402ae0 (scaffold; retired)
//   Product "SendRespawn helper" (parent only; this is shared map find)
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
  // isnil @ +0x29 (inside lower_bound only)
};

struct MapHost_Head4 {
  uint32_t _pad0;
  Node_Isnil29* head; // +0x04
};

// Residual lower_bound: EAX=map, EDX=key (EDI copied to EDX at call site).
// Returns candidate node* (may be head/end). Equality is caller's job here.
extern "C" Node_Isnil29* __fastcall FUN_00403e50(
    /*EAX*/ MapHost_Head4* /*map via in_EAX in decompiler*/,
    /*EDX*/ const KeyU32I32* pKey);

// EAX = map; EDI = pKey; stack outIt; RET 4
// Emulated as free function with explicit formals (register ABI documented).
extern "C" Node_Isnil29** StdMap_Find_Tfid_Isnil29_EaxMap_Inferred(
    MapHost_Head4* map /*EAX*/,
    const KeyU32I32* pKey /*EDI*/,
    Node_Isnil29** outIt /*stack*/)
{
  // Bytes: MOV EDX,EDI; MOV ESI,EAX; CALL FUN_00403e50
  Node_Isnil29* lb = FUN_00403e50(map, pKey);
  Node_Isnil29* head = map->head;

  if (lb != head) {
    const int32_t node_hi =
        *reinterpret_cast<int32_t*>(reinterpret_cast<char*>(lb) + 0x14);
    const uint32_t node_lo =
        *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(lb) + 0x10);
    // node.key <= *pKey  (with lower_bound ⇒ equality)
    // Bytes: CMP key.hi, node.hi → JL miss / JG hit;
    //        CMP key.lo, node.lo → JC miss
    if (node_hi <= pKey->hi && (node_hi < pKey->hi || node_lo <= pKey->lo)) {
      *outIt = lb;
      return outIt;
    }
  }
  *outIt = head;
  return outIt;
}

// Scaffold alias (Ghidra symbol)
extern "C" Node_Isnil29** FUN_00402ae0(
    MapHost_Head4* map,
    const KeyU32I32* pKey,
    Node_Isnil29** outIt)
{
  return StdMap_Find_Tfid_Isnil29_EaxMap_Inferred(map, pKey, outIt);
}
