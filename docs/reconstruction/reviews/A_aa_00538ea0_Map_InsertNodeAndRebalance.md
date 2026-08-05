# Review A (reconstruction fidelity): `aa_00538ea0` Map insert node + RB rebalance

| Field | Value |
|---|---|
| **Stable ID** | `aa_00538ea0` |
| **VA** | `0x00538ea0` |
| **Canonical name** | `FUN_00538ea0` (product English open) |
| **Inferred role** | Mission-staging-typed **map/set tree insert + red-black rebalance** (always allocates) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw + bytes) |
| **Counterpart** | `reviews/B_aa_00538ea0_Map_InsertNodeAndRebalance.md` |
| **System** | `missions-progression` (sole static consumer is staging insert) |
| **Dual status** | **Present — sealed 2026-07-29** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

`__thiscall` on the **MapShell** (`head @ +4`, `size @ +8`): MSVC-style `_Tree::_Insert` helper that **always** constructs a new node and rebalances. Not insert-or-find (that is parent `FUN_00539cb0`).

1. If `size > 0x4924922` → throw `std::length_error`-style with string **`"map/set<T> too long"`**.
2. `FUN_005380d0(head, where, head, valuePair, color=0)` → `operator_new(0x50)`, copy **14 dwords** @ `+0x10`, color `+0x48=0` (red), isnil `+0x49=0`.
3. `size++` at `map+8`.
4. Link under `where`:
   - `where == head` → first element: root = leftmost = rightmost = new.
   - `addLeft == 0` → `where.right = new`; if `where == rightmost`, update head.right.
   - `addLeft != 0` → `where.left = new`; if `where == leftmost`, update head.left.
5. RB fixup while parent color is red (`+0x48 == 0`): uncle recolor, left/right rotates (`FUN_00568b70` L-rotate, `FUN_005681a0` R-rotate; one L-rotate of grandparent **inlined**).
6. Root color forced black; `*outIt = newNode`; **`RET 0x10`**.

Sole static caller: `FUN_00539cb0` (×2 call sites @ `0x00539d09`, `0x00539d40`).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00538ea0_FUN_00538ea0.md` |
| Annotated | `docs/reconstruction/raw/aa_00538ea0_FUN_00538ea0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00538ea0.cpp` |
| Function record | `docs/reconstruction/functions/aa_00538ea0_FUN_00538ea0.md` |
| Fresh decompile | Ghidra `decompile_function` @ `0x00538ea0` (2026-07-29) — CF ≡ raw 2026-07-23 |
| Body image | Ghidra `read_memory` @ `0x00538ea0` length 512 — epilogue `C2 10 00`; size cap `cmp [edi+8],0x04924923` / `jb`; color `+0x48`; isnil `+0x49`; `mov ebx,1` black |
| Node ctor | `FUN_005380d0` @ `0x005380d0` — `push 0x50`, `rep movsd` ECX=`0xE`, color `+0x48`, isnil `+0x49`, **`RET 0x14`** |
| L-rotate | `FUN_00568b70` — `__thiscall(map, node*)`; uses isnil `+0x49` |
| R-rotate | `FUN_005681a0` — `__thiscall(map, node*)`; uses isnil `+0x49` |
| Parent dual | `A/B_aa_00539cb0_MissionStagingMap_Insert` — ABI + node layout sealed |
| Callers | Ghidra `get_function_callers` / xrefs: **only** `FUN_00539cb0` |

**Not performed:** `disassemble_bytes`, Launcher, runtime capture, binary diff.

---

## 3. Evidence table

| Claim | Evidence | Confidence |
|---|---|---|
| `__thiscall(map*, outIt*, addLeft, where*, value*)` + **`RET 0x10`** | Epilogue `C2 10 00`; stack locals for 4 args; `mov ecx,edi` before rotate calls | **High** |
| Always allocates (not find) | No key compare in body; always `FUN_005380d0` + size++ | **High** |
| Max size throw `"map/set<T> too long"` | String in throw path; `cmp [map+8], 0x4924923` / `jb` past throw | **High** |
| Map head `this+4`, size `this+8` | All head/size accesses; size++ | **High** |
| Node **0x50**; value **14 dwords** @ `+0x10` | ctor `push 0x50` + `mov ecx,0xE` / `rep movsd` | **High** |
| color `+0x48`, isnil `+0x49` | ctor stores; rebalance `cmp [reg+0x48]`; rotate guards `+0x49` | **High** |
| New node color **red (0)** | ctor arg `param_5=0`; loop continues while parent color `== 0` | **High** |
| Black = **1** | `mov ebx,1`; recolor / root paint use `bl` / `1` | **High** |
| Head: left@0 / parent(root)@4 / right@8 | First-node and leftmost/rightmost updates | **High** |
| `FUN_005681a0` = right rotate | Child = `*node` (left); splice left.right | **High** |
| `FUN_00568b70` = left rotate | Child = `node+8` (right); splice right.left | **High** |
| Grandparent left-rotate path **inlined** | Else branch mirrors `FUN_00568b70` body (isnil `+0x49`) | **High** |
| Sole static caller `FUN_00539cb0` | 2 xrefs, both in that function | **High** |
| Product English / typedef | No PDB/string for this instance | **Open** |
| Runtime / bit-exact | Not run | **Open** |

---

## 4. Sealed layouts

```
MapShell (this for FUN_00538ea0 / FUN_00539cb0 / FUN_00538a40)
  +0x00  (MSVC _Tree proxy / unused in this unit)
  +0x04  head / end sentinel node*
  +0x08  element count (u32); throw if > 0x4924922

