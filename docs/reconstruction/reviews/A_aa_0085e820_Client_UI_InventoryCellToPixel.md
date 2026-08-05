# Review A (reconstruction fidelity): `aa_0085e820` Client_UI_InventoryCellToPixel

| Field | Value |
|---|---|
| **Stable ID** | `aa_0085e820` |
| **VA** | `0x0085e820` |
| **Canonical name** | `Client_UI_InventoryCellToPixel` |
| **Aliases** | `FUN_0085e820`, cell→pixel reverse map (DropHitTest ghost path) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A/B — Drop/Grab callee residual) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_0085e820_Client_UI_InventoryCellToPixel.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** (first dual pair) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Convert inventory **grid cell coordinates** into **window-local pixel origin** for ghost/preview placement:

```
out[0] = *(window+0x504) - (int)((float)DAT_00d1e818 * (float)_DAT_00d1e50c * _DAT_00aaa6ac) * (cellX & 0xff)
out[1] = *(window+0x508) - (int)((float)DAT_00d1e81c * (float)_DAT_00d1e510 * _DAT_00aaa6a8) * cellY
```

Because pitch constants `_DAT_00aaa6ac` / `_DAT_00aaa6a8` are **negative** (`−0.000625` / `−0.000833…`), subtraction of a negative product is equivalent to **origin + |pitch| × cell** — the inverse of DropHitTest’s cell-from-pointer pitch.

---

## 2. Calling convention — SEALED (decompile + callers)

| Slot | Role | Evidence |
|------|------|----------|
| **EAX** | `int out[2]*` pixel result | writes `*in_EAX`, `in_EAX[1]` |
| **arg0 / param_1** | cellX (low 8 bits used) | `param_1 & 0xff`; hit-test ghost path |
| **arg1 / param_2** | inventory UI window* | loads `+0x504/+0x508` |
| **arg2 / param_3** | cellY (byte) | `(uint)param_3` |

Live xrefs (both inside DropHitTest family ~`0x0085f220`): `0x0085f533`, `0x0085f58c`.

---

## 3. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `raw/aa_0085e820_*`, `reconstructed-exact/FUN_0085e820.cpp` |
| Function record | `functions/aa_0085e820_FUN_0085e820.md` |
| Live decompile | Ghidra `batch_decompile` 2026-07-29 ≡ raw |
| Live bytes | `read_memory` @ `0x0085e820` — `cvtsi2ss` / `mulss` / `cvttss2si` / `imul` pitch path |
| Static floats | `read_memory` @ `0x00aaa6a8` → Y `−0.000833…`, X neighbor `−0.000625` |
| Parent dual | `A_aa_0085f220_Client_UI_InventoryDropHitTest` §5.3 / §5.6 |
| Sibling place | `A_aa_0085f150_Client_UI_InventoryItemWidget_PlaceFromCell` (forward pitch uses `+0x50c/+0x510`) |

**Not performed:** `disassemble_bytes`, Launcher, runtime, bit-exact.

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Load originY cache from `window+0x508` | **Yes** |
| Compute pitchY = scaleY × scale2Y × `_DAT_00aaa6a8` | **Yes** |
| outX = originX(`+0x504`) − pitchX×cellX_u8 | **Yes** |
| outY = originY − pitchY×cellY | **Yes** |
| No branches / early outs | **Yes** |
| Clean scaffold ≡ raw body | **Yes** |

---

## 5. Offsets / constants

| Symbol / offset | Role | Confidence |
|---|---|---|
| window `+0x504` | pixel origin X | **High** (body + PlaceFromCell dual) |
| window `+0x508` | pixel origin Y | **High** |
| `DAT_00d1e818` / `DAT_00d1e81c` | runtime screen scale X/Y | **High** as loads; live values open |
| `_DAT_00d1e50c` / `_DAT_00d1e510` | runtime UI scale factors | **High** as loads |
| `_DAT_00aaa6ac` | static X pitch scalar `−1/1600` | **Confirmed** (sibling dual + image) |
| `_DAT_00aaa6a8` | static Y pitch scalar `−1/1200` | **Confirmed** |
| cellX masked `& 0xff` | byte cell | **High** |

---

## 6. Gaps

1. Exact MSVC formal packing (register vs stack) beyond decompiler `__fastcall` + EAX out — call-site residual only.
2. Live magnitudes of `DAT_00d1e818/81c` / `_DAT_00d1e50c/510` (zeros in static image).
3. Relationship to forward pitch fields `window+0x50c/+0x510` used by PlaceFromCell (same product family, different cache).
4. Runtime / differential / bit-exact open.

**Verdict:** Leaf math helper sealed for inventory ghost placement. **accept-with-gaps.**
