# Dual A/B report — R11-014 OWN-ONLY (`0x00618180`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R11-014**  
**Scope:** VA `0x00618180` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs; parent dual `0x005788d0` edits.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `get_function_callers` / `get_function_xrefs` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** Residual dual wave R11 — skills-abilities; parent dual `0x005788d0` (`CVOGHBSkillBase_ctor`).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00618180` CVOGHBSkill_Common_ctor | **accept** — RTTI Common + ctor CF/ABI/vtbl + float tail + 30s period gate sealed; product field English residual |

Path A (fidelity): **accept**.  
Path B (adversarial): int-`param_9` / void-return / invent-name / always-run-period claims **falsified**; no CF rejects.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00618180` — sealed facts

1. **Body:** `0x00618180`–`0x00618265` inclusive (**230 B** / `0xE6`); Ghidra range end `00618267`; pad `CC`; terminal **`ret 0x20`**.

2. **ABI:** **`__thiscall`** (`mov esi,ecx`); **8 stack dwords**; **`EAX = this`**.

3. **Identity (Confirmed):**
   - RTTI **`.?AVCVOGHBSkill_Common@@`** (type_info `0x00af2918` via COL `0x00ab1820`)
   - Installs vtbl **`PTR_FUN_009e1f2c`**
   - Object size **`0x6d0`** at direct `operator_new` callers; Virus extends **`0x6e0`**

4. **Name:** `CVOGHBSkill_Common_ctor` — class **Confirmed**, ctor role **High**. Supersedes scaffold-only `FUN_00618180` product claim.

5. **High-level CF:**
   1. `CVOGHBSkillBase_ctor(p2..p7)`
   2. `*this = PTR_FUN_009e1f2c`
   3. `this+0x6c0 = byte(param_8)`; `this+0x6c4 = float(param_9)` (`movss`); `this+0x6c8 = 0`
   4. Gate: `this+0x44` && `pTarget` && `*(pTarget+0xa4)` && `*(*(pTarget+0xa4)+0xf6)`
   5. If `GetRemainingSeconds(this) > 30.0f` (`DAT_00a0f694`):
      - if `this+0x0C > 1`: `SetPeriodAndCounter(this, 30000/(this+0x08), true)`; return
      - else `this+0x08 = 30000`
   6. return this

6. **Callees:** `CVOGHBSkillBase_ctor` `0x005788d0`, `CVOGHBBase_GetRemainingSeconds` `0x00508280`, `CVOGHBBase_SetPeriodAndCounter` `0x005081a0`.

7. **Callers:** 15 UNCONDITIONAL_CALL / 12 named owners including **`CVOGHBSkill_Virus_Ctor`** (`0x0061f940`, passes `0, 1.0f`).

8. **Decompile ≡ raw CF**; **float-at-+0x6c4** sealed by bytes (decompiler int overlay closed).

### Gaps

1. Product design English for “Common” beyond RTTI.  
2. Field English for `+0x6c0` / `+0x6c4` / blob `+0x44`.  
3. Identity of `pTarget+0xa4` / `+0xf6` gate object.  
4. Full Common vtbl slot catalog.  
5. Runtime / bit-exact / differential.  
6. Semantic names for non-Virus callers (other partitions).

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00618180_CVOGHBSkill_Common_ctor.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_00618180_CVOGHBSkill_Common_ctor.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw (+ R11 re-verify append) | `docs/reconstruction/raw/aa_00618180_FUN_00618180.md` |
| Annotated | `docs/reconstruction/raw/aa_00618180_FUN_00618180.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/CVOGHBSkill_Common_ctor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00618180.cpp` |
| Function named | `docs/reconstruction/functions/aa_00618180_CVOGHBSkill_Common_ctor.md` |
| Function scaffold | `docs/reconstruction/functions/aa_00618180_FUN_00618180.md` |
| Review A | `docs/reconstruction/reviews/A_aa_00618180_CVOGHBSkill_Common_ctor.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00618180_CVOGHBSkill_Common_ctor.md` |
| This report | `docs/agents/task-dual-ab-00618180-r11-report.md` |

---

## Chain context (not dualled; evidence only)

```text
CVOGHBSkillBase_ctor          0x005788d0  [parent dual — not edited]
  ↑
CVOGHBSkill_Common_ctor       0x00618180  [OWN R11-014]
  ↑ used by
CVOGHBSkill_Virus_Ctor        0x0061f940  [prior dual; intermediate base = this]
  + many other new(0x6d0) skill spawn paths (FUN_006189d0, FUN_0061c090, …)
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00618180-r11-report.md` |
