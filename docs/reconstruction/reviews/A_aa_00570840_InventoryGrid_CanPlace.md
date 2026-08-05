# Review A (reconstruction fidelity): `aa_00570840` InventoryGrid_CanPlace

| Field | Value |
|---|---|
| **Stable ID** | `aa_00570840` |
| **VA** | `0x00570840` |
| **Canonical name** | `InventoryGrid_CanPlace` |
| **Review date** | `2026-07-29` (dual seal — height*x+y index + page rule) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw) |
| **Counterpart** | `reviews/B_aa_00570840_InventoryGrid_CanPlace.md` |
| **Residual scratch** | `reviews/a_00570840.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present and sealed** (A + B + residual; supersedes 2026-07-23 scaffold) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Full-rectangle can-place test** for an inventory grid footprint. Does **not** stamp cells or search free slots.

Given `(sizeX × sizeY)` at origin `(originX, originY)`:

1. Optional `conflictOut` (nullable `uint[2]` COID pair) cleared to `(-1,-1)`.
2. Fail if `originX + sizeX > width(+0x08)` (signed: `width < endX`).
3. Fail if `originY + sizeY > height(+0x0c)`.
4. Fail if **page span**: `(originY % pageH(+0x1c)) + sizeY > pageH`.
5. Else scan every cell in the rect (**X outer, Y inner**); occupied cells either fail or update/validate conflict COID.
6. All empty (or single-COID conflict allowed) → return **1**; else **0**.

**Calling convention:** MSVC `__thiscall` — grid in `ECX` / decompiler `param_1`.

| Slot | Role | Evidence |
|------|------|----------|
| `this` | `InventoryGrid*` | Loads `+0x08/+0x0c/+0x1c/+0x28` |
| stack0 | `sizeX` (`byte`) | Added to originX for endX |
| stack1 | `sizeY` (`byte`) | Added to originY for endY; page remainder test |
| stack2 | `originX` (`byte`) | Outer loop cursor `bVar2` |
| stack3 | `originY` (`byte`) | Y start; `% pageH` for page rule |
| stack4 | `uint* conflictOut` | Nullable; two dwords = COID pair |

**Returns:** `u32` with low byte **1** fit / **0** reject (`& 0xffffff00` on fail; success via `CONCAT31(...,1)`).

**Side effects:** only writes `conflictOut` when non-null. No cell mutation.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00570840_FUN_00570840.md` |
| Annotated | `docs/reconstruction/raw/aa_00570840_FUN_00570840.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/InventoryGrid_CanPlace.cpp` |
| Function record | `docs/reconstruction/functions/aa_00570840_InventoryGrid_CanPlace.md` |
| Residual seal | `reviews/a_00570840.md` |
| Live re-decompile | Ghidra MCP `decompile_function` @ `0x00570840` (2026-07-29) — **bit-identical to raw body** |
| Callers | Ghidra `get_function_callers` — 6 sites |
| FindFree dual | `A/B_aa_005713a0` — null conflictOut call site |
| Place residual | `a_00571620` — stamp same index family |
| Layout | `OBJECT_LAYOUTS.md` InventoryGrid partial |
| Server port | `InventoryGridPlacement.CanPlace` |

**Not performed:** `disassemble_bytes`, Launcher, live memory pack tests, bit-exact diff.

---

## 3. Grid offsets (body-backed only)

| Offset | Width | Role | Raw evidence |
|--------|-------|------|--------------|
| `+0x08` | `i32` | Width (X extent) | `if (width < originX+sizeX) fail` |
| `+0x0c` | `i32` | Height + **index stride** | `endY <= height`; `idx = *(+0xc) * x + y` |
| `+0x1c` | `i32` | Page height | `(originY % pageH) + sizeY <= pageH` |
| `+0x28` | ptr | Cell array base | `cells + idx*8`; lo/hi dwords |

Empty cell predicate (exact):

```c
(*(uint*)(cells + idx*8) & *(uint*)(cells + 4 + idx*8)) == 0xffffffff
```

Compatible with allocate fill (`both halves 0xFFFFFFFF`).

---

## 4. Control flow: clean ≡ raw ≡ live decompile

