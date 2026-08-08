# Dual A/B report — WQ9G-H OWN-ONLY (`0x00406de0`, `0x00406e50`)

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual **WQ9G-H**  
**Scope:** VAs `0x00406de0`, `0x00406e50` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` / `batch_decompile` + `read_memory` + `analyze_function_complete` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth4_partition_map.md` → **WQ9G-H**.  
**Work item:** WQ-009 depth-4 residual dual seal (tree neighborhood residual leaves near insert/buynode — actually **vector** helpers co-located at `0x00406xxx`).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00406de0` StdVector_InsertOne_RebindIt_Elem0x28_Via408050_Inferred | **accept-with-gaps** — insert-one + rebind CF/ABI/RET0xC/stride0x28/callee sealed; insert-N dual + product residual |
| `aa_00406e50` StdVector_UninitializedFillN_Elem0x28_Inferred | **accept-with-gaps** — fill-n CF/ABI/RET4/end×0x28 sealed; ConstructN dual + product residual |

Path A (fidelity): as above.  
Path B (adversarial): tree/buynode / dword-twin / Pod28(0x1c) / thiscall misreads rejected; scaffold void signatures closed via bytes.

---

## VA `0x00406de0` — sealed facts

1. **Body:** `0x00406de0`–`0x00406e48` exclusive (**104 B** / `0x68`); pad `CC`.
2. **ABI:** **customcc**; **EDI** = vector*; stack `T** out`, `T* where`, `const T* value`; **RET 0xC**; EAX = out.
3. **Semantics:** MSVC-style **insert exactly one 0x28-byte element + rebind out-iterator**:
   - `index = (begin!=0 && size!=0) ? (where-begin)/0x28 : 0`
   - `FUN_00408050(ECX=vec, EDX=value, where, count=1)` — may realloc
   - `*out = begin' + index*0x28`
4. **Stride:** **0x28** (div magic `0x66666667`).
5. **Callee:** undualed insert-N `FUN_00408050` (elem 0x28).
6. **Caller (1):** `FUN_00406220` push_back slow path @ `0x0040628e` (fast path: ConstructN@end + end+=0x28).
7. **Xrefs:** 1 UNCONDITIONAL_CALL.
8. **Name:** `StdVector_InsertOne_RebindIt_Elem0x28_Via408050_Inferred` (Ghidra `FUN_00406de0`). Product demangle open → `_Inferred`.
9. **Twins (CF):** dword rebind `0040b6d0` / `0040dbf0` / `00466da0` (different stride/engine/ABI).
10. **Decompile ≡ raw CF**; RET + register formals sealed via `read_memory`.

### Gaps

- Product / MSVC demangle for 0x28 POD element type.  
- Insert-N `FUN_00408050` and parent `FUN_00406220` undualed.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00406de0_StdVector_InsertOne_RebindIt_Elem0x28_Via408050_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00406de0_StdVector_InsertOne_RebindIt_Elem0x28_Via408050_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00406de0_FUN_00406de0.md` |
| Annotated | `docs/reconstruction/raw/aa_00406de0_FUN_00406de0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_InsertOne_RebindIt_Elem0x28_Via408050_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00406de0.cpp` |
| Function | `docs/reconstruction/functions/aa_00406de0_FUN_00406de0.md` |
| Function named | `docs/reconstruction/functions/aa_00406de0_StdVector_InsertOne_RebindIt_Elem0x28_Via408050_Inferred.md` |

---

## VA `0x00406e50` — sealed facts

1. **Body:** `0x00406e50`–`0x00406e6c` exclusive (**28 B** / `0x1c`); pad `CC`.
2. **ABI:** **customcc**; **EDI** = dst; **ESI** = count; stack `const T* value`; **RET 4**; EAX = end.
3. **Semantics:** MSVC-style **uninitialized_fill_n** for 0x28 POD:
   - `FUN_00409d40` ConstructN (loop `FUN_00409f30` PodCopy 10 dwords / +0x28)
   - `return dst + count * 0x28`
4. **Stride:** **0x28** (`lea` ×5×8).
5. **Callee:** undualed ConstructN `FUN_00409d40` → PodCopy leaf `FUN_00409f30`.
6. **Caller (1 function, 2 sites):** `FUN_00408050` InsertN @ `0x00408184`, `0x0040827e`.
7. **Xrefs:** 2 UNCONDITIONAL_CALL.
8. **Name:** `StdVector_UninitializedFillN_Elem0x28_Inferred` (Ghidra `FUN_00406e50`). Product demangle open → `_Inferred`.
9. **Twins (CF):** `UiToast_UninitializedFillN_0x98` (`0x00404130`); floater `0x00402ea0`.
10. **Decompile ≡ raw CF**; RET + end arithmetic sealed via `read_memory`.

### Gaps

- Product / POD English type (0x28 layout).  
- ConstructN / PodCopy undualed.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00406e50_StdVector_UninitializedFillN_Elem0x28_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00406e50_StdVector_UninitializedFillN_Elem0x28_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00406e50_FUN_00406e50.md` |
| Annotated | `docs/reconstruction/raw/aa_00406e50_FUN_00406e50.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_UninitializedFillN_Elem0x28_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00406e50.cpp` |
| Function | `docs/reconstruction/functions/aa_00406e50_FUN_00406e50.md` |
| Function named | `docs/reconstruction/functions/aa_00406e50_StdVector_UninitializedFillN_Elem0x28_Inferred.md` |

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00406de0-00406e50-wq9gh-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00406de0` | Port as **shared vector insert-one + rebind** for **elem stride 0x28** — not skill/tree logic. **EDI**=vec; **ret 0xC**; count forced **1** into `FUN_00408050`. Pair with push_back parent `00406220`. |
| `00406e50` | Port as **uninitialized_fill_n** leaf for **0x28** POD. **EDI**/ **ESI** + value stack; **ret 4**. Construct via `00409d40`/`00409f30` (10 dwords). Used only by insert-N `00408050`. |
| Pair with | dword rebind twins (`0040b6d0` family); fill-n twins (`00404130`); undualed insert-N `00408050` when dualed. |
| Naming caution | **Not** tree/buynode despite VA neighborhood of `StdTree_InsertAndRebalance_Isnil29` (`00406c40`). **Not** `Pod28` (0x1c) family. |

---

## Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/skills-abilities.md` residual table (or util/container system note — these are **vector** helpers, not skill domain)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN pair).

---

## Process

- OWN VAs only (`0x00406de0`, `0x00406e50`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Clean sources use meaningful names (not Ghidra iVar blank-line paste).  
- Odd behavior preserved: decompiler unaff_EDI/ESI = real customcc formals; phantom stack pushes into ConstructN.  
- `_Inferred` where English unproven; Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
