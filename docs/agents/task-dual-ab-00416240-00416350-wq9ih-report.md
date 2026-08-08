# Dual A/B report — WQ9I-H OWN-ONLY (`0x00416240`, `0x00416350`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **WQ9I-H**  
**Scope:** VAs `0x00416240`, `0x00416350` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` / `batch_decompile` + `read_memory` + `analyze_function_complete` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth6_partition_map.md` → **WQ9I-H**.  
**Work item:** WQ-009 depth-6 residual dual seal (00416xxx neighborhood — field-block assign wrapper + Class_00a7000c scalar dtor).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00416240` FieldBlock_CopyFrom_ClearFlags0xBC_Inferred | **accept-with-gaps** — thiscall RET4 / clear +0xBC + FUN_00416160 / 2 callers sealed; product layout + callee dual open |
| `aa_00416350` Class_00a7000c_ScalarDeletingDtor_Inferred | **accept-with-gaps** — scalar ABI/CF/vtbl[0]/complete-then-flags&1 sealed; product demangle + complete member map open |

Path A (fidelity): both **accept-with-gaps**.  
Path B (adversarial): shopveh plate, “clear controls copy ranges”, full-object memcpy, complete-vs-scalar, vector-dtor, always-free, and false-noreturn on `operator_delete` **rejected/narrowed**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00416240` — sealed facts

1. **Body:** `0x00416240`–`0x0041625c` inclusive / exclusive end `0x0041625d` (**29 B** / `0x1D`).
2. **ABI:** **`__thiscall`**; ECX = dest; stack `const void* src`; returns dest; **`RET 4`**.
3. **Semantics:** clear dest dword **`@+0xBC`** = 0, then `FUN_00416160(dest, src)` selective field-block assign, return dest.
4. **Classification:** wrapper.
5. **Xrefs (2 UNCONDITIONAL_CALL):** `0x00634ce5` in `FUN_00634c50`; `0x00833249` in `FUN_00833160` (swap of nested blocks at `+0x510`).
6. **Name:** `FieldBlock_CopyFrom_ClearFlags0xBC_Inferred` (Ghidra `FUN_00416240`). Scaffold shopveh chain **rejected**. Product English open → `_Inferred`.
7. **Decompile ≡ raw CF**; RET 4 + body sealed via `read_memory`.
8. **Note:** pre-clear of `+0xBC` is **overwritten** by `FUN_00416160`’s unconditional flag copy from src (still executed).

### Gaps

- Product / English map for ~0xC0 field-block.  
- `FUN_00416160` flag-bit dual (WQ9I-G) not OWN.  
- Pre-clear product motive.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00416240_FieldBlock_CopyFrom_ClearFlags0xBC_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00416240_FieldBlock_CopyFrom_ClearFlags0xBC_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00416240_FUN_00416240.md` |
| Annotated | `docs/reconstruction/raw/aa_00416240_FUN_00416240.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FieldBlock_CopyFrom_ClearFlags0xBC_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00416240.cpp` |
| Function | `docs/reconstruction/functions/aa_00416240_FUN_00416240.md` |
| Function named | `docs/reconstruction/functions/aa_00416240_FieldBlock_CopyFrom_ClearFlags0xBC_Inferred.md` |

---

## VA `0x00416350` — sealed facts

1. **Body:** `0x00416350`–`0x0041636d` inclusive / exclusive end `0x0041636e` (**30 B** / `0x1E`).
2. **ABI:** **`__thiscall`**; ECX = this; stack `uint8_t flags`; returns this; **`RET 4`**.
3. **Semantics:** MSVC **scalar-deleting destructor**:
   - Always `FUN_00832fa0(this)` complete dtor.
   - If `(flags & 1)` → `operator_delete(this)`.
   - Return this.
4. **Classification:** worker.
5. **Xrefs:** DATA only — `PTR_FUN_00a7000c[0]` @ `0x00a7000c` = `0x00416350` (`read_memory` sealed).
6. **Complete peer:** `FUN_00832fa0` installs `*this = &PTR_FUN_00a7000c` (not OWN).
7. **Name:** `Class_00a7000c_ScalarDeletingDtor_Inferred` (Ghidra `FUN_00416350`). Product demangle open → `_Inferred`.
8. **Decompile ≡ raw CF**; false noreturn on `operator_delete` corrected via epilogue bytes.

### Gaps

- Product demangle for class of vtbl `00a7000c`.  
- Complete dtor member map (`FUN_00832fa0` / `FUN_007b5be0`).  
- Vtbl slots [1+] English.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00416350_Class_00a7000c_ScalarDeletingDtor_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00416350_Class_00a7000c_ScalarDeletingDtor_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00416350_FUN_00416350.md` |
| Annotated | `docs/reconstruction/raw/aa_00416350_FUN_00416350.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Class_00a7000c_ScalarDeletingDtor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00416350.cpp` |
| Function | `docs/reconstruction/functions/aa_00416350_FUN_00416350.md` |
| Function named | `docs/reconstruction/functions/aa_00416350_Class_00a7000c_ScalarDeletingDtor_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_00833160  object nested-block swap
  ├─ FieldBlock_CopyFrom_ClearFlags0xBC_Inferred (0x00416240)  [OWN WQ9I-H]
  │     this = stack temp; src = ESI+0x510
  └─ FUN_00416160 ×2  (WQ9I-G)  EDI↔ESI at +0x510

FUN_00634c50  mesh/path worker
  └─ FieldBlock_CopyFrom_ClearFlags0xBC_Inferred (0x00416240)  [OWN]
        this = stack temp; src from FUN_00437960

FUN_00416160  SelectiveFieldBlock assign  [WQ9I-G OWN, not this agent]
  └─ flag dword @ +0xBC (index 0x2f); gen @ +0xB4

PTR_FUN_00a7000c vtbl
  [0] Class_00a7000c_ScalarDeletingDtor_Inferred (0x00416350)  [OWN WQ9I-H]
        └─ FUN_00832fa0 complete  (installs same vtbl; free this[0x122]; FUN_007b5be0)

Peers (shape only):
  Class_009c7948_ScalarDeletingDtor (0x0040d870)  [W33-A]
  Class_009c7938_ScalarDeletingDtor (0x0040d590)  [W31-E]
```

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00416240` | Port as **thin thiscall wrapper**: `*(u32*)(dest+0xBC)=0; SelectiveAssign(dest,src); return dest;` **RET 4**. **Not** full memcpy; **not** shopveh UI. Pair with `FUN_00416160`. |
| `00416350` | Port as **MSVC scalar dtor** for vtbl `00a7000c`: complete then `if (flags&1) delete`; return this; **RET 4**. **Not** complete; **not** vector-deleting. |
| Pair with | `FUN_00416160` (WQ9I-G); complete `FUN_00832fa0` when dualed; swap caller `FUN_00833160`. |
| Naming caution | Scaffold `shopveh` / `phySkeleton` chain names are **co-location auto labels** — not sealed product IDs for these VAs. |

---

## Process

- OWN VAs only (`0x00416240`, `0x00416350`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + assembly_context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Clean sources use meaningful names (not Ghidra blank-line paste).  
- Odd behavior preserved: pre-clear of flags overwritten by callee; decompiler false noreturn on `operator_delete`.  
- `_Inferred` where English unproven; Terminal **false**.

### Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- systems residual table (util / object field-block + MSVC dtor neighborhood)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

### Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00416240-00416350-wq9ih-report.md` |

---

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
