# Dual A/B report — W32-G OWN `aa_0043e4b0` + `aa_0044e1c0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W32-G  
**Scope:** VAs `0x0043e4b0`, `0x0044e1c0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` / `batch_decompile` + `read_memory` + `get_function_by_address` + `analyze_function_complete` (+ callers/callees/xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave32_partition_map.md` (W32-G).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0043e4b0` GuardedVector_PushBackLocked_Thiscall | **accept** — EDI/stack ABI + optional CS + nested PushBack_Thiscall sealed (94 B); product residual only |
| `aa_0044e1c0` GuardedVector_InsertRange | **accept-with-gaps** — RET 0x18 / 6-arg ABI + 4-arm shorter-side CF + thiscall push polarity sealed (815 B); nested move/assign free residual |

---

## VA `0x0043e4b0` — sealed facts

1. **Body:** `0x0043e4b0`–`0x0043e50d` (**94 B** / `0x5E`; pad `CC CC` then next).
2. **ABI:** **EDI=container**; stdcall **1** stack formal (`const uint32_t* value`); **`RET 0x4`**. Decompiler omits EDI (`unaff_EDI`).
3. **Semantics:** Optional CS wrapper around `GuardedVector_PushBack_Thiscall` (`FUN_0043d670`).  
   - If `container+0x2c != 0` → `EnterCriticalSection(container+0x14)`.  
   - `ECX = EDI`; call PushBack_Thiscall(value*).  
   - If locked → LeaveCS. SEH `LAB_009be0c8` (state −1→0 around push).
4. **Layout:** CS `+0x14`, lock-enable `char +0x2c` (family: PushBackLocked / AssignTo / Resize wrappers).
5. **Classification:** worker — callees EnterCS, `FUN_0043d670`, LeaveCS.
6. **Callers (1):** `FUN_00971640` @ `0x009716cd` (AssPreloader enqueue residual path).
7. **Name:** `GuardedVector_PushBackLocked_Thiscall` (Ghidra `FUN_0043e4b0`; **Inferred** structural; CS twin of W30-D `GuardedVector_PushBackLocked` over W31-I thiscall push_back).
8. **Decompile ≡ bytes** for full body (live 2026-07-29 ≡ raw 2026-07-23).  
   Full hex: `6aff68c8e09b0064a100000000506489250000000051807f2c00568d771489742404740756ff15bc619c008b442418508bcfc744241400000000e881f1ffff807e1800740756ff15b8619c008b4c24085e64890d0000000083c410c20400`

### Gaps

- Product/PDB class English.  
- Runtime / bit-exact under contended CS.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0043e4b0_GuardedVector_PushBackLocked_Thiscall.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0043e4b0_GuardedVector_PushBackLocked_Thiscall.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043e4b0_FUN_0043e4b0.md` |
| Annotated | `docs/reconstruction/raw/aa_0043e4b0_FUN_0043e4b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_PushBackLocked_Thiscall.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043e4b0.cpp` |
| Function | `docs/reconstruction/functions/aa_0043e4b0_FUN_0043e4b0.md` |
| Function named | `docs/reconstruction/functions/aa_0043e4b0_GuardedVector_PushBackLocked_Thiscall.md` |
| Scratch | `docs/reconstruction/tmp/a_0043e4b0.md` |

---

## VA `0x0044e1c0` — sealed facts

1. **Body:** `0x0044e1c0`–`0x0044e4ee` (**815 B** / `0x32F`; pad `CC` after last `RET 0x18`).
2. **ABI:** stdcall **6** stack formals; **`RET 0x18`**. Decompiler lists 5 live formals; 6th confirmed by sole-caller push order + cleanup size.
3. **Semantics:** Range insert of `N = (last−first)>>2` dwords at absolute `insert_at`.  
   - `prefix = insert_at − begin`; `suffix = size − prefix`.  
   - Front-biased (`prefix < suffix`): grow via `GuardedVector_PushFront_Thiscall` (`0043e3d0`) ± `FUN_0043ec50`, then `FUN_0044e4f0` assign.  
   - Back-biased: grow via `GuardedVector_PushBack_Thiscall` (`0043d670`) ± `FUN_0043ebb0`, then `FUN_0044e4f0` assign.  
   - Page map: `page = idx>>2`; if `capacity <= page` → `page −= capacity`; sub = `idx&3`.
4. **Layout:** `+0x04` pages, `+0x08` capacity, `+0x0c` begin, `+0x10` size (family).
5. **Classification:** worker — callees `0043e3d0`, `0043d670`, `0043ec50`, `0043ebb0`, `0044e4f0`.
6. **Callers (1):** `FUN_00971700` @ `0x0097176b` — six pushes then call (local ring + external `[first,last)` from host offsets `+0x50`/`+0x54`).
7. **Name:** `GuardedVector_InsertRange` (Ghidra `FUN_0044e1c0`; **Inferred** structural; range twin of W29-A `GuardedVector_InsertN` with thiscall push family).
8. **Decompile ≡ bytes** for success CF tree (live 2026-07-29 ≡ raw 2026-07-23). Nested push call displacements sealed. Full hex: raw W32-G append (815 B).

### Gaps

- Product/PDB class English.  
- Nested construct free inside unowned `FUN_0044e4f0` / `FUN_0043ec50` / `FUN_0043ebb0`.  
- Exact product role of 6th stack formal (ABI present; success CF decompiler-unused).  
- SEH throw/grow islands present in bytes, not re-owned.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0044e1c0_GuardedVector_InsertRange.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0044e1c0_GuardedVector_InsertRange.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0044e1c0_FUN_0044e1c0.md` |
| Annotated | `docs/reconstruction/raw/aa_0044e1c0_FUN_0044e1c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_InsertRange.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0044e1c0.cpp` |
| Function | `docs/reconstruction/functions/aa_0044e1c0_FUN_0044e1c0.md` |
| Function named | `docs/reconstruction/functions/aa_0044e1c0_GuardedVector_InsertRange.md` |
| Scratch | `docs/reconstruction/tmp/a_0044e1c0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0043e4b0` | Locked push_back for GuardedVector (thiscall nest): **EDI=container**, stack `value*`, **RET 4**. Optional CS at `+0x14` gated by `+0x2c`, then unlocked `GuardedVector_PushBack_Thiscall` (W31-I ECX contract). Do **not** substitute W30-D `GuardedVector_PushBackLocked` (EAX/`0043c830` nest) or invent entry thiscall. |
| `0044e1c0` | Range insert residual: **stdcall 6 args**, **RET 0x18**. Shorter-side front/back growth via thiscall PushFront/PushBack — not flat `vector::insert`, not W29-A InsertN (N×fill / EAX push). Nested ring-move/assign helpers remain free until owned. |

Shared: both close parent residuals that name W31-I thiscall push units as callees (`0043e4b0` as sole locked wrapper; `0044e1c0` as multi-site push consumer for range insert). Nested grow free already sealed at W31-I; only product English / nested move helpers / runtime remain open on the insert side.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` structural names only (`GuardedVector_*` family from parent duals W29–W31 / W30-D PushBackLocked / W31-I PushBack_Thiscall / PushFront_Thiscall).  
- Avoided bare `undefined4` in clean (used `uint32_t` / explicit header structs).
