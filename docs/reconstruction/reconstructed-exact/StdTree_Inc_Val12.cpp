// =============================================================================
// StdTree_Inc_Val12
// -----------------------------------------------------------------------------
// Stable ID: aa_005ae0b0
// Address:   0x005ae0b0  (autoassault.exe, image base 0x400000)
// Body:      0x005ae0b0 – 0x005ae0fb exclusive (75 B / 0x4B)
// System:    std red-black tree / map iterator (Val12)
// Generated: 2026-07-29 W28-N dual seal (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow + byte ABI.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: MSVC-style _Tree::_Inc / unchecked iterator++ for Val12 nodes
// (isnil @ +0x19). Advances *it to the in-order successor. Shared by multiple
// Val12 erase helpers (e.g. StdTree_EraseNode_Val12 @ 0x005ae990).
// Legacy seed Named_CalleeOf_…Client_RecvSkillStatusEffect is narrow.

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
extern "C" void __fastcall StdTree_Inc_Val12(StdTreeNode_Val12** it)
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

// Scaffold alias
extern "C" void __fastcall FUN_005ae0b0(StdTreeNode_Val12** it)
{
    StdTree_Inc_Val12(it);
}
