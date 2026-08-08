# Function record: Character_GetReverseEngineerSkillCapacityByTier_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00520520` |
| **Canonical name** | `Character_GetReverseEngineerSkillCapacityByTier_Inferred` (**Inferred** — product field English open) |
| **Ghidra name** | `FUN_00520520` |
| **Prior scaffold** | `Named_CalleeOf_Named_CalleeOf_Skill_You_do_not_possess_the_Tink_00520520` (**retired**) |
| **Address** | `0x00520520`–`0x005206aa` inclusive (**395 B** / `0x18b`) |
| **Jump table** | data `0x005206ac`–`0x005206c3` (6× dword) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer / reverse-engineer |
| **Parent dual / context** | `0x0052e640` `Character_ComputeReverseEngineerSuccessFraction_Inferred` (MEGA-117) |
| **Agent** | R10-033 OWN-ONLY dual 2026-08-05 |
| **Completion status** | Dual sealed (A/B **accept-with-gaps**) |
| **Terminal** | **false** |

## Evidence for name

1. Sole caller is dualed RE success-fraction `Character_ComputeReverseEngineerSuccessFraction_Inferred`.
2. Reads **character** skill byte `+0x598` (same field parent uses for primary skill×3.5 budget).
3. Returns integer capacity compared to recipe secondary cost / used as capacity[t] in score.
4. Tier argument selects decreasing multipliers 3.5 → 0.7.
5. No PDB/RTTI/in-body strings → **`_Inferred`**.

Retired: Named_CalleeOf tinkering-string scaffold (wrong domain).

## Purpose

```text
v = character[+0x598]   // uint8 skill
capacity(tier) =
  floor(v * 3.5)  // tier 0,1
  floor(v * 2.8)  // tier 2
  floor(v * 2.1)  // tier 3
  floor(v * 1.4)  // tier 4
  floor(v * 0.7)  // tier 5
  0               // else
```

## Signature

```c
// __thiscall: ECX = character; stack tier; RET 4; EAX = int capacity
int __thiscall Character_GetReverseEngineerSkillCapacityByTier_Inferred(
    void *character,
    unsigned tier);
```

## Layout (character fields touched)

| Offset | Width | Role in this VA |
|---|---|---|
| **+0x598** | u8 | **read** — RE skill rank/level source |

## Call graph

| Role | Target |
|---|---|
| **Callers (2 sites)** | `FUN_0052e640` @ `0x0052ea2b` (`PUSH row+1`); @ `0x0052ea96` (`PUSH tier 0..5`) |
| Callees | `floor` |
| Xrefs | 2 UNCONDITIONAL_CALL |

## Chain context (not dualled; evidence only)

```text
FUN_0052e640  Character_ComputeReverseEngineerSuccessFraction_Inferred  [parent MEGA-117]
  ├─ primary budget: floor(skill×3.5) inline
  ├─ FUN_00520520  Character_GetReverseEngineerSkillCapacityByTier_Inferred  [OWN R10-033]
  │    ├─ site A: capacity(row+1) vs secondary recipe cost
  │    └─ site B: capacity(tier) in score term
  └─ consumers: RE tooltip / %.01f%% UI
```

## Artifacts

- Clean: `docs/reconstruction/reconstructed-exact/Character_GetReverseEngineerSkillCapacityByTier_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00520520.cpp`
- Retired scaffold: `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Skill_You_do_not_possess_the_Tink_00520520.cpp`
- Raw: `docs/reconstruction/raw/aa_00520520_FUN_00520520.md`
- Annotated: `docs/reconstruction/raw/aa_00520520_FUN_00520520.annotated.md`
- Review A: `docs/reconstruction/reviews/A_aa_00520520_Character_GetReverseEngineerSkillCapacityByTier_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00520520_Character_GetReverseEngineerSkillCapacityByTier_Inferred.md`
- FUN record: `docs/reconstruction/functions/aa_00520520_FUN_00520520.md`
- Report: `docs/agents/task-dual-ab-00520520-r10-report.md`

## Confidence

| Claim | Level |
|---|---|
| Switch CF + jump table targets | **Confirmed** |
| ECX=character; +0x598; RET 4; EAX capacity | **Confirmed** |
| Mult table 3.5/2.8/2.1/1.4/0.7 | **Confirmed** |
| RE / inventory-transfer role via sole parent | **High** |
| Product English for +0x598 | **Inferred** |
| Runtime Confirmed | **Open** |
