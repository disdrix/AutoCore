# Function record: CVOGSectorMap_OnCharacterLeave_DecLevelIndex_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d3310` |
| **Canonical name** | `CVOGSectorMap_OnCharacterLeave_DecLevelIndex_Inferred` |
| **Address** | `0x004d3310` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | sector-map / combat-pool level index |
| **Completion status** | **Dual A/B present** (2026-07-29); accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

- Ghidra: `FUN_004d3310`
- Prior: `Named_CalleeOf_Named_VOGClient_004d3310`
- Scaffold: `functions/aa_004d3310_FUN_004d3310.md`

## Purpose

On sector-map character leave: decrement level/power index `+0xe818`, optionally notify pool rescale via `FUN_004d28c0(old,new)`, decrement race histogram `+0xe81c[def+0x532]`. Sibling `FUN_004d32c0` is the increment twin. Called from CompletelyDestroyObject when sector player-count probe changes.

## Signature

```c
int* __thiscall CVOGSectorMap_OnCharacterLeave_DecLevelIndex_Inferred(
    void *sectorMap, void *leavingObject, char notifyPools);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004d3310_FUN_004d3310.md`
- Annotated: `docs/reconstruction/raw/aa_004d3310_FUN_004d3310.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_004d3310.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_004d3310_CVOGSectorMap_OnCharacterLeave_DecLevelIndex_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_004d3310_CVOGSectorMap_OnCharacterLeave_DecLevelIndex_Inferred.md`

## Callers / callees

- Callers: `FUN_009440e0` (CompletelyDestroyObject)
- Callees: `FUN_004d28c0`

## Confidence

| Claim | Level |
|---|---|
| Control flow | **Confirmed** |
| Level index + race hist role | **High** |
| Product name | **Open** (`_Inferred`) |
