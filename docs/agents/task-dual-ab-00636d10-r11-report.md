# Dual A/B report — R11-024 OWN-ONLY (`0x00636d10`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R11-024**  
**Scope:** VA `0x00636d10` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + callers/xrefs + `read_memory` (body/vtbl/RTTI). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** R11-024 residual dual seal — input-drive-control `CVOGHBMoveVehicle` MSVC scalar-deleting destructor (vtbl[0]).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00636d10` CVOGHBMoveVehicle_ScalarDeletingDtor | **accept** — CF/ABI/vtbl[0]/RTTI product name/scalar pattern sealed; complete body dual residual; runtime open |

Path A (fidelity): **accept**.  
Path B (adversarial): vector-dtor / noreturn-delete / code-callers / ToMouse-share / OnEnd-merge / cdecl claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00636d10` — sealed facts

1. **Body:** `0x00636d10`–`0x00636d2d` inclusive (**30 B** / `0x1E`); pad `CC CC` before next `0x00636d30`.
2. **ABI:** **ECX** = `CVOGHBMoveVehicle* this`; stack **`uint8_t flags`**; ends **`RET 4`**; returns **`this*`** in **EAX**.
3. **Semantics:** MSVC **scalar-deleting destructor** (`vtbl[0]`):
   - Always `FUN_00636b90(this)` (complete/body: `*this = &PTR_FUN_009e3b70`; chain `FUN_00508390`).
   - If `(flags & 1)` → `operator_delete(this)` + `ADD ESP,4`.
   - Always return `this`.
4. **RTTI:** `.?AVCVOGHBMoveVehicle@@` @ `0x00af33c0`.
5. **DATA xrefs:** `0x009e3b70` only (`PTR_FUN_009e3b70` dword0).
6. **Code callers:** **none** — virtual dispatch via vtbl[0].
7. **Callees:** `0x00636b90` complete/body; `0x00489822` `operator_delete`.
8. **Not shared:** ToMouse vtbl `PTR_FUN_009d5590` dword0 = `0x005996a0`.
9. **Name:** `CVOGHBMoveVehicle_ScalarDeletingDtor` (Ghidra `FUN_00636d10`). Product class RTTI-sealed; role = MSVC scalar pattern.
10. **Decompile ≡ raw** for if/call CF; **decompiler** may mark delete noreturn / omit `ADD ESP,4` — sealed by disasm + `read_memory`.

### Gaps

- Runtime / bit-exact / differential.  
- Complete body dual `FUN_00636b90` residual (other VA).  
- PDB method symbol beyond RTTI + scalar convention.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00636d10_CVOGHBMoveVehicle_ScalarDeletingDtor.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_00636d10_CVOGHBMoveVehicle_ScalarDeletingDtor.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00636d10_FUN_00636d10.md` |
| Annotated | `docs/reconstruction/raw/aa_00636d10_FUN_00636d10.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBMoveVehicle_ScalarDeletingDtor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00636d10.cpp` |
| Function | `docs/reconstruction/functions/aa_00636d10_FUN_00636d10.md` |
| Function named | `docs/reconstruction/functions/aa_00636d10_CVOGHBMoveVehicle_ScalarDeletingDtor.md` |

---

## Chain context (not dualled; evidence only)

```text
PTR_FUN_009e3b70  CVOGHBMoveVehicle vtbl
  [0] 00636d10  CVOGHBMoveVehicle_ScalarDeletingDtor  [OWN R11-024]
  [3] 00636cc0  fire / MoveToTarget                    [residual R11-023]
  [4] 00636ba0  CVOGHBMoveVehicle_OnEnd                [MEGA-017 dualed]

FUN_00636b90  complete/body  [residual]
  ├─ *this = &PTR_FUN_009e3b70
  └─ FUN_00508390  CVOGHBBase complete dtor

FUN_00636bd0  CVOGHBMoveVehicle ctor  [residual]
  └─ install PTR_FUN_009e3b70; this+0x24 = vehicle entity

Contrast (do not merge):
  00508630  CVOGHBBase_ScalarDeletingDtor  [dualed family]
  005996a0  CVOGHBMoveVehicleToMouse scalar shell  [different dword0]
  00636ba0  OnEnd steer park  [not a dtor]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00636d10-r11-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00636d10` | Port as **`CVOGHBMoveVehicle` scalar-deleting dtor**. **thiscall**, stack **flags**, **RET 4**, return **this**. Always run complete body first; free only if **bit0**. Virtual only (`vtbl[0]`). |
| Pair with | residual complete `00636b90`; dualed OnEnd `00636ba0`; dualed base scalar `00508630` (do not merge bodies). |
| Do not merge | ToMouse scalar `005996a0`; OnEnd/fire; vector-deleting form. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- coverage / naming / system maps as applicable  
- residual complete body dual `00636b90` if scheduled
