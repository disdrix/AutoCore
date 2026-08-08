# Dual A/B report — WQ9J-A OWN-ONLY (`0x00409f50`, `0x0040a520`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **WQ9J-A**  
**Scope:** VAs `0x00409f50`, `0x0040a520` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` / `batch_decompile` + `read_memory` + `analyze_function_complete` + callers/xrefs + `get_assembly_context` + `disassemble_function`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth7_partition_map.md` → **WQ9J-A**.  
**Work item:** WQ-009 depth-7 residual dual seal (POD copy 3 dwords Elem12 + range-copy 0x28).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00409f50` StdVector_PodCopyElement_Elem12_Inferred | **accept-with-gaps** — leaf CF/ABI/3-dword/0x0C/null-dst sealed; product residual |
| `aa_0040a520` StdVector_UninitializedCopy_Elem0x28_Inferred | **accept-with-gaps** — range CF/ABI/stride0x28/PodCopy leaf/return dest sealed; product + parent residual |

Path A (fidelity): both **accept-with-gaps**.  
Path B (adversarial): EAX/EDX-merge-on-Elem12 / thiscall-on-range / stride 0x0C↔0x28 merge / ConstructN-as-leaf / non-POD all **rejected**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00409f50` — sealed facts

1. **Body:** `0x00409f50`–`0x00409f64` inclusive (**21 B** / `0x15`); pad `CC`.
2. **ABI:** **EAX** = dest `T*`; **ECX** = src `const T*`; plain **`ret`** (`C3`). No stack args.
3. **Semantics:** Null-dst no-op; else copy **3 dwords** (12 B / **0x0C**) at offsets 0/4/8.
4. **Bytes:** `85 C0 74 10 8B 11 89 10 8B 51 04 89 50 04 8B 49 08 89 48 08 C3`.
5. **Callees:** none (leaf).
6. **Callers (2):** `FUN_00409db0` ConstructN Elem12 @ `0x00409de8`; `FUN_0040a590` range-copy Elem12 @ `0x0040a5c8` (both advance +0x0C after call).
7. **Xrefs:** 2 UNCONDITIONAL_CALL.
8. **Name:** `StdVector_PodCopyElement_Elem12_Inferred` (Ghidra `FUN_00409f50`). Product demangle open → `_Inferred`.
9. **Twins (CF):** ConstructN parent `00409db0` (WQ9I-A dualed); peer PodCopy 0x28 `00409f30` (**EAX/EDX**, different ABI).
10. **Decompile ≡ raw CF**; register ABI sealed via `read_memory` + call-site context (ECX src, not EDX).

### Gaps

