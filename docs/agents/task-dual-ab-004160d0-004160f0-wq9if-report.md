# Dual A/B report — WQ9I-F OWN-ONLY (`0x004160d0`, `0x004160f0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **WQ9I-F**  
**Scope:** VAs `0x004160d0`, `0x004160f0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `batch_decompile` / `decompile_function` + `analyze_function_complete` + `read_memory` + callers/xrefs + RTTI COL. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth6_partition_map.md` → **WQ9I-F**.  
**Work item:** WQ-009 depth-6 residual dual seal (`00416xxx` neighborhood).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004160d0` CWndVehicle_ScalarDeletingDtor | **accept** — scalar-dtor CF/ABI/vtbl[0]/RTTI CWndVehicle/`RET 4`/false-noreturn sealed |
| `aa_004160f0` CWidgetRotateVehicle_ScalarDeletingDtor | **accept** — scalar-dtor CF/ABI/DATA slot+0x0C/RTTI CWidgetRotateVehicle/`RET 4`/false-noreturn sealed |

Path A (fidelity): both **accept**.  
Path B (adversarial): complete-body, vector-dtor, always-free, cdecl-this, and wrong-host claims all **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x004160d0` — sealed facts

1. **Body:** `0x004160d0`–`0x004160ee` exclusive (**30 B** / `0x1E`); pad `CC CC` then `FUN_004160f0`.
2. **ABI:** **ECX=`this`**; stack **flags**; **`RET 4`** (`C2 04 00`); returns **`this`** in EAX.
3. **Semantics:** MSVC **scalar-deleting destructor** for **CWndVehicle**:
   - Always call complete dtor **`FUN_00834520`** (thiscall).
   - If `(flags & 1)`: `operator_delete(this)`.
   - Return `this`.
4. **Classification:** worker.
5. **Callers:** DATA only — dword @ `0x00a6fbcc` = `0x004160d0` (`PTR_FUN_00a6fbcc[0]`).
6. **Callees:** `FUN_00834520`, `operator_delete`.
7. **RTTI:** COL @ `0x00a6fbc8` → `0x00ab5d3c` → type_info `0x00afe4b4` → **`.?AVCWndVehicle@@`**.
8. **Name:** `CWndVehicle_ScalarDeletingDtor` (Ghidra `FUN_004160d0`). Product demangle **sealed**.
9. **Decompile ≡ raw CF**; Ghidra false-noreturn on `operator_delete` ignored (epilogue present).  
   Full hex: raw WQ9I-F append (30 B).

### Gaps

