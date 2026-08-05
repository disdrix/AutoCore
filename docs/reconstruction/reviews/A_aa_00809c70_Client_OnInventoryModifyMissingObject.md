# Review A (reconstruction fidelity): `aa_00809c70` Client_OnInventoryModifyMissingObject

| Field | Value |
|---|---|
| **Stable ID** | `aa_00809c70` |
| **VA** | `0x00809c70` |
| **Canonical name** | `Client_OnInventoryModifyMissingObject` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00809c70_Client_OnInventoryModifyMissingObject.md` |
| **System tag** | `inventory-transfer` |
| **Verdict** | **accept** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Clean | `docs/reconstruction/reconstructed-exact/Client_OnInventoryModifyMissingObject.cpp` |
| Raw | `docs/reconstruction/raw/aa_00809c70_*` (annotated if present) |
| Reviews dir | `docs/reconstruction/reviews/` |

**Purpose (from clean plate / body):** Error path when modifying an object not present in inventory. Toast: 'Tried to modify an object that isn't in inventory.'

---

## 2. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Missing-object inventory toast | High | String |
| Error-only; no invent item | High | Purpose |
| Sibling Alt path exists | High | OnInventoryModifyMissingObjectAlt |

---

## 3. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Show missing-object error toast | Yes |

---

## 4. Gaps

1. Why two sibling handlers (primary vs Alt).
2. Dispatch opcode/context.

**Verdict:** **accept**
