# Review A (reconstruction fidelity): `aa_00809d20` Client_OnInventoryModifyMissingObjectAlt

| Field | Value |
|---|---|
| **Stable ID** | `aa_00809d20` |
| **VA** | `0x00809d20` |
| **Canonical name** | `Client_OnInventoryModifyMissingObjectAlt` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00809d20_Client_OnInventoryModifyMissingObjectAlt.md` |
| **System tag** | `inventory-transfer` |
| **Verdict** | **accept** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Clean | `docs/reconstruction/reconstructed-exact/Client_OnInventoryModifyMissingObjectAlt.cpp` |
| Raw | `docs/reconstruction/raw/aa_00809d20_*` (annotated if present) |
| Reviews dir | `docs/reconstruction/reviews/` |

**Purpose (from clean plate / body):** Sibling error path for inventory modify of a missing object. Same toast string as primary: 'Tried to modify an object that isn't in inventory.'

---

## 2. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Same missing-object toast string | High | String |
| Sibling of 00809c70 | High | Address/name pair |
| Error UX only | High | Purpose |

---

## 3. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Show missing-object error toast | Yes |

---

## 4. Gaps

1. Call-site difference vs primary handler.

**Verdict:** **accept**
