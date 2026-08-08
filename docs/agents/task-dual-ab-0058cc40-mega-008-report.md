# Dual A/B report — MEGA-008 OWN-ONLY (`0x0058cc40`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-008**  
**Scope:** VA `0x0058cc40` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context` + parent/callee decompile samples. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual dual seal — partition row MEGA-008 / skills-abilities residual under dualed parent `0x0061b6f0`.  
**Hint consumed:** `Skill_HB_ApplyShortAndFloater` → sealed as **`Skill_HB_ApplyShortAndFloater_Inferred`** (role yes; product demangle open).  
**Terminal:** **false** (no runtime Confirmed).  
**Note:** Prior agent hung on Ghidra; this run completed live decompile + full deliverable set.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0058cc40` Skill_HB_ApplyShortAndFloater_Inferred | **accept-with-gaps** — CF/ABI/cdecl/sign/percent/floater/callers sealed; short-pool product English + queue plate open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): HP/heat/shield-merge / duration-timer / positive-amount-drain / thiscall / RET4 / percent-of-current / free-function-floater / 4-arg-ABI claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0058cc40` — sealed facts

1. **Body:** `0x0058cc40`–`0x0058cd54` inclusive (**277 B** / `0x115`).
2. **ABI:** **`__cdecl`**; stack `source*`, `target*`, `float amount`; return **EAX**; bare **`RET`**; callers **`ADD ESP, 0xC`**.
3. **Semantics:** Skill HB **short-pool apply + combat floater**:
   - Resolve host via vtbl **+0x214** (prefer target; source only when `target==null && source!=null`).
   - `deltaInt = trunc(amount)`; if `amount ∈ [-1.0, 1.0]` then `trunc(maxShort*amount)` with `maxShort = *(short*)(host+0x12e)`.
   - `old = *(short*)(host+0x12c)`; set via vtbl **+0xAC**(`old + deltaInt`); `applied = new - old`.
   - Unconditional floater type **2**: colors from `source+0x160` (or `DAT_009d4d28`) and `target+0x160`.
   - Enqueue `Client_EnqueueCombatFloater_INFERRED` with **`ECX = *(target+0xA4) + 0xE8A4`**.
   - Return applied short delta (0 if host null).
4. **Sign convention:** float **+ → increase short**, float **− → decrease**. Damage parents multiply by **`DAT_00aaa668` (-1.0f)**.
5. **Constants:** `DAT_00aaa668` = -1.0f; `g_flOne` @ `0x00a0f2a0` = 1.0f; color quad `{−1,−1,0,0}` as u32.
6. **Callees:** `Client_EnqueueCombatFloater_INFERRED` (`0x00402620`) + virtuals +0x214 / +0xAC.
7. **Callers / xrefs (5):**  
   - `FUN_0061b6f0` @ `0x0061b8c3`  
   - `FUN_00618270` @ `0x0061862f`  
   - `0x0061bea1`, `0x0061e8aa`, `0x0061ea23`
8. **Parent gate:** `*(byte*)(skill+0x649) & 0x80`; amount `skill[0x6c4]*skill[0x64]`.
9. **Name:** `Skill_HB_ApplyShortAndFloater_Inferred` (Ghidra `FUN_0058cc40`). No `Named_CalleeOf_*` scaffold present.
10. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory` + call-site context. Assembly corrects decompiler CONCAT22 / missing floater thiscall.

### Gaps

- Product English for short resource at **+0x12c / +0x12e**.  
- Product English for vtbl **+0x214 / +0xAC** and queue **+0xE8A4**.  
- Floater type **2** plate name.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0058cc40_Skill_HB_ApplyShortAndFloater_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0058cc40_Skill_HB_ApplyShortAndFloater_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0058cc40_FUN_0058cc40.md` |
| Annotated | `docs/reconstruction/raw/aa_0058cc40_FUN_0058cc40.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Skill_HB_ApplyShortAndFloater_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0058cc40.cpp` |
| Function | `docs/reconstruction/functions/aa_0058cc40_FUN_0058cc40.md` |
| Function named | `docs/reconstruction/functions/aa_0058cc40_Skill_HB_ApplyShortAndFloater_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_0061b6f0  Skill HB OnHeartBeat dispatcher  [parent dual context; not OWN]
  ├─ FUN_005787a0  Skill_HB_RescheduleStatus     [MEGA-004]
  ├─ FUN_00589bc0  Skill_HB_ApplyHeatDelta       [MEGA-005]
  ├─ FUN_00589c70  Skill_HB_ApplyHpDelta_Inferred [MEGA-006]
  ├─ FUN_00589d90  Skill_HB_ApplyShieldPool      [MEGA-007]
  ├─ FUN_0058cc40  Skill_HB_ApplyShortAndFloater_Inferred [OWN MEGA-008]
  │    └─ Client_EnqueueCombatFloater_INFERRED (0x00402620)  [shared]
  └─ FUN_0058d8e0  Skill_HB_ApplyMultiArgEffect  [MEGA-009]

FUN_00618270  peer HB path
  └─ FUN_0058cc40  [OWN MEGA-008]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0058cc40-mega-008-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0058cc40` | Port as **skill HB short-pool apply + floater**. **`__cdecl`** 3 args. **Positive amount increases** short @+0x12c; **negative decreases**. `\|amount\|≤1` → fraction of **max** short @+0x12e. Always enqueue floater **type 2** via queue at `*(target+0xA4)+0xE8A4`. Do **not** merge with heat `00589bc0`, HP `00589c70`, or shield `00589d90`. Do **not** treat as duration/timer (that is reschedule `005787a0`). |
| Pair with | parent HB dispatcher `0061b6f0`; floater `00402620`; siblings heat/HP/shield/multi. |

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

- OWN VA only (`0x0058cc40`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + call-site context + parent/callee samples. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean sources use meaningful `_Inferred` name; twin keeps `FUN_0058cc40`.  
- Odd behavior preserved: floater path null-target loads; decompiler CONCAT22 corrected via assembly.  
- Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
