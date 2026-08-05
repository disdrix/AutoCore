# Review A (reconstruction fidelity): `aa_005538a0` Skill_ApplyEffectsOnTarget_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005538a0` |
| **VA** | `0x005538a0`–`0x00553c46` |
| **Canonical name** | `Skill_ApplyEffectsOnTarget_Inferred` |
| **Review date** | `2026-07-29` (dual residual **strengthen**) |
| **Reviewer role** | Reconstruction fidelity |
| **Counterpart** | `reviews/B_aa_005538a0_Skill_ApplyEffectsOnTarget_Inferred.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** (role + CF + callers sealed; event-code English + product name open) |

---

## 1. Purpose

Skill **`__thiscall`** (ECX = skill runtime) that resolves a **single** primary TFID target and applies combat/skill effects:

1. World gate `world && world+0xe4e8`
2. `CVOGReaction_ResolveObjectTarget` on `targetTfid`
3. Optional caster combat-event **4** (start) + `FUN_004c2f20(skillId)` side path
4. Optional accuracy (`skill+0x624` bit0 → `FUN_0058ab60` + `FUN_00553240`) with miss floater
5. Handler invoke `skill+0x5f0` → vtbl **`+0x2c`**
6. Conditional power-drain via caster vtbl `+0x210` / `+0x214` / plant `+0xb0`
7. Fail → caster event **0xc** return **0**; success → caster **0xe**, target **6** (type `0xe`) or **5**, return **1**

Closes UF-013 dual/map product-name residual as **`_Inferred`** (no string/RTTI). Not the S2C orchestrator (`Skill_ApplyStatusEffectLocal`); this is the **effect/combat apply core**.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005538a0_FUN_005538a0.md` |
| Annotated | `docs/reconstruction/raw/aa_005538a0_Skill_ApplyEffectsOnTarget_Inferred.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Skill_ApplyEffectsOnTarget_Inferred.cpp` |
| Function record | `docs/reconstruction/functions/aa_005538a0_Skill_ApplyEffectsOnTarget_Inferred.md` |
| Prior dual | this file + B (first pass 2026-07-29) |
| Chain | `reviews/CHAIN_2026-07-29_s2c_2031_skillstatuseffect.md` (UF-013 closed → prefer `_Inferred`) |
| Live Ghidra | `decompile_function`, `get_function_callers`, `get_function_callees`, `analyze_function_complete`, `read_memory` `DAT_009d1ca8`, caller decompiles `00514e70` / `00606180` / `00620480` |
| Scratch | `tmp/a_005538a0.md` |

---

## 3. Signature (sealed)

```c
// __thiscall  ECX = skill runtime
unsigned int Skill_ApplyEffectsOnTarget_Inferred(
    void *skill,          // this — skill id +0x5fc, handler +0x5f0, flags +0x624
    void *caster,         // may be null (Recv null-source 'c')
    void *world,          // world+0xe4e8 gate
    void *targetTfid,     // TFID* primary (lo/hi/bGlobal@+8) — not a multi-list walk here
    void *posOrArg,       // forwarded to handler vtbl+0x2c
    unsigned int randomSeed); // FUN_0058ab60 when accuracy bit set
// returns 1 = ok, 0 = fail/miss/no-world  (AL; high bytes may be junk from prior EAX)
```

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Function exists @ `0x005538a0`–`0x00553c46` | **Confirmed** | Ghidra body range |
| Skill thiscall (ECX skill) | **High** | offsets +0x5fc/+0x5f0/+0x624/+0x5f6/+0x174 match skill layout across units |
| Exactly **5** callers | **Confirmed** | `get_function_callers` + 5 xrefs |
| Call-site xrefs | **Confirmed** | `0x00514fd2`, `0x0051ae58`, `0x00811638`, `0x006061d2`, `0x006209f3` |
| World gate `+0xe4e8` → return 0 | **Confirmed** | early return `(world & ~0xff)` style clear AL |
| Primary TFID → `ResolveObjectTarget` `0x004bae70` | **Confirmed** | sole resolve in body |
| Combat event immediates 4 / 0xc / 0xe / 5 / 6 | **Confirmed** | body literals on vtbl+0x238 |
| Rank arg = `(short)(skill+0x5f6 + skill+0x174)` | **High** | same sum as 0x2031 packer / ApplyStatusEffectLocal |
| Event skill id = `skill+0x5fc`; short arg = `skill+0x14` | **High** | body |
| Fail/success events pass `ROUND(skill+0x28)` in 6th arg | **Confirmed** | events 0xc/0xe/5/6 (not event 4) |
| Accuracy optional `skill+0x624 & 1` | **High** | bit0 only |
| Miss → floater + fail; hit → handler | **High** | `FUN_00553240` returns 0 miss |
| Handler `*(skill+0x5f0)` vtbl **+0x2c** | **High** | args `(caster, skill, world, targetTfid, posOrArg, seed)` |
| Floater entry ~0x38: from TFID, to TFID, flag@+0x2a=1 | **High** | 14 dwords zeroed; from = caster+0x160 or `DAT_009d1ca8` |
| `DAT_009d1ca8` = invalid TFID `ff..ff 00..00` | **Confirmed** | `read_memory` 16 bytes |
| Target object TFID at obj+0x160 (`int[0x58..0x5b]`) | **High** | same index as caster TFID packing |
| Target type probe `*(target[0x2a]+0x38) == 0xe` → event 6 | **Confirmed** | CF; type 0xe family (vehicle/world object) |
| Power drain skip when plant `+0x6b4` (`[0x1ad]`) &gt; 0 | **High** | vtbl+0x210(0) result |
| **Power-drain CF asymmetry** | **Confirmed** | see §6 |
| Null caster allowed | **Confirmed** | body + Recv call site |
| Multi-TFID list walk **in this body** | **Falsified** | single Resolve; handler may walk |
| Server damage authority | **Falsified** | client events + handler only |
| Product C++ name | Inferred | no string/RTTI; keep `_Inferred` |
| Event-code English (start/hit/miss/…) | Tentative | codes sealed; labels open |

