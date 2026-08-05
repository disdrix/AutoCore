# Review A (reconstruction fidelity): `aa_004fdf20` Vehicle_AttachWeapon

| Field | Value |
|---|---|
| **Stable ID** | `aa_004fdf20` |
| **VA** | `0x004fdf20` |
| **Canonical name** | `Vehicle_AttachWeapon` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004fdf20_Vehicle_AttachWeapon.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Attach weapon object into vehicle hardpoint slot **0..2** at table **vehicle+0x260** (ptr array). Clears prior slot helpers when `param_4==0`; stores weapon ptr; zeros track state at **+0x630/+0x634** per slot×8; validates clonebase type **0xc** (weapon) with unhappy-type log; scales/parents weapon via vfuncs **+0xb8/+0x158/+0x218** and `FUN_004fdcb0`. Nested from EquipFromCreate / equip path.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004fdf20_Vehicle_AttachWeapon.md` (or `aa_004fdf20_FUN_004fdf20.md`) |
| Annotated | `docs/reconstruction/raw/aa_004fdf20_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Vehicle_AttachWeapon.cpp` |
| Function record | `docs/reconstruction/functions/aa_004fdf20_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Slot index < 3 gate` | High | Body |
| `Weapon ptr table +0x260` | High | Body store |
| `Track state +0x630/+0x634 per slot` | High | Body |
| `Type must be 0xc weapon` | High | Log string + check |
| `Detach/replace prior weapon path` | High | FUN_00512670/004fbb50 |
| `Exact FUN_004fdcb0 role` | Medium | Unnamed |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Validate slot → replace → store → parent/scale | Yes |
| No invent cargo grid | Yes |

---

## 5. Gaps / open

1. Name FUN_00512670 / FUN_004fdcb0 / FUN_00569d50.
2. Turret vs hardpoint 0..2 mapping.

**Verdict:** **accept-with-gaps**
