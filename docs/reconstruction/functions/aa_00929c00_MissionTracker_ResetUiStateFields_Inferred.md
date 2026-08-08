# Function record: MissionTracker_ResetUiStateFields_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00929c00` |
| **Canonical name** | `MissionTracker_ResetUiStateFields_Inferred` |
| **Ghidra name** | `FUN_00929c00` |
| **Address** | `0x00929c00`–`0x00929c50` inclusive (**81 B** / `0x51`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression / mission-tracker UI state |
| **Partition** | MEGA-087 residual — Tracker UI/state companion |
| **Completion status** | **Dual A/B sealed 2026-08-05 (MEGA-087)** — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Terminal** | **false** (no runtime Confirmed) |

## Alias

| Name | Status |
|---|---|
| `FUN_00929c00` | Ghidra |
| `MissionTracker_ResetUiStateFields_Inferred` | **Canonical** (this record) |
| `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_MissionDial_00929c00` | **Retired** |

## Purpose

Reset mission-tracker **derived UI/state fields** to defaults:

- Id / waypoint slots `+0x18`, `+0x20`, `+0x24`, `+0x108`, `+0x10c` → `-1`
- Flag / aux dwords `+0x54`, `+0x80`, `+0xac`, `+0x28` → `0`
- Flag bytes `+0x100..+0x102` → `0`
- Range float `+0x104` → **25.0f** (`DAT_00aaa6fc`)

Always returns success (`1`). Leaf companion used when clearing active mission or when tracker region context changes.

## Signature

```c
// Custom: object in EAX (not ECX thiscall). Bare RET. AL = 1.
uint8_t MissionTracker_ResetUiStateFields_Inferred(void *tracker /*EAX*/);
```

## Artifacts

| Kind | Path |
|---|---|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00929c00_FUN_00929c00.md` |
| Annotated | `docs/reconstruction/raw/aa_00929c00_FUN_00929c00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/MissionTracker_ResetUiStateFields_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00929c00.cpp` |
| FUN record | `docs/reconstruction/functions/aa_00929c00_FUN_00929c00.md` |
| Review A | `docs/reconstruction/reviews/A_aa_00929c00_MissionTracker_ResetUiStateFields_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00929c00_MissionTracker_ResetUiStateFields_Inferred.md` |
| Report | `docs/agents/task-dual-ab-00929c00-mega-087-report.md` |

## Callers / callees

| Kind | Detail |
|---|---|
| Callers | `FUN_0092a590` ×2; `FUN_0092c080` ×1 |
| Callees | none |
| Related dualed | `Client_TryBindActiveMissionTracker` `0x0092fd00`; `Client_MissionTrackerHud_Refresh_Inferred` `0x008a8770` |

## Confidence

| Claim | Level |
|---|---|
| CF / body / ABI / float constant | **Confirmed** |
| Tracker object family (client+0x4d0) | **High** |
| Product field English | **Inferred** |
| RTTI class name | **Open** |
