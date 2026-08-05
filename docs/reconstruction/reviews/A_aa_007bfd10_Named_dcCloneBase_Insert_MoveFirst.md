# Review A (reconstruction fidelity): `aa_007bfd10` Named_dcCloneBase_Insert_MoveFirst

| Field | Value |
|---|---|
| **Stable ID** | `aa_007bfd10` |
| **VA** | `0x007bfd10` |
| **Canonical name** | `Named_dcCloneBase_Insert_MoveFirst` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_007bfd10_Named_dcCloneBase_Insert_MoveFirst.md` |
| **System** | `client-load` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

DB cursor **`dcCloneBase` Insert/MoveFirst**. Positions clonebase insert cursor for child table opens (vehicle/armor/weapon under clonebase). Called from vehicle insert open family. Load pipeline primitive.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007bfd10_*.md` |
| Annotated | `docs/reconstruction/raw/aa_007bfd10_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Named_dcCloneBase_Insert_MoveFirst.cpp` |
| Function record | `docs/reconstruction/functions/aa_007bfd10_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| dcCloneBase insert/move-first | High | Name |
| Parent cursor for gear opens | High | Xref pattern |
| Not full tCloneBase load | High | Distinct from 007e07b0 |
| Cursor CF residual | Medium | FUN names |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| ensure open → move/insert first → return hr | Yes |

---

## 5. Gaps / open

1. Document parent/child open order with dcWeapon/dcArmor.

**Verdict:** **accept-with-gaps**
