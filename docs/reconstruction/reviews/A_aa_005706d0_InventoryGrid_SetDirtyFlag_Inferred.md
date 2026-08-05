# Review A (reconstruction fidelity): `aa_005706d0` InventoryGrid_SetDirtyFlag (**INFERRED**)

| Field | Value |
|---|---|
| **Stable ID** | `aa_005706d0` |
| **VA** | `0x005706d0` |
| **Canonical name** | `InventoryGrid_SetDirtyFlag` (**INFERRED**) |
| **Ghidra symbol** | `FUN_005706d0` |
| **Review date** | `2026-07-29` |
| **Counterpart** | `reviews/B_aa_005706d0_InventoryGrid_SetDirtyFlag_Inferred.md` |
| **System** | `inventory-transfer` |
| **Parent batch** | Grab/Drop/AddItem/Equip nested (via PlaceItemFootprint) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Mark inventory grid dirty after a mutating place path:**

```c
// __fastcall/thiscall: ECX = grid
void InventoryGrid_SetDirtyFlag(Grid* grid) {
  if (*(grid + 0x24) != 0)
    Object_PropagateDirtyBit0x20000(*(grid + 0x24));  // FUN_00512670
  *(uint8_t*)(grid + 0x21) = 1;
}
```

No place math. No footprint. Leaf post-stamp hook.

---

## 2. Inspected artifacts

| Artifact | Evidence |
|---|---|
| Live decompile | `batch_decompile` `0x005706d0` ≡ raw |
| Live bytes | `56 8B F1  8B 4E 24  85 C9  74 05  E8 …  C6 46 21 01  5E C3` |
| Raw / clean | `raw/aa_005706d0_*`, `reconstructed-exact/FUN_005706d0.cpp` |
| Callers | `0x00571808` PlaceItemFootprint tail; also `0x0088f77e`, `0x004f7fb0`, `0x00522da9` |
| Parent dual | `A_aa_00571620_InventoryGrid_PlaceItemFootprint` — post-stamp `FUN_005706d0(grid)` |
| Dirty sibling | `A_aa_00512670_Object_PropagateDirtyBit0x20000` |

**Not performed:** `disassemble_bytes`, Launcher.

---

## 3. Control flow: bytes ≡ decompile

| Stage | Match |
|---|---|
| `mov esi, ecx` (this = grid) | **Yes** |
| `ecx = [esi+0x24]`; null → skip call | **Yes** |
| `call FUN_00512670` with ECX = object at `grid+0x24` | **Yes** |
| `mov byte [esi+0x21], 1` always | **Yes** |
| `pop esi; ret` (no stack args) | **Yes** |

### Offsets

| Off | Role | Confidence |
|----:|------|------------|
| `grid+0x24` | optional related object* for dirty propagate | **High** CF; product name open |
| `grid+0x21` | dirty / needs-refresh flag (set 1) | **High** (also set by merge `0x00571830`) |

---

## 4. Confidence

| Claim | Confidence |
|---|---|
| Post-place dirty mark | **High** |
| Always sets `+0x21` | **High** |
| Conditional propagate via `0x00512670` | **High** |
| Product name of `+0x24` object | **Open** |
| Who clears `+0x21` | **Open** |

**Verdict:** **accept-with-gaps** — tiny sealed leaf for grid dirty after place/merge family.

---

## WQ8R-J reconfirm (2026-08-04)

| Check | Result |
|---|---|
| Live `batch_decompile` ≡ raw | **Yes** |
| `read_memory` 21 B body + plain `ret` | **Yes** (`56 8B F1 … C6 46 21 01 5E C3`) |
| Call rel → `FUN_00512670` | **Yes** |
| Xrefs still 4 | **Yes** (`00571808`, `0088f77e`, `004f7fb0`, `00522da9`) |
| Clean named twin | `reconstructed-exact/InventoryGrid_SetDirtyFlag_Inferred.cpp` |
| Verdict change | **None** — still **accept-with-gaps** |
