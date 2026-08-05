// =============================================================================
// FUN_005ae050  (scaffold alias → StdTree_Dec_Val12)
// -----------------------------------------------------------------------------
// Stable ID: aa_005ae050
// Address:   0x005ae050  (autoassault.exe, image base 0x400000)
// Body:      80 B; bare RET
// System:    std red-black tree / map iterator (Val12)
// Refined:   2026-07-29 W29-E
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

extern "C" void __fastcall FUN_005ae050(StdTreeNode_Val12** it)
{
    StdTreeNode_Val12* node = *it;
    if (node->isnil != 0) {
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
