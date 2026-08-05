# Dual A/B report — W35-T OWN `aa_004673b0` + `aa_00467320`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W35-T  
**Scope:** VAs `0x004673b0`, `0x00467320` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave35_partition_map.md` (W35-T).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004673b0` StdVector_UninitializedCopy_Elem28_Inferred | **accept** — EAX=dest / ECX=first / stack last / bare RET / stride 0x1c / leaf sealed |
| `aa_00467320` StdVector_UninitializedFillN_Elem28_Inferred | **accept** — ECX=dest / EDX=value* / EAX=count / bare RET / stride 0x1c / leaf sealed |

---

## VA `0x004673b0` — sealed facts

1. **Body:** `0x004673b0`–`0x00467406` inclusive (**87 B** / `0x57`; pad `CC` then next).
2. **ABI:** **EAX=`dest*`**, **ECX=`first*`**, stack **`last*`**; bare **`RET`** (caller cleans 1 arg). Reject Ghidra `__thiscall` plate.
3. **Semantics:** MSVC-style **`uninitialized_copy`** for POD T size **0x1c**:
   - Early-out if `first == last`.
   - Loop: if dest non-null, 7-dword fieldwise assign; advance first/dest by `0x1C`.
   - Null-dest skips stores but still advances (compiler artifact).
4. **Classification:** leaf worker — trivial POD range relocate.
5. **Callers (1):** `FUN_00466ea0` @ `0x00466ff9`, `0x00467031`, `0x004670e9`, `0x0046713b` (insert-n grow/hole; W34-Q sealed).
6. **Callees:** none.
7. **Name:** `StdVector_UninitializedCopy_Elem28_Inferred` (Ghidra `FUN_004673b0`; **Inferred** structural). **Reject** scaffold `Named_CalleeOf_…_anmAnimMaste_004673b0`.
8. **Decompile vs bytes:** CF ≡ raw; **bytes win** on EAX=dest, stack last, bare RET, reject thiscall.  
   Full hex: raw W35-T append (87 B).

### Gaps

- Product/PDB T English (parent anm residual only).  
- Runtime / bit-exact.  
- Null-dest path unused by sole known caller.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004673b0_StdVector_UninitializedCopy_Elem28_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_004673b0_StdVector_UninitializedCopy_Elem28_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004673b0_FUN_004673b0.md` |
| Annotated | `docs/reconstruction/raw/aa_004673b0_FUN_004673b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_UninitializedCopy_Elem28_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004673b0.cpp` |
| Function | `docs/reconstruction/functions/aa_004673b0_FUN_004673b0.md` |
| Function named | `docs/reconstruction/functions/aa_004673b0_StdVector_UninitializedCopy_Elem28_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_004673b0.md` |

---

## VA `0x00467320` — sealed facts

1. **Body:** `0x00467320`–`0x0046736e` inclusive (**79 B** / `0x4F`; pad `CC` then unrelated code before sibling copy).
2. **ABI:** **ECX=`dest*`**, **EDX=`value*`**, **EAX=`count`**; bare **`RET`**; no stack args.
3. **Semantics:** MSVC-style **`uninitialized_fill_n`** for POD T size **0x1c**:
   - Early-out if `count == 0` (`TEST`/`JBE` after snapshot to ESI).
   - Loop: if dest non-null, 7-dword fieldwise assign from `*value`; advance dest by `0x1C`; `count--`.
   - Null-dest skips stores but still advances.
4. **Classification:** leaf worker — trivial POD fill-n.
5. **Callers (1):** `FUN_00466ea0` @ `0x0046700f`, `0x0046711c` (insert-n fill arms; W34-Q sealed).
6. **Callees:** none.
7. **Name:** `StdVector_UninitializedFillN_Elem28_Inferred` (Ghidra `FUN_00467320`; **Inferred**). **Reject** scaffold long `Named_CalleeOf_…` chain.
8. **Decompile vs bytes:** CF ≡ raw; **bytes win** on EAX=count formal (phantom `in_EAX` is real), stride imm `0x1C`.  
   Full hex: raw W35-T append (79 B).

### Gaps

- Product/PDB T English.  
- Runtime / bit-exact.  
- Null-dest path unused by sole known caller.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00467320_StdVector_UninitializedFillN_Elem28_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_00467320_StdVector_UninitializedFillN_Elem28_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00467320_FUN_00467320.md` |
| Annotated | `docs/reconstruction/raw/aa_00467320_FUN_00467320.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_UninitializedFillN_Elem28_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00467320.cpp` |
| Function | `docs/reconstruction/functions/aa_00467320_FUN_00467320.md` |
| Function named | `docs/reconstruction/functions/aa_00467320_StdVector_UninitializedFillN_Elem28_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_00467320.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004673b0` | Port as **POD uninit-copy** stride **0x1c**: **EAX=dest**, **ECX=first**, stack **last**, bare **RET**. 7-dword fieldwise assign. Do **not** use BasicString uninit-copy or dword memmove. |
| `00467320` | Port as **POD uninit-fill-n** stride **0x1c**: **ECX=dest**, **EDX=value\***, **EAX=count**, bare **RET**. Do **not** treat as range copy or string fill. |
| Shared | Both are the nested helpers of W34-Q `StdVector_InsertN_Elem28_CountEcx_Inferred` (`0x00466ea0`). Server needs one correct trivial 28-byte relocate/fill — register ABIs are retail-specific. |

Shared context (not owned):

| VA | Role |
|---|---|
| `0x00466ea0` | sole parent — `StdVector_InsertN_Elem28_CountEcx_Inferred` (W34-Q) |
| `0x00469c50` | `StdVector_Elem28_Size` (W33-J) |
| `0x004540b0` | throw `"vector<T> too long"` |
| `0x0045f360` / `0x0045f150` | Pod28 sibling uninit helpers (other insert-n instantiation; W35-K/L) |
| `0x0046a350` / `0x0046a260` | ValueEdx insert-n siblings (W34-Q) |

Closes W35-T OWN pair: the two nested leaf helpers left open under W34-Q insert-n formal-wiring residual.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names; `_Inferred` structural names only.  
- Rejected long Named_CalleeOf scaffold aliases.  
- Avoided bare `undefined4` in clean (`uint32_t` / explicit `Pod28`).
