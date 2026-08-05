// =============================================================================
// StdTree_Buynode_Val12_EsiValue
// -----------------------------------------------------------------------------
// Stable ID: aa_0046c6c0
// Address:   0x0046c6c0  (autoassault.exe, image base 0x400000)
// Body:      0x0046c6c0 – 0x0046c702 exclusive (66 B / 0x42)
// System:    std red-black tree / map node allocation
// Generated: 2026-07-29 W28-T dual seal (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow + byte ABI.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: MSVC-style _Tree_node buy for Val12 (12-byte value) maps/sets where
// the value pointer is passed in ESI rather than as a 5th stack arg.
// Twin: StdTree_Buynode_Val12 @ 0x005ae220 (stack value*, ret 0x14).
// Callers: FUN_0044a8c0 (Map_TreeInsertAndRebalance_Val12_EsiBuy), FUN_0043c2e0.

#include <cstdint>

struct StdTreeNode_Val12 {
    StdTreeNode_Val12* left;    // +0x00
    StdTreeNode_Val12* parent;  // +0x04
    StdTreeNode_Val12* right;   // +0x08
    uint32_t value[3];          // +0x0c
    uint8_t  color;             // +0x18  (MSVC: 0=red, 1=black)
    uint8_t  isnil;             // +0x19
    uint8_t  _pad[2];
};

// operator_new(size_t) — CRT; address via rel32 from body.

// Retail ABI: stdcall ret 0x10; ESI = const uint32_t value3[3]; EAX = node*|null.
// ESI is an implicit register arg (not portable C). Callers load ESI before call.
// Port form below takes explicit value* — preferred for AutoCore.

extern "C" StdTreeNode_Val12* StdTree_Buynode_Val12_EsiValue(
    StdTreeNode_Val12* left,
    StdTreeNode_Val12* parent,
    StdTreeNode_Val12* right,
    const uint32_t value3[3],
    uint8_t color)
{
    auto* node = static_cast<StdTreeNode_Val12*>(operator_new(0x1c));
    if (node != nullptr) {
        node->left = left;
        node->parent = parent;
        node->right = right;
        // Retail: mov ecx,[esi]; mov [eax+0xc],ecx; … +4/+8
        node->value[0] = value3[0];
        node->value[1] = value3[1];
        node->value[2] = value3[2];
        node->color = color;
        node->isnil = 0;
    }
    return node;
}

// Scaffold alias — same algorithm; retail still uses ESI for value3.
extern "C" StdTreeNode_Val12* __stdcall FUN_0046c6c0(
    StdTreeNode_Val12* left,
    StdTreeNode_Val12* parent,
    StdTreeNode_Val12* right,
    uint8_t color
    /* ESI = value3 */)
{
    // Documentation stub: real body reads ESI; see raw/bytes.
    // Ports must use StdTree_Buynode_Val12_EsiValue(..., value3, color).
    (void)left; (void)parent; (void)right; (void)color;
    return nullptr;
}
