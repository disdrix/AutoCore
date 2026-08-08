# Review A (reconstruction fidelity): `aa_00570af0` InventoryGrid_MoveItemFootprint_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00570af0` |
| **VA** | `0x00570af0` |
| **Canonical name** | `InventoryGrid_MoveItemFootprint_Inferred` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw + live bytes) |
| **Counterpart** | `reviews/B_aa_00570af0_InventoryGrid_MoveItemFootprint_Inferred.md` |
| **Residual scratch** | `reviews/a_00570af0.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** (first full dual; supersedes 2026-07-23 scaffold) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Relocate an already-bound item** on a client inventory grid from its **current** footprint origin to a **new** `(originX, originY)`:

1. Null item → **0**.
2. `CanPlace(InvSizeX, InvSizeY, originX, originY, local conflictOut)` → fail **0**.
3. Clear old footprint at current `(vtbl+0x250, vtbl+0x254)` to empty `0xFFFFFFFF` pairs.
4. `vtbl+0x24c(originX, originY)` — set item grid origin.
5. Stamp item COID (`item+0x160/+0x164`) into every new footprint cell.
6. If `*(grid+0x24) != 0`: `FUN_00512670(that)`; `*(grid+0x21) = 1`; return **1**.

Does **not** re-bind list membership, reject type classes, or set quantity (contrast `PlaceItemFootprint` / `RemoveItem`).

**Calling convention:** MSVC `__thiscall` — grid in `ECX`. Callee **`RET 0x0C`** → **three** stack dwords.

| Slot | Role | Evidence |
|------|------|----------|
| `this` | `InventoryGrid*` | Prologue `MOV EBP, ECX`; loads `+0x0c/+0x21/+0x24/+0x28` |
| stack0 | `ItemObject*` | Prologue `MOV ESI, [ESP+0x20]` after `SUB ESP,0x14; PUSH EBP; PUSH ESI` |
| stack1 | `originX` | Passed to CanPlace + SetPos + stamp base |
| stack2 | `originY` | Same |

**Returns:** low-byte **1** success / **0** fail. Epilogue: `B0 01` … `C2 0C 00`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00570af0_FUN_00570af0.md` |
| Annotated | `docs/reconstruction/raw/aa_00570af0_FUN_00570af0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/InventoryGrid_MoveItemFootprint_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00570af0.cpp` |
| Function record | `docs/reconstruction/functions/aa_00570af0_InventoryGrid_MoveItemFootprint_Inferred.md` |
| Residual | `docs/reconstruction/reviews/a_00570af0.md` |
| Live decompile | Ghidra `batch_decompile` / `analyze_function_complete` @ `0x00570af0` |
| Live bytes | `read_memory` prologue, clear core, stamp core `0x00570c40+`, epilogue |
| CanPlace sibling | `aa_00570840` (lists this VA as InvSize caller) |
| Place / Remove siblings | `aa_00571620` stamp; `aa_00571b80` clear |

**Not performed:** `disassemble_bytes`, Launcher, CE live cell dump, bit-exact.

---

## 3. Stamp / clear formulas (byte-sealed)

```text
// clear old (curX,curY from vtbl+0x250/+0x254; size from blob+0x406/+0x407)
index = *(grid+0x0c) * x + y
cells[index].lo/hi = 0xFFFFFFFF

// stamp new
// dx in [0, sizeX), dy in [0, sizeY)
index = *(grid+0x0c) * (originX + dx) + (originY + dy)
cells[index].lo = item+0x160
cells[index].hi = item+0x164
```

| Opcode evidence (stamp) | Role |
|-------------------------|------|
| `8B 55 0C` | `EDX = [EBP+0x0c]` height |
| `0F AF 54 24 18` | `IMUL EDX, [ESP+baseX]` with `baseX = originX+dx` |
| `03 D0` / `03 54 24 1C` | `+ dy` then `+ originY` |
| `8B 9E 60 01 00 00` / `8B 9E 64 01 00 00` | COID lo/hi `item+0x160/+0x164` |
| `89 1C D7` / `89 5C D7 04` | store at `cells[idx*8]` |

Same packing as CanPlace / Place / Remove / FindFree: **`height * x + y`**.

### Decompiler corrections (bytes override)

| Topic | Correction |
|-------|------------|
| Stamp `unaff_retaddr` / `(byte)param_2` | **originX + dx** / **originY + dy** |
| CanPlace first size `CONCAT31(...)` | plain **u8** InvSizeX `@+0x406` |
| conflictOut | **local 8 B buffer** (non-null) — same-COID tolerance for overlap move |
| `FUN_00512670()` no-arg | **this = `*(grid+0x24)`** when non-null |
| ABI | **thiscall + 3 stack**; `RET 0x0C` |

---

## 4. Control flow: clean ≡ bytes

| Stage | Match |
|---|---|
| Null item → 0, `RET 0x0C` | **Yes** |
| InvSize load + CanPlace(conflictOut local) | **Yes** |
| CanPlace fail → 0 | **Yes** |
| Clear old footprint nested loops | **Yes** (index family) |
| `vtbl+0x24c(originX, originY)` | **Yes** |
| Stamp sizeX×sizeY COID | **Yes** (byte formula) |
| Optional `FUN_00512670` + dirty `+0x21` | **Yes** |
| Return 1 / `RET 0x0C` | **Yes** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Multi-cell clear + stamp full footprint | **Confirmed** | Byte loops |
| Index `height*x+y` / `height*(ox+dx)+(oy+dy)` | **Confirmed** | `IMUL`+`ADD` |
| InvSize `+0x406/+0x407` | **Confirmed** | Loads |
| conflictOut local (overlap-safe) | **High** | `LEA` push of local |
| ABI thiscall + 3 stack / `RET 0x0C` | **Confirmed** | Epilogue bytes |
| Name product English | **Inferred** | No xrefs; body role clear |
| Call graph / live use | **Open** | Ghidra xrefs empty |
| Runtime / bit-exact | **Open** | Deferred |

---

## 6. Gaps / open (do not block accept-with-gaps)

1. **No Ghidra callers** — orphan or indirect-only; name remains `_Inferred`.
2. **Runtime** — no live multi-cell dump for overlapping move.
3. **FUN_00512670** exact owner type when `grid+0x24` is the this-arg.
4. **Bit-exact / differential** — open matrix policy.

---

## 7. Verdict

### **accept-with-gaps**

**Accept:** ABI, CanPlace gate with local conflictOut, clear-then-SetPos-then-stamp CF, and index family sealed against Place/Remove/CanPlace.  
**Gaps:** product English, caller graph, runtime.
