// =============================================================================
// StdTree_Tidy_FreeHead_Bare_Val12_InventoryGrid_Inferred  (aa_005738d0)
// -----------------------------------------------------------------------------
// Address:   0x005738d0 – 0x005738fc inclusive (45 B / 0x2D)
//            autoassault.exe, image base 0x400000
// Wave:      R11-004 OWN-ONLY dual 2026-08-05
// Exactness: Behavior-preserving rewrite from live decompile + full-body
//            read_memory + disassemble_function. Post-delete epilogue from
//            bytes (decompiler false noreturn truncates after operator_delete).
// Bit-for-bit vs retail EXE: DEFERRED.
// ABI:       ECX=map*; bare RET (C3); void. No SEH frame.
// Peer:      StdTree_Tidy_FreeHead_Bare_Val12 @ 0x0040d6d0 (W33-A; erase=0040d700)
// System:    inventory-transfer (InventoryGrid placement map shell @ +0x5c)
// =============================================================================

#include <cstdint>

struct StdTreeNode_Val12 {
  StdTreeNode_Val12* left;    // +0x00
  StdTreeNode_Val12* parent;  // +0x04
  StdTreeNode_Val12* right;   // +0x08
  // color @ +0x18, isnil @ +0x19 (0 = real node)
  std::uint8_t pad_0c[12];
  std::uint8_t color;         // +0x18
  std::uint8_t isnil;         // +0x19
};

// Tree facade (InventoryGrid: shell at grid+0x5c):
//   +0x04 head (_Myhead)  → grid+0x60
//   +0x08 size (_Mysize)  → grid+0x64
struct StdTreeShell_Val12 {
  void* unused0;              // +0x00
  StdTreeNode_Val12* head;    // +0x04
  std::uint32_t size;         // +0x08
};

// Dualed MEGA-120: full-range erase Val12 (InventoryGrid free/erase leaves).
// ECX=map; stack out*, first*, last*; RET 0x0C.
// Full gate: first==head->left && last==head → free subtree + reset.
extern "C" void __thiscall StdTree_EraseRange_Val12_InventoryGrid_Inferred(
    StdTreeShell_Val12* map,
    StdTreeNode_Val12** outIt,
    StdTreeNode_Val12* first,
    StdTreeNode_Val12* last); // 0x00573700

extern "C" void __cdecl operator_delete(void* p);

// ECX = map shell*. Bare RET. void.
// MSVC-style _Tree tidy without SEH: erase full content, free header, null head+size.
// Does NOT free the map shell itself.
extern "C" void __fastcall StdTree_Tidy_FreeHead_Bare_Val12_InventoryGrid_Inferred(
    StdTreeShell_Val12* map)
{
  void* out; // stack slot only (entry push ECX; unused as value)
  StdTreeNode_Val12* head = map->head;
  // full range: begin = *head (left), end = head
  StdTree_EraseRange_Val12_InventoryGrid_Inferred(
      map,
      reinterpret_cast<StdTreeNode_Val12**>(&out),
      head->left,
      head);
  operator_delete(head);
  map->head = nullptr;
  map->size = 0;
}

// Scaffold / Ghidra alias
extern "C" void __fastcall FUN_005738d0(StdTreeShell_Val12* map)
{
  StdTree_Tidy_FreeHead_Bare_Val12_InventoryGrid_Inferred(map);
}
