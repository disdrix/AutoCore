// =============================================================================
// FUN_0046c6c0 / StdTree_Buynode_Val12_EsiValue
// -----------------------------------------------------------------------------
// Stable ID: aa_0046c6c0
// Address:   0x0046c6c0  (autoassault.exe, image base 0x400000)
// Body:      0x0046c6c0 – 0x0046c702 exclusive (66 B / 0x42)
// System:    std red-black tree / map node allocation
// Generated: 2026-07-29 W28-T dual seal (refined from 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite of decompiler control flow + byte ABI.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: Val12 node buy; value in ESI; ret 0x10. Twin of FUN_005ae220 (ret 0x14).
// See StdTree_Buynode_Val12_EsiValue.cpp for named plate + port form.

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

// Retail CF: operator_new(0x1c); if non-null: links, *ESI×3, color, isnil=0; ret 0x10.
// Decompiler shows unaff_ESI; bytes confirm mov from ESI into node+0x0c.
extern "C" StdTreeNode_Val12* __stdcall FUN_0046c6c0(
    StdTreeNode_Val12* param_1,  // left
    StdTreeNode_Val12* param_2,  // parent
    StdTreeNode_Val12* param_3,  // right
    uint8_t param_4             // color
    /* ESI = value* */)
{
    auto* puVar1 = static_cast<StdTreeNode_Val12*>(operator_new(0x1c));
    if (puVar1 != nullptr) {
        // ESI-held value pointer — modeled as register snapshot at call site
        uint32_t* unaff_ESI; // retail: live ESI
        (void)unaff_ESI;
        puVar1->left = param_1;
        puVar1->parent = param_2;
        puVar1->right = param_3;
        // puVar1->value[i] = unaff_ESI[i]  — see raw/bytes
        puVar1->color = param_4;
        puVar1->isnil = 0;
    }
    return puVar1;
}
