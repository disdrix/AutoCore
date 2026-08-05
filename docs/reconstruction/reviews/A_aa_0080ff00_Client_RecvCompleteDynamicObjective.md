# Review A (reconstruction fidelity): `aa_0080ff00` Client_RecvCompleteDynamicObjective

| Field | Value |
|---|---|
| **Stable ID** | `aa_0080ff00` |
| **VA** | `0x0080ff00` |
| **Canonical name** | `Client_RecvCompleteDynamicObjective` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0080ff00_Client_RecvCompleteDynamicObjective.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

S2C handler for CompleteDynamicObjective (plate opcode **0x2070**): clear mission UI helper, optional type-3 requirement world-target capture, **always** `CVOGReaction_CompleteObjective(id,-1,-1,force=1)`, refresh mission dialog/journal chrome, optional `Client_SendUseObject` when world target matches, bulk `Client_RefreshOpenMissionUiWindows`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0080ff00_Client_RecvCompleteDynamicObjective.md` |
| Annotated | `docs/reconstruction/raw/aa_0080ff00_Client_RecvCompleteDynamicObjective.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_RecvCompleteDynamicObjective.cpp` |
| Function record | `docs/reconstruction/functions/aa_0080ff00_Client_RecvCompleteDynamicObjective.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Packet objective id @+0x10` | **High** | Body reads pPacket+0x10 as CompleteObjective arg0 |
| `Always force-complete (force=1)` | **High** | Unconditional call after optional scan |
| `Reward COID filters -1,-1` | **High** | 0xffffffff pair in call |
| `Active-obj hash at char+0x548` | **High** | CNDHash_LookupByKey |
| `Req type==3 via vtbl+0x50; target piReq[6]` | **High** | Scan loop preserved |
| `Mission UI vcalls +0x107c / dialog +0x10b0` | **High** | Same family as ObjectiveState |
| `Optional UseObject world scan` | **High** | FUN_009197a0 / list iterate / LeaveCriticalSection |
| `Client in EDI (unaff_EDI)` | **Probable** | Handler register binding |
| `Opcode is 0x2070` | **Probable** | Plate/dispatch; body does not self-check opcode |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| UI clear + hash lookup + req scan | **Yes** |
| Unconditional CompleteObjective | **Yes** |
| UI refresh paths | **Yes** |
| World UseObject optional | **Yes** |
| Bulk refresh + secondary UI | **Yes** |
| No invented modernizations | **Yes** |

---

## 5. Gaps / open

1. True PacketDispatch opcode binding not sealed in body.
2. CVOGReaction_CompleteObjective thiscall framing (character) elided by decompiler.
3. World pick helper FUN_009197a0 key 0x41700000 (~15.0f) semantics open.
4. Runtime / differential open.

**Verdict:** **accept-with-gaps**
