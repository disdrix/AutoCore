# Review A (reconstruction fidelity): `aa_00571b80` InventoryGrid_RemoveItem

| Field | Value |
|---|---|
| **Stable ID** | `aa_00571b80` |
| **VA** | `0x00571b80` |
| **Canonical name** | `InventoryGrid_RemoveItem` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ sealed bytes) |
| **Counterpart** | `reviews/B_aa_00571b80_InventoryGrid_RemoveItem.md` |
| **Residual scratch** | `reviews/a_00571b80.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** (A + B + residual; supersedes 2026-07-23 scaffold) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Remove / pull an item from a client inventory grid** — occupancy inverse of `InventoryGrid_PlaceItemFootprint` (`0x00571620`), plus stack-peel and list detach.

1. Reject null item or item **not** in list at `grid+0x2c` (`FUN_00415c00`) → **null**.
2. If stack-mode (`FUN_00513e70(item)`): capture GetQty; when `qty > 1` and flag bit15 clear, **SetQty(cur − removeQty)**; if remaining &gt; 0 and `forceFull==0` → dirty grid/owner, return **null** (cells **stay** stamped).
3. Full path: if object type ≠ **4**, clear InvSizeX×InvSizeY cells at item origin to empty **`0xFFFFFFFF` halves**; `FUN_005085b0(grid+0x2c, item)`; SetQty(savedQtyOr1); unbind `vtbl+0x158(0)`; dirty; return **item\***.

**Calling convention:** MSVC `__thiscall` — grid in `ECX`. Callee `RET 0x0C` → **three** stack dwords.

| Slot | Role | Evidence |
|------|------|----------|
| `this` | `InventoryGrid*` | Prologue `MOV EDI, ECX`; loads `+0x0c/+0x10/+0x21/+0x24/+0x28/+0x2c` |
| stack0 | `ItemObject*` | Prologue `MOV ESI, [ESP+0x18]` after `SUB ESP,0x10; PUSH ESI` |
| stack1 | `removeQty` | `SUB EAX, [ESP+…]` before SetQty in peel; callers pass `1` / qty / `1000000` |
| stack2 | `forceFull` (char) | `CMP byte [ESP+0x2c], 0` before skip-full branch |

**Returns:** `EAX` = `item*` on full remove; **0** on gate fail or partial peel (`forceFull==0`). Epilogue bytes: `C2 0C 00`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00571b80_FUN_00571b80.md` |
| Annotated | `docs/reconstruction/raw/aa_00571b80_FUN_00571b80.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/InventoryGrid_RemoveItem.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00571b80.cpp` (superseded) |
| Function record | `docs/reconstruction/functions/aa_00571b80_InventoryGrid_RemoveItem.md` |
| Residual | `docs/reconstruction/reviews/a_00571b80.md` |
| Live decompile | Ghidra MCP `decompile_function` @ `0x00571b80` ≡ raw 2026-07-23 |
| Live bytes | `read_memory` entry 128 B; clear core ~`0x00571c50`; epilogue `0x00571d08` region |
| Place sibling | `aa_00571620` stamp dual (index family) |
| Contains sibling | `aa_00571b60` list `+0x2c` / `FUN_00415c00` |
| Callees | decompile `FUN_00513e70`, `FUN_005085b0` |
| Callers | Ghidra `get_function_callers` (equip / drop / reaction remove / …) |

**Not performed:** `disassemble_bytes`, Launcher, CE live cell dump after peel/remove, bit-exact.

---

## 3. Unstamp formula (byte-sealed)

```text
// dx in [0, sizeX), dy in [0, sizeY)
index = *(grid+0x0c) * (originX + dx) + (originY + dy)
if (0 <= index < *(grid+0x10)):
  *(i32*)(cells + index*8)     = 0xFFFFFFFF
  *(i32*)(cells + index*8 + 4) = 0xFFFFFFFF
```