| Stage | Match |
|---|---|
| conflictOut init to `(-1,-1)` | **Yes** |
| X bound `width < originX+sizeX` → 0 | **Yes** |
| Y bound `originY+sizeY <= height` | **Yes** |
| Page non-span `(y%pageH)+sizeY <= pageH` | **Yes** |
| Outer X / inner Y full-rect scan | **Yes** |
| Index `height * x + y` | **Yes / Sealed** |
| Empty AND halves | **Yes** |
| conflict null → fail on first occupied | **Yes** |
| conflict capture first COID; reject second distinct | **Yes** |
| Success return 1 | **Yes** |
| Fail return 0 (high bytes cleared) | **Yes** |
| No cell stamp in this unit | **Yes** |

### 4.1 Index formula (SEALED)

```text
idx = *(i32*)(this + 0x0c) * (uint)x + y
// column-major storage with height as stride
// x,y are absolute grid coordinates of each cell in the footprint
```

Cross-seals:

- FindFree origin probe: same expression (`a_005713a0`)
- Place stamp: `height*(ox+dx)+(oy+dy)` (`a_00571620` byte residual)

Logical `(x,y)` match AutoCore. Wire/UI 1-based slots / row-major `y*width+x` are a **different packing**.

### 4.2 Page rule (SEALED)

```text
pageH = *(i32*)(this + 0x1c)
// require: (originY % pageH) + sizeY <= pageH
```

Cargo grids use page height **13**. Item footprint must not cross page bands. Checked at origin Y only; with `endY <= height` this prevents multi-page spans.

### 4.3 Parameter map (sealed)

```c
uint __thiscall InventoryGrid_CanPlace(
    InventoryGrid* this,
    byte sizeX, byte sizeY, byte originX, byte originY,
    uint* conflictOut /* nullable; two dwords */);
```

Decompiler names: `param_2=sizeX`, `param_3=sizeY`, `param_4=originX`, `param_5=originY`, `param_6=conflictOut`. Confirmed by loop roles (outer adds to param_4-as-x, inner walks y from param_5) and FindFree call `FUN_00570840(sizeX, sizeY, x, y, 0)`.

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Full-rect can-place (not place/search) | **High / Confirmed** | Raw + callers |
| Index `height * x + y` | **High / Sealed** | Live ≡ raw; Find/Place family |
| Page non-span `(y%pageH)+sizeY<=pageH` | **High / Sealed** | Live; AutoCore port matches |
| `+0x08` width / `+0x0c` height+stride | **High** | Bounds + index |
| `+0x1c` page height | **High** | DIV/MOD + residual |
| `+0x28` 8-byte cells; empty AND | **High** | Raw + alloc fill |
| conflictOut COID capture semantics | **High** CF | Producers of non-null partially open |
| X-outer Y-inner scan order | **High** | Raw do/while structure |
| Degenerate 0-size success | **High** CF | AutoCore rejects intentionally |
| Runtime / bit-exact | **Open** | Deferred |

---

## 6. Gaps / open (do not block accept-with-gaps)

1. **Runtime / differential** — no live observation of conflictOut capture or multi-page rejects.
2. **Non-null conflictOut callers** — CF sealed; which UI/transfer paths pass a buffer remains open.
3. **pageH == 0** — DIV by zero risk if mis-constructed grid; cargo always pageH=13.
4. **Zero-size success** — ports should document intentional diverge (AutoCore rejects).

**No clean-vs-raw fidelity issue** after named clean rewrite.

---

## 7. Verdict

### **accept-with-gaps**

Live re-decompile matches raw. **Index `height*x+y` and page non-span rule are sealed.** Sibling FindFree/Place duals confirm the same cell packing family. Gaps are runtime/diff and conflictOut producer inventory — not formula fidelity.

---

## Checklist (reviewer)

| Check | Result |
|---|---|
| Live decompile matches raw | **Pass** |
| Index formula residual sealed | **Pass / Sealed** (`a_00570840.md`) |
| Page rule residual sealed | **Pass / Sealed** |
| Empty AND test preserved | **Pass** |
| Bounds vs width/height | **Pass** |
| conflictOut optional path | **Pass** (CF) |
| Layout labels sealed for this unit | **Pass** |
| Cross-family FindFree/Place | **Pass** |
| Runtime / bit-exact | **Open** |
| Verdict | **accept-with-gaps** |
