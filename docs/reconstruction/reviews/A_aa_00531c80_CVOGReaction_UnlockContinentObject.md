# Review A (reconstruction fidelity): `aa_00531c80` CVOGReaction_UnlockContinentObject

| Field | Value |
|---|---|
| **Stable ID** | `aa_00531c80` |
| **VA** | `0x00531c80` |
| **Canonical name** | `CVOGReaction_UnlockContinentObject` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00531c80_CVOGReaction_UnlockContinentObject.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Insert/mark a **continent/region unlock** on the character hash at `char+0x534`:

1. Probe hash bucket for `continentId`.
2. If found with non-null payload at node+8 → **already unlocked**, return.
3. Else allocate 0xC node: `{continentId, flag=1, 0}`, `CNDHash_Insert` into `+0x534`.
4. If this character is the local dual-base identity, fire UI packet path (`FUN_004d1d00` + opcode `0x2a` via `FUN_004d9ec0`).

Also used from `Client_RecvUnlockRegion` (fog 0x205B) and mission grant/complete. Distinct from reaction type 32 map-object unlock.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00531c80_CVOGReaction_UnlockContinentObject.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGReaction_UnlockContinentObject.cpp` |
| System map | `docs/reconstruction/systems/missions-progression.md` (when present) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__thiscall(char*, continentId)` | **High** | Raw |
| Hash at char+0x534 | **High** | Probe + Insert |
| Idempotent when node+8 set | **High** | Early return |
| Insert node layout 0xC | **High** | operator_new(0xc) |
| Local-player UI notify opcode 0x2a | **Probable** | identity check + packet |
| Name vs reaction type 32 UnlockContObj | **High** | Plate distinguishes |
| CNDHash internals | **Tentative** | Library helper |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Hash probe loop | **Yes** |
| Insert + local UI branch | **Yes** |
| Already-unlocked early return | **Yes** |
| No invented fog packet fields | **Yes** |

---

## 5. Gaps

1. Node field semantics beyond id/flag.
2. FUN_004d1d00 / FUN_004d9ec0 packet schema.
3. Whether continentId is map id, fog region, or object id.
4. Server authority vs client apply only.

**Verdict:** accept-with-gaps.
