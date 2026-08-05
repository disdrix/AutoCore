# Review A (reconstruction fidelity): `aa_00564290` CVOGSpawnPoint_CreateTemplateVehicle

| Field | Value |
|---|---|
| **Stable ID** | `aa_00564290` |
| **VA** | `0x00564290` |
| **Canonical name** | `CVOGSpawnPoint_CreateTemplateVehicle` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00564290_CVOGSpawnPoint_CreateTemplateVehicle.md` |
| **System** | `npc-ai` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Spawn template vehicle from spawn point: terrain height sample, optional scatter find, allocate/init vehicle (0x800), copy pose/orient from spawn, waypoint init, optional activate. Parallel to CreateCreature for vehicle templates / DR hosts.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00564290_CVOGSpawnPoint_CreateTemplateVehicle.md` |
| Annotated | `docs/reconstruction/raw/aa_00564290_CVOGSpawnPoint_CreateTemplateVehicle.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGSpawnPoint_CreateTemplateVehicle.cpp` |
| Function record | `docs/reconstruction/functions/aa_00564290_CVOGSpawnPoint_CreateTemplateVehicle.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `CVOGMap_CastTerrainHeight on spawn XYZ` | **High** | Y adjust with g_flVehicleHpTechCoeff |
| `Optional scatter FUN_004e9720 when +0x1a9` | **High** | Fail → log + return 0 |
| `operator_new(0x800) + FUN_00501970 construct` | **High** | Alloc path |
| `Init fail → destroy + VOG_DEBUG_STOP return 0` | **High** | FUN_00503780 gate |
| `Copy position +0x84 block and orient +0x94` | **High** | From spawn dual-base |
| `CVOGWaypoint_InitFromSpawn path COID` | **High** | AI return path support |
| `param_4 activate → flag + FUN_0053d970(1)` | **High** | Optional |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Height + optional scatter | **Yes** |
| Alloc/init/fail | **Yes** |
| Pose copy + waypoint + activate | **Yes** |

---

## 5. Gaps / open

1. FUN_00501970 vehicle ctor true name.
2. Scatter radius constants 0x40a00000 semantics.
3. Race id FUN_00512460 when +0x1a8.
4. Runtime template vehicle spawn capture.

**Verdict:** **accept-with-gaps**
