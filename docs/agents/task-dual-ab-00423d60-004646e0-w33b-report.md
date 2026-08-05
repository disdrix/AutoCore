# Dual A/B report — W33-B OWN `aa_00423d60` + `aa_004646e0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W33-B  
**Scope:** VAs `0x00423d60`, `0x004646e0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` + xrefs + callee decompile. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave33_partition_map.md` (W33-B).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00423d60` CircularSentinel_Alloc0x28_Inferred | **accept-with-gaps** — size/links/EAX return/26 B sealed; product payload English open |
| `aa_004646e0` PtrVecShell_InitFill_Inferred | **accept-with-gaps** — stdcall 3-arg/RET12/count*4/fill/max-size sealed; shell+0 + non-Ass caller product open |

---

## VA `0x00423d60` — sealed facts

1. **Body:** `0x00423d60`–`0x00423d79` (**26 B** / `0x1A`; pad `CC` then next @ `0x00423d80`).
2. **ABI:** no formals; bare **`C3`**; returns **node* in EAX** (decompiler `void` wrong).
3. **Semantics:**
   - `operator_new(0x28)`.
   - If non-null: `*node = node` (next).
   - `*(node+4) = node` (prev) — MSVC `lea/test` gate on `node+4`.
4. **Classification:** wrapper / factory.
5. **Callers (3):** `FUN_00423cf0` @ `0x00423d0b`; `FUN_0044a0d0` @ `0x0044a0eb`; `FUN_00469db0` @ `0x00469dcb`.
6. **Callees:** `operator_new`.
7. **Name:** `CircularSentinel_Alloc0x28_Inferred` (Ghidra `FUN_00423d60`; **Inferred**). **Reject** scaffold `Named_CalleeOf_*`.
8. **Family:** same CF as `StdList_AllocSentinel_0xC` (`0x004933f0`, 26 B) with size **0x28**; non-SEH (contrast `0x0040fb90`).
9. **Decompile ≡ bytes** for stores and bare RET; **bytes/callers win** on return type.

### Gaps

- Product English for remaining **0x20** payload bytes of the node.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00423d60_CircularSentinel_Alloc0x28_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00423d60_CircularSentinel_Alloc0x28_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00423d60_FUN_00423d60.md` |
| Annotated | `docs/reconstruction/raw/aa_00423d60_FUN_00423d60.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CircularSentinel_Alloc0x28_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00423d60.cpp` |
| Function | `docs/reconstruction/functions/aa_00423d60_FUN_00423d60.md` |
| Function named | `docs/reconstruction/functions/aa_00423d60_CircularSentinel_Alloc0x28_Inferred.md` |

---

## VA `0x004646e0` — sealed facts

1. **Body:** `0x004646e0`–`0x0046477e` (**159 B** / `0x9F`; main epilog **`C2 0C 00`** @ `0x0046476b`; pad `CC` @ `0x0046477f`).
2. **ABI:** **stdcall 3 formals**; **`RET 12`**. Decompiler 2-arg incomplete — **bytes win**.
   - `shell*` @ `[ebp+8]`
   - `count` @ `[ebp+0xc]` (element count)
   - `fill_src*` @ `[ebp+0x10]` (pointer to dword replicated)
3. **Semantics:**
   - Zero shell **`+0x04/+0x08/+0x0c`**; **`+0x00` unwritten**.
   - `count==0` → return after zeros.
   - `count > 0x3fffffff` → `FUN_004540b0` throws **`"vector<T> too long"`**.
   - Else: `operator_new(count*4)`; set begin/end_cap; **`FUN_00436ef0`** fills each slot with `*fill_src` (ECX=count, EDX=src, EAX=begin); set end = full.
4. **Classification:** worker.
5. **Callers (10):** includes Ass bag twins `FUN_00423cf0` / `FUN_00469db0` / `FUN_0044a0d0` (count **9** + sentinel fill); also `FUN_0043bdf0`, `FUN_00457ac0`, `FUN_00463bd0`, `FUN_0043fdf0`, `FUN_004438c0`, `FUN_00457b30`, `FUN_004642d0`.
6. **Callees:** `operator_new`, `FUN_004540b0`, `FUN_00436ef0`.
7. **Name:** `PtrVecShell_InitFill_Inferred` (Ghidra `FUN_004646e0`; **Inferred**). **Reject** scaffold `Named_CalleeOf_*`.
8. **SEH:** `LAB_009bd530`.
9. **Decompile ≡ bytes** for zero/alloc/end advance; **bytes win** on 3rd formal + RET 12 + fill source.

### Gaps

- Product meaning of unwritten **shell+0**.  
- Product English for non-Ass call sites.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004646e0_PtrVecShell_InitFill_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004646e0_PtrVecShell_InitFill_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004646e0_FUN_004646e0.md` |
| Annotated | `docs/reconstruction/raw/aa_004646e0_FUN_004646e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/PtrVecShell_InitFill_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004646e0.cpp` |
| Function | `docs/reconstruction/functions/aa_004646e0_FUN_004646e0.md` |
| Function named | `docs/reconstruction/functions/aa_004646e0_PtrVecShell_InitFill_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00423d60` | Port as **free factory**: `new(0x28)` + circular next/prev; return pointer. Pair with 0xC family if sharing list helpers. |
| `004646e0` | Port as **stdcall 3-arg** shell init (not cdecl 2-arg). Preserve count*4, fill-from-pointer, max-size throw, unwritten shell+0. Bag ctors use **n=9**. |
| Pair with | W32-D `AssResolverA_NestedHash_Ctor_Inferred`; W32-E `AssResolverCore_HeadBag_Ctor_Inferred`; unowned `FUN_00436ef0` / `FUN_004540b0` / `FUN_0044a0d0`. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers + callee decompile. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; structural `_Inferred` names only.  
- Avoided bare `undefined4` in clean (`uint32_t` / explicit structs).  
- Rejected scaffold `Named_CalleeOf_*` as product alias.
