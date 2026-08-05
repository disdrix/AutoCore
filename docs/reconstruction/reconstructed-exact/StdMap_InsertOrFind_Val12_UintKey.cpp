// =============================================================================
// StdMap_InsertOrFind_Val12_UintKey
// -----------------------------------------------------------------------------
// Stable ID: aa_00573810
// Address:   0x00573810  (autoassault.exe, image base 0x400000)
// Body:      0x00573810 – 0x005738c8 exclusive (184 B / 0xB8)
// System:    std map unique insert-or-find (Val12 / uint key)
// Generated: 2026-07-29 W28-T dual seal (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow + byte ABI.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: MSVC _Tree insert-or-find for Val12 nodes. Key is value[0] as uint.
// Miss → FUN_00573510 (StdTree_InsertAndRebalance_Val12). Hit → out{it,0}, no rewrite.
// Callers: inventory-grid helpers FUN_00572360 / FUN_00572730 / FUN_00572ab0.

#include <cstdint>

struct StdTreeNode_Val12 {
    StdTreeNode_Val12* left;    // +0x00
    StdTreeNode_Val12* parent;  // +0x04
    StdTreeNode_Val12* right;   // +0x08
    uint32_t key;               // +0x0c  (value dword0)
    uint32_t v1;                // +0x10
    uint32_t v2;                // +0x14
    uint8_t  color;             // +0x18
    uint8_t  isnil;             // +0x19
    uint8_t  _pad[2];
};

struct MapShell_Val12 {
    void* _pad0;                 // +0x00
    StdTreeNode_Val12* head;     // +0x04  MSVC header: left=leftmost, parent=root, right=rightmost
    uint32_t size;               // +0x08
};

struct InsertPair {
    StdTreeNode_Val12* it;       // +0
    uint8_t inserted;            // +4
    uint8_t _pad[3];
};

// Callees (not defined here):
//   FUN_00573510 — StdTree_InsertAndRebalance_Val12 (thiscall map; ret 0x10)
//   FUN_005ae050 — tree predecessor (mutates iterator*)

extern "C" void __thiscall FUN_00573510(
    MapShell_Val12* map,
    StdTreeNode_Val12** outIt,
    char addLeft,
    StdTreeNode_Val12* where,
    const uint32_t* value);

extern "C" void __fastcall FUN_005ae050(StdTreeNode_Val12** it);

extern "C" void __thiscall StdMap_InsertOrFind_Val12_UintKey(
    MapShell_Val12* map,
    InsertPair* out,
    const uint32_t* value)
{
    StdTreeNode_Val12* head = map->head;
    StdTreeNode_Val12* parent = head;
    bool addLeft = true;

    // Retail: if head->parent (root) isnil==0
    if (head->parent->isnil == 0) {
        StdTreeNode_Val12* cur = head->parent; // root
        do {
            parent = cur;
            addLeft = (value[0] < parent->key);
            cur = addLeft ? parent->left : parent->right;
        } while (cur->isnil == 0);
    }

    StdTreeNode_Val12* where = parent;

    if (addLeft) {
        // Retail: parent == *head == leftmost
        if (parent == head->left) {
            StdTreeNode_Val12* scratch = where;
            FUN_00573510(map, &scratch, 1, parent, value);
            out->it = scratch;
            out->inserted = 1;
            return;
        }
        FUN_005ae050(&where);
        parent = where;
    }

    if (parent->key < value[0]) {
        StdTreeNode_Val12* scratch = where;
        FUN_00573510(map, &scratch, static_cast<char>(addLeft), parent, value);
        out->it = scratch;
        out->inserted = 1;
        return;
    }

    out->it = parent;
    out->inserted = 0;
}

// Scaffold alias
extern "C" void __thiscall FUN_00573810(
    MapShell_Val12* map,
    InsertPair* out,
    const uint32_t* value)
{
    StdMap_InsertOrFind_Val12_UintKey(map, out, value);
}
