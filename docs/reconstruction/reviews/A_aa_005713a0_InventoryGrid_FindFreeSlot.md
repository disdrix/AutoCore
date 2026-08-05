# Review A (reconstruction fidelity): `aa_005713a0` InventoryGrid_FindFreeSlot

| Field | Value |
|---|---|
| **Stable ID** | `aa_005713a0` |
| **VA** | `0x005713a0` |
| **Canonical name** | `InventoryGrid_FindFreeSlot` |
| **Review date** | `2026-07-29` (dual residual strengthen — footprint scan formula) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw) |
| **Counterpart** | `reviews/B_aa_005713a0_InventoryGrid_FindFreeSlot.md` |
| **Residual scratch** | `reviews/a_005713a0.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present and strengthened** (A + B + residual formula seal; supersedes thin 2026-07-23 wave2 scaffold) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**First-fit free-rectangle search** for an inventory grid. Does **not** place/stamp cells.
Given footprint `(sizeX × sizeY)`, optional page filter, and two required out-bytes for origin:

1. Null `outX` or `outY` → return **0** (no write).
2. Either dim is **0** (tested as `char`) → write `(0,0)`, return **1** (degenerate success).
3. Else scan origins **Y outer, X inner**; on first origin whose corner cell is empty **and** `CanPlace` accepts the full rect, write outs and return **1**.
4. Exhausted → return **0**.

**Calling convention:** MSVC `__thiscall` — grid in `ECX` / decompiler `param_1`.

| Slot | Role | Evidence |
|------|------|----------|
| `this` | `InventoryGrid*` | Loads `+0x08/+0x0c/+0x1c/+0x28` |
| stack0 | `sizeX` (`u32`, low byte) | Compared as `char`; X bound uses `& 0xff` |
| stack1 | `sizeY` (`u32`/byte) | Compared as `char`; Y range uses as `char` |
| stack2 | `uint8_t* outX` | Required non-null |
| stack3 | `uint8_t* outY` | Required non-null |
| stack4 | `char pageIndex` | **`-1` / `0xFFFFFFFF`** = whole grid; else page window |

**Returns:** `u32` **1** hit / **0** miss (low byte is the meaningful flag).

**Side effects:** writes only the two out-bytes on success (or degenerate path). No cell mutation, no locks, no network.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005713a0_InventoryGrid_FindFreeSlot.md` |
| Annotated | `docs/reconstruction/raw/aa_005713a0_InventoryGrid_FindFreeSlot.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/InventoryGrid_FindFreeSlot.cpp` |
| Function record | `docs/reconstruction/functions/aa_005713a0_InventoryGrid_FindFreeSlot.md` |
| Prior dual (legacy scaffold) | thin A/B 2026-07-23; `aa_005713a0_reconstruction_review.md` / `_skeptical_review.md` |
| Live re-decompile | Ghidra MCP `decompile_function` @ `0x005713a0` (2026-07-29 residual) — **bit-identical to raw body** |
| CanPlace | Ghidra MCP re-decompile `FUN_00570840` @ `0x00570840` |
| Allocate empty fill | Ghidra `0x00570720` — all cell dwords `0xFFFFFFFF` |
| Place stamp family | residual `a_00571620` — `height*(ox+dx)+(oy+dy)` |
| Layout | `OBJECT_LAYOUTS.md` InventoryGrid partial; `aa_00570720` allocate |
| Server port | `InventoryGridPlacement.TryFindFirstFree` + tests |
| Callers (complete xref) | `0x00531570`, `0x005316c0`, `0x005714e0`, `0x00572360`, `0x00572730`, `0x00588290` |

**Not performed:** `disassemble_bytes`, Launcher, live memory pack tests, bit-exact diff.

---

## 3. Grid offsets (body-backed only)

| Offset | Width | Role | Raw evidence |
|--------|-------|------|--------------|
| `+0x08` | `i32` | Width (X extent) | X limit: `(width - (sizeX & 0xff)) + 1` |
| `+0x0c` | `i32` | Height + **index stride** | Y range (`page==-1`); `idx = *(+0xc) * x + y` |
| `+0x1c` | `i32` | Page height / window | Page branch: `yStart = pageH * pageIndex` |
| `+0x28` | ptr | Cell array base | Cells **8 B**; free test on both dwords |

Empty origin predicate (exact):

```c
(*(uint*)(cells + idx*8) & *(uint*)(cells + 4 + idx*8)) == 0xffffffff
```

Compatible with allocate fill (`both halves 0xFFFFFFFF`).

---

## 4. Control flow: clean ≡ raw ≡ live decompile

| Stage | Match |
|---|---|
| Null out-param guard → 0 | **Yes** |
| Zero-dim early success `(0,0)` → 1 | **Yes** |
| `pageIndex == -1` → `yStart=0`, `yLast=height-sizeY` | **Yes** |
| Else page band `yStart=pageH*p`, `yLast=yStart+(pageH-sizeY)` | **Yes** |
| Empty range (`yStart >= yLast+1`) → fall through to 0 | **Yes** |
| Outer Y / inner X first-fit | **Yes** |
| Origin free AND → `FUN_00570840` | **Yes** |
| On CanPlace hit: `*outX=x`, `*outY=y`, return 1 | **Yes** |
| Exhaust → return 0 | **Yes** |
| No place/stamp in this unit | **Yes** |

### 4.1 CanPlace call site (this unit)

Raw call:

