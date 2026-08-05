# Review B (skeptical / adversarial): `aa_005713a0` InventoryGrid_FindFreeSlot

| Field | Value |
|---|---|
| **Stable ID** | `aa_005713a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (dual residual strengthen — footprint scan formula) |
| **Counterpart** | `reviews/A_aa_005713a0_InventoryGrid_FindFreeSlot.md` |
| **Residual scratch** | `reviews/a_005713a0.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present and strengthened** (A + B + residual formula seal; supersedes thin 2026-07-23 wave2 scaffold + legacy skeptical `needs-more-evidence`) |
| **Verdict** | **accept-with-gaps** on CF + layout + **scan formula sealed**; **reject** overclaims that this unit alone “places items” or that client cell packing is row-major |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Function places / stamps items | **Falsified** — search + out-params only; place is `0x00571620` |
| 2 | Scan is X-outer Y-inner | **Falsified** — outer `bVar2` is Y; inner `bVar6` is X |
| 3 | Always scans page 0 only | **Falsified** — `pageIndex==-1` whole grid; else page band |
| 4 | This function alone proves full rect free | **Overstated** — corner free is prefilter; full rect is `FUN_00570840` |
| 5 | Client cells are row-major `y*width+x` | **Falsified for cell array** — `idx = height*x + y`; logical (x,y) still match ports |
| 6 | Empty cell is only `lo==-1` | **Falsified** — `(lo & hi) == -1` (both halves all-ones) |
| 7 | Zero footprint fails | **Falsified vs raw** — success at (0,0); AutoCore **intentionally rejects** at port |
| 8 | CanPlace 5th arg is “flag int” | **Falsified** — `uint* conflictOut`; FindFreeSlot passes null |
| 9 | Wave2 dual A/B “sealed” quality | **Falsified** — scaffold-only; this dual supersedes |
| 10 | Ready for bit-exact seal | **Fail** — runtime/diff open |

---

## 2. Decisive dataflow — footprint scan formula (SEALED)

```
if (!outX || !outY) return 0
if ((char)sizeX==0 || (char)sizeY==0) { *outX=*outY=0; return 1 }

if pageIndex == -1:
  y = 0
  yLast = (char)height - (char)sizeY          // height @ +0x0c  (char math)
else:
  pageH = (char)*(+0x1c)
  y = pageH * pageIndex                       // byte product
  yLast = y + (pageH - (char)sizeY)

// Y loop guard: y < (byte)(yLast + 1)  → inclusive [y0, yLast]
// X limit: (width(+0x08) - (sizeX & 0xff)) + 1  → x ∈ [0, width-sizeX]

for y .. yLast:                                // outer
  for x = 0 .. (width - sizeX):                // inner
    idx = height * x + y                       // full i32 height × x + y
    cell = *(+0x28) + idx*8
    if (cell.lo & cell.hi) == 0xFFFFFFFF:      // origin prefilter only
      if CanPlace(this, sizeX, sizeY, x, y, NULL):  // full rect + page non-span
        *outX=x; *outY=y; return 1
return 0
```

Live body matches 2026-07-23 raw capture **byte-for-byte** (no decompiler drift). Residual scratch: `a_005713a0.md`.

**Cross-seals:** allocate fills all cell dwords `0xFFFFFFFF` (`0x00570720`); Place stamp uses same `height*(ox+dx)+(oy+dy)` (`a_00571620`); CanPlace page rule `(y % pageH) + sizeY <= pageH`.

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| First-fit Y→X order | **High** | Different free origin vs retail |
| Degenerate size success | **High** CF | Ports that fail diverge (AutoCore does) |
| pageIndex band math | **High** | Wrong page loot / UI page |
| Corner free AND predicate | **High** | False free / false full |
| CanPlace full footprint | **High** | Overlap / page-span bugs |
| Column-major cell index | **High** | Wrong client memory layout (not logical XY) |
| `+0x08/+0x0c/+0x1c/+0x28` labels | **High** | Bounds / stride / page wrong |
| i8 truncation for height>127 | **Tentative risk** | Multi-page tall grids |
| Server row-major wire slots | **N/A to this unit** | Wire/UI packing separate |
| Runtime golden pack | **Open** | Residual parity risk |

---

## 4. Offset / formula attack checklist

| Item | Attack | Result |
|------|--------|--------|
| `+0x08` as width | Invented? | **No** — X bound only |
| `+0x0c` as height+stride | Invented? | **No** — Y range + `idx` multiplier; CanPlace same |
| `+0x1c` page height | Invented? | **No** — page branch + CanPlace `%`/`/` |
| `+0x28` cell base | Invented? | **No** — load + 8-byte stride |
| Row-major `y*w+x` cell array | Compatible? | **No** for client buffer; ports using `(x,y)` sets are fine |
| Place unit uses same index family | Cross-check | **Yes** (OBJECT_LAYOUTS / place record) |
| Side-effect stores on grid | Hidden? | **None** |

