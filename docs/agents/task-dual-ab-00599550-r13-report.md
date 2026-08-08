# Dual A/B report — R13-007 OWN-ONLY (`0x00599550`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R13-007**  
**Scope:** VA `0x00599550` (`aa_00599550`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs (including parent scalar `0x005996a0` re-dual, base ctor `0x00636bd0`, complete body `0x00599570`).  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + callers/xrefs + `read_memory` (body/vtbl/RTTI). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** R13-007 residual dual seal — input-drive-control `CVOGHBMoveVehicleToMouse` constructor (base chain + ToMouse vtbl + host-ctx `+0x40`).  
**Partition:** `WAVE_2026-08-05_r13_residual_partition_map.md` → **R13-007**.  
**System:** input-drive-control.  
**Parent dual:** `0x005996a0` CVOGHBMoveVehicleToMouse_ScalarDeletingDtor (R12-028).  
**Dual start:** 2686.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00599550` CVOGHBMoveVehicleToMouse_ctor | **accept-with-gaps** — CF/ABI/RET8/RTTI/vtbl override/+0x40 store/size sealed; host-ctx product type English + complete body residual + runtime open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): scalar-dtor / complete-body / base-ctor-merge / RET4 / cdecl / `_Inferred`-required / entity-at-+0x40 / runtime Confirmed claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher). **Never Runtime Confirmed.**

---

## VA `0x00599550` — sealed facts

1. **Body:** `0x00599550`–`0x0059956f` inclusive (**32 B** / `0x20`); next function complete/body at `0x00599570`.
2. **ABI:** **ECX** = `CVOGHBMoveVehicleToMouse* this`; stack **`void* pEntity`**, **`void* pHostCtx`**; ends **`RET 8`**; returns **`this*`** in **EAX**.
3. **Semantics:** Subclass **constructor**:
   - `FUN_00636bd0(this, pEntity)` — dualed `CVOGHBMoveVehicle_ctor` (base HB + MoveVehicle vtbl + drive defaults).
   - `*this = &PTR_FUN_009d5590` — override to ToMouse vtbl.
   - `*(this+0x40) = pHostCtx` — host/world-sim ctx (callers pass `client+0xe04` / peer).
   - Return `this`.
4. **Object size:** **0x44** (`operator_new(0x44)` at all four call sites).
5. **RTTI:** `.?AVCVOGHBMoveVehicleToMouse@@` @ `0x00af33e0`.
6. **Callees:** `0x00636bd0` only (`CVOGHBMoveVehicle_ctor`, R12-006).
7. **Callers (4 code CALLs):**
   - `Client_CreateVehicleObjectApply` @ `0x0081299a`
   - `FUN_00810360` @ `0x0081057a`
   - `FUN_009147a0` @ `0x009147e5`
   - `FUN_0094b3a0` @ `0x0094b47f`
   - Pattern: `new(0x44)` → ctor → store HB at host/player **`+0xc70`** → `CVOGHBList_Enqueue`.
8. **Xrefs:** 4 UNCONDITIONAL_CALL (same).
9. **Name:** `CVOGHBMoveVehicleToMouse_ctor` (Ghidra `FUN_00599550`). Product class RTTI-sealed; ctor role from body. **No `_Inferred`**.
10. **Decompile ≡ raw ≡ machine** for straight-line CF (`param_1[0x10]` ≡ `+0x40`).
11. **Hex:** `8b44240456508bf1e873d609008b4c240cc70690559d00894e408bc65ec20800`

### Gaps

- Product English type name for field **`+0x40`** / `client+0xe04` (role sealed as world/sim ctx).  
- Complete body dual `FUN_00599570` residual (other VA).  
- ToMouse-only vtbl residual slots (e.g. `0x00599680`).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00599550_CVOGHBMoveVehicleToMouse_ctor.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00599550_CVOGHBMoveVehicleToMouse_ctor.md` | **accept-with-gaps** |

### Files (trio + function records)

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00599550_FUN_00599550.md` |
| Annotated | `docs/reconstruction/raw/aa_00599550_FUN_00599550.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBMoveVehicleToMouse_ctor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00599550.cpp` |
| Function | `docs/reconstruction/functions/aa_00599550_FUN_00599550.md` |
| Function named | `docs/reconstruction/functions/aa_00599550_CVOGHBMoveVehicleToMouse_ctor.md` |

---

## Chain context (not dualled; evidence only)

```text
PTR_FUN_009d5590  CVOGHBMoveVehicleToMouse vtbl
  [0] 005996a0  CVOGHBMoveVehicleToMouse_ScalarDeletingDtor  [parent dual R12-028]
  [3] 00636cc0  OnHeartBeat / fire                           [shared; residual dualed]
  [4] 00636ba0  CVOGHBMoveVehicle_OnEnd                      [shared; MEGA-017 dualed]

FUN_00599550  CVOGHBMoveVehicleToMouse_ctor  [OWN R13-007]
  ├─ FUN_00636bd0  CVOGHBMoveVehicle_ctor  [R12-006 dualed]
  │    ├─ CVOGHBBase_ctor / SetPeriod / Attach
  │    └─ install PTR_FUN_009e3b70 then overridden by this unit
  ├─ *this = &PTR_FUN_009d5590
  └─ *(this+0x40) = pHostCtx

FUN_00599570  ToMouse complete/body  [residual]
  ├─ *this = &PTR_FUN_009d5590
  └─ FUN_00636b90  MoveVehicle complete → base

Factories (not OWN):
  Client_CreateVehicleObjectApply / FUN_00810360 / FUN_009147a0 / FUN_0094b3a0
    operator_new(0x44) → FUN_00599550 → host+0xc70 → CVOGHBList_Enqueue

Contrast (do not merge):
  00636bd0  CVOGHBMoveVehicle_ctor              [base; RET 4; vtbl 009e3b70]
  005996a0  ToMouse ScalarDeletingDtor          [parent dual]
  00599570  ToMouse complete/body               [residual]
  00636ba0  OnEnd steer park                    [not a ctor]
```

Partition system **input-drive-control** matches ToMouse HB move-to-mouse factory under vehicle create/switch paths.

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00599550-r13-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00599550` | Port as **`CVOGHBMoveVehicleToMouse` ctor**. **thiscall**, stack **pEntity + pHostCtx**, **RET 8**, return **this**. Size **0x44**. Always run base MoveVehicle ctor first; override vtbl to `009d5590`; store host ctx at **`+0x40`**. |
| Pair with | dualed base ctor `00636bd0`; parent dual scalar `005996a0`; dualed shared OnEnd `00636ba0`; residual complete `00599570`. |
| Do not merge | Base ctor body `00636bd0` (different RET/vtbl); scalar dtor `005996a0`; complete `00599570`; OnEnd/OnHB. |
| Naming caution | **No `_Inferred`** — RTTI seals class. Field `+0x40` product type English still open (role: client+0xe04 world/sim). |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/input-drive-control.md` residual tables  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  
- residual complete body dual `00599570` if scheduled  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x00599550`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + disassemble_function + read_memory + callers/xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean sources use RTTI product name (no `_Inferred`); machine ABI corrections (thiscall RET 8; `+0x40` host-ctx).  
- `_Inferred` only where English unproven (not applied to sealed class name). Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
