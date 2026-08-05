# Review A (reconstruction fidelity): `aa_004ceba0` Skill_NonCreatureCastAutoHit

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ceba0` |
| **VA** | `0x004ceba0`–`~0x004cef6b` |
| **Canonical name** | `Skill_NonCreatureCastAutoHit` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (accuracy **score** producer) |
| **Counterpart** | `reviews/B_aa_004ceba0_Skill_NonCreatureCastAutoHit.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** (gates + AutoHit + clamp + call chain sealed; middle residual math open) |

---

## 1. Purpose

**Accuracy hit-chance score** helper (returns `float10` / ST0 in **\[0, 1\]** range after clamps). Consumed by the skill accuracy hit/miss gate:

```
Skill_AccuracyHitCheck_Inferred (0x00553240)
  → FUN_005531d0 (0x005531d0)   // packs attacker bonus + skill+0x24 + entities + diag
    → Skill_NonCreatureCastAutoHit (0x004ceba0)  // THIS UNIT — score
  → miss if score <= (roll%100)*0.01f
```

Despite the plate name **"Non-Creature cast (AutoHit)"**, this is **not** structure-only: it is the **shared score kernel** for creature-vs-creature accuracy as well. Non-creature / inanimate paths short-circuit to AutoHit **1.0**.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004ceba0_FUN_004ceba0.md` |
| Annotated | `docs/reconstruction/raw/aa_004ceba0_FUN_004ceba0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Skill_NonCreatureCastAutoHit.cpp` (+ `FUN_004ceba0.cpp`) |
| Function record | `docs/reconstruction/functions/aa_004ceba0_FUN_004ceba0.md` |
| Parent dual | `reviews/A\|B_aa_00553240_Skill_AccuracyHitCheck_Inferred.md` |
| Live Ghidra | `decompile_function` `0x004ceba0` / `0x005531d0` / `0x0056cf00` / `0x004c4070` / `0x004c41c0` / `0x004c4140`; `get_function_callers`; `analyze_function_complete`; `get_function_pcode` high; `read_memory` constants; `audit_globals_in_function`; `get_xrefs_to` `DAT_009cbf7c` / `DAT_00af1b6c` |
| Naming | plate `"Non-Creature cast (AutoHit)"`; registry `Skill_NonCreatureCastAutoHit` |

---

## 3. Signature (from callers — decompiler shows `void`)

```c
// cdecl-style stack args (decompiler lists no formals; recovered from callers + stack layout)
// returns float10 (x87 ST0) — hit probability / accuracy score in ~[0.05, 0.95] or AutoHit 1.0 / fail 0.0
float10 Skill_NonCreatureCastAutoHit(
    float  attackerBonus,   // [esp+4]  — from 005531d0: (float)FUN_004c4140(creature); else 0
    float  unusedZero,      // [esp+8]  — both known callers pass 0; **no body use in high pcode**
    float  skillAccuracy,   // [esp+C]  — skill+0x24 from 005531d0; **no body use in high pcode**
    void  *attacker,        // [esp+10] entity*
    void  *victim,          // [esp+14] entity*
    char  *diagOptional);   // [esp+18] ~reason string buffer (may be NULL)
```

**Caller ABI proof**

| Caller | Site | Args |
|---|---|---|
| `FUN_005531d0` | `0x0055322c` | `(atkShortAsF32\|0, 0, skill+0x24, attacker, victim, diag)` — sole accuracy-chain path |
| `FUN_0056cf00` | `0x0056cf43` | `((float)(int)short(this+0x10c)+*(f32*)(this+0x114), 0, (float)FUN_0056ce90(...), …)` — secondary product path |

High pcode stack refs: **only** `0x0` (mis-tagged first float / score temp), `0x10`, `0x14`, `0x18`. **No** reads of stack `+4/+8/+C` as distinct slots — decompiler collapses first float into `unaff_retaddr`/`stack:0`. Second float and `skillAccuracy` are **unused by body** under current high pcode (skill accuracy still gates **-1.0 auto-hit** in parent `00553240` before this call).

---

## 4. Control flow (sealed)

```
if attacker == NULL:
    diag ← "No Attacker" (12 bytes memcpy-style)
    return g_flOne (1.0)                    // fail-open hit

if victim == NULL:
    diag ← "No Victim"
    return g_flZero (0.0)                   // fail-closed miss

