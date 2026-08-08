# Function record: Character_ComputeReverseEngineerSuccessFraction_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052e640` |
| **Canonical name** | `Character_ComputeReverseEngineerSuccessFraction_Inferred` |
| **Ghidra name** | `FUN_0052e640` |
| **Address** | `0x0052e640`–`0x0052eb76` |
| **Module** | `autoassault.exe` |
| **System** | `inventory-transfer` |
| **Dual** | MEGA-117 2026-08-05 — **accept-with-gaps** |

## Evidence for name

1. Consumer `FUN_0084b890` multiplies return by 100, clamps to 100, formats `%.01f%%`.
2. Dualed parent `Client_UI_ItemHover_ApplyRETinkerGadgetTooltip_Inferred` (`0x0085ce20`) uses score ≤ 0 to build `"Requires At Least %d Reverse Engineering"`.
3. Twin `FUN_0052e1d0` supplies the integer **required** level; this VA supplies the **success fraction**.
4. Skill byte at `character+0x598` with tier capacities via `FUN_00520520`; free short-circuit at `character+0x6b4`.
5. No PDB/RTTI method name → **`_Inferred`**.

Retired: `Named_CalleeOf_Skill_You_do_not_possess_the_Tinkering_skill_to_0052e640` (wrong domain — parent tinkering strings, not this body).

## Signature

```c
float __thiscall Character_ComputeReverseEngineerSuccessFraction_Inferred(
    void* character,  // ECX
    void* item);      // stack; RET 4; ST0 fraction
```

## Cross-links

| Related | VA | Note |
|---|---|---|
| Parent tooltip | `0x0085ce20` | dualed WQ8R-H |
| Required level twin | `0x0052e1d0` | residual |
| Slot count | `0x00599dd0` | dualed ItemDef_CountConfiguredModSlots |
| CloneBase lookup | `0x00404d70` | dualed GameData_LookupCloneBaseByCbid |
| Lootgen gate | `0x004ce940` | dualed CVOGLootGenerator_GetOrCreate |
| Capacity by tier | `0x00520520` | residual |
| RE eligibility | `0x00522950` | residual |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0052e640_FUN_0052e640.md`
- Annotated: `docs/reconstruction/raw/aa_0052e640_FUN_0052e640.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Character_ComputeReverseEngineerSuccessFraction_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_0052e640.cpp`
- A: `docs/reconstruction/reviews/A_aa_0052e640_Character_ComputeReverseEngineerSuccessFraction_Inferred.md`
- B: `docs/reconstruction/reviews/B_aa_0052e640_Character_ComputeReverseEngineerSuccessFraction_Inferred.md`
- FUN record: `docs/reconstruction/functions/aa_0052e640_FUN_0052e640.md`
- Report: `docs/agents/task-dual-ab-0052e640-mega-117-report.md`
