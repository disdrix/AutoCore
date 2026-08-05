# Review A (reconstruction fidelity): `aa_007fc100` Client_SendQuickBarUpdateWithSlot

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fc100` |
| **VA** | `0x007fc100` |
| **Canonical name** | `Client_SendQuickBarUpdateWithSlot` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_007fc100_Client_SendQuickBarUpdateWithSlot.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Same EMSG_Sector_QuickBarUpdate (**0x2062**) 0x10-byte wire as FromUi, but absolute slot supplied in **CL** and payload pointer in **EAX** (custom register convention).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007fc100_Client_SendQuickBarUpdateWithSlot.md` |
| Annotated | `docs/reconstruction/raw/aa_007fc100_Client_SendQuickBarUpdateWithSlot.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_SendQuickBarUpdateWithSlot.cpp` |
| Function record | `docs/reconstruction/functions/aa_007fc100_Client_SendQuickBarUpdateWithSlot.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Opcode 0x2062 size 0x10` | **High** | Body |
| `isItem = *payload != 1` | **High** | Body |
| `value from payload[2], payload[3]` | **High** | Body |
| `Slot from CL (plate; not visible as formal in clean)` | **Probable** | Register residual |
| `Null EAX no-op` | **High** | Body |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Null check + pack + send | **Yes** |
| Slot register not modeled as formal | **Gap in clean formals** |

---

## 5. Gaps / open

1. Clean omits explicit CL slot field in locals — stack layout may still include it via register.
2. Confirm slot is written into packet +0x04 in binary.

**Verdict:** **accept-with-gaps**