- Complete dtor body / member map not owned (`FUN_00834520`).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004160d0_CWndVehicle_ScalarDeletingDtor.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_004160d0_CWndVehicle_ScalarDeletingDtor.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_004160d0_FUN_004160d0.md` |
| Annotated | `docs/reconstruction/raw/aa_004160d0_FUN_004160d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CWndVehicle_ScalarDeletingDtor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004160d0.cpp` |
| Function | `docs/reconstruction/functions/aa_004160d0_FUN_004160d0.md` |
| Function named | `docs/reconstruction/functions/aa_004160d0_CWndVehicle_ScalarDeletingDtor.md` |

---

## VA `0x004160f0` — sealed facts

1. **Body:** `0x004160f0`–`0x0041610f` exclusive (**31 B** / `0x1F`); pad `CC`; next `FUN_00416110`.
2. **ABI:** **ECX=`this`**; stack **flags**; **`RET 4`**; returns **`this`** in EAX.
3. **Semantics:** MSVC **scalar-deleting destructor** for **CWidgetRotateVehicle**:
   - Push this; call complete dtor **`FUN_00416110`** (stack-`this`, `RET 4`) — installs base `PTR_LAB_00a9bbe8`.
   - If `(flags & 1)`: `operator_delete(this)`.
   - Return `this`.
4. **Classification:** worker.
5. **Callers:** DATA only — dword @ `0x00a6ffa0` = `0x004160f0` = **`PTR_LAB_00a6ff94[+0x0C]`** (not slot 0; base virtuals occupy [0..2]).
6. **Callees:** `FUN_00416110`, `operator_delete`.
7. **RTTI:** COL @ `0x00a6ff90` → `0x00ab5d8c` → type_info `0x00affac0` → **`.?AVCWidgetRotateVehicle@@`**. Ctor `FUN_00833500` installs `PTR_LAB_00a6ff94`.
8. **Name:** `CWidgetRotateVehicle_ScalarDeletingDtor` (Ghidra `FUN_004160f0`). Product demangle **sealed**.
9. **Decompile ≡ raw CF**; extra `PUSH ESI` vs sibling seals stack-this complete ABI.  
   Full hex: raw WQ9I-F append (31 B).

### Gaps

- Complete dtor dual is WQ9I-G OWN (`0x00416110`) — role sealed, not dualed here.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004160f0_CWidgetRotateVehicle_ScalarDeletingDtor.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_004160f0_CWidgetRotateVehicle_ScalarDeletingDtor.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_004160f0_FUN_004160f0.md` |
| Annotated | `docs/reconstruction/raw/aa_004160f0_FUN_004160f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CWidgetRotateVehicle_ScalarDeletingDtor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004160f0.cpp` |
| Function | `docs/reconstruction/functions/aa_004160f0_FUN_004160f0.md` |
| Function named | `docs/reconstruction/functions/aa_004160f0_CWidgetRotateVehicle_ScalarDeletingDtor.md` |

---

## Chain context (not dualled; evidence only)

```text
CWndVehicle_ScalarDeletingDtor (0x004160d0)              [OWN WQ9I-F]
  └─ complete → FUN_00834520 (installs PTR_FUN_00a6fbcc + teardown)
       ├─ nested host path @ +0xAA / FUN_0076c4d0
       ├─ FUN_00833d50
       └─ FUN_0078ca80 (CNDUIWndBuffered-family base dtor)
  Ctor twin: FUN_008345c0 → CNDUIWndBuffered_Ctor (0x0078caf0, W34-T)

CWidgetRotateVehicle_ScalarDeletingDtor (0x004160f0)     [OWN WQ9I-F]
  └─ complete → FUN_00416110 (*this = PTR_LAB_00a9bbe8)  [WQ9I-G OWN]
  Ctor: FUN_00833500 installs PTR_LAB_00a6ff94
  Base vtbl twin stub: FUN_0078bc20 → same PTR_LAB_00a9bbe8
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-004160d0-004160f0-wq9if-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004160d0` | Port as **scalar deleting only**: call complete dtor (`FUN_00834520`), then optional `operator_delete` on bit0. vtbl[0] of `PTR_FUN_00a6fbcc` / **CWndVehicle**. Do **not** inline complete body. |
| `004160f0` | Port as **scalar deleting only**: call complete dtor (`FUN_00416110`, stack this), then optional free. Wire as virtual dtor at **`PTR_LAB_00a6ff94[+0x0C]`** — **not** vtbl[0]. Host **CWidgetRotateVehicle**. |
| Pair with | Complete `00834520` / `00416110` (WQ9I-G); ctor `008345c0` / `00833500`; base UI `CNDUIWndBuffered` (W34-T). |
| Naming caution | **Do not** merge the two hosts. Neighbor strings at `00a6ffa8` (`no body found…CWndVehicle`) are **not** the host of `004160f0`. |

---

## Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- systems note (UI / vehicle widgets — not skill domain)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN pair).

---

## Process

- OWN VAs only (`0x004160d0`, `0x004160f0`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + xrefs + RTTI COL. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Clean sources use product RTTI names.  
- Odd behavior preserved: Ghidra false-noreturn on `operator_delete`; complete `00416110` stack-this vs complete `00834520` thiscall.  
- Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
