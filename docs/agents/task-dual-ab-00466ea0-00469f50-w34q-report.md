# Dual A/B report — W34-Q OWN `aa_00466ea0` + `aa_00469f50`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W34-Q  
**Scope:** VAs `0x00466ea0`, `0x00469f50` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` / `batch_decompile` + `read_memory` + `analyze_function_complete` + xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave34_partition_map.md` (W34-Q).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00466ea0` StdVector_InsertN_Elem28_CountEcx_Inferred | **accept-with-gaps** — insert-n ABI/CF/stride/max/growth sealed; helper formal wiring residual |
| `aa_00469f50` StdVector_InsertN_Elem28_ValueEdx_Inferred | **accept-with-gaps** — insert-n ABI/CF/stride/max/growth sealed; helper formal wiring residual |

---

## VA `0x00466ea0` — sealed facts

1. **Body:** `0x00466ea0`–`0x00467174` inclusive (**725 B** / `0x2D5`; pad `CC` then next @ `0x00467180`).
2. **ABI:** **ECX=`count`**, **EDX=`vec*`**; stack **`where*`**, **`value*`**; **`RET 8`** (callee cleans `0x08`).
3. **Semantics (MSVC-style `vector<T>::insert` for POD T size `0x1c`):**
   - Snapshot `*value` (28 B) onto stack (SSE + dword loads).
   - `cap = begin? (capEnd@+0xC − begin@+4)/0x1c : 0`; early-out if `count==0`.
   - Overflow: if `max(0x9249249) − size < count` → **`FUN_004540b0`** (`"vector<T> too long"`).
   - **Realloc** when `cap < size+count`: newCap = `cap+(cap>>1)` or exact floor `size+count`; `operator_new(newCap*0x1c)`; relocate prefix / fill-n / suffix via `FUN_004673b0` + `FUN_00467320`; `operator_delete` old; rewrite triad `+4/+8/+0xC`.
   - **In-place:** if `(end−where)/0x1c < count` → extend hole + fill + bump end; else reverse-move via `FUN_0046a240` + assign `FUN_0045efe0`.
4. **Classification:** worker — generic container insert-n (POD stride 28). **Not** `basic_string` insert (`004306b0` has string ctor/dtor).
5. **Callers (1):** `FUN_00466df0` @ `0x00466e46` (resize/grow parent; unowned).
6. **Callees:** `FUN_004540b0`, `FUN_00469c50` (`StdVector_Elem28_Size`), `FUN_004673b0`, `FUN_00467320`, `FUN_0046a240`, `FUN_0045efe0`, `operator_new` / `operator_delete`.
7. **Name:** `StdVector_InsertN_Elem28_CountEcx_Inferred` (Ghidra `FUN_00466ea0`; **Inferred** structural). **Reject** scaffold `Named_CalleeOf_…_anmAnimMaste_00466ea0`.
8. **Decompile vs bytes:** CF matches insert-n; **bytes win** on second stack formal (`value*` @ `[ebp+0xC]`) and dual `RET 8` sites. Magic `0x92492493` ÷28; max imm `0x09249249`. Full hex: raw W34-Q append.

### Gaps

- Product/MSVC demangle for exact `vector<T>::insert` plate / T identity.  
- Nested helper duals (`FUN_004673b0` / `FUN_00467320` / `FUN_0046a240` / `FUN_0045efe0` / parent `FUN_00466df0`) unowned.  
- Decompiler collapses helper formals (EAX dest / EBX template); algorithm sealed, per-call register map residual.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00466ea0_StdVector_InsertN_Elem28_CountEcx_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00466ea0_StdVector_InsertN_Elem28_CountEcx_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00466ea0_FUN_00466ea0.md` |
| Annotated | `docs/reconstruction/raw/aa_00466ea0_FUN_00466ea0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_InsertN_Elem28_CountEcx_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00466ea0.cpp` |
| Function | `docs/reconstruction/functions/aa_00466ea0_FUN_00466ea0.md` |
| Function named | `docs/reconstruction/functions/aa_00466ea0_StdVector_InsertN_Elem28_CountEcx_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_00466ea0.md` |

---

## VA `0x00469f50` — sealed facts

