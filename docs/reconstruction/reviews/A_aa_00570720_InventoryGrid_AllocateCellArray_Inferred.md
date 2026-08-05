# Review A (reconstruction fidelity): `aa_00570720` InventoryGrid_AllocateCellArray_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00570720` |
| **VA** | `0x00570720` |
| **Canonical name** | `InventoryGrid_AllocateCellArray_Inferred` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw) |
| **Counterpart** | `reviews/B_aa_00570720_InventoryGrid_AllocateCellArray_Inferred.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present and strengthened** (A + B modern pair; supersedes thin 2026-07-23 combat/loot dual scaffold) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Inventory grid **cell-buffer allocate / reallocate / empty-fill**. Does **not** place, stamp, or walk the item tree.

Given a grid with width/height/pages already stored:

1. Free prior `cells` at `+0x28` if non-null.
2. `nTotal = width * height` → store `+0x10`; temp-null `+0x28`.
3. Derive page geometry: `+0x1c = (nTotal / pages) / width`, `+0x18 = nTotal / height`.
4. `operator_new(nTotal * 8)`; store at `+0x28`.
5. Fill all dwords with `0xFFFFFFFF` (empty COID halves). Residual byte loop is dead (count forced 0).

**Calling convention:** MSVC `__fastcall` with sole arg in `ECX` (thiscall-equivalent for one-arg methods).

| Slot | Role | Evidence |
|------|------|----------|
| `this` / `pGrid` (ECX) | `InventoryGrid*` | Loads `+0x08/+0x0c/+0x14`; stores `+0x10/+0x18/+0x1c/+0x28` |

**Returns:** `void`.

**Side effects:** heap free/new; grid dim totals + page helpers + cell pointer + full empty fill. No locks inside this unit (callers often leave CS first).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00570720_InventoryGrid_AllocateCellArray_Inferred.md` |
| Annotated | `docs/reconstruction/raw/aa_00570720_InventoryGrid_AllocateCellArray_Inferred.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/InventoryGrid_AllocateCellArray_Inferred.cpp` |
| Function record | `docs/reconstruction/functions/aa_00570720_InventoryGrid_AllocateCellArray_Inferred.md` |
| Prior dual (legacy scaffold) | thin A/B 2026-07-23 combat/loot wave; long-form `aa_00570720_reconstruction_review.md` / `_skeptical_review.md` |
| Live re-decompile | Ghidra MCP `decompile_function` @ `0x00570720` (2026-07-29) — **matches raw body** |
| Ctor caller | live/raw `InventoryGrid_ctor_Inferred` @ `0x00572650` — clamps dims ≥1 then calls |
| Other callers | `0x00570f50`, `0x00570f70`, `0x00572360`, `0x00572730` (×2) |
| Consumers | FindFreeSlot `0x005713a0`, CanPlace `0x00570840`, Place `0x00571620` |
| Layout | `OBJECT_LAYOUTS.md` InventoryGrid partial; `docs/inventory-cargo-wire-re.md` |

**Not performed:** `disassemble_bytes`, Launcher, live heap dump, bit-exact diff.

---

## 3. Grid offsets (body-backed)

| Offset | Width | Role | Raw evidence |
|--------|-------|------|--------------|
| `+0x08` | `i32` | Width (X extent) | Factor of `nTotal`; divisor of page-height formula |
| `+0x0c` | `i32` | Height (Y extent + find/place stride) | Factor of `nTotal`; divisor for `+0x18` |
| `+0x10` | `i32` | **total cells** (write) | `nTotal = w*h` |
| `+0x14` | `i32` | Pages / page factor (read) | Divisor in `+0x1c` formula |
| `+0x18` | `i32` | Derived: `nTotal / height` (= width when consistent) | Written after total |
| `+0x1c` | `i32` | **Page height** in cells: `(nTotal / pages) / width` | Find window / CanPlace `%` |
| `+0x28` | ptr | Cell array base | Free → null → new → fill |

### Cargo sanity (from wire-RE + ctor plate)

| Setup | Math | Result |
|-------|------|--------|
| `w=6`, `h=pages*13`, `pages≥1` | `nTotal = 6*13*pages` | `+0x10` |
| page height | `(nTotal/pages)/w = 78/6` | **`+0x1c = 13`** |
| derived | `nTotal/h = w` | **`+0x18 = 6`** |

---

## 4. Control flow: clean ≡ raw ≡ live decompile

