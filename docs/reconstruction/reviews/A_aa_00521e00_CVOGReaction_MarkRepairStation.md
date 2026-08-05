# Review A (reconstruction fidelity): `aa_00521e00` CVOGReaction_MarkRepairStation

| Field | Value |
|---|---|
| **Stable ID** | `aa_00521e00` |
| **VA** | `0x00521e00` |
| **Canonical name** | `CVOGReaction_MarkRepairStation` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00521e00_CVOGReaction_MarkRepairStation.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Reaction type **29** client apply: remember player's **last repair station**:

1. Resolve related map object via dual-base `+0xa8`.
2. On success:
   - `char+0x634 |= 1`
   - `char+0x740 = mapId` from related `+0xFC`
   - `char+0x744 = stationKey` (reaction GenericVar1 — small key, not map object COID)
   - Call `CVOGReaction_UpdateRepairStationPosition(playerTFID, stationKey)` with TFID from dual-base `+0x164/+0x168`
3. On missing related object:
   - `char+0x634 |= 1`
   - `char+0x744 = -1`
   - return false-ish (low byte cleared)

AutoCore server mirror notes in clean plate: `Reaction.HandleMarkRepairStation` + `Character.SetLastRepairStation`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00521e00_CVOGReaction_MarkRepairStation.md` |
| Annotated | `docs/reconstruction/raw/aa_00521e00_CVOGReaction_MarkRepairStation.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGReaction_MarkRepairStation.cpp` |
| Function record | `docs/reconstruction/functions/aa_00521e00_CVOGReaction_MarkRepairStation.md` |
| Callee | UpdateRepairStationPosition `aa_004d38b0` |
| Mission notes | `docs/missionState.md` type 29 |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__thiscall(char*, stationKey)` | **High** | Clean plate + raw |
| Writes +0x634 bit0, +0x740 map, +0x744 key | **High** | Explicit |
| stationKey is GenericVar1 not COID | **High** | Plate + server docs family |
| UpdateRepairStationPosition follow-on | **High** | Call |
| Fail path +0x744=-1 | **High** | Explicit |
| Map id at related+0xFC | **High** | Load |
| Map `this` for Update call recovery | **Tentative** | Clean passes nullptr with comment |
| Bit0 of +0x634 product name | **Tentative** | Shared flags word with fail bit 0x10 |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Related present vs absent | **Yes** (human-refined clean) |
| Flag/map/key writes | **Yes** |
| Update call | **Yes** |
| Fail return packing | **Yes** |

---

## 5. Gaps

1. Exact dual-base TFID recovery vs decompiler registers.
2. Consumers of last station (+0x740/+0x744) for respawn.
3. Shared +0x634 bitfield map incomplete.
4. Runtime mark capture open.
5. Clean human refine slightly ahead of scaffold raw comments — still CF-aligned.

**Verdict:** Mark station CF faithful. **accept-with-gaps.**
