# Review A (reconstruction fidelity): `aa_0080cc50` Client_RecvSpecialEvent

| Field | Value |
|---|---|
| **Stable ID** | `aa_0080cc50` |
| **VA** | `0x0080cc50` |
| **Canonical name** | `Client_RecvSpecialEvent` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0080cc50_Client_RecvSpecialEvent.md` |
| **System** | `unknown` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

S2C presentation event (plate opcode **0x20A9**): type@+4 is Respawn(0)/TeleportOut(1)/TeleportIn(2); requires local entity TFID match (character coid) or resolve fallback type 0x14 vehicle with +0x250; constructs event object and enqueues via FUN_00403150.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0080cc50_Client_RecvSpecialEvent.md` |
| Annotated | `docs/reconstruction/raw/aa_0080cc50_Client_RecvSpecialEvent.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_RecvSpecialEvent.cpp` |
| Function record | `docs/reconstruction/functions/aa_0080cc50_Client_RecvSpecialEvent.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Event type byte @+4: 0/1/2 only` | **High** | Else early return |
| `TFID@+0x28/0x2c must match local char or vehicle resolve type 0x14` | **High** | Body |
| `Requires entity+0x250 non-null` | **High** | Body |
| `Respawn needs new 0x70 + flag@+0x40; TeleportOut 0x34; TeleportIn 0x50` | **High** | Body |
| `Pose floats copied from packet into ctor locals` | **High** | Body |
| `Opcode 0x20A9` | **Probable** | Plate/dispatch |
| `thiscall (packet, client)` | **Probable** | Plate |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| TFID match / resolve fallback | **Yes** |
| +0x250 gate | **Yes** |
| Type switch ctors | **Yes** |
| Enqueue FUN_00403150 | **Yes** |

---

## 5. Gaps / open

1. Vehicle-vs-character coid live note is operational; body compares TFID fields only.
2. Ctor internal semantics open.
3. Runtime special-event capture open.

**Verdict:** **accept-with-gaps**
