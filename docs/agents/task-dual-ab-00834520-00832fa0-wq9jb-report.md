# Dual A/B report — WQ9J-B OWN-ONLY (`0x00834520`, `0x00832fa0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **WQ9J-B**  
**Scope:** VAs `0x00834520`, `0x00832fa0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `batch_decompile` / `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + RTTI COL. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth7_partition_map.md` → **WQ9J-B**.  
**Work item:** WQ-009 depth-7 residual dual seal (UI complete dtors — CWndVehicle + CWndWaypointIcon).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00834520` CWndVehicle_CompleteDtor | **accept-with-gaps** — complete CF/ABI/vtbl/RTTI/nested+base order sealed; nested/helper product English open |
| `aa_00832fa0` CWndWaypointIcon_CompleteDtor | **accept-with-gaps** — complete CF/ABI/vtbl/RTTI/owned+0x488 free-null/base sealed; owned-block English open |

Path A (fidelity): both **accept-with-gaps**.  
Path B (adversarial): scalar/vector/host-free/cdecl/false-noreturn/wrong-class claims **falsified**; product RTTI sealed for both.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00834520` — sealed facts

1. **Body:** `0x00834520`–`0x008345b1` inclusive (**146 B** / `0x92`); `CC` pad then ctor `0x008345c0`.
2. **ABI:** **`__thiscall`**; ECX = this; SEH `LAB_009b4563`; bare **`RET`** (`C3`); **void**. Entry `MOV EDI,ECX`.
3. **Semantics:** MSVC **complete destructor** for **CWndVehicle**:
   - Install vtbl **`PTR_FUN_00a6fbcc`**.
   - If nested `@+0x2A8` (`this[0xAA]`) non-null: flag `+0x48=1`, copy `+0x40→+0x44` via subobj `+0x10`, `FUN_0076c4d0(nested+0x10)`, binder `{&PTR_LAB_00a9f4d8, nested}`, dual vcall on `*(nested+8)` at `+0x20` / `+0x10(0)`.
   - `FUN_00833d50` with **EDI=this** (derived vehicle UI teardown: `+0x50C`, nested again, vehicle host `+0x508` / `Vehicle_SetWheelset(0)`).
   - Base `FUN_0078ca80(this)` — CNDUIWndBuffered complete → later `FUN_007b5be0`.
4. **Classification:** worker (complete dtor body).
5. **Callers (1 code):** `FUN_004160d0` / `CWndVehicle_ScalarDeletingDtor` @ `0x004160d3` (vtbl[0]).
6. **RTTI:** COL `@0x00a6fbc8` → `0x00ab5d3c` → type_info `0x00afe4b4` → **`.?AVCWndVehicle@@`**.
7. **Name:** `CWndVehicle_CompleteDtor` (Ghidra `FUN_00834520`). Product demangle **sealed**.
8. **Decompile ≡ raw CF**; EDI helper + full hex sealed via `disassemble_function` + `read_memory`.

### Gaps

- Nested `+0x2A8` / binder `00a9f4d8` product English.  
- Full dual of `FUN_00833d50` / `FUN_0078ca80` / `FUN_0076c4d0` (not OWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00834520_CWndVehicle_CompleteDtor.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00834520_CWndVehicle_CompleteDtor.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00834520_FUN_00834520.md` |
| Annotated | `docs/reconstruction/raw/aa_00834520_FUN_00834520.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CWndVehicle_CompleteDtor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00834520.cpp` |
| Function | `docs/reconstruction/functions/aa_00834520_FUN_00834520.md` |
| Function named | `docs/reconstruction/functions/aa_00834520_CWndVehicle_CompleteDtor.md` |

---

## VA `0x00832fa0` — sealed facts

1. **Body:** `0x00832fa0`–`0x0083300f` inclusive (**112 B** / `0x70`); next at `0x00833010`.
2. **ABI:** **`__thiscall`**; ECX = this; SEH `LAB_009b33be`; bare **`RET`** (`C3`); **void**. Entry `MOV ESI,ECX`.
3. **Semantics:** MSVC **complete destructor** for **CWndWaypointIcon**:
   - Install vtbl **`PTR_FUN_00a7000c`**.
   - If owned `@+0x488` (`this[0x122]`) non-null: `FUN_0096efd0(owned)` then `operator_delete(owned)` (`ADD ESP,4`).
   - **Always** `*(this+0x488) = 0`.
   - Base `FUN_007b5be0(this)` — UI window base (`PTR_FUN_00a960ac`).