1. **Body:** `0x00469f50`–`0x0046a203` inclusive (**692 B** / `0x2B4`; pad `CC` then next).
2. **ABI:** **EDX=`value*`** (7 dwords / `0x1c` snapshot via `rep movsd`); stack **`vec*`**, **`where*`**, **`count`**; **`RET 0x0C`**. ECX clobbered at entry (`mov ecx,7`); **not** a formal.
3. **Semantics:** Same MSVC insert-n algorithm as `00466ea0` for POD stride `0x1c`:
   - Copy value → `local_34[7]`; capacity/size via triad `+4/+8/+0xC`.
   - Early-out `count==0`; overflow → **`FUN_004540b0`**.
   - Realloc: 1.5× / exact; `operator_new`; `FUN_0046a350` (copy range) + `FUN_0046a260` (fill-n) + `FUN_0046a350`; delete old; rewrite triad.
   - In-place hole/mid: `FUN_0046a350` / `FUN_0046a260` / `FUN_0046a240` / `FUN_0045efe0`.
4. **Classification:** worker — twin ABI flavor of elem-28 insert-n (value-in-EDX).
5. **Callers (1):** `FUN_00469e20` @ `0x00469e73` (insert-one wrapper; unowned).
6. **Callees:** `FUN_004540b0`, `FUN_00469c50`, `FUN_0046a350`, `FUN_0046a260`, `FUN_0046a240`, `FUN_0045efe0`, `operator_new` / `operator_delete`.
7. **Name:** `StdVector_InsertN_Elem28_ValueEdx_Inferred` (Ghidra `FUN_00469f50`; **Inferred**). **Reject** scaffold long `Named_CalleeOf_…` chain.
8. **Decompile vs bytes:** CF ≡ raw; **bytes win** on `RET 0x0C`, `count` @ `[ebp+0x10]`, value snapshot `mov ecx,7; rep movsd`. Full hex: raw W34-Q append.

### Gaps

- Product demangle / T identity.  
- Nested helper duals + insert-one parent `FUN_00469e20` unowned.  
- Helper register formal residual (EAX/EBX).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00469f50_StdVector_InsertN_Elem28_ValueEdx_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00469f50_StdVector_InsertN_Elem28_ValueEdx_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00469f50_FUN_00469f50.md` |
| Annotated | `docs/reconstruction/raw/aa_00469f50_FUN_00469f50.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_InsertN_Elem28_ValueEdx_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00469f50.cpp` |
| Function | `docs/reconstruction/functions/aa_00469f50_FUN_00469f50.md` |
| Function named | `docs/reconstruction/functions/aa_00469f50_StdVector_InsertN_Elem28_ValueEdx_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_00469f50.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00466ea0` | Port as **elem-28 insert-n**: **ECX=count**, **EDX=vec**, stack **where+value**, **`RET 8`**. Max elems `0x9249249`; grow `cap+cap/2` with exact floor; throw via `FUN_004540b0`. Do **not** use dword insert (`00419880`/`004073a0`) or basic_string insert (`004306b0`). |
| `00469f50` | Port as **same algorithm, different ABI**: **EDX=value***, stack **vec+where+count**, **`RET 0x0C`**. Same stride/max/growth. Do **not** treat as drop-in for `00466ea0`. |
| Shared | Both use sealed `StdVector_Elem28_Size` (`00469c50`). Server needs one correct `List<T>.Insert` / insert-range for 28-byte POD — not both retail ABIs. |

Shared context (not owned):

| VA | Role |
|---|---|
| `0x00469c50` | `StdVector_Elem28_Size` (W33-J sealed) |
| `0x004540b0` | throw `"vector<T> too long"` |
| `0x004306b0` | `StdVector_InsertN_BasicString` — string-aware 0x1c sibling |
| `0x00419880` | `StdVector_InsertN_Dword_CountEcx_Inferred` — stride-4 CountEcx twin |
| `0x00466df0` | sole parent of `00466ea0` (resize path) |
| `0x00469e20` | sole parent of `00469f50` (insert-one) |

Closes W34-Q OWN pair of elem-28 insert-n duals; size helper callers sealed on the insert side.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names; `_Inferred` structural names only.  
- Rejected long Named_CalleeOf scaffold aliases.  
- Avoided bare `undefined4` in clean (`uint32_t` / explicit POD structs).