- Product / MSVC demangle for 0x0C POD element type.  
- Full dual of range worker `FUN_0040a590` (role sealed).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00409f50_StdVector_PodCopyElement_Elem12_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00409f50_StdVector_PodCopyElement_Elem12_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00409f50_FUN_00409f50.md` |
| Annotated | `docs/reconstruction/raw/aa_00409f50_FUN_00409f50.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_PodCopyElement_Elem12_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00409f50.cpp` |
| Function | `docs/reconstruction/functions/aa_00409f50_FUN_00409f50.md` |
| Function named | `docs/reconstruction/functions/aa_00409f50_StdVector_PodCopyElement_Elem12_Inferred.md` |

---

## VA `0x0040a520` — sealed facts

1. **Body:** `0x0040a520`–`0x0040a584` inclusive (**101 B** / `0x65`).
2. **ABI:** **ECX** = `src_end`; stack `src_begin`, `dest`; **EAX** = advanced dest; plain **`ret`** (`C3`). Free helper (not vector thiscall despite decomp label).
3. **Semantics:** MSVC-style **uninitialized_copy** for **elem 0x28**:
   - Loop while `src_begin != src_end`.
   - Each step: `PodCopy_0x28(dest, src)` via dualed `FUN_00409f30` (EAX=dest, EDX=src).
   - Advance both cursors **+0x28**; return final dest.
4. **SEH:** frame with `LAB_009bd0b0`; try level 0 → −1 on exit.
5. **Callees:** `FUN_00409f30` only.
6. **Callers:** `FUN_00408050` InsertN/grow (2 sites @ `0x0040824c`, `0x004082b3`); trampoline `FUN_00409ae0` @ `0x00409af0`.
7. **Xrefs:** 3 UNCONDITIONAL_CALL.
8. **Name:** `StdVector_UninitializedCopy_Elem0x28_Inferred` (Ghidra `FUN_0040a520`). Product demangle open → `_Inferred`.
9. **Twins (CF):** PodCopy leaf `00409f30` (WQ9I-B dualed); Elem12 range twin `0040a590` (residual); peer `StdUninitCopy_Pod28` `0045f360` (elem 0x1c — keep distinct).
10. **Decompile ≡ raw CF**; empty `FUN_00409f30()` and false thiscall overridden by bytes + call-site context.

### Gaps

- Product / MSVC demangle for 0x28 POD element type.  
- Full dual of trampoline `00409ae0` and parent InsertN `00408050` (roles sealed).  
- Full dual of Elem12 range twin `0040a590` (not this OWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0040a520_StdVector_UninitializedCopy_Elem0x28_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0040a520_StdVector_UninitializedCopy_Elem0x28_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0040a520_FUN_0040a520.md` |
| Annotated | `docs/reconstruction/raw/aa_0040a520_FUN_0040a520.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_UninitializedCopy_Elem0x28_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0040a520.cpp` |
| Function | `docs/reconstruction/functions/aa_0040a520_FUN_0040a520.md` |
| Function named | `docs/reconstruction/functions/aa_0040a520_StdVector_UninitializedCopy_Elem0x28_Inferred.md` |

---

## Chain context (not dualled here; evidence only)

```text
FUN_00409db0  StdVector_ConstructN_Elem12_Inferred  [WQ9I-A dualed]
  └─ StdVector_PodCopyElement_Elem12_Inferred (0x00409f50)   [OWN WQ9J-A]
FUN_0040a590  (range-copy step +0x0C)  [residual]
  └─ StdVector_PodCopyElement_Elem12_Inferred (0x00409f50)   [OWN WQ9J-A]

FUN_00409d40  StdVector_ConstructN_Elem0x28_Inferred  [dualed]
  └─ StdVector_PodCopyElement_0x28_Inferred (0x00409f30)    [WQ9I-B dualed]
FUN_0040a520  StdVector_UninitializedCopy_Elem0x28_Inferred  [OWN WQ9J-A]
  └─ StdVector_PodCopyElement_0x28_Inferred (0x00409f30)    [WQ9I-B dualed]
FUN_00408050  InsertN / reallocate elem 0x28  [residual]
  └─ StdVector_UninitializedCopy_Elem0x28_Inferred (0x0040a520)  [OWN WQ9J-A]
FUN_00409ae0  thin trampoline → 0040a520  [residual]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00409f50-0040a520-wq9ja-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00409f50` | Port as **shared POD element copy** for **stride 0x0C** — EAX=dest, **ECX**=src, plain ret. Null-dst no-op; 3 dwords. Pair with ConstructN `00409db0` / Ufill `00406ee0` / push_back `004062a0`. |
| `0040a520` | Port as **shared vector uninitialized_copy** for **elem stride 0x28**. **ECX**=end, stack begin+dest, **EAX**=dest_end, plain ret. Pair with PodCopy `00409f30`, InsertN `00408050`. |
| Pair with | Elem12 ConstructN/Ufill/push_back; Elem0x28 PodCopy/ConstructN/InsertN; Elem12 range twin when dualed. |
| Naming caution | **PodCopy Elem12 is not PodCopy 0x28** — ABI trap (**ECX** vs **EDX** src). **UninitCopy 0x28 is not ConstructN** and **not** Elem12 range `0040a590`. |

---

## Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- systems notes (container / util — **vector POD**, not skill domain)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN pair).

---

## Process

- OWN VAs only (`0x00409f50`, `0x0040a520`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + assembly context + disassemble_function. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Raw bodies preserved; WQ9J-A re-verify sections appended.  
