# Review A (reconstruction fidelity): `aa_007e7940` Inv_dcArmor_Open

| Field | Value |
|---|---|
| **Stable ID** | `aa_007e7940` |
| **VA** | `0x007e7940` |
| **Canonical name** | `Inv_dcArmor_Open` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_007e7940_Inv_dcArmor_Open.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

DB **`dcArmor` insert/open** path for armor clonebase rows (plate family with `dcWeapon_Insert::Open`). Uses shared DBReader open helpers (`FUN_004230d0` / `00422fb0` / `0041a4b0` family) and damage sub-insert `FUN_007bfa70` (`dcDamage`). Combat gear table load — not runtime equip. Complements weapon open `007e82f0`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007e7940_*.md` |
| Annotated | `docs/reconstruction/raw/aa_007e7940_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Inv_dcArmor_Open.cpp` |
| Function record | `docs/reconstruction/functions/aa_007e7940_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Armor DB open / insert manager | High | Name + DBReader pattern |
| Shares damage insert FUN_007bfa70 | High | Callee |
| Not runtime Inventory equip packet | High | DB load role |
| Full column map sealed | Medium | Large residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| open reader → read columns → damage sub-open → close | Yes |

---

## 5. Gaps / open

1. Seal armor column → clonebase offsets.
2. Pair with Weapon open column ledger.

**Verdict:** **accept-with-gaps**
