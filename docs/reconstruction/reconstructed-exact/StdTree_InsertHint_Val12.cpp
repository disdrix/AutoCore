// =============================================================================
// StdTree_InsertHint_Val12  (FUN_0053a8e0)
// -----------------------------------------------------------------------------
// Stable ID: aa_0053a8e0
// Address:   0x0053a8e0  (autoassault.exe, image base 0x400000)
// Body:      0x0053a8e0–0x0053aa43 exclusive (355 B)
// System:    std red-black tree / map insert-with-hint (Val12)
// Wave:      W28-Q OWN-ONLY dual (2026-07-29)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
//            Neighbor path: Prevnode/Nextnode use a local nodeptr (decomp often
//            aliases it as param_3); insert targets match MSVC unique-hint insert.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================

#include <cstdint>

struct MapNode_Val12 {
    MapNode_Val12* left;     // +0
    MapNode_Val12* parent;    // +4
    MapNode_Val12* right;     // +8
    int32_t key;             // +0x0c
    int32_t val1;            // +0x10
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

struct InsertOrFindPair {
    MapNode_Val12* node;
    char inserted;
};

extern MapNode_Val12** __thiscall StdTree_InsertAndRebalance_Val12(
    MapShell_Val12* map,
    MapNode_Val12** outIt,
    int addLeft,
    MapNode_Val12* where,
    const Val12* value);

extern InsertOrFindPair* __thiscall StdTree_InsertOrFind_Val12(
    MapShell_Val12* map,
    InsertOrFindPair* outPair,
    const Val12* value);

extern void __fastcall StdTree_Prevnode_Val12(MapNode_Val12** node);
extern void __fastcall StdTree_Nextnode_Val12(MapNode_Val12** node);

MapNode_Val12** __thiscall StdTree_InsertHint_Val12(
    MapShell_Val12* map,
    MapNode_Val12** outIt,
    MapNode_Val12* hint,
    const Val12* value)
{
    MapNode_Val12* head = map->head;

    if (map->size == 0) {
        StdTree_InsertAndRebalance_Val12(map, outIt, /*addLeft*/1, head, value);
        return outIt;
    }

    if (hint == head->left) {
        if (value->key < hint->key) {
            StdTree_InsertAndRebalance_Val12(map, outIt, 1, hint, value);
            return outIt;
        }
    } else if (hint == head) {
        MapNode_Val12* rightmost = head->right;
        if (rightmost->key < value->key) {
            StdTree_InsertAndRebalance_Val12(map, outIt, 0, rightmost, value);
            return outIt;
        }
    } else {
        const int32_t key = value->key;
        int32_t hintKey = hint->key;

        if (key < hintKey) {
            MapNode_Val12* pred = hint;
            StdTree_Prevnode_Val12(&pred);
            if (pred->key < key) {
                // between pred and hint
                if (pred->right->isnil != 0)
                    StdTree_InsertAndRebalance_Val12(map, outIt, 0, pred, value);
                else
                    StdTree_InsertAndRebalance_Val12(map, outIt, 1, hint, value);
                return outIt;
            }
            hintKey = hint->key;
        }

        // decomp: SBORROW4 form of (hintKey < key)
        if (hintKey < key) {
            MapNode_Val12* succ = hint;
            StdTree_Nextnode_Val12(&succ);
            if (hint == map->head || key < succ->key /* after step, decomp uses updated node */) {
                if (hint->right->isnil != 0)
                    StdTree_InsertAndRebalance_Val12(map, outIt, 0, hint, value);
                else
                    StdTree_InsertAndRebalance_Val12(map, outIt, 1, succ, value);
                return outIt;
            }
        }
    }

    InsertOrFindPair pair;
    StdTree_InsertOrFind_Val12(map, &pair, value);
    *outIt = pair.node;
    return outIt;
}
