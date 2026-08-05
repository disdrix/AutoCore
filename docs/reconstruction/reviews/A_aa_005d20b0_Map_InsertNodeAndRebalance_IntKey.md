# Review A (reconstruction fidelity): `aa_005d20b0` Map_InsertNodeAndRebalance_IntKey

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d20b0` |
| **VA** | `0x005d20b0` |
| **Body end** | ~`0x005d229a` (`add esp,0x50` / `ret 0x10`) |
| **Canonical name** | `Map_InsertNodeAndRebalance_IntKey` |
| **Prior scaffold** | `FUN_005d20b0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_005d20b0_Map_InsertNodeAndRebalance_IntKey.md` |
| **System** | `skills-abilities` (NPC AI int→int post-cast timer map) |
| **Agent** | W17-Q OWN-ONLY |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

MSVC-style **`std::map`/`set` node insert + red-black rebalance** core for the **int-key / int-mapped** tree family (node size **0x18**). Called only from public insert-or-find front `Map_InsertOrFind_IntKey` (`0x005d2360`) after the tree walk decides a missing key must be inserted.

String-seals family: throws **`"map/set<T> too long"`** when `size > 0x1FFFFFFD` (body: `cmp [edi+8], 0x1FFFFFFE` / `jb` past throw).

### Control flow

1. SEH frame `LAB_009a7022`.
2. **Size guard** → length_error-style throw with string @ `0x00a1530c`.
3. **Allocate/link node:** `FUN_006173a0(header, parent, header, valuePair, color=0)` → `operator_new(0x18)`:
   - links left/parent/right from args  
   - copies **2 dwords** key/mapped into `node+0x0C` / `+0x10`  
   - color byte at `node+0x14` (`param_5=0` red), isnil `+0x15 = 0`.
4. `map->size++` (`*(map+8)++`).
5. **Attach under parent** (`param_4`):
   - If parent is header: set header left/parent/right extremes to new node.
   - Else if `side==0` (`param_3==0`): `parent->right = new`; update header right-most if needed.
   - Else: `parent->left = new`; update header left-most if needed.
6. **RB fixup loop** while parent color at `parent+0x14` is red (`==0`; decompiler stops when `cVar1 != '\0'`):
   - Uncle red → recolor parent/uncle black, grandparent red; climb.
   - Uncle black → rotate (`FUN_004e22d0` L / `FUN_006753b0` R) + recolor; includes **inlined** left-rotate of grandparent.
7. Force root black: header parent color `+0x14 = 1`.
8. `*outNode = newNode`; **`RET 0x10`**.

**Sole live caller:** `Map_InsertOrFind_IntKey` (×2 sites).

**Not** the walk/compare (that is `005d2360`), not erase, not lower_bound-only.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005d20b0_FUN_005d20b0.md` (+ residual) |
| Annotated | `docs/reconstruction/raw/aa_005d20b0_FUN_005d20b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Map_InsertNodeAndRebalance_IntKey.cpp` |
| Function record | `docs/reconstruction/functions/aa_005d20b0_Map_InsertNodeAndRebalance_IntKey.md` |
| Live decompile | Ghidra `0x005d20b0` (2026-07-29) — **≡ scaffold CF** |
| Prologue | `read_memory`: `MOV EDI,ECX` + `CMP [EDI+8], 0x1FFFFFFE` / `JB` |
| String | `read_memory` `0x00a1530c` = `"map/set<T> too long"` |
| Epilogue | `ret 0x10` (4 stack formals) |
| Node ctor | live `FUN_006173a0` — `new(0x18)`, key/val, color `+0x14`, isnil `+0x15` |
| Rotates | `FUN_004e22d0` L / `FUN_006753b0` R (isnil `+0x15`) |
| Front dual | `A\|B_aa_005d2360_Map_InsertOrFind_IntKey` |
| Parallel family | `A\|B_aa_005a3310_StdMap_InsertNodeAndRebalance_Inferred` (different node size/color off) |

**Not performed:** `disassemble_bytes`, Launcher, runtime capture, binary diff.

---

## 3. Signature / layout

```c
// __thiscall map; ret 0x10
void __thiscall Map_InsertNodeAndRebalance_IntKey(
    MapShell *map,        // this — +4 header*, +8 size
    Node    **outNode,    // param_2
    char      insertLeft, // param_3 — 1=left, 0=right
    Node     *parent,     // param_4
    IntPair  *value);     // param_5 — {int key; int mapped;}
```

| Offset | Role |
|---|---|
| map `+4` | header / end sentinel node* |
| map `+8` | element count |
| node `+0..+8` | left / parent / right |
| node `+0x0C` | key int |
| node `+0x10` | mapped int |
| node `+0x14` | RB color |
| node `+0x15` | nil leaf flag (0 = real) |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| map/set insert + RB rebalance | **Confirmed** | string + loop |
| Size throw `"map/set<T> too long"` | **Confirmed** | |
| Node size 0x18 via `006173a0` | **Confirmed** | |
| Color at `+0x14`, nil at `+0x15` | **Confirmed** | ctor + body |
| Side flag left vs right attach | **Confirmed** | |
| ABI thiscall `ret 0x10` | **Confirmed** | |
| Sole caller `005d2360` | **Confirmed** | xrefs |
| Threshold size `> 0x1FFFFFFD` | **Confirmed** | cmp imm `0x1FFFFFFE` |
| Clean ≡ raw ≡ live CF | **Confirmed** | |
| Color polarity 0=red/1=black | **High** | MSVC tree; root forced 1 |
| Product STL / RTTI name | **Open** | no PDB |
| Runtime / bit-exact | **Open** | |

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Size overflow throw | **Yes** |
| Alloc + size++ + link | **Yes** |
| RB recolor/rotate loop | **Yes** |
| Out store new node | **Yes** |
| RET 0x10 | **Yes** |

---

## 6. Gaps / open

1. Formal product names for rotate helpers (`004e22d0`/`006753b0`).
2. Whether any other host reuses this insert helper after reanalysis (currently sole front).
3. Runtime overflow path (unlikely at production sizes).
4. Bit-exact image diff.

---

## 7. Surviving contract

```
// map thiscall; ret 0x10
if (map.size > 0x1FFFFFFD) throw length_error("map/set<T> too long");
node = AllocNode_0x18(header, parent, valuePair, color=0, nil=0);
map.size++;
link node as left/right child of parent (update header extremes);
RB_rebalance_up(node);   // recolor + rotate until root black
*out = node;
// NOT key compare; NOT erase; requires correct parent/side from front walk
```
