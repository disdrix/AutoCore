// =============================================================================
// StdTree_Buynode_Val12
// -----------------------------------------------------------------------------
// Stable ID: aa_005ae220
// Address:   0x005ae220  (autoassault.exe, image base 0x400000)
// Body:      0x005ae220 – 0x005ae268 exclusive (72 B / 0x48)
// System:    std red-black tree / map node allocation
// Generated: 2026-07-29 W24-I dual seal (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow + byte ABI.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: MSVC-style _Tree_node buy for maps/sets whose value is 12 bytes
// (3 dwords). Allocates 0x1c, wires left/parent/right, copies value[3], sets
// color, forces isnil=0. Used by category-cooldown insert (FUN_0051c1c0) and
// five other map insert helpers. Twin FUN_005ae1c0 buys 0x24 (Val20).

#include <cstdint>

// operator_new(size_t) — CRT; address via rel32 from body (not re-listed).

struct StdTreeNode_Val12 {
    StdTreeNode_Val12* left;    // +0x00
    StdTreeNode_Val12* parent;  // +0x04
    StdTreeNode_Val12* right;   // +0x08
    uint32_t value[3];          // +0x0c
    uint8_t  color;             // +0x18  (MSVC: 0=red, 1=black)
    uint8_t  isnil;             // +0x19
    uint8_t  _pad[2];
};

// Retail: stdcall ret 0x14; return in EAX (null on OOM).
extern "C" StdTreeNode_Val12* __stdcall StdTree_Buynode_Val12(
    StdTreeNode_Val12* left,
    StdTreeNode_Val12* parent,
    StdTreeNode_Val12* right,
    const uint32_t* value3,
    uint8_t color)
{
    auto* node = static_cast<StdTreeNode_Val12*>(operator_new(0x1c));
    if (node != nullptr) {
        node->left = left;
        node->parent = parent;
        node->right = right;
        node->value[0] = value3[0];
        node->value[1] = value3[1];
        node->value[2] = value3[2];
        node->color = color;
        node->isnil = 0;
    }
    return node;
}

// Scaffold alias
extern "C" StdTreeNode_Val12* __stdcall FUN_005ae220(
    StdTreeNode_Val12* left,
    StdTreeNode_Val12* parent,
    StdTreeNode_Val12* right,
    const uint32_t* value3,
    uint8_t color)
{
    return StdTree_Buynode_Val12(left, parent, right, value3, color);
}
