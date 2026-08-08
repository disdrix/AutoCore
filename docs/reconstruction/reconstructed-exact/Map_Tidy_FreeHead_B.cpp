// =============================================================================
// Map_Tidy_FreeHead_B
// -----------------------------------------------------------------------------
// Stable ID: aa_0051e180
// Address:   0x0051e180–0x0051e1ad inclusive (46 B / 0x2E; exclusive end 0x0051e1ae)
//            autoassault.exe, image base 0x400000
// Wave:      2026-08-04 WQ9F-H OWN dual A/B seal
// Exactness: Behavior-preserving rewrite from live decompile + full-body
//            read_memory. Post-delete epilogue from bytes (decompiler false
//            noreturn truncates after operator_delete).
// Bit-for-bit vs retail EXE: DEFERRED.
// ABI:       ECX=map*; bare RET (C3); void. No SEH frame.
// Peer:      Map_Tidy_FreeHead @ 0x0051da30 (same 46 B template; different erase)
// Erase:     Map_EraseRange_B @ 0x0051d880 (dualed WQ9D; isnil@+0x29)
// =============================================================================

#include <cstdint>

struct MapNode_Isnil29 {
  MapNode_Isnil29* left;   // +0x00  (*head = begin)
  MapNode_Isnil29* parent; // +0x04
  MapNode_Isnil29* right;  // +0x08
  // isnil @ +0x29
};

// Map facade used by Map_EraseRange_B family:
//   +0x04 head (_Myhead sentinel)
//   +0x08 size (_Mysize)
struct MapFacade {
  void* _unused0;        // +0x00
  MapNode_Isnil29* head; // +0x04
  std::uint32_t size;    // +0x08
};

// Full-range erase twin B; when (first==*head && last==head) frees root via
// Map_FreeSubtree_B and resets sentinel/size.
// ECX=map; stack out*, first*, last*; RET 0x0C.
extern "C" void __thiscall Map_EraseRange_B(MapFacade* map,
                                            void* out_iter,
                                            MapNode_Isnil29* first,
                                            MapNode_Isnil29* last); // 0x0051d880
extern "C" void __cdecl operator_delete(void* p);

// ECX = map*. Bare RET. void.
// MSVC-style map tidy: erase full content via EraseRange_B, free header
// sentinel, null head+size. Does not free the map facade object.
extern "C" void __fastcall Map_Tidy_FreeHead_B(MapFacade* map)
{
  void* out; // stack slot only (entry push ECX)
  MapNode_Isnil29* head = map->head;
  // full range: begin = *head (left), end = head
  Map_EraseRange_B(map, &out, head->left, head);
  operator_delete(head);
  map->head = nullptr;
  map->size = 0;
}

// Scaffold twin entry (Ghidra name).
extern "C" void __fastcall FUN_0051e180(MapFacade* map)
{
  Map_Tidy_FreeHead_B(map);
}
