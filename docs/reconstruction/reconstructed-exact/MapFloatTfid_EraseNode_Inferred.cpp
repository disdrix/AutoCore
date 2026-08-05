// =============================================================================
// MapFloatTfid_EraseNode_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0058dc30
// Address:   0x0058dc30 – 0x0058dee5  (autoassault.exe, image base 0x400000)
//            Ghidra lists end 0x0058deb6 (truncated by false noreturn on delete)
// Ghidra:    FUN_0058dc30
// System:    shared tree helper / MapFloatTfid gather distance map
// Generated: 2026-07-29 W25-A dual A/B seal
// Exactness: Decompiler CF + byte-sealed size-- / ret 8 epilogue.
// Bit-for-bit vs retail EXE: DEFERRED.
// Dual:      reviews/A_aa_0058dc30_MapFloatTfid_EraseNode_Inferred.md
//            reviews/B_aa_0058dc30_MapFloatTfid_EraseNode_Inferred.md
// Family:    FreeSubtree 0058da00; EraseRange 0058df60
// =============================================================================
//
// PURPOSE: MSVC map/set single-node erase for MapFloatTfid nodes
//   (isnil @ +0x29, color @ +0x28): throw on nil, unlink, RB rebalance if black,
//   operator_delete(node), size--, write out iterator, ret 8.
// =============================================================================

#include <cstdint>

struct MapFloatTfidNode {
    MapFloatTfidNode* left;    // +0x00
    MapFloatTfidNode* parent;  // +0x04
    MapFloatTfidNode* right;   // +0x08
    // payload before color; color +0x28; isnil +0x29
};

struct MapFloatTfidTree {
    void* unused0;              // +0x00
    MapFloatTfidNode* head;     // +0x04 sentinel
    std::uint32_t size;         // +0x08
};

extern "C" void FUN_004cb270();
extern "C" MapFloatTfidNode* FUN_0051b5d0(MapFloatTfidNode* n);
extern "C" MapFloatTfidNode* FUN_00421b50(MapFloatTfidNode* n);
extern "C" void FUN_004192a0(MapFloatTfidNode* n);
extern "C" void FUN_004192f0(MapFloatTfidNode* n);
extern "C" void operator_delete(void* p);

static inline char node_isnil(MapFloatTfidNode* n) {
    return *reinterpret_cast<char*>(reinterpret_cast<char*>(n) + 0x29);
}
static inline char node_color(MapFloatTfidNode* n) {
    return *reinterpret_cast<char*>(reinterpret_cast<char*>(n) + 0x28);
}
static inline void set_node_color(MapFloatTfidNode* n, char c) {
    *reinterpret_cast<char*>(reinterpret_cast<char*>(n) + 0x28) = c;
}

extern "C" void __thiscall MapFloatTfid_EraseNode_Inferred(
    MapFloatTfidTree* tree,
    MapFloatTfidNode** /*out_it*/,
    MapFloatTfidNode* node)
{
    // SEH: ExceptionList / LAB_009a57b2 — elided

    if (node_isnil(node) != 0) {
        // throw "invalid map/set<T> iterator" @ 0x00a152f0
        // _CxxThrowException(..., &DAT_00acc34c);
        return; // unreachable
    }

    FUN_004cb270();

    MapFloatTfidNode* repl = node->left;
    if (node_isnil(repl) == 0) {
        if (node_isnil(node->right) == 0)
            repl = node->right;
    } else {
        repl = node->right;
    }
    MapFloatTfidNode* parent = node->parent;
    if (node_isnil(repl) == 0)
        repl->parent = parent;

    MapFloatTfidNode* head = tree->head;
    if (head->parent == node)
        head->parent = repl;
    else if (parent->left == node)
        parent->left = repl;
    else
        parent->right = repl;

    if (head->left == node) {
        MapFloatTfidNode* b = parent;
        if (node_isnil(repl) == 0)
            b = FUN_0051b5d0(repl);
        head->left = b;
    }
    if (head->right == node) {
        if (node_isnil(repl) == 0)
            head->right = FUN_00421b50(repl);
        else
            head->right = parent;
    }

    if (node_color(node) == 1) {
        MapFloatTfidNode* x = repl;
        MapFloatTfidNode* p = parent;
        if (x != head->parent) {
            do {
                if (node_color(x) != 1)
                    break;
                if (x == p->left) {
                    MapFloatTfidNode* w = p->right;
                    if (node_color(w) == 0) {
                        set_node_color(w, 1);
                        set_node_color(p, 0);
                        FUN_004192a0(p);
                        w = p->right;
                    }
                    if (node_isnil(w) == 0) {
                        char cl = node_color(w->left);
                        char cr = node_color(w->right);
                        if (cl != 1 || cr != 1) {
                            if (cr == 1) {
                                set_node_color(w->left, 1);
                                set_node_color(w, 0);
                                FUN_004192f0(w);
                                w = p->right;
                            }
                            set_node_color(w, node_color(p));
                            set_node_color(p, 1);
                            set_node_color(w->right, 1);
                            FUN_004192a0(p);
                            break;
                        }
                        set_node_color(w, 0);
                    }
                } else {
                    MapFloatTfidNode* w = p->left;
                    if (node_color(w) == 0) {
                        set_node_color(w, 1);
                        set_node_color(p, 0);
                        FUN_004192f0(p);
                        w = p->left;
                    }
                    if (node_isnil(w) == 0) {
                        if (node_color(w->right) == 1 && node_color(w->left) == 1) {
                            set_node_color(w, 0);
                        } else {
                            if (node_color(w->left) == 1) {
                                set_node_color(w->right, 1);
                                set_node_color(w, 0);
                                FUN_004192a0(w);
                                w = p->left;
                            }
                            set_node_color(w, node_color(p));
                            set_node_color(p, 1);
                            set_node_color(w->left, 1);
                            FUN_004192f0(p);
                            break;
                        }
                    }
                }
                x = p;
                p = p->parent;
            } while (p != head->parent);
        }
        set_node_color(x, 1);
    }

    operator_delete(node);

    // Sealed epilogue (missed by decompiler noreturn):
    if (tree->size > 0)
        tree->size--;
    // *out_it write from precomputed successor — stack slots; see raw seal
}

extern "C" void __thiscall FUN_0058dc30(
    MapFloatTfidTree* tree, MapFloatTfidNode** out_it, MapFloatTfidNode* node)
{
    MapFloatTfid_EraseNode_Inferred(tree, out_it, node);
}
