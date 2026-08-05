# Function record: Client_FindFirstObjectInRadius

| Field | Value |
|---|---|
| **Stable ID** | `aa_009197a0` |
| **Canonical name** | `Client_FindFirstObjectInRadius` (INFERRED) |
| **Address** | `0x009197a0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `interaction-activation` |
| **Completion status** | **Partial** — dual A/B sealed 2026-07-29; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (not run) |

## Alias

| Name | Notes |
|---|---|
| `FUN_009197a0` | Ghidra default |
| `Named_VOG_DEBUG_STOP_009197a0` | **Deprecated** — TraversalLock assert string only |
| “nearest-object radius helper (15f)” | Task nickname; **not** min-distance nearest |

## Purpose

Return the first world object within `radius` of the local player:

1. Prefer in-range **auto-patrol waypoint** object (`DAT_00d1ad10` + `Client_EvalAutoPatrolWaypoint`).
2. Else walk VOG object hash under TraversalLock; first resolve with dist² **&lt;** radius² wins.

All three production callers pass **15.0f** (`0x41700000`).

## Signature

```c
// __stdcall, RET 4
void * Client_FindFirstObjectInRadius(float radius);
```

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_009197a0_FUN_009197a0.md` |
| Annotated | `docs/reconstruction/raw/aa_009197a0_FUN_009197a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_FindFirstObjectInRadius.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_009197a0_Client_FindFirstObjectInRadius.md` |
| Review B | `docs/reconstruction/reviews/B_aa_009197a0_Client_FindFirstObjectInRadius.md` |
| Agent report | `docs/agents/task-dual-ab-009197a0-find-first-object-in-radius-report.md` |
| Scratch | `tmp/a_009197a0.md` |

Legacy scaffold (superseded name): `docs/reconstruction/functions/aa_009197a0_FUN_009197a0.md`, `reconstructed-exact/FUN_009197a0.cpp`.

## Callers

| VA (CALL) | Parent |
|---|---|
| `0x00927b2f` | `Client_Input_PollBoundActions` (`0x00925d60`) |
| `0x0081002e` | `Client_RecvCompleteDynamicObjective` (`0x0080ff00`) |
| `0x0092133d` | `FUN_009210e0` (`0x009210e0`) |

## Callees

| VA | Name |
|---|---|
| `0x00929ec0` | `Client_EvalAutoPatrolWaypoint` |
| `0x004e88e0` | `FUN_004e88e0` (xyz float3 copy) |
| `0x004bb950` | `Object_ResolveFromTFID` |
| `0x007a4480` | `FUN_007a4480` (log / VOG_DEBUG_STOP) |

## Key layouts

| Symbol | Role |
|---|---|
| `DAT_00d1b6d8` | Local character; adj + vtbl`+0x1a0` → player float4 pos |
| `DAT_00d1ad10` | Auto-patrol manager; vector `+0x11c`/`+0x120` |
| `DAT_00d1b644 + 0xe8f4` | VOG hash root; lock `+0x1d`; head `+0x14` |
| Hash node `+0xc` / `+0x20` | TFID*; next |
| Object `+0x80/84/88` | World position XYZ |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler + call-site asm | **High** |
| 15.0f at all callers | **High** |
| First-in-radius (not min-distance) | **High** |
| Parameter / return types | **High** (static) |
| Predicate field / PDB name | **Tentative / Open** |
