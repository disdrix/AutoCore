// =============================================================================
// FUN_005380d0 — StagingMapNode_Construct (inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_005380d0
// Address:   0x005380d0  (autoassault.exe, image base 0x400000)
// System:    missions-progression
// Generated: 2026-07-23 scaffold; dual-refined 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler control flow + body bytes.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// Dual:      reviews/A_aa_005380d0_StagingMapNode_Construct.md
//            reviews/B_aa_005380d0_StagingMapNode_Construct.md
// =============================================================================
//
// PURPOSE: Freestanding construct for mission-staging map RB nodes (0x50).
//   - operator_new(0x50)
//   - left/parent/right from args; valuePair[14] → +0x10 (REP MOVSD ECX=0xE)
//   - color @ +0x48; isnil @ +0x49 = 0
//   - Returns node* in EAX (0 if alloc failed). RET 0x14.
//   - Does NOT insert, rebalance, or bump map size (caller FUN_00538ea0).
//
// ABI (image-sealed): five stack dwords, freestanding (not thiscall).
// Ghidra decomp return type void is incorrect — EAX holds the pointer.
//

#include <cstdint>
#include <cstring>

struct StagingMapNode {
  StagingMapNode* left;    // +0x00
  StagingMapNode* parent;  // +0x04
  StagingMapNode* right;   // +0x08
  uint32_t        gap_0C;  // +0x0C — not written by this ctor
  uint32_t        key;     // +0x10
  uint32_t        pad_14;  // +0x14
  uint32_t        payload[12]; // +0x18 .. +0x47
  uint8_t         color;   // +0x48
  uint8_t         isnil;   // +0x49
  uint8_t         pad_4A[6];   // +0x4A .. +0x4F — not written
};

static_assert(sizeof(StagingMapNode) == 0x50, "StagingMapNode size");

// operator_new is the sole callee (VA 0x00489892 in image).
extern void* operator_new(std::size_t size);

// __stdcall-style: callee cleans 0x14 bytes of stack args.
StagingMapNode* FUN_005380d0(
    StagingMapNode* left,
    StagingMapNode* parent,
    StagingMapNode* right,
    const uint32_t* valuePair,  // 14 dwords: key, pad, payload[12]
    uint8_t color)
{
  auto* node = static_cast<StagingMapNode*>(operator_new(0x50));
  if (node != nullptr) {
    node->left = left;
    node->right = right;
    node->parent = parent;
    // Image: lea edi,[eax+0x10] / mov ecx,0xE / rep movsd
    std::memcpy(reinterpret_cast<uint8_t*>(node) + 0x10, valuePair, 0xE * 4);
    node->color = color;
    node->isnil = 0;
  }
  return node;
}
