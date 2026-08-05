# Review A (reconstruction fidelity): `aa_0054eb20` SkillElementTypeMap_InsertOrFind

| Field | Value |
|---|---|
| **Stable ID** | `aa_0054eb20` |
| **VA** | `0x0054eb20` |
| **Body** | `0x0054eb20`–`0x0054ebd7` (three `ret 8`) |
| **Canonical name** | `SkillElementTypeMap_InsertOrFind` (Ghidra `FUN_0054eb20`; **Inferred**) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_0054eb20_SkillElementTypeMap_InsertOrFind.md` |
| **System** | `skills-abilities` (skill-element type factory catalog) |
| **Live tools** | Ghidra `decompile_function` + `read_memory` (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

MSVC-style **`std::map` insert-or-find** for an **int-keyed** red-black tree whose mapped value is a **pointer** (node size **0x18**, isnil **`+0x15`**).

```
pair{it, inserted} = SkillElementTypeMap_InsertOrFind(map, {typeId, factory*})
// __thiscall; this = map shell; RET 0x8 (two stack dwords)
```

Walks from root `*( *(this+4) + 4 )` comparing search key against **`node+0x0C`**, using nil flag **`node+0x15`**. On miss, inserts via `FUN_0054de50` (allocate + rebalance; throws `"map/set<T> too long"`). On equal key, returns existing iterator with **`inserted=0`** and **does not** rewrite the mapped pointer.

Only static caller: `SkillElementFactory_RegisterCatalog` (`0x0054a640`) — **39** registration arms inserting sequential type ids → factory instances.

Shared CF pattern with `Map_InsertOrFind_IntKey` (`0x005d2360`) but **different insert helper** (`0054de50` vs `005d20b0`) and domain (skill-element catalog vs AI post-cast timers). Same isnil `+0x15` / size `0x18` family; shared predecessor `FUN_005a2850`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0054eb20_FUN_0054eb20.md` |
| Annotated | `docs/reconstruction/raw/aa_0054eb20_FUN_0054eb20.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/SkillElementTypeMap_InsertOrFind.cpp` |
| Function record | `docs/reconstruction/functions/aa_0054eb20_SkillElementTypeMap_InsertOrFind.md` |
| Fresh decompile | Ghidra `decompile_function` @ `0x0054eb20` (2026-07-29) — body ≡ raw |
| Bytes | `read_memory` 200 B @ `0x0054eb20` — three `C2 08 00`; isnil `80 78 15 00`; out `C6 40 04 0\|1` |
| Insert helper | `FUN_0054de50` — size check + `"map/set<T> too long"` + rebalance (color `+0x14`); node via `FUN_006173a0` |
| Predecessor | `FUN_005a2850` — tree predecessor only (no alloc) |
| Caller | `SkillElementFactory_RegisterCatalog` @ `0x0054a640` (39 UNCONDITIONAL_CALL xrefs) |
| Parent dual | `A_aa_0054a640_SkillElementFactory_RegisterCatalog_Inferred` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__thiscall` + **`RET 0x8`** (2 stack dwords) | **Confirmed** | three epilogues `C2 08 00` |
| Signature `(map this, InsertPair* out, Value* val)` | **High** | ECX=map; out written; key from `*val` |
| Out pair `{node* @+0, inserted @+4}` | **Confirmed** | `mov [eax],…` / `mov byte [eax+4],0\|1` |
| Map shell `+4` = head / end; `+8` = size (via insert) | **High** | body + `FUN_0054de50` size++ / throw |
| Nil flag **`node+0x15 == 0`** means real node | **Confirmed** | decompile + `cmp byte [reg+0x15],0` |
| Key int at **`node+0x0C`** | **Confirmed** | decompile + key cmp |
| Mapped pointer at **`node+0x10`** | **High** | node ctor copies 2 dwords; catalog stores factory* |
| Color **`+0x14`**, isnil **`+0x15`**, size **0x18** | **Confirmed** | insert helper + `FUN_006173a0` family |
| Left `*node`, parent `node+4`, right `node+8` | **Confirmed** | walk |
| Insert-or-find CF (miss→insert; equal→find) | **Confirmed** | three-exit structure |
| Equal key: **no** value rewrite | **Confirmed** | third path only stores out-pair |
| `FUN_0054de50` = tree insert + rebalance | **High** | `"map/set<T> too long"`; size++; rotations |
| `FUN_005a2850` = **predecessor**, not insert | **High** | body walks parent/leftmost only |
| Sole static caller catalog register | **Confirmed** | xrefs / callers |
| Domain: skill-element type factory map | **High** | parent dual + 39 type-id inserts |
| Product STL / RTTI name | **Open** | no PDB; structural + domain name |
| Runtime / bit-exact image diff | **Open** | matrix policy |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Load head `*(this+4)`; root = head[1] | Yes |
| Walk by key; isnil `+0x15`; left/right | Yes |
| goLeft + parent==leftmost → insert(side=1) → `{it,1}` | Yes |
| goLeft + not leftmost → predecessor | Yes |
| parent.key < key → insert(side=goLeft) → `{it,1}` | Yes |
| else equal → `{parent,0}` no value write | Yes |
| `RET 0x8` all three exits | Yes |

### Recovered CF

```c
// void __thiscall SkillElementTypeMap_InsertOrFind(MapShell *this, InsertPair *pOut, const IntPtrPair *pVal)
Node *parent = this->_Myhead;
bool goLeft = true;
if (parent->_Parent->_Isnil == 0) {
  Node *cur = parent->_Parent;
  do {
    parent = cur;
    goLeft = (pVal->key < parent->_Key);
    cur = goLeft ? parent->_Left : parent->_Right;
  } while (cur->_Isnil == 0);
}
if (goLeft) {
  if (parent == this->_Myhead->_Left) {
    pOut->it = TreeInsertAndRebalance(this, parent, /*insertLeft*/1, pVal); // FUN_0054de50
    pOut->inserted = 1;
    return;
  }
  TreePredecessor(&parent); // FUN_005a2850
}
if (parent->_Key < pVal->key) {
  pOut->it = TreeInsertAndRebalance(this, parent, goLeft, pVal);
  pOut->inserted = 1;
  return;
}
pOut->it = parent;
pOut->inserted = 0; // mapped UNCHANGED
```

---

## 5. Asm-sealed signature + layouts

```c
struct IntPtrPair {
    int32_t key;   // skill-element type id
    void *mapped;  // factory instance*
};

