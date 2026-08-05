// =============================================================================
// RbTree_InitEmptyHeader  (FUN_004e7450)
// -----------------------------------------------------------------------------
// Stable ID: aa_004e7450
// Address:   0x004e7450–0x004e747a  (autoassault.exe, image base 0x400000)
// Body size: 43 bytes
// System:    containers / RB-tree empty header
// Generated: 2026-07-23 scaffold as FUN_004e7450; dual A/B seal 2026-07-29 (W22-R)
// Exactness: Behavior-preserving rewrite of decompiler + entry-byte CF.
//            Not modernization. Bit-for-bit vs retail: DEFERRED.
// =============================================================================
//
// PURPOSE
//   Construct an empty RB-tree / std::_Tree-style header in place:
//     alloc 0x18 sentinel via RbTree_AllocEmptyNode_Inferred (FUN_00439770)
//     header+4 = node
//     node+0x15 = 1 (head/nil)
//     node left/parent/right = node (self-links)
//     header+8 = 0 (size)
//     return header*
//
// ABI
//   __thiscall: ECX = header*; plain ret; EAX = header*.
//
// READABILITY CF:
//   push esi; mov esi,ecx → call AllocEmptyNode → store head → flag →
//   self-link L/P/R → size 0 → mov eax,esi; pop esi; ret
//

#include <cstdint>

// Sealed W18-S node factory
extern "C" void *RbTree_AllocEmptyNode_Inferred(void);

struct RbTreeHeader {
  // +0x00: unused by this unit
  void *head;          // +0x04
  std::uint32_t size;  // +0x08
};

struct RbTreeNode18 {
  RbTreeNode18 *left;    // +0x00
  RbTreeNode18 *parent;  // +0x04
  RbTreeNode18 *right;   // +0x08
  // +0x0c .. +0x13: payload / color packing (factory zeros links only)
  // +0x14: factory flag byte (=1 from AllocEmptyNode)
  // +0x15: head/nil flag (set 1 here)
};

extern "C" RbTreeHeader *RbTree_InitEmptyHeader(RbTreeHeader *self /*ECX*/)
{
  auto *node = static_cast<RbTreeNode18 *>(RbTree_AllocEmptyNode_Inferred());

  self->head = node;
  *reinterpret_cast<std::uint8_t *>(reinterpret_cast<char *>(node) + 0x15) = 1;

  // Retail reloads head from self+4 for each link store (order: parent, left, right).
  auto *h = static_cast<RbTreeNode18 *>(self->head);
  h->parent = h;
  h->left = h;
  h->right = h;

  self->size = 0;
  return self;
}

// Also available under historical scaffold name FUN_004e7450 (same VA).
