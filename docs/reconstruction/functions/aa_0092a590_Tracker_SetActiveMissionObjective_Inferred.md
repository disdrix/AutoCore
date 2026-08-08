# Function record: Tracker_SetActiveMissionObjective_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0092a590` |
| **Canonical name** | `Tracker_SetActiveMissionObjective_Inferred` |
| **Ghidra name** | `FUN_0092a590` |
| **Address** | `0x0092a590`–`0x0092a5fe` (**111 B** / `0x6F`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `missions-progression` |
| **Partition** | MEGA-010 (WAVE_2026-08-05_mega_residual_partition_map) |
| **Parent dual** | `Client_TryBindActiveMissionTracker` (`0x0092fd00`, W21-Q) |
| **Completion status** | **Dual sealed** (2026-08-05 MEGA-010) — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred). Terminal **false**. |

## Alias

- Ghidra: `FUN_0092a590`
- Retired: `Named_CalleeOf_Named_CalleeOf_Client_MissionDialogHandleButton_0092a590`
- Parent plate already referenced this unit as tracker binder write

## Purpose

Set (or clear) the tracker's active mission objective binding:

1. `tracker+0x10 = missionId`; `tracker+0x6 = 1`.
2. If `missionId == 0`: clear vector (`FUN_0092a3d0` via EDI), reset display (`FUN_00929c00` via EAX), zero `+0x10`/`+0xc`, return 1.
3. Else resolve `character = (*tracker)->+0xe98`; lookup `CNDHash_LookupByKey(char+0x548, missionId)`.
4. On hit: `tracker+0xc = **(node+0x14c)`; `tracker+0x4 = 1`; return 1.
5. On miss/null: same clear as (2), return 0.

## Signature (image-sealed)

```c
char __fastcall Tracker_SetActiveMissionObjective_Inferred(
    MissionTracker* tracker /*ECX*/,
    uint32_t missionId /*EAX*/);
```

## Field map (sealed)

| Offset | Role |
|--------|------|
| `+0x00` | host/client* |
| `+0x04` | bind-success flag (byte) |
| `+0x06` | dirty flag (byte) |
| `+0x0c` | active objective head (u32 from node+0x14c) |
| `+0x10` | active mission id |
| `+0x11c/+0x120` | objective vector (cleared by helper) |

## Artifacts

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0092a590_FUN_0092a590.md` |
| Annotated | `docs/reconstruction/raw/aa_0092a590_FUN_0092a590.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Tracker_SetActiveMissionObjective_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0092a590.cpp` |
| Dual A | `docs/reconstruction/reviews/A_aa_0092a590_Tracker_SetActiveMissionObjective_Inferred.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_0092a590_Tracker_SetActiveMissionObjective_Inferred.md` |
| FUN record | `docs/reconstruction/functions/aa_0092a590_FUN_0092a590.md` |
| Report | `docs/agents/task-dual-ab-0092a590-mega-010-report.md` |

## Callers / callees

**Callers (1):** `Client_TryBindActiveMissionTracker` @ `0x0092fd4c`  
(`MOV ECX,[EDI+0x4d0]; MOV EAX,EBX; CALL`).

**Callees:** `FUN_0092a3d0`, `FUN_00929c00`, `CNDHash_LookupByKey` (`0x005b0920`).

## Confidence

| Claim | Level |
|---|---|
| Control flow / size 111 B | **High** |
| Dual-register ABI | **High** |
| Tracker/hash/objective offsets | **High** |
| Sole-caller binder leaf role | **High** |
| Product English | **Open** (`_Inferred`) |
| Runtime Confirmed | **Open** |

## Gaps

- Product tracker class / objective-head English.
- Residual duals for clear helpers `0092a3d0` / `00929c00`.
- Runtime / bit-exact / differential.
