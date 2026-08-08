// =============================================================================
// StdTree_NodeCtor_Val16_Isnil21_Inferred  (Ghidra FUN_004099b0)
// -----------------------------------------------------------------------------
// Stable ID: aa_004099b0
// Address:   0x004099b0  (autoassault.exe, image base 0x400000)
// Body:      0x004099b0–0x004099f3 exclusive (67 B / 0x43)
// System:    MSVC std::_Tree node construct — Val16 payload, isnil@+0x21
// Agent:     WQ9I-C OWN-ONLY dual 2026-08-05
// Exactness: Behavior-preserving; meaningful names. Not modernization.
// Terminal:  false
// =============================================================================

// PURPOSE:
// Construct one isnil21 tree node after operator_new(0x28) in buynode
// StdTree_Buynode_Val16_Isnil21_Inferred (0x00408990). Writes L/P/R links,
// copies 16-byte value at +0x10, sets color @+0x20, forces isnil=0 @+0x21.
// Does not touch +0x0c. Returns this in EAX.

#include <cstdint>

struct NodeIsnil21 {
  NodeIsnil21 *left;     // +0x00
  NodeIsnil21 *parent;   // +0x04
  NodeIsnil21 *right;    // +0x08
  // +0x0C untouched
  std::uint32_t val[4];  // +0x10 .. +0x1C  (Val16)
  std::uint8_t color;    // +0x20
  std::uint8_t isnil;    // +0x21
  // pad to 0x28
};

// __thiscall RET 0x14; EAX = self
extern "C" NodeIsnil21 *__thiscall StdTree_NodeCtor_Val16_Isnil21_Inferred(
    NodeIsnil21 *self,
    NodeIsnil21 *left,
    NodeIsnil21 *parent,
    NodeIsnil21 *right,
    const std::uint32_t *value4,
    std::uint8_t color)
{
  self->left = left;
  self->parent = parent;
  self->right = right;
  self->val[0] = value4[0];
  self->val[1] = value4[1];
  self->val[2] = value4[2];
  self->val[3] = value4[3];
  self->color = color;
  self->isnil = 0;
  return self;
}

// Scaffold alias
extern "C" NodeIsnil21 *__thiscall FUN_004099b0(
    NodeIsnil21 *self,
    NodeIsnil21 *left,
    NodeIsnil21 *parent,
    NodeIsnil21 *right,
    const std::uint32_t *value4,
    std::uint8_t color)
{
  return StdTree_NodeCtor_Val16_Isnil21_Inferred(
      self, left, parent, right, value4, color);
}
