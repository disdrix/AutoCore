# Function record: CVOGWaypoint_DoFollowObjectShortcutsUpdate

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d5cc0` |
| **Canonical name** | `CVOGWaypoint_DoFollowObjectShortcutsUpdate` |
| **Ghidra name** | `FUN_005d5cc0` |
| **Address** | `0x005d5cc0` |
| **Body range** | `0x005d5cc0`–`0x005d62fb` (**1596 B** / `0x63C`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities / waypoint path AI |
| **Completion status** | **Dual-reviewed MEGA-057** — A/B **accept-with-gaps**; product plate sealed |
| **Bit-for-bit / runtime / diff** | Open; Terminal **false** |
| **Dual A/B** | `reviews/A_aa_005d5cc0_CVOGWaypoint_DoFollowObjectShortcutsUpdate.md`, `reviews/B_aa_005d5cc0_CVOGWaypoint_DoFollowObjectShortcutsUpdate.md` |
| **Last reviewed** | `2026-08-05` (MEGA-057) |

## Alias

- `FUN_005d5cc0` (Ghidra / twin clean)
- Retired: `Named_CalleeOf_CVOGWaypoint_UpdateState_005d5cc0` (parent-seed scaffold)

## Purpose

`CVOGWaypoint` FSM **state-2** handler (dispatched from `CVOGWaypoint_UpdateState` when `*(this+0x50)==2`):

1. Resolve follow-object TFID at `this+0x30`; gate on object flag `+0x17c` bit5 → set `+0x52`.
2. Cast to `CVOGPhysicsBase`; load target + owner poses (rb/`+0x84` dual).
3. Surface distance owner↔target; set in-range flag `+0x53` vs patrol float `+0x4c`.
4. If dist &lt; 1.0: snap desired pose `+0x20..+0x2c` to target.
5. If path COID pair valid: run state-1 peer `FUN_005d5960`; clear path if direction-dot &lt; 0.2.
6. Else gather shortcut candidates (`FUN_004d5910`), pick nearest in range, store COID `+0x40/44` (from `obj+0x134`), optional secondary `+0x48`, write pose via vtbl.

Product plate: **`CVOGWaypoint::DoFollowObjectShortcutsUpdate`**.

## Signature

```c
// Machine: __thiscall, ECX = CVOGWaypoint*, no stack args, void, RET 0
// SEH: LAB_009a7110; scope FUN_0076cf00 / FUN_0076cef0
void __thiscall CVOGWaypoint_DoFollowObjectShortcutsUpdate(CVOGWaypoint *this);
```

## Offsets (sealed)

| Offset | Role | Conf |
|---|---|---|
| `+0x10` | owner entity* | **High** |
| `+0x20..+0x2c` | desired pose float4 out | **High** |
| `+0x30` | follow-object TFID | **High** |
| `+0x40/+0x44` | path/shortcut COID lo/hi | **High** |
| `+0x48` | secondary path id | **High** |
| `+0x4c` | patrol/follow range float | **High** |
| `+0x50` | FSM state (caller; case 2 → this) | **High** |
| `+0x52` | follow valid flag | **High** |
| `+0x53` | within-patrol flag | **High** |

## Constants

| Symbol | VA | Value |
|---|---|---|
| `g_flOne` | `0x00a0f2a0` | `1.0f` |
| `DAT_00a0f70c` | `0x00a0f70c` | `0.2f` |
| `_DAT_009dace0` | `0x009dace0` | `1e7f` |
| plate string | `0x009dace4` | `CVOGWaypoint::DoFollowObjectShortcutsUpdate` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005d5cc0_FUN_005d5cc0.md`
- Annotated: `docs/reconstruction/raw/aa_005d5cc0_FUN_005d5cc0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGWaypoint_DoFollowObjectShortcutsUpdate.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_005d5cc0.cpp`
- FUN record: `docs/reconstruction/functions/aa_005d5cc0_FUN_005d5cc0.md`
- Report: `docs/agents/task-dual-ab-005d5cc0-mega-057-report.md`

## Callers / callees

- **Callers (1):** `CVOGWaypoint_UpdateState` @ `0x005d6300` / site `0x005d6353`.
- **Callees:** `Object_ResolveFromTFID`, `__RTDynamicCast`, `Object_GetWorldPositionPtr`, `Object_SurfaceDistance3D_Inferred`, `FUN_005d5960`, `FUN_004d5910`, `operator_delete`, scope pair, virtuals `+0x10`/`+0x2c`.

## Confidence

| Claim | Level |
|---|---|
| Product plate name | **High** |
| CF + ABI | **High** |
| Field map used here | **High** |
| Residual `FUN_004d5910` / `FUN_005d5960` English | **Open** |
| Candidate class English | **Open** |
| Runtime Confirmed | **Open** |
