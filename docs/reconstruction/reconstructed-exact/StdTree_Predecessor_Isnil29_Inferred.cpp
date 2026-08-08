// =============================================================================
// StdTree_Predecessor_Isnil29_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004cb4f0
// Address:   0x004cb4f0  (autoassault.exe, image base 0x400000)
// Body:      0x004cb4f0 – 0x004cb540 exclusive (80 B / 0x50); pad CC
// System:    std red-black tree / map iterator (isnil @ +0x29)
// Generated: 2026-08-04 WQ9G-B dual seal (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow + byte ABI.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: MSVC-style _Tree::_Dec / unchecked iterator-- for nodes with
// isnil @ +0x29. Advances *it to the in-order predecessor.
// Same node family as StdTree_InsertAndRebalance_Isnil29_Inferred (0x004cbb60)
// and StdTree_InsertHint_Isnil29_Inferred (0x004cc220).
// ABI: ECX = Node**; bare RET; leaf. Distinct from Map_Tree_Predecessor_Isnil15*
// peers (isnil @ +0x15).

#include <cstdint>

struct StdTreeNode_Isnil29 {
    StdTreeNode_Isnil29* left;    // +0x00
    StdTreeNode_Isnil29* parent;  // +0x04
    StdTreeNode_Isnil29* right;   // +0x08
    // value payload begins +0x0C (not accessed here)
    // color @ +0x28 (layout context; not accessed)
    uint8_t isnil;                // +0x29
};

// Retail: ECX = it; bare C3; void. Ghidra: __fastcall.
extern "C" void __fastcall StdTree_Predecessor_Isnil29_Inferred(
    StdTreeNode_Isnil29** it /*ECX*/)
{
    StdTreeNode_Isnil29* node = *it;
    if (node->isnil != 0) {
        // end/header → rightmost via header.right
        *it = node->right;
        return;
    }

    StdTreeNode_Isnil29* left = node->left;
    if (left->isnil == 0) {
        StdTreeNode_Isnil29* p = left;
        while (p->right->isnil == 0) {
            p = p->right;
        }
        *it = p;
        return;
    }

    StdTreeNode_Isnil29* parent = node->parent;
    if (parent->isnil == 0) {
        while (parent->isnil == 0 && *it == parent->left) {
            *it = parent;
            parent = parent->parent;
        }
        if (parent->isnil == 0) {
            *it = parent;
        }
    }
}
