# Review A (reconstruction fidelity): `aa_0092ce00` Client_SendInstantRepairRequest

| Field | Value |
|---|---|
| **Stable ID** | `aa_0092ce00` |
| **VA** | `0x0092ce00` |
| **Canonical name** | `Client_SendInstantRepairRequest` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0092ce00_Client_SendInstantRepairRequest.md` |
| **System** | `unknown` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

C2S InstantRepair request (plate opcode **0x20B6**): if global `DAT_00d1b6d8` set and connection at `in_EAX+0xc78`, send 4-byte opcode-only packet via vtbl+0x18 and stamp `GetTickCount` to global+0x620.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0092ce00_Client_SendInstantRepairRequest.md` |
| Annotated | `docs/reconstruction/raw/aa_0092ce00_Client_SendInstantRepairRequest.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_SendInstantRepairRequest.cpp` |
| Function record | `docs/reconstruction/functions/aa_0092ce00_Client_SendInstantRepairRequest.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Opcode 0x20B6 in local stack` | **High** | Body |
| `Send size 4 (opcode only)` | **High** | Body |
| `Gate DAT_00d1b6d8 non-zero` | **High** | Body |
| `Connection *(in_EAX+0xc78) vtbl+0x18` | **High** | Body |
| `Tick stamp global+0x620` | **High** | Body |
| `in_EAX = client/game object` | **Probable** | Residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Global gate + send + tick | **Yes** |

---

## 5. Gaps / open

1. What DAT_00d1b6d8 represents (INC UI state?).
2. No body payload fields — confirm server accepts opcode-only.
3. Not implemented in AutoCore yet (plate).

**Verdict:** **accept-with-gaps**