if victim.vfunc(+0x214)() == 0:            // no creature/combatant → inanimate
    diag ← "Victim inanimate (AutoHit)"
    return 1.0

if attacker.vfunc(+0x214)() == 0:          // non-creature caster
    diag ← "Non-Creature cast (AutoHit)"
    return 1.0

// --- creature vs creature path ---
lvlAtk = attacker.vfunc(+0x27c)()
lvlVic = victim.vfunc(+0x27c)()
if attacker.vfunc(+0x210)(0) == 0 OR victim.vfunc(+0x210)(0) == 0:
    // level band only when either side lacks "vehicle component" (vfunc 0x210)
    if (lvlAtk - lvlVic) > 9:  return DAT_009cbf7c          // 0.95
    if (lvlAtk - lvlVic) < -9: return g_flKillSpreeBonusPerStack  // 0.05 (min band)

// residual: get creature, call FUN_004c4070 / FUN_004c41c0 (returns discarded in high pcode)
// base score:
score = *(float*)(attacker.creature + 0x260) + attackerBonus   // FLOAT_ADD @ 004ced06

// more residual vfunc probes (+0x1d4 / +0x214 / +0x210) with discarded returns in high pcode

// clamp (vehicle floor + [min,max]):
// if both have vfunc(+0x210) vehicle AND score < 0.15 → score = 0.15 (DAT_00af1b6c)
// else clamp score into [0.05, 0.95]
return score
```

### Clamp rewrite (from C short-circuit @ `004cef2e`–`004cef60`)

Let `hi = 0.95` (`DAT_009cbf7c`), `lo = 0.05` (`g_flKillSpreeBonusPerStack` @ `0x009cbf80`), `vehFloor = 0.15` (`DAT_00af1b6c`).

| Condition | Result |
|---|---|
| Both sides have vfunc `+0x210` **and** `score < 0.15` | `score = 0.15` |
| Else if `score > 0.95` | `score = 0.95` |
| Else if `score < 0.05` | `score = 0.05` |
| Else | `score` unchanged |

---

## 5. Constants (read_memory sealed)

| Symbol | VA | Bytes (LE) | Value | Role in this unit |
|---|---|---|---|---|
| `g_flOne` | `0x00a0f2a0` | `00 00 80 3f` | **1.0** | AutoHit / null-attacker |
| `g_flZero` | `0x00a0f518` | `00 00 00 00` | **0.0** | null-victim |
| `DAT_009cbf7c` | `0x009cbf7c` | `33 33 73 3f` | **0.95** | max clamp + level-band high; **xrefs only this fn** |
| `g_flKillSpreeBonusPerStack` | `0x009cbf80` | `cd cc 4c 3d` | **0.05** | min clamp + level-band low (**name is XP-domain; reused as float const**) |
| `DAT_00af1b6c` | `0x00af1b6c` | `9a 99 19 3e` | **0.15** | dual-vehicle floor; **xref only this fn** |

Strings:

| VA / label | Text |
|---|---|
| `s_No_Attacker_009cc380` | `"No Attacker"` |
| `s_No_Victim_009cc374` | `"No Victim"` |
| `s_Victim_inanimate_(AutoHit)_009cc358` | `"Victim inanimate (AutoHit)"` |
| `s_Non-Creature_cast_(AutoHit)_009cc33c` | `"Non-Creature cast (AutoHit)"` |

---

## 6. Vfunc / offset map (entity)

| Offset | Role (inferred from use) | Confidence |
|---|---|---|
| vtbl `+0x214` | Get creature/combatant subobject (NULL = non-creature / inanimate) | **High** |
| vtbl `+0x27c` | Level (int) for ±9 band | **High** (also used in DebugDump TargetAccuracy path) |
| vtbl `+0x210`(0) | Optional vehicle/component probe (NULL vs non-NULL gates level band + 0.15 floor) | **Medium** product name |
| vtbl `+0x1d4` | Residual victim side object; checks `*(obj+0x254)!=0` | **Low** (return discarded) |
| creature `+0x260` | `f32` base accuracy contribution | **High** as offset; product field name open |
| creature `+0x13e/+0x146` | shorts inside `FUN_004c4070` (atk-side cap helper) | callee residual |
| creature `+0x142/+0x14a` | shorts inside `FUN_004c41c0` (vic-side cap helper) | callee residual |
| creature `+0x140/+0x148` | shorts inside `FUN_004c4140` (attacker bonus source for 005531d0) | **High** for chain |

---

## 7. Callees

| VA | Role | Return used by score? |
|---|---|---|
| `FUN_004c4070` `0x004c4070` | int helper: clamp(min(short@0x13e,200)+short@0x146, 250) vs vehicle threshold | **No** (high pcode `CALL out=-`; EAX overwritten) |
| `FUN_004c41c0` `0x004c41c0` | twin with shorts @0x142/0x14a | **No** (same) |

DebugDump (`Client_DebugDumpEntityCombatStats`) uses `FUN_004c4070` for **"TargetAccuracy"** display with an explicit level formula — **not** the same composition as this unit's sealed FLOAT_ADD path.

---

## 8. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Exists @ `0x004ceba0`; 2 call xrefs | **Confirmed** | `0055322c`, `0056cf43` |
| Callers: `005531d0`, `0056cf00` only | **Confirmed** | `get_function_callers` |
| Return is accuracy **score** (not damage) | **Confirmed** | parent compares to `(roll%100)*0.01` |
| Null atk → 1.0 / null vic → 0.0 + diag strings | **Confirmed** | body |
| Inanimate victim / non-creature atk → AutoHit 1.0 | **Confirmed** | strings + returns |
| Level Δ>9 → 0.95, Δ<-9 → 0.05 when either lacks vfunc+0x210 | **Confirmed** | body + constants |
| Base score `*(creature+0x260) + attackerBonus` | **High** | FLOAT_ADD pcode `004ced06` |
| Clamp [0.05, 0.95] + dual-vehicle floor 0.15 | **High** | pcode FLOAT_LESS\* + short-circuit rewrite |
| `skill+0x24` unused inside this body | **High** (pcode) | still used by parent for -1 sentinel |
| `FUN_004c4070/41c0` contribute to score | **Falsified under high pcode** | residual risk if FPU side effects exist (unlikely; pure int returns) |
| Product field names for +0x260 / vfuncs | Open | no RTTI on unit |

---

## 9. Accuracy score chain (end-to-end contract)

```
skill.accuracy (f32 @ +0x24)
  if == -1.0f (DAT_00aaa668): HIT (skip score)          // parent 00553240
  else:
    atkBonus = 0
    if attacker.creature:
      atkBonus = (float) FUN_004c4140(creature)         // short@0x140 + short@0x148, clamp [1,250]
    score = Skill_NonCreatureCastAutoHit(atkBonus, 0, skill.accuracy, atk, vic, &diag)
      // AutoHit / level band / (creature+0x260 + atkBonus) / clamp
    thr = (roll % 100) * 0.01f                          // parent
    HIT if score > thr; MISS if score <= thr
