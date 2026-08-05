# Function record: Outpost_CaptureOutpost

| Field | Value |
|---|---|
| **Stable ID** | `aa_006082e0` |
| **Canonical name** | `Outpost_CaptureOutpost` |
| **Former name** | `FUN_006082e0` |
| **Address** | `0x006082e0` |
| **Body range** | `0x006082e0`–`0x00608614` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities / outpost |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF + ABI + string + success chain sealed; many callees/runtime open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_006082e0_Outpost_CaptureOutpost.md`, `reviews/B_aa_006082e0_Outpost_CaptureOutpost.md` |
| **Last reviewed** | `2026-07-29` (W20-D) |

## Alias

- `FUN_006082e0` (Ghidra default)
- `Named_Invalid_faction_CaptureOutpost` (plate-string alias)
- `Named_CalleeOf_CVOGReaction_Dispatch_006082e0` (prior parent-seed; superseded)

## Purpose

Apply **outpost capture** for the capturer's root race/faction: resolve capturer, credit nearby same-race entities within radius, and (when world flag `+0x7e` is set) transfer faction ownership, cast faction skills, recompute beacon-share ratio, and arm capture timer/schedule.

## Signature

```c
void __thiscall Outpost_CaptureOutpost(void *thisOutpost, void *capturerCtx);
// ECX = outpost; stack capturerCtx (nullable); RET 4
```

## Layout (this unit)

| Offset | Field | Role |
|---|---|---|
| `+0x218` | float | capture credit radius |
| `+0x220` | char | schedule bank select |
| `+0x234` | int | current faction (gate + store) |
| `+0x238` | int | schedule entry count (written) |
| `+0x23c` | int | schedule cursor (cleared to 0) |
| `+0x248` | ptr | timer blob (`+8` float, `+0x14` tick) |

## Algorithm

1. Seed `newFaction = 3`; if `capturerCtx` → resolve capturer via vtbl `+0x210`, then `Object_GetRootRaceId`.
2. If old faction in `[0,2]`: `FUN_004cd5f0(old)`.
3. Optional capturer race-byte path `FUN_004cd5d0`.
4. Require `newFaction != old` and `timerBlob != null`.
5. If `newFaction` outside `[0,3]`: log product string; return.
6. Nearby same-race credit within `radius²`.
7. If world `+0x7e`: clear-old helpers → arm-new helpers → `Outpost_CastSkillsForFaction` → store faction → `Outpost_UpdateBeaconShareRatio` → schedule/timer → `FUN_006081b0`.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_006082e0_FUN_006082e0.md`
- Annotated: `docs/reconstruction/raw/aa_006082e0_FUN_006082e0.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/Outpost_CaptureOutpost.cpp`
- Clean FUN_*: `docs/reconstruction/reconstructed-exact/FUN_006082e0.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-own-w20d-00439810-006082e0-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `Object_GetRootRaceId`, `Outpost_CastSkillsForFaction`, `Outpost_UpdateBeaconShareRatio`, log, GetTickCount, + many FUN_* helpers |
| **Callers** | `0x0057c88d` (push capturer; this=EAX); `0x00650752` (push 0; this=EDI) |

## Confidence

| Claim | Level |
|---|---|
| Control flow + body range + ABI | **High** |
| Product string / CaptureOutpost role | **High** |
| Faction store + dualed cast/ratio callees | **High** |
| Nearby radius credit loop geometry | **High** |
| World `+0x7e` gate | **High** |
| Unresolved helper semantics | **Tentative / Medium** |
| Product method English | **Inferred** from string (`Outpost_CaptureOutpost`) |

## Related

- `aa_00606d70` Outpost_CastSkillsForFaction
- `aa_006078e0` Outpost_UpdateBeaconShareRatio
- `aa_006070e0` Outpost_CastSkillsForBeaconShare
- `aa_00512440` Object_GetRootRaceId
