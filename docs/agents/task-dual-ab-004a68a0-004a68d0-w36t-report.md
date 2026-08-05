# Dual A/B report — W36-T OWN `aa_004a68a0` + `aa_004a68d0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W36-T  
**Scope:** VAs `0x004a68a0`, `0x004a68d0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave36_partition_map.md` (W36-T).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004a68a0` BasicStringW_FillAssignRange_0x1c | **accept** — cdecl fill-by-`operator=`; stride `0x1c`; 39 B sealed |
| `aa_004a68d0` BasicStringW_CopyBackward_0x1c | **accept** — cdecl reverse wstring assign + stride `0x1c` + IAT operator= sealed (51 B) |

---

## VA `0x004a68a0` — sealed facts

1. **Body:** `0x004a68a0`–`0x004a68c6` inclusive (**39 B** / `0x27`; pad `CC`×9 then sibling `004a68d0`).
2. **ABI:** **cdecl** stack **`first*`**, **`last*`**, **`value*`**; plain **`RET`** (`C3`); void.
3. **Semantics:** MSVC-style **range fill by assign** on live `basic_string<wchar_t>` slots (elem **0x1c**):
   - `for (cur = first; cur != last; cur += 0x1c) operator=(cur, value);`
   - Empty range no-op.
   - **Not** uninitialized fill; **not** count-N; **not** range-to-range copy.
4. **Classification:** worker leaf (IAT only).
5. **Callers (1 func / 2 sites):** `StdVector_InsertN_BasicStringW` (`FUN_004a7ad0`) @ `0x004a7d67`, `0x004a7dcc`.
6. **Callees:** IAT `basic_string<wchar_t>::operator=` via `[0x009c63bc]` → `0x006ec314`.
7. **Name:** `BasicStringW_FillAssignRange_0x1c` (Ghidra `FUN_004a68a0`; **Inferred**). Char twin `BasicString_FillAssignRange_0x1c` (`0x00431450`, W33-I). **Reject** scaffold `Named_CalleeOf_*`.
8. **Decompile ≡ bytes** for CF; full hex in raw W36-T append.

### Gaps

- Product/MSVC demangle English.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004a68a0_BasicStringW_FillAssignRange_0x1c.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_004a68a0_BasicStringW_FillAssignRange_0x1c.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004a68a0_FUN_004a68a0.md` |
| Annotated | `docs/reconstruction/raw/aa_004a68a0_FUN_004a68a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/BasicStringW_FillAssignRange_0x1c.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004a68a0.cpp` |
| Function | `docs/reconstruction/functions/aa_004a68a0_FUN_004a68a0.md` |
| Function named | `docs/reconstruction/functions/aa_004a68a0_BasicStringW_FillAssignRange_0x1c.md` |

---

## VA `0x004a68d0` — sealed facts

1. **Body:** `0x004a68d0`–`0x004a6902` inclusive (**51 B** / `0x33`; pad `CC` then next).
2. **ABI:** **cdecl** stack **`(first*, last*, dest_end*)`**; plain **`RET`**; returns final **dest** in **EAX**.
3. **Semantics:** MSVC-style **`copy_backward`** on live `basic_string<wchar_t>` slots (elem **0x1c**):
   - Empty (`first == last`) → return `dest_end` (no stores).
   - Else walk `last`/`dest_end` backward by `0x1c` and `operator=` each pair until `last == first`.
   - Return final dest pointer.
4. **Classification:** worker leaf (IAT only).
5. **Callers (1):** `StdVector_InsertN_BasicStringW` (`FUN_004a7ad0`) @ `0x004a7dbf` (mid-insert; then fill via `004a68a0` @ `0x004a7dcc`).
6. **Callees:** IAT `basic_string<wchar_t>::operator=` via `[0x009c63bc]` → `0x006ec314`.
7. **Name:** `BasicStringW_CopyBackward_0x1c` (Ghidra `FUN_004a68d0`; **Inferred**). Char twin `BasicString_CopyBackward_0x1c` (`0x00431790`, W34-L). **Reject** scaffold `Named_CalleeOf_*`.
8. **Decompile ≡ bytes** for CF; full hex in raw W36-T append.

### Gaps

- Product/MSVC demangle English.  
- Runtime / bit-exact under overlap edges.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004a68d0_BasicStringW_CopyBackward_0x1c.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_004a68d0_BasicStringW_CopyBackward_0x1c.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004a68d0_FUN_004a68d0.md` |
| Annotated | `docs/reconstruction/raw/aa_004a68d0_FUN_004a68d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/BasicStringW_CopyBackward_0x1c.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004a68d0.cpp` |
| Function | `docs/reconstruction/functions/aa_004a68d0_FUN_004a68d0.md` |
| Function named | `docs/reconstruction/functions/aa_004a68d0_BasicStringW_CopyBackward_0x1c.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004a68a0` | Port as **range fill-by-assign** on `basic_string<wchar_t>` (stride **0x1c**). cdecl 3-arg `(first, last, value)`; plain RET; void. Used by `vector<wstring>::insert` hole fill. Do **not** unify with char twin `00431450` (different IAT) or POD fill. |
| `004a68d0` | Port as **copy_backward** on `basic_string<wchar_t>` (stride **0x1c**). cdecl 3-arg; reverse `operator=` walk; returns final dest. Mid-insert **must** reverse-walk (not forward). Do not substitute POD memmove or char twin `00431790`. |
| Shared | Nested leaf helpers of W34-R `StdVector_InsertN_BasicStringW` (`0x004a7ad0`). Same sizes as char twins (39 B / 51 B); wstring IAT `[0x009c63bc]`. |

Shared context (not owned):

| VA | Role |
|---|---|
| `0x004a7ad0` | sole parent — `StdVector_InsertN_BasicStringW` (W34-R) |
| `0x00431450` | char twin fill (W33-I) |
| `0x00431790` | char twin copy_backward (W34-L) |
| `0x00469c50` | `StdVector_Elem28_Size` (W33-J) |

Closes W36-T OWN pair: the two nested leaf helpers left open under W34-R insert-n formal-wiring residual for wstring.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names; `_Inferred` structural names only.  
- Rejected long Named_CalleeOf scaffold aliases.  
- Avoided bare `undefined4` in clean (`uint8_t` / explicit `BasicStringW_0x1c`).
