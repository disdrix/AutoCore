# Skeptical / adversarial review: `InventoryGrid_FindFreeSlot` @ `0x005713a0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_005713a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | 2026-07-23 |
| **Scope** | First-fit free rectangle search |
| **Verdict** | **needs-more-evidence** |

---

## 1. What was inspected

Raw/annotated/clean/function record; AllocateCellArray; PlaceItemFootprint; system map; inventory-cargo-wire-re; vehicle cargo create notes (6×pages×13).

**Not performed:** asm, runtime pack tests, CanPlace decompile.

---

## 2. Evidence used

Raw alone:

1. Requires non-null X/Y out pointers.
2. Degenerate: if sizeX or sizeY is 0 → outs (0,0), success.
3. Scans candidate origins; for each origin free corner cell, runs `FUN_00570840`.
4. Free corner test: AND of cell lo/hi dwords equals `0xFFFFFFFF`.
5. Optional page band via `param_6` and `grid+0x1c`.

---

## 3. Attack results

### Claim 1 — “First-fit free rect”

| Sub-claim | Result |
|-----------|--------|
| Nested loops try origins in order | **Holds.** |
| Outer coordinate is Y, inner is X | **Holds as coded** (`bVar2` Y-like, `bVar6` X-like). |
| Full rect emptiness checked only at corner | **ATTACK:** free test is **single cell** at candidate origin; full rect is delegated to `FUN_00570840`. Name “find free slot” OK; “checks whole rect free in this function” overstated. |
| Deterministic first-fit | **Holds** given fixed scan order + CanPlace pure. |

### Claim 2 — Empty cell = both halves `0xFFFFFFFF`

| Sub-claim | Result |
|-----------|--------|
| Predicate `(lo & hi) == -1` | **Holds.** |
| Equivalent to `lo==-1 && hi==-1` | **Almost:** AND==-1 implies both all-bits-1; yes for full 32-bit -1. |
| Matches allocate fill | **Holds** (allocate writes -1 dwords). |
| Occupied means any non -1 half | **Compatible** with place writing COID pairs. |

### Claim 3 — Indexing is row-major `y*width+x`

| Sub-claim | Result |
|-----------|--------|
| Code uses `*(g+0xc) * x + y` | **Holds.** |
| System “width at +8, height at +0xc” + row-major | **TENSION.** If +0xc is height, index is `height*x+y` (column-major / transposed). If +0xc is width, then outer loop bounds using +0xc as height are mislabeled. |
| Place unit uses same convention | **Unclear** (place formula currently suspicious). |

**Severity:** High for port grid math.

### Claim 4 — Zero size → success (0,0)

| Sub-claim | Result |
|-----------|--------|
| Present in raw | **Holds.** |
| Intentional API | **Unknown.** Could be legacy quirk. Ports that treat 0-size as error diverge. |

### Claim 5 — Page parameter

| Sub-claim | Result |
|-----------|--------|
| `-1` → full vertical range | **Holds.** |
| Else page band from `+0x1c` | **Holds as math.** |
| UI page == `param_6` | **Probable only.** |

### Claim 6 — Clean complete / named modern API

Still `FUN_005713a0`; scaffold only. `extraout_ECX` pollution remains.

### Claim 7 — System map “High” multi-cell place confidence extends to find

Find is clearer than place, but layout labels still open — do not over-seal.

---

## 4. Alternate interpretations

### Minimal reading

```
bool find(Grid* g, uint8 sx, uint8 sy, uint8* ox, uint8* oy, int page) {
  if (!ox || !oy) return false;
  if (!sx || !sy) { *ox=*oy=0; return true; }
  for (y in y_range(page))
    for (x in 0 .. width-sx)
      if (cell_free(origin) && can_place(sx,sy,x,y))
        { *ox=x; *oy=y; return true; }
  return false;
}
```

### Competing storage orders

1. Column-major cells (`index = height*x + y`).
2. Misnamed dimensions (+8 height, +0xc width) with row-major — less likely given X scan uses +8.

---

## 5. Confirmed despite skepticism

1. First-fit nested search with early success.
2. Free predicate on 8-byte cells.
3. CanPlace gate for full footprint.
4. Page band math shape.
5. Clean ≡ raw CF.

---

## 6. Critical contradictions / risks

### C1 — Row-major narrative vs coded index

Docs that assume `index = y * 6 + x` for cargo must prove equivalence to `*(g+0xc)*x + y` under cargo dimensions (width 6). If `+0xc == height` (e.g. 13*pages), index is **not** `y*6+x`.

For width W=6, height H:  
- Row-major: `y*W + x`  
- Code: `H*x + y`  

These match only for specific (x,y) pairs, not generally. **This is a serious layout risk** for any port using row-major helpers.

### C2 — Corner free vs rect free

Single-cell prefilter can skip origins where corner occupied but… actually if corner occupied, rect cannot be free. If corner free, rect may still fail CanPlace. OK as optimization, not a bug — but docs should not claim this function alone proves multi-cell emptiness.

---

## 7. Residual uncertainty

| # | Item | Blocks seal? |
|---|------|--------------|
| R1 | Width/height field identity + storage order | **Yes** |
| R2 | CanPlace body | Yes for full parity |
| R3 | Page semantics | Medium |
| R4 | Runtime pack tests | Yes |
| R5 | Zero-size success intent | Mild |

---

## 8. Concrete checks performed

1. Re-derived scan order and free predicate from raw.
2. Compared free predicate to allocate fill pattern.
3. Algebraically compared coded index to row-major cargo narrative — **mismatch risk**.
4. Cross-read place unit index (also uses `+0xc` multiplier).
5. Line-compared clean vs raw.
6. Attacked “whole rect checked here” claim.
7. Noted zero-dim success footgun.

---

## 9. Verdict

### **`needs-more-evidence`**

Algorithm shape (first-fit + CanPlace + free corner) is solid in the decompile. **Storage indexing vs project row-major cargo helpers is not reconciled** — that alone blocks a strong seal for ports.

### Stronger-verdict bar

1. Seal grid layout note: exact meaning of `+8/+0xc/+0x10/+0x18/+0x1c/+0x28`.
2. Prove cargo 6×N indexing equivalence or fix port helpers.
3. Decompile `FUN_00570840`.
4. Runtime: empty grid find 2×2 → observe outs and cell indices.

---

## 10. Scorecard

| # | Claim | Result |
|---|-------|--------|
| 1 | First-fit | **Holds** |
| 2 | Empty -1 halves | **Holds** |
| 3 | Row-major y*width+x | **Challenged** |
| 4 | Zero-size success | **CF holds; intent open** |
| 5 | Page band | **CF holds** |
| 6 | Finished modern API | **Fail** |

**Final verdict: `needs-more-evidence`**
