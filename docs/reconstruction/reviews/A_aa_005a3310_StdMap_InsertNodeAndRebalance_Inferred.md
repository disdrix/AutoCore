# Review A (reconstruction fidelity): `aa_005a3310` StdMap_InsertNodeAndRebalance_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005a3310` |
| **VA** | `0x005a3310` |
| **Body end** | `add esp,0x50` / `ret 0x10` (~`0x005a34f8`) |
| **Canonical name** | `StdMap_InsertNodeAndRebalance_Inferred` |
| **Ghidra name** | `FUN_005a3310` |
| **Prior names** | `FUN_005a3310` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_005a3310_StdMap_InsertNodeAndRebalance_Inferred.md` |
| **System** | container / MSVC `std::map` / GhostNet spatial index |
| **Live tools** | Ghidra `batch_decompile`, `read_memory`, callers, node ctor `005a2de0` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

MSVC-style **`std::map`/`set` node insert + red-black rebalance** core. Called only from public insert-or-find front `StdMap_InsertOrFind_PairKey_Inferred` (`0x005a3b00`) after the tree walk decides a missing key must be inserted.

String-seals family: throws **`"map/set<T> too long"`** when `size > 0x0AAAAAA8`.

### Control flow

1. SEH frame `LAB_009a6342`.
2. **Size guard:** if `*(uint*)(map+8) > 0x0AAAAAA8` → construct `std::string` `"map/set<T> too long"`, wrap `std::length_error`-style exception (`PTR_FUN_009c7628` / `009c7634`), `_CxxThrowException` (noreturn).
3. **Allocate/link node:** `FUN_005a2de0(header, parent, header, keyPayload, color0)` → `operator_new(0x30)` node:
   - links `[0]=left?`, `[1]=parent`, `[2]=right` pattern from args  
   - copies **6 dwords** from key payload into `node[4..9]`  
   - color byte at `node+0x28` (`puVar1+10`), nil flag `+0x29 = 0`.
4. `map->size++` (`*(map+8)++`).
5. **Attach under parent** (`param_4`):
   - If parent is header: set header left/parent/right extremes to new node.
   - Else if `side==0` (`param_3==0`): `parent->right = new`; update header right-most if needed.
   - Else: `parent->left = new`; update header left-most if needed.
6. **RB fixup loop** while parent color at `parent+0x28` is red (`==0` in this encoding — decompiler tests `cVar1 != '\0'` for black stop):
   - Uncle red → recolor parent/uncle black, grandparent red; climb.
   - Uncle black → rotate (`FUN_004192a0` / `FUN_004192f0`) + recolor; includes inlined left-rotate tail.
7. Force root black: `header->parent (+4 of header path) +0x28 = 1`.
8. `*outNode = newNode`; return.

**Sole live caller:** `FUN_005a3b00`.

**Not** the walk/compare (that is `005a3b00`), not erase, not lower_bound-only.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Function record | `docs/reconstruction/functions/aa_005a3310_FUN_005a3310.md` |
| Raw / annotated / clean | `aa_005a3310_*` / `FUN_005a3310.cpp` |
| Live decompile | Ghidra `0x005a3310` (2026-07-29) — **≡ scaffold CF** |
| Prologue | `read_memory`: `MOV EDI,ECX` + size cmp `CMP [EDI+8], 0x0AAAAAA9` pattern |
| Epilogue | `ret 0x10` (4 stack formals) |
| Node ctor | live `FUN_005a2de0` — `new(0x30)`, key copy 6 dwords, `+0x28` color, `+0x29` nil |
| Front dual | `A\|B_aa_005a3b00_StdMap_InsertOrFind_PairKey_Inferred` |
| GhostNet caller | `A\|B_aa_005a0b30_GhostNet_SpatialIndexInsert` |

---

## 3. Signature / layout

```c
// __thiscall map; ret 0x10
void __thiscall StdMap_InsertNodeAndRebalance_Inferred(
    Map *map,            // this — +4 header*, +8 size
    Node **outNode,      // param_2 — receives new node*
    char insertLeft,     // param_3 — 1=left child, 0=right
    Node *parent,        // param_4 — attach under (or header)
    uint *keyPayload);   // param_5 — at least 6 dwords copied into node
```

| Offset | Role |
|---|---|
| map `+4` | header / end sentinel node* |
| map `+8` | element count |
| node `+0..+8` | left / parent / right (pointer triple) |
| node `+0x10..` | key/value payload (6 dwords from ctor) |
| node `+0x28` | RB color byte |
| node `+0x29` | nil leaf flag (0 = real node) |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| map/set insert + RB rebalance | **Confirmed** | string + loop |
| Size throw `"map/set<T> too long"` | **Confirmed** | |
| Node size 0x30 via `005a2de0` | **Confirmed** | |
| Color at `+0x28`, nil at `+0x29` | **Confirmed** | ctor + body |
| Side flag left vs right attach | **Confirmed** | |
| ABI thiscall `ret 0x10` | **Confirmed** | |
| Sole caller `005a3b00` | **High** | |
| Clean ≡ raw ≡ live | **Confirmed** | |
| Color polarity 0=red/1=black English | **High** | MSVC tree convention; root forced 1 |
| Payload field English beyond pair key | **Tentative** | GhostNet packs 5–6 dwords |

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Size overflow throw | **Yes** |
| Alloc + size++ + link | **Yes** |
| RB recolor/rotate loop | **Yes** |
| Out store new node | **Yes** |

---

## 6. Gaps / open

1. Full 6-dword payload schema (pair key + GhostNet value fields).
2. Rotate helper product names (`004192a0`/`004192f0`).
3. Runtime stress (size throw path).

**Verdict:** **accept-with-gaps** — insert/rebalance CF **Confirmed**; payload English residual.
