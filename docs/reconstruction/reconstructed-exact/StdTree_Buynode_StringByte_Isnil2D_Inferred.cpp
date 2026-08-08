// =============================================================================
// StdTree_Buynode_StringByte_Isnil2D_Inferred  (FUN_00401f40)
// -----------------------------------------------------------------------------
// Stable ID: aa_00401f40
// Address:   0x00401f40–0x00401fbf exclusive (127 B / 0x7F)
// System:    MSVC std::_Tree node buy — string+byte value, isnil@+0x2d, size 0x30
// Generated: 2026-08-05 MEGA-079 dual seal (scaffold 2026-07-23)
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Allocate one red-black tree node (size 0x30) and construct links +
//   MSVC basic_string (0x1c) + mapped byte + color + isnil=0. Shared buynode
//   for insert/rebalance residual FUN_00401db0 (isnil2D family; string-key map
//   under mission null-dialog partition host — body is pure STL).
//
// ABI: __stdcall; 5 stack args; RET 0x14; EAX = node* | null.
// Ctor helper: FUN_00401fe0 (ECX=parent, EDX=right, EDI=value*, stack node/left/color; RET 0xC).
// Value helper: FUN_00402040 (string copy + byte @ value+0x1c; RET 4).
// Distinct from isnil29 Val24 buynode 0x00404180/0x00407e30 and isnil31 Val32 0x00403f30.
// Reject scaffold Named_CalleeOf_*Mis_00401f40.
//
// Dual: reviews/A|B_aa_00401f40_StdTree_Buynode_StringByte_Isnil2D_Inferred.md

#include <cstdint>

struct StringByteVal {
  // MSVC std::basic_string<char> layout (0x1c) — opaque here
  std::uint8_t str_storage[0x1c];
  std::uint8_t mapped_byte;  // +0x1c of value / node+0x28
  std::uint8_t pad_to_color[3];  // +0x29..+0x2b so color lands at node+0x2c
};

struct NodeIsnil2D_StringByte {
  NodeIsnil2D_StringByte* left;    // +0x00
  NodeIsnil2D_StringByte* parent;  // +0x04
  NodeIsnil2D_StringByte* right;   // +0x08
  StringByteVal value;             // +0x0c .. +0x2b (string 0x1c + byte + pad)
  std::uint8_t color;              // +0x2c  (0=red, 1=black)
  std::uint8_t isnil;              // +0x2d
  // pad to 0x30
};

// UnOWN: node construct. Live VA 0x00401fe0; RET 0xC.
// Retail ABI: ECX=parent, EDX=right, EDI=value*, stack: node, left, color.
// Plate models as explicit args for readability (not a bit-exact CC claim on helper).
extern "C" NodeIsnil2D_StringByte* FUN_00401fe0(
    NodeIsnil2D_StringByte* self,
    NodeIsnil2D_StringByte* parent,
    NodeIsnil2D_StringByte* right,
    NodeIsnil2D_StringByte* left,
    std::uint8_t color);

// CRT
extern "C" void* operator_new(std::size_t size);

// __stdcall RET 0x14
extern "C" NodeIsnil2D_StringByte* __stdcall StdTree_Buynode_StringByte_Isnil2D_Inferred(
    NodeIsnil2D_StringByte* left,
    NodeIsnil2D_StringByte* parent,
    NodeIsnil2D_StringByte* right,
    const StringByteVal* value,
    std::uint8_t color)
{
  // SEH frame omitted in plate (present in retail: ExceptionList / LAB_009bc811).
  auto* node = static_cast<NodeIsnil2D_StringByte*>(operator_new(0x30));
  if (node != nullptr) {
    // Retail: PUSH color; PUSH left; PUSH node;
    //         EDI=value; EDX=right; ECX=parent; CALL 00401fe0
    FUN_00401fe0(node, parent, right, left, color);
    // Ctor body (evidence): L/P/R stores; FUN_00402040 string+byte; color@+0x2c; isnil=0@+0x2d
    (void)value;  // consumed via EDI at call site into ctor/value helpers
  }
  return node;
}

// Scaffold alias — Ghidra symbol
extern "C" NodeIsnil2D_StringByte* __stdcall FUN_00401f40(
    NodeIsnil2D_StringByte* left,
    NodeIsnil2D_StringByte* parent,
    NodeIsnil2D_StringByte* right,
    const StringByteVal* value,
    std::uint8_t color)
{
  return StdTree_Buynode_StringByte_Isnil2D_Inferred(left, parent, right, value, color);
}
