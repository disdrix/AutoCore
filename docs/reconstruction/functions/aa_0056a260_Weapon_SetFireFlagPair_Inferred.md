# Function record: Weapon_SetFireFlagPair_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0056a260` |
| **Canonical name** | `Weapon_SetFireFlagPair_Inferred` |
| **Ghidra symbol** | `FUN_0056a260` |
| **Address** | `0x0056a260`–`0x0056a27a` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `combat` / vehicle hardpoint weapons |
| **Completion status** | **partial** — three-rep + dual A/B accept-with-gaps (2026-07-29) |
| **Bit-for-bit / runtime / diff** | Body sealed via `read_memory`; package / runtime open |

## Alias

| Name | Notes |
|---|---|
| `FUN_0056a260` | Ghidra default |
| `Named_CalleeOf_Client_Input_DriveControlTick_0056a260` | Weak parent-seed alias (superseded) |

## Purpose

Leaf dual-byte setter for hardpoint **weapon fire flag pair**:

* **`this+0xC7`**: always set to `value`
* **`this+0xC8`**: set to `value` only when currently unequal

`this` is a weapon/hardpoint object from the 3-pointer table at **`vehicle+0x260`**. Not a vehicle entity method. Not the drive-axis suppress mask constant `0xC7`.

## Signature

```c
void __thiscall Weapon_SetFireFlagPair_Inferred(
    void* weapon /* ECX */,
    unsigned char value /* [esp+4], RET 4 */);
```

## Machine body

```
8a442404 3881c8000000 8881c7000000 7406 8881c8000000 c20400
```

| Bytes | Meaning |
|---|---|
| `8a 44 24 04` | `mov al, [esp+4]` |
| `38 81 c8 00 00 00` | `cmp [ecx+0xc8], al` |
| `88 81 c7 00 00 00` | `mov [ecx+0xc7], al` (always) |
| `74 06` | `jz` skip twin store |
| `88 81 c8 00 00 00` | `mov [ecx+0xc8], al` |
| `c2 04 00` | `ret 4` |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0056a260_FUN_0056a260.md` |
| Annotated | `docs/reconstruction/raw/aa_0056a260_FUN_0056a260.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Weapon_SetFireFlagPair_Inferred.cpp` |
| Dual A | `docs/reconstruction/reviews/A_aa_0056a260_Weapon_SetFireFlagPair_Inferred.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_0056a260_Weapon_SetFireFlagPair_Inferred.md` |
| Residual | `docs/reconstruction/reviews/a_0056a260.md` |

## Callers / callees

**Callees:** none (leaf).

**Callers (live xrefs 2026-07-29, 12 sites):**

| Function | Entry | Call site(s) | Arg |
|---|---|---|---|
| `Client_Input_DriveControlTick` | `0x009223b0` | `0x009231c8` | `0` |
| `VehicleAction_airStabilization` | `0x00598320` | `0x00598512` | `0` |
| `Vehicle_ActivateEnterWorld` | `0x00503f30` | `0x005042d4` | `0` |
| `VehicleNet_UnpackGhostVehicle` | `0x005f7720` | `0x005f9a01` | net-derived 0/1 |
| `FUN_005021d0` | `0x005021d0` | `0x00502268`, `0x0050234d` | bool / vfunc |
| `FUN_004f4eb0` | `0x004f4eb0` | `0x004f4ecf` | `0` |
| `FUN_004f4f00` | `0x004f4f00` | `0x004f4f1f` | `0` |
| `FUN_004f9030` | `0x004f9030` | `0x004f9076` | `0` (+ often `+0xC9=0`) |
| `FUN_00814400` | `0x00814400` | `0x00814452` | `0` |
| (unnamed site) | — | `0x004fb8c4` | `1` then peer clear |
| (unnamed site) | — | `0x005ff9f5` | `0` (+ `+0xC9=0`) |

## Related (not owned)

| Unit | VA | Relation |
|---|---|---|
| `FUN_0056d520` start-fire | `0x0056d520` | Inlines pair=`1` and sets `+0xC9=1` |
| `FUN_0056b400` | `0x0056b400` | Sets `+0xCB` (blocks start-fire when set) |
| `Vehicle_FireAllPrimaryWeapons_Inferred` | `0x004f50d0` | Same `+0x260` 3-slot table |
| `Vehicle_IsAnyWeaponFiring` | (sibling) | Reader family for fire state |

## Confidence

| Claim | Level |
|---|---|
| Control flow / bytes / RET 4 | **High** |
| Offsets +0xC7 always / +0xC8 change-gated | **High** |
| `this` = hardpoint weapon from `vehicle+0x260` | **High** |
| Name `Weapon_SetFireFlagPair_Inferred` | **Probable** (role) / product open |
| +0xC7/+0xC8 English (“desired vs latched”) | **Medium** |
| Runtime / bit-exact package | **Open** |
