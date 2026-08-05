# Review A (reconstruction fidelity): `aa_00931db0` Client_ShowEquipFailureMessage

| Field | Value |
|---|---|
| **Stable ID** | `aa_00931db0` |
| **VA** | `0x00931db0` |
| **Canonical name** | `Client_ShowEquipFailureMessage` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00931db0_Client_ShowEquipFailureMessage.md` |
| **System tag** | `inventory-transfer` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Clean | `docs/reconstruction/reconstructed-exact/Client_ShowEquipFailureMessage.cpp` |
| Raw | `docs/reconstruction/raw/aa_00931db0_*` (annotated if present) |
| Reviews dir | `docs/reconstruction/reviews/` |

**Purpose (from clean plate / body):** Map equip-failure reason codes (switch on unaff_EDI) to localized player messages: town-only, unidentified tech, too heavy, tech too advanced, inventory space, etc. Toast via FUN_007fdfb0.

---

## 2. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| switch(reason) multi-case | High | Body |
| Town-only string case 1 | High | String+case |
| Unidentified / heavy / advanced tech strings | High | Strings |
| Inventory space equipment string | High | String |
| Toast only | High | No equip attempt |

---

## 3. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| switch reason → format toast → return | Yes |

---

## 4. Gaps

1. Complete case table (all reason codes).
2. Caller mapping from server fail codes.

**Verdict:** **accept-with-gaps**
