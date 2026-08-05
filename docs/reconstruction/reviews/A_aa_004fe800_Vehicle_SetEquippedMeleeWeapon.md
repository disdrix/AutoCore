# Review A (reconstruction fidelity): `aa_004fe800` Vehicle_SetEquippedMeleeWeapon

| Field | Value |
|---|---|
| **Stable ID** | `aa_004fe800` |
| **VA** | `0x004fe800` |
| **Canonical name** | `Vehicle_SetEquippedMeleeWeapon` (**INFERRED**) |
| **Aliases** | `FUN_004fe800`, `Combat_Set_weapon_melee_unhappy_type_CBID` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004fe800_Vehicle_SetEquippedMeleeWeapon.md` |
| **System** | `inventory-transfer` (equip path) |
| **Evidence pass** | Live Ghidra decompile; class map type 0xc / subtype 9 |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Mutator for vehicle **melee hardpoint `this+0x264`**:

1. `FUN_00512670()` preamble; optional `*outPrev = *(this+0x264)`.
2. If previous non-null:
   - if `bSkipUnbind==0` → graphics clear `FUN_004fbb50` on prev base
   - `FUN_00569d50()`; unbind vfunc **`+0x158(0)`**
3. Store `*(this+0x264) = newMelee`.
4. If new non-null:
   - type-check: subtype short `*(blob+0x3f4) == 9` **and** clonebase `+0x38 == 0xc`; else log `"Set weapon melee of unhappy type: CBID:%d COID:%I64d"`
   - bind **`+0x158(vehicleGfx)`**; `FUN_004fdcb0`; notify **`+0x218`**; `FUN_0056be70()`
5. If vehicle has weapon-FX list at **`+0x3b8`** (begin/end iterators), rebuild each entry: destroy old FX object, `operator_new(0x14c)` + `FUN_00764030`, load name from melee blob path, attach.

RecvInventoryEquip / menu: class **0xc** with subtype **9** (melee branch before ranged slots).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004fe800_FUN_004fe800.md` |
| Annotated | `docs/reconstruction/raw/aa_004fe800_FUN_004fe800.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_004fe800.cpp` |
| Function record | `docs/reconstruction/functions/aa_004fe800_FUN_004fe800.md` |
| Counterpart B | `reviews/B_aa_004fe800_Vehicle_SetEquippedMeleeWeapon.md` |

---

## 3. Signature

```c
// __thiscall ECX = vehicle
void Vehicle_SetEquippedMeleeWeapon(
    void *vehicle,
    void *meleeWeapon,
    void **outPrev,     // optional
    char bSkipUnbind);
```

### Control flow seal

| Stage | Match | Confidence |
|---|---|---|
| Hardpoint `+0x264` | **Yes** | **High** |
| Type 0xc / subtype 9 | **Yes** | **High** |
| Bind `+0x158` / notify `+0x218` | **Yes** | **High** |
| FX list rebuild at `+0x3b8` | **Yes** | **Medium** product names |
| Unhappy type non-fatal log | **Yes** | **High** |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Melee slot `+0x264` | **High** | class map + store |
| Unhappy-type plate | **Confirmed** | string |
| Distinct from ranged `EquipWeaponSlot` | **High** | different hardpoint |
| `FUN_00569d50` / `FUN_0056be70` | **Open** | melee-specific helpers |
| FX ctor `FUN_00764030` | **Open** | residual |

---

## 5. Gaps / open

1. Product names for melee helpers and FX factory.
2. Exact structure of list at `vehicle+0x3b8`.

**Verdict:** **accept-with-gaps**
