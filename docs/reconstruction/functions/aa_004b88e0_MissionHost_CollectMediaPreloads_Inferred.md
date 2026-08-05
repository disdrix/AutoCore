# Function record: MissionHost_CollectMediaPreloads_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b88e0` |
| **Canonical name** | `MissionHost_CollectMediaPreloads_Inferred` (**Inferred** structural) |
| **Ghidra name** | `FUN_004b88e0` |
| **Address** | `0x004b88e0` |
| **Body** | `0x004b88e0`–`0x004b8db1` exclusive (**1233 B** / `0x4D1`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | mission host: flag-gated media/audio preload path collect + enqueue |
| **Completion status** | **Dual-reviewed** W32-H — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

Given a mission host and three independent boolean flags, walk circular object/resource/audio lists and enqueue path strings into the process preload guarded vector via `FUN_00989e00` + `GuardedVector_PushBack_Thiscall` (`0x0043d670`):

1. **flag_obj_paths (`param_5`):** list `host+0x204` — path at `obj+0x1d0` if flag bit, or name at `obj+0x2be` + `".tk"`.
2. **flag_media_strings (`param_3`):** same object list for long string `+0x33d` and nested records from `+0x3bc`; plus list `host+0x1e0` resource-id → string via `FUN_004a05c0`.
3. **flag_mission_audio (`param_4`):** list `host+0x1ec` — skip type dword `0x50`; `strtok` on `"|"`, run `Client_GetMissionCompleteAudioTable` + `FUN_00722790` per token, then enqueue.

## Signature

```c
// ECX = mission host. RET 0x10. void.
// Stack formal[0] unused in body but cleaned by epilogue.
void __thiscall MissionHost_CollectMediaPreloads_Inferred(
    void* self,
    uint32_t unused_stack,
    char flag_media_strings,
    char flag_mission_audio,
    char flag_obj_paths);
```

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `FUN_004a04f0` @ `0x004a051b` (map/tree walk); `FUN_00556b10` @ `0x00556c95`, `0x00556cce` |
| Callees | `FUN_00989e00`, `GuardedVector_PushBack_Thiscall` (`0x0043d670`, W31-I), `FUN_004a05c0`, `Client_GetMissionCompleteAudioTable`, `FUN_00722790`, `strtok`, `std::string` c_str/dtor |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004b88e0_FUN_004b88e0.md`
- Annotated: `docs/reconstruction/raw/aa_004b88e0_FUN_004b88e0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/MissionHost_CollectMediaPreloads_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_004b88e0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_004b88e0_MissionHost_CollectMediaPreloads_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_004b88e0_MissionHost_CollectMediaPreloads_Inferred.md`
- Scaffold record: `docs/reconstruction/functions/aa_004b88e0_FUN_004b88e0.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow (decompile ≡ live) | **High** |
| ABI ECX + RET 0x10 | **High** |
| Three flag gates independent | **High** |
| List / object / record offsets | **High** |
| `.tk` suffix constant | **High** (`read_memory` `0x009cb318`) |
| Preload vector ECX identity | **Open** |
| Product host/list English | **Low** |

## Rejected plates

- `Mission_Uses_Client_GetMissionCompleteAudioTable_004b88e0` (keyword contamination; only `param_4` path).
