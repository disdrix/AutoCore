# Dual A/B report — W38-F OWN `aa_00437e40` + `aa_00437f70`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual W38-F  
**Scope:** VAs `0x00437e40`, `0x00437f70` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + callers/xrefs + `get_function_by_address` + context decompile of stack dtor `FUN_00437da0`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wave38_partition_map.md` (W38-F).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00437e40` StdVector_Resize_Elem56_Inferred | **accept-with-gaps** — EDI=vec / ECX=n / stack value 0x38 / RET 38 / grow+shrink + dual-string T sealed; InsertN/erase unowned |
| `aa_00437f70` StdVector_Resize_Elem20_Inferred | **accept-with-gaps** — ESI=vec / ECX=n / stack value 0x14 / RET 14 / grow+shrink sealed; T English + epilogue helper open |

---

## VA `0x00437e40` — sealed facts

1. **Body:** `0x00437e40`–`0x00437f1e` exclusive (**222 B** / `0xDE`; pad `CC` then `FUN_00437f20`). Ghidra end `00437f1d` last byte of `C2 38 00` — **bytes win**.
2. **ABI:** **EDI=vec***, **ECX=new_size**, stack **Elem56 by value (0x38)**, **`RET 0x38`**.
3. **Semantics:** MSVC-style **`vector<T>::resize(n, value)`** for non-trivial T size **0x38**:
   - Size = `begin? (end@+8 − begin@+4)/0x38 : 0` via magic **`0x92492493`**.
   - **Grow** if `size < new_size`: `FUN_00438520(vec, where=end, count=new−size, &value)`.
   - **Shrink** if `begin && new_size < size`: `new_end = begin + new_size*0x38`; `FUN_00438430(vec, it*, new_end, end)`.
   - Equal / empty: no-op.
   - Epilogue: **`FUN_00437da0(&value)`** — destroys **two** MSVC `basic_string` at **T+0** and **T+0x1c**.
4. **Classification:** **worker**.
5. **Callers (4 functions / 7 sites):** `FUN_00437ad0` @ `0x00437ae4`; `FUN_00765740` @ `0x00765a21`, `0x00765dfb`; `FUN_0095e3e0` ×3; `FUN_009895c0` @ `0x0098979b`.
6. **Callees:** `FUN_00438520` (grow), `FUN_00438430` (shrink), `FUN_00437da0` (stack T dtor).
7. **Name:** `StdVector_Resize_Elem56_Inferred` (Ghidra `FUN_00437e40`; **Inferred**). **Reject** scaffold `Named_CalleeOf_*gfxBody*`.
8. **Decompile ≡ CF**; **bytes win** on EDI=vec, stack value, RET 38, call formals.  
   Full hex: raw W38-F append (222 B).

### Gaps

- Product/PDB T English (dual-string layout sealed; plate name open).  
- Unowned InsertN `FUN_00438520` / erase `FUN_00438430`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00437e40_StdVector_Resize_Elem56_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00437e40_StdVector_Resize_Elem56_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00437e40_FUN_00437e40.md` |
| Annotated | `docs/reconstruction/raw/aa_00437e40_FUN_00437e40.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_Resize_Elem56_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00437e40.cpp` |
| Function | `docs/reconstruction/functions/aa_00437e40_FUN_00437e40.md` |
| Function named | `docs/reconstruction/functions/aa_00437e40_StdVector_Resize_Elem56_Inferred.md` |

---

## VA `0x00437f70` — sealed facts

1. **Body:** `0x00437f70`–`0x00438040` exclusive (**208 B** / `0xD0`). Ghidra end `0043803f` last byte of `C2 14 00` — **bytes win**. Next: `FUN_00438040` (W38-G).
2. **ABI:** **ESI=vec***, **ECX=new_size**, stack **Elem20 by value (0x14)**, **`RET 0x14`**.
3. **Semantics:** MSVC-style **`vector<T>::resize(n, value)`** for T size **0x14**:
   - Size = `begin? (end−begin)/0x14 : 0` via magic **`0x66666667`**.
   - **Grow** if `size < new_size`: `FUN_004388b0(vec, where=end, count=new−size, &value)`.
   - **Shrink** if `begin && new_size < size`: `new_end = begin + new_size*0x14`; `FUN_00438850(vec, it*, new_end, end)`.
   - Equal / empty: no-op.
   - Epilogue calls **`FUN_00437f20`** (unowned; residual — do not seal as dual-string vector dtor product).
4. **Classification:** **worker**.
5. **Callers (1 function / 2 sites):** `FUN_00765740` @ `0x00765914`, `0x00765d6c`.
6. **Callees:** `FUN_004388b0`, `FUN_00438850`, `FUN_00437f20`.
7. **Name:** `StdVector_Resize_Elem20_Inferred` (Ghidra `FUN_00437f70`; **Inferred**). **Reject** scaffold `Named_CalleeOf_*gfxBody*`.
8. **Decompile ≡ CF**; **bytes win** on ESI=vec, stack value, RET 14.  
   Full hex: raw W38-F append (208 B).

### Gaps

- Product/PDB T English (0x14 lanes).  
- Unowned InsertN `FUN_004388b0` / erase `FUN_00438850`.  
- Epilogue `FUN_00437f20` role residual.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00437f70_StdVector_Resize_Elem20_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00437f70_StdVector_Resize_Elem20_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00437f70_FUN_00437f70.md` |
| Annotated | `docs/reconstruction/raw/aa_00437f70_FUN_00437f70.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_Resize_Elem20_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00437f70.cpp` |
| Function | `docs/reconstruction/functions/aa_00437f70_FUN_00437f70.md` |
| Function named | `docs/reconstruction/functions/aa_00437f70_StdVector_Resize_Elem20_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00437e40` | Port as **non-trivial vector resize**: **EDI=vec**, **ECX=new_size**, stack **value by value 0x38**, **RET 38**. T = two MSVC strings (+0 / +0x1c). Grow via InsertN-class; shrink via erase-range with element dtors. Do **not** use POD Pod28 (`0045c4b0`) / dword resize ABIs or invent ECX=this. |
| `00437f70` | Port as **elem-20 vector resize**: **ESI=vec**, **ECX=new_size**, stack **value by value 0x14**, **RET 14**. Separate register-vec from sibling (ESI vs EDI). Do **not** unify with Elem56 or Pod28. |
| Shared | Both are MSVC 3-pointer vector (`begin+4`/`end+8`) resize workers under `FUN_00765740` (gfxBody path). Sibling pair only by neighborhood + pattern — **different stride, vec register, and callees**. |

Shared context (not owned):

| VA | Role |
|---|---|
| `0x00438520` / `0x00438430` | Elem56 grow InsertN / shrink erase |
| `0x004388b0` / `0x00438850` | Elem20 grow InsertN / shrink erase |
| `0x00437da0` | Elem56 element dtor (two `basic_string`) |
| `0x00437f20` | between owned VAs; epilogue/vector helper residual |
| `0x00437ad0` | thin default-value wrapper → Elem56 resize |
| `0x00765740` | multi-site parent (also MapA factory consumer) |
| `0x004382c0` | default Elem56 ctor (W38-G neighbor) |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers + stack-dtor context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** (W38-F sections).  
- No invented product plates; `_Inferred` structural names (`StdVector_Resize_Elem*`).  
- Rejected scaffold gfxBody callee-of product roles.  
- Avoided bare `undefined4` in clean (`uint32_t` / explicit structs).
