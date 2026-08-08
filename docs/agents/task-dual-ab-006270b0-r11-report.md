# Dual A/B report — R11-022 OWN-ONLY (`0x006270b0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R11-022**  
**Scope:** VA `0x006270b0` (`aa_006270b0`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + callers/xrefs + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r11_residual_partition_map.md` → **R11-022**.  
**Work item:** Residual dual seal — skills-abilities; parent score `0x005788d0` (`CVOGHBSkillBase_ctor`).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_006270b0` CVOGHBSkill_AddSkillLevels_ctor | **accept-with-gaps** — RTTI class + CF + ABI + empty map @`+0x6c4` + sole-caller size/`ret 0x18` sealed; map payload + vfunc`+0x210` English open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): anonymous-scaffold / execute-body / budget-at-0x1b1 / always-detach / ExceptionList=this claims **falsified**; RTTI Confirmed.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x006270b0` — sealed facts

1. **Body:** `0x006270b0`–`0x00627160` inclusive (**177 B** / `0xB1`); exclusive end `0x00627161`; pad `CC` before `FUN_00627170` @ `0x00627170`.
2. **ABI:** **`__thiscall`** ECX = this; stack `(pSource, pSkillBlob, arg4, pTarget, pTfid, arg7)`; epilogue **`C2 18 00`** (`ret 0x18`); returns this in EAX.
3. **Classification:** worker (skill HB subclass ctor; **3** direct callees + 1 virtual).
4. **Callees (rel32 sealed):**
   - `CVOGHBSkillBase_ctor` `0x005788d0` (from `0x006270F4`)
   - `RbTree_AllocEmptyNode_Inferred` `0x00439770` (from `0x0062710F`)
   - `CVOGHBBase_AttachOwnerObject` `0x005083b0` (from `0x0062714B`, conditional)
5. **Virtual:** `(*(pTarget->vtbl + 0x210))(pTarget, 0)`; fail → attach null owner.
6. **Vtbl:** imm **`0x009d1c54`** (`PTR_FUN_009d1c54`).
7. **RTTI Confirmed:** COL `0x00aae638` (`*(vtbl-4)`) → type_info `0x00af22b4` → **`.?AVCVOGHBSkill_AddSkillLevels@@`**.
8. **Fields (this ctor):**
   - `*this = 0x009d1c54`
   - `+0x6c4` = empty RB sentinel (`FUN_00439770`; `+0x15=1`; self-links @0/4/8)
   - `+0x6c8` = **0** (map size)
9. **Caller (1):** `FUN_00627750` @ `0x006277ec` after `operator_new(0x6d0)`; enqueues only if `pOwnerObject != null`.
10. **Name:** `CVOGHBSkill_AddSkillLevels_ctor` (Ghidra `FUN_006270b0`).
11. **Decompile ≡ raw CF**; ExceptionList restore corrected via bytes (decompiler mislabels restore as `param_1`).

### Gaps

- Map key/value product type at `+0x6c4` (empty only here).  
- Object `vtbl+0x210` English (shared host/mode-style gate).  
- Vtbl method duals that populate/consume the map (not OWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_006270b0_CVOGHBSkill_AddSkillLevels_ctor.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_006270b0_CVOGHBSkill_AddSkillLevels_ctor.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify append) | `docs/reconstruction/raw/aa_006270b0_FUN_006270b0.md` |
| Annotated | `docs/reconstruction/raw/aa_006270b0_FUN_006270b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBSkill_AddSkillLevels_ctor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_006270b0.cpp` |
| Function | `docs/reconstruction/functions/aa_006270b0_FUN_006270b0.md` |
| Function named | `docs/reconstruction/functions/aa_006270b0_CVOGHBSkill_AddSkillLevels_ctor.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_00627750  [factory / multi-target skill-level HB spawn; not OWN]
  ├─ CVOGReaction_ResolveObjectTarget
  ├─ operator_new(0x6d0)
  └─ FUN_006270b0  CVOGHBSkill_AddSkillLevels_ctor  [OWN R11-022]
        ├─ CVOGHBSkillBase_ctor (0x005788d0)  [parent score; dual residual sealed]
        ├─ RbTree_AllocEmptyNode_Inferred (0x00439770)  [dualed]
        └─ CVOGHBBase_AttachOwnerObject (0x005083b0)  [dualed; conditional null]
  └─ if pOwnerObject: CVOGHBList_Enqueue + CVOGHBBase_Start
     else: vtbl dtor(1)
```

Partition parent `0x005788d0` is the **base skill HB ctor** (score parent), not the live factory caller.

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `006270b0` | Port as **`CVOGHBSkill_AddSkillLevels` ctor**: base skill HB → vtbl **`0x009d1c54`** → empty map @**`+0x6c4`** (sentinel + size0 @**`+0x6c8`**) → optional **owner clear** if target **`vtbl+0x210(0)`** fails. Preserve **`ret 0x18`** and size **`0x6d0`**. Do not invent level-table payload types until insert methods are dualled. Factory must Enqueue+Start only when owner non-null. |

---

## Process

- OWN VA only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze + xrefs/callers + `read_memory`. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- No invented product names; class from RTTI demangle Confirmed.  
- Avoid bare `undefined4` in clean (use `uint32_t` / `uint8_t` / `void*`).

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md` / `NAMING_REGISTRY.md` / coverage ledgers / `skills-abilities.md` — **not touched** by this agent.
- Name to register: `CVOGHBSkill_AddSkillLevels_ctor` @ `0x006270b0` / `aa_006270b0`.
- Verdict: **accept-with-gaps**; Terminal **false**.

---

## This report

`docs/agents/task-dual-ab-006270b0-r11-report.md`
