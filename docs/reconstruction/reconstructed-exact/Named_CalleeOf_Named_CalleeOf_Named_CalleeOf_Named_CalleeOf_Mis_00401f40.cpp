// =============================================================================
// RETIRED scaffold — Named_CalleeOf_*Mis_00401f40
// -----------------------------------------------------------------------------
// Stable ID: aa_00401f40
// Address:   0x00401f40
// Retired:   2026-08-05 MEGA-079 dual seal
// =============================================================================
//
// This chain-of-caller plate name is RETIRED.
// Canonical reconstruction:
//   StdTree_Buynode_StringByte_Isnil2D_Inferred
//   docs/reconstruction/reconstructed-exact/StdTree_Buynode_StringByte_Isnil2D_Inferred.cpp
//
// Ghidra symbol twin:
//   docs/reconstruction/reconstructed-exact/FUN_00401f40.cpp
//
// Evidence: pure MSVC _Tree buynode (string+byte / isnil@+0x2d / size 0x30);
// not a mission product method. See dual A/B reviews for aa_00401f40.

#include <cstdint>

struct StringByteVal;
struct NodeIsnil2D_StringByte;

extern "C" NodeIsnil2D_StringByte* __stdcall StdTree_Buynode_StringByte_Isnil2D_Inferred(
    NodeIsnil2D_StringByte* left,
    NodeIsnil2D_StringByte* parent,
    NodeIsnil2D_StringByte* right,
    const StringByteVal* value,
    std::uint8_t color);

// Retired alias — forwards to promoted name (do not use in new ports).
extern "C" NodeIsnil2D_StringByte* __stdcall
Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mis_00401f40(
    NodeIsnil2D_StringByte* left,
    NodeIsnil2D_StringByte* parent,
    NodeIsnil2D_StringByte* right,
    const StringByteVal* value,
    std::uint8_t color)
{
  return StdTree_Buynode_StringByte_Isnil2D_Inferred(left, parent, right, value, color);
}
