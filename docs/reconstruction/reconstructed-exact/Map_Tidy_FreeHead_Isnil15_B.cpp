// =============================================================================
// Map_Tidy_FreeHead_Isnil15_B
// -----------------------------------------------------------------------------
// Stable ID: aa_0051e1b0
// Address:   0x0051e1b0–0x0051e1dd inclusive (46 B / 0x2E; exclusive end 0x0051e1de)
//            autoassault.exe, image base 0x400000
// Wave:      2026-08-04 WQ9G-D OWN dual A/B seal
// Exactness: Behavior-preserving rewrite from live decompile + full-body
//            read_memory. Post-delete epilogue from bytes (decompiler false
//            noreturn truncates after operator_delete).
// Bit-for-bit vs retail EXE: DEFERRED.
// ABI:       ECX=map*; bare RET (C3); void. No SEH frame.
// Peer:      Map_Tidy_FreeHead @ 0x0051da30 (same 46 B template; different erase)
//            Map_Tidy_FreeHead_B @ 0x0051e180
//            Map_Tidy_FreeHead_Isnil1d_Inferred @ 0x0051e120
// Erase:     Map_EraseRange_Isnil15_B @ 0x0051d940 (dualed; isnil@+0x15)
// Free:      Map_FreeSubtree_Isnil15_B @ 0x0051bed0 (via erase full-clear)
// =============================================================================

#include <cstdint>

struct MapNode_Isnil15 {
  MapNode_Isnil15* left;   // +0x00  (*head = begin)
  MapNode_Isnil15* parent; // +0x04
  MapNode_Isnil15* right;  // +0x08
  // isnil @ +0x15
};

// Map facade used by Map_EraseRange_Isnil15_B family:
//   +0x04 head (_Myhead sentinel)
//   +0x08 size (_Mysize)
struct MapFacadeIsnil15_B {
  void* _unused0;         // +0x00
  MapNode_Isnil15* head;  // +0x04
  std::uint32_t size;     // +0x08
};

// Full-range erase twin Isnil15_B; when (first==*head && last==head) frees root
// via Map_FreeSubtree_Isnil15_B and resets sentinel/size.
// ECX=map; stack out*, first*, last*; RET 0x0C.
extern "C" void __thiscall Map_EraseRange_Isnil15_B(MapFacadeIsnil15_B* map,
                                                    void* out_iter,
                                                    MapNode_Isnil15* first,
                                                    MapNode_Isnil15* last); // 0x0051d940
extern "C" void __cdecl operator_delete(void* p);

// ECX = map*. Bare RET. void.
// MSVC-style map tidy: erase full content via EraseRange_Isnil15_B, free header
// sentinel, null head+size. Does not free the map facade object.
// Atexit: FUN_009c3980 vector-dtor over DAT_00b04288[3] (stride 0xc).
extern "C" void __fastcall Map_Tidy_FreeHead_Isnil15_B(MapFacadeIsnil15_B* map)
{
  void* out; // stack slot only (entry push ECX)
  MapNode_Isnil15* head = map->head;
  // full range: begin = *head (left), end = head
  Map_EraseRange_Isnil15_B(map, &out, head->left, head);
  operator_delete(head);
  map->head = nullptr;
  map->size = 0;
}

// Scaffold twin entry (Ghidra name).
extern "C" void __fastcall FUN_0051e1b0(MapFacadeIsnil15_B* map)
{
  Map_Tidy_FreeHead_Isnil15_B(map);
}
