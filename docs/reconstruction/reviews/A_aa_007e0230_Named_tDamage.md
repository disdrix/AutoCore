# Review A (reconstruction fidelity): `aa_007e0230` Named_tDamage

| Field | Value |
|---|---|
| **Stable ID** | `aa_007e0230` |
| **VA** | `0x007e0230` |
| **Canonical name** | `Named_tDamage` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_007e0230_Named_tDamage.md` |
| **System** | `combat` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

DB table loader **`tDamage`**. Reads damage definition rows via DBReader helpers; logs `DBReader: %u against %s`. Out struct init zeros `param_3[1]/[2]`. Empty path returns **0x80004004** if name empty when `DAT_00d1793c` set. Feeds combat damage type tables used by weapons/armor (`dcDamage` insert). Not runtime hit apply.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007e0230_*.md` |
| Annotated | `docs/reconstruction/raw/aa_007e0230_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Named_tDamage.cpp` |
| Function record | `docs/reconstruction/functions/aa_007e0230_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| tDamage table loader | High | Name + DBReader |
| HRESULT empty 0x80004004 path | High | Body |
| Multiple FUN_004231d0 column reads | High | Body |
| Column→damage field map complete | Medium | Residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| gate → open → column loop → store → close/fail | Yes |

---

## 5. Gaps / open

1. Seal damage row layout for AutoCore combat formulas.

**Verdict:** **accept-with-gaps**
