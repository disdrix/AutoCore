# Review A (reconstruction fidelity): `aa_004fe110` Vehicle_EquipWeaponSlot

| Field | Value |
|---|---|
| **Stable ID** | `aa_004fe110` |
| **VA** | `0x004fe110` |
| **Canonical name** | `Vehicle_EquipWeaponSlot` (**INFERRED**) |
| **Aliases** | `FUN_004fe110`, `Inv_Tried_to_equip_same_weapon_d` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004fe110_Vehicle_EquipWeaponSlot.md` |
| **System** | `inventory-transfer` (equip path) |
| **Evidence pass** | Live Ghidra decompile + `read_memory` prologue/body; sibling dual `Vehicle_AttachWeapon` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Same-equip-gated wrapper** around `Vehicle_AttachWeapon` for primary weapon hardpoint array **`vehicle+0x260`**:

1. Load current slot: `*( *(vehicle+0x260) + slot*4 )`.
2. If `newWeapon == current && newWeapon != 0` → log `"Tried to equip same weapon %d"` (CBID) and **return** (no out-write).
3. If current non-null → `FUN_00518630(100,0,0)` then unbind current via vfunc **`+0x158(0)`**.
4. `*outPrev = current` (slot pointer before attach).
5. `Vehicle_AttachWeapon(newWeapon, slot, 0)` (this = vehicle).

Class map: RecvInventoryEquip / menu equip **type 0xc** non-melee → slot index from weapon flags (`+0x536` bits → slot 0/1/2).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004fe110_FUN_004fe110.md` |
| Annotated | `docs/reconstruction/raw/aa_004fe110_FUN_004fe110.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_004fe110.cpp` |
| Function record | `docs/reconstruction/functions/aa_004fe110_FUN_004fe110.md` |
| Attach dual | `reviews/A_aa_004fdf20_Vehicle_AttachWeapon.md` |
| Counterpart B | `reviews/B_aa_004fe110_Vehicle_EquipWeaponSlot.md` |

---

## 3. Signature

```c
// __thiscall ECX = vehicle; ret 0x0c
void Vehicle_EquipWeaponSlot(
    void *vehicle,
    void *weapon,           // new weapon object (0 allowed via Attach)
    int slot,               // index into table at vehicle+0x260
    void **outPrev);        // writes previous slot occupant
```

### Control flow (decompile ≡ image shape)

| Stage | Match | Confidence |
|---|---|---|
| Slot load from `+0x260` table | **Yes** | **High** |
| Same-pointer early out + log | **Yes** | **High** (string) |
| Unbind prior via `+0x158` | **Yes** | **High** |
| `*outPrev` before attach | **Yes** | **High** |
| Terminal `Vehicle_AttachWeapon(w, slot, 0)` | **Yes** | **High** |
| `ret 0x0c` | **Yes** | **Confirmed** |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Hardpoint table `+0x260` | **High** | Matches AttachWeapon dual |
| Same-equip log string | **Confirmed** | plate |
| Out-prev only on non-same path | **High** | early return skips write |
| Slot 0..2 domain | **High** via Attach gate | this unit does not re-check range |
| `FUN_00518630(100,0,0)` meaning | **Open** | pre-unbind helper |

---

## 5. Gaps / open

1. Exact role of `FUN_00518630`.
2. Whether `outPrev` may be null (decompiler assumes non-null write).

**Verdict:** **accept-with-gaps**
