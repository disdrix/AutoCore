// =============================================================================
// StdMap_Dtor_Val12
// -----------------------------------------------------------------------------
// Stable ID: aa_004e7350
// Address:   0x004e7350  (autoassault.exe, image base 0x400000)
// System:    std red-black map / tree destructor (Val12)
// Wave:      W29-M OWN-ONLY dual (2026-07-29)
// Exactness: Behavior-preserving rewrite of decompiler + byte-sealed epilogue.
//            Not modernization. Bit-for-bit vs retail: DEFERRED.
// =============================================================================
//
// PURPOSE: Destroy Val12 map shell — erase all nodes [begin,end), free header,
//          null head and size. Callee FUN_004e5120 = StdMap_EraseRange_Val12.
//
// ABI: __thiscall ECX = map*; no stack args; RET 0 (C3).
// Body: 0x004e7350–0x004e737e exclusive (46 B). Ghidra end 0x004e736f stale.
//
// Decompiler residual: operator_delete marked noreturn — FALSE; null stores after.
// =============================================================================

#include <cstdint>

struct MapNode_Val12 {
  MapNode_Val12* left;    // +0  (also *header = leftmost under MSVC)
  MapNode_Val12* parent;  // +4  (header.parent = root)
  MapNode_Val12* right;   // +8
  // value 12 bytes @ +0x0c
  // color @ +0x18, isnil @ +0x19
};

struct MapShell_Val12 {
  // padding / unused @ +0 in some shells
  MapNode_Val12* head;  // +4
  std::uint32_t size;   // +8
};

// FUN_004e5120 — StdMap_EraseRange_Val12 (W28-P); ret 0x0c
extern "C" void __thiscall StdMap_EraseRange_Val12(
    MapShell_Val12* map,
    MapNode_Val12** outIt,
    MapNode_Val12* first,
    MapNode_Val12* last);

extern "C" void __cdecl operator_delete(void* p);

// Ghidra: FUN_004e7350
void __thiscall StdMap_Dtor_Val12(MapShell_Val12* self)
{
  MapNode_Val12* outIt;
  MapNode_Val12* head = self->head;
  // Bytes: first = *head (leftmost), last = head (end sentinel)
  MapNode_Val12* begin = head->left;

  StdMap_EraseRange_Val12(self, &outIt, begin, head);

  operator_delete(self->head);
  self->head = nullptr;
  self->size = 0;
}
