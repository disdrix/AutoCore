# Dual A/B — `aa_004ceba0` Skill_NonCreatureCastAutoHit (accuracy score chain)

**Date:** 2026-07-29  
**Owned VA:** `0x004ceba0` only  
**Tools:** Ghidra `decompile_function` / `read_memory` / pcode / callers (no Launcher; no WORK_QUEUE/RESUME/ACTIVE_WORK/CHANGE_LOG)  
**Verdict:** **accept-with-gaps**

---

## Sealed facts

### Role

| Fact | Evidence |
|---|---|
| Unit is accuracy **score** producer (`float10` / ST0), not damage | Parent `Skill_AccuracyHitCheck_Inferred` (`0x00553240`) compares `score <= (roll%100)*0.01f` |
| Sole accuracy-chain path | `00553240` → `005531d0` → **`004ceba0`** |
| Exactly **2** callers | `FUN_005531d0`, `FUN_0056cf00` |
| Plate name | `"Non-Creature cast (AutoHit)"` → registry `Skill_NonCreatureCastAutoHit` |

### Signature (caller-recovered)

```c
float10 Skill_NonCreatureCastAutoHit(
    float attackerBonus,   // 005531d0: (float)FUN_004c4140(creature) or 0
    float unusedZero,      // both callers pass 0
    float skillAccuracy,   // skill+0x24; unused in this body (high pcode)
    void *attacker,
    void *victim,
    char *diagOptional);
```

### Early-out returns

| Gate | Diag string | Return |
|---|---|---|
| `attacker == NULL` | `"No Attacker"` | **1.0** (`g_flOne`) |
| `victim == NULL` | `"No Victim"` | **0.0** (`g_flZero`) |
| victim vfunc `+0x214` == 0 | `"Victim inanimate (AutoHit)"` | **1.0** |
| attacker vfunc `+0x214` == 0 | `"Non-Creature cast (AutoHit)"` | **1.0** |

### Creature path

| Fact | Detail |
|---|---|
| Levels | vfunc `+0x27c` on atk & vic |
| Level band gate | Only if **either** side has vfunc `+0x210`(0) == NULL |
| `levelAtk - levelVic > 9` | return **0.95** |
| `levelAtk - levelVic < -9` | return **0.05** |
| Base score | `*(f32*)(attacker.creature + 0x260) + attackerBonus` (pcode `FLOAT_ADD` @ `004ced06`) |
| Dual-vehicle floor | both have vfunc `+0x210` and score < **0.15** → score = **0.15** |
| Else clamp | **[0.05, 0.95]** |

### Constants (`read_memory`)

| Symbol | VA | LE | Value |
|---|---|---|---|
| `g_flOne` | `0x00a0f2a0` | `00 00 80 3f` | 1.0 |
| `g_flZero` | `0x00a0f518` | `00 00 00 00` | 0.0 |
| `DAT_009cbf7c` | `0x009cbf7c` | `33 33 73 3f` | **0.95** (xrefs: this fn only) |
| `g_flKillSpreeBonusPerStack` | `0x009cbf80` | `cd cc 4c 3d` | **0.05** (min clamp; name is XP-domain reuse) |
| `DAT_00af1b6c` | `0x00af1b6c` | `9a 99 19 3e` | **0.15** (xrefs: this fn only) |

### Chain contract (with parent)

```
if skill+0x24 == -1.0f: HIT                        // parent only
else:
  atkBonus = creature ? (float)FUN_004c4140(cre) : 0  // shorts @+0x140/+0x148
  score = Skill_NonCreatureCastAutoHit(atkBonus, 0, skill+0x24, atk, vic, &diag)
  HIT if score > (roll%100)*0.01f; else MISS
```

**Port implication:** inanimate / non-creature → score 1.0 → always beats roll. Skill accuracy scalar does **not** scale score under sealed pcode (only -1 auto-hit in parent).

### Dead-looking callees (sealed observation)

`FUN_004c4070` / `FUN_004c41c0` are called after creature probes; high pcode marks `CALL out=-` and never feeds them into `FLOAT_ADD`. Do not port into score until asm proves otherwise.

---

## Gaps

1. Product names: vfunc `+0x214` / `+0x210` / `+0x27c` / `+0x1d4`; field `creature+0x260`.
2. Why 4070/41c0 exist if returns unused (dead code vs decompiler miss).
3. Absolute proof `skillAccuracy` never used (high pcode only; no `disassemble_bytes` per rules).
4. Full product role of second caller `FUN_0056cf00`.
5. Runtime capture / bit-exact / image diff.
6. Prefer dedicated constant names for 0.05/0.15/0.95 in accuracy domain (kill-spree alias is misleading).

---

## Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_004ceba0_Skill_NonCreatureCastAutoHit.md` | accept-with-gaps |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_004ceba0_Skill_NonCreatureCastAutoHit.md` | accept-with-gaps |

Prior shallow duals (2026-07-23) replaced with score-chain analysis.

---

## Files touched / authoritative

| Role | Absolute path |
|---|---|
| Dual A | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reviews\A_aa_004ceba0_Skill_NonCreatureCastAutoHit.md` |
| Dual B | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reviews\B_aa_004ceba0_Skill_NonCreatureCastAutoHit.md` |
| Function record | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\functions\aa_004ceba0_FUN_004ceba0.md` |
| Raw | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\raw\aa_004ceba0_FUN_004ceba0.md` |
| Annotated | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\raw\aa_004ceba0_FUN_004ceba0.annotated.md` |
| Clean | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reconstructed-exact\Skill_NonCreatureCastAutoHit.cpp` |
| This report | `C:\Users\josh\Documents\GitHub\AutoCore\docs\agents\task-dual-ab-004ceba0-skill-noncreature-castautohit-report.md` |
| Parent dual (context) | `docs\reconstruction\reviews\A_aa_00553240_Skill_AccuracyHitCheck_Inferred.md` |

Scratch only: `tmp\parse_pcode_004ceba0.py`, `tmp\parse_stack_refs_004ceba0.py`.

---

## AutoCore port sketch

```csharp
// Score only — parent owns -1.0 auto-hit and roll compare
float Score(Entity atk, Entity vic, float atkBonus, StringBuilder diag = null)
{
    if (atk == null) { diag?.Append("No Attacker"); return 1f; }
    if (vic == null) { diag?.Append("No Victim"); return 0f; }
    if (GetCreature(vic) == null) { diag?.Append("Victim inanimate (AutoHit)"); return 1f; }
    if (GetCreature(atk) == null) { diag?.Append("Non-Creature cast (AutoHit)"); return 1f; }

    bool vehAtk = HasVehicleComponent(atk);
    bool vehVic = HasVehicleComponent(vic);
    if (!vehAtk || !vehVic)
    {
        int d = Level(atk) - Level(vic);
        if (d > 9) return 0.95f;
        if (d < -9) return 0.05f;
    }

    float score = GetCreature(atk).AccuracyBase260 + atkBonus; // field name TBD
    if (vehAtk && vehVic && score < 0.15f) return 0.15f;
    if (score > 0.95f) return 0.95f;
    if (score < 0.05f) return 0.05f;
    return score;
}
```
