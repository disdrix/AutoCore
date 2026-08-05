# Review A (reconstruction fidelity): `aa_007e82f0` Named_dcWeapon_Insert_Open

| Field | Value |
|---|---|
| **Stable ID** | `aa_007e82f0` |
| **VA** | `0x007e82f0` |
| **Canonical name** | `Named_dcWeapon_Insert_Open` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_007e82f0_Named_dcWeapon_Insert_Open.md` |
| **System** | `combat` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

DB **`dcWeapon_Insert::Open`** — open weapon insert cursor and read weapon-specific columns. Calls `FUN_007bfa70` (dcDamage insert) and shared DBReader open. Plate string `dcWeapon_Insert::Open`. Combat weapon template load path paired with `Inv_dcArmor_Open`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007e82f0_*.md` |
| Annotated | `docs/reconstruction/raw/aa_007e82f0_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Named_dcWeapon_Insert_Open.cpp` |
| Function record | `docs/reconstruction/functions/aa_007e82f0_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Plate dcWeapon_Insert::Open | High | String |
| Invokes dcDamage insert FUN_007bfa70 | High | Callee |
| DBReader open family | High | Callees |
| Full weapon column map | Medium | 324-line residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| open → read weapon cols → damage insert → return | Yes |

---

## 5. Gaps / open

1. Map columns to clonebase weapon +0xD4 heat etc.

**Verdict:** **accept-with-gaps**
