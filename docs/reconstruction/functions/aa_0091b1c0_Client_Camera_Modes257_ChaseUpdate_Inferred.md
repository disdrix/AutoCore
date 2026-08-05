# Function record: Client_Camera_Modes257_ChaseUpdate_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0091b1c0` |
| **Canonical name** | `Client_Camera_Modes257_ChaseUpdate_Inferred` |
| **Ghidra name** | `FUN_0091b1c0` |
| **Address** | `0x0091b1c0` |
| **Body span** | `0091b1c0`–`0091b8c6` (**1798** B / `0x706`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client camera / modes 2·5·7 chase update |
| **Convention** | MSVC stdcall `RET 0x14` + **EDI = cam*** |
| **Completion status** | **partial** — three-rep + dual A/B sealed 2026-07-29; runtime/diff open |
| **Dual verdict** | **accept-with-gaps** (A+B) |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

| Name | Status |
|------|--------|
| `FUN_0091b1c0` | Ghidra auto / scaffold |
| `Client_Camera_Modes257_ChaseUpdate_Inferred` | **Canonical** (this dual) |
| `Named_VOG_DEBUG_STOP_0091b1c0` | **Rejected** — string is error-path only |

## Purpose

Chase/orbit camera update for dispatcher modes **2, 5, and 7**. Stores focus on the camera object, derives horizontal forward from player/vehicle quaternion (×2.0), optionally integrates look-yaw from forward·look dot, places the eye using `cos/sin(cam.yaw)` and range args, performs a **single vertical** map segment distance probe (`Client_Map_RaySegmentHitDistance_Inferred`), then normalizes look and commits the render camera.

Sole caller is `Client_Camera_ModeDispatchUpdate_Inferred` (`FUN_0091ce80`) on the 2/5/7 switch arms.

## Signature

```c
// stdcall RET 0x14; EDI = cam* (caller-set)
void Client_Camera_Modes257_ChaseUpdate_Inferred(
    float focus_x,
    float focus_y,
    float focus_z,
    float range_a,
    float range_b);
```

## Algorithm (summary)

```
FUN_00917cd0 prep
cache focus → cam+0xd04/08/0c; cam+0xd00=0
forward = quatToHorizAxis(client_or_vehicle) * 2.0
normalize forward & look-bus horizontals
look_dot = forward · look; range_b *= sin(yaw)
optional: cam+0x538 +=± |look_dot|*12*3.5
eye = focus + cos(yaw)*range_a*basis + (0, range_b', 0)
d = MapRaySegmentHitDistance(focus, focus+(0,5,0), focus)
if d > 0.2: residual pull on eye
normalize look; FUN_00915da0; render commit FUN_0099b8b0
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0091b1c0_FUN_0091b1c0.md`
- Annotated: `docs/reconstruction/raw/aa_0091b1c0_FUN_0091b1c0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_0091b1c0.cpp`
- Named: `docs/reconstruction/reconstructed-exact/Client_Camera_Modes257_ChaseUpdate_Inferred.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_0091b1c0_FUN_0091b1c0.md`
- Review A: `docs/reconstruction/reviews/A_aa_0091b1c0_Client_Camera_Modes257_ChaseUpdate_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_0091b1c0_Client_Camera_Modes257_ChaseUpdate_Inferred.md`
- Report: `docs/agents/task-dual-ab-0091b1c0-0091ce80-w25b-report.md`
- Collision helper dual: `aa_00916090_Client_Map_RaySegmentHitDistance_Inferred` (W23-O)
- Dispatcher dual: `aa_0091ce80_Client_Camera_ModeDispatchUpdate_Inferred` (this wave)

## Callers / callees

| Dir | VA | Name |
|---|---|---|
| Caller | `0x0091ce80` | `Client_Camera_ModeDispatchUpdate_Inferred` @ `0x0091d048` |
| Callee | `0x00916090` | `Client_Map_RaySegmentHitDistance_Inferred` |
| Callee | `0x00917cd0` | prep/basis |
| Callee | `0x00915da0` | post-focus |
| Callee | `0x0090e1b0` | look helper |
| Callee | `0x0076f5f0` | float3 normalize |
| Callee | `0x0040cf90` | eye post |
| Callee | `0x0099b8b0` | render commit |
| Callee | `0x007a4480` | VOG_DEBUG_STOP path |

## Confidence

| Claim | Level |
|---|---|
| Body span + `ret 0x14` | **Confirmed** |
| EDI = cam* (call-site) | **Confirmed** |
| Modes 2/5/7 only | **High** |
| Single vertical probe via dualed `00916090` | **Confirmed** |
| Eye bus `DAT_00d17944+0x228..` | **High** |
| Product method name | Tentative |
| Wheel-scan head loop purpose | Open |
| Runtime / bit-exact | Open |