### Algebra note (legacy skeptical C1)

For width W, height H:

- Client cell: `H*x + y`
- UI/wire 0-based row-major slot: `y*W + x`

These agree only for special cases, **not** generally. AutoCore `InventoryGridPlacement` comment already states: logical (x,y) match; storage order differs. **Attack on “server uses wrong index in TryFindFirstFree” fails** — server tracks occupied as coordinate pairs, not client column-major buffer.

---

## 5. Surviving contract for AutoCore

```
TryFindFirstFree ≈ FindFreeSlot(grid, sx, sy, outX, outY, pageIndex=-1):
  Y outer, X inner
  origin free then full CanPlace (bounds + page non-span + all cells free)
  first hit wins

Intentional port divergences (keep documented):
  - size 0 → false (client: success @ 0,0)
  - no pageIndex filter surface (always whole-grid + CanPlace page rule)
  - occupancy as HashSet<(x,y)> not 8-byte COID cells
```

Server tests (`InventoryGridPlacementTests`) already lock Y-then-X packing, page-span, and subtraction bounds.

---

## 6. Caller evidence (pageIndex) — complete xref seal

| Caller | pageIndex passed | Notes |
|--------|------------------|-------|
| `0x00531570` | `0xffffffff` | Whole grid; InvSize from blob+0x406/407 |
| `0x005316c0` | `0xffffffff` | Whole grid |
| `0x00572360` | `0xffffffff` | Repack: CanPlace at saved origin else FindFree |
| `0x00572730` | `0xffffffff` | Sort/repack into temp grid |
| `0x00588290` | `0xffffffff` | Direct 2×2 if both InvSize 0; else `FUN_005714e0(..., -1)` |
| `0x005714e0` | `param_5` passthrough | Only path that can pass non-`-1` |

**Attack on “always page 0 only” remains falsified** (whole-grid is the default). **Attack on “page band is dead code”** fails — branch is live CF; but **all six xrefs** either hardcode whole-grid or passthrough (observed wrapper call uses `-1`). Non-`-1` producers of `FUN_005714e0` last arg remain open (outside this unit).

---

## 7. Residual uncertainty

| # | Item | Blocks seal? |
|---|------|--------------|
| R1 | Runtime pack: empty 6×13 find 2×2 → outs (0,0) | **Yes** for bit-exact / complete |
| R2 | i8 height on tall multi-page cargo | Mild (cargo pageH=13; pages few; index mult is i32) |
| R3 | Conflict-out path of CanPlace | No for FindFreeSlot (null) |
| R4 | Stamp formula in PlaceItemFootprint | **Closed for family** (`a_00571620`); place unit separate |
| R5 | Non-`-1` pageIndex producers via `FUN_005714e0` | Mild (CF sealed; no live producer found) |
| ~~R6~~ | Footprint scan formula | **Sealed** this residual |

---

## 8. Concrete checks performed

1. Live re-decompile of `0x005713a0` — matches raw (residual re-confirm).
2. Live re-decompile of `FUN_00570840` — seals page-span + full-rect empty + index.
3. Live re-decompile of allocate `0x00570720` — empty fill all dwords `-1`.
4. Re-derived scan formula (Y band, X limit, free AND, CanPlace) — **sealed** in `a_005713a0.md`.
5. Algebraically separated client cell packing vs server logical coords.
6. Full xref caller inventory (6 sites) for `pageIndex`.
7. Cross-read Place residual stamp family + AutoCore `TryFindFirstFree` + tests.
8. Attacked wave2 dual quality (scaffold-only) — **replaced**; formula residual closed.

---

## 9. Verdict

### **accept-with-gaps**

Algorithm shape is solid and re-sealed. Storage-order attack from legacy skeptical review is **resolved for ports that use coordinate sets** (AutoCore); it remains a true warning only for anyone who linearizes with `y*width+x` against the **client** cell buffer. Runtime/diff still open → not complete / not bit-exact.

### Stronger-verdict bar (complete)

1. Runtime: empty cargo find 2×2 → observe outs + stamped cell indices after place.
2. Optional: pageIndex≠−1 path with multi-page grid golden.
3. Close i8 risk with height samples >127 or document retail limit.

---

## 10. Scorecard

| # | Claim | Result |
|---|-------|--------|
| 1 | First-fit free rect (with CanPlace) | **Holds** |
| 2 | Empty AND halves | **Holds** |
| 3 | Client cell row-major | **Falsified** (column-major storage) |
| 4 | Logical XY match ports | **Holds** |
| 5 | Zero-size success (client) | **Holds** |
| 6 | Places items | **Falsified** |
| 7 | Finished modern API / bit-exact | **Fail** |
| 8 | Wave2 dual quality | **Superseded** |
| 9 | Footprint scan formula residual | **Sealed High** |
| 10 | All direct callers whole-grid | **Holds** (xref) |

**Final verdict: `accept-with-gaps`**
