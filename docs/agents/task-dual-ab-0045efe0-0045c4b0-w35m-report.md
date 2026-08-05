# Dual A/B report — W35-M OWN `aa_0045efe0` + `aa_0045c4b0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W35-M  
**Scope:** VAs `0x0045efe0`, `0x0045c4b0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave35_partition_map.md` (W35-M).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0045efe0` Pod28_FillAssign_Forward | **accept-with-gaps** — EAX/EDX/EBX leaf fill-assign stride 0x1c sealed; product T English open |
| `aa_0045c4b0` StdVector_Resize_Pod28 | **accept-with-gaps** — EBX=vec / ECX=new_size / stack value 0x1c / RET 1C / grow+shrink sealed; erase helper + parent open |

---

## VA `0x0045efe0` — sealed facts

1. **Body:** `0x0045efe0`–`0x0045effb` exclusive (**27 B** / `0x1B`; pad `CC` then sibling). Ghidra end `0045effa` last byte of `C3` — **bytes win**.
2. **ABI:** **EAX=dst_begin**, **EDX=dst_end**, **EBX=value\***. No stack. **`RET 0`** (`C3`). Decompiler `param_1` phantom — ignore.
3. **Semantics:** MSVC-style **forward fill-assign** of half-open `[EAX, EDX)` from single POD template `*EBX`:
   - Outer loop until cursor==end; each step `ADD EAX, 0x1C`.
   - Inner: `ECX=7`, `ESI=EBX`, `EDI=cursor`, **`rep movsd`** (7 dwords = 0x1c).
4. **Classification:** **leaf** (no callees).
5. **Callers (3):** `FUN_0045cd30` @ `0x0045d004`; `FUN_00466ea0` @ `0x0046715d`; `FUN_00469f50` @ `0x0046a1ec` (InsertN mid-hole fill).
6. **Name:** `Pod28_FillAssign_Forward` (Ghidra `FUN_0045efe0`; **Inferred** structural). Reject scaffold `Named_CalleeOf_*anmTrackMast*`.
7. **Decompile ≡ bytes** for CF; **bytes win** on register ABI and unused formal.  
   Full hex: raw W35-M append (27 B).

### Gaps

- Product/PDB T English (anm-track residual only).  
- Float vs dword lane interpretation residual (POD either way).  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0045efe0_Pod28_FillAssign_Forward.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0045efe0_Pod28_FillAssign_Forward.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0045efe0_FUN_0045efe0.md` |
| Annotated | `docs/reconstruction/raw/aa_0045efe0_FUN_0045efe0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Pod28_FillAssign_Forward.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0045efe0.cpp` |
| Function | `docs/reconstruction/functions/aa_0045efe0_FUN_0045efe0.md` |
| Function named | `docs/reconstruction/functions/aa_0045efe0_Pod28_FillAssign_Forward.md` |

---

## VA `0x0045c4b0` — sealed facts

1. **Body:** `0x0045c4b0`–`0x0045c552` exclusive (**162 B** / `0xA2`; pad `CC` then next). Ghidra end `0045c551` last byte of `C2 1C 00` — **bytes win**.
2. **ABI:** **EBX=vec\***, **ECX=new_size**, stack **Pod28 value by value (0x1c)**, **`RET 0x1C`**.
3. **Semantics:** MSVC-style **`vector<T>::resize(n, value)`** for POD T size **0x1c**:
   - Size = `begin? (end@+8 − begin@+4)/0x1c : 0` via magic **`0x92492493`**.
   - **Grow** if `size < new_size`: `count = new_size − size`; call sealed **`StdVector_InsertN_Pod28`** (`0x0045cd30`) with **ECX=count**, **EDX=vec**, stack **where=end** + **value\***; RET 1C.
   - **Shrink** if `begin && new_size < size`: `new_end = begin + new_size*0x1c`; call **`FUN_0045cce0`** erase `[new_end, end)` (POD 7-dword forward shift + publish end).
   - Equal / empty: no-op, RET 1C.
4. **Classification:** **worker**.
5. **Callers (1):** `FUN_00459750` @ `0x004599bf`.
6. **Callees:** `FUN_0045cd30` (W34-P sealed InsertN), `FUN_0045cce0` (erase, unowned).
7. **Name:** `StdVector_Resize_Pod28` (Ghidra `FUN_0045c4b0`; **Inferred** structural). Reject scaffold `Named_CalleeOf_*anmTrackMaster*`.
8. **Decompile ≡ bytes** for CF; **bytes win** on EBX=vec, stack value blob, RET 1C, InsertN call formals.  
   Full hex: raw W35-M append (162 B).

### Gaps

- Product/PDB T English (anm-track residual only).  
- Erase helper `FUN_0045cce0` + parent `FUN_00459750` not dual-owned.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0045c4b0_StdVector_Resize_Pod28.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0045c4b0_StdVector_Resize_Pod28.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0045c4b0_FUN_0045c4b0.md` |
| Annotated | `docs/reconstruction/raw/aa_0045c4b0_FUN_0045c4b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_Resize_Pod28.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0045c4b0.cpp` |
| Function | `docs/reconstruction/functions/aa_0045c4b0_FUN_0045c4b0.md` |
| Function named | `docs/reconstruction/functions/aa_0045c4b0_StdVector_Resize_Pod28.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0045efe0` | Port as **POD fill-assign forward** stride **0x1c**: **EAX=begin**, **EDX=end**, **EBX=value\***, **RET 0**. Re-read template each slot (`rep movsd` ×7). Do **not** treat as range-copy or string assign. |
| `0045c4b0` | Port as **POD vector resize**: **EBX=vec**, **ECX=new_size**, stack **value by value 0x1c**, **RET 1C**. Grow via InsertN Pod28 ABI; shrink via erase. Do **not** use BasicString thiscall/RET C ABIs. |

Shared context (not owned):

| VA | Role |
|---|---|
| `0x0045cd30` | `StdVector_InsertN_Pod28` (W34-P) — grow callee of resize; caller of fill-assign |
| `0x0045cce0` | erase/truncate for shrink |
| `0x00466ea0` / `0x00469f50` | other InsertN callers of fill-assign (W34-Q) |
| `0x0046a240` | assign-backward sibling of fill-assign |
| `0x00459750` | sole resize parent |
| `0x00469c50` | `StdVector_Elem28_Size` (W33-J) — size leaf; resize inlines ÷0x1c |

Together they close the **Pod28 resize parent** and the **shared fill-assign leaf** used by Pod28/Elem28 insert-n mid-hole paths.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; `_Inferred` structural names only (`Pod28_*` / `StdVector_*` family from W33–W34).  
- Avoided bare `undefined4` in clean (`uint32_t` / explicit structs).
