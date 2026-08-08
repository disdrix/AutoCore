# Dual A/B report — R11-023 OWN-ONLY (`0x00636cc0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R11-023**  
**Scope:** VA `0x00636cc0` (`aa_00636cc0`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs (including sibling `0x00636d10` and ctor `0x00636bd0` duals).  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** R11 residual dual seal — undualed OnHeartBeat callee of dualed `CVOGHBMoveVehicle_OnEnd` parent `0x00636ba0` → **MoveToTarget fire + Stop on fail**.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00636cc0` CVOGHBMoveVehicle_OnHeartBeat | **accept-with-gaps** — CF/ABI/RET4/vtbl+0x0c/entity@+0x24/MoveTo thiscall/Stop-on-fail/status outs sealed; status-1 English + runtime open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): decompiler-this-at-+0x2c / OnEnd-merge / AxisPark-merge / entity-as-ECX-whole / status-1=Remove / cdecl / direct-caller / runtime Confirmed claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00636cc0` — sealed facts

1. **Body:** `0x00636cc0`–`0x00636d07` inclusive (**72 B** / `0x48`); pad `CC` before `FUN_00636d10` @ `0x00636d10`.
2. **ABI:** **ECX** = `CVOGHBMoveVehicle* this`; stack **`uint32_t* pOutStatus`**; **`RET 4`**; EAX = pOutStatus on exit.
3. **Semantics:**
   - entity null @ `+0x24` → `*out = DAT_00af4f84` (**1**)
   - else `MoveToTarget3DPoint(entity, +0x2c, +0x30, +0x34, allowReverse=1)` with **ECX=entity**
   - MoveTo AL==0 → `CVOGHBBase_Stop(this)`
   - entity path → `*out = DAT_00d02c60` (**0** Continue)
4. **Decompiler gap:** raw decompile mis-binds MoveTo `this` to `*(this+0x2c)`; machine keeps entity in ECX. Clean follows machine.
5. **Callees:** `0x004fc650` MoveToTarget3DPoint; `0x005081d0` CVOGHBBase_Stop.
6. **Callers:** **0** code CALL; **2** DATA — `0x009e3b7c`, `0x009d559c` (vtbl+0x0c base + ToMouse).
7. **Name:** `CVOGHBMoveVehicle_OnHeartBeat` (Ghidra `FUN_00636cc0`). RTTI class sealed via parent dual; slot +0x0c = OnHeartBeat via TryFire convention.
8. **CF sealed** via `disassemble_function` + `read_memory`.

### Gaps

- Product English for out-status **1**.  
- Ctor `00636bd0` / dtor `00636d10` residual duals.  
- Entity aim writer (`+0x190`) provenance.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00636cc0_CVOGHBMoveVehicle_OnHeartBeat.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00636cc0_CVOGHBMoveVehicle_OnHeartBeat.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00636cc0_FUN_00636cc0.md` |
| Annotated | `docs/reconstruction/raw/aa_00636cc0_FUN_00636cc0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBMoveVehicle_OnHeartBeat.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00636cc0.cpp` |
| Function | `docs/reconstruction/functions/aa_00636cc0_FUN_00636cc0.md` |
| Function named | `docs/reconstruction/functions/aa_00636cc0_CVOGHBMoveVehicle_OnHeartBeat.md` |

---

## Chain context (not dualled; evidence only)

```text
CVOGHBMoveVehicle  vtbl 009e3b70  (ctor FUN_00636bd0 residual)
  [+0x0c] FUN_00636cc0  CVOGHBMoveVehicle_OnHeartBeat  [OWN R11-023]
       ├─ MoveToTarget3DPoint  004fc650  [verified drive controller]
       └─ on fail → CVOGHBBase_Stop  005081d0  [dualed]
            └─ [+0x10] CVOGHBMoveVehicle_OnEnd  00636ba0  [dualed MEGA-017]
                 SetSteer(0)+Push only

  [+0x10] FUN_00636ba0  CVOGHBMoveVehicle_OnEnd       [parent dual; not re-owned]
  ToMouse vtbl 009d5590 shares OnHeartBeat + OnEnd pointers

Sibling residual (not OWN): ctor 00636bd0, dtor 00636d10 (R11-024 neighbor).
```

Partition system **input-drive-control** matches parent OnEnd chain; unit is HB fire that generates AI drive axes then optionally stops.

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00636cc0-r11-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00636cc0` | Port as **`CVOGHBMoveVehicle::OnHeartBeat`**: null entity → status 1; else MoveTo(entity, accept, cruise, aimUnused, reverse=1); fail → Stop; status 0. **thiscall + RET 4**. |
| Critical | MoveTo **this** is **entity @ +0x24**, never acceptDist float @ +0x2c. |
| Pair with | dualed OnEnd `00636ba0`; Stop `005081d0`; TryFire `005082c0`; verified MoveTo `004fc650`. |
| Do not merge | OnEnd body; AI AxisPark `005d73a0`; DriveControlTick; treat HB ECX as vehicle for whole function. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md` / coverage / naming registry when the merge agent runs.
- Record first dual seal for `aa_00636cc0` as `CVOGHBMoveVehicle_OnHeartBeat`.
