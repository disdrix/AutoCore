# Review A (reconstruction fidelity): `aa_007e1630` Named_vCloneBase_NameList

| Field | Value |
|---|---|
| **Stable ID** | `aa_007e1630` |
| **VA** | `0x007e1630` |
| **Canonical name** | `Named_vCloneBase_NameList` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_007e1630_Named_vCloneBase_NameList.md` |
| **System** | `client-load` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Clonebase **name-list vector/table loader** (`vCloneBase_NameList`). DB/list reader producing name entries for clonebase IDs — supports UI, loot labels, and load validation. Shares DBReader helpers with `tCloneBase`. Not runtime GetTypeFromIDPrefix.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007e1630_*.md` |
| Annotated | `docs/reconstruction/raw/aa_007e1630_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Named_vCloneBase_NameList.cpp` |
| Function record | `docs/reconstruction/functions/aa_007e1630_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Name-list loader for clonebase | High | Name + DB pattern |
| Shares reader helpers with tCloneBase | High | Callee overlap |
| Full entry format | Medium | Residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| open → iterate names → store list → close | Yes |

---

## 5. Gaps / open

1. Seal name entry struct (id, string, flags).

**Verdict:** **accept-with-gaps**
