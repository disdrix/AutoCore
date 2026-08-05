# Review A (reconstruction fidelity): `aa_007bfa70` Named_dcDamage_Insert_MoveFirst

| Field | Value |
|---|---|
| **Stable ID** | `aa_007bfa70` |
| **VA** | `0x007bfa70` |
| **Canonical name** | `Named_dcDamage_Insert_MoveFirst` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_007bfa70_Named_dcDamage_Insert_MoveFirst.md` |
| **System** | `combat` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

DB cursor helper **`dcDamage` Insert/MoveFirst** (plate family). Shared by weapon/armor open paths (`Named_dcWeapon_Insert_Open` calls this). Positions/inserts damage child rows under parent open. Not tDamage full table load.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007bfa70_*.md` |
| Annotated | `docs/reconstruction/raw/aa_007bfa70_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Named_dcDamage_Insert_MoveFirst.cpp` |
| Function record | `docs/reconstruction/functions/aa_007bfa70_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| dcDamage insert/move-first helper | High | Name + callees from weapon open |
| Used by weapon/armor DB open | High | Xref pattern |
| Not full tDamage loader | High | Distinct VA 007e0230 |
| Full cursor state machine | Medium | Residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| open-state check → move/insert damage row → return hr | Yes |

---

## 5. Gaps / open

1. Seal relationship to parent dcWeapon/dcArmor.

**Verdict:** **accept-with-gaps**
