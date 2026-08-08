# Function record: ReverseEngineer_CeilCostToLevelByTier_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005206d0` |
| **Canonical name** | `ReverseEngineer_CeilCostToLevelByTier_Inferred` (**Inferred** — product English open) |
| **Ghidra name** | `FUN_005206d0` |
| **Prior scaffold** | `Named_CalleeOf_Named_CalleeOf_Skill_You_do_not_possess_the_Tink_005206d0` (**retired**) |
| **Address** | `0x005206d0`–`0x00520829` inclusive (**346 B** / `0x15A`) |
| **Jump table** | data `0x0052082c`–`0x00520843` (6× dword); align `8B FF` @ `0x0052082a` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer / reverse-engineer |
| **Parent dual / context** | `0x0052e1d0` `Character_ComputeReverseEngineerRequiredLevel_Inferred` (R11-002) |
| **Capacity twin (scale table)** | `0x00520520` `Character_GetReverseEngineerSkillCapacityByTier_Inferred` (R10-033) — skill×mult floor; this VA is cost×(1/mult) ceil |
| **Agent** | R12-019 OWN-ONLY dual 2026-08-05 |
| **Partition** | `WAVE_2026-08-05_r12_residual_partition_map.md` R12-019; dual start 2646 |
| **Completion status** | Dual sealed (A/B **accept-with-gaps**) |
| **Terminal** | **false** |

## Evidence for name

1. Sole caller is dualed RE required-level parent `Character_ComputeReverseEngineerRequiredLevel_Inferred`.
2. Body is pure `(tier, cost) → ceil(cost * inv_mult[tier])` int; no character/item this.
3. Inv mult table is exact inverse of dualed capacity mults `{3.5, 3.5, 2.8, 2.1, 1.4, 0.7}`.
4. Parent folds results into `max(...)` required RE skill level for tooltip `"Requires At Least %d Reverse Engineering"`.
5. No PDB/RTTI/in-body strings → **`_Inferred`**.

Retired: Named_CalleeOf tinkering-string scaffold (wrong domain).

## Purpose

```text
level(tier, cost) =
  ceil(cost * 1/3.5)  // tier 0,1
  ceil(cost * 1/2.8)  // tier 2
  ceil(cost * 1/2.1)  // tier 3
  ceil(cost * 1/1.4)  // tier 4
  ceil(cost * 1/0.7)  // tier 5
  0                   // else
```

## Signature

```c
// __stdcall: stack tier, stack cost; RET 8; EAX = int level
// Not thiscall — no ECX/this.
int __stdcall ReverseEngineer_CeilCostToLevelByTier_Inferred(
    unsigned tier,
    int cost);
```

## Constants (sealed `read_memory`)

| VA | Float | = 1/mult | Tier(s) |
|---|---:|---:|---|
| `0x009cdff4` | 0.2857143 | 3.5 | 0, 1 |
| `0x009cefcc` | 0.3571429 | 2.8 | 2 |
| `0x009cefc8` | 0.4761905 | 2.1 | 3 |
| `0x00aaa7c4` | 0.7142857 | 1.4 | 4 |
| `0x009cefc4` | 1.4285715 | 0.7 | 5 |

## Call graph

| Role | Target |
|---|---|
| **Callers (4 sites, 1 fn)** | `FUN_0052e1d0` @ `0x0052e5c6`, `0x0052e5d5`, `0x0052e5fb`, `0x0052e60a` |
| Callees | `ceil` (IAT `@0x009c6588`) |
| Xrefs | 4 UNCONDITIONAL_CALL |

## Chain context (not dualled; evidence only)

```text
FUN_0085ce20  Client_UI_ItemHover_ApplyRETinkerGadgetTooltip_Inferred  [dualed]
  mode 0 Reverse Engineer:
    └─ FUN_0052e1d0  Character_ComputeReverseEngineerRequiredLevel_Inferred  [parent R11-002]
         ├─ inline ceil(primary * 1/3.5)
         └─ FUN_005206d0  ReverseEngineer_CeilCostToLevelByTier_Inferred  [OWN R12-019]
              ├─ site: (row_count, total_secondary_cost)
              └─ sites: (tier 1..5, per-tier row cost)

Scale twin (success-fraction path; not this VA):
  FUN_00520520  Character_GetReverseEngineerSkillCapacityByTier_Inferred  [R10-033]
    skill[+0x598] * mult[tier] → floor capacity
```

## Artifacts

- Clean: `docs/reconstruction/reconstructed-exact/ReverseEngineer_CeilCostToLevelByTier_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_005206d0.cpp`
- Retired scaffold: `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Skill_You_do_not_possess_the_Tink_005206d0.cpp`
- Raw: `docs/reconstruction/raw/aa_005206d0_FUN_005206d0.md`
- Annotated: `docs/reconstruction/raw/aa_005206d0_FUN_005206d0.annotated.md`
- Dual A: `docs/reconstruction/reviews/A_aa_005206d0_ReverseEngineer_CeilCostToLevelByTier_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_005206d0_ReverseEngineer_CeilCostToLevelByTier_Inferred.md`
- Report: `docs/agents/task-dual-ab-005206d0-r12-report.md`

## Gaps

- Product English for tier index vs recipe-row ordinal.
- Server vs display-only enforcement.
- Runtime / bit-exact / differential.

## Confidence

| Claim | Level |
|---|---|
| CF / jump table / default 0 | **High** |
| ABI stdcall RET 8 / two stack / EAX int | **High** |
| Inv-mult table + ceil formula | **High** |
| Sole parent RE required-level max helper | **High** |
| Product method name | **Inferred** |
| Runtime Confirmed | **Not claimed** |
