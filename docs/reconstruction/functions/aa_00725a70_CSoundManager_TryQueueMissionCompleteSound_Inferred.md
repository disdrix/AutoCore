# Function record: CSoundManager_TryQueueMissionCompleteSound_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00725a70` |
| **Canonical name** | `CSoundManager_TryQueueMissionCompleteSound_Inferred` |
| **Ghidra name** | `FUN_00725a70` |
| **Address** | `0x00725a70` |
| **Body range** | `0x00725a70`–`0x00725bcd` (349 bytes) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client audio / `CSoundManager` / mission-complete SFX |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF + constants sealed; runtime open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_00725a70_CSoundManager_TryQueueMissionCompleteSound_Inferred.md`, `reviews/B_aa_00725a70_CSoundManager_TryQueueMissionCompleteSound_Inferred.md` (2026-07-29 W18-R) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_00725a70`
- `Named_CalleeOf_Mission_Uses_Client_GetMissionCompleteAudioTable_00725a70` (parent-seed; prefer canonical)

## Purpose

Queue a mission-complete (type `0x32`) sound slot on `CSoundManager` when enabled and the world position is zero or within fixed XZ radius (dist² ≤ 10000).

## Signature

```c
uint32_t __thiscall CSoundManager_TryQueueMissionCompleteSound_Inferred(
    CSoundManager *this, void *path_or_key, float *world_pos3);  // ret 8; 1/0
```

## Algorithm

1. Enable gate `this+0x258`.
2. Fixed proximity gate (XZ, 10000 dist²) with zero-pos pass.
3. `ResolveSoundPath` → freelist pop → tail init → strncpy.
4. Hardcode type/TFID/params; push list at `this+0x310`.
5. Return 1.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00725a70_FUN_00725a70.md`
- Annotated: `docs/reconstruction/raw/aa_00725a70_FUN_00725a70.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CSoundManager_TryQueueMissionCompleteSound_Inferred.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_00725a70.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-00725a70-00521310-w18r-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FUN_007249c0`, `FUN_00480460`, `FUN_00480170`, `strncpy`, `FUN_00480350`, SQRT/ABS |
| **Callers** | `FUN_004b0f80` @ `0x004b1056` |

## Confidence

| Claim | Level |
|---|---|
| Control flow + gates | **High** |
| Fixed 10000 / type 0x32 / floats | **High** |
| Mission-complete role | **High** (caller) |
| Product English name | **Inferred** |
| Runtime / bit-exact | Open |

## Related

- `aa_007258a0` CSoundManager_TryQueueProximitySound_Inferred
- `aa_007249c0` CSoundManager_ResolveSoundPath_Inferred
- `aa_00480460` AlignedFreelist_PopSlot_0x160_Inferred
- `aa_00480170` SoundQueueSlot_InitTailFields_Inferred
- `aa_00480350` StdList_PushPayloadNode_Inferred
