# Dual A/B report — WQ9H-C OWN-ONLY (`0x00406220`, `0x004062a0`)

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual **WQ9H-C**  
**Scope:** VAs `0x00406220`, `0x004062a0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` / `batch_decompile` + `read_memory` + `analyze_function_complete` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth5_partition_map.md` → **WQ9H-C**.  
**Work item:** WQ-009 depth-5 residual dual seal (vector push_back parents of dualed insert-one `00406de0` / `00406e70`).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00406220` StdVector_PushBack_Elem0x28_EaxVec_EcxVal_Inferred | **accept-with-gaps** — push_back CF/ABI/ret0/stride0x28/fast ConstructN + slow insert-one sealed; product T residual |
| `aa_004062a0` StdVector_PushBack_Elem12_EaxVec_EcxVal_Inferred | **accept-with-gaps** — twin CF/ABI/ret0/stride0xC/fast ConstructN + slow insert-one sealed; product T residual |

Path A (fidelity): both **accept-with-gaps**.  
Path B (adversarial): tree/buynode, thiscall, dword/0x28↔0xC merge, always-grow, by-value stack, and scaffold domain names all **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00406220` — sealed facts

1. **Body:** `0x00406220`–`0x00406298` exclusive (**120 B** / `0x78`); pad `CC` to twin.
2. **ABI:** **customcc**; **EAX** = vector* (+4 begin, +8 end, +0xC capEnd); **ECX** = `const T*` value; **`ret 0`** (`C3` both exits).
3. **Semantics:** MSVC-style **`vector::push_back`** for **0x28** POD:
   - If `begin != 0` and `size < capacity` (both `/0x28`, magic `0x66666667`): ConstructN `FUN_00409d40(end,1)` then `end += 0x28`.
   - Else: insert-one rebind `StdVector_InsertOne_RebindIt_Elem0x28_Via408050_Inferred` (`0x00406de0`, dualed WQ9G-H) with `where = end`; out discarded.
4. **Stride:** **0x28**.
5. **Classification:** worker.
6. **Xrefs (2 UNCONDITIONAL_CALL):** `0x009335fb` (`FUN_00933480` — `EAX=*(ESI+0xc80)+0x68`, `ECX=&local`); `0x00976b7c` (`FUN_00976900` — `EAX=ESI+0x68`, path-parse element).
7. **Callees:** `FUN_00409d40` (ConstructN; undualed residual WQ9H-B); `FUN_00406de0` (dualed insert-one).
8. **Name:** `StdVector_PushBack_Elem0x28_EaxVec_EcxVal_Inferred` (Ghidra `FUN_00406220`). Product demangle open → `_Inferred`.
9. **Decompile ≡ raw CF**; EAX host + RET sealed via **bytes** + call sites.

### Gaps

- Product / 0x28 POD field layout.  
- ConstructN `FUN_00409d40` undualed.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00406220_StdVector_PushBack_Elem0x28_EaxVec_EcxVal_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00406220_StdVector_PushBack_Elem0x28_EaxVec_EcxVal_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00406220_FUN_00406220.md` |
| Annotated | `docs/reconstruction/raw/aa_00406220_FUN_00406220.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_PushBack_Elem0x28_EaxVec_EcxVal_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00406220.cpp` |
| Function | `docs/reconstruction/functions/aa_00406220_FUN_00406220.md` |
| Function named | `docs/reconstruction/functions/aa_00406220_StdVector_PushBack_Elem0x28_EaxVec_EcxVal_Inferred.md` |

---

## VA `0x004062a0` — sealed facts

