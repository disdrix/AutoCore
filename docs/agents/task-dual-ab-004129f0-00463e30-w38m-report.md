# Dual A/B report — W38-M OWN `aa_004129f0` + `aa_00463e30`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual W38-M  
**Scope:** VAs `0x004129f0`, `0x00463e30` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + xrefs + `get_assembly_context` + helper decompiles. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wave38_partition_map.md` (W38-M).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004129f0` Map_Tree_Predecessor_Isnil15_Edx | **accept** — tree iterator predecessor; isnil@+0x15; **EDX=it**; 81 B sealed leaf |
| `aa_00463e30` StdVector_InsertN_Dword_Via4ea70_Inferred | **accept-with-gaps** — thiscall dword insert-N; 1.5× grow; helpers 4ea70/36ef0/4ea50; decompiler post-delete gap documented |

---

## VA `0x004129f0` — sealed facts

1. **Body:** `0x004129f0`–`0x00412a40` inclusive (**81 B** / `0x51`); pad `CC` then sibling `FUN_00412a50` @ `0x00412a50`.
2. **ABI:** **`EDX = Node**`** (entry `mov eax,[edx]`); no stack args; void; bare **`ret`** (`c3` on all exits). Decompiler invents unused `__fastcall` first arg — **ignore**.
3. **Semantics:** MSVC **`_Tree::_Dec` / iterator--** (in-order **predecessor**):
   - If `(*it)->isnil` → `*it = right` (end → rightmost via header.right)
   - Else if left not isnil → rightmost of left subtree
   - Else climb parents while current is parent's left; if parent not isnil → `*it = parent`
4. **Node (partial):** left`+0`, parent`+4`, right`+8`, isnil **`+0x15`**.
5. **Classification:** shared leaf (8 CODE xrefs / 8 caller funcs). **Not** successor, insert, rebalance, key compare, or color.
6. **Callers:** `FUN_00411fa0`, `FUN_0041b360`, `FUN_0041d680`, `FUN_00421050`, `FUN_0043daf0`, `FUN_00452190`, `FUN_004582e0`, `FUN_00458510` — sites load `lea edx,[esp+…]` then `call`.
7. **Callees:** none (leaf).
8. **Name:** `Map_Tree_Predecessor_Isnil15_Edx` (Ghidra `FUN_004129f0`; **Inferred**). Peer ECX twin: sealed `Map_Tree_Predecessor_Isnil15` @ `0x005a2850` (W19-N). **Reject** scaffold `Named_CalleeOf_…Mission_bActiveObj_004129f0`.
9. **Decompile ≡ bytes** for CF; register **EDX** sealed by body + call-site context. Full hex in raw W38-M append.

### Gaps