| Stage | Match |
|---|---|
| Conditional `operator_delete` of old `+0x28` | **Yes** |
| `nTotal = *(+8) * *(+0xc)` | **Yes** |
| Clear `+0x28` then write `+0x10` | **Yes** |
| `+0x1c = (nTotal / *(+0x14)) / *(+8)` | **Yes** |
| `+0x18 = nTotal / *(+0xc)` | **Yes** |
| `operator_new(nTotal * 8)` → store `+0x28` | **Yes** |
| Dword fill `0xFFFFFFFF` for `(nTotal*8)>>2` | **Yes** |
| Residual byte loop with counter forced **0** | **Yes** (dead; preserved) |
| No item-tree / stamp / find | **Yes** |

### 4.1 Residual loop

```c
for (nTotalCells = 0; nTotalCells != 0; nTotalCells = nTotalCells + -1) {
  *(undefined1 *)pCell = 0xff;
  pCell = (undefined4 *)((int)pCell + 1);
}
```

MSVC `memset`-style dword loop + residual-byte tail. Size is always `nTotal*8` (multiple of 4) → residual **never runs**. Clean correctly keeps it for CF parity.

### 4.2 Division preconditions

Body has **no** zero checks. Primary ctor path clamps:

```c
if (nPages < 1) pages = 1;
if (width  < 1) width  = 1;
if (height < 1) height = 1;
InventoryGrid_AllocateCellArray_Inferred(this);
```

Rebuild callers re-use existing dims (already ≥1 if constructed via ctor). Div-by-zero remains a precondition gap for malformed grids.

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Free old cells then realloc | **High / Confirmed** | Raw + live |
| `nTotal = w * h` → `+0x10` | **High** | Body |
| 8-byte cells | **High** | `nTotal*8` alloc; Find/Can/Place |
| Empty = both dwords `0xFFFFFFFF` | **High** | Fill; matches free predicate `(lo&hi)==-1` |
| `+0x1c` page height formula | **High** CF; cargo **13** sealed | Algebra + consumers |
| `+0x18` = `nTotal/h` (width echo) | **High** CF; name “page width helper” **Probable** | Doc label only |
| Residual loop dead | **High** | Counter=0 |
| Name is retail symbol | **Inferred only** | `_Inferred` honest |
| Divisors always ≠0 | **Probable** via ctor; not proven in unit alone | Rebuild paths rely on prior clamp |
| Runtime / bit-exact | **Open** | Deferred |

---

## 6. Callers (sample)

| VA | Role | Notes |
|----|------|-------|
| `0x00572650` | `InventoryGrid_ctor_Inferred` | Clamp dims ≥1 → allocate empty grid |
| `0x00570f50` | Thin re-empty | `FUN_004bc580` then allocate |
| `0x00570f70` | Clear items + re-empty | Walk tree / leave CS / clear / allocate |
| `0x00572360` | Rebuild path | When rebuild flag path clears tree, re-allocate empty then callers re-stamp |
| `0x00572730` | Sort/rebuild | Two call sites: fail-path on scratch grid; success-path on live grid before re-place |

**Contract:** allocate produces a **fully empty** occupancy buffer. Occupancy is re-established only by place/stamp callees (`0x00571620`), not by this unit.

---

## 7. Gaps / open (do not block accept-with-gaps)

1. **Runtime / differential** — no live cargo create heap dump of `nTotal` / `+0x1c` / cell pointer.
2. **Retail symbol** — name remains `_Inferred`.
3. **`+0x14` English** — “pages” is probable; exact product enum not sealed in this body.
4. **OOM** — `operator_new__` throw vs null unspecified; window where `+0x28` is null after free.
5. **Width/height identity** — sealed for this unit + Find/Can/Place family (`+0x08` X, `+0x0c` Y/stride); not a fidelity gap.

**No clean-vs-raw fidelity rewrite required.**

---

## 8. Verdict

### **accept-with-gaps**

Body is among the shortest high-confidence inventory units: live decompile ≡ raw ≡ clean. Empty encoding and page-height formula are sealed for AutoCore ports. Gaps are naming, OOM, runtime goldens — not CF drift.

---

## Checklist (reviewer)

| Check | Result |
|---|---|
| Live decompile matches raw | **Pass** |
| Clean CF matches raw | **Pass** |
| 8-byte cells filled with -1 | **Pass** |
| Free old array preserved | **Pass** |
| Dead residual loop preserved | **Pass** |
| Page-height formula vs Find/Can | **Pass** (cargo 13) |
| Ctor dim clamp cross-check | **Pass** |
| Runtime / bit-exact | **Open** |
| Verdict | **accept-with-gaps** |
