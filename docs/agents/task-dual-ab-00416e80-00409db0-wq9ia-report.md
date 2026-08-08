# Dual A/B report — WQ9I-A OWN-ONLY (`0x00416e80`, `0x00409db0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **WQ9I-A**  
**Scope:** VAs `0x00416e80`, `0x00409db0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` / `batch_decompile` + `read_memory` + `analyze_function_complete` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth6_partition_map.md` → **WQ9I-A**.  
**Work item:** WQ-009 depth-6 residual dual seal (freelist vector teardown + ConstructN elem12).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00416e80` FreelistSlabVector_Teardown_Inferred | **accept-with-gaps** — freelist slab ptr-vector teardown CF/ABI/ret4/aligned_free loop/always-zero triad sealed; product residual |
| `aa_00409db0` StdVector_ConstructN_Elem12_Inferred | **accept-with-gaps** — construct-N CF/ABI/ECX-value/stride0xC/3-dword PodCopy sealed; product residual |

Path A (fidelity): as above.  
Path B (adversarial): thiscall-on-freelist / noreturn-delete / stride mix-ups / dword-max / InsertN merge rejects closed via bytes; product demangle open → `_Inferred`.

---

## VA `0x00416e80` — sealed facts

1. **Body:** `0x00416e80`–`0x00416ef6` inclusive (**119 B** / `0x77`); pad `CC`.
2. **ABI:** stack freelist subobject*; **`ret 4`** (`C2 04 00`) — **stdcall**, not thiscall.
3. **Semantics:** freelist **slab pointer-vector teardown**:
   - Loop `[begin,end)` at +0x08/+0x0c: `_aligned_free(*it)`; it += 1 pointer.
   - If begin ≠ null: `operator_delete(begin)` (**returns** — decomp noreturn false).
   - **Always** zero +0x08 / +0x0c / +0x10.
4. **Layout:** freelist subobject triad at +8/+0xc/+0x10; head at +0 untouched (nodes already reclaimed).
5. **Callees:** `_aligned_free` (IAT `0x009c6578`); `operator_delete`.
6. **Callers (5 code + 3 unwind):** `FUN_00406420` CNDHash_Dtor_00a2c2b0 (`PUSH this+0x20`); sibling hash dtors `00413850`/`004157f0`/`004169a0`; wrapper `00416c30`.
7. **Xrefs:** 8 total (incl. SEH unwind).
8. **Name:** `FreelistSlabVector_Teardown_Inferred` (Ghidra `FUN_00416e80`). Product demangle open → `_Inferred`.
9. **Twins (CF):** thiscall `FreelistSlabVector_dtor` @ `0x0059c8a0` (W24-M) — same loop/zero, different ABI.
10. **Decompile ≡ raw CF spine**; ret4 + always-zero sealed via `read_memory` (override decomp gaps).

### Gaps

- Product / PDB English for freelist type.  
- Wrapper `00416c30` + sibling hash dtors undualed (not OWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00416e80_FreelistSlabVector_Teardown_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00416e80_FreelistSlabVector_Teardown_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00416e80_FUN_00416e80.md` |
| Annotated | `docs/reconstruction/raw/aa_00416e80_FUN_00416e80.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FreelistSlabVector_Teardown_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00416e80.cpp` |
| Function | `docs/reconstruction/functions/aa_00416e80_FUN_00416e80.md` |
| Function named | `docs/reconstruction/functions/aa_00416e80_FreelistSlabVector_Teardown_Inferred.md` |

---

## VA `0x00409db0` — sealed facts

1. **Body:** `0x00409db0`–`0x00409e12` inclusive (**99 B** / `0x63`); plain ret `C3`.
2. **ABI:** **ECX** = `const T* value`; stack `T* dest`, `int count`; plain **`ret`** (`C3`).
3. **Semantics:** MSVC-style **construct-N** for 0x0C POD:
   - Loop count times: `FUN_00409f50(EAX=dest, ECX=value)` PodCopy **3 dwords**.
   - Advance dest by **`+0x0C`** each iter.
4. **Stride:** **0x0C** (sealed `add esi,0x0C`; decomp omits step).
5. **Callee:** PodCopy leaf `FUN_00409f50` (3 dwords / null-dst no-op; EAX/ECX ABI).
6. **Callers (2):** `FUN_00406ee0` Ufill @ `0x00406eec`; `FUN_004062a0` push_back fast @ `0x004062ef`.
7. **Xrefs:** 2 UNCONDITIONAL_CALL.
8. **Name:** `StdVector_ConstructN_Elem12_Inferred` (Ghidra `FUN_00409db0`). Product demangle open → `_Inferred`.
9. **Twins (CF):** ConstructN elem **0x28** `00409d40` (WQ9H-B); Ufill wrapper `00406ee0` (WQ9G-I).
10. **Decompile ≡ raw CF**; ECX formal + dest step sealed via `read_memory` (override decomp gaps).

### Gaps

- Product / MSVC demangle for 0x0C POD element type.  
- PodCopy `FUN_00409f50` undualed (CF sealed).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00409db0_StdVector_ConstructN_Elem12_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00409db0_StdVector_ConstructN_Elem12_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00409db0_FUN_00409db0.md` |
| Annotated | `docs/reconstruction/raw/aa_00409db0_FUN_00409db0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_ConstructN_Elem12_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00409db0.cpp` |
| Function | `docs/reconstruction/functions/aa_00409db0_FUN_00409db0.md` |
| Function named | `docs/reconstruction/functions/aa_00409db0_StdVector_ConstructN_Elem12_Inferred.md` |

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00416e80-00409db0-wq9ia-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00416e80` | Port as **freelist slab pointer-vector teardown**. **stdcall** stack freelist*; **`ret 4`**. Loop `_aligned_free` on each void* in [begin,end); optional `operator_delete` of array; **always** zero +8/+0xc/+0x10. Call with freelist = hash+0x20. Twin thiscall is `0059c8a0`. |
| `00409db0` | Port as **shared construct-N** for **elem stride 0x0C** — ECX=value*, stack dest+count, plain ret. Loop PodCopy 3 dwords + dest+=0x0C. Used by Ufill `00406ee0` and push_back fast `004062a0`. |
| Pair with | CNDHash dtor `00406420` (WQ9H-D); ConstructN 0x28 `00409d40` (WQ9H-B); InsertN elem12 `004082f0` (WQ9H-B); Ufill `00406ee0` (WQ9G-I); push_back `004062a0` (WQ9H-C). |
| Naming caution | **Not** DestroyBucketTable. Freelist teardown is **not** thiscall (that is `0059c8a0`). ConstructN is **not** Ufill wrapper (that is `00406ee0`). ConstructN is **not** InsertN (that is `004082f0`). |

---

## Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- systems notes (container / util — freelist + vector helpers, not skill domain)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN pair).

---

## Process

- OWN VAs only (`0x00416e80`, `0x00409db0`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Clean sources use meaningful names (not Ghidra iVar blank-line paste).  
- Odd behavior preserved: decomp noreturn on freelist delete; decomp omits ConstructN dest step/ECX.  
- `_Inferred` where English unproven; Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
