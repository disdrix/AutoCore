# Dual A/B report — W36-L OWN `aa_007647c0` + `aa_0045cce0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W36-L  
**Scope:** VAs `0x007647c0`, `0x0045cce0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave36_partition_map.md` (W36-L).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_007647c0` Host_RegisterObjectAndAccumulateBounds | **accept-with-gaps** — thiscall+RET4 host register + Bounds handoff sealed; virtual product English open |
| `aa_0045cce0` StdVector_EraseRange_Pod28 | **accept-with-gaps** — stack erase-range stride 0x1c + RET 10 sealed; product T English open |

---

## VA `0x007647c0` — sealed facts

1. **Body:** `0x007647c0`–`0x0076482d` exclusive (**109 B** / `0x6D`; pad `CC`×3 then next @ `0x00764830`).
2. **ABI:** **ECX=`host*`**, stack **`object*`**, **`RET 4`**. Decompiler shows thiscall pair; bytes seal cleanup.
3. **Semantics:** Host-side **register object + fold bounds**:
   - `FUN_004406e0`: push `object*` into **vector at host+0xbc** (EAX=vec, ESI=&value).
   - Object virt **+0x20**(host); optional virt **+0x80** (gate +0x58/+0x5c/+0x60); optional virt **+0x5c** (flag bit0 @ object+0xbc).
   - Host virt **+0x0c**(object+0x28, object+0x64) → xformRef.
   - **`Bounds_AccumulateTransformedLocal`** (`0x0074c9c0`, W21-O): ECX=host+4, stack (xform, local@+0x28, scale@+0x64), ret 12.
4. **Classification:** **worker**.
5. **Callers:** multi (~37 xrefs) — e.g. `CVOGTacArc_InitializeMesh`, `FUN_0073c810` (HostPtrTable12 Bootstrap), mesh/host helpers. **Not** TacArc-only.
6. **Callees:** `FUN_004406e0`, `FUN_0074c9c0`, object/host virtuals.
7. **Name:** `Host_RegisterObjectAndAccumulateBounds` (Ghidra `FUN_007647c0`; **Inferred**). **Reject** scaffold `Named_CalleeOf_CVOGTacArc_InitializeMesh_007647c0`.
8. **Decompile vs bytes:** CF matches; **bytes win** on RET 4 and Bounds stack packing. Full hex: raw W36-L append.

### Gaps

- Product/PDB host + object English.  
- Virtual slot meanings (offsets sealed).  
- Host virt+0x0c clean convention residual (Bounds entry stack image sealed).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_007647c0_Host_RegisterObjectAndAccumulateBounds.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_007647c0_Host_RegisterObjectAndAccumulateBounds.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_007647c0_FUN_007647c0.md` |
| Annotated | `docs/reconstruction/raw/aa_007647c0_FUN_007647c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Host_RegisterObjectAndAccumulateBounds.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_007647c0.cpp` |
| Function | `docs/reconstruction/functions/aa_007647c0_FUN_007647c0.md` |
| Function named | `docs/reconstruction/functions/aa_007647c0_Host_RegisterObjectAndAccumulateBounds.md` |

---

## VA `0x0045cce0` — sealed facts

1. **Body:** `0x0045cce0`–`0x0045cd2b` exclusive (**75 B** / `0x4B`; pad `CC`×5 then `FUN_0045cd30` InsertN Pod28 @ `0x0045cd30`).
2. **ABI:** stack **`(vec*, out_it*, first, last)`**, **`RET 0x10`**, return **`out_it*`** in EAX.
3. **Semantics:** MSVC-style **`vector<T>::erase(first, last)`** for POD T size **0x1c**:
   - Empty (first==last): no end write; still `*out=first`.
   - last==end: truncate — `end = first` (resize shrink path).
   - last < end: forward copy 7 dwords per element until last reaches old end; publish new end.
4. **Classification:** **leaf**.
5. **Callers (2):** `FUN_0045c4b0` (`StdVector_Resize_Pod28`) @ `0x0045c547`; `FUN_00466df0` @ `0x00466e87` (W36-P OWN, unowned here).
6. **Callees:** none.
7. **Name:** `StdVector_EraseRange_Pod28` (Ghidra `FUN_0045cce0`; **Inferred**). **Reject** scaffold `Named_CalleeOf_*anmTrackMaster*0045cce0`.
8. **Decompile ≡ bytes** for CF/stride; **bytes win** on RET 10 + 4 stack formals. Full hex: raw W36-L append.

### Gaps

- Product/PDB T English (anm residual only).  
- Parent `FUN_00466df0` not dual-owned here.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0045cce0_StdVector_EraseRange_Pod28.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0045cce0_StdVector_EraseRange_Pod28.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0045cce0_FUN_0045cce0.md` |
| Annotated | `docs/reconstruction/raw/aa_0045cce0_FUN_0045cce0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_EraseRange_Pod28.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0045cce0.cpp` |
| Function | `docs/reconstruction/functions/aa_0045cce0_FUN_0045cce0.md` |
| Function named | `docs/reconstruction/functions/aa_0045cce0_StdVector_EraseRange_Pod28.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `007647c0` | Port as **host register + bounds fold**: **ECX=host**, stack **object***, **RET 4**. Append object* to host+0xbc; run object virt prep; host virt+0x0c → xform; call **`Bounds_AccumulateTransformedLocal`(host+4, xform, obj+0x28, obj+0x64)**. Do **not** treat as TacArc-only. Virtual bodies are hooks — do not invent product names. |
| `0045cce0` | Port as **POD vector erase-range** stride **0x1c**: stack **(vec, out_it, first, last)**, **RET 10**, return out_it. Forward shift + publish end. Resize shrink uses last==end (truncate only). Do **not** use string erase / destroy-range ABIs. |

Shared context (not owned):

| VA | Role |
|---|---|
| `0x0074c9c0` | `Bounds_AccumulateTransformedLocal` (W21-O) — bounds callee of host register |
| `0x004406e0` | ptr-vector push helper |
| `0x0045c4b0` | `StdVector_Resize_Pod28` (W35-M) — shrink parent of erase |
| `0x0045cd30` | `StdVector_InsertN_Pod28` (W34-P) — next symbol after erase |
| `0x00466df0` | other erase parent (W36-P OWN) |
| `0x0073c810` | HostPtrTable12 Bootstrap caller of register |

Closes W36-L OWN pair: **host object-register/bounds worker** + **Pod28 erase-range leaf** (resize shrink residual).

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; `_Inferred` structural names only.  
- Rejected Named_CalleeOf scaffold aliases.  
- Avoided bare `undefined4` in clean (`uint32_t` / explicit structs).
