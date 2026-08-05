# Function record: Skill_ApplyEffectsOnTarget_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005538a0` |
| **Canonical name** | `Skill_ApplyEffectsOnTarget_Inferred` |
| **Prior** | `FUN_005538a0` / alias `Named_CalleeOf_Client_RecvSkillStatusEffect_005538a0` |
| **Address** | `0x005538a0`–`0x00553c46` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Calling convention** | MSVC `__thiscall` (this = skill runtime) |
| **System** | skills-abilities |
| **Name confidence** | **Probable** — multi-caller skill-cast graph; combat event dispatch; no product string |
| **Completion status** | **Human-refined + dual A/B residual strengthen** (2026-07-29) |
| **Bit-for-bit / runtime / diff** | Open (deferred) |
| **UF** | UF-013 **closed** (dual/map `_Inferred`; PDB product still open) |

---

## 1. Purpose

Skill **thiscall** that resolves a **primary** TFID target and applies combat/skill effects: start/fail/hit combat events via entity `vtbl+0x238` (codes **4 / 0xc / 0xe / 5 / 6**), optional accuracy check (`skill+0x624` bit0 → `FUN_00553240` + miss floater), skill-handler invoke (`skill+0x5f0` vtbl `+0x2c`), and conditional power drain. Return **1** applied/ok, **0** fail/miss/no-world.

Closes residual name open from `Skill_ApplyStatusEffectLocal` / `Client_RecvSkillStatusEffect` duals (UF-013).

**Not** network emit, not S2C parse, not delayed HB ctor — pure apply core after targets are ready.

---

## 2. Signature (decompiler-derived)

```c
unsigned int /*__thiscall*/ Skill_ApplyEffectsOnTarget_Inferred(
    void *skill,           // this — skill runtime
    void *caster,          // may be null
    void *world,           // world+0xe4e8 gate
    void *targetTfid,      // TFID* primary (not multi-list walk in body)
    void *posOrArg,        // forwarded to handler
    unsigned int randomSeed);
```

---

## 3. Behavior outline

1. If `world==0` or `*(world+0xe4e8)==0` → return **0**
2. `target = CVOGReaction_ResolveObjectTarget(tfid)`
3. If caster: event **4** (start); if `vtbl+0x214()` non-null → `FUN_004c2f20(skillId)`
4. If handler (`skill+0x5f0`) and target:
   - If `skill+0x624&1`: RNG slice + accuracy; miss → floater + `miss`; hit → handler; always then power LAB
   - Else: handler; **only on success** enter power LAB; on fail skip drain
5. Power LAB (caster): skip if plant `+0x6b4>0`; else plant `vtbl+0xb0(skill+8)`
6. If miss or handler fail: caster event **0xc** → return **0**
7. If target: caster event **0xe**; if type `*(target[0x2a]+0x38)==0xe` and target event **6** nonzero → return **1**; else target event **5**
8. Return **1**

### Power-drain CF matrix (sealed)

| Path | Power drain LAB? |
|---|---|
| No handler or null target | Yes |
| Accuracy + miss | Yes |
| Accuracy + hit (handler any) | Yes |
| No accuracy + handler ok | Yes |
| No accuracy + handler fail | **No** |

---

## 4. Offsets (body)

| Off | Role |
|---:|---|
| skill+0x08 | u16 → plant drain arg |
| skill+0x14 | s16 event arg |
| skill+0x28 | f32 ROUND → fail/success event arg |
| skill+0x174 / +0x5f6 | s16 rank sum |
| skill+0x5f0 | handler* |
| skill+0x5fc | skillId |
| skill+0x624 bit0 | accuracy enable |
| entity+0x160 | TFID 16 B |
| world+0xe4e8 | world live gate |
| plant+0x6b4 | drain suppress if &gt;0 |
| `DAT_009d1ca8` | invalid TFID fallback for floater from-field |

---

## 5. Callers / callees

### Callers (Confirmed ×5)

| Caller | VA | Call site |
|---|---|---|
| `Skill_ApplyStatusEffectLocal` | `0x0051aa00` | `0x0051ae58` |
| `Client_RecvSkillStatusEffect` | `0x00811170` | `0x00811638` |
| `FUN_00606180` (active-skill HB fire) | `0x00606180` | `0x006061d2` |
| `FUN_00514e70` | `0x00514e70` | `0x00514fd2` |
| `FUN_00620480` | `0x00620480` | `0x006209f3` |

**Caller notes:**
- ApplyStatusEffectLocal: only when delay &lt; 1
- Recv: null source + status `'c'`
- HB fire: skill overlay at HB+0x24; requires LocalCastValidate==0
- `FUN_00514e70`: self TFID as target; skill+0x615 bit0; may HB-delay instead
- `FUN_00620480`: skill this = **ResolveSkillTargets result**, not always original skill*

### Callees (Confirmed)

| Address | Name |
|---|---|
| `0x004bae70` | `CVOGReaction_ResolveObjectTarget` |
| `0x00402620` | `Client_EnqueueCombatFloater_INFERRED` |
| `0x00553240` | `Skill_AccuracyHitCheck_Inferred` (accuracy) |
| `0x0058ab60` | `FUN_0058ab60` (RNG slice) |
| `0x004c2f20` | `FUN_004c2f20` |
| `0x0048981c` | `operator_delete[]` |

---

## 6. Related artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005538a0_FUN_005538a0.md` |
| Annotated | `docs/reconstruction/raw/aa_005538a0_Skill_ApplyEffectsOnTarget_Inferred.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Skill_ApplyEffectsOnTarget_Inferred.cpp` |
| Dual A | `docs/reconstruction/reviews/A_aa_005538a0_Skill_ApplyEffectsOnTarget_Inferred.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_005538a0_Skill_ApplyEffectsOnTarget_Inferred.md` |
| Chain | `docs/reconstruction/reviews/CHAIN_2026-07-29_s2c_2031_skillstatuseffect.md` |
| Superseded stub | `docs/reconstruction/functions/aa_005538a0_FUN_005538a0.md` |
| Scratch | `tmp/a_005538a0.md` |

---

## 7. Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | **High** / Confirmed |
| Skill thiscall (offsets +0x5fc/+0x5f0/+0x624) | **High** |
| Multi-caller skill-cast role | **Confirmed** |
| Power-drain CF asymmetry | **Confirmed** |
| Floater layout + invalid TFID global | **High** / Confirmed |
| Product original name | Inferred only (`_Inferred`) |
| Combat event code English | Tentative |
| Multi-TFID list walk inside this body | **No** — primary TFID only; handler may walk |
| Overall | **Human-refined; dual residual strengthen sealed; runtime open** |

---

## 8. Open questions

1. Product / mangled C++ name (none recovered).
2. English labels for combat events 4 / 5 / 6 / 0xc / 0xe.
3. Handler multi-target walk (out of unit).
4. Residual FUN product names for accuracy / HB / side helpers.
5. Runtime cast observation / bit-exact.
