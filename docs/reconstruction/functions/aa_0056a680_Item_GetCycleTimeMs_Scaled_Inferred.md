# Function record: Item_GetCycleTimeMs_Scaled_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0056a680` |
| **Canonical name** | `Item_GetCycleTimeMs_Scaled_Inferred` |
| **Ghidra name** | `FUN_0056a680` |
| **Address** | `0x0056a680` |
| **Body range** | `0x0056a680`–`0x0056a765` (Ghidra) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | item / weapon combat stats |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF + ms role + scale/floor sealed; product English open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_0056a680_Item_GetCycleTimeMs_Scaled_Inferred.md`, `reviews/B_aa_0056a680_Item_GetCycleTimeMs_Scaled_Inferred.md` |
| **Last reviewed** | `2026-07-29` (W25-L) |

## Alias

- `FUN_0056a680` (Ghidra)
- Prior scaffold system `unknown`
- Prior auto name `Named_CalleeOf_CVOGTacArc_UpdateMesh_0056a680`

## Purpose

Return the item/weapon **cycle time in milliseconds** from `this+0xD0`. When `bSkipScale==0` and a related object (`MI+0xB0`) exposes a non-1.0 float scale via `vtbl+0x214`→`blob+0x1E8`, return `max(500, round(scale * baseMs))`. Callers use the result as the DPS / tac-arc time denominator (`* g_flMsToSeconds`).

## Signature

```c
// thiscall; stack char; ret 4; EAX = int ms
int Item_GetCycleTimeMs_Scaled_Inferred(void* this_item, char bSkipScale);
```

## Algorithm

1. If `bSkipScale != 0` → return `*(int*)(this+0xD0)`.
2. Resolve `related` at `this + *( *(this+4)+4 ) + 0xB0`; null → raw.
3. `blob = related->vtbl[+0x214]()`; null → raw.
4. If `*(float*)(blob+0x1E8) == 1.0f` (`g_flOne`) → raw.
5. `product = scale * (float)baseMs`; if trunc(product±bias) ≤ 500 → **500**; else `FUN_0040dab0(product)`.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0056a680_FUN_0056a680.md`
- Annotated: `docs/reconstruction/raw/aa_0056a680_FUN_0056a680.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Item_GetCycleTimeMs_Scaled_Inferred.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_0056a680.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-0063f5b0-0056a680-w25l-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callers** | `CVOGTacArc_UpdateMesh`, `UI_BuildItemTooltipStats`, `FUN_0087d810` (DPS UI), `FUN_005fe6a0`, `FUN_004f79d0`, `FUN_00509c70`, `FUN_00902c40`, … (**21** xrefs) |
| **Callees** | `FUN_0040dab0` (round float→int) |

## Confidence

| Claim | Level |
|---|---|
| thiscall + ret 4 + `this+0xD0` base | **High** |
| Scale path + 500 floor + bias globals | **High** |
| Result is ms cycle used for DPS | **High** (caller use) |
| Product type / `+0x1E8` English | **Inferred** |
| Runtime / bit-exact | Open |

## Related

- Setter `FUN_0056a1b0` (`this+0xD0`, min 1)
- Round helper `aa_0040dab0` / `FUN_0040dab0`
- `g_flOne` `0x00a0f2a0`, bias `0x00aaa6d0`
