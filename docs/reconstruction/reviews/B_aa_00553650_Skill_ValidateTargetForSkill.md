# Review B (skeptical / adversarial): `aa_00553650` Skill_ValidateTargetForSkill

| Field | Value |
|---|---|
| **Stable ID** | `aa_00553650` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (residual tighten) |
| **Counterpart** | `reviews/A_aa_00553650_Skill_ValidateTargetForSkill.md` |
| **Verdict** | **accept** on wrapper contract + callers; **accept-with-gaps** only on handler catalog |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Plate “returns 1 if valid, 0 if rejected” is a lie | **Falsified attack** — 7/7 callers treat nonzero AL as proceed; plate holds for wrapper |
| 2 | Formal `pTarget` is dead / unused | **Falsified** — asm reads low byte of stack1; stack0 is real target |
| 3 | `FUN_004e2600` is “UI feedback on reject” | **Falsified** — runs on accept path; thiscall list walk on `target+0xB0` |
| 4 | Implements all target filters / outFlags inline | **Holds as false** — single vcall + optional HB re-probe; **no outFlags** |
| 5 | Primary player cast path gate | **Unproven / likely false** — not in RequestCast/QB; used NPC/outpost/reaction/HB |
| 6 | Handler returns 1 means “valid” | **Falsified** — `CMP EAX,1` → `AL=0`; listener treats 1 as reject, 2 as accept |
| 7 | Unbound xrefs lack parents | **Falsified this pass** — Dispatch case 0xC + BeaconShare second site |
| 8 | NPC outFlags from ResolveTargetList are ValidateTarget codes | **Falsified** — orthogonal; ValidateTarget is post-resolve bool |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Wrapper 1=accept / 0=reject | **Confirmed** | Inverted cast allow breaks AI/outpost/reaction |
| stack0=target, this=skill | **Confirmed** | Wrong object in handler |
| Handler code 1 = reject | **Confirmed** | Same |
| Handler code 2 = accept (+HB notify) | **High** | Proven in listener path only |
| List util removes matching nodes | **High** | Side-effect on target HB list |
| All 7 call parents named | **Confirmed** | Incomplete caller map |
| No outFlags from this unit | **Confirmed** | Confusing ResolveTargetList diagnostics |
| Handler class identity | Tentative | Wrong port of legality rules |

---

## 3. Cross-check against raw / asm / live decompile

```
raw decompile (2026-07-23 / still live): incomplete ABI
  — 2-arg vcall, free FUN_004e2600, dead pTarget, fixed CONCAT31(...1)
asm appendix (2026-07-29) + site dumps: AUTHORITY
  — 3-arg vcall; flag used; thiscall list; return ctx byte
listener (0x005532E0) live decomp: CVOGHBSkillBase RTTI; re-call vtbl+0x44(target,skill,hb); codes 1/2
caller site dumps (this pass):
  0057c976 / 0057ca3c: PUSH 0; PUSH target; ECX=skill; CALL; TEST AL / JZ
  00607285 / 006074f2: same pattern inside BeaconShare
  HB ctor: notify=1; (char)!=0 → attach
  NPC: after ResolveTargetList + range; (char)!=0 → CastSkillOnTarget
clean (refreshed): follows asm, not the incomplete raw body alone
```

**Attack on dual-review scaffolding:** 2026-07-23 A/B inverted plate vs body without callers — **insufficient**. 2026-07-29 pass closed polarity; **this residual** closes remaining “unbound” xrefs and outFlags confusion.

---

## 4. Surviving contract for AutoCore

```
ValidateTargetForSkill(skill, target, notifyFlag) -> bool:
  if skill.handler[+0x5F0].vtbl+0x44(target, skill, null) == 1: return false
  scan target.hbList(+0xB0) with Skill_ValidateTarget_HBSkillListener
  return ctx.result   # default true; listener may force false / notify HB

Pair with (orthogonal):
  Skill_LocalCastValidate          — caster gates / eSkillResponses (0=ok style)
  Skill_ResolveTargetList + Filter — TFID list + outFlags bits 1/2/4/8/0x10
  Skill_LocalRangeTargetCheck      — geometry
Do NOT treat this as sole cast authority (server still owns outcomes).
Do NOT map AL onto outFlags or eSkillResponses without an adapter.
```

### Handler codes (as used here)

| EAX | Wrapper / listener effect | Conf |
|---:|---|---|
| **1** | Primary gate → wrapper **0**; listener sets `ctx.result=0` and stop | **Confirmed** |
| **2** | Listener sets `ctx.result=1`; if notify flag, `hb->vtbl+0x18(1,0)` | **High** |
| other ≠1 | Passes primary gate; listener ignores non-{1,2} (no result change from that node) | **High** |

---

## 5. Residual uncertainty (honest)

| # | Item | Blocks wrapper seal? |
|---|---|---|
| R1 | Handler class / per-skill vtbl+0x44 bodies | **No** (port can stub allow-all with risk) |
| R2 | Exact CNDDoubleList product method symbol | No |
| R3 | HB `vtbl+0x18` meaning | Mild (notify path only when flag=1) |
| R4 | Unbound call sites | **Closed** |
| R5 | outFlags coupling | **Closed** (none) |
| R6 | Ghidra decompile lag vs asm | Mild (use asm appendix) |

---

## 6. Concrete checks performed

1. Live decompile `0x00553650` (still incomplete — noted).
2. Live decompile listener `0x005532E0` — string + RTTI + codes 1/2.
3. `get_xrefs_to` → 7 sites; `get_function_callers` → 4 named (under-report).
4. Parent decompiles: `CVOGReaction_Dispatch` (case 0xC owns `0x57c976`/`0x57ca3c`), BeaconShare owns both `0x607285`/`0x6074f2` (next FUN `0x607550`).
5. Site memory dumps: all use `TEST AL` / `(char)!=0` proceed polarity.
6. NPC chain: ResolveTargetList outFlags **before** ValidateTarget bool — no shared storage.
7. Compared plate “feedback on reject” to accept-path list walk — plate clause **rejected**.

---

## 7. Verdict

### **accept** (wrapper + callers + polarity + outFlags orthogonality)

### **accept-with-gaps** (handler implementation catalog only)

Wrapper glue is small, asm-clear, and caller-validated at **every** static xref. Remaining gaps are **downstream handler implementations**, not this unit’s control flow or call graph.

**Port guidance:**

- Return **true/1** to allow, **false/0** to deny.
- Pass **target** as first stack arg, skill as `this`, notify as second stack (0/1).
- Expect side effects on target HB lists when accepting.
- Do not invert polarity to match LocalCastValidate’s `0=ok` without an adapter.
- Do not invent `outFlags` from this return value.
