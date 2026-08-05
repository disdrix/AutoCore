# Review B (skeptical / adversarial): `aa_00570840` InventoryGrid_CanPlace

| Field | Value |
|---|---|
| **Stable ID** | `aa_00570840` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (dual seal — height*x+y index + page rule) |
| **Counterpart** | `reviews/A_aa_00570840_InventoryGrid_CanPlace.md` |
| **Residual scratch** | `reviews/a_00570840.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present and sealed** (A + B + residual; supersedes scaffold) |
| **Verdict** | **accept-with-gaps** on CF + **index sealed** + **page rule sealed**; **reject** overclaims that this places items, that cells are row-major, or that page rule is per-cell |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Function places / stamps items | **Falsified** — read-only can-place; stamp is `0x00571620` |
| 2 | Cell index is row-major `y*width+x` | **Falsified for client buffer** — `idx = height*x + y` |
| 3 | Only origin cell checked | **Falsified** — full footprint X outer / Y inner |
| 4 | Page rule uses pageIndex arg | **Falsified** — no pageIndex; uses `(originY % pageH) + sizeY <= pageH` |
| 5 | Page rule rechecked every cell | **Overstated / false** — single check at origin Y before loops |
| 6 | Occupied = lo dword only | **Falsified** — `(lo & hi) != 0xFFFFFFFF` |
| 7 | 5th arg is “flag int” | **Falsified** — `uint* conflictOut` COID pair (nullable) |
| 8 | Zero footprint fails | **Falsified vs raw** — can return 1 if bounds/page hold |
| 9 | Scaffold dual “already sealed” | **Falsified** — only raw body; this dual seals formulas |
| 10 | Ready for bit-exact complete | **Fail** — runtime/diff open |

---

## 2. Decisive dataflow — index + page (SEALED)

```
// InventoryGrid_CanPlace(this, sizeX, sizeY, ox, oy, conflictOut*)

if conflictOut:
  *conflictOut = (-1, -1)

if width(+0x08) < ox + sizeX: return 0
endY = oy + sizeY
height = *(+0x0c)
pageH  = *(+0x1c)
if endY > height: fall through fail
if (oy % pageH) + sizeY > pageH: fall through fail   // ★ page non-span SEALED

for x = ox .. ox+sizeX-1:            // outer
  for y = oy .. oy+sizeY-1:          // inner
    idx = height * x + y             // ★ index SEALED (full i32 height)
    lo, hi = cells[idx]              // *(+0x28) + idx*8
    if (lo & hi) != 0xFFFFFFFF:
      if !conflictOut: return 0
      if conflict empty: capture (lo,hi)
      else if (lo,hi) != captured: return 0
      // same COID: continue
return 1
```

Live body matches 2026-07-23 raw capture **byte-for-byte** (no decompiler drift). Residual: `a_00570840.md`.

**Cross-seals:** FindFree free probe same index; Place stamp `height*(ox+dx)+(oy+dy)` (`a_00571620`); allocate empty fill both dwords `-1`.

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Full rect occupancy scan | **High** | Overlap bugs |
| Column-major `height*x+y` | **High / Sealed** | Wrong client buffer linearization |
| Page non-span at origin Y | **High / Sealed** | Cross-page cargo placement |
| Bounds width/height | **High** | OOB place |
| Empty AND halves | **High** | False free/occupied |
| conflictOut multi-COID reject | **High** CF | Wrong swap/drop UI |
| Scan order X-outer Y-inner | **High** | Only matters if early-out side effects (conflict capture order) |
| Zero-size success | **High** CF | Port diverge |
| pageH==0 | **Risk** | DIV0 if bad construct |
| Runtime golden | **Open** | Residual parity |

---

## 4. Offset / formula attack checklist

| Item | Attack | Result |
|------|--------|--------|
| `+0x08` as width | Invented? | **No** — only X bound |
| `+0x0c` as height+stride | Invented? | **No** — Y bound + `idx` multiplier |
| `+0x1c` page height | Invented? | **No** — DIV/MOD of originY |
| `+0x28` cell base | Invented? | **No** — 8-byte loads |
| Row-major cell array | Compatible? | **No** for client buffer |
| Place uses same family | Cross-check | **Yes** |
| Side-effect stores on grid | Hidden? | **None** (conflictOut only) |
| Page rule = FindFree page window | Same? | **Related but different** — FindFree filters origin band; CanPlace forbids span |

### Algebra note

For width W, height H:

- Client cell: `H*x + y`
- UI/wire 0-based row-major: `y*W + x`

Disagree generally. AutoCore `CanPlace` uses coordinate sets + logical XY — **attack on “server wrong linear index” fails** for ports that never linearize client-style.

Page: remaining rows in page = `pageH - (oy % pageH)`; need `sizeY <= remaining`.

---

## 5. Surviving contract for AutoCore

```
CanPlace(gridW, gridH, pageH, occupied, x, y, sizeX, sizeY):
  reject size < 1                          // intentional diverge vs client 0-size success
  reject if x+sizeX > gridW or y+sizeY > gridH
  reject if (y % pageH) + sizeY > pageH    // sealed retail rule
  reject if any cell in rect occupied

