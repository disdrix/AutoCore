# Dual A/B report — W31-J OWN `aa_0043e970` + `aa_0043e9e0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W31-J  
**Scope:** VAs `0x0043e970`, `0x0043e9e0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` / `batch_decompile` + `read_memory` + `get_function_by_address` + `analyze_function_complete` (+ callers/callees/xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave31_partition_map.md` (W31-J).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0043e970` GuardedVector_PushBack_Stride2_U32x2 | **accept** — EAX push_back + stride-2 grow/page + 8-byte store sealed (110 B) |
| `aa_0043e9e0` GuardedVector_PushBack_Stride2_U32U8 | **accept** — bit-twin of sibling; dword+byte store via `0043ecf0` sealed (110 B) |

---

## VA `0x0043e970` — sealed facts

1. **Body:** `0x0043e970`–`0x0043e9dd` (**110 B** / `0x6E`; pad `CC` then sibling push).
2. **ABI:** **EAX=container** (`MOV EBX,EAX`); stack **1** formal (`const PodU32x2* value`); **`RET 0x4`**. Not thiscall.
3. **Semantics:** Stride-2 ring **push_back**:
   - Grow when `((begin+size)&1)==0` && `capacity <= (size+2)>>1` → `FUN_0043ea60(1)` (`GuardedVector_GrowBlockMap_Stride2`, EBX this).
   - `page = (begin+size)>>1` with wrap subtract capacity; lazy `operator_new(0x10)` into `pages[page]`.
   - Slot `pages[page] + ((begin+size)&1)*8`; `FUN_0043ece0` null-safe copy of **two dwords**.
   - **`size++`**; **begin unchanged**.
4. **Layout:** `+0x04` pages, `+0x08` capacity, `+0x0c` begin, `+0x10` size.
5. **Classification:** worker — callees grow / new / Pod8 copy.
6. **Callers (2):** `FUN_00971280` @ `0x00971381`; `FUN_00972140` @ `0x00972322`.
7. **Name:** `GuardedVector_PushBack_Stride2_U32x2` (Ghidra `FUN_0043e970`; **Inferred** structural; family W29-B PushBack + W30-A GrowBlockMap_Stride2).
8. **Decompile ≡ raw CF**; **bytes win** on ABI, LEA slot math, stack formal. Full hex: raw W31-J append.

### Gaps

- Product/PDB English.  
- Runtime / bit-exact.  
- Nested free of grow / new (owned elsewhere).

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0043e970_GuardedVector_PushBack_Stride2_U32x2.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0043e970_GuardedVector_PushBack_Stride2_U32x2.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043e970_FUN_0043e970.md` |
| Annotated | `docs/reconstruction/raw/aa_0043e970_FUN_0043e970.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_PushBack_Stride2_U32x2.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043e970.cpp` |
| Function | `docs/reconstruction/functions/aa_0043e970_FUN_0043e970.md` |
| Function named | `docs/reconstruction/functions/aa_0043e970_GuardedVector_PushBack_Stride2_U32x2.md` |
| Scratch | `docs/reconstruction/tmp/a_0043e970.md` |

---

## VA `0x0043e9e0` — sealed facts

1. **Body:** `0x0043e9e0`–`0x0043ea4d` (**110 B** / `0x6E`; pad `CC` then `FUN_0043ea50`).
2. **ABI:** **EAX=container**; stack **1** formal (`const PodU32U8* value`); **`RET 0x4`**. Not thiscall.
3. **Semantics:** Bit-twin of `0043e970` for grow / page wrap / lazy alloc / LEA `*8` / `size++`. Sole behavioral delta: store helper **`FUN_0043ecf0`** copies **dword + byte** (null-safe). Slots remain 8 bytes; write width is 5.
4. **Layout:** same header offsets as sibling.
5. **Classification:** worker.
6. **Callers (2):** `FUN_0043e7f0` @ `0x0043e82a` (optional CS wrapper — not owned); `FUN_0075de80` @ `0x0075e046`.
7. **Name:** `GuardedVector_PushBack_Stride2_U32U8` (Ghidra `FUN_0043e9e0`; **Inferred** structural).
8. **Decompile ≡ raw CF**; **bytes win** on ABI/slot/store. Twin opcode stream differs only in three `E8` rel32 displacements. Full hex: raw W31-J append.

### Gaps

- Product/PDB element English; trailing 3 slot bytes unwritten.  
- Parent CS wrapper / high-VA caller free.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0043e9e0_GuardedVector_PushBack_Stride2_U32U8.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0043e9e0_GuardedVector_PushBack_Stride2_U32U8.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043e9e0_FUN_0043e9e0.md` |
| Annotated | `docs/reconstruction/raw/aa_0043e9e0_FUN_0043e9e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_PushBack_Stride2_U32U8.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043e9e0.cpp` |
| Function | `docs/reconstruction/functions/aa_0043e9e0_FUN_0043e9e0.md` |
| Function named | `docs/reconstruction/functions/aa_0043e9e0_GuardedVector_PushBack_Stride2_U32U8.md` |
| Scratch | `docs/reconstruction/tmp/a_0043e9e0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0043e970` | Stride-2 **push_back** for 8-byte POD: **EAX=container**, stack `value*`, **RET 4**. Grow via `GuardedVector_GrowBlockMap_Stride2` (EBX). Do **not** use dword PushBack (`>>2`/`&3`) or thiscall. |
| `0043e9e0` | Same ABI/map math; store is **u32+u8** via distinct helper. Do not unify store with U32x2 sibling. Locking is parent `0043e7f0`, not this body. |

Shared: both close W30-A parent residual (“push-style callers of GrowBlockMap_Stride2”). Null page base → store skipped, **size still increments** (matches null-check helpers).

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` structural names only (`GuardedVector_*` family from W28–W30 duals).  
- Avoided bare `undefined4` in clean (used `uint32_t` / explicit POD structs).
