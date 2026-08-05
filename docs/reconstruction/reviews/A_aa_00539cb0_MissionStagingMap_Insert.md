# Review A (reconstruction fidelity): `aa_00539cb0` Mission staging map insert

| Field | Value |
|---|---|
| **Stable ID** | `aa_00539cb0` |
| **VA** | `0x00539cb0` |
| **Canonical name** | `FUN_00539cb0` (product English open) |
| **Inferred role** | Mission staging `std::map`-style **insert-or-find** (tree insert) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw + bytes) |
| **Counterpart** | `reviews/B_aa_00539cb0_MissionStagingMap_Insert.md` |
| **System** | `missions-progression` |
| **Dual status** | **Present — sealed 2026-07-29** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

`__thiscall` on the **mission staging map shell** (`Character+0x508` when called from `FUN_0052c700`): classic MSVC `map::insert` / insert-or-find for an int key.

1. Walk RB tree from `head->parent` (`*(this+4)+4`), compare `*valuePair` (key) vs `node+0x10`.
2. isnil stop at `node+0x49`; left `*node`, right `node[2]`.
3. If last step was left-child and parent is **leftmost** (`head->left`): insert with `addLeft=1`.
4. Else if last step was left-child: **predecessor** (`FUN_00537770` on parent iterator).
5. If `parent.key < key`: insert via `FUN_00538ea0` (node alloc + rebalance); else equal → `{parent, inserted=0}` with **no** value rewrite.
6. Out pair: `{node* @+0, uint8 inserted @+4}`; **`RET 8`**.

Sole static caller: mission staging store `FUN_0052c700` (miss path after `FUN_00538a40` lower_bound).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00539cb0_FUN_00539cb0.md` |
| Annotated | `docs/reconstruction/raw/aa_00539cb0_FUN_00539cb0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00539cb0.cpp` |
| Function record | `docs/reconstruction/functions/aa_00539cb0_FUN_00539cb0.md` |
| Fresh decompile | Ghidra `decompile_function` @ `0x00539cb0` (2026-07-29) — CF ≡ raw 2026-07-23 |
| Body image | Ghidra `read_memory` @ `0x00539cb0` length 200 — three `C2 08 00`; key cmp `[reg+0x10]`; isnil `+0x49` |
| Node ctor | `FUN_005380d0` @ `0x005380d0` — `operator_new(0x50)`, copy **0xE** dwords @ `+0x10`, color `+0x48`, isnil `+0x49` |
| Insert+rebalance | `FUN_00538ea0` — size at `map+8`, head at `map+4`, `"map/set<T> too long"` |
| Predecessor | `FUN_00537770` — iterator decrement; isnil `+0x49` |
| Sibling lower_bound | `FUN_00538a40` — same map shell / key @ `node[4]` |
| Parent upsert | `FUN_0052c700` dual A/B (`MissionStagingStore`) — map `char+0x508` |
| Callers | Ghidra `get_function_callers`: **only** `FUN_0052c700` @ `0x0052c700` |

**Not performed:** `disassemble_bytes`, Launcher, runtime capture, binary diff.

---

## 3. Evidence table

| Claim | Evidence | Confidence |
|---|---|---|
| `__thiscall(map*, outPair*, valuePair*)` + **`RET 8`** | Three epilogues `C2 08 00` in body image | **High** |
| Out pair `{it @+0, inserted @+4}` | `mov [eax],…` / `mov byte [eax+4],0/1` | **High** |
| Map head `this+4`, size `this+8` | Walk uses `*(this+4)`; insert helper increments `+8` | **High** |
| Key at `node+0x10` | `cmp edx,[eax+0x10]` / `mov eax,[edx+0x10]` in bytes | **High** |
| isnil `+0x49` | `cmp byte [reg+0x49],0` walk terminator | **High** |
| color `+0x48` | Node ctor + rebalance in `FUN_00538ea0` | **High** |
| Node size **0x50** | `operator_new(0x50)` in `FUN_005380d0` | **High** |
| Value copy **14 dwords** @ `+0x10` | ctor loop `iVar2=0xe` from `node+4` | **High** |
| Key + pad + 12-dword payload | Parent store: key `+0x10`, payload `+0x18`×12; 1+1+12=14 | **High** |
| Insert-or-find (no overwrite on equal) | Equal path only writes out pair `inserted=0` | **High** |
| `FUN_00538ea0` = insert + RB rebalance | `"map/set<T> too long"`, size++, rotations | **High** |
| `FUN_00537770` = predecessor only | Body walks left/right/parent; no alloc | **High** |
| Sole caller `FUN_0052c700` | `get_function_callers` | **High** |
| Product English name | No string/RTTI this pass | **Open** |
| Runtime / bit-exact | Not run | **Open** |

---

## 4. Sealed layouts

```
MapShell (this for FUN_00539cb0 / FUN_00538a40 / FUN_00538ea0)  // @ Character+0x508
  +0x00  (unused / proxy in MSVC _Tree) — not read in this unit
  +0x04  head / end sentinel node*
  +0x08  element count

