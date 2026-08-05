# Function record: Client_EvalAutoPatrolWaypoint (scaffold slug: identity)

| Field | Value |
|---|---|
| **Stable ID** | `aa_00929ec0` |
| **Canonical name** | `Client_EvalAutoPatrolWaypoint` |
| **Scaffold alias** | `identity` (**not** CRT identity — mis-slug) |
| **Address** | `0x00929ec0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression / client AutoPatrol |
| **Completion status** | **Dual A/B accept** (2026-07-29) — game CF + C2S 0x20B3 sealed; not CRT |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Evaluate mission patrol waypoint by index: resolve object, refresh cached XYZ, write out TFID + position, optionally send **C2S AutoPatrol `0x20B3`** (size `0x18`) when AutoPatrol is enabled and player is in range.

## Signature (sealed)

```c
// EAX = waypointIndex (register formal)
// stack: patrolManager*, outWaypointTfid[16], outPosition[3]
void __cdecl Client_EvalAutoPatrolWaypoint(void *patrolManager, void *outWaypointTfid, float *outPosition);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00929ec0_identity.md`
- Annotated: `docs/reconstruction/raw/aa_00929ec0_identity.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/identity.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00929ec0_Client_EvalAutoPatrolWaypoint.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00929ec0_Client_EvalAutoPatrolWaypoint.md`

## Callers / callees

| Callers | Callees |
|---|---|
| `Client_FindFirstObjectInRadius` / `FUN_009197a0`, `FUN_00919ae0`, `FUN_00851630`, `FUN_00859bc0`, `FUN_008a8770` | `Object_ResolveFromTFID` `0x004bb950`, `Client_SendSectorPacket` `0x00807460` |

## Confidence

| Claim | Level |
|---|---|
| Real game code (not CRT) | **Confirmed** |
| Control flow + 0x20B3 path | **High** (dual sealed) |
| EAX waypoint index formal | **Confirmed** |
| Manager layout flags/vector | **High** / Probable product names |
| Parameter semantic names | High (mgr/outTfid/outPos) |
