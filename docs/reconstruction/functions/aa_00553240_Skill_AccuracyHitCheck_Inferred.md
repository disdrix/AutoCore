# Function record: Skill_AccuracyHitCheck_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00553240` |
| **Canonical name** | `Skill_AccuracyHitCheck_Inferred` |
| **Address** | `0x00553240`–`0x005532ce` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `skills-abilities` |
| **Completion status** | **Dual A/B sealed** (accept-with-gaps) — 2026-07-29 |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

| Name | Notes |
|---|---|
| `FUN_00553240` | Ghidra default |
| `Named_CalleeOf_Named_CalleeOf_Client_RecvSkillStatusEffect_00553240` | obsolete scaffold |
| `Skill_AccuracyHitCheck_Inferred` | **canonical** (role; no product string) |

## Purpose

Skill **thiscall** boolean accuracy check: auto-hit when `skill+0x24 == -1.0f`, else miss when score from `FUN_005531d0`/`FUN_004ceba0` is `<= (roll%100)*0.01f`. Return **1** hit / **0** miss; optional out-byte set on miss.

Primary ApplyEffects path: `Skill_ApplyEffectsOnTarget_Inferred` when `skill+0x624` bit0.

## Signature (sealed)

```c
// __thiscall  ECX = skill
unsigned int Skill_AccuracyHitCheck_Inferred(
    void *skill,
    void *attacker,
    void *target,
    unsigned short roll,
    unsigned char *outMissFlagOptional);
// AL: 1=hit, 0=miss
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00553240_FUN_00553240.md`
- Annotated: `docs/reconstruction/raw/aa_00553240_Skill_AccuracyHitCheck_Inferred.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Skill_AccuracyHitCheck_Inferred.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00553240_Skill_AccuracyHitCheck_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00553240_Skill_AccuracyHitCheck_Inferred.md`
- Scratch: `tmp/a_00553240.md`

## Callers / callees

| Direction | Address | Name / role |
|---|---|---|
| Caller | `0x005538a0` / site `0x00553982` | `Skill_ApplyEffectsOnTarget_Inferred` |
| Caller | `0x0058c850` / site `0x0058c9ac` | multi-target damage helper (`FUN_0058c850`) |
| Callee | `0x005531d0` | score wrapper → `FUN_004ceba0` |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | **High** |
| ABI (skill thiscall) from assembly | **Confirmed** |
| Constants -1.0 / 0.01 | **Confirmed** (`read_memory`) |
| Parameter semantic names | **High** |
| Product name | Inferred |
| Score formula internals | Tentative (callee residual) |
