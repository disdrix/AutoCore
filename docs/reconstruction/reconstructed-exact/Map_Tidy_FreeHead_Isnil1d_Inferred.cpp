// =============================================================================
// Map_Tidy_FreeHead_Isnil1d_Inferred  (FUN_0051e120)
// -----------------------------------------------------------------------------
// Stable ID: aa_0051e120
// Address:   0x0051e120–0x0051e14d inclusive (46 B / 0x2E; exclusive end 0x0051e14e)
//            autoassault.exe, image base 0x400000
// Wave:      2026-08-04 WQ9F-G OWN dual A/B seal
// Exactness: Behavior-preserving rewrite from live decompile + full-body
//            read_memory. Post-delete epilogue from bytes (decompiler false
//            noreturn truncates after operator_delete).
// Bit-for-bit vs retail EXE: DEFERRED.
// ABI:       ECX=map*; bare RET (C3); void. No SEH frame.
// Peer:      Map_Tidy_FreeHead @ 0x0051da30 (same 46 B template; isnil@+0x29)
//            StdTree_Tidy_FreeHead_Bare_Val12 @ 0x0040d6d0
// Erase:     Map_EraseRange_Isnil1d_Inferred @ 0x0051d700 (dualed WQ9E-I)
// =============================================================================

#include <cstdint>

struct MapNode_Isnil1d {
  MapNode_Isnil1d* left;    // +0x00  (*head = begin)
  MapNode_Isnil1d* parent;  // +0x04
  MapNode_Isnil1d* right;   // +0x08
  // isnil @ +0x1d (from dualed Map_EraseRange_Isnil1d_Inferred)
};

// Map facade used by Map_EraseRange family:
//   +0x04 head (_Myhead sentinel)
//   +0x08 size (_Mysize)
struct MapFacadeIsnil1d {
  void* _unused0;           // +0x00
  MapNode_Isnil1d* head;    // +0x04
  std::uint32_t size;       // +0x08
};

// Full-range erase for isnil@+0x1d family; when (first==*head && last==head)
// frees root via FUN_0051be10(head->parent) and resets sentinel/size.
// ECX=map; stack out*, first*, last*; RET 0x0C.
extern "C" void __thiscall Map_EraseRange_Isnil1d_Inferred(
    MapFacadeIsnil1d* map,
    void* out_iter,
    MapNode_Isnil1d* first,
    MapNode_Isnil1d* last); // 0x0051d700
extern "C" void __cdecl operator_delete(void* p);

// ECX = map*. Bare RET. void.
// MSVC-style map tidy: erase full content, free header sentinel, null head+size.
// Does not free the map facade object (caller may operator_delete the facade).
// Static atexit thunk FUN_009c3940 loads ECX=0xb04240 then JMP here.
extern "C" void __fastcall Map_Tidy_FreeHead_Isnil1d_Inferred(MapFacadeIsnil1d* map)
{
  void* out; // stack slot only (entry push ECX)
  MapNode_Isnil1d* head = map->head;
  // full range: begin = *head (left), end = head
  Map_EraseRange_Isnil1d_Inferred(map, &out, head->left, head);
  operator_delete(head);
  map->head = nullptr;
  map->size = 0;
}

// Ghidra alias
extern "C" void __fastcall FUN_0051e120(MapFacadeIsnil1d* map)
{
  Map_Tidy_FreeHead_Isnil1d_Inferred(map);
}
