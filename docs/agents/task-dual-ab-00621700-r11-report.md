# Dual A/B report — R11-018 OWN-ONLY (`0x00621700`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R11-018**  
**Scope:** VA `0x00621700` (`aa_00621700`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs (including parent `0x005788d0` dual rewrite).  
**Ghidra:** `decompile_function` + `disassemble_function` + `read_memory` + callers/xrefs/callees + `analyze_function_complete`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r11_residual_partition_map.md` → **R11-018**.  
**Work item:** Residual dual seal — skills-abilities; parent score `0x005788d0` (`CVOGHBSkillBase_ctor`); class RTTI `CVOGHBSkill_OnDoHit`.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00621700` CVOGHBSkill_OnDoHit_Execute_Inferred | **accept-with-gaps** — 264 B SEH multi-target arm; ret0x18; RTTI class + vtbl+0x2C; resolve/enqueue/start sealed; product method English open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): void-signature / ctor-identity / code-xref fanout / return-0 / this-used / 0x6d0-merge claims **falsified**; method-English sealed claim **held as Inferred only**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00621700` — sealed facts

1. **Body:** `0x00621700`–`0x00621807` inclusive (**264 B** / `0x108`); terminal **`C2 18 00`**; pad `CC` before next.
2. **ABI:** six stack formals; **`ret 0x18`**; EAX = **1** on sentinel. **ECX this unused**.
3. **Semantics:** TFID table walk (stride **`0x10`**, sentinel `{-1,-1,bGlobal=0}`) → `CVOGReaction_ResolveObjectTarget` (`ECX=world+0xe4e8`) → on hit `operator_new(0x6c0)` + `CVOGHBSkillBase_ctor` + vtbl **`009d15c4`** → owner@**+0x18** ? `Enqueue(world+0xe4ec)` + `Start` : `vtbl[0](1)`.
4. **Class:** RTTI **Confirmed** `.?AVCVOGHBSkill_OnDoHit@@` (COL `0x00aae1a0` → type_info `0x00af1d80`).
5. **Install:** sole xref DATA `@0x009d15f0` = **`PTR_FUN_009d15c4 + 0x2C`**.
6. **Callees:** ResolveObjectTarget `004bae70`, `operator_new`, `CVOGHBSkillBase_ctor` `005788d0`, Enqueue `005078f0`, Start `005081c0`, dtor path `00651190`.
7. **Name:** `CVOGHBSkill_OnDoHit_Execute_Inferred` (Ghidra `FUN_00621700`). Method English **Inferred**; class **Confirmed**.
8. **Decompile ≡ raw CF**; live decomp names base ctor; ABI sealed via disassembly + bytes.
9. **Partition parent** `0x005788d0` is base ctor (score parent); this unit **calls** it, does not dual it.

### Gaps

- Product C++ method name for vtbl+0x2C.  
- Virtual dispatch call sites (not OWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00621700_CVOGHBSkill_OnDoHit_Execute_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00621700_CVOGHBSkill_OnDoHit_Execute_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify append) | `docs/reconstruction/raw/aa_00621700_FUN_00621700.md` |
| Annotated | `docs/reconstruction/raw/aa_00621700_FUN_00621700.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/CVOGHBSkill_OnDoHit_Execute_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00621700.cpp` |
| Function named | `docs/reconstruction/functions/aa_00621700_CVOGHBSkill_OnDoHit_Execute_Inferred.md` |
| Function scaffold | `docs/reconstruction/functions/aa_00621700_FUN_00621700.md` |

---

## Sibling context (not dualled; evidence only)

| VA | Role |
|---|---|
| `0x005788d0` | `CVOGHBSkillBase_ctor` (base; partition parent) |
| `0x00621350` | OnDoHit subclass ctor (base + vtbl only) — R11-017 |
| `0x009d15c4` | `CVOGHBSkill_OnDoHit` vtbl |
| `0x00621500` / `0x00621600` / `0x00621650` | Peer slots (tooltip / conversion_percent) |
| `0x00621f50` | Similar multi-target loop; size `0x6d0`, vtbl `009d1624` — **do not merge** |
| `0x00620480` | `Skill_SpawnTemplateAndStartHB` — different handler |

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00621700-r11-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00621700` | Port as **OnDoHit multi-target apply**: table stride `0x10`, always return **1**, HB size **`0x6c0`**, list `@world+0xe4ec`, resolve `@world+0xe4e8`. |
| Distinct from | OnDoHit ctor `00621350`; SpawnEntities execute `00615020`; template spawn `00620480`; peer loop `00621f50`. |
| Pair with | sealed base `CVOGHBSkillBase_ctor`; dualed `CVOGReaction_ResolveObjectTarget`; Enqueue/Start HB list services. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md` / `NAMING_REGISTRY.md` / coverage ledgers — **not touched** by this agent.
- Name to register: `CVOGHBSkill_OnDoHit_Execute_Inferred` @ `0x00621700` / `aa_00621700`.
- Verdict: **accept-with-gaps**; Terminal **false**.
