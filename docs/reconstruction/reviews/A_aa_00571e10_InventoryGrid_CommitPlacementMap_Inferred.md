# Review A (reconstruction fidelity): `aa_00571e10` InventoryGrid_CommitPlacementMap_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00571e10` |
| **VA** | `0x00571e10`–`0x00571fae` |
| **Canonical name** | `InventoryGrid_CommitPlacementMap_Inferred` |
| **Ghidra name** | `FUN_00571e10` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W22-C) |
| **Counterpart** | `reviews/B_aa_00571e10_InventoryGrid_CommitPlacementMap_Inferred.md` |
| **System** | inventory-transfer |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory`; callers RePlaceItems + SortAndRepack |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Commit staged placement-map items on an inventory grid: optional remove-from-related, set origin, bind owner, restamp cells (type≠4), clear map at `+0x60` / count `+0x64`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00571e10_FUN_00571e10.md` (+ 2026-07-29 append) |
| Annotated | `docs/reconstruction/raw/aa_00571e10_FUN_00571e10.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/InventoryGrid_CommitPlacementMap_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00571e10.cpp` |
| Function record | `docs/reconstruction/functions/aa_00571e10_FUN_00571e10.md` |
| Parents | `InventoryGrid_RePlaceItems_Inferred` `0x00572360`; `InventoryGrid_SortAndRepack_Inferred` `0x00572730` |
| Sibling | `InventoryGrid_RemoveItem` `0x00571b80` |
| Live | decompile ≡ raw CF; body 415 B; epilogue `C2 08 00` |

---

## 3. Signature (sealed)

```c
// ECX=this; stack related + flag; RET 8
void InventoryGrid_CommitPlacementMap_Inferred(
    InventoryGrid* this,
    InventoryGrid* related,
    char doRemoveFromRelated);
```

| Formal | Source | Conf |
|---|---|---|
| this | **ECX** (`mov ebx,ecx`) | **High** |
| related | stack0 → EBP in body; RemoveItem ECX | **High** |
| doRemove | stack1 byte | **High** |
| epilogue | `ret 8` | **Confirmed** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
begin = *head(grid+0x60)
if begin != head:
  for node in map:
    item = node+0x10
    if item && related && flag:
      RemoveItem(related, item, qty=vtbl+0x25c(1), force=1)
    vtbl+0x24c(originX, originY)
    vtbl+0x158(grid+0x24)
    if type != 4: restamp footprint COIDs into cells
    iterator++
clear map nodes (shell this+0x5c); count=0; head links = head
```

| Stage | Match | Conf |
|---|---|---|
| Map walk + isnil iterator | **Yes** | **High** |
| Optional RemoveItem gate | **Yes** | **High** |
| Origin + owner bind | **Yes** | **High** |
| Type-4 skip restamp | **Yes** | **High** |
| Clear + count 0 + ret 8 | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Body 415 B through `add esp,10; ret 8`. Entry `83 ec 10 53 8b d9 8b 43 60…`. RemoveItem call uses `mov ecx,ebp` (related) + `call FUN_00571b80`. Clear uses `add ebx,0x5c` before `FUN_005731c0`.

---

## 6. Gaps

- Product/PDB English name (`_Inferred` retained).
- relatedGrid exact typedef beyond InventoryGrid-compatible.
- Decompiler "non-returning delete" was wrong — sealed as loop from bytes.
- Runtime / bit-exact open.

## Verdict rationale

ABI, gate, restamp family, and map-clear sealed High from bytes + both major callers. Residual is naming + related type → **accept-with-gaps**.
