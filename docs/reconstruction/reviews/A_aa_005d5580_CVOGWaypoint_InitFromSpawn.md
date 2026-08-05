# Review A (reconstruction fidelity): `aa_005d5580` CVOGWaypoint_InitFromSpawn

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d5580` |
| **VA** | `0x005d5580` |
| **Canonical name** | `CVOGWaypoint_InitFromSpawn` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005d5580_CVOGWaypoint_InitFromSpawn.md` |
| **System** | `npc-ai` |
| **Verdict** | **accept** |

---

## 1. Purpose

Initialize `CVOGWaypoint` from spawn/path params (Phase D). Clears pose `+0x20..+0x2c` to 0; seeds path slots `+0x40/+0x44/+0x48` to **0xFFFFFFFF** then writes `param_2/3/4` (MapPath COID low/high + extra path id). Sets FSM state `+0x50` to **0** if `param_6==0` else **2**; flag `+0x51 = param_7`; patrol float `+0x4c = param_5` (spawn `InitialPatrolDistance`). Called from `CVOGSpawnPoint_CreateCreature` / `CreateTemplateVehicle`. Core for NPC path AI attach — AutoCore mirrors MapPathCoid + PatrolDistance.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005d5580_CVOGWaypoint_InitFromSpawn.md` |
| Annotated | `docs/reconstruction/raw/aa_005d5580_CVOGWaypoint_InitFromSpawn.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGWaypoint_InitFromSpawn.cpp` |
| Function record | `docs/reconstruction/functions/aa_005d5580_CVOGWaypoint_InitFromSpawn.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Clears +0x51 then path ids to -1 first` | **High** | Body order |
| `+0x50 = 0 if param_6==0 else 2` | **High** | Branch |
| `Zeros pose +0x20..+0x2c` | **High** | Stores |
| `+0x40=param_2 +0x44=param_3 +0x48=param_4 path COIDs` | **High** | Stores |
| `+0x51=param_7 flags` | **High** | Store |
| `+0x4c=param_5 patrol distance float` | **High** | Store + NPC.md |
| `Spawn sources MapPathCoid +0xa0, InitialPatrolDistance +0x7c` | **High** | Plate/NPC.md |
| `No UpdateState call here` | **High** | No call |
| `CreateCreature / CreateTemplateVehicle callers` | **High** | Xref notes |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Clear + state gate + write COIDs/patrol/flags | **Yes** |
| No invented path follow | **Yes** |

---

## 5. Gaps / open

1. Full meaning of param_6 (start state select) vs param_7 flags.
2. Whether +0x48 extra path id is always -1 from spawn path.
3. Object size / other fields not touched by init.

**Verdict:** **accept**
