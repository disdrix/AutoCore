# Function record: TargetFilter_DispatchMatchArms_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0092af80` |
| **Canonical name** | `TargetFilter_DispatchMatchArms_Inferred` |
| **Ghidra name** | `FUN_0092af80` |
| **Address** | `0x0092af80` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer |
| **Dual** | R11-039 2026-08-05 — **accept-with-gaps** |
| **Parent dual (partition)** | `0x0092adf0` `TargetFilter_FindNearestWorldObjByCbidList_Inferred` |

## Purpose

Run all eligible target-filter context match arms in order, writing the best/direct object into `*bestOut` (and squared distance for nearest arms). Return whether any arm executed.

## Signature

```c
// EAX = TargetFilterCtx*, ESI = Object **bestOut, ret 8
bool TargetFilter_DispatchMatchArms_Inferred(float *origin, float *bestDistSq);
```

## Arms (order)

1. Direct COID `@+0x20/+0x24` → `CVOGReaction_ResolveObjectTarget`
2. CBID list `@+0x28` → dualed `TargetFilter_FindNearestWorldObjByCbidList_Inferred`
3. Residual `@+0x80` → `FUN_0092abc0`
4. Residual `@+0x54` → `FUN_0092a980`
5. Residual `@+0xAC` → `FUN_0092a760` else `FUN_00929cd0`

## Artifacts

See `aa_0092af80_FUN_0092af80.md` for full path table.

## Confidence

High on CF/ABI/role; product English open; residual arm duals open; runtime open.
