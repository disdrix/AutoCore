// =============================================================================
// FUN_004129f0  (scaffold alias → Map_Tree_Predecessor_Isnil15_Edx)
// -----------------------------------------------------------------------------
// Stable ID: aa_004129f0
// Address:   0x004129f0  (autoassault.exe, image base 0x400000)
// Body:      0x004129f0 – 0x00412a40 inclusive (81 B / 0x51)
// System:    std red-black tree / map iterator (isnil @ +0x15)
// Generated: 2026-08-04 W38-M (replaces 2026-07-23 scaffold)
// Exactness: Behavior-preserving. Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

struct MapTreeNode_Isnil15 {
    MapTreeNode_Isnil15* left;
    MapTreeNode_Isnil15* parent;
    MapTreeNode_Isnil15* right;
    uint8_t  color;
    uint8_t  isnil;
};

// Retail: EDX = it; bare RET; void.
extern "C" void FUN_004129f0(MapTreeNode_Isnil15** it /*EDX*/)
{
    MapTreeNode_Isnil15* node = *it;
    if (node->isnil != 0) {
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
