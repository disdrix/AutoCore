// =============================================================================
// StdTree_OperatorIndex_Val12  (FUN_0053af20)
// -----------------------------------------------------------------------------
// Stable ID: aa_0053af20
// Address:   0x0053af20  (autoassault.exe, image base 0x400000)
// Body:      0x0053af20–0x0053af91 exclusive (113 B / 0x71)
// System:    std red-black map operator[] / get-or-insert (Val12)
// Wave:      W29-Q OWN-ONLY dual (2026-07-29)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================

#include <cstdint>

struct MapNode_Val12 {
    MapNode_Val12* left;     // +0
    MapNode_Val12* parent;    // +4
    MapNode_Val12* right;     // +8
    int32_t key;             // +0x0c
    int32_t val1;            // +0x10  (mapped start — return value)
    int32_t val2;            // +0x14
    char color;              // +0x18
    char isnil;              // +0x19
};

struct MapShell_Val12 {
    void* pad0;
    MapNode_Val12* head;     // +4
    int size;                // +8
};

struct Val12 {
    int32_t key;
    int32_t val1;
    int32_t val2;
};

// FUN_0053a8e0 — W28-Q sealed
extern MapNode_Val12** __thiscall StdTree_InsertHint_Val12(
    MapShell_Val12* map,
    MapNode_Val12** outIt,
    MapNode_Val12* hint,
    const Val12* value);
// RET 0x0C

// __thiscall; RET 0x04
// Returns pointer to mapped (val1,val2) at node+0x10.
int32_t* __thiscall StdTree_OperatorIndex_Val12(MapShell_Val12* map, const int32_t* key)
{
    MapNode_Val12* head = map->head;
    MapNode_Val12* candidate = head;
    MapNode_Val12* node = head->left; // root

    if (node->isnil == 0) {
        // lower_bound: walk to first node with key >= *key
        do {
            if (node->key < *key) {
                node = node->right;
            } else {
                candidate = node;
                node = node->left;
            }
        } while (node->isnil == 0);
    }

    // Hit: candidate is in-tree and candidate.key == *key
    // (lower_bound gives >= ; <= seals equality)
    if (candidate != head && candidate->key <= *key) {
        return &candidate->val1; // node + 0x10
    }

    // Miss: insert default-mapped zeros with hint = lower_bound candidate
    Val12 value;
    value.key = *key;
    value.val1 = 0;
    value.val2 = 0;

    MapNode_Val12* outIt = nullptr;
    StdTree_InsertHint_Val12(map, &outIt, candidate, &value);
    return &outIt->val1; // *outIt + 0x10
}
