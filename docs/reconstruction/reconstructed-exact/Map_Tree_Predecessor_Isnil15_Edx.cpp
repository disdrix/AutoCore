// =============================================================================
// Map_Tree_Predecessor_Isnil15_Edx
// -----------------------------------------------------------------------------
// Stable ID: aa_004129f0
// Address:   0x004129f0  (autoassault.exe, image base 0x400000)
// Body:      0x004129f0 – 0x00412a40 inclusive (81 B / 0x51)
// System:    std red-black tree / map iterator (isnil @ +0x15)
// Generated: 2026-08-04 W38-M dual seal (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow + byte ABI.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: MSVC-style _Tree::_Dec / unchecked iterator-- for nodes with
// isnil @ +0x15. Advances *it to the in-order predecessor.
// ABI differs from peer Map_Tree_Predecessor_Isnil15 (0x005a2850): this unit
// takes the iterator in EDX (call sites: lea edx, [local]; call), not ECX.

#include <cstdint>

struct MapTreeNode_Isnil15 {
    MapTreeNode_Isnil15* left;    // +0x00
    MapTreeNode_Isnil15* parent;  // +0x04
    MapTreeNode_Isnil15* right;   // +0x08
    // value payload begins +0x0C (not accessed here)
    uint8_t  color;               // +0x14 (layout context; not accessed)
    uint8_t  isnil;               // +0x15
};

// Retail: EDX = it; bare RET; void. (Not MSVC __fastcall ECX first-arg.)
extern "C" void Map_Tree_Predecessor_Isnil15_Edx(MapTreeNode_Isnil15** it /*EDX*/)
{
    MapTreeNode_Isnil15* node = *it;
    if (node->isnil != 0) {
        // end → rightmost via header.right
        *it = node->right;
        return;
    }

    MapTreeNode_Isnil15* left = node->left;
    if (left->isnil == 0) {
        MapTreeNode_Isnil15* p = left;
        while (p->right->isnil == 0) {
            p = p->right;
        }
        *it = p;
        return;
    }

    MapTreeNode_Isnil15* parent = node->parent;
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

// Scaffold alias (Ghidra)
extern "C" void FUN_004129f0(MapTreeNode_Isnil15** it /*EDX*/)
{
    Map_Tree_Predecessor_Isnil15_Edx(it);
}
