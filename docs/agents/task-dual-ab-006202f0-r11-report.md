# Dual A/B report — R11-016 OWN-ONLY (`0x006202f0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R11-016**  
**Scope:** VA `0x006202f0` (`aa_006202f0`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `get_function_by_address` + callers/xrefs + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r11_residual_partition_map.md` → **R11-016**.  
**Work item:** Residual dual seal — skills-abilities; `CVOGHBSkillBase` subclass ctor (parent score `0x005788d0`).  
**Hint retired:** `Named_CalleeOf_Skill_Skill_d_had_invalid_template_d_006202f0` (caller string, not class).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_006202f0` CVOGHBSkill_SummonSnoop_Ctor | **accept** — 52 B thiscall ctor: base `CVOGHBSkillBase_ctor` + vtbl `009d156c`; RTTI `.?AVCVOGHBSkill_SummonSnoop@@`; sole caller `Skill_SpawnTemplateAndStartHB` `new(0x6c0)`; `ret 0x18` |

Path A (fidelity): **accept**.  
Path B (adversarial): void-return / execute-merge / multi-caller / invented-fields / string-as-class claims **falsified**; RTTI class **Confirmed**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x006202f0` — sealed facts

1. **Body:** `0x006202f0`–`0x00620323` inclusive (**52 B** / `0x34`); terminal **`C2 18 00`**; pad `CC` before next unit.
2. **ABI:** **`__thiscall`** — **ECX=this**; **six** stack formals; **RET 0x18**; EAX = this*.
3. **Semantics:** MSVC subclass ctor only:
   - `CVOGHBSkillBase_ctor(this, p2..p7)` @ `0x005788d0` (rel32 **Confirmed**).
   - `*this = PTR_FUN_009d156c` subclass vtbl.
   - **No** extra field stores.
4. **RTTI:** COL `0x00aae154` (vtbl-4) → type_info `0x00afed18` → **`.?AVCVOGHBSkill_SummonSnoop@@`** (**Confirmed**).
5. **Caller (1):** `Skill_SpawnTemplateAndStartHB` (`FUN_00620480`) @ `0x006208f4` after `operator_new(0x6c0)`; owner-null → scalar dtor else Enqueue+Start.
6. **Xrefs:** 1 UNCONDITIONAL_CALL.
7. **Callees:** `CVOGHBSkillBase_ctor` only.
8. **Name:** `CVOGHBSkill_SummonSnoop_Ctor` (Ghidra `FUN_006202f0`). Class product demangle **Confirmed** → no `_Inferred` suffix.
9. **Decompile ≡ raw CF**; base plate rename in live Ghidra (`CVOGHBSkillBase_ctor` vs old `FUN_005788d0`) is identity, not CF drift.
10. **Partition parent** `0x005788d0` is wave score parent (base ctor family); **live structural caller** is `0x00620480`.

### Gaps

- Product design English for SummonSnoop beyond RTTI demangle.  
- Peer OnHB `FUN_00620340` / dtor `FUN_00651190` undualed (not OWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_006202f0_CVOGHBSkill_SummonSnoop_Ctor.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_006202f0_CVOGHBSkill_SummonSnoop_Ctor.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_006202f0_FUN_006202f0.md` |
| Annotated | `docs/reconstruction/raw/aa_006202f0_FUN_006202f0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/CVOGHBSkill_SummonSnoop_Ctor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_006202f0.cpp` |
| Function | `docs/reconstruction/functions/aa_006202f0_FUN_006202f0.md` |
| Function named | `docs/reconstruction/functions/aa_006202f0_CVOGHBSkill_SummonSnoop_Ctor.md` |

---

## Chain context (not dualled; evidence only)

```text
Skill_SpawnTemplateAndStartHB (0x00620480)  [prior dual W19-E]
  ├─ operator_new(0x6c0)
  └─ FUN_006202f0  CVOGHBSkill_SummonSnoop_Ctor  [OWN R11-016]
        └─ CVOGHBSkillBase_ctor (0x005788d0)  [parent dual residual; not OWN]
              └─ CVOGHBBase_ctor / ValidateTarget / AttachOwner / SetPeriod…

vtbl PTR_FUN_009d156c
  +0x00 FUN_00651190  scalar dtor
  +0x04 FUN_00620340  OnHB-like tick
  +0x2c 0x00620480    co-located skill dispatch site (0x009d1598)
```

Partition host "skills-abilities" matches class family.

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-006202f0-r11-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `006202f0` | Port as **`CVOGHBSkill_SummonSnoop` ctor**: size **0x6c0**, base skill HB init then vtbl **`009d156c`**, **RET 0x18**. No subclass-local fields. |
| Pair with | dualed base `CVOGHBSkillBase_ctor`; dualed caller `Skill_SpawnTemplateAndStartHB`; residual OnHB `00620340`. |
| Do not merge | with SpawnEntities ctor (`00614dc0`, size `0x6d0` + ushort) or Virus ctor (`0061f940`, size `0x6e0` + budget/period). |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md` / `NAMING_REGISTRY.md` / coverage ledgers — **not touched** by this agent.
- Name to register: `CVOGHBSkill_SummonSnoop_Ctor` @ `0x006202f0` / `aa_006202f0`.
- Verdict: **accept**; Terminal **false**.
