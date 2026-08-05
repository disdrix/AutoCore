# Review A (reconstruction fidelity): `aa_005b0d70` GhostObject_OnGhostAdd

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b0d70` |
| **VA** | `0x005b0d70` |
| **Canonical name** | `GhostObject_OnGhostAdd` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005b0d70_GhostObject_OnGhostAdd.md` |
| **System** | `networking` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

GhostObject **onGhostAdd** hook. If **this+0x50** object non-null, calls vtbl **+0x2b8** on that object with `this` and returns **1**. Else `FUN_005a0b30(this, this+0x40)` spatial helper and returns **1**. Always success 1 — thin lifecycle entry.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005b0d70_*.md` |
| Annotated | `docs/reconstruction/raw/aa_005b0d70_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GhostObject_OnGhostAdd.cpp` |
| Function record | `docs/reconstruction/functions/aa_005b0d70_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| +0x50 present → vtbl+0x2b8(this) | High | Body |
| Else FUN_005a0b30(this, this+0x40) | High | Body |
| Always returns 1 | High | Both paths |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| if +0x50: vtbl; else spatial; return 1 | Yes |

---

## 5. Gaps / open

1. Name vtbl+0x2b8 and FUN_005a0b30.
2. Confirm +0x40 spatial block layout.

**Verdict:** **accept-with-gaps**
