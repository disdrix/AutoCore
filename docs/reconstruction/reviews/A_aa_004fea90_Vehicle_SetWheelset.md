# Review A (reconstruction fidelity): `aa_004fea90` Vehicle_SetWheelset

| Field | Value |
|---|---|
| **Stable ID** | `aa_004fea90` |
| **VA** | `0x004fea90` |
| **Canonical name** | `Vehicle_SetWheelset` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004fea90_Vehicle_SetWheelset.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Attach/clear vehicle wheelset at **`this+0x258`**. Called from `Vehicle_EquipFromCreate` and InventoryEquip (**0x203C**). Store pointer; type-check clonebase **`+0x38 == 0x10`** (else log unhappy type); bind vfunc **`+0x158`**; sector notify **`+0x218`**; for each wheel `i in [0, wheelCount@wheelset+0xb0)` scale via chassis table **`+0x600+i`**. Critical create/equip path for wheels (PATH_A / owner-wheel RE).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004fea90_Vehicle_SetWheelset.md` (or `aa_004fea90_FUN_004fea90.md`) |
| Annotated | `docs/reconstruction/raw/aa_004fea90_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Vehicle_SetWheelset.cpp` |
| Function record | `docs/reconstruction/functions/aa_004fea90_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Hardpoint +0x258` | High | Plate |
| `Type 0x10 wheelset` | High | Plate |
| `wheelCount at wheelset+0xb0` | High | Plate |
| `Per-wheel scale +0x600 table` | High | Plate |
| `Callers EquipFromCreate + 0x203C` | High | Plate |
| `Scale global residual` | Medium | g_flLevelUpUiBase name |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Store → typecheck → bind → scale wheels | Yes |
| No thr/steer write | Yes |

---

## 5. Gaps / open

1. Wheel object FUN_005a6e00 identity.
2. Clear/null wheelset full path.

**Verdict:** **accept-with-gaps**
