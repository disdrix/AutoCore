# Review A (reconstruction fidelity): `aa_00571620` InventoryGrid_PlaceItemFootprint

| Field | Value |
|---|---|
| **Stable ID** | `aa_00571620` |
| **VA** | `0x00571620` |
| **Canonical name** | `InventoryGrid_PlaceItemFootprint` |
| **Review date** | `2026-07-29` (strengthen: stamp byte seal) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw bytes / corrected model) |
| **Counterpart** | `reviews/B_aa_00571620_InventoryGrid_PlaceItemFootprint.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present and strengthened** (stamp core via `read_memory`; residual `a_00571620.md`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Place an item into an inventory grid at `(originX, originY)`:

1. Reject object types `{0x12,0x14,0x16,0x36,0x38,0x3a}` → **0**.
2. Type **4**: light bind via `FUN_00566f00` + vtbl `+0x158(grid+0x24)` → **1**, **no multi-cell stamp**.
3. Else load InvSizeX/Y from clonebase blob `+0x406/+0x407`; if grid type `+0x04==4` and a dim is 0, force **2**.
4. `CanPlace(sizeX, sizeY, originX, originY, null)` → fail **0**.
5. Bind / set pos / flag item; optional gfx when item flag bit 6; set quantity via vtbl `+0x260`.
6. **Stamp COID** into every footprint cell; mark item `|0x10`; post helpers → **1**.

**Calling convention:** MSVC `__thiscall` — grid in `ECX`. Callee `RET 0x10` → **four** stack dwords.

| Slot | Role | Evidence |
|------|------|----------|
| `this` | `InventoryGrid*` | Prologue `EDI=ECX`; loads `+0x04/+0x0c/+0x24/+0x28` |
| stack0 | `ItemObject*` | Prologue `ESI=[ESP+0x14]` after `PUSH ESI` |
| stack1 | `originX` | Outer setup `baseX = originX + dx` |
| stack2 | `originY` | Stamp addend `[ESP+…]` |
| stack3 | `quantity` | vtbl `+0x260` before stamp |

**Returns:** low-byte flag **1** success / **0** fail (`AL`). Epilogue bytes: `B0 01` … `C2 10 00`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00571620_InventoryGrid_PlaceItemFootprint.md` |
| Annotated | `docs/reconstruction/raw/aa_00571620_InventoryGrid_PlaceItemFootprint.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/InventoryGrid_PlaceItemFootprint.cpp` |
| Function record | `docs/reconstruction/functions/aa_00571620_InventoryGrid_PlaceItemFootprint.md` |
| Residual scratch | `docs/reconstruction/reviews/a_00571620.md` |
| Prior dual / long-form | thin A/B 2026-07-23; `aa_00571620_reconstruction_review.md` / `_skeptical_review.md` |
| Live bytes | Ghidra `read_memory` stamp core `0x005717a0`, outer `0x00571760`, prologue/epilogue |
| Live decompile | `0x00571620` still wrong on stamp (`unaff_*`); **bytes override** |
| CanPlace / FindFree decompile | `0x00570840` / `0x005713a0` same index family |

**Not performed:** `disassemble_bytes`, Launcher, CE cell dump, bit-exact.

---

## 3. Stamp formula (byte-sealed)

```text
// dx in [0, sizeX), dy in [0, sizeY)
index = *(grid+0x0c) * (originX + dx) + (originY + dy)
*(i32*)(cells + index*8)     = item+0x160   // COID lo
*(i32*)(cells + index*8 + 4) = item+0x164   // COID hi
```

| Opcode evidence (inner) | Role |
|-------------------------|------|
| `8B 57 0C` | `EDX = [EDI+0x0c]` height |
| `0F AF 54 24 14` | `IMUL EDX, [ESP+baseX]` |
| `03 D0` | `+ dy` |
| `03 54 24 18` | `+ originY` |
| `89 2C D3` / `89 6C D3 04` | COID lo/hi at `cells[idx*8]` |

- Outer loop bound = **sizeX**.
- Inner loop bound = **sizeY**.
- Same packing as CanPlace/FindFree: `height * x + y`.

### Raw decompile was corrupted here

Do **not** port:

```c
// WRONG (raw unaff body)
index = height * (sizeY + row) + col + bStack_8;
```

Clean follows **bytes**, not that expression. Clean already has correct formula (2026-07-29 residual).

---

## 4. Control flow: clean ≡ bytes

| Stage | Match |
|---|---|
| Reject six type ids → 0 | **Yes** |
| Type 4: `00566f00(grid+0x2c,item)` + vtbl+0x158(grid+0x24) → 1 | **Yes** |
| InvSize load + grid-type min 2×2 | **Yes** |
| CanPlace gate → 0 | **Yes** |
| vtbl +0x158 / +0x24c(originX,originY) / +0x40(1) | **Yes** |
| Flag bit6 gfx path + 1.0f scale | **Yes** |
| vtbl +0x260(quantity) | **Yes** |
| Nested stamp sizeX × sizeY COID pair | **Yes** (byte formula) |
| Flag `\|0x10` + `00512670(item)` + `005706d0(grid)` | **Yes** |
| `RET 0x10` | **Yes** (`C2 10 00`) |

### 4.1 Notable corrections vs decompiler

| Topic | Correction |
|-------|------------|
| `FUN_00566f00` | `this = grid+0x2c`, arg = item |
| vtbl `+0x24c` | `(originX, originY)` not `(sizeX, originX)` |
| Outer stamp dim | **sizeX** not mystery SI |
| Index | `height*(ox+dx)+(oy+dy)` not `height*(sizeY+row)+…` |
| Quantity | explicit 4th stack arg |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Multi-cell COID stamp full footprint | **Confirmed** | Byte loop |
| Index `height*(ox+dx)+(oy+dy)` | **Confirmed** | `IMUL`+`ADD` chain |
| InvSize `+0x406/+0x407` | **High** | Prior + CF |
| Reject type CMP set | **High** | Six exact constants |
| Type 4 no-stamp path | **High** | Early RET |
| Stack ABI 4 args + this | **Confirmed** | `RET 0x10` bytes |
| Quantity → vtbl+0x260 | **High** | Pre-stamp call |
| Cell 8 B pair | **Confirmed** | `EDX*8` / `+4` |
| Reject type English names | **Open** | CF only |
| Runtime / bit-exact | **Open** | Deferred |

---

## 6. Gaps / open (do not block accept-with-gaps)

1. **Runtime** — no live observation of six stamped cells for a 2×3 place.
2. **Reject class names** — ids sealed; retail names unknown in this unit.
3. **Bit-exact / differential** — open matrix policy.
4. **Deep vfunc names** (`+0x158/+0x24c/+0x40/+0x260/+0x1cc`) — roles Probable; PDB open.

---

## 7. Verdict

### **accept-with-gaps**

Core place algorithm and stamp formula are **byte-sealed** (`read_memory`). Live decompiler body remains non-authoritative for the stamp residual. Remaining gaps are runtime/diff and naming — not stamp math.

---

## Checklist (reviewer)

| Check | Result |
|---|---|
| Stamp formula sealed from bytes | **Pass** |
| Clean CF matches sealed formula | **Pass** |
| CanPlace / FindFree index family match | **Pass** |
| Reject list preserved exact | **Pass** |
| Type-4 path preserved | **Pass** |
| ABI `RET 0x10` documented | **Pass** |
| Runtime / bit-exact | **Open** |
| Verdict | **accept-with-gaps** |