// Do not implement client column-major buffer unless talking to retail memory.
// Logical (x,y) parity is what matters for ports.
```

Server tests already lock page-span and bounds (`InventoryGridPlacementTests`).

---

## 6. Caller evidence

| Caller | Address | Notes |
|--------|---------|-------|
| FindFreeSlot | `0x005713a0` | conflictOut **null**; sealed dual |
| PlaceItemFootprint | `0x00571620` | gate before stamp; null |
| FUN_00570af0 | `0x00570af0` | InvSize from clonebase |
| FUN_005715d0 | `0x005715d0` | footprint probe |
| FUN_00572360 | `0x00572360` | repack path |
| FUN_0085f220 | `0x0085f220` | UI path |

**Attack on “unused dead code”** fails — six live callers. **Attack on “always null conflict”** survives for Find/Place; other callers need per-unit residual if non-null is claimed.

---

## 7. Residual uncertainty

| # | Item | Blocks seal of index/page? |
|---|------|----------------------------|
| R1 | Runtime: 2×2 at (0,0) on empty → CanPlace true; at page edge span → false | **No** (formula sealed; goldens open) |
| R2 | conflictOut non-null producer | **No** for index/page |
| R3 | pageH==0 | Mild |
| ~~R4~~ | height*x+y | **Sealed** |
| ~~R5~~ | page non-span | **Sealed** |
| R6 | Bit-exact image | Yes for complete only |

---

## 8. Concrete checks performed

1. Live re-decompile of `0x00570840` — matches raw (no drift).
2. Re-derived index from body: `*(+0xc) * bVar2 + uVar7` with bVar2=x, uVar7=y.
3. Re-derived page: `(ulonglong)originY % pageH + sizeY <= pageH`.
4. Cross-read FindFree + Place residuals for same family.
5. Cross-read AutoCore `InventoryGridPlacement.CanPlace` — page rule text matches.
6. Attacked row-major / origin-only / place-claims — falsified.
7. Caller list via Ghidra `get_function_callers` (6).

---

## 9. Verdict

### **accept-with-gaps**

Index and page formulas are **sealed High**. Unit is read-only can-place with optional conflict COID capture. Not bit-exact complete until runtime/diff.

### Stronger-verdict bar (complete)

1. Runtime: empty 6×13, place 2×2 → CanPlace true; force page-span sizeY → false.
2. Optional: conflictOut non-null path with two distinct COIDs → reject; same COID multi-cell → accept.
3. pageH edge cases documented.

---

## 10. Scorecard

| # | Claim | Result |
|---|-------|--------|
| 1 | Full-rect free check | **Holds** |
| 2 | Index height*x+y | **Sealed High** |
| 3 | Page non-span | **Sealed High** |
| 4 | Client cells row-major | **Falsified** |
| 5 | Places items | **Falsified** |
| 6 | conflictOut is flag int | **Falsified** |
| 7 | Empty AND halves | **Holds** |
| 8 | Bit-exact complete | **Fail** (open) |
| 9 | Scaffold quality | **Superseded** |

**Final verdict: `accept-with-gaps`**