---

## 5. Call-graph contract (callers sealed)

| Caller | VA | Call site | Args / gate |
|---|---|---|---|
| `Skill_ApplyStatusEffectLocal` | `0x0051aa00` | `0x0051ae58` | delay &lt; 1 immediate apply; skill this, packet caster/world/list/pos/seed |
| `Client_RecvSkillStatusEffect` | `0x00811170` | `0x00811638` | source unresolved && status **`'c'`** → ResolveSkillTargets then this (**caster may be null**) |
| `FUN_00606180` (active-skill HB fire) | `0x00606180` | `0x006061d2` | after `Skill_LocalCastValidate==0`; skill = HB+0x24, caster=HB+0x18, world=HB+0x654, tfid*=HB+0x660, pos=HB+0x66c, seed=HB+0x670 |
| `FUN_00514e70` | `0x00514e70` | `0x00514fd2` | self-target when skill+0x615 bit0; target TFID = **caller entity** `param_1[0x58..0x5b]`; only if world non-null; delay/charge short &gt;0 uses WakeupSkill HB instead |
| `FUN_00620480` | `0x00620480` | `0x006209f3` | after spawn/HB setup; if `skill+0x150` non-null → ResolveSkillTargets → this on **resolved skill** `puVar2` as this; target from spawned entity TFID |

**Callees (Confirmed):**

| Address | Name | Role |
|---|---|---|
| `0x004bae70` | `CVOGReaction_ResolveObjectTarget` | primary TFID → object* |
| `0x00402620` | `Client_EnqueueCombatFloater_INFERRED` | miss floater queue |
| `0x00553240` | `Skill_AccuracyHitCheck_Inferred` | accuracy hit/miss (char) |
| `0x0058ab60` | `FUN_0058ab60` | RNG slice from seed |
| `0x004c2f20` | `FUN_004c2f20` | side effect on skillId when caster vtbl+0x214 non-null |
| `0x0048981c` | `operator_delete[]` | free accuracy slice |

---

## 6. Control flow: clean ≡ raw (residual strengthen)

| Stage | Match |
|---|---|
| World gate → return 0 | **Yes** |
| ResolveObjectTarget | **Yes** |
| Caster event 4 + optional FUN_004c2f20 | **Yes** |
| Handler null **or** target null → skip apply, still power path | **Yes** |
| Accuracy bit0 → roll → miss floater / handler | **Yes** |
| **Power drain only via LAB path** (see below) | **Yes** (clean fixed 2026-07-29 strengthen) |
| Fail flags → event 0xc → return 0 | **Yes** |
| Success → event 0xe; type 0xe → event 6 early-out; else event 5; return 1 | **Yes** |
| No invented multi-target walk | **Yes** |

### Power-drain CF (sealed)

| Path | Runs LAB power drain (`vtbl+0x210/+0x214/+0xb0`)? |
|---|---|
| No handler **or** null target | **Yes** |
| Accuracy bit set + miss | **Yes** |
| Accuracy bit set + hit (handler 0 **or** 1) | **Yes** |
| No accuracy + handler success | **Yes** |
| No accuracy + handler fail (returns 0) | **No** — skip drain, go fail event 0xc |

Power skip inside LAB: if `vtbl+0x210(0)` non-null **and** `result[0x1ad]` (`+0x6b4`) **&gt; 0**, skip drain entirely.

---

## 7. Skill / entity offsets used (body)

| Off | Width | Role |
|---:|---|---|
| skill+0x08 | u16 | forwarded to plant vtbl+0xb0 |
| skill+0x14 | s16 | event arg / charge-related |
| skill+0x28 | f32 | ROUND → event 6th arg on fail/success |
| skill+0x174 | s16 | rank component |
| skill+0x5f0 | ptr | handler object |
| skill+0x5f6 | s16 | rank component |
| skill+0x5fc | u32 | skillId |
| skill+0x624 | u8 | bit0 = accuracy check |
| entity+0x160 | 16 B | TFID (floater from/to) |
| world+0xe4e8 | int | non-zero required |
| plant+0x6b4 | int | &gt;0 skips power drain |

---

## 8. Gaps (acceptable)

1. Product C++ name — keep `_Inferred` (UF-013 dual closed; PDB still open).
2. Exact player-facing English for combat event codes 4 / 5 / 6 / 0xc / 0xe.
3. Whether handler walks multi-TFID list (out of unit).
4. Residual names: `FUN_0058ab60`, `FUN_00606180` / `FUN_006061e0`, `FUN_00514e70`, `FUN_00620480`, `FUN_004c2f20` (`0x00553240` dual-sealed as `Skill_AccuracyHitCheck_Inferred`).
5. Runtime cast capture / bit-exact / image diff.

**Verdict:** **accept-with-gaps** — dual residual strengthen seals CF asymmetry, caller arg contracts, floater/global, callees; role rename remains `_Inferred`.

---

## Checklist

| Check | Result |
|---|---|
| Exists as function | **Pass** |
| 5 callers + 5 xrefs | **Pass** |
| Return 1/0 contract | **Pass** |
| Clean matches CF (incl. power-drain) | **Pass** (post-fix) |
| Dual B counterpart | **Pass** |
| UF-013 product name | **Closed** as `_Inferred` |
| Verdict | **accept-with-gaps** |
