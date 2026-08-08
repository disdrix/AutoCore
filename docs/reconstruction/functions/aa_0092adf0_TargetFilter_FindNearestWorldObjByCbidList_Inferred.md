# Function record: TargetFilter_FindNearestWorldObjByCbidList_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0092adf0` |
| **Canonical name** | `TargetFilter_FindNearestWorldObjByCbidList_Inferred` |
| **Address** | `0x0092adf0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `skills-abilities` / inventory-adjacent |
| **Completion status** | **Dual A/B complete** (WQ8R-I 2026-08-04) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (static seal only) |

## Alias

- Ghidra: `FUN_0092adf0`
- Prior scaffold: `FUN_0092adf0` only

## Purpose

Nearest world-object picker for a target-filter context: CBID whitelist match, exclude local player, require object COID **not** present in character **locker** grid (`*(char+0xCBC)` via `InventoryGrid_FindItemByCoid`). Updates best squared-distance and object pointer.

WQ-008 residual: **skill-adjacent inventory consumer** (FindItemByCoid gate).

## Signature

```c
// EDI = TargetFilterCtx* (*ctx = Client*)
// ret 0x0C; returns 1
uint32_t TargetFilter_FindNearestWorldObjByCbidList_Inferred(
    float *origin, void **bestOut, float *bestDistSq);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0092adf0_FUN_0092adf0.md`
- Annotated: `docs/reconstruction/raw/aa_0092adf0_FUN_0092adf0.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/TargetFilter_FindNearestWorldObjByCbidList_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_0092adf0.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_0092adf0_TargetFilter_FindNearestWorldObjByCbidList_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0092adf0_TargetFilter_FindNearestWorldObjByCbidList_Inferred.md`
- Function FUN alias: `docs/reconstruction/functions/aa_0092adf0_FUN_0092adf0.md`

## Callers / callees

| Direction | Addr | Name |
|---|---|---|
| Caller | `0x0092af80` | multi-list target dispatcher (`ctx+0x28 > 0`) |
| Grandcaller | `0x0092bf60` | character-gated target attempt |
| Callee | `0x004294f0` | TraversalLock |
| Callee | `0x004022a0` | IterateNext |
| Callee | `0x00571010` | `InventoryGrid_FindItemByCoid` |
| Callee | vtbl `+0x144` | object refresh before dist |
| Callee | `LeaveCriticalSection` | list unlock |

## Confidence

| Claim | Level |
|---|---|
| Body + `ret 0x0C` + return 1 | **High / Sealed** |
| EDI ctx / `*ctx` client | **High** |
| CBID list `+0x28/+0x2C` vs clonebase `+0x34` | **High / Sealed** |
| FindItemByCoid on `*(char+0xCBC)` when absent | **High / Sealed** (bytes) |
| Self-exclude via `+0x250` this-adjust vs `+0xAC` | **High** |
| Squared distance nearest update | **High** |
| Product filter-class English | **Tentative** (`_Inferred`) |
| Runtime / bit-exact | **Open** |
