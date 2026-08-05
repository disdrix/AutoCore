# Dual A/B report — W31-A OWN `aa_0040d630` + `aa_0040d820`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W31-A  
**Scope:** VAs `0x0040d630`, `0x0040d820` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` + xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave31_partition_map.md` (W31-A).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0040d630` StdTree_FreeSubtree_Val12 | **accept-with-gaps** — left-walk free + recursive right + ABI/RET4 sealed; product node type residual |
| `aa_0040d820` StdTreeHost_PtrVal_CompleteDtor | **accept-with-gaps** — complete-dtor stage order/ABI/vtbl/this+4 sealed; product class + nested `FUN_0040d7c0` open |

---

## VA `0x0040d630` — sealed facts

1. **Body:** `0x0040d630`–`0x0040d664` (**53 B** / `0x35`; pad `CC`).
2. **ABI:** **ECX=`tree_base`** (threaded; unused in body except recursive pass); stack **`node*`**; **`RET 4`** (`C2 04 00`); void. Ghidra decompiler dropped ECX and showed false noreturn.
3. **Semantics:** MSVC-style **`_Tree` free-subtree** on Val12 nodes (isnil@`+0x19`, left@`+0`, right@`+8`):
   - If node isnil: return.
   - Loop: **`FUN_0040d630(right)`** with same ECX; `operator_delete(node)` (cdecl); advance **left**.
   - Does **not** destroy `T*` values (clear phase owns vtbl[+0xc]).
4. **Classification:** worker.
5. **Callers:** `FUN_0040d5b0` @ `0x0040d5f6` (clear free path; ECX=this+4); `FUN_0040d700` @ `0x0040d71c`; self @ `0x0040d647`.
6. **Callees:** self, `operator_delete`.
7. **Name:** `StdTree_FreeSubtree_Val12` (Ghidra `FUN_0040d630`; **Inferred** structural). Closes nested free residual named in W30-P clear dual.
8. **Decompile ≢ bytes** on free path (collapsed); **bytes win**.  
   Full hex: raw W31-A append (53 B).

### Gaps

- Product/MSVC demangle for node / map T.  
- tree_base semantic use beyond threading.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0040d630_StdTree_FreeSubtree_Val12.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0040d630_StdTree_FreeSubtree_Val12.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0040d630_FUN_0040d630.md` |
| Annotated | `docs/reconstruction/raw/aa_0040d630_FUN_0040d630.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_FreeSubtree_Val12.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0040d630.cpp` |
| Function | `docs/reconstruction/functions/aa_0040d630_FUN_0040d630.md` |
| Function named | `docs/reconstruction/functions/aa_0040d630_StdTree_FreeSubtree_Val12.md` |
| Scratch | `docs/reconstruction/tmp/a_0040d630.md` |

---

## VA `0x0040d820` — sealed facts

1. **Body:** `0x0040d820`–`0x0040d86f` (**80 B** / `0x50`).
2. **ABI:** **ECX=`this`**; SEH `LAB_009be2bb`; EH state **0** during clear then **`0xFFFFFFFF`**; epilogue **`ADD ESP,0x10; RET`**. Complete dtor — **does not** free `this`.
3. **Semantics:**
   - Install **`PTR_FUN_009c7938`** at `*this`.
   - **`FUN_0040d5b0(this)`** — sealed clear (value destroy + free nodes + empty reset).
   - **`FUN_0040d7c0(this+4)`** — bytes `LEA ECX,[ESI+4]` (decompiler missed adjust).
4. **Classification:** worker (complete dtor body).
5. **Callers:** `FUN_0040d590` (scalar-deleting dtor, vtbl[0]); `FUN_0040d890` (derived complete after `PTR_FUN_009c7948`); Unwind `@009be2d3`.
6. **Callees:** `FUN_0040d5b0`, `FUN_0040d7c0`.
7. **Name:** `StdTreeHost_PtrVal_CompleteDtor` (Ghidra `FUN_0040d820`; **Inferred**).
8. **Vtbl** `0x009c7938`: [0]=`0x0040d590`, [2]=`0x0040d5b0` (read_memory).  
   Full hex: raw W31-A append (80 B).

### Gaps

- Product/MSVC demangle for host class and map T.  
- Nested `FUN_0040d7c0` product English (not owned).  
- Vtbl slot[1] `0x00489918`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0040d820_StdTreeHost_PtrVal_CompleteDtor.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0040d820_StdTreeHost_PtrVal_CompleteDtor.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0040d820_FUN_0040d820.md` |
| Annotated | `docs/reconstruction/raw/aa_0040d820_FUN_0040d820.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTreeHost_PtrVal_CompleteDtor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0040d820.cpp` |
| Function | `docs/reconstruction/functions/aa_0040d820_FUN_0040d820.md` |
| Function named | `docs/reconstruction/functions/aa_0040d820_StdTreeHost_PtrVal_CompleteDtor.md` |
| Scratch | `docs/reconstruction/tmp/a_0040d820.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0040d630` | Port as **free-subtree**: recursive free right, `delete` node, walk left; stop at isnil. Thread unused tree_base. **RET 4**. Do **not** destroy values here. Ignore Ghidra noreturn. |
| `0040d820` | Port as **complete dtor only**. Install `PTR_FUN_009c7938`, clear (`StdTree_Clear_PtrVal_Vtbl0C`), then `FUN_0040d7c0(this+4)`. Scalar path is `FUN_0040d590`. |
| Pair with | `StdTree_Clear_PtrVal_Vtbl0C` (`0x0040d5b0`, W30-P), `StdTree_Inc_Val12` (`0x005ae0b0`), scalar `FUN_0040d590`, nested head free `FUN_0040d7c0` (unowned). |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; structural `_Inferred` names only.  
- Avoided bare `undefined4` in clean (`uint32_t` / explicit structs).  
- Closes W30-P residual “nested free helper `FUN_0040d630` not dual-owned”.
