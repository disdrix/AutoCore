// =============================================================================
// StdTree_Buynode_CharKey_Isnil21_Inferred  (FUN_0041d860)
// -----------------------------------------------------------------------------
// Stable ID: aa_0041d860
// Address:   0x0041d860–0x0041d8e5 inclusive (134 B / 0x86)
// System:    skills-abilities / MSVC std::_Tree node buy — char key, isnil@+0x21
// Generated: 2026-08-05 R13-023 dual seal (scaffold 2026-07-23)
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Allocate one red-black tree node (size 0x24) and construct links + char key
//   @+0x0C + residual value body @+0x10 + color @+0x20 + isnil=0 @+0x21.
//   Shared buynode for always-insert FUN_0041ba30 (R12-011 dualed).
//
// ABI: __stdcall; 5 stack args; RET 0x14; EAX = node* | null.
// Value residual ctor: FUN_0041c140 (thiscall on node+0x10; RET 0x4).
// Distinct from Val16 isnil21 buynode 00408990 (node 0x28 / Val16 @+0x10).
//
// Dual: reviews/A|B_aa_0041d860_StdTree_Buynode_CharKey_Isnil21_Inferred.md

#include <cstdint>

struct NodeCharKeyIsnil21 {
  NodeCharKeyIsnil21* left;    // +0x00
  NodeCharKeyIsnil21* parent;  // +0x04
  NodeCharKeyIsnil21* right;   // +0x08
  std::uint8_t key;            // +0x0C  (char key)
  // +0x0D..+0x0F pad
  // +0x10 residual value body (vector-like of 0x18-byte elems; product Open)
  std::uint8_t value_body[0x10]; // +0x10 .. +0x1F (layout placeholder)
  std::uint8_t color;          // +0x20  (0=red, 1=black)
  std::uint8_t isnil;          // +0x21
  // pad to 0x24
};

// Value pack passed by parent insert: char key at +0, payload at +4.
struct CharKeyValueInferred {
  std::uint8_t key;
  // pad to +4
  std::uint8_t payload[1];  // start of residual vector-like object
};

// UnOWN: residual value construct (thiscall on node+0x10). Live VA 0x0041c140.
extern "C" void* __thiscall FUN_0041c140(void* self, const void* src_payload);

// CRT
extern "C" void* operator_new(std::size_t size);

// __stdcall RET 0x14
extern "C" NodeCharKeyIsnil21* __stdcall StdTree_Buynode_CharKey_Isnil21_Inferred(
    NodeCharKeyIsnil21* left,
    NodeCharKeyIsnil21* parent,
    NodeCharKeyIsnil21* right,
    const CharKeyValueInferred* value,
    std::uint8_t color)
{
  // SEH frame omitted in plate (present in retail: ExceptionList / LAB_009bd7d1).
  auto* node = static_cast<NodeCharKeyIsnil21*>(operator_new(0x24));
  if (node != nullptr) {
    node->left = left;
    node->parent = parent;
    node->right = right;
    node->key = value->key;
    // thiscall construct residual payload at node+0x10 from value+4
    FUN_0041c140(reinterpret_cast<void*>(
                     reinterpret_cast<std::uint8_t*>(node) + 0x10),
                 reinterpret_cast<const void*>(
                     reinterpret_cast<const std::uint8_t*>(value) + 4));
    node->color = color;
    node->isnil = 0;
  }
  return node;
}

// Scaffold alias
extern "C" NodeCharKeyIsnil21* __stdcall FUN_0041d860(
    NodeCharKeyIsnil21* left,
    NodeCharKeyIsnil21* parent,
    NodeCharKeyIsnil21* right,
    const CharKeyValueInferred* value,
    std::uint8_t color)
{
  return StdTree_Buynode_CharKey_Isnil21_Inferred(left, parent, right, value, color);
}
