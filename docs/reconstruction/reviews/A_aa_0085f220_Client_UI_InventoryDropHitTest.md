# Review A (reconstruction fidelity): `aa_0085f220` Client_UI_InventoryDropHitTest

| Field | Value |
|---|---|
| **Stable ID** | `aa_0085f220` |
| **VA** | `0x0085f220` |
| **Canonical name** | `Client_UI_InventoryDropHitTest` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (raw ≡ live decompile ≡ call-site asm) |
| **Counterpart** | `reviews/B_aa_0085f220_Client_UI_InventoryDropHitTest.md` |
| **System** | `inventory-transfer` |
| **Live re-decompile** | Ghidra MCP `decompile_function` + `read_memory` @ `0x0085f220` / helpers / call sites |
| **Verdict** | **accept-with-gaps** — ABI, page-local outs, CanPlace absolute-Y, half-cell pitch **sealed**; full pixel-rect vtable map still Probable |

---

## 1. Purpose

**Drop hit-test** for inventory UI grids (primary consumer: `Client_UI_InventoryDropToGrid` @ `0x00860a50`).

Given a held item object and the inventory window:

1. Fail if item / out pointers / type-host missing, or pointer is outside the grid hit rect.
2. Convert pointer position → **page-local** cell `(X,Y)` via page dims × relative fraction + half-cell snap + footprint clamp.
3. Gate with `InventoryGrid_CanPlace` (`FUN_00570840`) using **absolute** origin Y = `pageH * pageIdx + cellY`.
4. Optionally resolve the cell occupant object and refresh a ghost/preview widget.
5. Return **1** on success (outs written), **0** on any reject (no packet send here).

Does **not** build or send C2S drop; does **not** stamp cells (`PlaceItemFootprint` is DropResponse-side).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0085f220_FUN_0085f220.md` |
| Annotated | `docs/reconstruction/raw/aa_0085f220_FUN_0085f220.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0085f220.cpp` |
| Function record | `docs/reconstruction/functions/aa_0085f220_FUN_0085f220.md` |
| Live body | Ghidra decompile `0x0085f220` (matches raw CF) |
| Entry / epilogue bytes | `read_memory` `0x0085f220`, `0x0085f5e0` → **`ret 0x0c`** |
| DropToGrid call site | `read_memory` `0x00860a50`–`0x00860a8a` |
| Sibling call sites | `0x0085fc2c`, `0x00861634` (xrefs; bodies not named functions in Ghidra) |
| Page dims | `FUN_0085f1d0` / `FUN_0085f1f0` bytes (`window+0x56c` → `+0x1c` / `+0x18`) |
| Cell→pixel reverse | `FUN_0085e820` |
| CanPlace | `FUN_00570840` (dual-sealed via FindFreeSlot) |
| Pitch constants | `read_memory` `0x00aaa678`–`0x00aaa6ac` |
| DropToGrid residual | `A_/B_aa_00860a50_…_residual.md` (outs → packet `+0x18/+0x19`) |
| System map | `systems/inventory-transfer.md` |

**Not performed:** `disassemble_bytes` (per project RE rules), Launcher, live pointer capture, bit-exact EXE diff.

---

## 3. ABI (SEALED)

| Slot | Role | Evidence |
|------|------|----------|
| **EAX** | Held / cursor item object* | Prolog `mov edi, eax`; DropToGrid loads `DAT_00d1b1f8` into EAX before call; site `0x00861634` same |
| **ESI** | Inventory UI window* | Prolog tests `[esi+0x56c]`; DropToGrid `mov esi, eax` (this); site `0x0085fbf0` `mov esi, ecx` |
| stack0 | `uint8_t* outCellX` | Required non-null; written page-local X |
| stack1 | `uint8_t* outCellY` | Required non-null; written page-local Y |
| stack2 | `void** outOccupant` | Optional write path when non-null; DropToGrid zeros then passes `&local_104` |
| return | `AL` 0/1 | `test al` at all three call sites |
| cleanup | **`ret 0x0c`** | Epilogue `c2 0c 00` → **stdcall 3 stack dwords** |

```c
// Custom dual-register + stdcall outs (not pure thiscall)
uint8_t __stdcall Client_UI_InventoryDropHitTest(
    uint8_t* outCellX,
    uint8_t* outCellY,
    void**   outOccupant /* nullable write target */);
