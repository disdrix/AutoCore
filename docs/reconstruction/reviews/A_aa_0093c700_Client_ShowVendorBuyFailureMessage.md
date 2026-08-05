# Review A (reconstruction fidelity): `aa_0093c700` Client_ShowVendorBuyFailureMessage

| Field | Value |
|---|---|
| **Stable ID** | `aa_0093c700` |
| **VA** | `0x0093c700` |
| **Canonical name** | `Client_ShowVendorBuyFailureMessage` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0093c700_Client_ShowVendorBuyFailureMessage.md` |
| **System tag** | `inventory-transfer` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Clean | `docs/reconstruction/reconstructed-exact/Client_ShowVendorBuyFailureMessage.cpp` |
| Raw | `docs/reconstruction/raw/aa_0093c700_*` (annotated if present) |
| Reviews dir | `docs/reconstruction/reviews/` |

**Purpose (from clean plate / body):** Vendor buy failure: stock ('aren't enough of this item'), full inventory, or cannot afford. May involve Client_SendSectorPacket on some branches; primarily failure UX with currency/stock checks.

---

## 2. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Stock insufficient string | High | String |
| Inventory full buy string | High | String |
| Cannot afford string | High | String |
| Client_SendSectorPacket present in callees | Probable | Notable callees |
| Multi-branch failure map | High | Body |

---

## 3. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Evaluate stock/space/afford → toast and/or related send | Yes |

---

## 4. Gaps

1. Exact conditions for send vs toast-only.
2. Vendor packet opcodes on success path (not this unit).

**Verdict:** **accept-with-gaps**
