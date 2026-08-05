# Review A (reconstruction fidelity): `aa_005d2360` Map_InsertOrFind_IntKey

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d2360` |
| **VA** | `0x005d2360` |
| **Canonical name** | `Map_InsertOrFind_IntKey` |
| **Review date** | `2026-07-29` (dual seal; prior 2026-07-23 scaffold) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005d2360_Map_InsertOrFind_IntKey.md` |
| **System** | `skills-abilities` (NPC AI post-cast timer map; only static caller) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

MSVC-style **`std::map` insert-or-find** for an **int-keyed** red-black tree whose mapped value is a second **int** (node size **0x18**).

```
pair{it, inserted} = Map_InsertOrFind_IntKey(map, {key, value})
// __thiscall; this = map shell; RET 0x8 (two stack dwords)
```

Walks from root `*( *(this+4) + 4 )` comparing search key against **`node+0x0C`**, using nil flag **`node+0x15`**. On miss, inserts via `FUN_005d20b0` (allocate + rebalance; throws `"map/set<T> too long"`). On equal key, returns existing iterator with **`inserted=0`** and **does not** rewrite the mapped value.

Only static caller: `NPC_TryCastSkillFromSet` @ `0x005d18f7` on AI controller map shell **`this+0x98`**, writing post-cast deadline `{nSkillSetIndex, g_dwClientTickMs + wUsPostCastDelayMs}`. Sibling erase is `Map_EraseNode_IntKey` (`0x005d1df0`); sibling lower_bound used at entry is `Map_LowerBoundFindByIntKey` (same `+0x15` family).

Shared CF pattern with `Skill_CategoryCooldownMap_Insert` (`0x0051d2f0`) but **different node layout** (this unit: isnil `+0x15`, size `0x18`; category CD: isnil `+0x19`, size `0x1C`).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005d2360_Map_InsertOrFind_IntKey.md` |
| Annotated | `docs/reconstruction/raw/aa_005d2360_Map_InsertOrFind_IntKey.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Map_InsertOrFind_IntKey.cpp` |
| Function record | `docs/reconstruction/functions/aa_005d2360_Map_InsertOrFind_IntKey.md` |
| Fresh decompile | Ghidra `decompile_function` @ `0x005d2360` (2026-07-29) — body ≡ raw |
| Complete analysis | Ghidra `analyze_function_complete` — 1 xref, callees `FUN_005d20b0`, `FUN_005a2850` |
| Bytes | `read_memory` 200 B @ `0x005d2360` — three `C2 08 00`; isnil `80 78 15 00`; key `3B 50 0C`; out `C6 40 04 0/1` |
| Node ctor | `FUN_006173a0` @ `0x006173a0`: `push 0x18` / `operator_new(0x18)`; copies 2 dwords from value*; color `+0x14`; isnil `+0x15=0` |
| Insert helper | `FUN_005d20b0` — size check + `"map/set<T> too long"` + rebalance (color `+0x14`) |
| Predecessor | `FUN_005a2850` — tree predecessor only (no alloc) |
| Caller | `NPC_TryCastSkillFromSet` @ `0x005d1280` site `0x005d18f7` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__thiscall` + **`RET 0x8`** (2 stack dwords) | **Confirmed** | three epilogues `C2 08 00` @ `+0x6E`, `+0xA5`, `+0xB6` |
| Signature `(map this, InsertPair* out, Value* val)` | **High** | prolog loads arg2 into EBP as key source; out written via arg1; Ghidra phantom 3rd stack `pKey` **unused** |
| Out pair `{node* @+0, inserted @+4}` | **Confirmed** | `mov [eax],…` / `mov byte [eax+4],0\|1` |
| Map shell `+4` = head / end; `+8` = size (via insert helper) | **High** | body + `FUN_005d20b0` size++ / throw |
| Nil flag **`node+0x15 == 0`** means real node | **Confirmed** | decompile + `cmp byte [reg+0x15],0` |
| Key int at **`node+0x0C`** (`node[3]`) | **Confirmed** | decompile + `cmp edx,[eax+0xc]` |
| Mapped value int at **`node+0x10`** | **High** | node ctor copies `param_4[0]`→`+0x0C`, `param_4[1]`→`+0x10`; caller stores deadline adjacent after key |
| Color **`+0x14`**, isnil **`+0x15`** | **Confirmed** | ctor + rebalance helper |
| Node size **0x18** | **Confirmed** | `operator_new(0x18)` in `FUN_006173a0` |
| Left `*node`, parent `node+4`, right `node+8` | **Confirmed** | walk + ctor link stores |
| Insert-or-find CF (miss→insert; equal→find) | **Confirmed** | body three-exit structure |
| Equal key: **no** value rewrite (`inserted=0`) | **Confirmed** | third path only stores out-pair |
| `FUN_005d20b0` = tree insert + rebalance | **High** | `"map/set<T> too long"`; size++; rotations |
| `FUN_005a2850` = **predecessor**, not insert | **High** | body walks parent/leftmost only |
| Only one static caller (`NPC_TryCastSkillFromSet`) | **Confirmed** | xrefs / callers tools |
| Domain: AI skill-set post-cast timer map @ `+0x98` | **High** | caller plate + lower_bound/erase on same shell |
| Product STL / RTTI name | **Open** | no PDB; structural name only |
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
// void __thiscall Map_InsertOrFind_IntKey(MapShell *this, InsertPair *pOut, const IntPair *pVal)
// IntPair = { int32 key; int32 mapped; }  // 8 bytes consumed by node ctor
Node *parent = this->_Myhead;              // *(this+4)
bool goLeft = true;
if (parent->_Parent->_Isnil == 0) {        // root; isnil +0x15
  Node *cur = parent->_Parent;
  do {
    parent = cur;
    goLeft = (pVal->key < parent->_Key);   // key +0x0C
    cur = goLeft ? parent->_Left : parent->_Right;
  } while (cur->_Isnil == 0);
}
if (goLeft) {
  if (parent == this->_Myhead->_Left) {    // leftmost
    pOut->it = TreeInsertAndRebalance(this, /*hint*/parent, /*insertLeft*/1, pVal);
    pOut->inserted = 1;
    return;
  }
  TreePredecessor(&parent);                // FUN_005a2850
}
if (parent->_Key < pVal->key) {
  pOut->it = TreeInsertAndRebalance(this, parent, goLeft, pVal); // FUN_005d20b0
  pOut->inserted = 1;
  return;
}
pOut->it = parent;                         // exact key hit
pOut->inserted = 0;                        // mapped value UNCHANGED
```

---

## 5. Asm-sealed signature + layouts

```c
struct IntPair {
    int32_t key;     // e.g. nSkillSetIndex
    int32_t mapped;  // e.g. post-cast deadline tick (g_dwClientTickMs + delay)
};