4. **Classification:** worker (complete dtor body).
5. **Callers (1 code):** `FUN_00416350` @ `0x00416353` (scalar deleting; vtbl[0] of `00a7000c`).
6. **RTTI:** COL `@0x00a70008` → `0x00ab5e08` → type_info `0x00affae4` → **`.?AVCWndWaypointIcon@@`**.
7. **Name:** `CWndWaypointIcon_CompleteDtor` (Ghidra `FUN_00832fa0`). Product demangle **sealed** (closes prior scaffold `Class_00a7000c` for this body).
8. **Decompile ≡ raw CF**; Ghidra false-noreturn on `operator_delete` corrected via epilogue bytes.

### Gaps

- Owned block at `+0x488` product layout / `FUN_0096efd0` English.  
- Full dual of base `FUN_007b5be0` (not OWN).  
- Parent rename residual for scalar peer `Class_00a7000c_ScalarDeletingDtor_Inferred` → `CWndWaypointIcon_ScalarDeletingDtor`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00832fa0_CWndWaypointIcon_CompleteDtor.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00832fa0_CWndWaypointIcon_CompleteDtor.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00832fa0_FUN_00832fa0.md` |
| Annotated | `docs/reconstruction/raw/aa_00832fa0_FUN_00832fa0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CWndWaypointIcon_CompleteDtor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00832fa0.cpp` |
| Function | `docs/reconstruction/functions/aa_00832fa0_FUN_00832fa0.md` |
| Function named | `docs/reconstruction/functions/aa_00832fa0_CWndWaypointIcon_CompleteDtor.md` |

---

## Chain context (not dualled; evidence only)

```text
CWndVehicle_ScalarDeletingDtor (0x004160d0)                 [WQ9I-F sealed]
  └─ CWndVehicle_CompleteDtor (0x00834520)                  [OWN WQ9J-B]
        ├─ nested notify @ +0x2A8 + FUN_0076c4d0
        ├─ FUN_00833d50 (EDI=this; +0x50C / nested / +0x508 vehicle)
        └─ FUN_0078ca80 CNDUIWndBuffered complete
              └─ FUN_007b5be0 base window complete
  Ctor twin: FUN_008345c0 → CNDUIWndBuffered_Ctor (0x0078caf0, W34-T)

Class_00a7000c_ScalarDeletingDtor_Inferred (0x00416350)     [WQ9I-H sealed]
  └─ CWndWaypointIcon_CompleteDtor (0x00832fa0)           [OWN WQ9J-B]
        ├─ FUN_0096efd0 + operator_delete @ +0x488
        └─ FUN_007b5be0 base window complete
  Product rename residual on scalar → CWndWaypointIcon_ScalarDeletingDtor
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00834520-00832fa0-wq9jb-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00834520` | Port as **complete dtor only** for **CWndVehicle**: install `PTR_FUN_00a6fbcc`; nested notify `@+0x2A8`; `FUN_00833d50` (preserve EDI=this or rewrite helper); base `FUN_0078ca80`. **Do not** free host. Pair with scalar `0x004160d0`. |
| `00832fa0` | Port as **complete dtor only** for **CWndWaypointIcon**: install `PTR_FUN_00a7000c`; free owned `@+0x488` after `FUN_0096efd0`; always null field; base `FUN_007b5be0`. **Do not** free host. Pair with scalar `0x00416350`. |
| Pair with | Scalar peers WQ9I-F / WQ9I-H; base UI `CNDUIWndBuffered` / `FUN_007b5be0`; ctor `FUN_008345c0`. |
| Naming | Product RTTI seals both names. Parent may rename scalar `Class_00a7000c_*` → `CWndWaypointIcon_ScalarDeletingDtor`. |

---

## Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history (`CWndVehicle_CompleteDtor`, `CWndWaypointIcon_CompleteDtor`; optional scalar rename)  
- systems note (UI windows / vehicle widgets — not skill domain)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN pair).

---

## Process

- OWN VAs only (`0x00834520`, `0x00832fa0`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + disassemble_function + read_memory + xrefs + RTTI COL. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Clean sources use product RTTI names.  
- Odd behavior preserved: nested double-notify path; EDI-based `FUN_00833d50`; false-noreturn on `operator_delete`; always-null `+0x488`.  
- Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
