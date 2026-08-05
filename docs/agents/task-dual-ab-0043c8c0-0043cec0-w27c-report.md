# Dual A/B report — W27-C OWN `aa_0043c8c0` + `aa_0043cec0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W27-C  
**Scope:** VAs `0x0043c8c0`, `0x0043cec0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` (+ callers/callees). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave27_partition_map.md`

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0043c8c0` GuardedVector_EraseRange | **accept-with-gaps** — EAX/stdcall ABI + shorter-side erase CF + begin wrap/`size` sealed; nested move free residual |
| `aa_0043cec0` GuardedVector_GrowAssignRange | **accept** — thin 7→8-arg trampoline to `FUN_0043cf40` fully sealed (body 48 B) |

---

## VA `0x0043c8c0` — sealed facts

1. **Body:** `0x0043c8c0`–`0x0043c9af` (**240 B** / `0xF0`; next `FUN_0043c9b0`).
2. **ABI:** **EAX=container**; stdcall **5** stack formals; frame `SUB/ADD ESP,0x10`; **`RET 0x14`**.
3. **Semantics:** Erase absolute range `[erase_from, erase_to)` in ring header.  
   - `prefix = erase_from - begin`; `suffix = (size+begin) - erase_to`.  
   - If `prefix < suffix` → `FUN_0043d300` then advance `begin` (wrap when `begin >= capacity*4`) and shrink `size`.  
   - Else → `FUN_0043d390` then shrink `size` only (`begin=0` when emptied).  
   - Return out-iterator `{container, begin+prefix}` via `param_1`.
4. **Layout:** `+0x04` slots, `+0x08` capacity, `+0x0c` begin, `+0x10` size (same family as `GuardedVector_CopyAssign`).
5. **Classification:** worker — callees `FUN_0043d300`, `FUN_0043d390`.
6. **Callers (3):** `FUN_0043c550` (erase match), `FUN_0043c730` / `GuardedVector_CopyAssign` (fit), `FUN_0043c7e0` (shrink).
7. **Name:** `GuardedVector_EraseRange` (Ghidra `FUN_0043c8c0`; **Inferred** structural).
8. **Decompile ≡ bytes** for CF (live 2026-07-29 ≡ raw 2026-07-23).

### Gaps

- Product/PDB class English.  
- Nested element-move packing in unowned `0043d300` / `0043d390`.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0043c8c0_GuardedVector_EraseRange.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0043c8c0_GuardedVector_EraseRange.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043c8c0_FUN_0043c8c0.md` |
| Annotated | `docs/reconstruction/raw/aa_0043c8c0_FUN_0043c8c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_EraseRange.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043c8c0.cpp` |
| Function | `docs/reconstruction/functions/aa_0043c8c0_FUN_0043c8c0.md` |
| Function named | `docs/reconstruction/functions/aa_0043c8c0_GuardedVector_EraseRange.md` |
| Scratch | `docs/reconstruction/tmp/a_0043c8c0.md` |

---

## VA `0x0043cec0` — sealed facts

1. **Body:** `0x0043cec0`–`0x0043ceef` (**48 B** / `0x30`; next `FUN_0043cef0`).
2. **ABI:** stdcall **7** stack formals; **`RET 0x1c`**; no register this contract.
3. **Semantics:** Thin trampoline — `FUN_0043cf40(p1,p2,p3,p4,p5,p6,p7,p1)` (8th = `param_1` dest self-ref).
4. **Classification:** worker / trampoline — sole callee `FUN_0043cf40`.
5. **Callers (1):** `FUN_0043c730` / `GuardedVector_CopyAssign` grow path only (xref `0x0043c7c5`).
6. **Name:** `GuardedVector_GrowAssignRange` (Ghidra `FUN_0043cec0`; **Inferred** structural).
7. **Decompile ≡ bytes** for full body (live 2026-07-29 ≡ raw 2026-07-23).  
   Full hex: `8b4424048b4c241c8b542418508b442418518b4c2418528b542418508b442418518b4c2418525051e853000000c21c00`

### Gaps

- Nested grow/construct/destroy inside unowned `FUN_0043cf40` (not this body).  
- Product English.  
- Runtime golden for full assign-grow path.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0043cec0_GuardedVector_GrowAssignRange.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0043cec0_GuardedVector_GrowAssignRange.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043cec0_FUN_0043cec0.md` |
| Annotated | `docs/reconstruction/raw/aa_0043cec0_FUN_0043cec0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_GrowAssignRange.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043cec0.cpp` |
| Function | `docs/reconstruction/functions/aa_0043cec0_FUN_0043cec0.md` |
| Function named | `docs/reconstruction/functions/aa_0043cec0_GuardedVector_GrowAssignRange.md` |
| Scratch | `docs/reconstruction/tmp/a_0043cec0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0043c8c0` | Assign-fit / shrink / erase-match must use shorter-side ring erase: wrap `begin` at `capacity*4`, commit `size`, return iterator at `begin+prefix`. Do not invent plain `memmove` erase without the reverse vs forward branch. Closes open fit residual from W26-G `GuardedVector_CopyAssign`. |
| `0043cec0` | Grow path may inline this trampoline; worker remains `FUN_0043cf40` with **8** args (dest repeated). Closes open grow-entry residual from W26-G. Nested grow free still residual. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers/callees). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` structural names only (`GuardedVector_*` family from parent dual).  
- Avoided bare `undefined4` in clean (used `uint32_t` / explicit header structs).