```

**Implication for AutoCore:** structure/inanimate targets and non-creature casters always score **1.0** → always beat roll threshold. Creature combat uses clamped score from entity float + attacker short bonus; skill accuracy scalar does **not** enter the score product under sealed pcode (only -1 auto-hit matters for skill+0x24).

---

## 10. Gaps (acceptable)

1. Product C++ name beyond plate `Skill_NonCreatureCastAutoHit`.
2. Semantic names for vfunc `+0x214` / `+0x210` / `+0x27c` / `+0x1d4`.
3. Product field name for creature `+0x260`.
4. Why `FUN_004c4070`/`41c0` are called if returns unused (dead code vs decompiler miss) — treat returns as **non-contributing** until asm proves FPU use.
5. Whether `skillAccuracy` / second float were ever live in another build; high pcode shows no use.
6. Runtime / bit-exact / image diff.
7. Full `FUN_0056cf00` product role (secondary caller).

**Verdict:** **accept-with-gaps** — score-chain position, AutoHit gates, level band, base FLOAT_ADD, clamp constants, and both callers sealed.

---

## Checklist

| Check | Result |
|---|---|
| Exists as function | **Pass** |
| 2 xrefs / 2 callers | **Pass** |
| Score vs damage role | **Pass** (parent compare) |
| AutoHit / null gates | **Pass** |
| Constants 0.05 / 0.15 / 0.95 / 1.0 / 0.0 | **Pass** (`read_memory`) |
| Middle 4070/41c0 product formula | **Gap** (returns unused) |
| Clean ≡ raw CF | **Pass** (scaffold; signature still under-declared) |
