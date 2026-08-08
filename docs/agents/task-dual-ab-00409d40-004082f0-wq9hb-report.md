# Dual A/B report — WQ9H-B OWN-ONLY (`0x00409d40`, `0x004082f0`)

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual **WQ9H-B**  
**Scope:** VAs `0x00409d40`, `0x004082f0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` / `batch_decompile` + `read_memory` + `analyze_function_complete` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth5_partition_map.md` → **WQ9H-B**.  
**Work item:** WQ-009 depth-5 residual dual seal (vector ConstructN Ufill 0x28 + InsertN elem12).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00409d40` StdVector_ConstructN_Elem0x28_Inferred | **accept-with-gaps** — construct-N CF/ABI/ECX-value/stride0x28/10-dword PodCopy sealed; product residual |
| `aa_004082f0` StdVector_InsertN_Elem12_Inferred | **accept-with-gaps** — InsertN CF/ABI/thiscall/RET0xC/stride12/1.5× grow sealed; product + helper dual residual |

Path A (fidelity): as above.  
Path B (adversarial): void-signature / stride mix-ups / EDI-this / always-grow / dword-max rejects closed via bytes; product demangle open → `_Inferred`.

---

## VA `0x00409d40` — sealed facts

1. **Body:** `0x00409d40`–`0x00409da2` exclusive (**98 B** / `0x62`).
2. **ABI:** **ECX** = `const T* value`; stack `T* dest`, `int count`; plain **`ret`** (`C3`).
3. **Semantics:** MSVC-style **construct-N** for 0x28 POD:
   - Loop count times: `FUN_00409f30(EAX=dest, EDX=value)` PodCopy **10 dwords**.
   - Advance dest by **`+0x28`** each iter.
4. **Stride:** **0x28** (sealed `add esi,0x28`; decomp omits step).
5. **Callee:** PodCopy leaf `FUN_00409f30` (10 dwords / null-dst no-op).
6. **Callers (2):** `FUN_00406e50` Ufill @ `0x00406e5c`; `FUN_00406220` push_back fast @ `0x00406271`.
7. **Xrefs:** 2 UNCONDITIONAL_CALL.
8. **Name:** `StdVector_ConstructN_Elem0x28_Inferred` (Ghidra `FUN_00409d40`). Product demangle open → `_Inferred`.
9. **Twins (CF):** ConstructN elem **0xC** `00409db0`; Ufill wrapper `00406e50` (WQ9G-H).
10. **Decompile ≡ raw CF**; ECX formal + dest step sealed via `read_memory` (override decomp gaps).

### Gaps

- Product / MSVC demangle for 0x28 POD element type.  
- PodCopy `FUN_00409f30` undualed (CF sealed).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00409d40_StdVector_ConstructN_Elem0x28_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00409d40_StdVector_ConstructN_Elem0x28_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00409d40_FUN_00409d40.md` |
| Annotated | `docs/reconstruction/raw/aa_00409d40_FUN_00409d40.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_ConstructN_Elem0x28_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00409d40.cpp` |
| Function | `docs/reconstruction/functions/aa_00409d40_FUN_00409d40.md` |
| Function named | `docs/reconstruction/functions/aa_00409d40_StdVector_ConstructN_Elem0x28_Inferred.md` |

---

## VA `0x004082f0` — sealed facts

1. **Body:** `0x004082f0`–`0x00408587` exclusive (**663 B** / `0x297`); pad `CC`.
2. **ABI:** **thiscall** ECX=vec; stack `T* where`, `uint count`, `const T* value`; **`ret 0xC`**.
3. **Semantics:** MSVC-style **insert-n** for 12-byte POD:
   - Snap 3 dwords of `*value` to locals.
   - cap/size via `(ptr-begin)/0xC` (magic `0x2AAAAAAB`).
   - Max elems **`0x15555555`**; overflow → `FUN_00418130`.
   - Grow path: **1.5×** then floor `size+count` (`FUN_00480c80`); `operator_new`; uninit_copy prefix; **Ufill** `FUN_00406ee0`; uninit_copy suffix; delete; rebind triad.
   - In-place: near-end (tail < count) vs far (copy_backward `00480fb0` + assign-fill `0042ac90`).
4. **Stride:** **0xC** throughout.
5. **Callees:** `00409b40`/`0040a590` uninit_copy; `00406ee0` Ufill (WQ9G-I dualed); `00480fb0` copy_backward; `0042ac90` assign-fill; `00480c80` size; `00418130` overflow; new/delete.
6. **Caller (1):** `FUN_00406e70` InsertOne rebind @ `0x00406ebf` (count forced **1**).
7. **Xrefs:** 1 UNCONDITIONAL_CALL.
8. **Name:** `StdVector_InsertN_Elem12_Inferred` (Ghidra `FUN_004082f0`). Product demangle open → `_Inferred`.
9. **Twins (CF):** InsertN elem **0x28** `00408050` (WQ9H-A); dword InsertN `004073a0` / `00419880`.
10. **Decompile ≡ raw CF**; RET + thiscall + stride sealed via `read_memory`.

### Gaps

- Product / MSVC demangle for 12-byte element type.  
- Full dual of uninit_copy / copy_backward / assign-fill leaves (roles sealed).  
- Runtime / bit-exact / differential.  
- Decompiler false "delete does not return" — triad rebind after free is real.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004082f0_StdVector_InsertN_Elem12_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004082f0_StdVector_InsertN_Elem12_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_004082f0_FUN_004082f0.md` |
| Annotated | `docs/reconstruction/raw/aa_004082f0_FUN_004082f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_InsertN_Elem12_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004082f0.cpp` |
| Function | `docs/reconstruction/functions/aa_004082f0_FUN_004082f0.md` |
| Function named | `docs/reconstruction/functions/aa_004082f0_StdVector_InsertN_Elem12_Inferred.md` |

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00409d40-004082f0-wq9hb-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00409d40` | Port as **shared construct-N** for **elem stride 0x28** — ECX=value*, stack dest+count, plain ret. Loop PodCopy 10 dwords + dest+=0x28. Used by Ufill `00406e50` and push_back fast `00406220`. |
| `004082f0` | Port as **vector InsertN** for **elem size 12**. **thiscall** ECX=vec; **ret 0xC**. Growth 1.5×; max `0x15555555`. Pair with InsertOne `00406e70` and Ufill `00406ee0`. |
| Pair with | ConstructN 0xC `00409db0`; InsertN 0x28 `00408050` (WQ9H-A); dword InsertN family; push_back parents `00406220`/`004062a0` (WQ9H-C). |
| Naming caution | **Not** tree/buynode. **Not** dword stride. ConstructN is **not** Ufill wrapper (that is `00406e50`). InsertN is **not** InsertOne rebind (that is `00406e70`). |

---

## Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- systems notes (container / util — **vector** helpers, not skill domain)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN pair).

---

## Process

- OWN VAs only (`0x00409d40`, `0x004082f0`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Clean sources use meaningful names (not Ghidra iVar blank-line paste).  
- Odd behavior preserved: decomp omits ConstructN dest step/ECX; delete noreturn false positive on grow path.  
- `_Inferred` where English unproven; Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
