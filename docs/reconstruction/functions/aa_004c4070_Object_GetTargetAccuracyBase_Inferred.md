# Function record: Object_GetTargetAccuracyBase_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c4070` |
| **Canonical name** | `Object_GetTargetAccuracyBase_Inferred` |
| **Ghidra name** | `FUN_004c4070` |
| **Address** | `0x004c4070` |
| **Body range** | `0x004c4070`–`0x004c413d` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | combat / accuracy stats |
| **Completion status** | **partial** — dual A/B **accept**; clamp + thr bytes sealed; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_004c4070_Object_GetTargetAccuracyBase_Inferred.md`, `reviews/B_aa_004c4070_Object_GetTargetAccuracyBase_Inferred.md` (2026-07-29 W17-O) |
| **Last reviewed** | `2026-07-29` |

## Purpose

Return capped accuracy-base integer used as the raw input for TargetAccuracy display and related combat paths:

```
score = min(min(*(i16*)(this+0x13e), 200) + *(i16*)(this+0x146), 250)
thr   = (MI_vtbl_call(this, +0x1DC) != 0) ? 1 : -100
return max(score, thr)
```

Does **not** apply the DebugDump level-band float formula (that is outside this unit).

## Signature

```c
int __fastcall Object_GetTargetAccuracyBase_Inferred(void *self);  // this = ECX; ret 0
```

## Layout (this unit)

| Offset | Field | Role |
|---|---|---|
| `+0x13e` | short base stat | min(, 200) primary term |
| `+0x146` | short bonus | additive |
| MI + `vtbl+0x1DC` | vehicle/object probe | nonzero → thr 1 else thr -100 |

## Algorithm

1. `score = clamp(min(base@+0x13e, 200) + bonus@+0x146, upper=250)`.
2. Call adjusted `vtbl+0x1DC` → probe.
3. `thr = (probe != 0) ? 1 : -100`.
4. If `thr < score` return score (asm recomputes clamp); else return thr (second probe call).

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004c4070_FUN_004c4070.md`
- Annotated: `docs/reconstruction/raw/aa_004c4070_FUN_004c4070.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Object_GetTargetAccuracyBase_Inferred.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_004c4070.cpp`
- Parent-seed alias: `Named_CalleeOf_Client_DebugDumpEntityCombatStats_004c4070.cpp` (prefer Object_ name)
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-004c4070-object-gettargetaccuracybase-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | virtual only — MI `vtbl+0x1DC` (no direct FUN_*) |
| **Callers (sample)** | `Client_DebugDumpEntityCombatStats` (`0x00955eb0`), `Skill_NonCreatureCastAutoHit` (`0x004ceba0` — return discarded under high pcode), `FUN_004c4b80`, `FUN_004c8f00`, `FUN_00514390`, `FUN_00568250`, `FUN_00845360`, `FUN_00846820`, `FUN_008d0b70`, `FUN_008f97c0`, `FUN_00933d60` |

## Confidence

| Claim | Level |
|---|---|
| Control flow + clamp constants | **High** |
| Offsets +0x13e / +0x146 | **High** |
| thr encode 1 / -100 | **High** |
| vtbl+0x1DC vehicle probe (object*) | **High** (nonzero test); English name **Inferred** |
| Product field English for +0x13e/+0x146 | Open |
| Runtime / bit-exact | Open |

## Related

- `FUN_004c41c0` — same shape on `+0x142` / `+0x14a`
- `FUN_004c4140` — `+0x140` / `+0x148`, floor 1, no vehicle thr
- `aa_004ceba0` Skill_NonCreatureCastAutoHit (return discarded residual)
- `Client_DebugDumpEntityCombatStats` TargetAccuracy display formula
