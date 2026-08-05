# Dual A/B report — W36-P OWN `aa_00466df0` + `aa_0046a350`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W36-P  
**Scope:** VAs `0x00466df0`, `0x0046a350` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` / `batch_decompile` + `read_memory` + `analyze_function_complete` + xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave36_partition_map.md` (W36-P).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00466df0` StdVector_Resize_Elem28_Inferred | **accept-with-gaps** — EBX=vec / ECX=new_size / stack value 0x1c / RET 1C / grow+shrink sealed; erase helper + parent open |
| `aa_0046a350` StdUninitCopy_Elem28_Inferred | **accept** — 34 B leaf uninit_copy; EAX dst / EDX src_begin / EBX src_end; stride 0x1c; null gate sealed |

---

## VA `0x00466df0` — sealed facts

1. **Body:** `0x00466df0`–`0x00466e91` inclusive (**162 B** / `0xA2`; pad `CC` then next @ `0x00466ea0` InsertN).
2. **ABI:** **EBX=`vec*`**, **ECX=`new_size`**, stack **Elem28 value by value (0x1c)**, **`RET 0x1C`**.
3. **Semantics:** MSVC-style **`vector<T>::resize(n, value)`** for POD T size **0x1c**:
   - Size = `begin? (end@+8 − begin@+4)/0x1c : 0` via magic **`0x92492493`**.
   - **Grow** if `size < new_size`: `count = new_size − size`; call sealed **`StdVector_InsertN_Elem28_CountEcx_Inferred`** (`0x00466ea0`) with **ECX=count**, **EDX=vec**, stack **where=end** + **value\***; RET 1C.
   - **Shrink** if `begin && new_size < size`: `new_end = begin + new_size*0x1c`; call **`FUN_0045cce0`** erase `[new_end, end)`.
   - Equal / empty: no-op, RET 1C.
4. **Classification:** **worker**.
5. **Callers (1):** `FUN_00963fb0` @ `0x0096443d`.
6. **Callees:** `FUN_00466ea0` (W34-Q sealed InsertN), `FUN_0045cce0` (erase, unowned).
7. **Name:** `StdVector_Resize_Elem28_Inferred` (Ghidra `FUN_00466df0`; **Inferred** structural). Twin of `StdVector_Resize_Pod28` (`0x0045c4b0`). **Reject** scaffold `Named_CalleeOf_…_anmAnimMaster_00466df0`.
8. **Decompile vs bytes:** CF ≡ raw; **bytes win** on EBX=vec, stack value blob, RET 1C, InsertN call formals.  
   Full hex: raw W36-P append (162 B).

### Gaps

- Product/PDB T English (anmAnimMaster residual only).  
- Erase helper `FUN_0045cce0` + parent `FUN_00963fb0` not dual-owned.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00466df0_StdVector_Resize_Elem28_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00466df0_StdVector_Resize_Elem28_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00466df0_FUN_00466df0.md` |
| Annotated | `docs/reconstruction/raw/aa_00466df0_FUN_00466df0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_Resize_Elem28_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00466df0.cpp` |
| Function | `docs/reconstruction/functions/aa_00466df0_FUN_00466df0.md` |
| Function named | `docs/reconstruction/functions/aa_00466df0_StdVector_Resize_Elem28_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_00466df0.md` |

---

## VA `0x0046a350` — sealed facts

1. **Body:** `0x0046a350`–`0x0046a371` inclusive (**34 B** / `0x22`; pad `CC` then unrelated).
2. **ABI:** **EAX=`dest*`** (in) / **`dest_end*`** (out), **EDX=`src_begin*`**, **EBX=`src_end*`**; bare **`RET`**. Decompiler phantom `param_1` is **not** a formal.
3. **Semantics:** MSVC-style **`uninitialized_copy`** for POD T size **0x1c**:
   - Empty range: `EDX == EBX` → return.
   - Loop: if dest non-null, `REP MOVSD` 7 dwords; always `ADD EDX/EAX, 0x1C`.
   - Null-dest skips stores but still advances (compiler family artifact).
4. **Classification:** leaf worker — 0 callees.
5. **Callers (1 func / 4 sites):** `FUN_00469f50` @ `0x0046a07f`, `0x0046a0b4`, `0x0046a16b`, `0x0046a1c8` (ValueEdx InsertN; W34-Q).
6. **Callees:** none.
7. **Name:** `StdUninitCopy_Elem28_Inferred` (Ghidra `FUN_0046a350`; **Inferred**). **Reject** scaffold long `Named_CalleeOf_…`.
8. **Decompile vs bytes:** CF ≡ forward 7-dword range copy; **bytes win** on three-register formals + bare RET + EAX live-out.  
   Full hex: raw W36-P append (34 B).

### Gaps

- Product/MSVC demangle English.  
- Concrete POD T identity.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0046a350_StdUninitCopy_Elem28_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0046a350_StdUninitCopy_Elem28_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0046a350_FUN_0046a350.md` |
| Annotated | `docs/reconstruction/raw/aa_0046a350_FUN_0046a350.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdUninitCopy_Elem28_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0046a350.cpp` |
| Function | `docs/reconstruction/functions/aa_0046a350_FUN_0046a350.md` |
| Function named | `docs/reconstruction/functions/aa_0046a350_StdUninitCopy_Elem28_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_0046a350.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00466df0` | Port as **POD vector resize**: **EBX=vec**, **ECX=new_size**, stack **value by value 0x1c**, **RET 1C**. Grow via sealed InsertN CountEcx ABI; shrink via erase. Do **not** drop in Pod28 resize (`0045c4b0`) or BasicString thiscall/RET C ABIs. |
| `0046a350` | Port as **elem-28 uninit_copy**: **EAX=dst**, **EDX=src_begin**, **EBX=src_end**, bare RET, EAX=dst_end out. Null-safe store + always advance 0x1c. Do **not** conflate with stack-last `004673b0`, copy_backward `0046a240`, or fill-n `0046a260`. |
| Shared | Closes W34-Q residuals: sole parent of CountEcx InsertN + ValueEdx InsertN's uninit_copy leaf. Server needs one correct `List<T>.Resize` + range relocate for 28-byte POD — retail register ABIs are compile artifacts. |

Shared context (not owned):

| VA | Role |
|---|---|
| `0x00466ea0` | `StdVector_InsertN_Elem28_CountEcx_Inferred` (W34-Q) — grow callee of resize |
| `0x00469f50` | `StdVector_InsertN_Elem28_ValueEdx_Inferred` (W34-Q) — sole parent of uninit_copy |
| `0x0045cce0` | erase/truncate for shrink |
| `0x0045c4b0` | `StdVector_Resize_Pod28` structural twin (W35-M) |
| `0x004673b0` | `StdVector_UninitializedCopy_Elem28_Inferred` stack-last peer (W35-T) |
| `0x0046a240` | `StdCopyBackward_Elem28_Inferred` (W35-L) |
| `0x0046a260` | sibling fill-n next symbol |
| `0x00469c50` | `StdVector_Elem28_Size` (W33-J) — size inlined in resize |
| `0x00963fb0` | sole resize parent |

Closes W36-P OWN pair: **Elem28 resize parent** of CountEcx InsertN + **ValueEdx uninit_copy leaf**.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names; `_Inferred` structural names only.  
- Rejected long Named_CalleeOf scaffold aliases.  
- Avoided bare `undefined4` in clean (`uint32_t` / explicit `Elem28`).
