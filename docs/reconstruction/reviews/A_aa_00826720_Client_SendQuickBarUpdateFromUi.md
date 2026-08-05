# Review A (reconstruction fidelity): `aa_00826720` Client_SendQuickBarUpdateFromUi

| Field | Value |
|---|---|
| **Stable ID** | `aa_00826720` |
| **VA** | `0x00826720` |
| **Canonical name** | `Client_SendQuickBarUpdateFromUi` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00826720_Client_SendQuickBarUpdateFromUi.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Build/send EMSG_Sector_QuickBarUpdate (**0x2062**) for active QuickBar UI slot: slot = page*10+column from ESI UI object; isItem = (kind != 1 skill); value int64 from payload; send 0x10 bytes via sector net vtbl+0x18.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00826720_Client_SendQuickBarUpdateFromUi.md` |
| Annotated | `docs/reconstruction/raw/aa_00826720_Client_SendQuickBarUpdateFromUi.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_SendQuickBarUpdateFromUi.cpp` |
| Function record | `docs/reconstruction/functions/aa_00826720_Client_SendQuickBarUpdateFromUi.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Opcode 0x2062` | **High** | Body |
| `Packet size 0x10` | **High** | Body |
| `slot = *(ESI+0x504)*10 + *(ESI+0x500)` | **High** | Body |
| `isItem = kind != QuickBarSlotKind_Skill(1)` | **High** | Body |
| `value lo/hi from payload +8/+0xc` | **High** | Body |
| `Null payload no-op` | **High** | Body |
| `ESI UI this residual` | **Probable** | Custom convention |
| `No server ack / optimistic` | **Probable** | Plate RE note |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Null check + pack + send | **Yes** |

---

## 5. Gaps / open

1. Pad uint16 at +0x06 uninitialized on stack (plate) — noise risk.
2. Register convention non-standard.

**Verdict:** **accept-with-gaps**
