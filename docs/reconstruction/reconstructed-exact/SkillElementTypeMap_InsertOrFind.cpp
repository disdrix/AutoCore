// =============================================================================
// SkillElementTypeMap_InsertOrFind
// -----------------------------------------------------------------------------
// Stable ID: aa_0054eb20
// Address:   0x0054eb20  (autoassault.exe, image base 0x400000)
// Body:      0x0054eb20–0x0054ebd7 (three ret 8)
// System:    skills-abilities (skill-element type → factory instance map)
// Generated: 2026-07-29 dual W19-L (raw 2026-07-23 + live re-decompile)
// Exactness: Behavior-preserving reconstruction of decompiler CF + byte ABI seals.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE: MSVC-style std::map insert-or-find for int type-id keys and pointer
// mapped values (RB node size 0x18, isnil +0x15). On miss inserts via
// FUN_0054de50 (rebalance; may throw "map/set<T> too long"). On equal key
// returns existing iterator with inserted=0 and does NOT rewrite mapped.
//
// Sole static caller: SkillElementFactory_RegisterCatalog @ 0x0054a640 (39 sites).
// Shared predecessor helper: FUN_005a2850. Sibling CF twin: Map_InsertOrFind_IntKey
// @ 0x005d2360 (different insert helper FUN_005d20b0 / AI post-cast domain).
//
// =============================================================================

#include <cstdint>

// Forward decls — roles sealed; product names open
extern void *FUN_0054de50(void *pOutNode, char insertLeft, void *parent, const void *pVal);
extern void FUN_005a2850(void); // tree predecessor (mutates parent in caller's frame)

struct IntPtrPair {
    std::int32_t key;   // skill-element type id
    void *mapped;       // factory instance*
};

struct InsertPair {
    void *it;                 // node*
    std::uint8_t inserted;    // @+4
};

struct MapNode_IntPtr { // size 0x18
    MapNode_IntPtr *left;    // +0x00
    MapNode_IntPtr *parent;  // +0x04
    MapNode_IntPtr *right;   // +0x08
    std::int32_t key;        // +0x0C
    void *mapped;            // +0x10
    std::uint8_t color;      // +0x14
    std::uint8_t isnil;      // +0x15
};

struct MapShell {
    // +0x00 allocator / pad (not read by this body)
    MapNode_IntPtr *_Myhead; // +0x04
    std::uint32_t _Mysize;   // +0x08 (via insert helper)
};

// void __thiscall — RET 0x8
void __thiscall SkillElementTypeMap_InsertOrFind(
    MapShell *self,
    InsertPair *pOut,
    const IntPtrPair *pVal)
{
    MapNode_IntPtr *parent = self->_Myhead;
    bool goLeft = true;

    if (parent->parent->isnil == 0) {
        MapNode_IntPtr *cur = parent->parent; // root
        do {
            parent = cur;
            goLeft = (pVal->key < parent->key);
            cur = goLeft ? parent->left : parent->right;
        } while (cur->isnil == 0);
    }

    if (goLeft) {
        if (parent == self->_Myhead->left) {
            // insert as left child of leftmost (empty-side / begin)
            void *insertedNode =
                FUN_0054de50(&parent, /*insertLeft*/ 1, parent, pVal);
            pOut->it = *reinterpret_cast<void **>(insertedNode);
            pOut->inserted = 1;
            return;
        }
        FUN_005a2850(); // predecessor(&parent) — decompiler elides arg
    }

    if (parent->key < pVal->key) {
        void *insertedNode =
            FUN_0054de50(&parent, static_cast<char>(goLeft), parent, pVal);
        pOut->it = *reinterpret_cast<void **>(insertedNode);
        pOut->inserted = 1;
        return;
    }

    // equal key — find only
    pOut->it = parent;
    pOut->inserted = 0;
}
