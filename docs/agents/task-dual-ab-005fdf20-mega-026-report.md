# Dual A/B report — MEGA-026 OWN-ONLY (`0x005fdf20`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-026**  
**Scope:** VA `0x005fdf20` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + callers/xrefs + `get_assembly_context` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual partition — input-drive-control filtered steer leaf of `hkDefaultAnalogDriverInput_calcStatus`.  
**Hint:** filtered steer / calcStatus.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_005fdf20` hkDefaultAnalogDriverInput_FilterSteer_Inferred | **accept-with-gaps** — CF/ABI/ST0/plain-RET/leaf/sole-caller→+0x14/offsets/constants sealed; product helper English open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): accel/brake-misname / calcStatus-merge / RET4 / EAX-return / non-leaf / wrong-deadzone / non-−1-DAT claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x005fdf20` — sealed facts

1. **Body:** `0x005fdf20`–`0x005fdf97` inclusive (**120 B** / `0x78`); pad `CC` after.
2. **ABI:** **ECX** = this (`hkDefaultAnalogDriverInput*`); **no stack args**; **plain `RET`** ×3 exits; return **float on FPU ST0**.
3. **Semantics:** piecewise-linear **filtered steer**:
   - `abs = |this.+0x1c|`
   - if `abs < this.+0x38` (deadzone): return `0`
   - `sign = (raw > 0) ? +1 : −1` (`g_flOne` / `DAT_00aaa668`)
   - if `abs < this.+0x28`: return `(abs − deadzone) * +0x2c * sign`
   - else: return `((abs − +0x28) * +0x30 + +0x34) * sign`
4. **Globals:** `g_flZero` @ `0x00a0f518` = `0.0f`; `g_flOne` @ `0x00a0f2a0` = `1.0f`; `DAT_00aaa668` = `−1.0f` (`00 00 80 bf`).
5. **Callees:** **none** (leaf).
6. **Callers:** **1** — `hkDefaultAnalogDriverInput_calcStatus` @ `0x005fe520`; site `0x005fe58d` (`MOV ECX,ESI` / `CALL` / `FSTP [ESI+0x14]`).
7. **Xrefs:** 1 UNCONDITIONAL_CALL.
8. **Name:** `hkDefaultAnalogDriverInput_FilterSteer_Inferred` (Ghidra `FUN_005fdf20`). Product helper English open → `_Inferred`.
9. **Decompile ≡ raw CF**; ABI/offsets sealed via `disassemble_function` + `read_memory` + call-site context.
10. **System:** input-drive-control (parent plate WI-MOV-005: `+0x14 steer via FUN_005fdf20`).

### Gaps

- Product / Havok SDK English for this exact leaf (may be inlined in SDK `calcStatus`).  
- Tuning-field product names for `+0x28..+0x38` beyond structural roles.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005fdf20_hkDefaultAnalogDriverInput_FilterSteer_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005fdf20_hkDefaultAnalogDriverInput_FilterSteer_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_005fdf20_FUN_005fdf20.md` |
| Annotated | `docs/reconstruction/raw/aa_005fdf20_FUN_005fdf20.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/hkDefaultAnalogDriverInput_FilterSteer_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005fdf20.cpp` |
| Function | `docs/reconstruction/functions/aa_005fdf20_FUN_005fdf20.md` |
| Function named | `docs/reconstruction/functions/aa_005fdf20_hkDefaultAnalogDriverInput_FilterSteer_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
hkDefaultAnalogDriverInput_calcStatus  0x005fe520  [prior scaffold; not dualled here]
  ├─ pedal(+0x20) → status.+0x0c accel  (sign-flip path uses DAT_00aaa668)
  ├─ pedal(+0x20) → status.+0x10 brake
  ├─ FUN_005fdf20  hkDefaultAnalogDriverInput_FilterSteer_Inferred  [OWN MEGA-026]
  │     └─ result → status.+0x14 steer
  ├─ ctrl(+0x24) → status.+0x18 handbrake
  └─ hkDefaultAnalogDriverInput_calcReverse  0x005fe0b0
        └─ result → status.+0x19 reverse
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-005fdf20-mega-026-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `005fdf20` | Port as **leaf filtered-steer** on analog driver input. **ECX=this**, plain **RET**, float **ST0**. Deadzone `+0x38`, inner `+0x28/+0x2c`, outer `+0x30/+0x34`, raw `+0x1c`. |
| Caller contract | `calcStatus` must `FSTP` result to **status.+0x14**. Keep distinct from pedal→accel/brake and `calcReverse`. |
| Constants | Share `DAT_00aaa668 = −1.0f` with pedal sign path; `g_flZero` / `g_flOne` for 0/+1. |
| Naming | `_Inferred` until product/Havok SDK symbol is sealed. Do not invent retail method name. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- coverage / naming ledgers if used
- optional cross-link from `aa_005fe520` calcStatus artifacts to this named leaf
