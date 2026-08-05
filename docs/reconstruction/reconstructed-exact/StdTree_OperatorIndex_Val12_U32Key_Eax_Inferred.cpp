// =============================================================================
// StdTree_OperatorIndex_Val12_U32Key_Eax_Inferred  (FUN_0043bd40)
// -----------------------------------------------------------------------------
// Stable ID: aa_0043bd40
// Address:   0x0043bd40  (autoassault.exe, image base 0x400000)
// Body:      0x0043bd40–0x0043bda5 exclusive (101 B / 0x65)
// System:    std red-black map operator[] / get-or-insert (Val12, u32 key)
// Wave:      W37-Q OWN-ONLY dual (2026-08-04)
// Exactness: Behavior-preserving rewrite of decompiler control flow + body bytes.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================

#include <cstdint>

struct MapNode_Val12 {
    MapNode_Val12* left;     // +0
    MapNode_Val12* parent;    // +4
    MapNode_Val12* right;     // +8
    uint32_t key;            // +0x0c  (unsigned compare)
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
    uint32_t key;
    int32_t val1;
    int32_t val2;
};

// FUN_0043be60 — unowned insert-hint helper (register/out-param ABI).
// Modeled as: writes *outIt; stages value {key,0,0} with hint node.
extern MapNode_Val12** __thiscall FUN_0043be60(
    MapShell_Val12* map,
    MapNode_Val12** outIt,
    MapNode_Val12* hint,
    const Val12* value);

// ECX = map; EAX = key* (not a stack formal); plain RET
// Returns pointer to mapped (val1,val2) at node+0x10.
int32_t* StdTree_OperatorIndex_Val12_U32Key_Eax_Inferred(
    MapShell_Val12* map /* ECX */,
    const uint32_t* key /* EAX */)
{
    MapNode_Val12* head = map->head;
    MapNode_Val12* candidate = head;
    MapNode_Val12* node = head->left; // root (header parent/left as used by family)

    if (node->isnil == 0) {
        // unsigned lower_bound: walk to first node with key >= *key
        do {
            if (node->key < *key) {
                node = node->right;
            } else {
                candidate = node;
                node = node->left;
            }
        } while (node->isnil == 0);
    }

    // Hit: candidate in-tree and candidate.key == *key
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
    FUN_0043be60(map, &outIt, candidate, &value);
    return &outIt->val1; // *outIt + 0x10
}
