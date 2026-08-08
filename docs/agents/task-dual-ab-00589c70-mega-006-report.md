# Dual A/B report — MEGA-006 OWN-ONLY (`0x00589c70`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-006**  
**Scope:** VA `0x00589c70` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context` + parent/callee decompile samples. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual dual seal — partition row MEGA-006 / skills-abilities residual under dualed parent `0x0061b6f0`.  
**Hint consumed:** `Skill_HB_ApplyHpDelta` → sealed as **`Skill_HB_ApplyHpDelta_Inferred`** (role yes; product demangle open).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00589c70` Skill_HB_ApplyHpDelta_Inferred | **accept-with-gaps** — CF/ABI/cdecl/sign/percent/floor/callers sealed; vtbl product English + shared apply dual open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): heat-merge / shield-merge / positive-amount-damage / thiscall / RET4 / percent-of-current / floor-recomputes-return claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00589c70` — sealed facts

1. **Body:** `0x00589c70`–`0x00589d80` inclusive (**273 B** / `0x111`); next sibling `FUN_00589d90` (ApplyShieldPool).
2. **ABI:** **`__cdecl`**; stack `source*`, `target*`, `float amount`, `char allowKill`; return **EAX**; bare **`RET`**; callers **`ADD ESP, 0x10`**.
3. **Semantics:** Skill HB **HP delta apply**:
   - Resolve entity via vtbl **+0x19C** + MSVC adjustor LEA, else **`target+0xAC`**, else source path.
   - `deltaInt = -trunc(amount)`; if `amount ∈ [-1.0, 1.0]` then `-trunc(GetMaxHp()*amount)` (vtbl **+0x244**).
   - `cur = GetCurrentHp()` (vtbl **+0x23C**); `projected = cur - deltaInt`.
   - If `!allowKill && projected < 1`: applied `deltaInt = cur - 1` (return still unclamped).
   - Apply via **`FUN_004d7e30`** (`ECX = entity+0xA4`, floater flags, color `DAT_009d4d28..34`).
   - Return `0` if no projected change; else `projected - cur`.
4. **Sign convention:** float **+ → heal**, float **− → damage** (downstream `HP' = HP - deltaInt`). Damage parents multiply by **`DAT_00aaa668` (-1.0f)**.
5. **Constants:** `DAT_00aaa668` = -1.0f; `g_flOne` @ `0x00a0f2a0` = 1.0f; color quad `{−1,−1,0,0}` as u32.
6. **Callees:** `FUN_004d7e30` only.
7. **Callers / xrefs (5):**  
   - `FUN_0061b6f0` @ `0x0061b854`  
   - `FUN_00618270` @ `0x006185c0`  
   - `0x0061be88`, `0x0061e86d`, `0x0061ea02`
8. **Name:** `Skill_HB_ApplyHpDelta_Inferred` (Ghidra `FUN_00589c70`). No `Named_CalleeOf_*` scaffold present.
9. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory` + call-site context.

### Gaps

- Product English for vtbl **+0x19C / +0x23C / +0x244** and controller field **`+0xA4`**.  
- Dual seal of shared apply `FUN_004d7e30` / `FUN_004d78e0`.  
- Floater color plate name.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00589c70_Skill_HB_ApplyHpDelta_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00589c70_Skill_HB_ApplyHpDelta_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00589c70_FUN_00589c70.md` |
| Annotated | `docs/reconstruction/raw/aa_00589c70_FUN_00589c70.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Skill_HB_ApplyHpDelta_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00589c70.cpp` |
| Function | `docs/reconstruction/functions/aa_00589c70_FUN_00589c70.md` |
| Function named | `docs/reconstruction/functions/aa_00589c70_Skill_HB_ApplyHpDelta_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_0061b6f0  Skill HB OnHeartBeat dispatcher  [parent dual context; not OWN]
  ├─ FUN_005787a0  Skill_HB_RescheduleStatus     [MEGA-004]
  ├─ FUN_00589bc0  Skill_HB_ApplyHeatDelta       [MEGA-005]
  ├─ FUN_00589c70  Skill_HB_ApplyHpDelta_Inferred [OWN MEGA-006]
  │    └─ FUN_004d7e30  combat apply + floater   [shared residual]
  │         └─ FUN_004d78e0  GetHp/SetHp path
  ├─ FUN_00589d90  Skill_HB_ApplyShieldPool      [MEGA-007]
  ├─ FUN_0058cc40  Skill_HB_ApplyShortAndFloater [MEGA-008]
  └─ FUN_0058d8e0  Skill_HB_ApplyMultiArgEffect  [MEGA-009]

FUN_00618270  peer HB path
  └─ FUN_00589c70  [OWN MEGA-006]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00589c70-mega-006-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00589c70` | Port as **skill HB HP delta apply**. **`__cdecl`** 4 args. **Positive amount heals**, **negative damages**. `\|amount\|≤1` → fraction of **max** HP. `allowKill==false` → leave at least 1 HP on applied delta; return uses **pre-floor** projection. Do **not** merge with heat `00589bc0` or shield `00589d90`. |
| Pair with | parent HB dispatcher `0061b6f0`; shared apply `004d7e30`; siblings heat/shield/floater. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/*` skills-abilities residual tables  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Not written by this agent.**

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x00589c70`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + call-site context + callee/parent samples. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean sources use meaningful `_Inferred` name; twin keeps `FUN_00589c70`.  
- Odd behavior preserved: return ignores floor rewrite; positive float heals.  
- Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
