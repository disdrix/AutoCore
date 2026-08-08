# Dual A/B report — R12-028 OWN-ONLY (`0x005996a0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R12-028**  
**Scope:** VA `0x005996a0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs (including complete body `0x00599570`, base scalar `0x00636d10`, ctor `0x00599550`).  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + callers/xrefs + `read_memory` (body/vtbl/RTTI). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** R12-028 residual dual seal — input-drive-control `CVOGHBMoveVehicleToMouse` MSVC scalar-deleting destructor (vtbl[0]).  
**Partition:** `WAVE_2026-08-05_r12_residual_partition_map.md` → R12-028.  
**Parent dual:** `0x00636d10` (R11-024 `CVOGHBMoveVehicle_ScalarDeletingDtor`).  
**Dual start:** 2646.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_005996a0` CVOGHBMoveVehicleToMouse_ScalarDeletingDtor | **accept** — CF/ABI/vtbl[0]/RTTI product name/scalar pattern sealed; complete body dual residual; runtime open |

Path A (fidelity): **accept**.  
Path B (adversarial): vector-dtor / noreturn-delete / code-callers / MoveVehicle-share / OnEnd-merge / cdecl / `_Inferred`-required claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher). **Never Runtime Confirmed.**

---

## VA `0x005996a0` — sealed facts

1. **Body:** `0x005996a0`–`0x005996bd` inclusive (**30 B** / `0x1E`); pad `CC CC` then `C3`/pad.
2. **ABI:** **ECX** = `CVOGHBMoveVehicleToMouse* this`; stack **`uint8_t flags`**; ends **`RET 4`**; returns **`this*`** in **EAX**.
3. **Semantics:** MSVC **scalar-deleting destructor** (`vtbl[0]`):
   - Always `FUN_00599570(this)` (complete/body: `*this = &PTR_FUN_009d5590`; chain `FUN_00636b90`).
   - If `(flags & 1)` → `operator_delete(this)` + `ADD ESP,4`.
   - Always return `this`.
4. **RTTI:** `.?AVCVOGHBMoveVehicleToMouse@@` @ `0x00af33e0`.
5. **DATA xrefs:** `0x009d5590` only (`PTR_FUN_009d5590` dword0).
6. **Code callers:** **none** — virtual dispatch via vtbl[0].
7. **Callees:** `0x00599570` ToMouse complete/body; `0x00489822` `operator_delete`.
8. **Not shared:** base MoveVehicle vtbl `PTR_FUN_009e3b70` dword0 = `0x00636d10` (parent dual).
9. **Name:** `CVOGHBMoveVehicleToMouse_ScalarDeletingDtor` (Ghidra `FUN_005996a0`). Product class RTTI-sealed; role = MSVC scalar pattern. **No** `_Inferred`.
10. **Decompile ≡ raw** for if/call CF; **decompiler/disasm** may mark delete noreturn / omit `ADD ESP,4` — sealed by `read_memory` bytes.
11. **Hex:** `568bf1e8c8fefffff644240801740956e86d01efff83c4048bc65ec20400`

### Gaps

- Runtime / bit-exact / differential.  
- Complete body dual `FUN_00599570` residual (other VA).  
- PDB method symbol beyond RTTI + scalar convention.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005996a0_CVOGHBMoveVehicleToMouse_ScalarDeletingDtor.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_005996a0_CVOGHBMoveVehicleToMouse_ScalarDeletingDtor.md` | **accept** |

### Files (trio + function records)

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_005996a0_FUN_005996a0.md` |
| Annotated | `docs/reconstruction/raw/aa_005996a0_FUN_005996a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBMoveVehicleToMouse_ScalarDeletingDtor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005996a0.cpp` |
| Function | `docs/reconstruction/functions/aa_005996a0_FUN_005996a0.md` |
| Function named | `docs/reconstruction/functions/aa_005996a0_CVOGHBMoveVehicleToMouse_ScalarDeletingDtor.md` |

---

## Chain context (not dualled; evidence only)

```text
PTR_FUN_009d5590  CVOGHBMoveVehicleToMouse vtbl
  [0] 005996a0  CVOGHBMoveVehicleToMouse_ScalarDeletingDtor  [OWN R12-028]
  [3] 00636cc0  OnHeartBeat / fire                           [shared; residual dualed]
  [4] 00636ba0  CVOGHBMoveVehicle_OnEnd                      [shared; MEGA-017 dualed]

FUN_00599570  ToMouse complete/body  [residual]
  ├─ *this = &PTR_FUN_009d5590
  └─ FUN_00636b90  MoveVehicle complete → base

FUN_00599550  CVOGHBMoveVehicleToMouse ctor  [residual]
  └─ FUN_00636bd0 base ctor then install PTR_FUN_009d5590

Contrast (do not merge):
  00636d10  CVOGHBMoveVehicle_ScalarDeletingDtor  [parent dual R11-024]
  00508630  CVOGHBBase_ScalarDeletingDtor         [dualed family]
  00636ba0  OnEnd steer park                      [not a dtor]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-005996a0-r12-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `005996a0` | Port as **`CVOGHBMoveVehicleToMouse` scalar-deleting dtor**. **thiscall**, stack **flags**, **RET 4**, return **this**. Always run complete body first; free only if **bit0**. Virtual only (`vtbl[0]`). |
| Pair with | residual complete `00599570`; dualed shared OnEnd `00636ba0`; parent dual base scalar `00636d10` (do not merge bodies). |
| Do not merge | MoveVehicle scalar `00636d10`; OnEnd/fire; vector-deleting form; base scalar `00508630`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- coverage / naming / system maps as applicable  
- residual complete body dual `00599570` if scheduled
