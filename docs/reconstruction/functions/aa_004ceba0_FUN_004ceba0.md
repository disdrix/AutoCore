# Function record: Skill_NonCreatureCastAutoHit (FUN_004ceba0)

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ceba0` |
| **Canonical name** | `Skill_NonCreatureCastAutoHit` |
| **Address** | `0x004ceba0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `skills-abilities` |
| **Completion status** | **Partial** — dual A/B refreshed 2026-07-29; score chain + clamps sealed; middle residual open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

Human name: `Skill_NonCreatureCastAutoHit` (plate string `Non-Creature cast (AutoHit)`)

## Alias_prev

- `FUN_004ceba0`
- `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_004ceba0`

## Purpose

Accuracy **hit-chance score** producer for skill combat. Shared kernel for creature vs creature (clamped score) and AutoHit short-circuits (inanimate victim / non-creature attacker / null attacker). Consumed by `Skill_AccuracyHitCheck_Inferred` via `FUN_005531d0`.

## Signature (caller-recovered)

```c
float10 Skill_NonCreatureCastAutoHit(
    float attackerBonus,   // esp+4
    float unusedZero,      // esp+8  — callers pass 0; unused in high pcode
    float skillAccuracy,   // esp+C  — skill+0x24; unused in high pcode
    void *attacker,        // esp+10
    void *victim,          // esp+14
    char *diagOptional);   // esp+18
```

Decompiler still prints `float10 FUN_004ceba0(void)` with `in_stack_*` / `unaff_retaddr`.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004ceba0_FUN_004ceba0.md`
- Annotated: `docs/reconstruction/raw/aa_004ceba0_FUN_004ceba0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Skill_NonCreatureCastAutoHit.cpp` (alias `FUN_004ceba0.cpp`)
- Dual A: `docs/reconstruction/reviews/A_aa_004ceba0_Skill_NonCreatureCastAutoHit.md`
- Dual B: `docs/reconstruction/reviews/B_aa_004ceba0_Skill_NonCreatureCastAutoHit.md`

## Callers / callees

| Direction | Address | Name / role |
|---|---|---|
| Caller | `0x005531d0` | Score wrapper for accuracy hit check (`atkBonus` from `FUN_004c4140`, `skill+0x24`) |
| Caller | `0x0056cf00` | Secondary product path (this+0x10c/0x114 bonus) |
| Callee | `0x004c4070` | Atk-side short clamp helper — **return unused** in high pcode |
| Callee | `0x004c41c0` | Vic-side short clamp helper — **return unused** in high pcode |

## Sealed constants

| Symbol | VA | Value |
|---|---|---|
| `g_flOne` | `0x00a0f2a0` | 1.0 |
| `g_flZero` | `0x00a0f518` | 0.0 |
| `DAT_009cbf7c` | `0x009cbf7c` | 0.95 (max / level-high) |
| `g_flKillSpreeBonusPerStack` | `0x009cbf80` | 0.05 (min / level-low; reused const) |
| `DAT_00af1b6c` | `0x00af1b6c` | 0.15 (dual-vehicle floor) |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler + high pcode | High |
| Accuracy score chain position | High / Confirmed |
| Parameter semantic names | Probable (callers) |
| `skillAccuracy` unused in body | High (pcode) |
| Types / vfunc product names | Tentative |
