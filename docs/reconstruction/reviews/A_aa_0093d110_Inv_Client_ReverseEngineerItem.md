# Review A (reconstruction fidelity): `aa_0093d110` Inv_Client_ReverseEngineerItem

| Field | Value |
|---|---|
| **Stable ID** | `aa_0093d110` |
| **VA** | `0x0093d110` |
| **Canonical name** | `Inv_Client_ReverseEngineerItem` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0093d110_Inv_Client_ReverseEngineerItem.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Client reverse-engineer UI/action path on selected item (`param_1` view/object; client shell in register). Checks item flags (`>>0x13 & 1`), type codes (e.g. `+0x38 == 0x1a`), uses many UI/item helpers; may prompt skill target (`FUN_0093bac0` family) and fire RE request. Client gate + UX; pairs failure toast unit `Client_OnReverseEngineerFailure`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0093d110_Inv_Client_ReverseEngineerItem.md` (or `aa_0093d110_FUN_0093d110.md`) |
| Annotated | `docs/reconstruction/raw/aa_0093d110_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Inv_Client_ReverseEngineerItem.cpp` |
| Function record | `docs/reconstruction/functions/aa_0093d110_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Selected item entry` | High | param_1 |
| `Flag bit >>0x13 & 1 gate` | High | Body |
| `Type code checks` | High | 0x1a path |
| `Heavy UI/item FUN fanout` | High | Callees |
| `Client RE path` | High | System |
| `Not server RE authority` | High | Client |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Validate selection → gates → UI/request | Yes |
| No invented server craft tables | Yes |

---

## 5. Gaps / open

1. Exact C2S opcode for RE request.
2. Full flag meaning for >>0x13.

**Verdict:** **accept-with-gaps**
