# Review B (skeptical / adversarial): `aa_004f3a30` Vehicle_CreateCargoInventoryFromPageCount

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f3a30` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (refresh; prior 2026-07-23 batch stub) |
| **Counterpart** | `reviews/A_aa_004f3a30_Vehicle_CreateCargoInventoryFromPageCount.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Function places loot / fills cells | Body has no place/find/alloc beyond ctor | **Falsified** — empty grid only |
| 2 | Always creates cargo grid | Gate `*(char*)(this+0x2ac) != 0` skips alloc; leaves `+0x2b0==0` | **Falsified** “always” |
| 3 | `nPages` is total cell count | Ctor args: width 6, height `nPages*13`, third arg pages; AutoCore InventorySlots | **Falsified** — pages not cells |
| 4 | Geometry formula unfinished / guessed | Literals `6` and `0xd` in decompile; vtable/ctor independent | **Survives** as Confirmed |
| 5 | “Owner TFID” is literal TFID write | vfunc+0x18 stores pointer at `grid+0x24` and walks items; +0x14 stores dword at `grid+0x58` | **Overstated plate wording** — pointers, not raw TFID fields in this function |
| 6 | Clean invents clamp here | Clamp is in **ctor**, not this function | Clean header OK; body does not clamp `nPages` |
| 7 | `+0x2ac` means “special vehicles” only | Also set on switch path `FUN_005252f0` after create of *other* veh; shared gate with RecalcCombatPools | **Name unsealed** — behavior High, English Probable |
| 8 | Dual batch already sealed unit | Prior A/B stubs lacked vtable resolution / callers | **Prior dual weak** — this refresh required |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| `+0x2b0` lifecycle destroy→null→create | **High** | Leak / null cargo UI |
| `+0x2ac` skip branch | **High** | Create cargo on no-cargo vehicles |
| `6 × pages×13` geometry | **Confirmed** | Wrong server capacity / wire pages |
| Owner bind targets `+0x24` / `+0x58` | **High** store / **Probable** semantics | Wrong ownership for place/grab |
| SetOwnerFlag name / `grid+0x4` | **High** write / **Inferred** name | Cosmetic |
| No runtime proof | **N** | Policy open |

---

## 3. Cross-check against raw + live decompile

```text
SEH
if grid@+0x2b0: (**grid)(1)          // scalar deleting dtor
grid@+0x2b0 = 0
if flag@+0x2ac == 0:
  p = new(0x68)
  if p: p = InventoryGrid_ctor(p, 6, nPages*13, (int)nPages)
  grid@+0x2b0 = p
  SetOwnerFlag(p, 1)                 // p+4 = 1
  (grid.vtbl+0x18)( mi_adjusted_this )  // → FUN_005718a0: +0x24
  (grid.vtbl+0x14)( * (mi_base + 0xa8 + this) )  // → 00573900: +0x58
SEH restore
```

Clean C++ ≡ raw ≡ live decompile on CF and constants. Vtable slots resolved by `read_memory` of `0x009d3390`.

---

## 4. Surviving contract for AutoCore

```text
CreateCargoInventoryFromPageCount(vehicle, nPages):
  // nPages = chassis InventorySlots (UI pages), NOT cell count
  destroy prior cargo grid at vehicle+0x2b0
  if vehicle.skipCargoFlag(+0x2ac) == 0:
    cargo = new InventoryGrid(width=6, height=nPages*13, pages=nPages)
    vehicle.cargoGrid(+0x2b0) = cargo
    cargo.ownerFlag(+0x4) = 1
    cargo.ownerObj(+0x24) = adjusted vehicle identity
    cargo.ownerChar(+0x58) = character pointer from entity chain +0xa8
  // items placed elsewhere (applyCreatePacket COID loop / FUN_00572360)

AutoCore: VehicleCargoCapacity.GridWidth=6, RowsPerPage=13, ClampPageCount for wire.
```

---

## 5. Open questions (do not block accept-with-gaps)

1. Seal English name / full writer set for `vehicle+0x2ac`.
2. Seal type of `grid+0x58` (character object vs other).
3. Runtime hit test on create vehicle page count field `packet[0x35e]` vs vehicle `+0x1e6` equality.

**Verdict:** **accept-with-gaps** — adversarial review does not break geometry or lifecycle; gaps are naming/types/runtime only.
