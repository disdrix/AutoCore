# Dual A/B report — W28-B OWN `aa_0043cf40` + `aa_0043c9b0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W28-B  
**Scope:** VAs `0x0043cf40`, `0x0043c9b0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `read_memory` + `analyze_function_complete` (+ callers/callees). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** wave28.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0043cf40` GuardedVector_GrowAssignRangeCore | **accept-with-gaps** — 8-arg stdcall (`RET 0x20`) + 4-way shorter-side grow-assign CF sealed; nested `0043d300`/`0043d390` free residual |
| `aa_0043c9b0` GuardedVector_GrowBlockMap | **accept** — EBX ABI + geometric map grow + rebalance + post-delete commit sealed (full 334 B) |

---

## VA `0x0043cf40` — sealed facts

1. **Body:** `0x0043cf40`–`0x0043d2f6` (**951 B** / `0x3B7`).
2. **ABI:** stdcall **8** stack formals; SEH frame (`LAB_009be0b0`); **`RET 0x20`** @ `0x0043d2f4`. Decompiler lists 7 used formals; trampoline supplies 8th=`param_1`.
3. **Semantics:** Grow-assign **core** for dest shorter than needed source range:
   - `prefix = bound - begin`; `suffix = size - prefix`; `src_len = src_end - src_begin`.
   - If `prefix < suffix`: front-side path — excess construct via `FUN_0043ce10` when `prefix < src_len`, else reverse residual walks + `FUN_0043d390` internal shift.
   - Else: back-side path — excess construct via `FUN_0043c830` when `suffix < src_len`, else residual walks + `FUN_0043d300`.
   - Common final: `FUN_0043d390` source-range → dest insert.
4. **Layout (dest):** `+0x04` block map, `+0x08` capacity, `+0x0c` begin, `+0x10` size (same family as erase/copy-assign).
5. **Classification:** worker — callees `FUN_0043ce10`, `FUN_0043c830`, `FUN_0043d300`, `FUN_0043d390`.
6. **Callers (1):** only `FUN_0043cec0` / `GuardedVector_GrowAssignRange` @ `0x0043cee8`.
7. **Name:** `GuardedVector_GrowAssignRangeCore` (Ghidra `FUN_0043cf40`; **Inferred** structural; body of W27-C trampoline).
8. **Decompile ≡ raw** for CF (live 2026-07-29 ≡ raw 2026-07-23).

### Gaps

- Product/PDB class English.  
- Nested move free packing in unowned `0043d300` / `0043d390`.  
- Full English labels for p2/p6/p8.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0043cf40_GuardedVector_GrowAssignRangeCore.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0043cf40_GuardedVector_GrowAssignRangeCore.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043cf40_FUN_0043cf40.md` |
| Annotated | `docs/reconstruction/raw/aa_0043cf40_FUN_0043cf40.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_GrowAssignRangeCore.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043cf40.cpp` |
| Function | `docs/reconstruction/functions/aa_0043cf40_FUN_0043cf40.md` |
| Function named | `docs/reconstruction/functions/aa_0043cf40_GuardedVector_GrowAssignRangeCore.md` |
| Scratch | `docs/reconstruction/tmp/a_0043cf40.md` |

---

## VA `0x0043c9b0` — sealed facts

1. **Body:** `0x0043c9b0`–`0x0043cafd` (**334 B** / `0x14E`).
2. **ABI:** **EBX=container**; stdcall **1** stack formal (`min_grow`); frame `SUB ESP,0xC`; **`RET 0x4`**.
3. **Semantics:** Grow deque-style **block-pointer map**:
   - Overflow if `0x0FFFFFFF - capacity < min_grow` → `FUN_00436860` (`"deque<T> too long"`).
   - Geometric: `min_grow = max(min_grow, max(capacity/2, 8))` when no overflow.
   - `operator_new((cap+grow)*4)`; `memmove` rebalance of existing map entries around `begin>>2`; zero new/unused slots.
   - If old map non-null → `operator_delete` then **fall through** (not noreturn).
   - Commit: `capacity += grow`; `slots = new_map`.
4. **Layout:** `+0x04` slots, `+0x08` capacity, `+0x0c` begin (same family).
5. **Classification:** worker — callees CRT + `FUN_00436860`.
6. **Callers (2):** `FUN_0043c830` @ `0x0043c84d`, `FUN_0043ce10` @ `0x0043ce2a` (push_back / push_front grow-by-1).
7. **Name:** `GuardedVector_GrowBlockMap` (Ghidra `FUN_0043c9b0`; **Inferred** structural; throw string is deque).
8. **Decompile ≡ raw** for growth/rebalance CF; **bytes correct** decompiler noreturn mis-model on delete path (live 2026-07-29).

### Gaps

- Product/PDB English (`GuardedVector_*` family; retail message `deque<T>`).  
- Runtime / bit-exact golden for both rebalance arms.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0043c9b0_GuardedVector_GrowBlockMap.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0043c9b0_GuardedVector_GrowBlockMap.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043c9b0_FUN_0043c9b0.md` |
| Annotated | `docs/reconstruction/raw/aa_0043c9b0_FUN_0043c9b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_GrowBlockMap.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043c9b0.cpp` |
| Function | `docs/reconstruction/functions/aa_0043c9b0_FUN_0043c9b0.md` |
| Function named | `docs/reconstruction/functions/aa_0043c9b0_GuardedVector_GrowBlockMap.md` |
| Scratch | `docs/reconstruction/tmp/a_0043c9b0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0043cf40` | Grow-assign must use this core (or equivalent 4-way shorter-side policy) after the thin `GuardedVector_GrowAssignRange` trampoline. Do not invent flat `memcpy` grow-assign. Closes nested grow free residual left open by W27-C. Nested `0043d300`/`0043d390` still residual. |
| `0043c9b0` | Push_front / push_back capacity miss must grow the **block map** geometrically (`max(req, max(cap/2, 8))`), rebalance pointers, zero free map slots, then commit. Overflow → length_error. Do not vector-realloc element storage. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers/callees). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` structural names only (`GuardedVector_*` family from parent duals; throw string notes deque).  
- Avoided bare `undefined4` in clean (used `uint32_t` / explicit header structs).
