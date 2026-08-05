# Review A (reconstruction fidelity): `aa_00569d50` WeaponMelee_DisableActiveState

| Field | Value |
|---|---|
| **Stable ID** | `aa_00569d50` |
| **VA** | `0x00569d50` |
| **Canonical name** | `WeaponMelee_DisableActiveState` (**INFERRED**) |
| **Aliases** | `FUN_00569d50`, melee unbind teardown |
| **Review date** | `2026-07-29` (OWN-ONLY dual A/B — Equip nested residual) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00569d50_WeaponMelee_DisableActiveState.md` |
| **System** | `inventory-transfer` / weapons |
| **Dual status** | **Present** (first dual pair) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Disable / teardown active melee presentation state** on a melee weapon object (inverse of `FUN_0056be70`):

If `*(melee + 0xc5) != 0`:

1. Clear `*(melee + 0xc5) = 0`
2. COM vfunc **`+0x104(0)`** on melee graphics base (disable flag)
3. If `*(melee + 0xc0)` non-null: virtual dtor `(*obj)(1)` (delete)
4. `*(melee + 0xc0) = 0`

If flag already clear → no-op.

**Equip path:** `Vehicle_SetEquippedMeleeWeapon` calls this on the **previous** melee before unbind vfunc `+0x158(0)`. Also from `Vehicle_AttachWeapon` / `Vehicle_EquipFromCreate` teardown arms.

---

## 2. Calling convention

| Slot | Role |
|------|------|
| **ECX** | melee weapon object (this) |
| return | void |

No stack args. Tiny body; no external callees beyond vfuncs.

---

## 3. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `raw/aa_00569d50_*`, `reconstructed-exact/FUN_00569d50.cpp` |
| Live decompile | Ghidra 2026-07-29 ≡ raw |
| Parent dual | `A_aa_004fe800_Vehicle_SetEquippedMeleeWeapon` |
| Inverse | `aa_0056be70` WeaponMelee_EnableActiveState |
| Sibling callers | `Vehicle_AttachWeapon`, `Vehicle_EquipFromCreate` |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Gate on `+0xc5` | **Yes** |
| Clear flag + vfunc `+0x104(0)` | **Yes** |
| Optional delete of `+0xc0` | **Yes** |
| Null `+0xc0` | **Yes** |
| Early no-op if already off | **Yes** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Melee-only equip residual helper | **High** | parent dual places call |
| Inverse of `0056be70` | **High** | flag polarity + `+0x104` 0 vs 1 |
| `+0xc0` is heap action/FX host | **Probable** | dtor pattern; enable path allocates HB |
| Product English | **Tentative** | roles sealed |

---

## 6. Gaps

1. Exact type of `+0xc0` object (HB vs FX vs action).
2. Product name for vfunc `+0x104`.
3. Runtime open.

**Verdict:** Melee disable/teardown sealed. **accept-with-gaps.**
