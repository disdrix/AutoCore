# Review A (reconstruction fidelity): `aa_005a3b00` StdMap_InsertOrFind_PairKey_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005a3b00` |
| **VA** | `0x005a3b00` |
| **Body** | `0x005a3b00`–`0x005a3bd2` |
| **Canonical name** | `StdMap_InsertOrFind_PairKey_Inferred` |
| **Ghidra name** | `FUN_005a3b00` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_005a3b00_StdMap_InsertOrFind_PairKey_Inferred.md` |
| **System** | container / GhostNet spatial index (caller `GhostNet_SpatialIndexInsert`) |
| **Live tools** | Ghidra `batch_decompile`, `read_memory`, callers/callees |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

MSVC-style **`std::map` insert-or-find** for an ordered **pair key** stored as two dwords on the node (`node[4]` = lo, `node[5]` = hi as signed/unsigned dual compare).

`__thiscall` on the map object; stack formals cleaned with **`ret 8`**:

```c
// this = map*; out = { node*, inserted_bool at out+4 }; key = at least 2 dwords (hi/lo order key)
void __thiscall StdMap_InsertOrFind_PairKey_Inferred(
    Map *this, void *outPair /* node* + bool */, uint *pKey /* key[0]=lo, key[1]=hi */);
```

1. Start at root `*(this+4)` → parent pointer `root[1]`.
2. Walk while child nil-flag `*(char*)(child+0x29) == 0`:
   - Order: prefer **right** when `node[5] < key[1]` **or** (`node[5] <= key[1]` **and** `node[4] <= key[0]`); else **left**.
   - Track `goLeft` / insert-side flag (`local_4`: 1=left, 0=right).
3. After walk: if came from left path and landed on left-most sentinel (`node == **(this+4)`), **insert** via `FUN_005a3310(..., 1, node, key)` → out `{node*, inserted=1}`.
4. Else if on left path: `FUN_004cb4f0` **predecessor step** on the candidate iterator.
5. If candidate key is **strictly less** than request (`node[5] < key[1]` or equal hi and `node[4] < key[0]`), **insert** via `FUN_005a3310(..., side, node, key)` → out `{node*, inserted=1}`.
6. Else **found equal** (or not less): out `{node*, inserted=0}`.

Insert helper `FUN_005a3310` throws **`"map/set<T> too long"`** on size overflow and rebalances (RB colors at `+0x28`).

**Sole live caller:** `GhostNet_SpatialIndexInsert` `0x005a0b30` (packs 4 dwords + object* then calls this).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Function record | `docs/reconstruction/functions/aa_005a3b00_FUN_005a3b00.md` |
| Raw / annotated | `docs/reconstruction/raw/aa_005a3b00_FUN_005a3b00*.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_005a3b00.cpp` |
| Live decompile | Ghidra `batch_decompile` `0x005a3b00` (2026-07-29) — **≡ raw CF** |
| Body bytes | `read_memory 0x005a3b00` length 160; epilogue **`ret 8`** |
| Insert | `FUN_005a3310` — `"map/set<T> too long"` + RB fixup |
| Pred | `FUN_004cb4f0` — tree iterator bidir step (nil `+0x29`) |
| Caller dual | `A\|B_aa_005a0b30_GhostNet_SpatialIndexInsert` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Role: map insert-or-find (not erase) | **Confirmed** | insert helper + inserted bool |
| Pair-key compare on `node[4]`/`node[5]` vs `key[0]`/`key[1]` | **Confirmed** | body |
| Nil leaf flag at `+0x29` | **Confirmed** | walk predicate |
| Color / RB sibling work in insert at `+0x28` | **High** | `005a3310` |
| Out pair: `*out = node*`, `*(bool*)(out+4) = inserted` | **Confirmed** | stores |
| ABI: thiscall + 2 stack args, `ret 8` | **Confirmed** | bytes |
| Clean ≡ raw ≡ live CF | **Confirmed** | scaffold identity |
| Product English “spatial” | **Probable** | caller only; this unit is generic map |
| Full key payload layout beyond lo/hi | **Medium** | insert stores `param_5`; caller packs 5 dwords |
| Map host identity at call sites | **Open** | `005a0b30` does not seal ECX (global vs outer this) |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Root walk with pair-key order | **Yes** |
| Left-most → insert side=1 | **Yes** |
| Else pred step `004cb4f0` | **Yes** |
| Key strictly less → insert with recorded side | **Yes** |
| Else found → inserted=0 | **Yes** |
| No free / no network | **Yes** |

### Recovered CF (behavioral)

```c
// Order: (hi, lo) with hi signed-ish dual + lo unsigned on ties
// node slots: [0]=left, [1]=parent, [2]=right, [4]=keyLo, [5]=keyHi, +0x29=nil
void Map_InsertOrFind(Map *m, Out *out, uint *key) {
  Node *n = *(Node **)(m + 4);          // header
  Node *cur = (Node *)n[1];             // root
  int goLeft = 1;
  if (*(char *)((int)cur[1] /*?*/ + 0x29) == 0) { /* decomp: check child nil via walk */
    // walk until nil child; update goLeft / side
  }
  if (goLeft) {
    if (cur == **(Node ***)(m + 4)) {   // begin
      insert(out, side=1, cur, key); out->inserted = 1; return;
    }
    pred(&cur);                          // FUN_004cb4f0
  }
  if (cur->keyHi < key[1] || (cur->keyHi == key[1] && cur->keyLo < key[0])) {
    insert(out, side, cur, key); out->inserted = 1; return;
  }
  out->node = cur; out->inserted = 0;
}
```

---

## 5. Layout (node / map)

| Offset | Role |
|---|---|
| map `+4` | header / end sentinel node* |
| map `+8` | size (checked in insert) |
| node `+0/+4/+8` | left / parent / right |
| node `+0x10/+0x14` | keyLo / keyHi (`[4]`/`[5]`) |
| node `+0x28` | color (RB, insert) |
| node `+0x29` | nil / is-header leaf flag |

---

## 6. Gaps

1. Seal map **this** at `GhostNet_SpatialIndexInsert` (global DAT vs ghost manager member).
2. Whether key dwords `[0]/[1]` are TFID vs spatial hash — compare sealed; English open.
3. Full node value layout for remaining key payload after lo/hi.
4. Runtime / bit-for-bit deferred.

**Verdict:** **accept-with-gaps** — CF + pair-key order + insert/find polarity sealed; map host and key English residual.
