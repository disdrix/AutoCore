# Review A (reconstruction fidelity): `aa_007e7530` Named_dcCreature_Insert_Open

| Field | Value |
|---|---|
| **Stable ID** | `aa_007e7530` |
| **VA** | `0x007e7530` |
| **Canonical name** | `Named_dcCreature_Insert_Open` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_007e7530_Named_dcCreature_Insert_Open.md` |
| **System** | `combat` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

DB **`dcCreature` Insert/Open** — creature template child open under clonebase. Loads creature-specific columns for AI/combat spawn data. Paired with `Named_tCreatureAI` and loot generators using creature CBids.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007e7530_*.md` |
| Annotated | `docs/reconstruction/raw/aa_007e7530_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Named_dcCreature_Insert_Open.cpp` |
| Function record | `docs/reconstruction/functions/aa_007e7530_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| dcCreature open path | High | Name + DB pattern |
| Child of clonebase insert hierarchy | High | Family |
| Column map complete | Medium | Residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| open → read creature cols → return | Yes |

---

## 5. Gaps / open

1. Seal creature combat fields (HP, XP level key, faction).

**Verdict:** **accept-with-gaps**
