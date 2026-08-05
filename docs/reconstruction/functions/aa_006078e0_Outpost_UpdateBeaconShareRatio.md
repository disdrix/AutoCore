# Function record: Outpost_UpdateBeaconShareRatio

| Field | Value |
|---|---|
| **Stable ID** | `aa_006078e0` |
| **Canonical name** | `Outpost_UpdateBeaconShareRatio` |
| **Former name** | `FUN_006078e0` |
| **Address** | `0x006078e0` |
| **Body range** | `0x006078e0`–`0x006079e2` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `skills-abilities` / outpost |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF + bytes + string sealed; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_006078e0_Outpost_UpdateBeaconShareRatio.md`, `reviews/B_aa_006078e0_Outpost_UpdateBeaconShareRatio.md` |
| **Last reviewed** | `2026-07-29` (W19-O) |

## Purpose

Recompute outpost **beacon-share ratio** `factionBeacons / totalBeacons` into `this+0x24c`. On total ≤ 0, log `"Total beacons was %f on map %s"` and leave ratio unchanged. When ratio **changes**, call `FUN_00606ff0(faction)` then `Outpost_CastSkillsForBeaconShare(faction)`.

## Signature

```c
void __thiscall Outpost_UpdateBeaconShareRatio(void *thisOutpost);  // ECX=this; ret 0
```

## Layout (this unit)

| Offset | Field | Role |
|---|---|---|
| `+0x1d0` | map-var id | total beacons (`CVOGMap_LookupVariable`) |
| `+0x234` | faction index | selects per-faction var + cast bank |
| `+0xf0 + faction*0x48` | map-var id | faction beacon count |
| `+0x24c` | `float` ratio | written here; gate for BeaconShare cast |

## Algorithm

1. `total = Lookup(+0x1d0)` seeded `g_flOne`; `factionB = Lookup(+0xf0+faction*0x48)` seeded 0.
2. If `total <= 0`: log; return (no store).
3. `ratio = factionB / total`; store `+0x24c`.
4. If ratio ≠ old: `FUN_00606ff0(faction)`; `Outpost_CastSkillsForBeaconShare(faction)`.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_006078e0_FUN_006078e0.md`
- Annotated: `docs/reconstruction/raw/aa_006078e0_FUN_006078e0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Outpost_UpdateBeaconShareRatio.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_006078e0.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-own-w19o-006078e0-00507290-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `CVOGMap_LookupVariable` `0x005b05f0`, `FUN_00606ff0`, `Outpost_CastSkillsForBeaconShare` `0x006070e0`, `FUN_007a4480` |
| **Callers** | `FUN_006082e0` (CaptureOutpost); MI thunk `0x006079f0` (`add ecx,-0x260`) |

## Confidence

| Claim | Level |
|---|---|
| Control flow + bytes | **High** |
| Ratio math + store `+0x24c` | **High** |
| String + total≤0 log | **High** |
| Change → 00606ff0 + BeaconShare cast | **High** |
| Map-var English (total/faction beacons) | **High** (string + math); product field names residual |
| Product method English | **Inferred** (`Outpost_UpdateBeaconShareRatio`) |

## Related

- `aa_006070e0` Outpost_CastSkillsForBeaconShare
- `aa_00606d70` Outpost_CastSkillsForFaction
- `FUN_00606ff0` pre-recast bank walk (not dual-owned this wave)
- `FUN_006082e0` CaptureOutpost path