// EAX = item*, ESI = window*  (caller-owned)
```

Null gate (entry):

```text
if (!item || !outX || !outY || !*(window+0x56c)) return 0;
```

(`window+0x56c` = type host / grid binder — same host DropToGrid uses for `ucTypeTo`.)

---

## 4. Control flow: live ≡ raw

| Stage | Match |
|---|---|
| Null item / outs / typeHost → 0 | **Yes** |
| UI rect / pointer containment fails → 0 | **Yes** (vtable `+0x120` / `+0x144` / `+0x140` family) |
| Ratio → cell floor | **Yes** |
| Clamp negative cell → 0 | **Yes** |
| Half-cell +1 snap | **Yes** (asm pitch products) |
| Footprint clamp vs pageW/pageH | **Yes** (`item+0x4a0/+0x4a4`) |
| Write `*outX/*outY` page-local | **Yes** |
| `CanPlace` fail → 0 | **Yes** |
| Resolve occupant via cell TFID → `FUN_00413b30` | **Yes** when outOccupant non-null |
| No ghost widget (`window+0x574==0`) → return 1 | **Yes** |
| Ghost path: `FUN_0085e820` + color + `+0x34c` refresh | **Yes** |
| Success return 1 | **Yes** |

---

## 5. Sealed formulas

### 5.1 Page dimensions (helpers)

```text
// FUN_0085f1f0 (bytes @ 0x0085f1f0): EAX=window
typeHost = *(window + 0x56c)
pageW    = typeHost ? *(i32*)(typeHost + 0x18) : 0

// FUN_0085f1d0 (bytes @ 0x0085f1d0): EAX=window
pageH    = typeHost ? *(i32*)(typeHost + 0x1c) : 0
```

Matches DropToGrid residual (page height for wire Y) and InventoryGrid `+0x1c` page dim family.

### 5.2 Cell from pointer (CF shape; rect sources Probable)

```text
cellX0 = (int)( pageW * (float)deltaX / (float)hitRectW )
cellY0 = (int)( pageH * (float)deltaY / (float)hitRectH )
// then clamp negatives to 0; half-cell snap; footprint clamp
```

`delta*` / `hitRect*` come from UI vtable getters on window (`+0x120`) and item/cursor (`+0x144` / `+0x120`) plus size query `+0x140` — exact field names not sealed beyond “screen/rect integers.”

### 5.3 Half-cell snap pitch (SEALED constants)

Static floats @ `0x00aaa678`:

| Address | Value | Role in body |
|--------:|------:|--------------|
| `DAT_00aaa67c` | `+0.000625` (`1/1600`) | X half numerator |
| `_DAT_00aaa6ac` | `−0.000625` | X pitch (with screen scale) |
| `DAT_00aaa678` | `+0.000833333…` (`1/1200`) | Y half numerator |
| `_DAT_00aaa6a8` | `−0.000833333…` | Y pitch |

```text
pitchX ≈ (int)( (float)DAT_00d1e818 * (float)_DAT_00d1e50c * 0.000625 )
// if mouseRelX > pitchX*cellX + pitchX/2 → cellX++
// symmetric for Y with DAT_00d1e81c / _DAT_00d1e510 / 0.000833…
```

`DAT_00d1e818/81c` and `_DAT_00d1e50c/510` are **runtime** (static image zeros) — formula sealed; live magnitudes open.

Reverse map `FUN_0085e820` uses the same pitch constants to convert cell → pixel for ghost placement (`origin - (pitch_neg)*cell` ≡ `origin + |pitch|*cell`).

### 5.4 Footprint clamp (SEALED offsets)

```text
sizeX = *(i32*)(item + 0x4a0)   // dword slot; used as byte extent
sizeY = *(i32*)(item + 0x4a4)
if (cellX + sizeX > pageW) cellX = pageW - sizeX
if (cellY + sizeY > pageH) cellY = pageH - sizeY
*outX = cellX; *outY = cellY   // page-local
```

English “InvSize cache on item” is **Probable** (clonebase blob `+0x406/+0x407` is the authoritative InvSize elsewhere); offset use in this unit is **High**.

### 5.5 CanPlace call (SEALED)

```text
absY = (i8)pageH * (i8)*(window + 0x564) + cellY   // pageIdx @ window+0x564 (slot 0x159)
// thiscall:
CanPlace( typeHost /*ECX=*(window+0x56c)*/,
          sizeX, sizeY, cellX, absY,
          &conflictTfidPair )