// Value pair pushed by FUN_0052c700 miss path (14 dwords contiguous):
//   [0]     key (mission id)
//   [1]     pad / pair alignment (4 bytes; not used as payload)
//   [2..13] payload[12]

StagingMapNode  // size 0x50 (FUN_005380d0)
  +0x00  left*
  +0x04  parent*
  +0x08  right*
  +0x0C  (uninitialized by ctor; not used in walk/compare)
  +0x10  key (int / mission id)
  +0x14  pad dword (pair mid)
  +0x18  MissionStagingPayload[12]  // 0x30 bytes; see aa_0052c700 dual
  +0x48  color (u8)
  +0x49  isnil (u8)
  +0x4A  pad to 0x50

InsertOutPair
  +0x00  StagingMapNode* it
  +0x04  uint8_t inserted   // 1 = new node, 0 = existing equal key
```

---

## 5. Control flow: clean ≡ raw ≡ bytes

| Stage | Match |
|---|---|
| Root walk; key @ `+0x10`; isnil `+0x49` | **Yes** |
| goLeft + leftmost → `FUN_00538ea0(...,1,...)` → `{it,1}` | **Yes** |
| goLeft + not leftmost → `FUN_00537770` predecessor | **Yes** |
| parent.key < key → insert with `addLeft=bVar2` | **Yes** |
| else equal → `{parent,0}` no value copy | **Yes** |
| Three `RET 8` exits | **Yes** |
| No invent of mission eligibility / dialog UI | **Yes** |

---

## 6. Callers (OWN boundary)

| VA | Name | Role re this unit |
|---|---|---|
| `0x0052c700` | Mission staging store (`FUN_0052c700`) | On lower_bound miss: build `{key, pad, payload[12]}` and call insert |

Higher callers of the store (dialog / prerequisites / create-if-missing) are owned by `aa_0052c700`, not this insert helper.

---

## 7. Gaps / open questions

1. Product English / MSVC template typedef name for this map type.
2. Semantic of the 4-byte pad at `node+0x14` (pair alignment vs reserved field) — layout effect sealed.
3. Whether any dynamic/indirect call sites exist beyond static xrefs (none found).
4. Runtime / bit-exact / image diff.
5. Formal Ghidra rename of helpers (`Tree_InsertRebalance`, `Tree_Predecessor`, `Node_Construct0x50`) — **roles High**.

---

## 8. Verdict

### **accept-with-gaps**

**Accept because:** Fresh decompile matches raw CF; body bytes seal `RET 8`, key offset `+0x10`, isnil `+0x49`, insert-or-find (no overwrite on equal); node ctor seals size `0x50` and 14-dword value block; sole caller is staging store. Product name and pad field English remain open.
