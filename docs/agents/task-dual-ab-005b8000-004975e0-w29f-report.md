# Dual A/B report — W29-F OWN `aa_005b8000` + `aa_004975e0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W29-F  
**Scope:** VAs `0x005b8000`, `0x004975e0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave29_partition_map.md` (W29-F).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_005b8000` Elem0x28_CompleteDtor | **accept-with-gaps** — element CF/ABI/stride 0x28/field free order sealed; product types open |
| `aa_004975e0` Class_009c7a1c_ScalarDeletingDtor | **accept** — scalar-deleting CF/ABI/vtbl[0]/RET 4 sealed; body twin W28-M |

---

## VA `0x005b8000` — sealed facts

1. **Body:** `0x005b8000`–`0x005b810b` exclusive (**267 B** / `0x10B`). Final bare **`RET`** (`C3` @ `0x005b810a`); pad `CC`; next fn @ `0x005b8110`.
2. **ABI:** **`__thiscall`** (Ghidra `__fastcall` + ECX = same); ECX = element; no stack formals; **void**; bare **`RET`**.
3. **Semantics:** MSVC **element complete destructor** for **0x28-byte** cookie-vector elements:
   - SEH `LAB_009a6b0a`, EH state `1` on owned path.
   - If owned @ `+0x24`: `FUN_004be2a0(owned)` (ECX=owned) then `operator_delete(owned)`; zero `+0x24`.
   - For each list-host pointer in vector `[+0x14,+0x18)`: free node payloads @ `node+8`; empty list (sentinel self-links, size 0); free remaining nodes + head + list host.
   - Free vector storage @ `+0x14`; zero begin/end/cap.
   - Free buffer begin @ `+0x4`; zero begin/end/cap.
4. **Classification:** worker (element dtor callback; not vtbl[0]).
5. **Xrefs (4 DATA):** `FUN_004970b0` @ `0x004970ec`; `FUN_00494170` @ `0x00494181`; `FUN_004941b0` @ `0x004941da`, `0x004942d6`.
6. **Callees:** `FUN_004be2a0`, `operator_delete`.
7. **Related:** Host complete dtor `Class_009c7a1c_CompleteDtor` (`0x004970b0`, W28-M); scalar deleting `0x004975e0` (this dual).
8. **Name:** `Elem0x28_CompleteDtor` (Ghidra `FUN_005b8000`). Reject scaffold VOG_DEBUG_STOP alias. Product demangle open.
9. **Decompile ≡ raw CF** for order; false noreturn on `operator_delete` ignored (bytes fall-through).

### Gaps

- Product English / demangle for element type and owned object (`FUN_004be2a0`).  
- List node payload semantics.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005b8000_Elem0x28_CompleteDtor.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005b8000_Elem0x28_CompleteDtor.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_005b8000_FUN_005b8000.md` |
| Annotated | `docs/reconstruction/raw/aa_005b8000_FUN_005b8000.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Elem0x28_CompleteDtor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005b8000.cpp` |
| Function | `docs/reconstruction/functions/aa_005b8000_FUN_005b8000.md` |
| Function named | `docs/reconstruction/functions/aa_005b8000_Elem0x28_CompleteDtor.md` |
| Scratch | `docs/reconstruction/tmp/a_005b8000.md` |

---

## VA `0x004975e0` — sealed facts

1. **Body:** `0x004975e0`–`0x004975fe` exclusive (**30 B** / `0x1E`). Epilogue **`RET 4`** (`C2 04 00`); pad `CC CC`.
2. **ABI:** **`__thiscall`**; ECX = `this`; stack formal `flags`; cleans **4** bytes; returns `this` in EAX.
3. **Semantics:** MSVC **scalar-deleting destructor** = **vtbl[0]** of `PTR_FUN_009c7a1c` (dword @ `0x009c7a1c` = `0x004975e0`):
   - `ESI = this`
   - `call FUN_004970b0` / `Class_009c7a1c_CompleteDtor`
   - `if (flags & 1) operator_delete(this)`
   - `return this; RET 4`
4. **Classification:** worker (scalar-deleting wrapper).
5. **Xrefs (1 DATA):** vtbl `PTR_FUN_009c7a1c` only.
6. **Callees:** `FUN_004970b0`, `operator_delete`.
7. **Body twin:** `Class_009c7a1c_CompleteDtor` (W28-M **accept-with-gaps**).
8. **Name:** `Class_009c7a1c_ScalarDeletingDtor` (Ghidra `FUN_004975e0`). **Do not** merge with complete body or element dtor.
9. **Decompile ≡ raw CF**; false noreturn ignored; full-body hex seals all branches.

### Gaps

- Product English / MSVC demangle for class behind `PTR_FUN_009c7a1c` (naming only).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004975e0_Class_009c7a1c_ScalarDeletingDtor.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_004975e0_Class_009c7a1c_ScalarDeletingDtor.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004975e0_FUN_004975e0.md` |
| Annotated | `docs/reconstruction/raw/aa_004975e0_FUN_004975e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Class_009c7a1c_ScalarDeletingDtor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004975e0.cpp` |
| Function | `docs/reconstruction/functions/aa_004975e0_FUN_004975e0.md` |
| Function named | `docs/reconstruction/functions/aa_004975e0_Class_009c7a1c_ScalarDeletingDtor.md` |
| Scratch | `docs/reconstruction/tmp/a_004975e0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `005b8000` | Port as **element dtor** only (stride **0x28**). Destroy owned@+0x24 via `FUN_004be2a0`+delete; tear down list-ptr vector @+0x14; free buffer @+0x4. Used by Class_009c7a1c vector path and `FUN_00494170`/`FUN_004941b0`. Ignore Ghidra noreturn on `operator_delete`. |
| `004975e0` | Port as **scalar-deleting** wrapper only: always `Class_009c7a1c_CompleteDtor(this)`; if `(flags&1)` free host; `ret 4`. Keep separate from complete body and element dtor. |
| Pair with | `Class_009c7a1c_CompleteDtor` (`0x004970b0`), owned dtor `FUN_004be2a0`, `StdList_Destroy_FreeHead` (`0x00497360`, inside complete body). |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; names use vtbl/stride structural roles.
