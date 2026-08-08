# Dual A/B report — R12-022 OWN-ONLY (`0x00548990`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R12-022**  
**Scope:** VA `0x00548990` (`aa_00548990`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + callers/xrefs + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r12_residual_partition_map.md` → **R12-022**.  
**System:** skills-abilities  
**Parent dual (context only):** `0x0061c590` `CVOGHBSkill_XP_ApplyToTargetList_Inferred`  
**Dual start:** 2646  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00548990` CVOGHBSkill_XP_CreateDefaultInstance_Inferred | **accept** — RTTI class Confirmed; factory CF/ABI/size/DefaultCtor/vtbl+0x48 DATA sealed |

Path A (fidelity): **accept**.  
Path B (adversarial): full-ctor-merge / Apply-merge / OnHeartBeat-merge / size-0x6d0 / multi-CALL / inbound-this-ctor claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).  
**Terminal:** false.

---

## VA `0x00548990` — sealed facts

1. **Body:** `0x00548990`–`0x005489e2` inclusive (**83 B** / `0x53`); terminal plain **`RET`** (`C3`); pad `CC` after.
2. **ABI:** **no** stack formals; **EAX** = object* or **null**. SEH `LAB_009a43fb`.
3. **Semantics:** MSVC-style **default factory** for **`CVOGHBSkill_XP`**:
   - `operator_new(0x6c0)`
   - if non-null: **`CVOGHBSkillBase_DefaultCtor`** (`0x00578830`, thiscall ECX=new)
   - install vtbl **`PTR_FUN_009d119c`**
   - return instance* / null
4. **Class:** **`CVOGHBSkill_XP`** — RTTI **Confirmed** `.?AVCVOGHBSkill_XP@@` via COL `0x00aade00` → type_info `0x00af29ec` on vtbl `009d119c`.
5. **Xrefs:** 1× **DATA** from **`0x009d11e4`** = **vtbl+0x48**. No UNCONDITIONAL_CALL callers.
6. **Callees:** `operator_new` @ `0x00489892`; `FUN_00578830` / `CVOGHBSkillBase_DefaultCtor` (dualed; not OWN).
7. **Distinct from parent dual `0x0061c590`:** Apply uses full ctor **`0x005788d0`**, pulse@+0x08, SetPeriod(−1000,true), Enqueue/Start — **do not merge**.
8. **Name:** `CVOGHBSkill_XP_CreateDefaultInstance_Inferred` (Ghidra `FUN_00548990`). Class Confirmed; method role **Inferred**.
9. **Decompile ≡ raw CF ≡ bytes**; decompiler omits DefaultCtor ECX — sealed via `disassemble_function` + `read_memory` (`8B CE` / `E8 …` / `C7 06 9C 11 9D 00`).
10. **Partition parent** `0x0061c590` is wave score parent (same XP class); **live structural inbound** is vtbl DATA only.

### Gaps

- Product / PDB method English for vtbl+0x48.  
- Whether virtual dispatchers pass unused ECX `this`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00548990_CVOGHBSkill_XP_CreateDefaultInstance_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_00548990_CVOGHBSkill_XP_CreateDefaultInstance_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw (+ R12-022 append) | `docs/reconstruction/raw/aa_00548990_FUN_00548990.md` |
| Annotated | `docs/reconstruction/raw/aa_00548990_FUN_00548990.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/CVOGHBSkill_XP_CreateDefaultInstance_Inferred.cpp` |
| Clean scaffold | `docs/reconstruction/reconstructed-exact/FUN_00548990.cpp` |
| Function named | `docs/reconstruction/functions/aa_00548990_CVOGHBSkill_XP_CreateDefaultInstance_Inferred.md` |
| Function scaffold | `docs/reconstruction/functions/aa_00548990_FUN_00548990.md` |
| Review A | `docs/reconstruction/reviews/A_aa_00548990_CVOGHBSkill_XP_CreateDefaultInstance_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00548990_CVOGHBSkill_XP_CreateDefaultInstance_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
CVOGHBSkillBase_DefaultCtor  0x00578830     [dualed; empty shell; not OWN]
  └─ FUN_00548990 / CVOGHBSkill_XP_CreateDefaultInstance_Inferred  [OWN R12-022]
        ├─ operator_new(0x6c0)
        └─ stamp PTR_FUN_009d119c  (CVOGHBSkill_XP)

CVOGHBSkill_XP vtbl 009d119c
  +0x2C  CVOGHBSkill_XP_ApplyToTargetList_Inferred  0x0061c590  [parent dual R11-015]
         uses full CVOGHBSkillBase_ctor 0x005788d0 + period/Enqueue — do not merge
  +0x48  CVOGHBSkill_XP_CreateDefaultInstance_Inferred  0x00548990  [OWN R12-022]

SkillElementFactory_RegisterCatalog  0x0054a640  [dualed; pattern family]
  └─ many new(0x6c0..0x6f0)+DefaultCtor/other + subclass vtbl — same factory shape
```

Partition host "skills-abilities" names the **system**; parent dual supplies **class** identity via shared vtbl/RTTI.

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00548990-r12-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00548990` | Port as **`CVOGHBSkill_XP` default factory**: `new(0x6c0)` → **DefaultCtor** → XP vtbl; return null on OOM. No stack args. |
| Distinct from | ApplyToTargetList `0061c590` (full ctor + arm); full cast ctor `005788d0`; OnHeartBeat sibling slots. |
| Pair with | dualed DefaultCtor `00578830`; dualed parent Apply `0061c590`; catalog factory pattern `0054a640`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md` / `NAMING_REGISTRY.md` / coverage ledgers — **not touched** by this agent.
- Name to register: `CVOGHBSkill_XP_CreateDefaultInstance_Inferred` @ `0x00548990` / `aa_00548990`.
- Verdict: **accept**; Terminal **false**.
