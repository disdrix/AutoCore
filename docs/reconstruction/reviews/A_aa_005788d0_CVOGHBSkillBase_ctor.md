# Review A (reconstruction fidelity): `aa_005788d0` CVOGHBSkillBase_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_005788d0` |
| **VA** | `0x005788d0` |
| **Canonical name** | `CVOGHBSkillBase_ctor` |
| **Review date** | `2026-07-29` (dual residual strengthen) |
| **Reviewer role** | Independent reconstruction review (faithfulness of clean / annotated to decompile + RTTI + ValidateTarget attach) |
| **Counterpart** | `reviews/B_aa_005788d0_CVOGHBSkillBase_ctor.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept** (name Confirmed; ValidateTarget attach dual residual **sealed**) |

---

## 1. Purpose

Skill heartbeat base constructor. Builds a `CVOGHBSkillBase` on top of `CVOGHBBase`: installs RTTI-backed vtable, copies the skill runtime blob into the HB, validates the cast **target** with `Skill_ValidateTargetForSkill(..., notify=1)`, and on accept attaches **that same target** as HB owner and starts the period counter. Type tag `+0x1c = 1` enables later `Skill_ValidateTarget_HBSkillListener` RTTI recognition.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005788d0_FUN_005788d0.md` (+ RTTI append) |
| Annotated | `docs/reconstruction/raw/aa_005788d0_CVOGHBSkillBase_ctor.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBSkillBase_ctor.cpp` |
| Function record | `docs/reconstruction/functions/aa_005788d0_CVOGHBSkillBase_ctor.md` |
| RTTI chain | COL `0x00aaede0` → type_info `0x00af8cec` → `".?AVCVOGHBSkillBase@@"` (live `read_memory`) |
| ValidateTarget dual | `reviews/A|B_aa_00553650_Skill_ValidateTargetForSkill.md` |
| Listener | `Skill_ValidateTarget_HBSkillListener` @ `0x005532e0` (live decompile) |
| Attach / period | `CVOGHBBase_AttachOwnerObject` `0x005083b0`; `SetPeriodAndCounter` `0x005081a0` |
| Callers | 14 subclass ctors (Ghidra `get_function_callers`) |

**Live re-decompile + RTTI memory read + callee decompile performed** (not review-from-scaffold-only).

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Product class = `CVOGHBSkillBase` | **Confirmed** | COL → type_info name string (re-read) |
| Vtbl = `PTR_FUN_009d3fdc` | **Confirmed** | store after base ctor; COL dword immediately before vtbl |
| Calls `Skill_ValidateTargetForSkill(this+0x24, target, 1)` | **Confirmed** | decompile; notify=1 |
| Accept → AttachOwner(**target**), not source | **Confirmed** | same `param_5`; `param_2` never to Attach |
| Accept → SetPeriodAndCounter(period, true) | **Confirmed** | period from `this+0x3C`, floor 0→1 |
| Type tag `this+0x1C = 1` | **Confirmed** | `param_1[7]=1`; listener requires `+0x1c==1` |
| Prior name `CVOGHBSkillCast_ctor_Inferred` wrong | **Confirmed** | no RTTI `CVOGHBSkillCast` |
| Invalid TFID sentinel layout | **Confirmed** | `DAT_009d3f88` = `{FFFFFFFF,FFFFFFFF,0,0}` |
| Blob size `0x18c` dwords → `+0x24` | **Confirmed** | copy loop |
| Full field semantics of arg4/arg7 | Tentative | storage sealed; product English open |
| `FUN_0058ab60` product name | Tentative | behavior High: `operator_new(0x4b0)` + 300-dword table fill |

---

## 4. Control flow: clean ≡ decompile

| Stage | Match |
|---|---|
| CVOGHBBase_ctor → vtbl store | **Yes** |
| Zero tails / type tag `this[7]=1` | **Yes** |
| Copy 0x18c dwords skill blob → this+9 | **Yes** |
| Source TFID / alt TFID blocks | **Yes** |
| ValidateTarget → optional attach/period | **Yes** |
| Attach subject = ValidateTarget target | **Yes** (residual strengthen) |
| Period floor + both period fields | **Yes** |

---

## 5. Dual residual seals (this pass)

### R1 — Attach subject is target (was soft)

| Item | Sealed |
|---|---|
| `Skill_ValidateTargetForSkill(this+9, param_5, 1)` | **Confirmed** |
| `CVOGHBBase_AttachOwnerObject(this, param_5)` on accept | **Confirmed** |
| `param_2` (source) used only for TFID seeds | **Confirmed** |
| Post-attach TFID `this+0x678` from `this[+0x18]+0x160` | **Confirmed** |

### R2 — Type tag ↔ listener gate (was soft)

| Item | Sealed |
|---|---|
| Ctor writes `+0x1c = 1` | **Confirmed** |
| Listener requires `hb+0x1c == 1` before RTTI | **Confirmed** (`0x005532e0`) |
| Listener RTTI target class `CVOGHBSkillBase` | **Confirmed** |

### R3 — notify=1 purpose (was soft)

| Item | Sealed |
|---|---|
| Third formal is notify flag (ValidateTarget dual) | **Confirmed** (asm dual `aa_00553650`) |
| Listener: handler code **2** + notify → `hb.vtbl+0x18(1,0)` | **High** |
| Ctor forces notify=1 so accept-side HB notify can fire | **High** |

### R4 — Period / accept side effects

| Item | Sealed |
|---|---|
| Period source `this+0x3C` (blob-relative `+0x18`) | **Confirmed** |
| Floor: `0 → 1` | **Confirmed** |
| `SetPeriodAndCounter(this, period, true)` writes `+0x0C` and `+0x10` | **Confirmed** |
| `this+0x08 = this+0x40` on accept | **Confirmed** (English open) |

### R5 — Reject path

| Item | Sealed |
|---|---|
| No AttachOwner / no SetPeriod | **Confirmed** |
| `pOwner` remains 0 from base ctor | **Confirmed** |
| Returns `this` either way | **Confirmed** |
| Caller free-on-reject | **Open** (out of unit) |

---

## 6. Gaps / open (acceptable)

1. Product meaning of `arg4` / `arg7` / `FUN_0058ab60` buffer (behavior of `0058ab60` High: seeded 300-dword clone into `0x4b0` heap).
2. Full skill-blob field glossary (shared with other skill units; not unique to ctor).
3. Product name of `this+0x08` accept copy from `+0x40`.
4. Whether failed ValidateTarget leaves a live but non-attached HB for caller free (static: returned; free site not in unit).
5. Subclass product names for the 14 re-vtbl callers (catalog of addresses sealed; English open).

**Verdict:** **accept** — RTTI name sealed; ValidateTarget construction **attach dual residual sealed** (target attach + type tag + notify + period).

---

## Checklist (reviewer)

| Check | Result |
|---|---|
| RTTI name vs clean symbol | **Pass** |
| Clean CF matches decompile | **Pass** |
| ValidateTarget call site sealed | **Pass** |
| Attach subject = target sealed | **Pass** |
| Type tag ↔ HBSkillListener sealed | **Pass** |
| Supersedes CVOGHBSkillCast scaffold | **Pass** |
| Verdict | **accept** |
