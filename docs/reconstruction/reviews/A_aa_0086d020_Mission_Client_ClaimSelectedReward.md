# Review A (reconstruction fidelity): `aa_0086d020` Mission_Client_ClaimSelectedReward

| Field | Value |
|---|---|
| **Stable ID** | `aa_0086d020` |
| **VA** | `0x0086d020` |
| **Canonical name** | `Mission_Client_ClaimSelectedReward` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0086d020_Mission_Client_ClaimSelectedReward.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Mission/arena reward-claim UI handler (`__thiscall`). Switch on UI message ids (**40000** / **0x9c41**). Accept path requires selected reward — else toast `You need to select a reward first!`. On accept with selection (`+0x510>0` and related `+0x528` state), builds sector packet with opcode **0x20c6** (local stack seed) and `Client_SendSectorPacket`; may also `CVOGReaction_GiveItemByCbid` for local grant path. Client claim UX + C2S, not pure server authority.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0086d020_Mission_Client_ClaimSelectedReward.md` (or `aa_0086d020_FUN_0086d020.md`) |
| Annotated | `docs/reconstruction/raw/aa_0086d020_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Mission_Client_ClaimSelectedReward.cpp` |
| Function record | `docs/reconstruction/functions/aa_0086d020_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Switch UI msgs 40000 / 0x9c41` | High | Body switch |
| `Select-reward gate string` | High | Literal |
| `Selection state +0x510 / +0x528` | High | Accept path |
| `Sector packet seed 0x20c6` | High | Stack opcode |
| `Client_SendSectorPacket` | High | Callee |
| `GiveItemByCbid on grant path` | High | Callee |
| `Not server-only claim` | High | Client UI handler |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Msg switch → select gate → send/grant | Yes |
| No invented opcode beyond stack seed | Yes |

---

## 5. Gaps / open

1. Full packet payload layout for 0x20c6.
2. Whether GiveItemByCbid is optimistic local vs post-ack.
3. Arena vs mission dialog sharing.

**Verdict:** **accept-with-gaps**
