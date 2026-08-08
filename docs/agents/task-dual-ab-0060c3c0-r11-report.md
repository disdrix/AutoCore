# Dual A/B report — R11-010 OWN-ONLY (`0x0060c3c0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R11-010**  
**Scope:** VA `0x0060c3c0` (`aa_0060c3c0`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r11_residual_partition_map.md` → **R11-010**.  
**Work item:** Residual dual seal — mission reqHost lazy match-ref fill from skill materialize (escort ctor nested).  
**Hint retired:** scaffold `unknown` system / decompiler `in_EAX` / noreturn-delete.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0060c3c0` MissionReqHost_LazyFillMatchRefFromSkill_Inferred | **accept-with-gaps** — thiscall reqHost / gate −1 / harvest +0x14c & +0x22 / free temporary / sole escort caller sealed; product English open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): escort-this / TFID-gather / permanent-skill-cache / cast-apply / phantom-rank / noreturn-delete / multi-caller claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0060c3c0` — sealed facts

1. **Body:** `0x0060c3c0`–`0x0060c3fc` exclusive (**60 B** / `0x3C`); terminal plain **`C3` RET**; pad `CC`.
2. **ABI:** **`__thiscall`** — **ECX = reqHost**; **no stack args**; plain **RET**; void. **Not** decompiler multi-arg `__fastcall`.
3. **Semantics:** lazy fill when `reqHost+0x44 == -1`:
   - `CVOGReaction_ResolveSkillTargets(skillId@+0x10, rankWord@+0x14)` → temp 0x630 runtime or null.
   - Hit: `reqHost+0x44 ← skill+0x14c`; `reqHost+0x48 ← (skill+0x22 != 0)`; `operator_delete(skill)`.
   - Miss: leave `+0x44` as **−1**; no `+0x48` write.
4. **Caller (1):** dualed `CVOGHBMissionEscort_ctor` @ `0x00650835` (`MOV ECX,EDI` reqHost).
5. **Xrefs:** 1 UNCONDITIONAL_CALL.
6. **Callees:** dualed `CVOGReaction_ResolveSkillTargets` (`0x0054c570`); `operator_delete` (`0x00489822`).
7. **Consumer copy (parent, evidence):** escort `+0x2c ← reqHost+0x44` (targetMatchRef); escort `+0x30 ← reqHost+0x48` (matchByObjRefMode).
8. **Name:** `MissionReqHost_LazyFillMatchRefFromSkill_Inferred` (Ghidra `FUN_0060c3c0`). Product demangle open → `_Inferred`.
9. **Decompile ≡ raw CF**; ABI/rank/free sealed via `disassemble_function` + `read_memory` (decomp arity/CC incomplete, not CF conflict).
10. **Partition parent** `0x006507c0` is both wave score parent and **sole live structural caller**.

### Gaps

- Product / PDB English for reqHost class and full field dictionary.  
- Product label for skill `+0x14c` beyond dualed template/match id.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0060c3c0_MissionReqHost_LazyFillMatchRefFromSkill_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0060c3c0_MissionReqHost_LazyFillMatchRefFromSkill_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0060c3c0_FUN_0060c3c0.md` |
| Annotated | `docs/reconstruction/raw/aa_0060c3c0_FUN_0060c3c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/MissionReqHost_LazyFillMatchRefFromSkill_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0060c3c0.cpp` |
| Function | `docs/reconstruction/functions/aa_0060c3c0_FUN_0060c3c0.md` |
| Function named | `docs/reconstruction/functions/aa_0060c3c0_MissionReqHost_LazyFillMatchRefFromSkill_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_0060c860  [escort factory; residual / dualed neighborhood]
  └─ operator_new(0x78)
       └─ CVOGHBMissionEscort_ctor (0x006507c0)  [dualed WQ9G-E]
            ├─ CVOGHBBase_ctor
            ├─ FUN_0060c3c0  MissionReqHost_LazyFillMatchRefFromSkill_Inferred  [OWN R11-010]
            │     └─ CVOGReaction_ResolveSkillTargets (0x0054c570)  [dualed]
            │           └─ Skill_SetRankAndReevaluate …
            │     └─ operator_delete (temp runtime)
            ├─ copy reqHost+0x44/+0x48 → escort+0x2c/+0x30
            ├─ CVOGHBBase_SetPeriodAndCounter
            └─ CVOGHBBase_AttachOwnerObject

Skill layout (dualed aa_00620480): +0x22 template-path flag; +0x14c template id
```

Partition host “skills-abilities” names the **materialize** neighborhood; consumer role is escort **reqHost** seed.

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0060c3c0-r11-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0060c3c0` | Port as **lazy reqHost match-ref fill**: if `TargetMatchRef==-1`, materialize skill by `(skillId, rank)`, copy template id + template-mode bool, **free** temp. Thiscall on reqHost. |
| Distinct from | TFID target gather; permanent skill cache; cast/apply. |
| Pair with | dualed materialize `0054c570`; dualed escort ctor `006507c0` / OnHB `006508d0`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md` / `NAMING_REGISTRY.md` / coverage ledgers — **not touched** by this agent.
- Name to register: `MissionReqHost_LazyFillMatchRefFromSkill_Inferred` @ `0x0060c3c0` / `aa_0060c3c0`.
- Systems: `skills-abilities` (materialize) + `missions-progression` (escort reqHost consumer).
- Verdict: **accept-with-gaps**; Terminal **false**.

---

## Process

- OWN VA only (`0x0060c3c0`); no Launcher; no parent ledger edits.
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + call-site context. **No** `disassemble_bytes`.
- Dual A (fidelity) + B (adversarial) both filed.
- Scaffold raw body preserved; re-verify **appended** only.
- Clean source uses meaningful name; machine ABI corrections (thiscall; rank word; delete returns).
- Odd behavior preserved: miss leaves sentinel −1; free-after-harvest; bool from SETNZ on skill+0x22.
- `_Inferred` where English unproven. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