```c
cVar1 = FUN_00570840(param_2, param_3, local_c, bVar2, 0);
param_1 = extraout_ECX;   // thiscall ECX restore of grid
```

Callee sealed as `__thiscall` with signature:

```c
uint __thiscall FUN_00570840(
    InventoryGrid* this,
    byte sizeX, byte sizeY, byte originX, byte originY,
    uint* conflictOut /* nullable */);
```

FindFreeSlot passes **null** conflict out (`0`). Live CanPlace confirms:

- bounds vs `+0x08` / `+0x0c`
- page non-span: `(y % pageH) + sizeY <= pageH` using `+0x1c`
- full footprint empty via same `height*x+y` index + `(lo&hi)==-1`
- optional conflict COID capture when `conflictOut != null` (unused here)

Clean previously typed CanPlace last arg as `int32_t flag` — **prototype error only**; call site value `0` still matches null. Corrected in clean plate (2026-07-29).

### 4.2 Indexing

```text
idx = *(this+0x0c) * x + y     // column-major with height stride
```

Logical `(x,y)` match AutoCore; wire slot examples `y*width+x` are a **different packing** (server set-of-coords / 1-based UI slots). Do not conflate cell-array linearization with logical coordinates.

### 4.3 Footprint scan formula (SEALED — dual residual 2026-07-29)

Authoritative residual: `reviews/a_005713a0.md`.

```text
// null outs → 0
// (char)sizeX==0 || (char)sizeY==0 → *outX=*outY=0; return 1

// Y band (char math):
//   pageIndex==-1: y0=0, yLast=(char)height-(char)sizeY
//   else: pageH=(char)*(+0x1c); y0=pageH*pageIndex; yLast=y0+(pageH-(char)sizeY)
// X limit (i32): xLimit = (width - (sizeX&0xff)) + 1   // x ∈ [0, xLimit)

// first-fit Y outer, X inner:
//   idx = height*x + y; origin free iff (lo&hi)==0xFFFFFFFF
//   then CanPlace(this, sizeX, sizeY, x, y, NULL) → write outs, return 1
// exhaust → 0
```

| Sub-formula | Live seal |
|---|---|
| Y-outer X-inner order | Raw ≡ live decompile |
| Inclusive Y to `yLast` via `y < (byte)(yLast+1)` | Raw |
| X bound subtraction form | Raw `(width - sizeX) + 1` |
| Free prefilter AND halves | Raw + allocate fill `0xFFFFFFFF` |
| CanPlace full rect + page non-span | Live `0x00570840` |
| Index family with Place | `a_00571620` stamp matches |

**Direct callers (6):** all pass `pageIndex=0xffffffff` except `FUN_005714e0` which passthroughs its last arg (observed call from `0x00588290` still uses `-1`).

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Y-outer X-inner first-fit | **High / Confirmed** | Raw + live + callers |
| Null outs → fail | **High** | Raw |
| Degenerate size → success (0,0) | **High** CF | Intent for ports: **deliberate diverge** OK |
| `pageIndex -1` whole grid | **High** | Raw; callers pass `0xffffffff` |
| Empty corner AND test | **High** | Raw + alloc fill |
| CanPlace full-rect gate | **High** | Live CanPlace body |
| `+0x08` width / `+0x0c` height+stride | **High** | Find + CanPlace + alloc |
| `+0x1c` page height | **High** | Find window + CanPlace modulo |
| Cell packing column-major | **High** (client storage) | Same formula in CanPlace + Place |
| Full scan formula (residual) | **High / Sealed** | `a_005713a0.md` |
| Direct callers whole-grid | **High / Sealed** | 5 direct + wrapper path default `-1` |
| i8 trunc on large height | **Risk** | Decomp uses `char` for Y band; index mult is full `i32` height |
| Runtime / bit-exact | **Open** | Deferred |

---

## 6. Gaps / open (do not block accept-with-gaps)

1. **Runtime / differential** — no live pack observation of outs + cell indices.
2. **i8 math** — retail uses `char` for Y range; ports using full `i32` height are safer and still match cargo (height ≤ 127 typical).
3. **pageIndex producers** — CF sealed; non-`-1` inputs only via `FUN_005714e0` last arg (no observed non-`-1` at residual time).
4. **Zero-size success** — AutoCore rejects 0×N / N×0 at port boundary (documented intentional).

**No clean-vs-raw fidelity rewrite required** beyond CanPlace prototype note.

---

## 7. Verdict

### **accept-with-gaps**

Clean is a faithful first-fit of a clear decompile. Live re-decompile sealed CF; CanPlace cross-check sealed the full-rect gate and layout labels. Gaps are runtime/diff, i8 edge heights, and intentional port divergences — not fidelity failures.

---

## Checklist (reviewer)

| Check | Result |
|---|---|
| Live decompile matches raw | **Pass** |
| Clean CF matches raw | **Pass** |
| Free test preserved | **Pass** |
| Page filter preserved | **Pass** |
| First-fit order preserved | **Pass** |
| CanPlace contract cross-checked | **Pass** (body) |
| Layout labels sealed for this unit | **Pass** (width/height/page/cells) |
| Footprint scan formula residual | **Pass / Sealed** (`a_005713a0.md`) |
| Caller pageIndex inventory | **Pass** (6 xrefs; direct = whole-grid) |
| Runtime / bit-exact | **Open** |
| Verdict | **accept-with-gaps** |
