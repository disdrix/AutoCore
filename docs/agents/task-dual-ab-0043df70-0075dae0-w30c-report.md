
# Dual A/B report — W30-C OWN `aa_0043df70` + `aa_0075dae0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W30-C  
**Scope:** VAs `0x0043df70`, `0x0075dae0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` (+ callers/callees/xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave30_partition_map.md` (W30-C).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0043df70` GuardedVector_PopBack | **accept** — ECX ABI + size-- / empty begin=0 fully sealed; leaf; decompile ≡ bytes |
| `aa_0075dae0` Owner_ClearDestroyGuardedPtrDequeAt28 | **accept-with-gaps** — ECX owner +0x28 steal/destroy/free sealed from bytes; decompile broken; 0 xrefs + product English residual |

---

## VA `0x0043df70` — sealed facts

1. **Body:** `0x0043df70`–`0x0043df86` (**23 B** / `0x17`; pad `CC`).
2. **ABI:** **ECX=container**; no stack formals; plain **`RET`**.
3. **Semantics:** Ring-deque **pop_back bookkeeping**.  
   - If `size==0` → return.  
   - `size--`.  
   - If `size` becomes 0 → `begin=0`.  
   - **No** element dtor, **no** page free (leaf).
4. **Layout:** `+0x0c` begin, `+0x10` size (GuardedVector family).
5. **Classification:** leaf — no callees.
6. **Callers (5):** SEH catch sites `Catch@0043cd81`, `Catch@0043d278`, `Catch@0043e305`, `Catch@0044e470`, `Catch@00544508` (sites `0043cd92`, `0043d285`, `0043e312`, `0044e482`, `00544515`). Matches W29-A InsertN SEH “pop_back” naming.
7. **Name:** `GuardedVector_PopBack` (Ghidra `FUN_0043df70`; **Inferred** structural). Polarity twin of `FUN_0040d980` pop_front bookkeeping.
8. **Decompile ≡ bytes** for full body (live 2026-07-29 ≡ raw 2026-07-23).  
   Full hex: `8b411085c0740f83c0ff8941107507c7410c00000000c3`

### Gaps

- Product/PDB class English (cosmetic).  
- Runtime / bit-exact under multi-insert unwind.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0043df70_GuardedVector_PopBack.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0043df70_GuardedVector_PopBack.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043df70_FUN_0043df70.md` |
| Annotated | `docs/reconstruction/raw/aa_0043df70_FUN_0043df70.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_PopBack.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043df70.cpp` |
| Function | `docs/reconstruction/functions/aa_0043df70_FUN_0043df70.md` |
| Function named | `docs/reconstruction/functions/aa_0043df70_GuardedVector_PopBack.md` |
| Scratch | `docs/reconstruction/tmp/a_0043df70.md` |

---

## VA `0x0075dae0` — sealed facts

1. **Body:** `0x0075dae0`–`0x0075db93` (**180 B** / `0xB4`; pad `CC`).
2. **ABI:** **ECX=owner**; no stack formals; SEH (`LAB_009afe4b`); epilogue **`ADD ESP,0x20; RET`**.
3. **Semantics:** Clear owned-pointer GuardedVector at **`owner+0x28`**:  
   - Zero stack-local header (`+04/+08/+0c/+10`).  
   - `ESI=&local`, `EDI=owner+0x28` → `GuardedVector_ClearAndSwap` (steal field into local under optional CS).  
   - For `idx` in `[begin, begin+size)`: page=`idx>>2`, sub=`idx&3`, capacity wrap; if element non-null → **`vtable[0](elem, 1)`** scalar deleting dtor.  
   - `ESI=&local` → `FUN_0040d9c0` free pages + map.
4. **Layout:** owner `+0x28` = GuardedVector header (family `+04` pages, `+08` cap, `+0c` begin, `+10` size; lockable form may host CS at header+0x14 / flag+0x2c).
5. **Classification:** worker — callees `FUN_0043c660` / ClearAndSwap, `FUN_0040d9c0`, indirect vtable dtor.
6. **Callers:** **0** code xrefs in Ghidra (reachability open).
7. **Name:** `Owner_ClearDestroyGuardedPtrDequeAt28` (Ghidra `FUN_0075dae0`; **Inferred** structural). Sole sealed consumer of W29-A ClearAndSwap.
8. **Decompile ≠ bytes** on loop/this — **bytes authoritative**.  
   Full hex: see raw append (180 B).

### Gaps

- Owner product/PDB class and field English.  
- Zero code xrefs (vtable/data miss vs dead).  
- Element static type beyond owned vobject.  
- Runtime under CS.  
- Nested `FUN_0040d9c0` product-name residual (W18-M).

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0075dae0_Owner_ClearDestroyGuardedPtrDequeAt28.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0075dae0_Owner_ClearDestroyGuardedPtrDequeAt28.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0075dae0_FUN_0075dae0.md` |
| Annotated | `docs/reconstruction/raw/aa_0075dae0_FUN_0075dae0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Owner_ClearDestroyGuardedPtrDequeAt28.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0075dae0.cpp` |
| Function | `docs/reconstruction/functions/aa_0075dae0_FUN_0075dae0.md` |
| Function named | `docs/reconstruction/functions/aa_0075dae0_Owner_ClearDestroyGuardedPtrDequeAt28.md` |
| Scratch | `docs/reconstruction/tmp/a_0075dae0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0043df70` | Insert/construct SEH undo and shrink paths must use **ECX=container** pop_back bookkeeping only (`size--`, empty→`begin=0`). Do **not** destroy here — pair with separate dtor when needed. Closes W29-A InsertN residual naming of pop_back cleanup. |
| `0075dae0` | Owner field clear: **steal** via ClearAndSwap (ESI/EDI), **scalar-delete** each owned pointer in ring order, **then** free page map (`FUN_0040d9c0`). Do not trust Ghidra decompile. Do not invent linear `vector::clear` without page map + steal. Closes W29-A ClearAndSwap “parent ownership” residual. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers/callees/xrefs). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` structural names only (`GuardedVector_*` family; owner clear naming structural).  
- Avoided bare `undefined4` in clean (used `uint32_t` / explicit header structs).  
- For `0075dae0`, bytes override broken decompiler loop text.

