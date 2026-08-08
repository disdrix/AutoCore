// =============================================================================
// FUN_00401fe0  (Ghidra alias of StdTree_NodeCtor_StringByte_Isnil2D_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00401fe0
// Address:   0x00401fe0–0x0040203a exclusive (90 B / 0x5A)
// System:    MSVC std::_Tree node construct — string+byte, isnil@+0x2d
// Generated: 2026-08-05 R10-004 dual seal (scaffold 2026-07-23)
// Exactness: Behavior-preserving rewrite. Bit-for-bit / runtime: DEFERRED.
// =============================================================================
// Prefer named unit: StdTree_NodeCtor_StringByte_Isnil2D_Inferred.cpp

#include <cstdint>

struct BasicString_0x1c {
  std::uint8_t raw[0x1C];
};

struct StringByteVal {
  BasicString_0x1c str;
  std::uint8_t mapped_byte;
  std::uint8_t pad_to_color[3];
};

struct NodeIsnil2D_StringByte {
  NodeIsnil2D_StringByte* left;
  NodeIsnil2D_StringByte* parent;
  NodeIsnil2D_StringByte* right;
  StringByteVal value;
  std::uint8_t color;
  std::uint8_t isnil;
};

extern "C" StringByteVal* BasicStringFlag_CopyCtor_EdiSrc_Inferred(StringByteVal* dest);

// Hybrid: ECX=parent, EDX=right, EDI=value*, stack node/left/color, RET 0xC
extern "C" NodeIsnil2D_StringByte* FUN_00401fe0(
    NodeIsnil2D_StringByte* node,
    NodeIsnil2D_StringByte* parent,
    NodeIsnil2D_StringByte* right,
    NodeIsnil2D_StringByte* left,
    const StringByteVal* value,
    std::uint8_t color)
{
  // SEH LAB_009bc7ed omitted.
  node->left = left;
  node->parent = parent;
  node->right = right;
  (void)value;  // retail source is EDI into BasicStringFlag_CopyCtor_EdiSrc_Inferred
  BasicStringFlag_CopyCtor_EdiSrc_Inferred(&node->value);
  node->color = color;
  node->isnil = 0;
  return node;
}
