# Dual A/B report — W31-I OWN `aa_0043d670` + `aa_0043e3d0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W31-I  
**Scope:** VAs `0x0043d670`, `0x0043e3d0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` / `batch_decompile` + `read_memory` + callers/callees. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** wave31.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0043d670` GuardedVector_PushBack_Thiscall | **accept** — ECX thiscall + end write/page wrap/size++ sealed (119 B); product residual only |
| `aa_0043e3d0` GuardedVector_PushFront_Thiscall | **accept** — ECX thiscall + begin wrap/page map/size++/begin commit sealed (120 B); product residual only |

---

## VA `0x0043d670` — sealed facts

1. **Body:** `0x0043d670`–`0x0043d6e6` (**119 B** / `0x77`; pad `CC` after last RET).
2. **ABI:** **ECX=container** (`MOV ESI,ECX`); stack **`const uint32_t* value`**; **`RET 0x4`**. True thiscall entry.
3. **Semantics:** Ring-deque **push_back** of one dword.  
   - If `((begin+size) & 3)==0` and `capacity <= (size+4)>>2` → `GuardedVector_GrowBlockMap_Thiscall(1)` (`MOV ECX,ESI`).  
   - `abs = begin + size`; `page = abs>>2`; if `capacity <= page` → `page -= capacity`.  
   - Lazy `operator_new(0x10)` if page null; `FUN_0043d420(slot, value*)`; `size++` only (**begin unchanged**).
4. **Layout:** `+0x04` pages, `+0x08` capacity, `+0x0c` begin, `+0x10` size (family).
5. **Classification:** worker — callees `FUN_0043d990`, `operator_new`, `FUN_0043d420`.
6. **Callers (16):** `FUN_0043e080`, `FUN_0043e4b0`, `FUN_0044e1c0`, `FUN_004b88e0`, `FUN_004ec430`, `FUN_004ec7b0`, `FUN_004f1c70`, `FUN_004f1e20`, `FUN_004f1ff0`, `FUN_00542790`, `FUN_005441d0`, `FUN_00556b10`, `FUN_00971280`, `FUN_009717a0`, `FUN_00971820`, `FUN_00972140`.
7. **Name:** `GuardedVector_PushBack_Thiscall` (Ghidra `FUN_0043d670`; **Inferred** structural; twin of W29-B EAX `GuardedVector_PushBack`).
8. **Decompile ≡ bytes** for full CF (live 2026-07-29 ≡ raw 2026-07-23).  
   Full hex: `53568bf18b46108b4e0c03c8f6c10357751483c004c1e80239460877096a018bcee8fa0200008b7e0c037e108b46088bdfc1eb023bc377022bd88b5604833c9a0075106a10e8d8c104008b4e0483c4048904998b46048b5424108b0c985283e7038d14b952e846fdffff8346100183c4085f5e5bc20400`

### Gaps

- Product/PDB class English.  
- Element type beyond dword POD.  
- Runtime / bit-exact.  
- Null-`operator_new` still advances size (bytes).

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0043d670_GuardedVector_PushBack_Thiscall.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0043d670_GuardedVector_PushBack_Thiscall.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043d670_FUN_0043d670.md` |
| Annotated | `docs/reconstruction/raw/aa_0043d670_FUN_0043d670.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_PushBack_Thiscall.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043d670.cpp` |
| Function | `docs/reconstruction/functions/aa_0043d670_FUN_0043d670.md` |
| Function named | `docs/reconstruction/functions/aa_0043d670_GuardedVector_PushBack_Thiscall.md` |

---

## VA `0x0043e3d0` — sealed facts

1. **Body:** `0x0043e3d0`–`0x0043e447` (**120 B** / `0x78`; pad `CC` after last RET).
2. **ABI:** **ECX=container** (`MOV ESI,ECX`); stack **`const uint32_t* value`**; **`RET 0x4`**. True thiscall entry.
3. **Semantics:** Ring-deque **push_front** of one dword.  
   - If `(begin & 3)==0` and `capacity <= (size+4)>>2` → `GuardedVector_GrowBlockMap_Thiscall(1)` (ECX preserved; no reload).  
   - If `begin==0` → treat as `capacity*4`.  
   - `new_begin = begin - 1`; map `page = new_begin>>2`, sub `new_begin&3`.  
   - Lazy `operator_new(0x10)` if page null; `FUN_0043d420(slot, value*)`; `size++`; `begin = new_begin`.
4. **Layout:** same family as PushBack_Thiscall / W29-B push pair / EraseRange.
5. **Classification:** worker — callees `FUN_0043d990`, `operator_new`, `FUN_0043d420`.
6. **Callers (5):** `FUN_0043e080`, `FUN_0044e1c0`, `FUN_004f2540`, `FUN_005441d0`, `FUN_00744360`.
7. **Name:** `GuardedVector_PushFront_Thiscall` (Ghidra `FUN_0043e3d0`; **Inferred** structural; twin of W29-B EAX `GuardedVector_PushFront`).
8. **Decompile ≡ bytes** for full CF (live 2026-07-29 ≡ raw 2026-07-23).  
   Full hex: `53568bf1f6460c035775158b461083c004c1e80239460877076a01e8a0f5ffff8b7e0c85ff75078b7e0803ff03ff8b4e0483ef018bdfc1eb02833c990075106a10e87cb404008b560483c40489049a8b4424108b4e04508b04998bd783e2038d0c9051e8e8efffff8346100183c408897e0c5f5e5bc20400`

### Gaps

- Product/PDB class English.  
- Element type beyond dword POD.  
- Runtime / bit-exact.  
- Null-`operator_new` still advances size/begin (bytes).

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0043e3d0_GuardedVector_PushFront_Thiscall.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0043e3d0_GuardedVector_PushFront_Thiscall.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043e3d0_FUN_0043e3d0.md` |
| Annotated | `docs/reconstruction/raw/aa_0043e3d0_FUN_0043e3d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_PushFront_Thiscall.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043e3d0.cpp` |
| Function | `docs/reconstruction/functions/aa_0043e3d0_FUN_0043e3d0.md` |
| Function named | `docs/reconstruction/functions/aa_0043e3d0_GuardedVector_PushFront_Thiscall.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0043d670` | Thiscall push_back for GuardedVector: **ECX=container**, stack `value*`, **RET 4**. Map grow via W30-A `GuardedVector_GrowBlockMap_Thiscall` (not EBX `0043c9b0`). Write at absolute `begin+size` with page wrap; **begin unchanged**. Do not mix with EAX W29-B `GuardedVector_PushBack` sites. Assign goes through `FUN_0043d420` (null-checked dword copy). |
| `0043e3d0` | Thiscall push_front: same ECX contract; grow when begin page-aligned; wrap `begin==0` through `capacity*4`; commit `begin` after store. Pair with `0043d670` for thiscall ring polarity. Do not reuse EAX W29-B `GuardedVector_PushFront` ABI. |

Shared: both close the parent-push residual named by W30-A grow seal (`0043d670` / `0043e3d0` callers of GrowBlockMap_Thiscall). Nested grow free is sealed; only product English / runtime remain open.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + callers/callees. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` structural names only (`GuardedVector_*` family from parent duals W28–W30 / W29-B PushFront/PushBack / W30-A GrowBlockMap_Thiscall).  
- Avoided bare `undefined4` in clean (used `uint32_t` / explicit header structs).
