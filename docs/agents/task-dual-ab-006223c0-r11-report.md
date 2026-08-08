# Dual A/B report — R11-019 OWN-ONLY (`0x006223c0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R11-019**  
**Scope:** VA `0x006223c0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs; parent dual `0x005788d0` edits; peer factory `0x006226a0` (R11-020).  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `get_function_callers` / `get_function_xrefs` + `read_memory` (body + vtbl + RTTI COL/type_info). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** Residual dual wave R11 — skills-abilities ctor under parent `CVOGHBSkillBase_ctor` (`0x005788d0`).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_006223c0` CVOGHBSkill_KillCharge_Ctor | **accept** — CF/ABI/vtbl/RTTI/sole CALL sealed; product skill English open |

Path A (fidelity): **accept**.  
Path B (adversarial): OnHeartBeat / CommonCastOnDeath-identity / cdecl-void / self-alloc-0x6d0 / SkillBase-only / multi-CALL claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x006223c0` — sealed facts

1. **Body:** `0x006223c0`–`0x006223f3` inclusive (**52 B** / `0x34`); pad `CC` after `ret 0x18`.
2. **ABI:** **`__thiscall`** `ECX` = this; **6 stack dwords**; **`RET 0x18`**; returns **this** in EAX.
3. **Semantics:** **`CVOGHBSkill_KillCharge` subclass constructor** —
   - Call **`CVOGHBSkillBase_ctor`** (`0x005788d0`) with the six stack args (this in ECX).
   - Install vtbl **`PTR_FUN_009d16e4`**.
   - Return this. No other stores / branches / Enqueue / Start.
4. **RTTI:** COL `@0x00aae2d8` → type_info `@0x00af2b70` → **`.?AVCVOGHBSkill_KillCharge@@`** (**Confirmed**).
5. **Callees:** `CVOGHBSkillBase_ctor` only.
6. **Callers:** **1** — `FUN_00622f70` @ `0x00623009` (`operator_new(0x6d0)` → this ctor → overwrite vtbl to `PTR_FUN_009d1744` / CommonCastOnDeath).
7. **Xrefs:** 1 UNCONDITIONAL_CALL.
8. **Name:** `CVOGHBSkill_KillCharge_Ctor` (Ghidra `FUN_006223c0`). Scaffold product names not present.
9. **Size evidence (not allocated here):** peer factory `FUN_006226a0` uses `operator_new(0x6c0)` + same vtbl for pure KillCharge; sole CALL uses `0x6d0` for further subclass.
10. **Decompile ≡ raw CF**; ABI + vtbl + RTTI sealed via `read_memory` (no `disassemble_bytes`).

### Gaps

- Product design English for KillCharge skill.  
- Full base-ctor stack-arg English (parent domain).  
- Dual of sole caller / peer factory (not OWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_006223c0_CVOGHBSkill_KillCharge_Ctor.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_006223c0_CVOGHBSkill_KillCharge_Ctor.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify append) | `docs/reconstruction/raw/aa_006223c0_FUN_006223c0.md` |
| Annotated | `docs/reconstruction/raw/aa_006223c0_FUN_006223c0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/CVOGHBSkill_KillCharge_Ctor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_006223c0.cpp` |
| Function | `docs/reconstruction/functions/aa_006223c0_FUN_006223c0.md` |
| Function named | `docs/reconstruction/functions/aa_006223c0_CVOGHBSkill_KillCharge_Ctor.md` |

---

## Chain context (not dualled; evidence only)

```text
CVOGHBSkillBase_ctor  0x005788d0  [partition parent — dual sealed prior]
  RTTI CVOGHBSkillBase; ValidateTarget notify=1; AttachOwner; SetPeriod

FUN_006223c0  CVOGHBSkill_KillCharge_Ctor  [OWN R11-019]
  base ctor + vtbl PTR_FUN_009d16e4 (.?AVCVOGHBSkill_KillCharge@@)

FUN_00622f70  CommonCastOnDeath reaction factory  [residual]
  operator_new(0x6d0)
  CALL 0x006223c0
  *vtbl = PTR_FUN_009d1744 (.?AVCVOGHBSkill_CommonCastOnDeath@@)
  if owner attached: Enqueue(world+0xe4ec) + Start; else vtbl dtor(1)

FUN_006226a0  pure KillCharge reaction factory  [R11-020 OWN]
  operator_new(0x6c0)
  CVOGHBSkillBase_ctor + *vtbl = PTR_FUN_009d16e4  (inlines this ctor pattern)
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-006223c0-r11-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `006223c0` | Port as **`CVOGHBSkill_KillCharge` ctor**. **thiscall** + **6 stack args**, **`RET 0x18`**, return **this**. Always call **`CVOGHBSkillBase_ctor`** then install vtbl **`0x009d16e4`**. Do **not** treat as CommonCastOnDeath (caller may override vtbl), as void/cdecl, or as the allocator. Pure object size **0x6c0**; subclass path may allocate larger. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md`  
- `systems/skills-abilities.md` residual tables  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).
