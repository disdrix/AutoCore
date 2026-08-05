# Dual A/B report — W34-R OWN-ONLY (`0x004a7ad0`, `0x0055be00`)

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W34-R  
**Scope:** OWN ONLY VAs `0x004a7ad0`, `0x0055be00`. Dual A/B + artifacts (trio + function + A/B).  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave34_partition_map.md` → **W34-R**.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / parent ledgers.  
**Ghidra:** `batch_decompile` / `get_function_by_address` / `get_function_xrefs` / `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict per VA

| Unit | Verdict |
|------|---------|
| `aa_004a7ad0` StdVector_InsertN_BasicStringW | **accept-with-gaps** — thiscall insert-n RET 0x0C; stride 0x1c wstring; 1.5× grow; sole insert-one caller sealed; nested helpers English open |
| `aa_0055be00` StdVector_InsertN_Elem28 | **accept-with-gaps** — thiscall insert-n RET 0x0C; stride 0x1c POD; 1.5× grow; resize+insert-one callers sealed; Elem28 product type open |

---

## `aa_004a7ad0` — StdVector_InsertN_BasicStringW

### Sealed facts

1. **Body:** `0x004a7ad0`–`0x004a7df7` exclusive (**807 B** / `0x327`). Final **`C2 0C 00`** (`ret 0x0C`); pad `CC`.

2. **ABI:** **`__thiscall`**; ECX=`vector*`; stack **where*, count, value***; void. Confirmed `8B F1` + `C2 0C 00`.

3. **Layout:** begin@`+4`, end@`+8`, capEnd@`+0xC`. Element stride **`0x1c`**. Max elems **`0x9249249`**. Div magic **`0x92492493`**.

4. **Algorithm:**
   - Local `basic_string<wchar_t>` copy of `*value` (IAT ctor; SEH `LAB_009a11e9`)
   - `count==0` → dtor local; return
   - overflow → `FUN_004a6820`
   - **Grow** (`cap < size+count`): 1.5× (`cap+(cap>>1)`), floor `size+count` via `FUN_00469c50`+count; `operator_new`; relocate (`FUN_004a6b50`) + fill (`FUN_004a74f0`) + suffix; destroy-range (`FUN_004a7aa0`) + `operator_delete`; rebind triad
   - **In-place:** hole arm (`FUN_004a6b50` / `FUN_004a7a70` / `FUN_004a68a0`) or mid-shift (`FUN_004a68d0` / `FUN_004a68a0`)
   - dtor local; RET 0x0C

5. **Classification:** worker (generic vector insert-n).

6. **Callers (1):** `FUN_004a7ff0` @ `0x004a8043` — always `count=1`, rebinds out-iterator to `begin + idx*0x1c`.

7. **Related:** char twin `StdVector_InsertN_BasicString` (`0x004306b0`, W32-B); size helper `StdVector_Elem28_Size` (`0x00469c50`, W33-J); POD wave-mate `0055be00`.

8. **Name:** `StdVector_InsertN_BasicStringW` (Ghidra `FUN_004a7ad0`). **Reject** scaffold `Named_CalleeOf_Named_*_004a7ad0`.

9. **Decompile ≡ raw CF** (live 2026-07-29 ≡ raw 2026-07-23); ABI sealed by `read_memory`.

### Gaps

