# Review A (reconstruction fidelity): `aa_00537770` Map predecessor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00537770` |
| **VA** | `0x00537770` |
| **Canonical name** | `FUN_00537770` (structural: **Map / `_Tree` predecessor**, iterator decrement) |
| **Inferred role** | MSVC-style ordered-tree **bidirectional iterator `--`** (in-place on `Node**`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw + bytes) |
| **Counterpart** | `reviews/B_aa_00537770_Map_Predecessor.md` |
| **System** | shared map/tree helper (callers: mission staging insert + sibling isnil`+0x49` maps) |
| **Dual status** | **Present — sealed 2026-07-29** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

`__fastcall` **leaf** helper: `void Map_Tree_Predecessor(Node** pIt)` with **`ECX = pIt`**.

Classic MSVC `_Tree` / `std::map` **iterator decrement** for nodes whose **isnil** flag lives at **`node+0x49`** and child/parent links are:

| Offset | Field |
|---|---|
| `+0x00` | left* |
| `+0x04` | parent* |
| `+0x08` | right* |
| `+0x49` | isnil (u8); non-zero ⇒ head/end sentinel |

Control flow (sealed):

1. **`cur = *pIt`**. If **`cur->isnil`**: `*pIt = cur->right` (end → rightmost / max) and return.
2. Else if **`cur->left` is not isnil**: set `*pIt` to **rightmost** of the left subtree (walk `right` while right not isnil).
3. Else climb parents: while parent not isnil and `cur == parent->left`, step to parent; if final parent not isnil, `*pIt = parent`.

**No** allocation, rebalance, key compare, color touch, or map-shell access. Pure link walk.

Used by insert-or-find units when the walk last stepped **left** and parent is **not** the leftmost child of head — predecessor supplies the previous in-order node for the “parent.key < key?” gate (e.g. `FUN_00539cb0`).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00537770_FUN_00537770.md` |
| Annotated | `docs/reconstruction/raw/aa_00537770_FUN_00537770.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00537770.cpp` |
| Function record | `docs/reconstruction/functions/aa_00537770_FUN_00537770.md` |
| Fresh decompile | Ghidra `decompile_function` @ `0x00537770` (2026-07-29) — CF ≡ raw 2026-07-23 |
| Body image | Ghidra `read_memory` @ `0x00537770` length 160 — leaf (`C3` rets, **no `E8` CALL**); isnil `cmp byte [reg+0x49],0` |
| Callers | Ghidra `get_function_callers`: `FUN_00539cb0`, `FUN_00569320`, `FUN_00569560` |
| Callees | **none** (leaf) |
| Parent insert dual | `A\|B_aa_00539cb0_MissionStagingMap_Insert` — predecessor role High |
| Sibling insert (same isnil) | `FUN_00569320` key @ `node[3]` (`+0x0C`); still calls this unit |
| Wave tag | `WAVE_2026-07-29_wave5_partition_map.md` — “Map predecessor” |

**Not performed:** `disassemble_bytes`, Launcher, runtime capture, binary image diff.

---

## 3. Evidence table

| Claim | Evidence | Confidence |
|---|---|---|
| `__fastcall(Node** pIt)` via **ECX**; **no stack args** | Body starts `mov eax,[ecx]`; all exits **`C3`** (not `C2 xx 00`) | **High** |
| void return; mutates `*pIt` only | No EAX product; stores only through `[ecx]` | **High** |
| isnil at **`+0x49`** | Bytes: `80 78 49 00` / `80 7a 49 00` throughout | **High** |
| left `+0`, parent `+4`, right `+8` | `mov edx,[eax]`; `mov eax,[eax+4]`; `mov eax,[eax+8]` | **High** |
| isnil path → right child | `cmp [eax+49],0` / je skip / `mov eax,[eax+8]` / `mov [ecx],eax` / `ret` | **High** |
| left-subtree max via right walk | After load left: loop on `[reg+8]` while not isnil | **High** |
| climb while `cur == parent->left` | `cmp edx,[eax]` (`*pIt` vs `parent->left`); equal → climb | **High** |
| Leaf (no callees) | `get_function_callees` empty; no `E8` in body | **High** |
| Role = **predecessor only** (not insert/rebalance) | Body is link walk only; insert dual already falsified mis-role | **High** |
| Shared by ≥3 map insert/hint units with isnil `+0x49` | Callers list | **High** |
| Key offset **not** fixed by this unit | Staging insert keys `@+0x10`; `FUN_00569320` keys `@+0x0C` | **High** |
| Product English / MSVC template name | No string/RTTI this pass | **Open** |
| Runtime / bit-exact | Not run | **Open** |
| Color offset (sibling maps use `+0x48`) | **Not read** in this body | N/A here |

---

## 4. Sealed layouts (what this unit assumes)

```
// Iterator = Node* held by caller (often stack local Node*)
// This unit: ECX = Node** ; writes *pIt; RET (C3)

TreeNode_Isnil49  // partial — links + isnil only
  +0x00  left*
  +0x04  parent*
  +0x08  right*
  +0x49  isnil (u8)   // 0 = real node; !=0 = head/end sentinel

// Value / key / color layout is CALLER-map specific:
//   Mission staging (aa_00539cb0): key +0x10, color +0x48, size 0x50
//   FUN_00569320 family:          key +0x0C (node[3]), isnil still +0x49
// Predecessor does not touch key/color/payload.
```

---

## 5. Control flow: clean ≡ raw ≡ bytes

| Stage | Match |
|---|---|
| Load `cur = *pIt` from ECX | **Yes** |
| isnil → `*pIt = right`; ret | **Yes** |
| left non-nil → rightmost of left; ret | **Yes** |
| else climb while left-child; maybe set parent | **Yes** |
| No CALL / no map shell / no key cmp | **Yes** |
| Three `C3` return sites in body image | **Yes** |

---

## 6. Callers (OWN boundary = this VA only; listed for context)

| VA | Name | Role re this unit |
|---|---|---|
| `0x00539cb0` | Mission staging map insert | goLeft && not leftmost → predecessor before key gate |
| `0x00569320` | Sibling isnil`+0x49` map insert-or-find (key `@+0x0C`) | same predecessor pattern |
| `0x00569560` | Hinted insert path into same family | may call predecessor then fall through to `FUN_00569320` |

Domain meaning of those maps is **caller-owned**. This unit only advances the iterator to the in-order predecessor.

---

## 7. Gaps / open questions

1. Product English / export / typedef (`_Tree_unchecked_const_iterator::operator--`, etc.).
2. Exact node size for non-staging callers (0x4C-class suspected from nearby ctors; not re-proven here).
3. Runtime multi-iterator decrement capture (begin edge, end→max, single-node tree).
4. Bit-exact image diff vs retail EXE.
5. Formal Ghidra rename to `Map_Tree_Predecessor_Isnil49` — **role High**, English Tentative.
6. Whether any dynamic/indirect call sites exist beyond static xrefs (none found).

---

## 8. Verdict

### **accept-with-gaps**

**Accept because:** Fresh decompile matches raw CF; body bytes seal `__fastcall` ECX iterator, isnil `+0x49`, left/parent/right links, leaf predecessor algorithm (end→right, left-max, parent climb); no insert/rebalance confusion. Shared across multiple isnil`+0x49` maps; key layout is intentionally not part of this contract. Product name and runtime remain open.
