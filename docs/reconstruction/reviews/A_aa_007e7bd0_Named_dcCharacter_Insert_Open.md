# Review A (reconstruction fidelity): `aa_007e7bd0` Named_dcCharacter_Insert_Open

| Field | Value |
|---|---|
| **Stable ID** | `aa_007e7bd0` |
| **VA** | `0x007e7bd0` |
| **Canonical name** | `Named_dcCharacter_Insert_Open` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_007e7bd0_Named_dcCharacter_Insert_Open.md` |
| **System** | `client-load` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

DB **`dcCharacter` Insert/Open** — character template/child open. Loads character-specific columns used by create packet / load path. Sibling of creature/weapon opens; not `CVOGCharacter_CreateFromPacket`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007e7bd0_*.md` |
| Annotated | `docs/reconstruction/raw/aa_007e7bd0_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Named_dcCharacter_Insert_Open.cpp` |
| Function record | `docs/reconstruction/functions/aa_007e7bd0_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| dcCharacter open | High | Name |
| DBReader pattern | High | Callees |
| Distinct from runtime CreateFromPacket | High | Role |
| Column map | Medium | Residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| open → read character cols → return | Yes |

---

## 5. Gaps / open

1. Seal columns vs create packet 0x2013 layout.

**Verdict:** **accept-with-gaps**
