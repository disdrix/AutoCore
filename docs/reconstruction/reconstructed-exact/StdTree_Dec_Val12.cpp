// =============================================================================
// StdTree_Dec_Val12
// -----------------------------------------------------------------------------
// Stable ID: aa_005ae050
// Address:   0x005ae050  (autoassault.exe, image base 0x400000)
// Body:      0x005ae050 – 0x005ae0a0 exclusive (80 B / 0x50)
// System:    std red-black tree / map iterator (Val12)
// Generated: 2026-07-29 W29-E dual seal (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow + byte ABI.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: MSVC-style _Tree::_Dec / unchecked iterator-- for Val12 nodes
// (isnil @ +0x19). Advances *it to the in-order predecessor. Shared by Val12
// insert-or-find / insert-with-hint helpers (e.g. StdMap_InsertOrFind_Val12_UintKey).

#include <cstdint>

struct StdTreeNode_Val12 {
    StdTreeNode_Val12* left;    // +0x00
    StdTreeNode_Val12* parent;  // +0x04
    StdTreeNode_Val12* right;   // +0x08
    uint32_t value[3];          // +0x0c  (layout context; not accessed here)
    uint8_t  color;             // +0x18
    uint8_t  isnil;             // +0x19
    uint8_t  _pad[2];
};

// Retail: ECX = it; bare RET; void
extern "C" void __fastcall StdTree_Dec_Val12(StdTreeNode_Val12** it)
{
    StdTreeNode_Val12* node = *it;
    if (node->isnil != 0) {
        // end → rightmost via header.right
        *it = node->right;
        return;
    }

    StdTreeNode_Val12* left = node->left;
    if (left->isnil == 0) {
        StdTreeNode_Val12* p = left;
        while (p->right->isnil == 0) {
            p = p->right;
        }
        *it = p;
        return;
    }

    StdTreeNode_Val12* parent = node->parent;
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

// Scaffold alias
extern "C" void __fastcall FUN_005ae050(StdTreeNode_Val12** it)
{
    StdTree_Dec_Val12(it);
}
