# Review A (reconstruction fidelity): `aa_0093bf60` Inv_ValidateItemsAfterRandomization

| Field | Value |
|---|---|
| **Stable ID** | `aa_0093bf60` |
| **VA** | `0x0093bf60` |
| **Canonical name** | `Inv_ValidateItemsAfterRandomization` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0093bf60_Inv_ValidateItemsAfterRandomization.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Post-randomization inventory integrity check: walks cargo and locker linked lists of item nodes and logs when a recorded coid/qty is missing from inventory after a randomize pass. Multi-list walk (`param_3` cargo head, `param_9` / `param_12` related lists). Debug/integrity — not loot grant.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0093bf60_Inv_ValidateItemsAfterRandomization.md` (or `aa_0093bf60_FUN_0093bf60.md`) |
| Annotated | `docs/reconstruction/raw/aa_0093bf60_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Inv_ValidateItemsAfterRandomization.cpp` |
| Function record | `docs/reconstruction/functions/aa_0093bf60_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Walk cargo linked list` | High | Body loops |
| `Walk locker/related lists` | High | Multi param lists |
| `Log missing coid/qty after randomize` | High | Purpose |
| `Not mutation of inventory` | High | Validate/log |
| `inventory-transfer system` | High | Plate |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Nested list walks + missing checks | Yes |
| No invented grant | Yes |

---

## 5. Gaps / open

1. Full param role map (many params).
2. Randomize caller identity.

**Verdict:** **accept-with-gaps**