1. **Body:** `0x004062a0`–`0x00406316` exclusive (**118 B** / `0x76`); pad `CC`.
2. **ABI:** **customcc**; **EAX** = vector*; **ECX** = `const T*` value; **`ret 0`**.
3. **Semantics:** MSVC-style **`vector::push_back`** for **0xC** POD:
   - If `begin != 0` and `size < capacity` (both `/0xC`, magic `0x2AAAAAAB`): ConstructN `FUN_00409db0(end,1)` then `end += 0xC`.
   - Else: insert-one rebind `StdVector_InsertOne_RebindIt_Elem12_EdiVec_Inferred` (`0x00406e70`, dualed WQ9G-I) with `where = end`.
4. **Stride:** **0xC** (12 bytes).
5. **Classification:** worker.
6. **Xrefs (1 UNCONDITIONAL_CALL):** `0x00930d53` — `MOV EAX,0x00d1a82c` static vector; `LEA ECX,[ESP]` local 12-byte value.
7. **Callees:** `FUN_00409db0` ConstructN; `FUN_00406e70` insert-one (dualed).
8. **Name:** `StdVector_PushBack_Elem12_EaxVec_EcxVal_Inferred` (Ghidra `FUN_004062a0`). Twin naming of `00406220`.
9. **Decompile ≡ raw CF**; stride/ABI sealed by **bytes** + sole caller.

### Gaps

- Product / 12-byte POD English type.  
- ConstructN `FUN_00409db0` undualed.  
- Enclosing caller function English / static map meaning.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004062a0_StdVector_PushBack_Elem12_EaxVec_EcxVal_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004062a0_StdVector_PushBack_Elem12_EaxVec_EcxVal_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_004062a0_FUN_004062a0.md` |
| Annotated | `docs/reconstruction/raw/aa_004062a0_FUN_004062a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_PushBack_Elem12_EaxVec_EcxVal_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004062a0.cpp` |
| Function | `docs/reconstruction/functions/aa_004062a0_FUN_004062a0.md` |
| Function named | `docs/reconstruction/functions/aa_004062a0_StdVector_PushBack_Elem12_EaxVec_EcxVal_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
StdVector_PushBack_Elem0x28_EaxVec_EcxVal_Inferred (0x00406220)  [OWN WQ9H-C]
  ├─ fast → FUN_00409d40 ConstructN (elem 0x28)                 [WQ9H-B residual]
  └─ slow → StdVector_InsertOne_RebindIt_Elem0x28… (0x00406de0) [dualed WQ9G-H]
              └─ FUN_00408050 InsertN                           [WQ9H-A residual]

StdVector_PushBack_Elem12_EaxVec_EcxVal_Inferred (0x004062a0)   [OWN WQ9H-C]
  ├─ fast → FUN_00409db0 ConstructN (elem 0xC)
  └─ slow → StdVector_InsertOne_RebindIt_Elem12… (0x00406e70)   [dualed WQ9G-I]
              └─ FUN_004082f0 InsertN                           [WQ9H-B residual]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00406220-004062a0-wq9hc-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00406220` | Port as **shared vector push_back** for **elem stride 0x28**. **EAX**=vec, **ECX**=value*, **ret 0**. Fast ConstructN@end; slow insert-one `00406de0`. Not skill/tree logic. |
| `004062a0` | Port as **shared vector push_back** for **elem stride 0xC**. Same EAX/ECX ABI. Pair insert-one `00406e70`. Keep **distinct** from 0x28 twin. |
| Pair with | insert-one duals `00406de0` / `00406e70`; ConstructN `00409d40` / `00409db0` when dualed; dword push_back family (`00411180`) is different ABI. |
| Naming caution | **Not** tree/buynode despite VA neighborhood of `00406c40`. **Not** merge 0x28 ↔ 0xC. |

---

## Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- systems note (util/container — not skill domain)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN pair).

---

## Process

- OWN VAs only (`0x00406220`, `0x004062a0`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + assembly_context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Clean sources use meaningful names (not Ghidra iVar blank-line paste).  
- Odd behavior preserved: decompiler `in_EAX` host; ConstructN phantom 4-arg stack pack + `add esp,0x10`; insert-one out scratch discarded.  
- `_Inferred` where English unproven; Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
