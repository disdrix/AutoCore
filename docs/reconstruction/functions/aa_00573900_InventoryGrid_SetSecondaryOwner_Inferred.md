# Function record: InventoryGrid_SetSecondaryOwner_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00573900` |
| **Canonical name** | `InventoryGrid_SetSecondaryOwner_Inferred` |
| **Ghidra name** | `FUN_00573900` |
| **Address** | `0x00573900` |
| **Body** | `0x00573900`–`0x00573909` inclusive (**10 B** / `0x0A`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer / InventoryGrid |
| **Completion status** | **Dual-reviewed** MEGA-092 (2026-08-05) — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred). Terminal false. |

## Alias

| Name | Status |
|------|--------|
| `FUN_00573900` | Ghidra default (created MEGA-092; was undefined entry) |
| `InventoryGrid_SetSecondaryOwner_Inferred` | Preferred (_Inferred; partition hint + parent dual) |

## Purpose

InventoryGrid **vtbl+0x14** leaf: store secondary owner / character link pointer at **`grid+0x58`**. Used by vehicle cargo create after primary owner bind (`vtbl+0x18` → `+0x24`).

Does **not** set owner flag (`+0x4`), does **not** rebind list items.

## Signature (byte-sealed)

```c
// ECX = InventoryGrid*; stack secondaryOwner*; RET 4; void
void __thiscall InventoryGrid_SetSecondaryOwner_Inferred(
    InventoryGrid* self,
    void* secondaryOwner);
```

## Machine bytes

```
8b442404894158c20400
```

```
MOV EAX, [ESP+4]
MOV [ECX+0x58], EAX
RET 4
```

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | DATA only — `PTR_FUN_009d3390[+0x14]` @ `0x009d33a4`; virtual from `Vehicle_CreateCargoInventoryFromPageCount` (`0x004f3a30`) |
| Callees | none (leaf) |

## Related

| VA | Name | Relation |
|---|---|---|
| `0x005718a0` | `InventoryGrid_SetOwner_Inferred` | Primary owner vtbl+0x18 / `+0x24` |
| `0x00570600` | `InventoryGrid_SetOwnerFlag_Inferred` | Flag `+0x4` |
| `0x00573910` | `InventoryGrid_ScalarDeletingDtor` | Adjacent; vtbl[0] |
| `0x00572650` | `InventoryGrid_ctor_Inferred` | Installs same vtbl |
| `0x004f3a30` | `Vehicle_CreateCargoInventoryFromPageCount` | Parent virtual caller |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00573900_FUN_00573900.md`
- Annotated: `docs/reconstruction/raw/aa_00573900_FUN_00573900.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/InventoryGrid_SetSecondaryOwner_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00573900.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00573900_InventoryGrid_SetSecondaryOwner_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00573900_InventoryGrid_SetSecondaryOwner_Inferred.md`
- FUN record: `docs/reconstruction/functions/aa_00573900_FUN_00573900.md`
- Report: `docs/agents/task-dual-ab-00573900-mega-092-report.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow (bytes) | **High** |
| ABI ECX + RET 4 + void | **High** |
| Store offset `+0x58` | **High** |
| vtbl+0x14 slot | **High** |
| InventoryGrid family (ctor + cargo parent) | **High** |
| Product English / pointee type | **Inferred / Probable** |
| Runtime Confirmed | **Open** |
