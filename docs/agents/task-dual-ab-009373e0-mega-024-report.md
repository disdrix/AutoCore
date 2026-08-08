# Dual A/B report — MEGA-024 OWN-ONLY (`0x009373e0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-024**  
**Scope:** VA `0x009373e0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + `get_function_xrefs` / `get_xrefs_to` + `get_assembly_context` + `analyze_control_flow`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_mega_residual_partition_map.md` → **MEGA-024**.  
**Work item:** residual dual seal — **dialog UI park** (dialog gate thr0+steer0+HB).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_009373e0` Client_DialogGate_OpenIndex10_ParkDriveAxes_Inferred | **accept-with-gaps** — CF/ABI/EDI-host/dialog-index-10/caption-host+0x1058/thr0+steer0+HB1/tail-JMP/sole-caller sealed; product dialog-slot English open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): void-ABI / HB=0 / ECX-thiscall / always-park / multi-caller / merge-with-0092f090 / scaffold-ABI-complete claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x009373e0` — sealed facts

1. **Body:** `0x009373e0`–`0x00937462` inclusive (**131 B** / `0x83`); pad `CC` after.
2. **ABI:** **EDI** = client host; stack **1 dword** stamp; void; **`RET 4`**. Vehicle HB path **tail-JMPs** `VehicleEntity_SetHandbrake` after rewriting `[ESP+4]=1`.
3. **Semantics:**
   - Gate: `[EDI+0xf40] != 0` and `**[EDI+0xf40] == *[EDI+0xf38]`.
   - `Client_OpenDialogByIndex(EDI, 10, 0, 0)`.
   - `MissionDialog_SetNpcObjectAndNameCaption([EDI+0x1058], stamp)` (`FUN_008aa4b0`).
   - If actor `[EDI+0xe98]` and vehicle `+0x250`: thr **0**, steer **0**, handbrake **1**.
4. **Callees:** `0x007fef20`, `0x008aa4b0`, `0x004f5650`, `0x004f5620`, `0x004f3620`.
5. **Callers:** **1** UNCONDITIONAL_CALL @ `0x00952b25` (stub `0x00952b20`: push 0, `MOV EDI,ECX`, call, `EAX=1`, `RET 8`).
6. **Xrefs:** 1× UNCONDITIONAL_CALL.
7. **Name:** `Client_DialogGate_OpenIndex10_ParkDriveAxes_Inferred` (Ghidra `FUN_009373e0`). Product English open → `_Inferred`. No Named_CalleeOf_ scaffold for this VA.
8. **Decompile ≡ raw CF**; ABI/HB polarity sealed via `disassemble_function` + `read_memory` + call-site context (scaffold void/`SetHandbrake()` corrected).
9. **System:** `input-drive-control`.

### Gaps

- Product English for dialog index **10**.  
- Product name of caller stub `0x00952b20` / reason for `RET 8`.  
- Product English for `f40`/`f38` host equality.  
- Sibling pure-park `0x0092f090` residual (MEGA-021).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_009373e0_Client_DialogGate_OpenIndex10_ParkDriveAxes_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_009373e0_Client_DialogGate_OpenIndex10_ParkDriveAxes_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_009373e0_FUN_009373e0.md` |
| Annotated | `docs/reconstruction/raw/aa_009373e0_FUN_009373e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_DialogGate_OpenIndex10_ParkDriveAxes_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_009373e0.cpp` |
| Function | `docs/reconstruction/functions/aa_009373e0_FUN_009373e0.md` |
| Function named | `docs/reconstruction/functions/aa_009373e0_Client_DialogGate_OpenIndex10_ParkDriveAxes_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
stub 0x00952b20  (vmethod; RET 8; returns 1)  [residual]
  └─ FUN_009373e0  Client_DialogGate_OpenIndex10_ParkDriveAxes_Inferred  [OWN MEGA-024]
        ├─ Client_OpenDialogByIndex (0x007fef20) index=10  [dualed]
        ├─ MissionDialog_SetNpcObjectAndNameCaption_Inferred (0x008aa4b0)  [dualed MEGA-058]
        ├─ VehicleEntity_SetLongitudinalInput (0x004f5650) 0  [dualed]
        ├─ VehicleEntity_SetSteerInput (0x004f5620) 0  [dualed]
        └─ VehicleEntity_SetHandbrake (0x004f3620) 1  [dualed; tail JMP]

Sibling (not this VA):
  FUN_0092f090  pure thr0/steer0/HB1 park (no dialog open)  [MEGA-021 residual]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-009373e0-mega-024-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `009373e0` | Port as **dialog-gated open-index-10 + mission-dialog caption stamp + vehicle axis park**. **EDI=client**, stack stamp, **RET 4**. Axes: thr **0**, steer **0**, handbrake **1** (not all-zero). Keep distinct from pure park `0092f090` and interact thr0+HB `00938670`. |
| Pair with | dualed `Client_OpenDialogByIndex` `007fef20`; dualed caption `008aa4b0`; dualed vehicle setters `004f5650`/`004f5620`/`004f3620`; residual stub `00952b20`; residual pure park `0092f090`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/*` residual tables (`input-drive-control`)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x009373e0`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + call-site context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended**.  
- Clean sources use meaningful `_Inferred` name; twin `FUN_009373e0.cpp` updated.  
- Odd behavior preserved: HB=1 while thr/steer=0; custom EDI ABI; caption helper on park path; tail JMP to SetHandbrake.  
- Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
