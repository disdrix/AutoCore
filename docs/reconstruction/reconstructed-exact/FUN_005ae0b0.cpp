// =============================================================================
// FUN_005ae0b0  (scaffold alias → StdTree_Inc_Val12)
// -----------------------------------------------------------------------------
// Stable ID: aa_005ae0b0
// Address:   0x005ae0b0  (autoassault.exe, image base 0x400000)
// Body:      75 B; bare RET
// System:    std red-black tree / map iterator (Val12)
// Refined:   2026-07-29 W28-N
// =============================================================================

#include <cstdint>

struct StdTreeNode_Val12 {
    StdTreeNode_Val12* left;
    StdTreeNode_Val12* parent;
    StdTreeNode_Val12* right;
    uint32_t value[3];
    uint8_t  color;
    uint8_t  isnil;
    uint8_t  _pad[2];
};

extern "C" void __fastcall FUN_005ae0b0(StdTreeNode_Val12** it)
{
    StdTreeNode_Val12* node = *it;
    if (node->isnil != 0) {
        return;
    }

    StdTreeNode_Val12* right = node->right;
    if (right->isnil == 0) {
        StdTreeNode_Val12* p = right;
        while (p->left->isnil == 0) {
            p = p->left;
        }
        *it = p;
        return;
    }

    StdTreeNode_Val12* parent = node->parent;
    while (parent->isnil == 0 && *it == parent->right) {
        *it = parent;
        parent = parent->parent;
    }
    *it = parent;
}
