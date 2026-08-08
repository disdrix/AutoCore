# Function record: Tracker_ClearOwnedPtrVectorAt11c_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0092a3d0` |
| **Canonical name** | `Tracker_ClearOwnedPtrVectorAt11c_Inferred` |
| **Ghidra name** | `FUN_0092a3d0` |
| **Address** | `0x0092a3d0`–`0x0092a43d` (**110 B** / `0x6E`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Partition** | MEGA-088 (parent context `0x0092a590` Tracker_SetActiveMissionObjective) |
| **Completion status** | **Dual sealed** — Path A/B **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (Terminal **false**) |

## Purpose

Clear the owned pointer vector at MissionTracker `+0x11c`:

1. For each element from begin to end: `operator_delete(*p)` (scalar, cdecl).
2. If buffer non-null and non-empty: MSVC-style clear via `memmove(begin, end, 0)` then store `end = begin`.
3. Return `1` in `AL`.

Does **not** free the vector buffer (sibling `FUN_0092a600` free+zeros `+0x11c/120/124`). Does **not** free the tracker host.

## Signature

```c
// Custom: EDI = MissionTracker*; stack none; AL = 1; RET
uint8_t Tracker_ClearOwnedPtrVectorAt11c_Inferred(void* tracker /*EDI*/);
```

## Layout

| Offset | Field |
|---|---|
| `+0x11c` | `T** begin` |
| `+0x120` | `T** end` (written) |
| `+0x124` | capacity end (sibling only) |

## Call graph (evidence)

```text
FUN_0092a590  Tracker_SetActiveMissionObjective   [MEGA-010 partition]
  ├─ MOV EDI,ECX
  ├─ CALL FUN_0092a3d0   @ 0092a5a1  (missionId==0 clear)
  └─ CALL FUN_0092a3d0   @ 0092a5e8  (hash miss clear)

FUN_0092a600  vector destroy sibling
  ├─ MOV EDI,[ESP+arg]
  ├─ CALL FUN_0092a3d0   @ 0092a621
  └─ operator_delete(begin); zero +0x11c/120/124

FUN_0092bf60 / FUN_0092c080  tracker refresh/bind
  └─ CALL FUN_0092a3d0   (EDI = tracker)
```

## Artifacts

| Kind | Path |
|---|---|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0092a3d0_FUN_0092a3d0.md` |
| Annotated | `docs/reconstruction/raw/aa_0092a3d0_FUN_0092a3d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Tracker_ClearOwnedPtrVectorAt11c_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0092a3d0.cpp` |
| Scaffold retired | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_MissionDial_0092a3d0.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_0092a3d0_Tracker_ClearOwnedPtrVectorAt11c_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0092a3d0_Tracker_ClearOwnedPtrVectorAt11c_Inferred.md` |
| Report | `docs/agents/task-dual-ab-0092a3d0-mega-088-report.md` |

## Gaps

1. Product English for element type `T*`.
2. Product field name at `+0x11c`.
3. Runtime / bit-exact / differential.

## Confidence

| Claim | Level |
|---|---|
| CF loop + clear from bytes | **High** |
| ABI EDI / AL=1 / RET | **High** |
| Vector layout +0x11c/120 | **High** |
| Tracker host role via callers | **High** |
| Product type of elements | **Low** |
