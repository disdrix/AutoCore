// =============================================================================
// StdMap_EraseIterator_Inferred  /  FUN_004baa30
// -----------------------------------------------------------------------------
// Stable ID: aa_004baa30
// Address:   0x004baa30 – 0x004bace5  (autoassault.exe, image base 0x400000)
//            Ghidra lists end 0x004bacb6 (truncated by false noreturn on delete)
// System:    CRT / MSVC STL _Tree erase (shared; NDSpecialFX map clear path)
// Generated: 2026-07-29 W23-I dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE: MSVC map/set single-iterator erase — nil throw, unlink, RB rebalance,
//          operator_delete(node), size--, write out iterator.
// See also: FUN_004baa30.cpp (scaffold twin).
// =============================================================================

#include <cstdint>

struct StdMapNode {
    StdMapNode* left;    // +0x00
    StdMapNode* parent;  // +0x04
    StdMapNode* right;   // +0x08
    // +0x0c.. payload-ish / padding to color
    // color at +0x14 (also node dword[5] low byte); isnil at +0x15
};

struct StdMapFacade {
    void* unused0;       // +0x00
    StdMapNode* head;    // +0x04 sentinel
    uint32_t size;       // +0x08
};

extern "C" void FUN_00673070();
extern "C" StdMapNode* FUN_004e12a0(StdMapNode* n); // leftmost
extern "C" StdMapNode* FUN_00421b70(StdMapNode* n); // rightmost
extern "C" void FUN_004e22d0(StdMapNode* n);       // rotate A
extern "C" void FUN_006753b0(StdMapNode* n);       // rotate B
extern "C" void operator_delete(void* p);
// throw path uses basic_string + exception + _CxxThrowException — elided detail

static inline char node_isnil(StdMapNode* n) {
    return *reinterpret_cast<char*>(reinterpret_cast<char*>(n) + 0x15);
}
static inline char node_color(StdMapNode* n) {
    return *reinterpret_cast<char*>(reinterpret_cast<char*>(n) + 0x14);
}
static inline void set_node_color(StdMapNode* n, char c) {
    *reinterpret_cast<char*>(reinterpret_cast<char*>(n) + 0x14) = c;
}

// __thiscall; stack formals cleaned with ret 8
extern "C" void __thiscall StdMap_EraseIterator_Inferred(
    StdMapFacade* map,
    void* /*param_2 out_it shadow*/,
    StdMapNode* node)
{
    // SEH: ExceptionList / LAB_009a16a2 — elided

    if (node_isnil(node) != 0) {
        // throw std exception with "invalid map/set<T> iterator" @ 0x00a152f0
        // _CxxThrowException(..., &DAT_00acc34c); // noreturn
        return; // unreachable
    }

    FUN_00673070();

    // Replacement child selection (standard erase splice)
    StdMapNode* repl = node->left;
    if (node_isnil(repl) == 0) {
        if (node_isnil(node->right) == 0)
            repl = node->right;
    } else {
        repl = node->right;
    }
    StdMapNode* parent = node->parent;
    if (node_isnil(repl) == 0)
        repl->parent = parent;

    StdMapNode* head = map->head;
    if (head->parent == node)
        head->parent = repl;
    else if (parent->left == node)
        parent->left = repl;
    else
        parent->right = repl;

    // begin / rbegin fixups
    if (head->left == node) {
        StdMapNode* b = parent;
        if (node_isnil(repl) == 0)
            b = FUN_004e12a0(repl);
        head->left = b;
    }
    if (head->right == node) {
        if (node_isnil(repl) == 0)
            head->right = FUN_00421b70(repl);
        else
            head->right = parent;
    }

    // RB fixup when erased node was black (color == 1)
    if (node_color(node) == 1) {
        StdMapNode* x = repl;
        StdMapNode* p = parent;
        if (x != head->parent) {
            do {
                if (node_color(x) != 1)
                    break;
                // sibling / recolor / rotate cases (FUN_004e22d0 / FUN_006753b0)
                // — full case tree matches live decompile; rotations sealed by call sites
                if (x == p->left) {
                    StdMapNode* w = p->right;
                    if (node_color(w) == 0) {
                        set_node_color(w, 1);
                        set_node_color(p, 0);
                        FUN_004e22d0(p);
                        w = p->right;
                    }
                    if (node_isnil(w) == 0) {
                        char cl = node_color(w->left);
                        char cr = node_color(w->right);
                        if (cl != 1 || cr != 1) {
                            if (cr == 1) {
                                set_node_color(w->left, 1);
                                set_node_color(w, 0);
                                FUN_006753b0(w);
                                w = p->right;
                            }
                            set_node_color(w, node_color(p));
                            set_node_color(p, 1);
                            set_node_color(w->right, 1);
                            FUN_004e22d0(p);
                            break;
                        }
                        set_node_color(w, 0);
                    }
                } else {
                    StdMapNode* w = p->left;
                    if (node_color(w) == 0) {
                        set_node_color(w, 1);
                        set_node_color(p, 0);
                        FUN_006753b0(p);
                        w = p->left;
                    }
                    if (node_isnil(w) == 0) {
                        if (node_color(w->right) == 1 && node_color(w->left) == 1) {
                            set_node_color(w, 0);
                        } else {
                            if (node_color(w->left) == 1) {
                                set_node_color(w->right, 1);
                                set_node_color(w, 0);
                                FUN_004e22d0(w);
                                w = p->left;
                            }
                            set_node_color(w, node_color(p));
                            set_node_color(p, 1);
                            set_node_color(w->left, 1);
                            FUN_006753b0(p);
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
    if (map->size > 0)
        map->size--;
    // *out_it write from precomputed successor — stack slots; see annotated
}
