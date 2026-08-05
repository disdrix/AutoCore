# Annotated low-level: Vehicle_CreateCargoInventoryFromPageCount (`aa_004f3a30`)

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f3a30` |
| **VA** | `0x004f3a30` |
| **Module** | `autoassault.exe` @ image base `0x400000` |
| **Source raw** | `aa_004f3a30_Vehicle_CreateCargoInventoryFromPageCount.md` (capture 2026-07-23) |
| **System** | inventory-transfer |

This file is the **annotated** layer: widths, signedness, branch order, side effects, and decompiler corrections. It does not replace the immutable raw capture.

---

## 1. Corrected signature

```c
// MSVC thiscall: ECX = this (vehicle entity)
void __thiscall Vehicle_CreateCargoInventoryFromPageCount(VehicleEntity* this, int16_t nPages);
```

| Name | Width | Signedness | Origin | Role |
|---|---|---|---|---|
| `this` | 32-bit pointer | unsigned address | `ECX` | Vehicle entity owning cargo grid |
| `nPages` | **16-bit** (`short`) | signed | stack arg | Chassis inventory **page count** (`InventorySlots`), **not** total cells |

---

## 2. Decompiler corrections

| Decompiler artifact | Correction | Confidence |
|---|---|---|
| `void *this` | **`VehicleEntity*`** (or equivalent vehicle object) | **High** |
| `short nPages` | Keep **i16**; promoted to `int` only for ctor arg | **Confirmed** |
| `nPages * 0xd` | Height = **pages × 13** cells (page row pitch) | **Confirmed** |
| Width literal `6` | Cargo grid width = **6** cells | **Confirmed** |
| `operator_new(0x68)` | `InventoryGrid` object size **0x68** bytes | **High** |
| Vtable delete `(**grid)(1)` | Scalar deleting destructor on prior grid | **High** |
| `*(this+0x2ac) == 0` gate | Skip grid create when special/no-cargo flag set | **Probable** |

---

## 3. Control flow

```text
SEH prolog (ExceptionList)
if (this+0x2b0 != NULL):
  (**vtbl)(grid, 1)          // destroy prior InventoryGrid
this+0x2b0 = 0
if (*(u8*)(this+0x2ac) == 0):
  mem = operator_new(0x68)
  if mem != NULL:
    mem = InventoryGrid_ctor_Inferred(mem, width=6, height=nPages*13, pages=(int)nPages)
  this+0x2b0 = mem
  InventoryGrid_SetOwnerFlag_Inferred(mem, 1)
  (grid.vtbl+0x18)( owner_entity_ref )   // bind owner object identity
  (grid.vtbl+0x14)( character_or_owner_ptr ) // bind character link
SEH epilog
return
```

| Branch | Condition | Effect |
|---|---|---|
| Always | prior grid non-null | Virtual dtor with `1` (delete) |
| Skip create | `*(u8*)(this+0x2ac) != 0` | Leave `+0x2b0 == 0` |
| Create | flag clear | New 6 × (pages×13) empty grid |

Control-flow confidence: **High** (matches plate + raw).

---

## 4. Side-effect order

1. Install SEH frame (`LAB_009a2c75`).
2. **Call** prior grid vtable `[0]` with arg `1` if `this+0x2b0 != 0`.
3. **Store** `this+0x2b0 = 0` (u32).
4. If flag `this+0x2ac` is zero:
   1. **Alloc** 0x68 bytes (`operator_new`).
   2. **Call** `InventoryGrid_ctor_Inferred` (width 6, height `nPages*13`, pages `nPages`).
   3. **Store** grid pointer → `this+0x2b0`.
   4. **Call** `InventoryGrid_SetOwnerFlag_Inferred(grid, 1)`.
   5. **Call** grid vfunc `@vtbl+0x18` with entity-relative owner id:
      `*( *( *(this+4) + 4 ) + 4 + this )` (pointer/int chain, 32-bit).
   6. **Call** grid vfunc `@vtbl+0x14` with:
      `*( *( *( *(this+4) + 4 ) + 0xa8 + this ) )` (32-bit load).
5. Restore `ExceptionList`; return.

**No** cell stamping here — grid is empty (`AllocateCellArray` fills `0xFFFFFFFF`).

---

## 5. Field map

| Offset | Type | Role |
|---|---|---|
| `vehicle+0x2ac` | u8 | Create-suppress flag (0 → build cargo grid) |
| `vehicle+0x2b0` | `InventoryGrid*` | Cargo inventory grid pointer |
| `vehicle+4` chain | ptr | Owner identity for grid bind |
| Grid size | 0x68 | Allocation size |
| Cargo geometry | w=6, h=pages×13 | Callisto X pages=1 → **78** cells |

---

## 6. Geometry note

| pages | height | total cells (× width 6) |
|---:|---:|---:|
| 1 | 13 | 78 |
| 2 | 26 | 156 |
| n | 13n | 78n |

Wire / AutoCore: page count is chassis `InventorySlots`, not a raw cell total.

---

## 7. Confidence / open

| Area | Level |
|---|---|
| Geometry 6 × pages×13 | **Confirmed** |
| Destroy/create order | **High** |
| Semantic of `+0x2ac` | **Probable** (control High) |
| vfunc `+0x18` → `FUN_005718a0` stores `grid+0x24` | **High** (2026-07-29 vtable resolve) |
| vfunc `+0x14` → `0x00573900` stores `grid+0x58` | **High** store / **Probable** type |
| Exact types of bind args (entity vs character) | **Probable** |
| `SetOwnerFlag` name | **Inferred** (Ghidra plate); write `grid+0x4` High |

### Vtable resolution (2026-07-29)

`PTR_FUN_009d3390` @ `0x009d3390` (first 7 dwords):

| Slot | Addr | Role |
|---:|---|---|
| +0x00 | `0x00573910` | scalar deleting dtor |
| +0x14 | `0x00573900` | `*(this+0x58)=arg; ret 4` |
| +0x18 | `0x005718a0` | `*(this+0x24)=arg` + item propagate |

Dual A/B refreshed 2026-07-29: **accept-with-gaps**.