```

Same product shape as DropToGrid wire Y (`pageH × pageIdx + cellY`) and FindFree page band. Conflict pair: empty `0xFFFFFFFF` halves → `*outOccupant=0`; else `FUN_00413b30(lo,hi)` object resolve.

### 5.6 Ghost / preview (when `window+0x574 != 0`)

| Path | Color arg | Notes |
|------|-----------|--------|
| Empty / no occupant | stack `0xff828282` | Gray placeholder |
| Occupied cell | `&DAT_00afdad8` | Highlight occupied |
| Type host `+4 == 5` and held class `+0x38 == 4` | `&DAT_00afdad4` (`0xFFFFFFFF` static) | Trade special |

Position via `FUN_0085e820(cellX, window?, cellY)` then vtable `+0x11c` / `+0x138` / `+0x15c` / `+0x34c` on ghost object.

---

## 6. Callers (xrefs)

| Call site | Enclosing | Notes |
|----------:|-----------|--------|
| `0x00860a7e` | `Client_UI_InventoryDropToGrid` | Named; ESI=this, EAX=`DAT_00d1b1f8`, outs local X/Y + object |
| `0x0085fc2c` | Unnamed start ~`0x0085fbf0` | `mov esi,ecx`; type check `*(typeHost+4)==7` after |
| `0x00861634` | Unnamed start ~`0x00861618` | `mov esi,edi`; EAX=`DAT_00d1b1f8` |

Ghidra `get_function_callers` only lists DropToGrid (other two not in function DB). Xref list has all three.

---

## 7. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Role = drop cell hit-test + CanPlace gate | **High** | Callers + CF |
| EAX item / ESI window / ret 0x0c | **Confirmed** | Prolog + epilogue + sites |
| Outs page-local X/Y | **Confirmed** | Write before CanPlace absY |
| CanPlace absY = pageH×pageIdx+cellY | **Confirmed** | `imul [esi+0x564]` asm |
| pageW/H via `+0x18/+0x1c` on typeHost | **Confirmed** | Helper bytes |
| Half-cell pitch constants | **Confirmed** | Static floats |
| item `+0x4a0/+0x4a4` = footprint extents | **High** CF; InvSize English **Probable** |
| typeHost is InventoryGrid* | **Probable** | CanPlace this; offsets align with grid layout |
| Exact mouse rect vtable math | **Tentative** | Decompiler stack noise |
| Ghost widget full type | **Tentative** | vtable-only |
| Runtime pitch magnitudes | **Open** | BSS zeros in image |

---

## 8. Gaps / open

1. Full typed UI rect pipeline (which vtable returns which edge/size).
2. Confirm `item+0x4a0/+0x4a4` always mirrors clonebase InvSize (vs temporary UI state).
3. Name/identity of callers @ `0x0085fbf0` / `0x00861618`.
4. Live multi-page drop with `pageIdx≠0` (absY vs page-local outs).
5. Differential / bit-exact vs retail EXE.

**Verdict:** **accept-with-gaps.** Core hit-test contract for DropToGrid is dual-sealed.
