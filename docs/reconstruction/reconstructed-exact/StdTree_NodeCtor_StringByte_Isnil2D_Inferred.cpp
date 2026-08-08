// =============================================================================
// StdTree_NodeCtor_StringByte_Isnil2D_Inferred  (FUN_00401fe0)
// -----------------------------------------------------------------------------
// Stable ID: aa_00401fe0
// Address:   0x00401fe0–0x0040203a exclusive (90 B / 0x5A)
// System:    MSVC std::_Tree node construct — string+byte value, isnil@+0x2d, size 0x30
// Generated: 2026-08-05 R10-004 dual seal (scaffold 2026-07-23)
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   In-place construct one red-black tree node (no allocation): links L/P/R +
//   MSVC basic_string (0x1c) + mapped byte + color + isnil=0. Called from
//   dualed buynode FUN_00401f40 after operator_new(0x30); that buy is used by
//   residual insert/rebalance FUN_00401db0 (isnil2D family; string-key map
//   under mission null-dialog partition host — body is pure STL).
//
// ABI: hybrid __usercall — ECX=parent, EDX=right, EDI=value*,
//      stack: node, left, color; RET 0xC; EAX = node*.
// Value helper: FUN_00402040 BasicStringFlag_CopyCtor_EdiSrc_Inferred (RET 4).
// Distinct from Val24 isnil29 NodeCtor 0x00409880/0x004098d0 and BuyHead 0x00409780.
// Reject scaffold Named_CalleeOf_*Nam_00401fe0.
//
// Dual: reviews/A|B_aa_00401fe0_StdTree_NodeCtor_StringByte_Isnil2D_Inferred.md

#include <cstdint>

struct BasicString_0x1c {
  std::uint8_t raw[0x1C];
};

struct StringByteVal {
  BasicString_0x1c str;   // +0x00 of value / node+0x0c
  std::uint8_t mapped_byte;  // +0x1c of value / node+0x28
  std::uint8_t pad_to_color[3];  // +0x29..+0x2b so color lands at node+0x2c
};

struct NodeIsnil2D_StringByte {
  NodeIsnil2D_StringByte* left;    // +0x00
  NodeIsnil2D_StringByte* parent;  // +0x04
  NodeIsnil2D_StringByte* right;   // +0x08
  StringByteVal value;             // +0x0c .. +0x2b
  std::uint8_t color;              // +0x2c  (0=red, 1=black)
  std::uint8_t isnil;              // +0x2d
  // pad to 0x30
};

// Dualed MEGA-080: dest stack; EDI = source; RET 4
extern "C" StringByteVal* BasicStringFlag_CopyCtor_EdiSrc_Inferred(
    StringByteVal* dest /* stack */);

// Retail hybrid ABI (plate free-function form for readability).
// Call sites must place parent@ECX, right@EDX, value*@EDI before CALL.
extern "C" NodeIsnil2D_StringByte* StdTree_NodeCtor_StringByte_Isnil2D_Inferred(
    NodeIsnil2D_StringByte* node,     // stack [ESP+4] → ESI
    NodeIsnil2D_StringByte* parent,   // ECX
    NodeIsnil2D_StringByte* right,    // EDX
    NodeIsnil2D_StringByte* left,     // stack [ESP+8]
    const StringByteVal* value,       // EDI
    std::uint8_t color)               // stack [ESP+0xC]
{
  // SEH frame omitted in plate (present in retail: ExceptionList / LAB_009bc7ed).
  node->left = left;
  node->parent = parent;
  node->right = right;
  // Retail: LEA EAX,[ESI+0xc]; PUSH EAX; CALL 00402040  (EDI already = value)
  (void)value;
  BasicStringFlag_CopyCtor_EdiSrc_Inferred(&node->value);
  node->color = color;
  node->isnil = 0;
  return node;  // EAX; RET 0xC
}

// Scaffold alias — Ghidra symbol
extern "C" NodeIsnil2D_StringByte* FUN_00401fe0(
    NodeIsnil2D_StringByte* node,
    NodeIsnil2D_StringByte* parent,
    NodeIsnil2D_StringByte* right,
    NodeIsnil2D_StringByte* left,
    const StringByteVal* value,
    std::uint8_t color)
{
  return StdTree_NodeCtor_StringByte_Isnil2D_Inferred(
      node, parent, right, left, value, color);
}
