// =============================================================================
// Client_AssignPendingGhostByObjectTfid_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00807550
// Address:   0x00807550–0x008075cb exclusive (123 B; autoassault.exe base 0x400000)
// System:    client net / pending ghost map (TFID)
// Generated: 2026-08-04 WQ9H-G OWN dual A/B seal
// Exactness: Behavior-preserving rewrite of live decompile + sealed disasm.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// Supersedes: FUN_00807550.cpp scaffold.
// Dual: reviews/A|B_aa_00807550_Client_AssignPendingGhostByObjectTfid_Inferred.md
// Calls: StdMap_Find_Tfid_Isnil29_Inferred (aa_004cba00, dualed WQ9G-G)
//        Map_EraseNode_B (aa_00409220, dualed WQ9E-G)
// =============================================================================
//
// PURPOSE:
//   Resolve a pending-ghost map entry by the object's TFID (object+0x160), and
//   if present with payload+0x5c == 0: log assignment, invoke object vtbl+0x2b8
//   with the payload, then erase the map node.
//
// ABI: EAX = client/host (register); stack Object* object; RET 4.
// =============================================================================

#include <cstdint>

struct MapShell {
  // head lives at +0x4 relative to map base (manager+0x244)
  void* _pad0;
  void* head; // +0x4
};

struct MapNode {
  // key at +0x10/+0x14 (TFID); value/payload pointer at +0x20
  char _pad[0x20];
  void* payload; // +0x20
};

extern "C" void __fastcall StdMap_Find_Tfid_Isnil29_Inferred(
    MapShell* map /*ECX*/, MapNode** outIt, const void* pKey);
extern "C" void __thiscall Map_EraseNode_B(
    MapShell* map /*ECX*/, MapNode** outIt, MapNode* node);
extern "C" void FUN_007a4480(int level, const char* fmt, ...);

// EAX = host on entry; object on stack; ret 4.
extern "C" void Client_AssignPendingGhostByObjectTfid_Inferred(
    void* object /* stack */)
{
  void* host = /*EAX*/ nullptr; // sealed: host in EAX at entry

  void* mgrIface =
      *reinterpret_cast<void**>(reinterpret_cast<char*>(host) + 0xc78);
  int* mgrVtbl = *reinterpret_cast<int**>(mgrIface);
  auto getManager =
      reinterpret_cast<void*(__thiscall*)(void*)>(mgrVtbl[0x48 / 4]);
  void* manager = getManager(mgrIface);
  if (manager == nullptr) {
    return;
  }

  MapShell* map =
      reinterpret_cast<MapShell*>(reinterpret_cast<char*>(manager) + 0x244);
  const void* keyTfid = reinterpret_cast<char*>(object) + 0x160;

  MapNode* it = nullptr;
  StdMap_Find_Tfid_Isnil29_Inferred(map, &it, keyTfid);

  // end / miss
  if (it == reinterpret_cast<MapNode*>(map->head)) {
    return;
  }

  void* payload = it->payload; // node+0x20
  if (*reinterpret_cast<int*>(reinterpret_cast<char*>(payload) + 0x5c) != 0) {
    return; // already assigned
  }

  uint32_t tfidLo =
      *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(object) + 0x160);
  uint32_t tfidHi =
      *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(object) + 0x164);
  FUN_007a4480(-1, "Assigned a pending ghost to %I64d", tfidLo, tfidHi);

  int* objVtbl = *reinterpret_cast<int**>(object);
  auto assignGhost =
      reinterpret_cast<void(__thiscall*)(void*, void*)>(objVtbl[0x2b8 / 4]);
  assignGhost(object, payload);

  MapNode* scratch = it;
  Map_EraseNode_B(map, &scratch, it);
}
