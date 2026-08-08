// =============================================================================
// StdTree_Buynode_Node24_Isnil21_Inferred  (FUN_005118b0)
// -----------------------------------------------------------------------------
// Stable ID: aa_005118b0
// Address:   0x005118b0–0x00511935 inclusive (134 B / 0x86)
// System:    MSVC std::_Tree node buy — Node24, isnil@+0x21 / color@+0x20
// Generated: 2026-08-05 R13-030 dual seal (scaffold 2026-07-23)
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Allocate one red-black tree node (size 0x24) and construct links + int key
//   + vector-like payload + color + isnil=0. Shared buynode for parent insert
//   StdTree_InsertAndRebalance_Node24_Isnil21_Inferred (0x00511950, R12-014).
//
// ABI: __stdcall; 5 stack args; RET 0x14; EAX = node* | null.
// Payload helper: FUN_005114e0 (thiscall on node+0x10; residual R13-029).
// Distinct from Val16/isnil21 buynode 0x00408990 (node 0x28 / Val16 @+0x10).
//
// Dual: reviews/A|B_aa_005118b0_StdTree_Buynode_Node24_Isnil21_Inferred.md

#include <cstdint>

struct Node24Isnil21 {
  Node24Isnil21* left;     // +0x00
  Node24Isnil21* parent;   // +0x04
  Node24Isnil21* right;    // +0x08
  std::int32_t key;        // +0x0C
  // +0x10 .. vector-like shell (copy-constructed by FUN_005114e0; elem stride 0x10)
  // layout residual: three pointer-sized fields + pad into 0x10 bytes before color
  std::uint8_t _vec_shell[0x10]; // +0x10
  std::uint8_t color;      // +0x20  (0=red, 1=black)
  std::uint8_t isnil;      // +0x21
  // total 0x24
};

// Value blob passed from insert: int key followed by source vector object.
struct ValueIntKeyVec {
  std::int32_t key;        // +0x00 → node+0x0C
  // +0x04 → source for FUN_005114e0 into node+0x10
  std::uint8_t vec_src[1]; // opaque; residual dual owns element English
};

// Residual vector copy-construct (thiscall). Live VA 0x005114e0 (R13-029).
extern "C" void* __thiscall FUN_005114e0(void* dst_vec_at_node_plus_10, const void* src_vec);

// CRT
extern "C" void* operator_new(std::size_t size);

// __stdcall RET 0x14
extern "C" Node24Isnil21* __stdcall StdTree_Buynode_Node24_Isnil21_Inferred(
    Node24Isnil21* left,
    Node24Isnil21* parent,
    Node24Isnil21* right,
    const ValueIntKeyVec* value,
    std::uint8_t color)
{
  // SEH frame omitted in plate (present in retail: ExceptionList / LAB_009a34e1).
  auto* node = static_cast<Node24Isnil21*>(operator_new(0x24));
  if (node != nullptr) {
    node->left = left;
    node->parent = parent;
    node->right = right;
    node->key = value->key;
    FUN_005114e0(node->_vec_shell, reinterpret_cast<const void*>(
        reinterpret_cast<const std::uint8_t*>(value) + 4));
    node->color = color;
    node->isnil = 0;
  }
  return node;
}

// Scaffold alias
extern "C" Node24Isnil21* __stdcall FUN_005118b0(
    Node24Isnil21* left,
    Node24Isnil21* parent,
    Node24Isnil21* right,
    const ValueIntKeyVec* value,
    std::uint8_t color)
{
  return StdTree_Buynode_Node24_Isnil21_Inferred(left, parent, right, value, color);
}
