# Function record: Character_ComputeReverseEngineerRequiredLevel_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052e1d0` |
| **Canonical name** | `Character_ComputeReverseEngineerRequiredLevel_Inferred` |
| **Ghidra name** | `FUN_0052e1d0` |
| **Address** | `0x0052e1d0`–`0x0052e636` |
| **Module** | `autoassault.exe` |
| **System** | `inventory-transfer` |
| **Dual** | R11-002 2026-08-05 — **accept-with-gaps** |

## Evidence for name

1. Dualed parent `Client_UI_ItemHover_ApplyRETinkerGadgetTooltip_Inferred` (`0x0085ce20`) uses return as `%d` in `"Requires At Least %d Reverse Engineering"` when twin fraction ≤ 0.
2. Twin `Character_ComputeReverseEngineerSuccessFraction_Inferred` (`0x0052e640`) supplies **float** success; this VA supplies **integer** required level (MEGA-117 residual).
3. Formula `ceil(cost * 1/mult[tier])` is the inverse of dualed capacity `floor(skill * mult[tier])` (`FUN_00520520` / `FUN_005206d0`).
4. Free flag `character+0x6b4>0` → **0** here (twin free → **1.0**).
5. No PDB/RTTI method name → **`_Inferred`**.

Retired: `Named_CalleeOf_Skill_You_do_not_possess_the_Tinkering_skill_to_0052e1d0` (wrong domain — parent tinkering strings, not this body).

## Signature

```c
int __thiscall Character_ComputeReverseEngineerRequiredLevel_Inferred(
    void* character,  // ECX
    void* item);      // stack; RET 4; EAX required level
```

## Cross-links

| Related | VA | Note |
|---|---|---|
| Parent tooltip | `0x0085ce20` | dualed; sole caller |
| Success fraction twin | `0x0052e640` | dualed MEGA-117 |
| Slot count | `0x00599dd0` | dualed ItemDef_CountConfiguredModSlots |
| CloneBase lookup | `0x00404d70` | dualed GameData_LookupCloneBaseByCbid |
| Lootgen gate | `0x004ce940` | dualed CVOGLootGenerator_GetOrCreate |
| Capacity by tier | `0x00520520` | dualed R10-033 |
| Cost→level by tier | `0x005206d0` | residual (inv mult table sealed here) |
| Recipe-by-prefix | `0x005097b0` | residual |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0052e1d0_FUN_0052e1d0.md`
- Annotated: `docs/reconstruction/raw/aa_0052e1d0_FUN_0052e1d0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Character_ComputeReverseEngineerRequiredLevel_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_0052e1d0.cpp`
- A: `docs/reconstruction/reviews/A_aa_0052e1d0_Character_ComputeReverseEngineerRequiredLevel_Inferred.md`
- B: `docs/reconstruction/reviews/B_aa_0052e1d0_Character_ComputeReverseEngineerRequiredLevel_Inferred.md`
- FUN record: `docs/reconstruction/functions/aa_0052e1d0_FUN_0052e1d0.md`
- Report: `docs/agents/task-dual-ab-0052e1d0-r11-report.md`
