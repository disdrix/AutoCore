// =============================================================================
// FUN_00573700 — scaffold twin of StdTree_EraseRange_Val12_InventoryGrid_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00573700
// Address:   0x00573700 (autoassault.exe, image base 0x400000)
// Wave:      MEGA-120 OWN-ONLY dual 2026-08-05
// Canonical: StdTree_EraseRange_Val12_InventoryGrid_Inferred
//            (see StdTree_EraseRange_Val12_InventoryGrid_Inferred.cpp)
// ABI:       __thiscall; ECX=map*; stack (outIt, first, last); RET 0x0C
// =============================================================================

#include <cstdint>

// Forward to named clean (same ABI).
extern "C" void __thiscall StdTree_EraseRange_Val12_InventoryGrid_Inferred(
    void* map, void** outIt, void* first, void* last);

extern "C" void __thiscall FUN_00573700(void* map, void** outIt, void* first,
                                        void* last)
{
  StdTree_EraseRange_Val12_InventoryGrid_Inferred(map, outIt, first, last);
}
