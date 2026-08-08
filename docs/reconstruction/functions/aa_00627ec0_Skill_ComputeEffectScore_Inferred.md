# Function record: Skill_ComputeEffectScore_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00627ec0` |
| **Canonical name** | `Skill_ComputeEffectScore_Inferred` |
| **Ghidra name** | `FUN_00627ec0` |
| **Address** | `0x00627ec0`–`0x00628516` exclusive (1878 B / `0x756`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities |
| **Completion status** | **Dual A/B sealed** (WQ9E-B 2026-08-04) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias / superseded

- Scaffold: `FUN_00627ec0`

## Purpose

Weighted **effect score** for a skill runtime. Calls dualed presence leaf, then accumulates bank terms only when corresponding presence bits are set, applies duration/charge scales, floors at 1.0, returns `(int)ceil(score)`.

Callers compare two scores (often skill-at-`obj+0x24` vs another skill) to decide HB/conflict winner (`return 2` when first < second).

## Signature

```c
int __fastcall Skill_ComputeEffectScore_Inferred(void *pSkill);
// ECX = skill runtime; EAX = ceil score; plain ret
```

## Callers / callees

| Direction | Symbol | VA / notes |
|---|---|---|
| Callee | `Skill_ComputeEffectPresenceFlags_Inferred` | `0x00627be0` |
| Callee | `ceil` | CRT |
| Caller | `FUN_00625b00` | ×2 dual-score |
| Caller | `FUN_00618bf0` | ×2 dual-score |
| Call sites | `0x00578730`, `0x00578739`, `0x0059a0f7`, `0x0059a126`, `0x0059a163`, `0x0061fa12`, `0x0061fa1b` | dual-score pattern |

## Presence bits used

| Bit | Source | Role in score |
|---:|---|---|
| `0x1` | presence scan bank `+0x60` | primary pair terms + global scale |
| `0x100` | pairs `+0x78/+0x90` | secondary pair terms |
| `0x40` | i16 `+0xd0..` | duration-linked sum |
| `0x8` | i16 `+0x6c` | signed short terms |
| `0x2` | f32 `+0x3c` | single float term |
| `0x10` | char `+0xda` | byte × 2.0 |
| `0x800` / `0x1000` | base `skill+0xc` bits | i16@0 term / score×5 |

## Artifacts

- Raw (+ re-verify): `docs/reconstruction/raw/aa_00627ec0_FUN_00627ec0.md`
- Annotated: `docs/reconstruction/raw/aa_00627ec0_FUN_00627ec0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Skill_ComputeEffectScore_Inferred.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_00627ec0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00627ec0_Skill_ComputeEffectScore_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00627ec0_Skill_ComputeEffectScore_Inferred.md`

## Confidence

| Claim | Level |
|---|---|
| Score CF + bit gates | **High** |
| Sealed float pool | **High** |
| Dual-score caller role | **High** |
| Product English (threat/DPS/priority) | **Open** (`_Inferred`) |
| Exhaustive bank combat labels | **Open** |
