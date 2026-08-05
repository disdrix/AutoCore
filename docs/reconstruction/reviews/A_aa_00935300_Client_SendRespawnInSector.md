# Review A (reconstruction fidelity): `aa_00935300` Client_SendRespawnInSector

| Field | Value |
|---|---|
| **Stable ID** | `aa_00935300` |
| **VA** | `0x00935300` |
| **Canonical name** | `Client_SendRespawnInSector` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00935300_Client_SendRespawnInSector.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

C2S **INC airlift / respawn-in-sector request**:

- Opcode **`EMSG_Sector_RespawnInSector = 0x2073`**
- Wire size **`0x28`** bytes (via `Client_SendSectorPacket`)

**Layout (plate + body):**

| Off | Field |
|---:|---|
| +0x00 | opcode `0x2073` |
| +0x04 | float3 **current vehicle position** (NOT destination) |
| +0x10 | float4 **current vehicle quaternion** |
| +0x20 | int64 entity COID from local char at `client+0xe98` (live: **character** coid) |

Gates: local char present and `char+0x250 != 0` (vehicle); map/context id matches `FUN_00402ae0` vs `client+0xd28`.

After send: `FUN_007fc840` (likely UI/state cleanup). Called after INC option-0 countdown (“Returning you to nearest repair station…”). Server resolves dest from LastStation\* / pad pose and replies SpecialEvent Respawn.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00935300_Client_SendRespawnInSector.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_SendRespawnInSector.cpp` |
| Function record | `docs/reconstruction/functions/aa_00935300_Client_SendRespawnInSector.md` |
| Related | `Client_SendSectorPacket` dual-reviewed |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Opcode 0x2073 + size 0x28 | **High** | Body + plate |
| Pose = current vehicle, not dest | **High** | Plate + FUN_00404c90 / 00404a20 reads |
| COID from local char entity | **High** | +0x164/+0x168 pattern |
| Vehicle required (`+0x250`) | **High** | Gate |
| Map id match gate | **High** | Compare to +0xd28 |
| Server chooses destination | **High** | Plate / AutoCore note |
| `unaff_ESI` = client context | **Probable** | Standard client this |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Char / vehicle gates | **Yes** |
| Map match gate | **Yes** |
| Pack pose + COID | **Yes** |
| SendSectorPacket 0x28 | **Yes** |
| Post-send FUN | **Yes** |

---

## 5. Gaps

1. Exact FUN_00404c90 / 00404a20 names (pos/quat getters).
2. FUN_007fc840 cleanup role.
3. Full INC UI countdown caller not dual-reviewed.
4. Runtime wire capture open.
5. Other `Client_SendRespawn*` variants not present in corpus (only InSector).

**Verdict:** C2S 0x2073 packer sealed. **accept-with-gaps.**