1. Product/MSVC demangle plate for `vector<basic_string<wchar_t>>::insert`.  
2. Nested helper duals (`FUN_004a6b50`, `FUN_004a74f0`, `FUN_004a7aa0`, `FUN_004a7a70`, `FUN_004a68*`, `FUN_004a7ff0`).  
3. Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_004a7ad0_StdVector_InsertN_BasicStringW.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_004a7ad0_StdVector_InsertN_BasicStringW.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_004a7ad0_StdVector_InsertN_BasicStringW.md` |
| Review B | `docs/reconstruction/reviews/B_aa_004a7ad0_StdVector_InsertN_BasicStringW.md` |
| Function record | `docs/reconstruction/functions/aa_004a7ad0_StdVector_InsertN_BasicStringW.md` |
| Scaffold record | `docs/reconstruction/functions/aa_004a7ad0_FUN_004a7ad0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_InsertN_BasicStringW.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_004a7ad0.cpp` |
| Raw (+ W34-R append) | `docs/reconstruction/raw/aa_004a7ad0_FUN_004a7ad0.md` |
| Annotated | `docs/reconstruction/raw/aa_004a7ad0_FUN_004a7ad0.annotated.md` |

---

## `aa_0055be00` — StdVector_InsertN_Elem28

### Sealed facts

1. **Body:** `0x0055be00`–`0x0055c11c` exclusive (**796 B** / `0x31C`). Final **`C2 0C 00`** (`ret 0x0C`); pad `CC`.

2. **ABI:** **`__thiscall`**; ECX=`vector*`; stack **where*, count, value***; void. Confirmed `8B F1` + `C2 0C 00`.

3. **Layout:** begin@`+4`, end@`+8`, capEnd@`+0xC`. Element stride **`0x1c`**. Max elems **`0x9249249`**. Div magic **`0x92492493`**.

4. **Algorithm:**
   - Local **POD** copy of `*value` (7× dword / `movss` ladder; SEH `LAB_009a4860`)
   - `count==0` → return
   - overflow → `FUN_0055b3a0`
   - **Grow:** 1.5× floor; `operator_new`; relocate (`FUN_0055b6a0`) + fill (`FUN_0055b7a0`) + suffix; **`operator_delete` only** (no destroy-range); rebind triad
   - **In-place:** hole (`FUN_0055b6a0` / `FUN_0055bd90` / `FUN_0055b5d0`) or mid-shift (`FUN_0055b4d0` / `FUN_0055b5d0`)
   - RET 0x0C (no local dtor)

5. **Classification:** worker (generic vector insert-n, POD T).

6. **Callers (2):**
   - `FUN_0055c250` @ `0x0055c2ae` — resize grow: insert `(need)` copies at `end`
   - `FUN_0055c310` @ `0x0055c363` — insert-one rebind (`count=1`)

7. **Related:** size helper `StdVector_Elem28_Size` (`0x00469c50`, W33-J); wstring wave-mate `004a7ad0`; char twin `004306b0` (string, not POD).

8. **Name:** `StdVector_InsertN_Elem28` (Ghidra `FUN_0055be00`). **Reject** scaffold `Named_CalleeOf_*` / VOG_DEBUG plate.

9. **Decompile ≡ raw CF**; ABI sealed by `read_memory`.

### Gaps

1. Product English for the 0x1c POD element type in this host domain.  
2. Nested helper duals (`FUN_0055b6a0`, `FUN_0055b7a0`, `FUN_0055bd90`, `FUN_0055b5d0`, `FUN_0055b4d0`, callers).  
3. Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_0055be00_StdVector_InsertN_Elem28.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_0055be00_StdVector_InsertN_Elem28.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_0055be00_StdVector_InsertN_Elem28.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0055be00_StdVector_InsertN_Elem28.md` |
| Function record | `docs/reconstruction/functions/aa_0055be00_StdVector_InsertN_Elem28.md` |
| Scaffold record | `docs/reconstruction/functions/aa_0055be00_FUN_0055be00.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_InsertN_Elem28.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_0055be00.cpp` |
| Raw (+ W34-R append) | `docs/reconstruction/raw/aa_0055be00_FUN_0055be00.md` |
| Annotated | `docs/reconstruction/raw/aa_0055be00_FUN_0055be00.annotated.md` |

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-004a7ad0-0055be00-w34r-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004a7ad0` | Port as **`vector<wstring>::insert(where, count, value)`**: thiscall + **RET 0x0C**; stride **0x1c**; max **0x9249249**; 1.5× grow; destroy-range on realloc. Do **not** unify with char twin `004306b0` or POD twin `0055be00`. Callers may wrap as insert-one + iterator rebind (`FUN_004a7ff0`). |
| `0055be00` | Port as **`vector<Elem28>::insert(where, count, value)`** with **trivial T**: same ABI/growth/max as string twins, but POD copy and **delete without destroy**. Used by resize-growth and insert-one wrappers. Product type of Elem28 residual. |

### Shared context (not owned)

| VA | Role |
|---|---|
| `0x00469c50` | `StdVector_Elem28_Size` (W33-J) — size leaf used by both |
| `0x004306b0` | `StdVector_InsertN_BasicString` (W32-B) — char-string twin shape |
| `0x004a7ff0` | insert-one rebind wrapper for wstring vector |
| `0x0055c250` / `0x0055c310` | resize / insert-one wrappers for POD vector |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + `get_function_by_address` + xrefs + `read_memory`. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; structural `_Inferred` / family names only (`StdVector_InsertN_*`).  
