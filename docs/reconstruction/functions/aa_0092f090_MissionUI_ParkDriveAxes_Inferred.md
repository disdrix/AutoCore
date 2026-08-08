# Function record: MissionUI_ParkDriveAxes_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0092f090` |
| **Canonical name** | `MissionUI_ParkDriveAxes_Inferred` |
| **Ghidra name** | `FUN_0092f090` |
| **Address** | `0x0092f090`–`0x0092f0d1` (**66 B** / `0x42`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `input-drive-control` |
| **Partition** | MEGA-021 — Mission-UI axis park thr0/steer0/HB1 (parent `0x009438f0`) |
| **Completion status** | **Dual sealed** (A/B **accept-with-gaps**) |
| **Bit-for-bit / runtime / diff** | Open |
| **Terminal** | **false** |

## Naming rationale

| Evidence | Weight |
|---|---|
| Body forces thr=0, steer=0, HB=1 via dualed vehicle setters | High |
| Callers are mission dialog UI (`Client_ShowNpcMissionDialogUI`) and dialog-case dispatcher `FUN_0093e450` | High |
| Partition map hint: **Mission-UI axis park thr0/steer0/HB1** | Medium |
| Peer axis-park family (AI/dialog) uses same setter trio pattern | Medium |
| No product symbol inside body → **`_Inferred`** suffix | Required |

Retired: `Named_CalleeOf_Client_ShowNpcMissionDialogUI_0092f090`.

## Purpose

Park player drive axes for mission / NPC dialog UI:

1. Gate on non-null `client+0xe98` (character) and `character+0x250` (vehicle entity).
2. `VehicleEntity_SetLongitudinalInput(vehicle, 0)`.
3. `VehicleEntity_SetSteerInput(vehicle, 0)`.
4. `VehicleEntity_SetHandbrake(vehicle, 1)`.

Does **not** call `PushDriveAxes`. Does **not** free UI or open dialogs.

## Signature

```c
// Retail ABI: ESI = client host*; void; bare RET
void MissionUI_ParkDriveAxes_Inferred(void);
```

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0092f090_FUN_0092f090.md` |
| Annotated | `docs/reconstruction/raw/aa_0092f090_FUN_0092f090.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/MissionUI_ParkDriveAxes_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0092f090.cpp` |
| FUN record | `docs/reconstruction/functions/aa_0092f090_FUN_0092f090.md` |
| Review A | `docs/reconstruction/reviews/A_aa_0092f090_MissionUI_ParkDriveAxes_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0092f090_MissionUI_ParkDriveAxes_Inferred.md` |
| Report | `docs/agents/task-dual-ab-0092f090-mega-021-report.md` |

## Callers / callees

| Direction | Value |
|---|---|
| Callers | `Client_ShowNpcMissionDialogUI` ×2; `FUN_0093e450` ×3 |
| Callees | dualed SetLongitudinalInput / SetSteerInput / SetHandbrake |

## Gaps

- Product English for ESI host class.
- Product English for residual parent `FUN_0093e450`.
- 0xC7 suppress interaction on thr/steer during park.
- Runtime / differential.

## Confidence

| Claim | Level |
|---|---|
| CF / ABI / offsets | **High** |
| Mission-UI park role | **High** |
| Product type names | **Low** |
