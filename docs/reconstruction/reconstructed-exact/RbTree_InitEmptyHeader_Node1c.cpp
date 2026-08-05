// =============================================================================
// RbTree_InitEmptyHeader_Node1c  (FUN_004e7420)
// -----------------------------------------------------------------------------
// Stable ID: aa_004e7420
// Address:   0x004e7420–0x004e744a  (autoassault.exe, image base 0x400000)
// Body size: 43 bytes
// System:    containers / RB-tree empty header (0x1c-node flavor)
// Generated: 2026-07-23 scaffold as FUN_004e7420; dual A/B seal 2026-07-29 (W23-M)
// Exactness: Behavior-preserving rewrite of decompiler + entry-byte CF.
//            Not modernization. Bit-for-bit vs retail: DEFERRED.
// =============================================================================
//
// PURPOSE
//   Construct an empty RB-tree / std::_Tree-style header in place for the
//   0x1c-byte node flavor:
//     alloc 0x1c sentinel via FUN_005ae2b0
//     header+4 = node
//     node+0x19 = 1 (head/nil)
//     node left/parent/right = node (self-links)
//     header+8 = 0 (size)
//     return header*
//
// ABI
//   __thiscall: ECX = header*; plain ret; EAX = header*.
//
// SIBLING
//   FUN_004e7450 / RbTree_InitEmptyHeader — same CF with 0x18 factory + flag +0x15.
//

#include <cstdint>

// Nested factory (not dual-owned here): operator_new(0x1c); zero L/P/R; +0x18=1; +0x19=0
extern "C" void *FUN_005ae2b0(void);

struct RbTreeHeader {
  // +0x00: unused by this unit
  void *head;          // +0x04
  std::uint32_t size;  // +0x08
};

struct RbTreeNode1c {
  RbTreeNode1c *left;    // +0x00
  RbTreeNode1c *parent;  // +0x04
  RbTreeNode1c *right;   // +0x08
  // +0x0c .. +0x17: payload / color packing
  // +0x18: factory flag byte (=1 from FUN_005ae2b0)
  // +0x19: head/nil flag (set 1 here)
};

extern "C" RbTreeHeader *RbTree_InitEmptyHeader_Node1c(RbTreeHeader *self /*ECX*/)
{
  auto *node = static_cast<RbTreeNode1c *>(FUN_005ae2b0());

  self->head = node;
  *reinterpret_cast<std::uint8_t *>(reinterpret_cast<char *>(node) + 0x19) = 1;

  // Retail reloads head from self+4 for each link store (order: parent, left, right).
  auto *h = static_cast<RbTreeNode1c *>(self->head);
  h->parent = h;
  h->left = h;
  h->right = h;

  self->size = 0;
  return self;
}

// Also available under historical scaffold name FUN_004e7420 (same VA).
