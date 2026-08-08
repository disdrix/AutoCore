# Dual A/B report — R12-006 OWN-ONLY (`0x00636bd0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R12-006**  
**Scope:** VA `0x00636bd0` (`aa_00636bd0`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs (including parent `0x00636cc0`, sibling dtor `0x00636d10`, ToMouse ctor `0x00599550`).  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** R12 residual dual seal — undualed ctor of dualed parent `CVOGHBMoveVehicle_OnHeartBeat` `0x00636cc0` → **entity bind + drive defaults + dual-period HB setup**.  
**Partition:** `WAVE_2026-08-05_r12_residual_partition_map.md` → R12-006; system **input-drive-control**; dual start **2646**; **Terminal false**.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00636bd0` CVOGHBMoveVehicle_ctor | **accept-with-gaps** — CF/ABI/RET4/vtbl/RTTI class/field defaults/dual-period/Attach arms sealed; flag English + MI owner type + runtime open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): OnHB/OnEnd/dtor-merge / period=-1000 fire / float-slot swap / attach-raw-only / multi-caller / ToMouse-vtbl-here / runtime Confirmed claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00636bd0` — sealed facts

1. **Body:** `0x00636bd0`–`0x00636c49` inclusive (**122 B** / `0x7A`); pad `CC` from `0x00636c4a`.
2. **ABI:** **ECX** = `CVOGHBMoveVehicle* this`; stack **`void* pEntity`**; **`RET 4`**; **EAX = this**.
3. **Semantics:**
   - `CVOGHBBase_ctor` → install vtbl **`PTR_FUN_009e3b70`**
   - `SetPeriodAndCounter(-1000, true)` then **`+0x08 = 50`** (dual period)
   - Drive defaults: **`+0x2c = 2.5f`**, **`+0x30 = 0.0f`**, **`+0x34 = 15.0f`** bits
   - **`+0x24 = pEntity`** (raw); **`+0x29 = 0`**
   - null entity → `AttachOwner(null)`; else MI this-adjust then Attach
4. **Callees:** `0x00508200` Base ctor; `0x005081a0` SetPeriod; `0x005083b0` Attach (×2).
5. **Callers:** **1** code CALL — `FUN_00599550` @ `0x00599558` (ToMouse subclass ctor).
6. **Name:** `CVOGHBMoveVehicle_ctor` (Ghidra `FUN_00636bd0`). RTTI class sealed via sibling duals; ctor role from body. **No `_Inferred`** (product class English sealed).
7. **CF sealed** via `disassemble_function` + `read_memory`.

### Gaps

- Product English for flag **`+0x29`**.  
- MI-adjusted Attach owner product type.  
- ToMouse ctor `00599550` residual (other VA).  
- Whether aim default `+0x34` is overwritten before MoveTo.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00636bd0_CVOGHBMoveVehicle_ctor.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00636bd0_CVOGHBMoveVehicle_ctor.md` | **accept-with-gaps** |

### Files (trio + function records)

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00636bd0_FUN_00636bd0.md` |
| Annotated | `docs/reconstruction/raw/aa_00636bd0_FUN_00636bd0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBMoveVehicle_ctor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00636bd0.cpp` |
| Function | `docs/reconstruction/functions/aa_00636bd0_FUN_00636bd0.md` |
| Function named | `docs/reconstruction/functions/aa_00636bd0_CVOGHBMoveVehicle_ctor.md` |

---

## Chain context (not dualled; evidence only)

```text
CVOGHBMoveVehicle  vtbl 009e3b70
  ctor FUN_00636bd0  CVOGHBMoveVehicle_ctor  [OWN R12-006]
       ├─ CVOGHBBase_ctor           00508200  [dualed]
       ├─ SetPeriodAndCounter       005081a0  [dualed]
       └─ AttachOwnerObject         005083b0  [dualed]
            entity@+0x24 raw; owner@+0x18 attach; defaults for OnHB

  [+0x0c] FUN_00636cc0  OnHeartBeat  [parent dual R11-023 — not re-owned]
  [+0x10] FUN_00636ba0  OnEnd        [MEGA-017 — not re-owned]
  [+0x00] FUN_00636d10  ScalarDtor   [R11-024 — not re-owned]

Sole code caller (not OWN):
  FUN_00599550  ToMouse ctor → calls this then *this = 009d5590; +0x40 = param_3
```

Partition system **input-drive-control** matches parent OnHeartBeat chain; unit is the factory that binds entity + MoveTo defaults.

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00636bd0` | Port as **`CVOGHBMoveVehicle` ctor**: base → vtbl → SetPeriod(-1000,true) → pulse 50 → defaults 2.5/0/15f → entity@+0x24 → Attach. **thiscall + RET 4**. |
| Critical | Dual period: **-1000 is sentinel**, fire interval is **`+0x08=50`**. Entity@+0x24 is **raw** arg; Attach owner may be MI-adjusted. |
| Pair with | dualed OnHB `00636cc0`; OnEnd `00636ba0`; dtor `00636d10`; Base ctor/SetPeriod/Attach. |
| Do not merge | ToMouse body `00599550`; OnHB fire; treat -1000 as pulse; swap 2.5/15 float slots. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md` / coverage / naming registry when the merge agent runs.
- Record first dual seal for `aa_00636bd0` as `CVOGHBMoveVehicle_ctor`.

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00636bd0-r12-report.md` |
