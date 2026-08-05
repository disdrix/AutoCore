# Review A (reconstruction fidelity): `aa_0089bf50` Inv_Client_ValidateCraftAffordability

| Field | Value |
|---|---|
| **Stable ID** | `aa_0089bf50` |
| **VA** | `0x0089bf50` |
| **Canonical name** | `Inv_Client_ValidateCraftAffordability` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0089bf50_Inv_Client_ValidateCraftAffordability.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Craft UI validation: look up recipe cost, format Cost line, block craft when required components missing from inventory or player cannot afford credit cost. String evidence includes cannot-make-with-components-you-have path. Uses `CNDHash_LookupByKey` + inventory probes. Companion of refinery/craft UI (related to refinery remove response path). Client gate only.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0089bf50_Inv_Client_ValidateCraftAffordability.md` (or `aa_0089bf50_FUN_0089bf50.md`) |
| Annotated | `docs/reconstruction/raw/aa_0089bf50_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Inv_Client_ValidateCraftAffordability.cpp` |
| Function record | `docs/reconstruction/functions/aa_0089bf50_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Recipe cost lookup` | High | Purpose |
| `Component missing block` | High | String evidence |
| `Credit afford gate` | High | Purpose |
| `Formats Cost UI line` | High | UI |
| `CNDHash_LookupByKey` | High | Callee |
| `Client-only validate` | High | No server craft exec |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Lookup recipe → check mats/credits → UI block/format | Yes |
| No invented server craft commit | Yes |

---

## 5. Gaps / open

1. Exact mat slot offsets.
2. Credit field source on character.
3. Full toast string set.

**Verdict:** **accept-with-gaps**
