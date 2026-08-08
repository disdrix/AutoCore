# Dual A/B report — R11-012 OWN-ONLY (`0x00617ad0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R11-012**  
**Scope:** VA `0x00617ad0` (`aa_00617ad0`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs/callees. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r11_residual_partition_map.md` → **R11-012**.  
**Work item:** Residual dual seal — skills-abilities; parent `CVOGHBSkillBase_ctor` `0x005788d0`.  
**Hint retired:** `Named_CalleeOf_Named_VOG_DEBUG_STOP_00617ad0` chain plate.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00617ad0` CVOGHBSkill_OnHit_ctor | **accept-with-gaps** — RTTI class Confirmed; thiscall RET0x18 / vtbl / +0x6c0·+0x6c4 seed sealed; product English for float field open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): OnHeartBeat / generic-FUN / chain-plate / cdecl / period-merge / flag0-zero-store claims **falsified**; RTTI+ABI+offsets **survive**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00617ad0` — sealed facts

1. **Body:** `0x00617ad0`–`0x00617b33` (**100 B** / `0x64`); terminal dual **`C2 18 00`** (`RET 0x18`); pad `CC` before next unit.
2. **ABI:** `__thiscall` — **ECX=this**; **6 stack args** (source, skillBlob, arg4, target, tfid, arg7); **RET 0x18**; EAX = this.
3. **Semantics:** `CVOGHBSkill_OnHit` constructor:
   - `CVOGHBSkillBase_ctor(...)` (parent dual sealed).
   - Install vtbl **`PTR_FUN_009d0f1c`**.
   - If `*(float*)(skillBlob+0x4c) != g_flZero` (`0x00a0f518`): `this+0x6c4=1`, `this+0x6c0=CVTTSS2SI(blob+0x4c)`.
   - Else: `this+0x6c4=0` (no write to `+0x6c0`).
4. **RTTI:** COL `0x00aadbc4` → type_info `0x00af1d60` → **`.?AVCVOGHBSkill_OnHit@@`** (**Confirmed**).
5. **Callers (4):** `FUN_00617fc0`, `FUN_0061c430`, `FUN_00623330`, `FUN_00624d40` — factories often `operator_new(0x6d0)` then overwrite subclass vtbl.
6. **Xrefs:** 4 UNCONDITIONAL_CALL.
7. **Callees:** `CVOGHBSkillBase_ctor` only.
8. **Family:** OnHit intermediate base for hit-family HB skills. Contrast Virus ctor `0x0061f940` (size 0x6e0; +0x6d0/+0x6d4) — **do not merge**. Sibling factory `FUN_00617df0` (R11-013) inlines same fields without calling this VA — **not dualled here**.
9. **Name:** `CVOGHBSkill_OnHit_ctor` (Ghidra `FUN_00617ad0`). Class product name **Confirmed** (RTTI); no `_Inferred` suffix on class.
10. **Decompile ≡ raw CF**; dword-index vs byte offsets sealed via `disassemble_function`.
11. **Partition parent** `0x005788d0` is live structural parent (base ctor).

### Gaps

- Product English for `skillBlob+0x4c` → `this+0x6c0` int seed.  
- Flag=0 path does not clear `+0x6c0`.  
- Caller / subclass vtbl duals (not OWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00617ad0_CVOGHBSkill_OnHit_ctor.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00617ad0_CVOGHBSkill_OnHit_ctor.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00617ad0_FUN_00617ad0.md` |
| Annotated | `docs/reconstruction/raw/aa_00617ad0_FUN_00617ad0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBSkill_OnHit_ctor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00617ad0.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_VOG_DEBUG_STOP_00617ad0.cpp` |
| Function | `docs/reconstruction/functions/aa_00617ad0_FUN_00617ad0.md` |
| Function named | `docs/reconstruction/functions/aa_00617ad0_CVOGHBSkill_OnHit_ctor.md` |

---

## Chain context (not dualled; evidence only)

```text
CVOGHBSkillBase_ctor (0x005788d0)  [parent dual sealed]
  └─ FUN_00617ad0  CVOGHBSkill_OnHit_ctor  [OWN R11-012]
        ├─ FUN_00617fc0  factory new(0x6d0) → subclass vtbl 009d0f7c
        ├─ FUN_0061c430  factory new(0x6d0) → subclass vtbl 009d10e4
        ├─ FUN_00623330  subclass thiscall + creature RTDynamicCast
        └─ FUN_00624d40  factory new(0x6e0) → subclass vtbl 009d196c

FUN_00617df0 (R11-013)  [NOT OWN]
  └─ inlines OnHit field init (base ctor + same vtbl/fields) without CALL 00617ad0

CVOGHBSkill_Virus_Ctor (0x0061f940)  [dualed prior]
  └─ different class / size / tail — do not merge
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00617ad0-r11-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00617ad0` | Port as **`CVOGHBSkill_OnHit` ctor**: base skill-HB ctor then OnHit vtbl; optional int seed at **`+0x6c0`** from skill float **`+0x4c`** (truncate); enable **`+0x6c4`**. Size **0x6d0**. ABI thiscall, **RET 0x18**. |
| Distinct from | Virus `0061f940`; base-only `005788d0`; period fields `+0x0C`/`+0x10`. |
| Pair with | dualed parent `005788d0`; residual factories `00617fc0`/`0061c430`/`00623330`/`00624d40`; residual inline twin `00617df0`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md` / `NAMING_REGISTRY.md` / coverage ledgers — **not touched** by this agent.
- Name to register: `CVOGHBSkill_OnHit_ctor` @ `0x00617ad0` / `aa_00617ad0`.
- Verdict: **accept-with-gaps**; Terminal **false**.

---

## Process

- OWN VA only (`0x00617ad0`); no Launcher; no parent ledger edits.
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function. **No** `disassemble_bytes`.
- Dual A (fidelity) + B (adversarial) both filed.
- Scaffold raw body preserved; re-verify **appended** only.
- Clean source uses RTTI name; machine ABI corrections (RET 0x18; absolute +0x6c0/+0x6c4; CVTTSS2SI).
- Odd behavior preserved: flag=0 does not write `+0x6c0`.
- Product class Confirmed (RTTI). Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
