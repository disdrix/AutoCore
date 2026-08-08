# Function record: Skill_StoreEffectPresenceFlags_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0054fec0` |
| **Canonical name** | `Skill_StoreEffectPresenceFlags_Inferred` |
| **Ghidra name** | `FUN_0054fec0` |
| **Address** | `0x0054fec0`–`0x0054fef8` (57 B inclusive of ret) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities |
| **Completion status** | **Dual A/B sealed** (WQ9E-B 2026-08-04) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias / superseded

- Scaffold: `FUN_0054fec0`

## Purpose

Standalone **store** of dualed `Skill_ComputeEffectPresenceFlags_Inferred` into `skill+0x624`. Applies the sealed Reevaluate post-process:

```
mask = Skill_ComputeEffectPresenceFlags_Inferred(skill)
if skill[+0x620] == 0:
  skill[+0x624] = mask
else:
  skill[+0x624] = mask | 4
  if skill[+0x148] == 0:
    skill[+0x620] |= 0x100000
```

Does **not** call `Skill_EvaluateRankedElements` (unlike Reevaluate). No static call sites recovered; Reevaluate inlines the same store after Evaluate.

## Signature

```c
void __fastcall Skill_StoreEffectPresenceFlags_Inferred(void *pSkill);
// ECX = skill runtime; void; plain ret
```

## Callers / callees

| Direction | Symbol | VA |
|---|---|---|
| Callee | `Skill_ComputeEffectPresenceFlags_Inferred` | `0x00627be0` |
| Static callers | *(none)* | — |
| Twin (inlined store) | `Skill_ReevaluateForCurrentRank` | `0x00553390` |

## Artifacts

- Raw (+ re-verify): `docs/reconstruction/raw/aa_0054fec0_FUN_0054fec0.md`
- Annotated: `docs/reconstruction/raw/aa_0054fec0_FUN_0054fec0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Skill_StoreEffectPresenceFlags_Inferred.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_0054fec0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0054fec0_Skill_StoreEffectPresenceFlags_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_0054fec0_Skill_StoreEffectPresenceFlags_Inferred.md`

## Confidence

| Claim | Level |
|---|---|
| Store CF + bit ops | **High** |
| Skill ECX + presence callee | **High** |
| Role name (store presence → +0x624) | **High** (behavior); product demangle **Inferred** |
| Live consumers of this exact VA | **Open** (zero static xrefs) |