- Product/MSVC demangle (`_Tree_unchecked_const_iterator::operator--`).  
- Full value/color layout per caller map.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004129f0_Map_Tree_Predecessor_Isnil15_Edx.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_004129f0_Map_Tree_Predecessor_Isnil15_Edx.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004129f0_FUN_004129f0.md` |
| Annotated | `docs/reconstruction/raw/aa_004129f0_FUN_004129f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Map_Tree_Predecessor_Isnil15_Edx.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004129f0.cpp` |
| Function | `docs/reconstruction/functions/aa_004129f0_FUN_004129f0.md` |
| Function named | `docs/reconstruction/functions/aa_004129f0_Map_Tree_Predecessor_Isnil15_Edx.md` |

---

## VA `0x00463e30` — sealed facts

1. **Body:** `0x00463e30`–`0x00464070` inclusive (**577 B** / `0x241`); pad `CC` then next function SEH prolog.
2. **ABI:** **`__thiscall`**; ECX = vector control (`begin@+4`, `end@+8`, `capEnd@+0xC`); stack **`(where*, count, value*)`**; void; **`ret 0xC`** (`c2 0c 00`).
3. **Semantics:** MSVC-style **`vector<uint32_t>::insert(where, count, value)`**:
   - `size` / `cap` via `>>2`; early-out if `count==0`
   - **Throw** if `size+count > 0x3fffffff` via **`FUN_004540b0`** (`vector<T> too long`)
   - **Realloc** if `cap < size+count`: newCap = 1.5× (`cap+(cap>>1)`) floored to `size+count`; `operator_new`; relocate prefix/fill/suffix; optional `operator_delete(old)`; rewrite triad
   - **In-place**: end-biased shift+fill or mid-shift via copy helpers + fill
4. **Helpers:** `FUN_0044ea70` (forward dword copy), `FUN_00436ef0` (fill-n), `FUN_0044ea50` (backward dword copy).
5. **Decompiler pitfall:** `operator_delete` marked **noreturn** — **bytes win**: triad rewrite + `ret 0xC` after optional delete.
6. **Classification:** multi-domain worker (16 CODE xrefs / 13 caller funcs).
7. **Callers (sample):** `FUN_00449a90`, `FUN_0044a380` (W37-Z), `FUN_0044cb20`, `FUN_0073bad0`, `FUN_00746d40`, `FUN_0074a2e0`, `FUN_0074e3e0`, `FUN_0075d6f0`, `FUN_007649c0`, `FUN_0096e710`, `FUN_00983720`, `FUN_0098dd70`, `FUN_0098fc40`.
8. **Callees:** `0044ea70`, `00436ef0`, `0044ea50`, `004540b0`, `operator_new`/`delete`.
9. **Name:** `StdVector_InsertN_Dword_Via4ea70_Inferred` (Ghidra `FUN_00463e30`; **Inferred**). Twins: thiscall family `0x004073a0`; count-ECX `0x00419880` (W23-D). **Reject** scaffold `Named_CalleeOf_Named_effVertexDecl_00463e30`.
10. **Decompile CF spine OK** except post-delete; machine seals ABI/growth/throw. Details in raw W38-M append.

### Gaps

- Product/MSVC demangle.  
- Bit-exact micro-ABI of in-place shift ranges (helper duals preferred).  
- Full caller taxonomy.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00463e30_StdVector_InsertN_Dword_Via4ea70_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00463e30_StdVector_InsertN_Dword_Via4ea70_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00463e30_FUN_00463e30.md` |
| Annotated | `docs/reconstruction/raw/aa_00463e30_FUN_00463e30.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_InsertN_Dword_Via4ea70_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00463e30.cpp` |
| Function | `docs/reconstruction/functions/aa_00463e30_FUN_00463e30.md` |
| Function named | `docs/reconstruction/functions/aa_00463e30_StdVector_InsertN_Dword_Via4ea70_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004129f0` | Port as **tree iterator `--`** for isnil@+0x15 nodes. On x86 retail shape the iterator pointer is passed in **EDX** (not ECX). Do **not** unify call convention with ECX peer `0x005a2850` without site check. Pure link walk — no map shell, no key compare. |
| `00463e30` | Port as **`vector<uint32_t>::insert(it, n, value)`** on MSVC 3-pointer vector (`begin+4`/`end+8`/`cap+0xC`). Growth 1.5×; throw via `004540b0` when size would exceed `0x3fffffff`. Relocate via POD dword copy/fill helpers (`0044ea70` / `00436ef0` / `0044ea50`). Prefer **bytes** over decompiler after `delete`. **Do not** use count-in-ECX ABI of twin `00419880`. |
| Shared | Unrelated domains (tree iterator leaf vs dword vector insert engine). Co-owned only by W38-M partition pair. |

Shared context (not owned):

| VA | Role |
|---|---|
| `0x005a2850` | `Map_Tree_Predecessor_Isnil15` (ECX peer of `004129f0`) |
| `0x005ae050` | `StdTree_Dec_Val12` (isnil@+0x19) |
| `0x004540b0` | `vector<T> too long` throw |
| `0x0044ea70` / `0x00436ef0` / `0x0044ea50` | dword forward copy / fill-n / backward copy |
| `0x004073a0` | thiscall insert-N twin (other helpers) |
| `0x00419880` | count-in-ECX insert-N twin (W23-D) |
| `0x0044a380` | W37-Z consumer of insert-N |

Closes W38-M OWN pair: isnil15 tree predecessor (**EDX**) + dword vector insert-N (thiscall via 4ea70 helpers).

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers + assembly context + helper decompiles. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names; `_Inferred` / structural names only.  
- Rejected long Named_CalleeOf scaffold aliases.  
- Clean avoids bare `undefined4` (`uint32_t` / explicit structs).
