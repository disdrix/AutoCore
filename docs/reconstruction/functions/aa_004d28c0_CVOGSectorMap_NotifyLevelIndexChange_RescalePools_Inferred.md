# Function record: CVOGSectorMap_NotifyLevelIndexChange_RescalePools_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d28c0` |
| **Canonical name** | `CVOGSectorMap_NotifyLevelIndexChange_RescalePools_Inferred` |
| **Address** | `0x004d28c0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | sector-map / vehicle-combat-pools |
| **Completion status** | **Dual A/B present** (2026-07-29); accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

- Ghidra: `FUN_004d28c0`
- Prior: `Named_CalleeOf_Named_CalleeOf_Client_RecvCreateCharacter_004d28c0`

## Purpose

On level-index transition: gate, clamp levels to ≤0xF, lock, walk object vector at `this+0xe4e8`, call `Object_ScaleCombatPoolsByLevelTable_Inferred` for each. Sole callers: enter/leave index twins `004d32c0` / `004d3310`.

## Signature

```c
void __thiscall CVOGSectorMap_NotifyLevelIndexChange_RescalePools_Inferred(
    void *sectorMap, int oldLevel, int newLevel);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004d28c0_FUN_004d28c0.md`
- Annotated: `docs/reconstruction/raw/aa_004d28c0_FUN_004d28c0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_004d28c0.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_004d28c0_CVOGSectorMap_NotifyLevelIndexChange_RescalePools_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_004d28c0_CVOGSectorMap_NotifyLevelIndexChange_RescalePools_Inferred.md`

## Callers / callees

- Callers: `FUN_004d32c0`, `FUN_004d3310`
- Callees: `FUN_004bade0`, `FUN_004cf3b0`, `FUN_004badf0`

## Confidence

| Claim | Level |
|---|---|
| Control flow + clamps | **Confirmed** |
| Fan-out to pool rescale | **Confirmed** |
| Product name | **Open** |
