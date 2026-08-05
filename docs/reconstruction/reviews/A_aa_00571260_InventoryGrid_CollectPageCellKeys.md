# Review A (reconstruction fidelity): `aa_00571260` InventoryGrid_CollectPageCellKeys

| Field | Value |
|---|---|
| **Stable ID** | `aa_00571260` |
| **VA** | `0x00571260` |
| **Canonical name** | `InventoryGrid_CollectPageCellKeys` (inferred) |
| **Ghidra symbol** | `FUN_00571260` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual A/B) |
| **Counterpart** | `reviews/B_aa_00571260_InventoryGrid_CollectPageCellKeys.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Scan one page band of an inventory grid's cell array** and **append each occupied cell's 64-bit key (COID/TFID halves)** into a caller-provided list — **if that key is not already present**.

```text
// __thiscall grid*, list*, pageIndex(byte)  →  list* or 0
// ret 8

if (list == 0 || pageIndex >= *(grid+0x14)) return 0;

pageW = *(grid+0x1c)
baseY = pageW * pageIndex          // page-local band start
// outer: x = 0 .. *(grid+0x18)-1
// inner: y = baseY .. baseY+pageW-1
// index = *(grid+0xc) * x + y     // height * x + y (same Place/FindFree)
// cells = *(grid+0x28); key = cells[index] as 2×u32
// empty if (lo & hi) == 0xFFFFFFFF  (both halves FFFFFFFF → skip)

for each non-empty cell key:
  found = 0; cursor = 0
  List_TraversalLock(list)
  while List_IterateNext_u64(list, &cursor, &outKey) == 0:
    if outKey == cellKey: found = 1; break
  unlock list if flag set
  if !found:
    List_Insert_u64(list, cellKey.lo, cellKey.hi)   // FUN_00573040
return list
```

**Not** a UI rebuild. **Not** grid mutation. Collects keys for callers (sole live caller: sheet rebuild).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00571260_FUN_00571260.md` |
| Annotated | `docs/reconstruction/raw/aa_00571260_FUN_00571260.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00571260.cpp` |
| Function record | `docs/reconstruction/functions/aa_00571260_FUN_00571260.md` |
| Live decompile | Ghidra `decompile` / `force_decompile` @ `0x00571260` — **A ≡ B ≡ raw** |
| Live bytes | `read_memory` @ `0x00571260` length 200 — `c2 08 00` |
| Callees | `List_TraversalLock` `0x004294f0`, `List_IterateNext_u64` `0x00413be0`, `FUN_00573040` insert, `LeaveCriticalSection` |
| Parent dual | `A_aa_00860700_Client_UI_InventorySheet_RebuildItemWidgets` |
| Empty cell formula | same `0xFFFFFFFF` halves as `InventoryGrid_RemoveItem` unstamp |

**Not performed:** `disassemble_bytes`, Launcher, live cell dump.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `thiscall` grid; stack: list*, page byte; `ret 8` | **High** | Prologue + `c2 08 00` |
| Gate list null / page ≥ `grid+0x14` → 0 | **High** | Early return |
| Page band: `base = pageW * page`; width `grid+0x1c` | **High** | `imul` |
| Index `height*x + y` with height `grid+0xc` | **High** | Matches Place dual |
| Cells base `grid+0x28`; stride 8 | **High** | `* 8` loads |
| Empty iff `(lo & hi) == 0xFFFFFFFF` | **High** | Decompile `!= 0xffffffff` on AND |
| Membership via TraversalLock + IterateNext_u64 | **High** | Calls sealed |
| Insert only when not found (`FUN_00573040`) | **High** | `if param_3==0` insert |
| Returns **list** pointer (not grid) | **High** | `return iVar1` = saved list |
| Decompiler omits list `this` on callees | **High** (artifact) | ECX = list (`iVar1`/`param_2`) |
| Product name | **Probable** | Role High; no string |

---

## 4. Control flow: clean ≡ raw ≡ force

| Stage | Match |
|---|---|
| Null list / bad page → 0 | **Yes** |
| Nested x/y page loops | **Yes** |
| Skip empty cells | **Yes** |
| Lock → walk for match → unlock | **Yes** |
| Insert missing keys | **Yes** |
| Return list | **Yes** |
| Dual A≡B | **Yes** |

### Decompiler corrections

| Topic | Correction |
|---|---|
| `FUN_004294f0()` / `FUN_00413be0` / `FUN_00573040` without this | **`ECX = list`** (`param_2`), not grid |
| `param_3` reuse | Page index first; then **found** flag 0/1 per cell |
| Return value | **list\*** (or 0), not grid |

### Insert callee seal (`0x00573040`)

Under list CS: reject if traversal flag; alloc node via list vtbl+4; link; store key at `node+8/+0xc`; `count++`. Confirms collect **appends** keys, does not purge.

---

## 5. Layout reuse (grid)

| Offset | Role | Conf |
|---|---|---|
| `+0x0c` | height / row stride | **High** |
| `+0x14` | page count (page index upper bound) | **High** |
| `+0x18` | sizeX (outer loop) | **High** |
| `+0x1c` | page height / band width in Y | **High** |
| `+0x28` | cells base (`i32[2]` per cell) | **High** |

---

## 6. Callers

| Caller | Role |
|---|---|
| `Client_UI_InventorySheet_RebuildItemWidgets` `0x00860700` | **Sole** xref — collect current page COIDs then AddItemWidget each |

Page arg = `window+0x564` (byte) per parent dual.

---

## 7. Gaps

1. Product name (CollectPageCellKeys vs CollectOccupiedTFIDs).
2. Whether `(lo & hi) == -1` empty test differs from `lo==-1 && hi==-1` for partial fills (AND form is what retail does).
3. Confirm `grid+0x14` always “page count” English across all grid types.
4. Runtime page bounds on trade vs cargo sheets.

**Verdict:** **accept-with-gaps** — collect CF + empty/index formulas **sealed**.
