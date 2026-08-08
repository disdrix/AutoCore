# Review A (reconstruction fidelity): `aa_005715d0` InventoryGrid_CanPlaceItem

| Field | Value |
|---|---|
| **Stable ID** | `aa_005715d0` |
| **VA** | `0x005715d0` |
| **Canonical name** | `InventoryGrid_CanPlaceItem` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw + live bytes) |
| **Counterpart** | `reviews/B_aa_005715d0_InventoryGrid_CanPlaceItem.md` |
| **Residual scratch** | `reviews/a_005715d0.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** (first full dual; supersedes 2026-07-23 scaffold) |
| **Verdict** | **accept** (leaf; residual product English only) |

---

## 1. Purpose

**Item-aware CanPlace probe** — does **not** place, stamp, clear, or mutate grid cells.

1. Null item (`stack0`) → **0**.
2. Load InvSizeX/Y from clonebase blob (`item+0xa8` → `+0x3c` → `+0x406/+0x407`).
3. Tail into `InventoryGrid_CanPlace(this, sizeX, sizeY, originX, originY, conflictOut)`.
4. Return CanPlace result.

**Calling convention:** MSVC `__thiscall` — grid in `ECX` (prologue `PUSH ECX`). Callee **`RET 0x10`** → **four** stack dwords.

| Slot | Role | Evidence |
|------|------|----------|
| `this` (ECX) | `InventoryGrid*` | Saved; restored as CanPlace this |
| stack0 | `ItemObject*` | Null test; `+0xa8` type/blob host |
| stack1 | `originX` | Forwarded to CanPlace |
| stack2 | `originY` | Forwarded |
| stack3 | `conflictOut*` | Forwarded (nullable; callers often `0`) |

**Returns:** CanPlace **1** fit / **0** reject. Body `0x005715d0`–`0x0057161d` (~78 B).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005715d0_FUN_005715d0.md` |
| Annotated | `docs/reconstruction/raw/aa_005715d0_FUN_005715d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/InventoryGrid_CanPlaceItem.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005715d0.cpp` |
| Function record | `docs/reconstruction/functions/aa_005715d0_InventoryGrid_CanPlaceItem.md` |
| Residual | `docs/reconstruction/reviews/a_005715d0.md` |
| Live decompile | Ghidra `batch_decompile` @ `0x005715d0` — **≡ raw body** |
| Live bytes | full body `read_memory` (incl. `C2 10 00`) |
| CanPlace dual | `aa_00570840` residual + A/B |
| Callers | `get_function_callers` / xrefs: `008012f0`, `00941b20`, `00952bc0`, `00955010` (+ multi-sites) |

**Not performed:** `disassemble_bytes`, Launcher, bit-exact.

---

## 3. Relation to CanPlace (fidelity seal)

Bytes: load sizes → push conflictOut, originY, originX, sizeY, sizeX → `CALL 0x00570840` with ECX=grid.

So every CanPlace seal applies unchanged:

- index `height*x+y`
- page non-span `(originY % pageH)+sizeY <= pageH`
- empty `(lo & hi) == 0xFFFFFFFF`
- conflictOut same-COID tolerance when non-null

Wrapper-only CF:

| Path | Result |
|------|--------|
| item == null | **0** (no CanPlace call) |
| else | **return CanPlace(...)** |

---

## 4. Control flow: live ≡ raw ≡ bytes

| Stage | Match |
|---|---|
| Null item → 0, `RET 0x10` | **Yes** |
| InvSize load `+0x406/+0x407` | **Yes** |
| Forward 5 CanPlace stack args + this | **Yes** |
| Return CanPlace | **Yes** |
| `RET 0x10` | **Yes** (`C2 10 00`) |

### Decompiler note

Ghidra presents the function as non-thiscall and omits explicit grid this on the CanPlace call. **Bytes** `PUSH ECX` / restore ECX into CanPlace this seal **thiscall**. Call sites equip/place probes keep grid in ECX.

---

## 5. Confidence

| Dimension | Level |
|---|---|
| Function boundary | **Confirmed** (`005715d0`–`0057161d`) |
| thiscall + 4 stack args | **Confirmed** (`RET 0x10` + prologue) |
| InvSize path | **Confirmed** |
| Relation to `0x00570840` | **Confirmed** |
| Caller roles (equip/space probe) | **High** |
| Product English name | **Probable** (CanPlaceItem) |
| Overall | **accept** (leaf residual: PDB English only) |

---

## 6. Verdict

### **accept**

Live body matches raw; ABI and InvSize→CanPlace handoff sealed. No cell mutation. Remaining gap is product/PDB English only (does not block accept).
