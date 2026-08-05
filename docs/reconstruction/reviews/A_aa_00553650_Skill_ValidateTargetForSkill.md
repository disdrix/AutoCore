# Review A (reconstruction fidelity): `aa_00553650` Skill_ValidateTargetForSkill

| Field | Value |
|---|---|
| **Stable ID** | `aa_00553650` |
| **VA** | `0x00553650` |
| **Canonical name** | `Skill_ValidateTargetForSkill` |
| **Review date** | `2026-07-29` (residual tighten pass) |
| **Reviewer role** | Independent reconstruction review (faithfulness of clean / annotated to asm+raw) |
| **Counterpart** | `reviews/B_aa_00553650_Skill_ValidateTargetForSkill.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept** (wrapper ABI + callers + outFlags orthogonality sealed; handler catalog open) |

---

## 1. Purpose

Thin skill-side target legality wrapper. Loads handler at `skill+0x5F0`, invokes virtual `+0x44` with `(target, skill, 0)`. Rejects immediately if handler returns **1**. Otherwise walks the target’s HB listener list at `target+0xB0` through `CNDDoubleList_InvokePredicateAndRemove_Inferred` + `Skill_ValidateTarget_HBSkillListener`, returning a context result byte (**1** accept / **0** reject). Does **not** implement range math, TFID list builds, or `outFlags` writes (those live in `LocalRangeTargetCheck` / `ResolveTargetList` / Filter / Gather).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00553650_Skill_ValidateTargetForSkill.md` (+ 2026-07-29 asm appendix) |
| Annotated | `docs/reconstruction/raw/aa_00553650_Skill_ValidateTargetForSkill.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Skill_ValidateTargetForSkill.cpp` |
| Function record | `docs/reconstruction/functions/aa_00553650_Skill_ValidateTargetForSkill.md` |
| Listener decompile | Ghidra `Skill_ValidateTarget_HBSkillListener` @ `0x005532E0` |
| Callers (live xrefs) | 7 UNCONDITIONAL_CALL sites (all parents sealed this pass) |
| Related residual | `reviews/a_00550300.md` (outFlags ownership — no ValidateTarget writes) |

**Live re-decompile of wrapper + listener + full caller parents performed.** Ghidra decompile of the wrapper still drops the third handler arg / flag formal / thiscall list this — **assembly appendix remains ABI authority**.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `this` = skill; stack0 = target; stack1 = flag byte | **Confirmed** | Asm + all 7 call sites |
| Handler `skill+0x5F0`, vtbl `+0x44` | **Confirmed** | Load/call |
| Handler third arg `0` on primary call | **Confirmed** | `PUSH 0` at every site before skill/target order |
| Handler result `1` → wrapper `AL=0` | **Confirmed** | `CMP EAX,1` / `JZ` → `XOR AL,AL` |
| Accept path `thiscall` on `target+0xB0` | **Confirmed** | `MOV ECX,[EDI+0xB0]` |
| Predicate is `Skill_ValidateTarget_HBSkillListener` | **Confirmed** | `PUSH 0x5532E0` + decompile |
| Wrapper return `1` = valid for callers | **Confirmed** | All sites `TEST AL,AL` / `(char)!=0` → proceed |
| Listener RTTI `CVOGHBSkillBase` + no-base-class string | **Confirmed** | Decompile of `0x005532E0` |
| Handler codes **1=reject**, **2=accept** (listener path) | **Confirmed** / **High** | Gate uses 1; listener 1→result0, 2→result1 |
| Does **not** write `outFlags` | **Confirmed** | No out-param; orthogonal to ResolveTargetList |
| Not player RequestCast primary gate | **High** | Not in RequestCast/QB; used NPC/outpost/reaction/HB |
| Clean matches asm CF | **High** | Param roles + list walk corrected vs old scaffold |

---

## 4. Control flow: clean ≡ asm

| Stage | Match |
|---|---|
| Load handler → vcall +0x44 `(target,skill,0)` | **Yes** |
| `rc==1` → return 0 | **Yes** |
| Else pack ctx → list walk → return `ctx.result` | **Yes** |
| No invented range/TFID/`outFlags` in wrapper | **Yes** |

Legacy 2026-07-23 clean that treated formals as `(pSkill,pTarget)` with dead `pTarget` and free-function `FUN_004e2600` is **superseded**.

---

## 5. Caller seal (all xrefs)

| Call site VA | Parent | notify | Polarity test | On accept |
|---|---|---:|---|---|
| `0x005789F3` | `CVOGHBSkillBase_ctor` `0x005788D0` | **1** | `(char)rc != 0` | AttachOwner + SetPeriod |
| `0x0057C976` | `CVOGReaction_Dispatch` `0x0057C500` case **0xC** (single-target skill cast) | **0** | `TEST AL` / `JZ` skip | `CastSkillOnTarget` |
| `0x0057CA3C` | same Dispatch case **0xC** (multi-target TFID collect loop) | **0** | `TEST AL` / `JZ` skip | append TFID slot |
| `0x005D1882` | `NPC_TryCastSkillFromSet` `0x005D1280` | **0** | `(char)rc != 0` after range ok (or self/ground bypass) | `CastSkillOnTarget` |
| `0x00606EB6` | `Outpost_CastSkillsForFaction` `0x00606D70` | **0** | `(char)rc != 0` | TFID batch + cast |
| `0x00607285` | `Outpost_CastSkillsForBeaconShare` `0x006070E0` | **0** | `TEST AL` / `JZ` | TFID batch + cast |
| `0x006074F2` | same BeaconShare (second site in body; next FUN @ `0x00607550`) | **0** | `TEST AL` / `JZ` | TFID batch + cast |

**Prior open “unbound call sites”** (`0x0057C976` / `0x0057CA3C` / `0x006074F2`) **sealed**: Dispatch case 0xC and BeaconShare respectively. Ghidra `get_function_callers` under-reports Dispatch (mid-function xrefs without name on some entries); `get_xrefs_to` + parent decompile close them.

### NPC / outFlags interaction (static)

`NPC_TryCastSkillFromSet` calls **`Skill_ResolveTargetList`** (writes resolve `outFlags`) **before** `Skill_ValidateTargetForSkill`. ValidateTarget return is a **separate boolean gate** — it does not consume or produce those bits. Failures of ValidateTarget skip cast silently (no flag OR from this unit).

`Skill_ResolveTargetList` body does **not** call ValidateTarget (see dual residual `a_00550300.md`).

---

## 6. Gaps / open (acceptable for wrapper accept)

1. Product type name of `skill+0x5F0` handler class.
2. Full set of vtbl+0x44 method bodies per skill family (catalog).
3. Exact product name of `CNDDoubleList_*` method beyond `_Inferred`.
4. HB `vtbl+0x18(1,0)` semantics on notify path (listener only).
5. Live Ghidra decompile still incomplete vs asm (documented; not a port blocker).

**Verdict:** **accept** — wrapper ABI, AL polarity, handler code **1**, all callers, and outFlags orthogonality sealed statically. Residual is handler catalog, not glue CF.

---

## Checklist (reviewer)

| Check | Result |
|---|---|
| Clean CF matches asm | **Pass** |
| Return polarity matches callers | **Pass** (7/7) |
| Formal roles corrected | **Pass** |
| Listener named with string/RTTI evidence | **Pass** |
| All call-site parents named | **Pass** (sealed this pass) |
| outFlags non-writer | **Pass** |
| Handler identity sealed | **Open** (documented) |
| Verdict | **accept** |
