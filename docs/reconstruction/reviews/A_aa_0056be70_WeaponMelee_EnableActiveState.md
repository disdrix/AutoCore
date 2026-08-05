# Review A (reconstruction fidelity): `aa_0056be70` WeaponMelee_EnableActiveState

| Field | Value |
|---|---|
| **Stable ID** | `aa_0056be70` |
| **VA** | `0x0056be70` |
| **Canonical name** | `WeaponMelee_EnableActiveState` (**INFERRED**) |
| **Aliases** | `FUN_0056be70`, melee equip activate / HB arm |
| **Review date** | `2026-07-29` (OWN-ONLY dual A/B — Equip nested residual) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0056be70_WeaponMelee_EnableActiveState.md` |
| **System** | `inventory-transfer` / weapons |
| **Dual status** | **Present** (first dual pair) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Enable active melee state** after a melee weapon is bound to the vehicle (inverse of `FUN_00569d50`):

If `*(melee + 0xc5) == 0`:

1. COM vfunc **`+0x104(1)`** (enable)
2. Set `*(melee + 0xc5) = 1`, `*(melee + 0xcb) = 1`, `*(melee + 0xd8) = 0`
3. `FUN_0056ab40()` (melee-local reset residual)
4. If clonebase host path `COM+0xa8` non-null **and** `*(clonebaseHost + 0xe4ec)` (HB list) non-null:
   - `operator_new(0x24)` + `FUN_005fe6a0(melee, 1000)` → `CVOGHBBase*` period **1000**
   - `CVOGHBList_Enqueue(list, action)` + `CVOGHBBase_Start(action)`
   - If `melee+0x30` non-null: `(*(melee+0x24)).vfunc+0x18(melee+0x30, 0x3e4ccccd /*0.2f*/, 0)`
   - `*(melee + 0x78) = 0xffffffff`

If already active (`+0xc5 != 0`) → no-op.

**Equip path:** `Vehicle_SetEquippedMeleeWeapon` after bind/`FUN_004fdcb0`/notify `+0x218`. Also `Vehicle_AttachWeapon` and sibling activate paths.

---

## 2. Calling convention

| Slot | Role |
|------|------|
| **ECX** | melee weapon object (this) |
| return | void |

---

## 3. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `raw/aa_0056be70_*`, `reconstructed-exact/FUN_0056be70.cpp` |
| Live decompile | Ghidra 2026-07-29 |
| Parent dual | `A_aa_004fe800_Vehicle_SetEquippedMeleeWeapon` |
| Inverse | `aa_00569d50` |
| HB duals | `CVOGHBList_Enqueue`, `CVOGHBBase_Start` |
| Float | `0x3e4ccccd` = **0.2f** |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Gate `+0xc5 == 0` | **Yes** |
| vfunc `+0x104(1)` + flags | **Yes** |
| HB new(0x24) + period 1000 | **Yes** |
| Enqueue + Start | **Yes** |
| Optional vfunc `+0x18` with 0.2f | **Yes** |
| Skip if already active | **Yes** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Enable after melee equip bind | **High** | parent call order |
| Uses CVOGHBList at clonebase `+0xe4ec` | **High** | named callees |
| Period 1000 | **High** | arg sealed |
| `FUN_0056ab40` product | **Open** | called once |
| 0.2f product meaning | **Tentative** | float sealed |

---

## 6. Gaps

1. Product names for `FUN_0056ab40` / `FUN_005fe6a0` (HB factory).
2. What `+0x78 = -1` means.
3. Runtime open.

**Verdict:** Melee equip activate + HB arm sealed. **accept-with-gaps.**
