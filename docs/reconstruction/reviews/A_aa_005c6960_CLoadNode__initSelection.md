# Review A (reconstruction fidelity): `aa_005c6960` CLoadNode__initSelection

| Field | Value |
|---|---|
| **Stable ID** | `aa_005c6960` |
| **VA** | `0x005c6960` |
| **Canonical name** | `CLoadNode__initSelection` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005c6960_CLoadNode__initSelection.md` |
| **System** | `client-load` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

CLoadNode stage **`_initSelection`**. Clears **+0x65**, calls `FUN_0051aed0(1, 0)`, returns **0**. Thin selection/UI bind stage.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005c6960_*.md` |
| Annotated | `docs/reconstruction/raw/aa_005c6960_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CLoadNode__initSelection.cpp` |
| Function record | `docs/reconstruction/functions/aa_005c6960_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Clears +0x65 | High | Body |
| FUN_0051aed0(1,0) | High | Body |
| Always return 0 | High | Body |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| +0x65=0 → FUN_0051aed0 → 0 | Yes |

---

## 5. Gaps / open

1. Name FUN_0051aed0 selection helper.

**Verdict:** **accept-with-gaps**
