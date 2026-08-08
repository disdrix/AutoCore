// =============================================================================
// FUN_00421a60  (clean twin alias of StdTree_Max_Isnil21_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00421a60
// Address:   0x00421a60  (autoassault.exe, image base 0x400000)
// Body:      0x00421a60–0x00421a7c exclusive (28 B)
// System:    MSVC std::_Tree max / rightmost (isnil@+0x21)
// Generated: 2026-08-05 R13-001 dual
// Exactness: Behavior-preserving; see StdTree_Max_Isnil21_Inferred.cpp for plate.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

// Forward to named plate (same ABI: cdecl, EAX return).
extern "C" std::int32_t *StdTree_Max_Isnil21_Inferred(std::int32_t *node);

// Ghidra alias — decompiler shows void; bytes return node* in EAX.
extern "C" std::int32_t *FUN_00421a60(std::int32_t *param_1)
{
  return StdTree_Max_Isnil21_Inferred(param_1);
}
