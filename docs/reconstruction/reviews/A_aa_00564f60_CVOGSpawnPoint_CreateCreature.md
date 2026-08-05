# Review A (reconstruction fidelity): `aa_00564f60` CVOGSpawnPoint_CreateCreature

| Field | Value |
|---|---|
| **Stable ID** | `aa_00564f60` |
| **VA** | `0x00564f60` |
| **Canonical name** | `CVOGSpawnPoint_CreateCreature` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00564f60_CVOGSpawnPoint_CreateCreature.md` |
| **System** | `npc-ai` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Spawn creature from map spawn point: validate template type **0x12**, instantiate (new path or cached +0x1c0), assign unique id, init waypoints, apply terrain height (Speed>0 OR spawn flag OR IsNPC: ray Y+3, +flying height if flag bit4 clear, +foot offset creature+0x120).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00564f60_CVOGSpawnPoint_CreateCreature.md` |
| Annotated | `docs/reconstruction/raw/aa_00564f60_CVOGSpawnPoint_CreateCreature.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGSpawnPoint_CreateCreature.cpp` |
| Function record | `docs/reconstruction/functions/aa_00564f60_CVOGSpawnPoint_CreateCreature.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Lookup template FUN_00404d70; fail → 0` | **High** | Body |
| `Require type 0x12 else old-vehicle error log` | **High** | Body |
| `Cached creature at spawn+0x1c0 vs generate FUN_004cf2a0` | **High** | Body |
| `Unique id stamp map counters +0xe6d8` | **High** | Body |
| `CVOGWaypoint_InitFromSpawn` | **High** | Body |
| `Height path: terrain ray + flying + foot offset when Speed/flag/IsNPC` | **High** | Plate + AutoCore NPC_SPAWN_HEIGHT |
| `SEH / ExceptionList noise` | **High** | Decomp artifact |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Validate + create/cache + id + waypoints + place | **Yes** |
| Full height math details | **See plate/docs — preserved in body** |

---

## 5. Gaps / open

1. Full height math rest of function not line-audited here (body continues past init).
2. AI bind helpers residual.

**Verdict:** **accept-with-gaps**