struct MapNode_IntInt { // size 0x18
    MapNode_IntInt* left;    // +0x00
    MapNode_IntInt* parent;  // +0x04
    MapNode_IntInt* right;   // +0x08
    int32_t  key;            // +0x0C
    int32_t  mapped;         // +0x10
    uint8_t  color;          // +0x14
    uint8_t  isnil;          // +0x15
};

struct InsertPair {
    MapNode_IntInt* it; // +0
    uint8_t inserted;   // +4
};

struct MapShell { // size 0x0C typical
    // +0x00 allocator / pad (not read here)
    MapNode_IntInt* _Myhead; // +0x04 end/head sentinel
    uint32_t        _Mysize; // +0x08
};

void __thiscall Map_InsertOrFind_IntKey(
    MapShell* this,
    InsertPair* pOut,
    const IntPair* pVal);
// RET 0x8
```

### Callees (roles sealed; product names open)

| VA | Role |
|---|---|
| `0x005d20b0` | Tree insert + RB rebalance; may throw `"map/set<T> too long"` |
| `0x005a2850` | Tree predecessor (in-order previous) |
| `0x006173a0` (via insert) | Node construct `new(0x18)` + copy 2-dword value |

### Callers

| Caller | Site | Role |
|---|---|---|
| `NPC_TryCastSkillFromSet` | `0x005d18f7` | After successful cast: insert post-cast timer for skill-set index into map @ AI `+0x98` |

No other xrefs in image (this dual pass).

---

## 6. Gaps / open

1. Ghidra parameter names still show unused phantom `pKey` and mislabel first stack as `pMap` — ABI sealed by `RET 0x8` + body; optional prototype fix in Ghidra.
2. Optional rename of helpers `FUN_005d20b0` / `FUN_005a2850` / `FUN_006173a0` to product English names.
3. Whether any **dynamic** call (vtbl/fn-ptr) reaches this VA — static xrefs only.
4. Runtime / bit-exact image diff (deferred).
5. Full map-shell field at `+0x00` (allocator) not read by this body.

**Verdict:** **accept-with-gaps** — ABI, out-pair, node **0x18** layout, insert-or-find CF, helper roles, single caller, no-update-on-equal **sealed High/Confirmed**; Ghidra param naming noise + runtime/diff remain.
