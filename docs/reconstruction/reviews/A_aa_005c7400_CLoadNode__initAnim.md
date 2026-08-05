# Review A (reconstruction fidelity): `aa_005c7400` CLoadNode__initAnim

| Field | Value |
|---|---|
| **Stable ID** | `aa_005c7400` |
| **VA** | `0x005c7400` |
| **Canonical name** | `CLoadNode__initAnim` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005c7400_CLoadNode__initAnim.md` |
| **System** | `client-load` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

CLoadNode stage **`_initAnim`**. Wait/mark clonebase **+0x138**. Clears node **+0x61**. Calls object vtbl **+0x20** (anim init). Return 0|3.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005c7400_*.md` |
| Annotated | `docs/reconstruction/raw/aa_005c7400_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CLoadNode__initAnim.cpp` |
| Function record | `docs/reconstruction/functions/aa_005c7400_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Wait key +0x138 | High | Body |
| Clears +0x61; vtbl+0x20 | High | Body |
| Return 3 on wait incomplete | High | Shared stage pattern |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| wait/mark → +0x61=0 → vtbl+0x20 → 0 | Yes |

---

## 5. Gaps / open

1. Name vtbl+0x20 anim bind.

**Verdict:** **accept-with-gaps**
