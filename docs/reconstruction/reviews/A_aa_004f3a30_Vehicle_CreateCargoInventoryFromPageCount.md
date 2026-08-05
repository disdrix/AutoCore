# Review A (reconstruction fidelity): `aa_004f3a30` Vehicle_CreateCargoInventoryFromPageCount

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f3a30` |
| **VA** | `0x004f3a30` |
| **Canonical name** | `Vehicle_CreateCargoInventoryFromPageCount` |
| **Review date** | `2026-07-29` (refresh; prior 2026-07-23 batch stub) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004f3a30_Vehicle_CreateCargoInventoryFromPageCount.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Destroy any prior cargo `InventoryGrid` at vehicle **`+0x2b0`** (scalar deleting dtor). Unless byte flag **`+0x2ac`** is non-zero, allocate a fresh empty grid:

- `operator_new(0x68)`
- `InventoryGrid_ctor_Inferred(mem, width=6, height=nPages*13, pages=(int)nPages)`
- `InventoryGrid_SetOwnerFlag_Inferred(grid, 1)` → `grid+0x4 = 1`
- Bind owner object via grid vfunc **`vtbl+0x18`** → `FUN_005718a0` (stores `grid+0x24`)
- Bind secondary owner/character via grid vfunc **`vtbl+0x14`** → `0x00573900` (stores `grid+0x58`)

Does **not** place items. Foundation for later `FUN_00572360` re-layout / place paths.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live decompile | Ghidra MCP `0x004f3a30` (2026-07-29) |
| Raw | `docs/reconstruction/raw/aa_004f3a30_Vehicle_CreateCargoInventoryFromPageCount.md` |
| Annotated | `docs/reconstruction/raw/aa_004f3a30_Vehicle_CreateCargoInventoryFromPageCount.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Vehicle_CreateCargoInventoryFromPageCount.cpp` |
| Function record | `docs/reconstruction/functions/aa_004f3a30_Vehicle_CreateCargoInventoryFromPageCount.md` |
| Grid ctor | `InventoryGrid_ctor_Inferred` `0x00572650` |
| SetOwnerFlag | `InventoryGrid_SetOwnerFlag_Inferred` `0x00570600` |
| Grid vtable | `PTR_FUN_009d3390` @ `0x009d3390` (read_memory) |
| Callers | `Vehicle_applyCreatePacket` `0x00505270`, `FUN_005252f0` |
| AutoCore | `VehicleCargoCapacity.cs` (6×13×pages) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Cargo grid pointer at `vehicle+0x2b0` | **High** | body + DropResponse type-1 grid path |
| Destroy old via scalar deleting dtor `vtbl[0](1)` | **High** | `FUN_00573910` at vtable[0]; bit0 → `operator_delete` |
| Skip create when `*(char*)(this+0x2ac) != 0` | **High** (control) / **Probable** (English name) | Same flag gates other vehicle helpers (e.g. RecalcCombatPools) |
| Geometry `6 × (nPages×13)` pages=`nPages` | **Confirmed** | literals `6`, `0xd`; Callisto X pages=1 → 78 |
| Alloc size `0x68` | **High** | `operator_new(0x68)` + ctor layout |
| `SetOwnerFlag` writes `grid+0x4` | **High** | decompile `0x00570600` |
| vfunc `+0x18` = `FUN_005718a0` stores owner at `grid+0x24` | **High** | vtable dword + decompile |
| vfunc `+0x14` stores arg at `grid+0x58` | **High** (store) / **Probable** (semantic = character) | code @ `0x00573900`: `mov [ecx+0x58], eax; ret 4` |
| Owner arg = MI-adjusted `this` chain | **High** (expression) | `*( *(this+4)+4 ) + 4 + this` |
| Char arg = load at `…+0xa8+this` | **High** (expression) / **Probable** (type) | matches other vehicle owner-char patterns |
| Empty grid only (no cell stamp) | **High** | no place/find calls |
| `nPages` is chassis InventorySlots (pages) | **High** | packet `0x201e` field / vehicle `+0x1e6`; AutoCore wire |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| SEH prolog | Yes |
| Dtor old grid if non-null | Yes |
| Null `+0x2b0` | Yes |
| Gate on `+0x2ac == 0` | Yes |
| new(0x68) → ctor(6, nPages*13, nPages) → store | Yes |
| SetOwnerFlag(1) → vfunc+0x18 → vfunc+0x14 | Yes (order preserved) |
| SEH epilog | Yes |
| No item placement | Yes |

---

## 5. Callers

| Caller | Condition | `nPages` |
|---|---|---|
| `Vehicle_applyCreatePacket` | `*packet == 0x201e` | `(short)packet[0x35e]` |
| `FUN_005252f0` (switch vehicles) | always on new veh | `*(short*)(veh+0x1e6)`; then sets **other** vehicle `+0x2ac = 1` |

---

## 6. Gaps / open

1. English meaning of `+0x2ac` (special / no-cargo / template vehicle?) — not sealed; list of writers incomplete.
2. Exact type of value stored at `grid+0x58` (character vs abstract owner) — expression clear, type Probable.
3. Runtime / instruction-diff / bit-exact open (policy).
4. OOM path: retail still vcalls on null after failed `new` — clean preserves; not a reconstruction gap.

**Verdict:** **accept-with-gaps** — core cargo lifecycle + geometry sealed; residual naming/types only.
