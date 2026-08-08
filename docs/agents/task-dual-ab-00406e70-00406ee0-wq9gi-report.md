# Dual A/B report — WQ9G-I OWN-ONLY (`0x00406e70`, `0x00406ee0`)

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual **WQ9G-I**  
**Scope:** VAs `0x00406e70`, `0x00406ee0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` / `batch_decompile` + `read_memory` + `analyze_function_complete` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth4_partition_map.md` → **WQ9G-I**.  
**Work item:** WQ-009 depth-4 residual dual seal (tree neighborhood residual leaves — vector InsertOne/Ufill elem **0xC**).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00406e70` StdVector_InsertOne_RebindIt_Elem12_EdiVec_Inferred | **accept-with-gaps** — insert-one + index rebind CF/ABI/RET0xC/stride12/EDI host sealed; product T residual |
| `aa_00406ee0` StdVector_UninitializedFillN_Elem12_Inferred | **accept-with-gaps** — Ufill wrapper CF/ABI/RET4/stride12/EDI·ESI sealed; construct-N residual |

Path A (fidelity): as above.  
Path B (adversarial): no CF rejects; thiscall-vs-EDI, stride-4/0x28 mix-ups, void-signature traps closed via bytes; product demangle open → `_Inferred`.

---

## VA `0x00406e70` — sealed facts

1. **Body:** `0x00406e70`–`0x00406ed8` exclusive (**104 B** / `0x68`); pad `CC` to `0x00406ee0`.
2. **ABI:** **customcc**; **EDI** = vector* (+4 begin, +8 end, +0xC capEnd); stack `T** out`, `T* where`, `const T* value`; **RET 0x0C**; EAX = out*.
3. **Semantics:** MSVC-style **insert-one + iterator rebind**:
   - `index = empty ? 0 : (where - begin) / 12` (magic `0x2AAAAAAB`).
   - `FUN_004082f0(vec, where, count=1, value)` thiscall (may realloc).
   - `*out = begin' + index * 12`.
4. **Stride:** **0xC** (12-byte / 3-dword POD).
5. **Caller (1):** `FUN_004062a0` push_back slow path (EAX→EDI vec; where=`end`).
6. **Xrefs:** 1 UNCONDITIONAL_CALL @ `0x0040630c`.
7. **Name:** `StdVector_InsertOne_RebindIt_Elem12_EdiVec_Inferred` (Ghidra `FUN_00406e70`). Product demangle open → `_Inferred`.
8. **Decompile ≡ raw CF**; RET / count-1 / stride sealed via `read_memory`.

### Gaps

- Product / MSVC demangle for 12-byte element type.  
- InsertN engine `FUN_004082f0` undualed residual.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00406e70_StdVector_InsertOne_RebindIt_Elem12_EdiVec_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00406e70_StdVector_InsertOne_RebindIt_Elem12_EdiVec_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00406e70_FUN_00406e70.md` |
| Annotated | `docs/reconstruction/raw/aa_00406e70_FUN_00406e70.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_InsertOne_RebindIt_Elem12_EdiVec_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00406e70.cpp` |
| Function | `docs/reconstruction/functions/aa_00406e70_FUN_00406e70.md` |
| Function named | `docs/reconstruction/functions/aa_00406e70_StdVector_InsertOne_RebindIt_Elem12_EdiVec_Inferred.md` |

---

## VA `0x00406ee0` — sealed facts

1. **Body:** `0x00406ee0`–`0x00406efd` exclusive (**29 B** / `0x1d`); pad `CC` to `0x00406f00`.
2. **ABI:** **customcc**; **EDI** = dest*; **ESI** = count; stack `const T* value`; **RET 4**; EAX = dest + count×12.
3. **Semantics:** MSVC-style **uninitialized_fill_n**:
   - `FUN_00409db0(dest, count)` with ECX=value* — loop construct via `FUN_00409f50` (3-dword POD copy; advance +0xC).
   - Return `dest + count * 0xC` (`lea` `esi*3*4`).
4. **Stride:** **0xC**.
5. **Caller (1 fn / 2 sites):** `FUN_004082f0` InsertN hole fill @ `0x00408426`, `0x0040851b`.
6. **Xrefs:** 2 UNCONDITIONAL_CALL.
7. **Name:** `StdVector_UninitializedFillN_Elem12_Inferred` (Ghidra `FUN_00406ee0`). Structural Ufill naming.
8. **Decompile ≡ raw CF** with register formals sealed by parent call-site + bytes.

### Gaps

- Product / PDB for element type.  
- Construct-N `00409db0` / copy `00409f50` undualed.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00406ee0_StdVector_UninitializedFillN_Elem12_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00406ee0_StdVector_UninitializedFillN_Elem12_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00406ee0_FUN_00406ee0.md` |
| Annotated | `docs/reconstruction/raw/aa_00406ee0_FUN_00406ee0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_UninitializedFillN_Elem12_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00406ee0.cpp` |
| Function | `docs/reconstruction/functions/aa_00406ee0_FUN_00406ee0.md` |
| Function named | `docs/reconstruction/functions/aa_00406ee0_StdVector_UninitializedFillN_Elem12_Inferred.md` |

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00406e70-00406ee0-wq9gi-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00406e70` | Port as **shared vector insert-one + rebind** for **elem size 12**. Host in **EDI** (not ECX). Max-formals **ret 0xC**. Pair with InsertN `004082f0`. Parent push_back `004062a0` owns capacity fast path. |
| `00406ee0` | Port as **uninitialized_fill_n** for **elem size 12**. **EDI=dest, ESI=count, stack value*, ret 4**. Do not trust decomp `void` signature. Used inside InsertN hole plant. |
| Pair with | InsertN `004082f0`; construct-N `00409db0`; sibling InsertOne/Ufill elem **0x28** (`00406de0`/`00406e50`); dword InsertOne family (`0040dbf0`/`0040b6d0`). |

---

## Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- systems notes (container / tree-neighborhood residual)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN pair).

---

## Process

- OWN VAs only (`0x00406e70`, `0x00406ee0`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Clean sources use meaningful names (not Ghidra iVar blank-line paste).  
- Odd behavior preserved: decomp `unaff_EDI/ESI`; phantom pushes into construct-N; customcc EDI host.  
- `_Inferred` where English unproven; Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
