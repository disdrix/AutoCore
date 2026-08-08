# Dual A/B report — R11-013 OWN-ONLY (`0x00617df0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R11-013**  
**Scope:** VA `0x00617df0` (`aa_00617df0`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs (including sibling ctor `0x00617ad0`).  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs/callees + COL/type_info. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r11_residual_partition_map.md` → **R11-013**.  
**Work item:** Residual dual seal — skills-abilities; parent score `0x005788d0` (`CVOGHBSkillBase_ctor` callee family).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00617df0` CVOGHBSkill_OnHit_SpawnActionsForTargetList_Inferred | **accept-with-gaps** — RTTI OnHit class Confirmed; multi-target spawn CF/ABI/period/Enqueue sealed; method English + call sites open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): subclass-ctor / SpawnEntities-merge / Virus-merge / free-function / decompiler period-overlay / return-as-count / always-Enqueue / uses-virtual-this claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00617df0` — sealed facts

1. **Body:** `0x00617df0`–`0x00617f2c` inclusive (**317 B** / `0x13D`); terminal **`C2 18 00`**; pad `CC` before next.
2. **ABI:** six stack formals; **RET 0x18**; **EAX = 1** on terminator. Virtual **ECX this unused** in body.
3. **Class:** RTTI **Confirmed** `.?AVCVOGHBSkill_OnHit@@` via COL `0x00aadbc4` → type_info `0x00af1d60` on vtbl `PTR_FUN_009d0f1c`.
4. **Role:** virtual multi-target **OnHit HB spawn factory** (vtbl **+0x2c** @ `0x009d0f48`):
   - List stride **0x10**; terminator `{−1,−1,type0}`.
   - `CVOGReaction_ResolveObjectTarget` thiscall with ECX=`*(world+0xe4e8)`.
   - `operator_new(0x6d0)` + `CVOGHBSkillBase_ctor` + install OnHit vtbl.
   - Period from skill float `+0x4c` → action **`+0x6c0`** (int trunc) / **`+0x6c4`** (u8 flag).
   - Owner `+0x18` non-null → Enqueue `*(world+0xe4ec)` + Start; else `vtbl[0](1)` (`FUN_00651190`).
5. **Xrefs:** 1 DATA (vtbl); **0** CODE callers.
6. **Callees:** ResolveObjectTarget, operator_new, CVOGHBSkillBase_ctor, CVOGHBList_Enqueue, CVOGHBBase_Start, scalar dtor.
7. **Sibling (not OWN):** true ctor `FUN_00617ad0` same vtbl + period pattern.
8. **Name:** `CVOGHBSkill_OnHit_SpawnActionsForTargetList_Inferred` (Ghidra `FUN_00617df0`). Method English open → `_Inferred`.
9. **Decompile ≡ raw CF**; assembly corrects Resolve thiscall + period offsets (decompiler overlay wrong).
10. **Partition parent** `0x005788d0` is **callee** (base ctor), not live CODE parent.

### Gaps

- Product method English for slot +0x2c.  
- Virtual invokers / target-list producers.  
- Null-`operator_new` crash path.  
- Runtime / bit-exact / differential.  
- Sibling ctor dual is separate OWN (R11-012).

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00617df0_CVOGHBSkill_OnHit_SpawnActionsForTargetList_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00617df0_CVOGHBSkill_OnHit_SpawnActionsForTargetList_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify append) | `docs/reconstruction/raw/aa_00617df0_FUN_00617df0.md` |
| Annotated | `docs/reconstruction/raw/aa_00617df0_FUN_00617df0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/CVOGHBSkill_OnHit_SpawnActionsForTargetList_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00617df0.cpp` |
| Function | `docs/reconstruction/functions/aa_00617df0_FUN_00617df0.md` |
| Function named | `docs/reconstruction/functions/aa_00617df0_CVOGHBSkill_OnHit_SpawnActionsForTargetList_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
CVOGHBSkill_OnHit  vtbl PTR_FUN_009d0f1c
  COL 0x00aadbc4 → type_info 0x00af1d60  ".?AVCVOGHBSkill_OnHit@@"
  [+0x00] FUN_00651190  scalar-deleting dtor
  [+0x2c] FUN_00617df0  SpawnActionsForTargetList  [OWN R11-013]
  ctor:   FUN_00617ad0  (installs vtbl + period)   [R11-012 OWN; not this unit]
            └─ CVOGHBSkillBase_ctor 0x005788d0     [dualed; partition parent]

Contrast — do not merge:
  Skill_HB_SpawnEntities  vtbl 009d0ec4  (ctor 00614dc0 / execute 00615020)
  CVOGHBSkill_Virus       vtbl 009d14bc  (size 0x6e0)
```

Partition host "skills-abilities" / parent `0x005788d0` names the **base-ctor family**, not a direct CODE caller of this virtual.

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00617df0-r11-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00617df0` | Port as **OnHit multi-target HB spawner**: list stride 0x10, resolve via reaction at world+0xe4e8, construct 0x6d0 OnHit actions, Enqueue world+0xe4ec then Start. RET 0x18; return always 1 on terminator. |
| Distinct from | SpawnEntities execute `00615020`; Virus ctor/OnHB; true OnHit ctor `00617ad0`. |
| Pair with | dualed `CVOGHBSkillBase_ctor`; residual ctor `00617ad0`; ResolveObjectTarget; HB list Enqueue/Start. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md` / `NAMING_REGISTRY.md` / coverage ledgers — **not touched** by this agent.
- Name to register: `CVOGHBSkill_OnHit_SpawnActionsForTargetList_Inferred` @ `0x00617df0` / `aa_00617df0` (class `CVOGHBSkill_OnHit` Confirmed).
- Verdict: **accept-with-gaps**; Terminal **false**.

---

## Process

- OWN VA only (`0x00617df0`); no Launcher; no parent ledger edits.
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + RTTI walk + callee decompile. **No** `disassemble_bytes`.
- Dual A (fidelity) + B (adversarial) both filed.
- Scaffold raw body preserved; re-verify **appended** only.
- Clean source uses meaningful name; machine ABI corrections (Resolve thiscall; +0x6c0/+0x6c4; RET 0x18; ECX unused).
- Odd behavior preserved: ignores virtual this; unbounded loop without terminator; null-new UB; return always 1.
- `_Inferred` on method English. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