// head (sentinel) link convention used here:
//   head[0] leftmost*, head[1] root*, head[2] rightmost*

StagingMapNode  // size 0x50 (FUN_005380d0)
  +0x00  left*
  +0x04  parent*
  +0x08  right*
  +0x0C  (not written by ctor)
  +0x10  value block start (14 dwords: key, pad, payload[12])
  +0x48  color (u8): 0=red, 1=black
  +0x49  isnil (u8): 0 for real nodes
  +0x4A  pad to 0x50

// ABI
// void/out __thiscall FUN_00538ea0(
//   MapShell* map,           // ECX
//   Node** outIt,            // stack+4  → *outIt = new node
//   char addLeft,            // stack+8  → 1 link left, 0 link right
//   Node* where,             // stack+C  → parent (or head if empty)
//   const void* valuePair);  // stack+10 → 14 dwords copied to node+0x10
// RET 0x10
```

---

## 5. Control flow: clean ≡ raw ≡ bytes

| Stage | Match |
|---|---|
| Size cap → `"map/set<T> too long"` throw | **Yes** |
| `FUN_005380d0` + size++ | **Yes** |
| Empty / right-child / left-child link + extremum updates | **Yes** |
| While parent red: uncle red recolor; L/R rotate cases | **Yes** |
| Root black; `*outIt = new`; `RET 0x10` | **Yes** |
| No key compare / no equal-key path | **Yes** |
| Scaffold “self-callee” claim | **False** — no recursion |

---

## 6. Callers (OWN boundary)

| VA | Name | Role re this unit |
|---|---|---|
| `0x00539cb0` | MissionStagingMap_Insert | On miss: pass `addLeft` + parent `where` + value pair; then mark `inserted=1` |

Higher mission dialog / eligibility logic is **not** this unit.

---

## 7. Gaps / open questions

1. Product English / MSVC template typedef for this map specialization.
2. Why one grandparent left-rotate is inlined vs calling `FUN_00568b70` (code-gen artifact; behavior sealed).
3. Exact Ghidra return type: epilogue leaves `EAX = outIt*`; callers may treat return as `Node**` — out-param contract is authoritative.
4. Runtime multi-insert size/rebalance capture; bit-exact image diff.
5. Formal rename: `Tree_InsertNodeAndRebalance` / `Node_Construct0x50` / `Tree_RotateLeft` / `Tree_RotateRight` — **roles High**, names Tentative.

---

## 8. Verdict

### **accept-with-gaps**

**Accept because:** Fresh decompile matches raw CF; body bytes seal `RET 0x10`, size cap, color/isnil offsets, black=`1`, always-alloc insert, and rotation helpers; node ctor seals `0x50` / 14-dword value; sole static caller is staging insert. Product name and runtime/diff remain open.
