// =============================================================================
// FUN_00408990  (scaffold twin of StdTree_Buynode_Val16_Isnil21_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00408990
// Address:   0x00408990  (autoassault.exe, image base 0x400000)
// System:    MSVC std::_Tree buynode Val16 / isnil@+0x21
// Generated: 2026-08-04 WQ9H-J dual (supersedes 2026-07-23 scaffold paste)
// Exactness: Behavior-preserving; see named clean for plate notes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

// Prefer named plate:
//   docs/reconstruction/reconstructed-exact/StdTree_Buynode_Val16_Isnil21_Inferred.cpp

struct NodeIsnil21;

extern "C" NodeIsnil21* __stdcall StdTree_Buynode_Val16_Isnil21_Inferred(
    NodeIsnil21* left,
    NodeIsnil21* parent,
    NodeIsnil21* right,
    const std::uint32_t* value4,
    std::uint8_t color);

extern "C" NodeIsnil21* __stdcall FUN_00408990(
    NodeIsnil21* left,
    NodeIsnil21* parent,
    NodeIsnil21* right,
    const std::uint32_t* value4,
    std::uint8_t color)
{
  return StdTree_Buynode_Val16_Isnil21_Inferred(left, parent, right, value4, color);
}
