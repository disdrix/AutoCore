# Function record: Skill_AccuracyScore_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005531d0` |
| **Canonical name** | `Skill_AccuracyScore_Inferred` |
| **Address** | `0x005531d0`–`0x00553239` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `skills-abilities` |
| **Completion status** | **Dual A/B sealed (accept-with-gaps)** — ABI + CF + call pack sealed; product name + cebao internals open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Review date** | `2026-07-29` |

## Alias

- Ghidra: `FUN_005531d0`
- Scaffold: `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvSkillSt_005531d0` (**falsified as role** — accuracy score helper, not Recv helper)
- Parent consumer: `Skill_AccuracyHitCheck_Inferred` (`0x00553240`)

## Purpose

Skill **`__thiscall`** accuracy **score** producer: optional attacker creature short-stat bonus → float, plus `skill+0x24`, forwarded into `Skill_NonCreatureCastAutoHit` (`0x004ceba0`). Returns **float** (ST0). Used by hit/miss compare and a second display-scale site (`score * 100.0f`).

## Signature (assembly-sealed)

```c
// __thiscall  ECX = skill
// RET 0xC; returns float in ST0 (x87)
float Skill_AccuracyScore_Inferred(
    void *skill,
    void *attacker,
    void *target,
    char *debugReasonOut);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005531d0_FUN_005531d0.md` (+ 2026-07-29 re-verify append)
- Annotated: `docs/reconstruction/raw/aa_005531d0_Skill_AccuracyScore_Inferred.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Skill_AccuracyScore_Inferred.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_005531d0_Skill_AccuracyScore_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_005531d0_Skill_AccuracyScore_Inferred.md`
- Scaffold clean (superseded name): `docs/reconstruction/reconstructed-exact/FUN_005531d0.cpp`

## Callers / callees

| Direction | Address | Name / role |
|---|---|---|
| Caller | `0x00553297` | `Skill_AccuracyHitCheck_Inferred` |
| Caller | `0x0082731b` | unnamed (no function); score×100 display path |
| Callee | vtbl+0x214 | creature / animate getter on attacker |
| Callee | `0x004c4140` | short-stat clamp [1,250] from +0x140/+0x148 |
| Callee | `0x004ceba0` | `Skill_NonCreatureCastAutoHit` |

## Confidence

| Claim | Level |
|---|---|
| Skill thiscall + RET 0xC | **Confirmed** (asm) |
| Float ST0 return | **Confirmed** (no FSTP; parent FCOMIP) |
| Bonus 0 when attacker or creature null | **Confirmed** |
| Pack into cebao: (bonus, 0, skill+0x24, atk, tgt, dbg) | **Confirmed** (push order + ADD ESP 0x18) |
| Product name | **Inferred** |
| Full score math (cebao) | Out of unit / partial sibling dual |
