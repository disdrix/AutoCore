# Review A (reconstruction fidelity): `aa_004fe620` Vehicle_SetEquippedOrnament

| Field | Value |
|---|---|
| **Stable ID** | `aa_004fe620` |
| **VA** | `0x004fe620` |
| **Canonical name** | `Vehicle_SetEquippedOrnament` (**INFERRED**) |
| **Aliases** | `FUN_004fe620`, `Named_Set_ornament_unhappy_type_CBID_COID` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004fe620_Vehicle_SetEquippedOrnament.md` |
| **System** | `inventory-transfer` (equip path) |
| **Evidence pass** | Live Ghidra decompile; class map inventory-transfer + RecvInventoryEquip |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Mutator for vehicle **ornament hardpoint `this+0x26c`** (clonebase type **6** / subtype short **`+0x3f4 == 10`**):

1. `FUN_00512670()` preamble.
2. Optional `*outPrev = *(this+0x26c)`.
3. If previous non-null:
   - if `bSkipUnbind == 0` → `FUN_004fbb50` on prev graphics base
   - `FUN_004fe380(prevGfx, 0)`; vfunc **`+0x158(0)`** unbind
4. Store `*(this+0x26c) = newOrnament`.
5. If new non-null:
   - type-check: clonebase `+0x38 == 6` **and** subtype `*(blob+0x3f4) == 10`; else log `"Set ornament of unhappy type: CBID:%d COID:%I64d"`
   - bind vfunc **`+0x158(vehicleGfx)`**; `FUN_004fdcb0`; `FUN_004fe380(...,1)`; notify **`+0x218`**
6. Optional chassis-related vector copy into vehicle **`+0x3bc..+0x3d8`** when owner graphics list present (`+0x48` chain + `FUN_00989270(100)`).

RecvInventoryEquip / menu path: class **6** + subtype **10**.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004fe620_FUN_004fe620.md` |
| Annotated | `docs/reconstruction/raw/aa_004fe620_FUN_004fe620.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_004fe620.cpp` |
| Function record | `docs/reconstruction/functions/aa_004fe620_FUN_004fe620.md` |
| Counterpart B | `reviews/B_aa_004fe620_Vehicle_SetEquippedOrnament.md` |

---

## 3. Signature

```c
// __thiscall ECX = vehicle
void Vehicle_SetEquippedOrnament(
    void *vehicle,
    void *ornament,     // new item object or null
    void **outPrev,     // optional previous out
    char bSkipUnbind);  // non-zero skips FUN_004fbb50 on old
```

### Control flow seal

| Stage | Match | Confidence |
|---|---|---|
| Hardpoint store `+0x26c` | **Yes** | **High** |
| Type 6 / subtype 10 | **Yes** | **High** (log + check) |
| Bind `+0x158` / notify `+0x218` | **Yes** | **High** |
| Unbind path gated by `bSkipUnbind` | **Yes** | **High** |
| Optional `+0x3bc` matrix/vector fill | **Yes** | **Medium** semantics |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Ornament slot `+0x26c` | **High** | inventory-transfer class map |
| Unhappy-type plate | **Confirmed** | string |
| Sibling of plant/melee equip shape | **High** | same bind/notify pattern |
| `FUN_004fe380` / `FUN_004fdcb0` names | **Open** | residual FUN_* |
| `+0x3bc` block product meaning | **Tentative** | likely transform/scales |

---

## 5. Gaps / open

1. Product names for `FUN_004fe380`, `FUN_004fbb50`, `FUN_004fdcb0`.
2. When callers pass `bSkipUnbind != 0`.

**Verdict:** **accept-with-gaps**
