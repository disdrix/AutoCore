# Dual A/B report — R12-005 OWN-ONLY (`0x00621f50`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R12-005**  
**Scope:** VA `0x00621f50` (`aa_00621f50`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs (including parent `0x00621350` dual rewrite).  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs/callees + `get_function_by_address` + `audit_globals_in_function`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r12_residual_partition_map.md` → **R12-005**.  
**Work item:** Residual dual seal — skills-abilities; parent dual `0x00621350` (`CVOGHBSkill_OnDoHit_Ctor`); dual start 2646.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00621f50` CVOGHBSkill_HitCharge_Execute_Inferred | **accept-with-gaps** — 270 B SEH multi-target arm; ret0x18; RTTI HitCharge + vtbl+0x2C; OnDoHit parent ctor + vtbl upgrade + tail zeros; resolve/enqueue/start sealed; product method English open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): void-signature / OnDoHit-ctor-identity / OnDoHit-execute-merge / code-xref fanout / return-0 / this-used / 0x6c0-size claims **falsified**; method-English sealed claim **held as Inferred only**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00621f50` — sealed facts

1. **Body:** `0x00621f50`–`0x0062205d` inclusive (**270 B** / `0x10E`); terminal **`C2 18 00`**; pad `CC` before next.
2. **ABI:** six stack formals; **`ret 0x18`**; EAX = **1** on sentinel. **ECX this unused**.
3. **Semantics:** TFID table walk (stride **`0x10`**, sentinel `{-1,-1,bGlobal=0}`) → `CVOGReaction_ResolveObjectTarget` (`ECX=world+0xe4e8`) → on hit `operator_new(0x6d0)` + `CVOGHBSkill_OnDoHit_Ctor` + vtbl **`009d1624`** + zero **`+0x6c0`/`+0x6c4`** → owner@**+0x18** ? `Enqueue(world+0xe4ec)` + `Start` : `vtbl[0](1)`.
4. **Class:** RTTI **Confirmed** `.?AVCVOGHBSkill_HitCharge@@` (COL `0x00aae1f0` → type_info `0x00af2b4c`).
5. **Install:** sole xref DATA `@0x009d1650` = **`PTR_FUN_009d1624 + 0x2C`**.
6. **Callees:** ResolveObjectTarget `004bae70`, `operator_new`, OnDoHit ctor `00621350`, Enqueue `005078f0`, Start `005081c0`, dtor path `00651190`.
7. **Name:** `CVOGHBSkill_HitCharge_Execute_Inferred` (Ghidra `FUN_00621f50`). Class **Confirmed**; method English **Inferred**.
8. **Decompile ≡ raw CF**; ABI sealed via disassembly + bytes. Decompiler period overlay at `+0x6c0` is type noise — bytes seal dword/float zeros.
9. **Partition parent** `0x00621350` is OnDoHit ctor (score parent); this unit **calls** it, does not dual it.

### Gaps

- Product C++ method name for vtbl+0x2C.  
- HitCharge tail field English (`+0x6c0` / `+0x6c4`).  
- Virtual dispatch call sites (not OWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00621f50_CVOGHBSkill_HitCharge_Execute_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00621f50_CVOGHBSkill_HitCharge_Execute_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify append) | `docs/reconstruction/raw/aa_00621f50_FUN_00621f50.md` |
| Annotated | `docs/reconstruction/raw/aa_00621f50_FUN_00621f50.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/CVOGHBSkill_HitCharge_Execute_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00621f50.cpp` |
| Function named | `docs/reconstruction/functions/aa_00621f50_CVOGHBSkill_HitCharge_Execute_Inferred.md` |
| Function scaffold | `docs/reconstruction/functions/aa_00621f50_FUN_00621f50.md` |

---

## Sibling context (not dualled; evidence only)

| VA | Role |
|---|---|
| `0x00621350` | `CVOGHBSkill_OnDoHit_Ctor` — parent dual (called per target) |
| `0x009d1624` | `CVOGHBSkill_HitCharge` vtbl |
| `0x00621700` | OnDoHit execute peer — size `0x6c0`, vtbl `009d15c4` — **do not merge** |
| `0x00615020` | SpawnEntities execute — also size `0x6d0` class family — **do not merge** |
| `0x00620480` | `Skill_SpawnTemplateAndStartHB` — different handler |

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00621f50-r12-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00621f50` | Port as **HitCharge multi-target apply**: table stride `0x10`, always return **1**, HB size **`0x6d0`**, construct via OnDoHit parent then HitCharge vtbl + zero `+0x6c0/+0x6c4`, list `@world+0xe4ec`, resolve `@world+0xe4e8`. |
| Distinct from | OnDoHit ctor `00621350`; OnDoHit execute `00621700`; SpawnEntities execute `00615020`; template spawn `00620480`. |
| Pair with | sealed parent `CVOGHBSkill_OnDoHit_Ctor`; dualed `CVOGReaction_ResolveObjectTarget`; Enqueue/Start HB list services. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md` / `NAMING_REGISTRY.md` / coverage ledgers — **not touched** by this agent.
- Name to register: `CVOGHBSkill_HitCharge_Execute_Inferred` @ `0x00621f50` / `aa_00621f50`.
- Verdict: **accept-with-gaps**; Terminal **false**.

---

## Compliance

| Rule | Status |
|------|--------|
| Exclusive VA `0x00621f50` only | **Held** |
| No parent ledgers | **Held** |
| No Launcher | **Held** |
| No `disassemble_bytes` | **Held** |
| Infer `_Inferred` method English; RTTI class Confirmed | **Held** |
| Never Runtime Confirmed | **Held** |
| Raw append-only (no wipe) | **Held** |
| Terminal false | **Held** |