| Opcode evidence (inner) | Role |
|-------------------------|------|
| `8B 4F 0C` | `ECX = [EDI+0x0c]` height |
| `0F AF CD` | `IMUL ECX, EBP` with `EBP = ox+dx` |
| `03 CA` / `03 C8` | `+ dy` then `+ oy` |
| `8B 5F 28` | cells base |
| `C7 04 CB FF…` / `C7 44 CB 04 FF…` | empty lo/hi at `cells[idx*8]` |

- Outer bound = **sizeX** (`blob+0x406`); inner = **sizeY** (`+0x407`).
- Origins from vtbl `+0x250` / `+0x254` (stored as **bytes**).
- Same packing as Place/CanPlace/FindFree: `height * x + y`.
- Type **4**: jumps over clear loop (still detach/unbind).

### Decompiler corrections (bytes)

| Topic | Correction |
|-------|------------|
| `FUN_00415c00(item)` alone | **`this = grid+0x2c`**, arg = item (`LEA ECX,[EDI+0x2C]`) |
| `FUN_005085b0(item)` alone | **`this = grid+0x2c`**, arg = item |
| Scaffold signature 4 params as `param_1..4` mess | **thiscall + 3 stack**; `RET 0x0C` |
| “Occupancy sibling” = only cell clear | **Also** stack peel + list detach + unbind |

---

## 4. Control flow: clean ≡ raw ≡ bytes

| Stage | Match |
|---|---|
| Null item → 0, `RET 0x0C` | **Yes** |
| `FUN_00415c00(grid+0x2c, item)` fail → 0 | **Yes** |
| `FUN_00513e70` stack-mode gate | **Yes** (decompile + call) |
| Peel `SetQty(GetQty − removeQty)` when qty&gt;1 && !bit15 | **Yes** |
| remain&gt;0 && force==0 → dirty, return 0 (no clear) | **Yes** |
| Type 4 skip clear | **Yes** |
| Nested clear sizeX×sizeY empty pairs | **Yes** (byte formula) |
| `FUN_005085b0(grid+0x2c, item)` | **Yes** (bytes) |
| SetQty(saved) + vtbl+0x158(0) | **Yes** |
| Owner dirty if `grid+0x24`; `grid+0x21=1` | **Yes** |
| `RET 0x0C` | **Yes** (`C2 0C 00`) |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Multi-cell empty clear full footprint | **Confirmed** | Byte loop |
| Index `height*(ox+dx)+(oy+dy)` | **Confirmed** | `IMUL`+`ADD` chain |
| InvSize `+0x406/+0x407` | **High** | Same as Place |
| List gate + detach at `+0x2c` | **Confirmed** | `LEA` + call targets |
| ABI 3 stack args + this | **Confirmed** | `RET 0x0C` |
| Stack peel + force flag | **High** | CF + caller patterns |
| Type-4 no-clear | **High** | `CMP [host+0x38],4` |
| Product name `RemoveItem` | **High** | Role; PDB open |
| Bit15 English meaning | **Open** | CF only |
| Runtime / bit-exact | **Open** | Deferred |

---

## 6. Gaps / open (do not block accept-with-gaps)

1. **Runtime** — no CE dump of cells after peel vs full remove.
2. **Bit15 / force** retail names — open.
3. **`FUN_005085b0` vs `FUN_00566f00`** — both use `grid+0x2c` but different bodies; attach/detach API split not re-owned here.
4. **Bit-exact / differential** — open matrix policy.
5. Early fail path: membership fail does **not** set `grid+0x21` (success-shaped LAB does).

---

## 7. Verdict

### **accept-with-gaps**

Core remove algorithm, unstamp formula, list base, and ABI are **byte-sealed**. Remaining gaps are runtime/diff, bit15 naming, and deep list-API product names — not index math.

---

## Checklist (reviewer)

| Check | Result |
|---|---|
| Unstamp formula sealed from bytes | **Pass** |
| Clean CF matches sealed formula | **Pass** |
| Place / CanPlace / FindFree index family match | **Pass** |
| Membership + detach `+0x2c` | **Pass** |
| Type-4 path preserved | **Pass** |
| ABI `RET 0x0C` documented | **Pass** |
| Runtime / bit-exact | **Open** |
| Verdict | **accept-with-gaps** |
