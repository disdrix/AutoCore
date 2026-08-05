// =============================================================================
// FUN_0040d700 — scaffold twin of StdTree_EraseRange_Val12
// -----------------------------------------------------------------------------
// Stable ID: aa_0040d700
// Address:   0x0040d700 (autoassault.exe, image base 0x400000)
// Wave:      W32-C OWN-ONLY dual 2026-07-29
// Canonical: StdTree_EraseRange_Val12 (see StdTree_EraseRange_Val12.cpp)
// =============================================================================

#include <cstdint>

// Forward to named clean (same ABI).
extern "C" void __thiscall StdTree_EraseRange_Val12(void* map, void** outIt,
                                                    void* first, void* last);

extern "C" void __thiscall FUN_0040d700(void* map, void** outIt, void* first,
                                        void* last)
{
  StdTree_EraseRange_Val12(map, outIt, first, last);
}
