// =============================================================================
// FUN_00401f40  — scaffold twin of StdTree_Buynode_StringByte_Isnil2D_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00401f40
// Address:   0x00401f40–0x00401fbf exclusive (127 B / 0x7F)
// System:    MSVC std::_Tree node buy — string+byte value, isnil@+0x2d, size 0x30
// Generated: 2026-08-05 MEGA-079 dual seal (scaffold 2026-07-23 refreshed)
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Canonical clean: StdTree_Buynode_StringByte_Isnil2D_Inferred.cpp
// Dual: reviews/A|B_aa_00401f40_StdTree_Buynode_StringByte_Isnil2D_Inferred.md
// Retired: Named_CalleeOf_*Mis_00401f40 chain plate.

#include <cstdint>

struct StringByteVal {
  std::uint8_t str_storage[0x1c];
  std::uint8_t mapped_byte;
};

struct NodeIsnil2D_StringByte {
  NodeIsnil2D_StringByte* left;
  NodeIsnil2D_StringByte* parent;
  NodeIsnil2D_StringByte* right;
  StringByteVal value;
  std::uint8_t color;
  std::uint8_t isnil;
};

extern "C" NodeIsnil2D_StringByte* FUN_00401fe0(
    NodeIsnil2D_StringByte* self,
    NodeIsnil2D_StringByte* parent,
    NodeIsnil2D_StringByte* right,
    NodeIsnil2D_StringByte* left,
    std::uint8_t color);

extern "C" void* operator_new(std::size_t size);

extern "C" NodeIsnil2D_StringByte* __stdcall StdTree_Buynode_StringByte_Isnil2D_Inferred(
    NodeIsnil2D_StringByte* left,
    NodeIsnil2D_StringByte* parent,
    NodeIsnil2D_StringByte* right,
    const StringByteVal* value,
    std::uint8_t color);

// Ghidra symbol alias
extern "C" NodeIsnil2D_StringByte* __stdcall FUN_00401f40(
    NodeIsnil2D_StringByte* left,
    NodeIsnil2D_StringByte* parent,
    NodeIsnil2D_StringByte* right,
    const StringByteVal* value,
    std::uint8_t color)
{
  // SEH omitted (LAB_009bc811). operator_new(0x30); null-safe FUN_00401fe0; RET 0x14.
  return StdTree_Buynode_StringByte_Isnil2D_Inferred(left, parent, right, value, color);
}
