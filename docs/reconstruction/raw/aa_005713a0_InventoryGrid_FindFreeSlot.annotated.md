# Annotated low-level: InventoryGrid_FindFreeSlot (`aa_005713a0`)

| Field | Value |
|---|---|
| **Stable ID** | `aa_005713a0` |
| **VA** | `0x005713a0` |
| **Module** | `autoassault.exe` @ image base `0x400000` |
| **Source raw** | `aa_005713a0_InventoryGrid_FindFreeSlot.md` (capture 2026-07-23; live re-decompile 2026-07-29 **identical**) |
| **System** | inventory-transfer |
| **Server parity** | `InventoryGridPlacement.TryFindFirstFree` (whole-grid / pageIndex=-1 path; size-0 intentionally diverges) |
| **Dual** | `reviews/A|B_aa_005713a0_*` strengthened 2026-07-29 |

---

## 1. Corrected signature

```c
// MSVC thiscall
bool /*u32 0/1*/ __thiscall InventoryGrid_FindFreeSlot(
    InventoryGrid* this,
    uint32_t sizeX,          // footprint width (low 8 bits used)
    uint32_t sizeY,          // footprint height (low 8 as char)
    uint8_t* outX,           // required non-null
    uint8_t* outY,           // required non-null
    int8_t pageIndex);       // -1 = whole grid from y=0; else page-scoped
```

| Name | Width | Role |
|---|---|---|
| `this` | ptr | Grid |
| `sizeX` | u32 (byte-significant) | Item `InvSizeX` |
| `sizeY` | u32/byte | Item `InvSizeY` |
| `outX` / `outY` | `uint8_t*` | Origin of free rect on success |
| `pageIndex` | i8 | `-1` full scan; else page `p` with y base = `pageHeight * p` |
| **return** | u32 | **1** success / trivial accept; **0** fail |

---

## 2. Control flow

```text
if (outX == NULL || outY == NULL) return 0

if (sizeX == 0 || sizeY == 0):
  *outX = 0; *outY = 0; return 1     // degenerate accept (not a place)

// y range
if pageIndex == -1:
  yStart = 0
  yLast  = height - sizeY            // this+0x0c - sizeY  (as i8 math in decomp)
else:
  pageH  = (i8)*(this+0x1c)
  yStart = pageH * pageIndex
  yLast  = yStart + (pageH - sizeY)

for y = yStart .. yLast:             // outer Y (byte)
  for x = 0 .. (width - sizeX):      // inner X
    cellIndex = height * x + y       // this+0x0c * x + y
    cell = cells[cellIndex]          // base this+0x28, stride 8
    if (cell.lo & cell.hi) == 0xFFFFFFFF:   // origin cell empty
      if CanPlace(sizeX, sizeY, x, y, 0):   // FUN_00570840
        *outX = x; *outY = y; return 1
return 0
```

Scan order: **Y outer, X inner** (first-fit) — matches `docs/inventory-grid-footprint.md`.

---

## 3. Decompiler corrections

| Artifact | Correction | Confidence |
|---|---|---|
| `param_2`/`param_3` as full u32 | Semantic **u8 footprint** dims; compared as `char` | **High** |
| `param_6 == -1` | Page unrestricted | **Confirmed** |
| Empty test `(lo & hi) == 0xFFFFFFFF` | Both halves must be empty-bits (AND form) | **Confirmed** |
| `FUN_00570840` | **CanPlace** full footprint (not only origin); thiscall; 5th arg `uint* conflictOut` (null here) | **Confirmed** (live decompile 2026-07-29) |
| `extraout_ECX` reassign `param_1` | Thiscall `this` recovery after callee | **Confirmed** (MSVC) |
| Index `height*x + y` | Column-major linearization vs docs’ row-major wire examples — **trust decompile for client occupancy** | **High** for client code; wire slot policy separate; AutoCore uses coord sets |

---

## 4. Side-effect order

1. Null-check out pointers (no write on fail).
2. Degenerate size path: **write** `*outX=*outY=0`, return 1.
3. Nested scan: **read-only** cells + **call** `FUN_00570840`.
4. On hit: **write** out coords, return 1.
5. No cell mutation, no locks, no network.

---

## 5. Field map

| Offset | Use |
|---|---|
| `this+0x08` | width — X loop bound |
| `this+0x0c` | height — Y range + index stride |
| `this+0x1c` | page height — page-scoped y window |
| `this+0x28` | cell array base |

---

## 6. Confidence / open

| Area | Level |
|---|---|
| First-fit Y→X | **Confirmed** |
| Empty cell predicate | **Confirmed** |
| CanPlace callee | **High** |
| Page clamp vs page-span rule `(y % pageH)+sizeY<=pageH` | **Confirmed in CanPlace** (`+0x1c`); FindFree pageIndex is separate Y window |
| i8 truncation on large heights | **Risk** if height > 127 (cargo multi-page) — decompiler uses `char` extensively |
