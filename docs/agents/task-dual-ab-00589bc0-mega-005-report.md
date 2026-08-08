# Dual A/B report — MEGA-005 OWN-ONLY (`0x00589bc0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-005**  
**Scope:** VA `0x00589bc0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `force_decompile` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_function_by_address` + parent/peer/callee samples. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual dual seal — partition row MEGA-005 / skills-abilities residual under dualed parent `0x0061b6f0`.  
**Hint consumed:** `Skill_HB_ApplyHeatDelta` → sealed as **`Skill_HB_ApplyHeatDelta_Inferred`** (role yes; product demangle open).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00589bc0` Skill_HB_ApplyHeatDelta_Inferred | **accept-with-gaps** — CF/ABI/cdecl-3arg/percent/RTTI/gate/AddHeat/callers sealed via assembly; decompiler wrong; product English + orphan sites + runtime open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): HP-merge / shield-merge / thiscall / 2-arg-only / adjustor-as-delta / inverted-sign / ungated-apply claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00589bc0` — sealed facts

1. **Body:** `0x00589bc0`–`0x00589c69` inclusive (**170 B** / `0xAA`); next sibling `FUN_00589c70` (ApplyHpDelta).
2. **ABI:** **`__cdecl`**; stack `source*` (unused), `target*`, `float amount`; return **EAX** int actual heat delta; bare **`RET`**; callers **`ADD ESP, 0xC`**.
3. **Semantics:** Skill HB **heat delta apply**:
   - RTTI `target` → `CVOGVehicle`; else `CVOGCreature` → vehicle* at **`+0x250`**.
   - `delta = trunc(amount)`; if `amount ∈ [-1.0, 1.0]` then `trunc(nMaxHeat * amount)` with max @ **`+0x244`**.
   - Snapshot cur @ **`+0x150`**; if netobj (MI+`0xA8`) non-null and `*(net+0x7E) != 0` → `Vehicle_AddHeat(vehicle, delta)`.
   - Return `heat' - cur` (0 if unresolved / gate skip / unchanged).
4. **Sign convention:** float **+ → heat**, float **− → cool**.
5. **Constants:** `DAT_00aaa668` = -1.0f; `g_flOne` @ `0x00a0f2a0` = 1.0f.
6. **Callees:** `__RTDynamicCast` (`0x004898a4`), `Vehicle_AddHeat` (`0x004f7210`).
7. **Callers / xrefs (5):**  
   - `FUN_0061b6f0` @ `0x0061b7d2` (heat float@`+0x114` × period@`+0x6c4`)  
   - `FUN_00618270` @ `0x0061858a`  
   - `0x0061beaf`, `0x0061e8de`, `0x0061ea44`
8. **Name:** `Skill_HB_ApplyHeatDelta_Inferred` (Ghidra `FUN_00589bc0`). No `Named_CalleeOf_*` scaffold present.
9. **Decompile ≠ assembly math** — clean follows **assembly**; raw scaffold body preserved; re-verify **appended**.

### Gaps

- Product English for this VA and netobj `+0x7E`.  
- Orphan/switch site function plates.  
- Dual seal of `Vehicle_AddHeat` full contract (out of OWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00589bc0_Skill_HB_ApplyHeatDelta_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00589bc0_Skill_HB_ApplyHeatDelta_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00589bc0_FUN_00589bc0.md` |
| Annotated | `docs/reconstruction/raw/aa_00589bc0_FUN_00589bc0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Skill_HB_ApplyHeatDelta_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00589bc0.cpp` |
| Function | `docs/reconstruction/functions/aa_00589bc0_FUN_00589bc0.md` |
| Function named | `docs/reconstruction/functions/aa_00589bc0_Skill_HB_ApplyHeatDelta_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_0061b6f0  Skill HB OnHeartBeat dispatcher  [parent dual context; not OWN]
  ├─ FUN_005787a0  Skill_HB_RescheduleStatus     [MEGA-004]
  ├─ FUN_00589bc0  Skill_HB_ApplyHeatDelta_Inferred [OWN MEGA-005]
  │    └─ Vehicle_AddHeat 004f7210               [shared residual]
  ├─ FUN_00589c70  Skill_HB_ApplyHpDelta         [MEGA-006]
  ├─ FUN_00589d90  Skill_HB_ApplyShieldPool      [MEGA-007]
  ├─ FUN_0058cc40  Skill_HB_ApplyShortAndFloater [MEGA-008]
  └─ FUN_0058d8e0  Skill_HB_ApplyMultiArgEffect  [MEGA-009]

FUN_00618270  peer HB path
  └─ FUN_00589bc0  [OWN MEGA-005]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00589bc0-mega-005-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00589bc0` | Port as **skill HB heat delta apply**. **`__cdecl`** 3 args. **Positive amount heats**, **negative cools**. `\|amount\|≤1` → fraction of **max** heat (`+0x244`). Gate on netobj `+0x7E` before `Vehicle_AddHeat`. Source arg unused. Do **not** trust Ghidra 2-arg decompile. Do **not** merge with HP `00589c70` or shield `00589d90`. |
| Pair with | parent HB dispatcher `0061b6f0`; `Vehicle_AddHeat` `004f7210`; siblings HP/shield/floater. |

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

- OWN VA only (`0x00589bc0`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + force_decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + parent/peer/callee samples. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean sources use assembly-corrected math under `_Inferred` name; twin keeps `FUN_00589bc0`.  
- Odd behavior preserved: unused source arg; apply gated by net+0x7E.  
- Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
