# Function record: MissionTracker_RefreshTrackedTargets_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0092bf60` |
| **Canonical name** | `MissionTracker_RefreshTrackedTargets_Inferred` |
| **Address** | `0x0092bf60` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer partition (parent `0x0092adf0`); MissionTracker role |
| **Completion status** | **Dual A/B complete** (R11-040 2026-08-05) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (static seal only) |

## Alias

- Ghidra: `FUN_0092bf60`
- FUN record: `aa_0092bf60_FUN_0092bf60.md`

## Purpose

On MissionTracker dirty refresh (sole caller `FUN_0092c640` after bind `FUN_0092c080`):

1. Clear owned pointer vector at `host+0x11c` via dualed `Tracker_ClearOwnedPtrVectorAt11c_Inferred`.
2. Reload poll timer `host+0x14 = 4.0f` (`DAT_00aaa690`).
3. Gate on character present, not busy (`+0x4F1`), and world list (`client+0xD34`).
4. Origin from character vtbl `+0x1A0`.
5. Primary: `FUN_0092af80` multi-list filter (includes parent `TargetFilter_FindNearestWorldObjByCbidList_Inferred` / locker FindItemByCoid gate) with bestDist seed **1e9f**.
6. On hit: optional clone-type gate for flag `+0xB` (`0x12` / `0x0E`); `FUN_0092a440` node; copy **TFID_16** from `obj+0x160`.
7. Else secondary `FUN_0092b2a0(host, origin)`; on fail clear `host+0x8` and return 0.

## Signature

```c
// EAX = MissionTracker* host
// returns AL bool
// no stack args; ADD ESP,8; RET
uint8_t MissionTracker_RefreshTrackedTargets_Inferred(void* host /*EAX*/);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0092bf60_FUN_0092bf60.md`
- Annotated: `docs/reconstruction/raw/aa_0092bf60_FUN_0092bf60.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/MissionTracker_RefreshTrackedTargets_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_0092bf60.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_0092bf60_MissionTracker_RefreshTrackedTargets_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0092bf60_MissionTracker_RefreshTrackedTargets_Inferred.md`
- Report: `docs/agents/task-dual-ab-0092bf60-r11-report.md`

## Callers / callees

| Direction | Addr | Name |
|---|---|---|
| Caller (1) | `0x0092c640` @ `0x0092c67c` | timer/dirty tick |
| Callee | `0x0092a3d0` | `Tracker_ClearOwnedPtrVectorAt11c_Inferred` |
| Callee | vtbl `+0x1A0` | character origin |
| Callee | `0x0092af80` | multi-list target dispatcher |
| Callee | `0x0092a440` | node alloc/bind |
| Callee | `0x0092b2a0` | secondary fill |

## Confidence

| Claim | Level |
|---|---|
| Body + ABI + sole caller | **High / Sealed** |
| Timer 4.0f + bestDist 1e9f | **High / Sealed** |
| Primary bind + TFID_16 | **High / Sealed** (bytes) |
| Secondary arm | **High / Sealed** |
| Product English | **Tentative** (`_Inferred`) |
| Runtime / bit-exact | **Open** |