struct MapNode_IntPtr { // size 0x18
    MapNode_IntPtr* left;    // +0x00
    MapNode_IntPtr* parent;  // +0x04
    MapNode_IntPtr* right;   // +0x08
    int32_t  key;            // +0x0C
    void*    mapped;         // +0x10
    uint8_t  color;          // +0x14
    uint8_t  isnil;          // +0x15
};

struct InsertPair {
    MapNode_IntPtr* it; // +0
    uint8_t inserted;   // +4
};

void __thiscall SkillElementTypeMap_InsertOrFind(
    MapShell* this,
    InsertPair* pOut,
    const IntPtrPair* pVal);
// RET 0x8
```

### Callees (roles sealed; product names open)

| VA | Role |
|---|---|
| `0x0054de50` | Tree insert + RB rebalance; may throw `"map/set<T> too long"` |
| `0x005a2850` | Tree predecessor (in-order previous) |
| `0x006173a0` (via insert) | Node construct `new(0x18)` + copy 2-dword value |

### Callers

| Caller | Sites | Role |
|---|---|---|
| `SkillElementFactory_RegisterCatalog` | 39 in `0x0054a640` | Register type-id → factory instance |

No other static xrefs in image (this dual pass).

---

## 6. Gaps / open

1. Product / RTTI name for the map type.
2. Optional dual of helpers `FUN_0054de50` / `FUN_005a2850` (W19-N owns `005a2850`).
3. Dynamic/fn-ptr call sites residual.
4. Runtime / bit-exact image diff (deferred).
5. Full map-shell field at `+0x00` (allocator) not read by this body.

**Verdict:** **accept-with-gaps** — ABI, out-pair, node **0x18** layout, insert-or-find CF, helper roles, sole catalog caller, no-update-on-equal **sealed High/Confirmed**; product name + runtime/diff remain.
