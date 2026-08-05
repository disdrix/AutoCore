# Dual A/B report — W30-A OWN `aa_0043d990` + `aa_0043ea60`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W30-A  
**Scope:** VAs `0x0043d990`, `0x0043ea60` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `read_memory` + callers/callees. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave30_partition_map.md`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0043d990` GuardedVector_GrowBlockMap_Thiscall | **accept** — ECX thiscall + `begin>>2` + geometric grow + post-delete commit sealed (340 B) |
| `aa_0043ea60` GuardedVector_GrowBlockMap_Stride2 | **accept** — EBX this + `begin>>1` + same grow/rebalance/commit sealed (333 B) |

---

## VA `0x0043d990` — sealed facts

1. **Body:** `0x0043d990`–`0x0043dae3` (**340 B** / `0x154`; pad `CC` then next unit).
2. **ABI:** **ECX=container** (`MOV EBX,ECX`); stack **`min_grow`**; **`RET 0x4`**. True thiscall entry (unlike EBX-entry twin `0x0043c9b0`).
3. **Semantics:** Grow circular **block-pointer map**:
   - Overflow: `0x0FFFFFFF - cap < min_grow` → `FUN_00436860` (`"deque<T> too long"`).
   - Geometric: `min_grow = max(request, max(cap/2, 8))` when safe.
   - `begin_blk = begin >> 2`; `operator_new((cap+grow)*4)`; memmove rebalance + zero new slots.
   - Optional `operator_delete(old)`; then **`capacity += grow`**, **`slots = neu`** (bytes; decompiler noreturn plate **wrong**).
4. **Layout:** `+0x04` slots, `+0x08` capacity, `+0x0c` begin, `+0x10` size (untouched).
5. **Classification:** worker — callees throw / new / memmove / delete.
6. **Callers (2):** `FUN_0043d670`, `FUN_0043e3d0` — both pass **`1`** on map-full gate.
7. **Name:** `GuardedVector_GrowBlockMap_Thiscall` (Ghidra `FUN_0043d990`; **Inferred** structural; twin of W28-B `GuardedVector_GrowBlockMap`).
8. **Decompile ≡ bytes** for growth CF; **bytes win** on commit tail. Full hex: raw W30-A append.

### Gaps

- Product/PDB English.  
- Parent push units unowned.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0043d990_GuardedVector_GrowBlockMap_Thiscall.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0043d990_GuardedVector_GrowBlockMap_Thiscall.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043d990_FUN_0043d990.md` |
| Annotated | `docs/reconstruction/raw/aa_0043d990_FUN_0043d990.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_GrowBlockMap_Thiscall.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043d990.cpp` |
| Function | `docs/reconstruction/functions/aa_0043d990_FUN_0043d990.md` |
| Function named | `docs/reconstruction/functions/aa_0043d990_GuardedVector_GrowBlockMap_Thiscall.md` |

---

## VA `0x0043ea60` — sealed facts

1. **Body:** `0x0043ea60`–`0x0043ebac` (**333 B** / `0x14D`; pad `CC` then next unit).
2. **ABI:** **EBX=container** (entry `MOV EAX,[EBX+8]`); stack **`min_grow`**; **`RET 0x4`**. Not thiscall.
3. **Semantics:** Same grow/rebalance/zero/commit family, but **`begin_blk = begin >> 1`** (stride-2 pages). Overflow / geometric policy identical (`0x0FFFFFFF`, max(cap/2, 8)).
4. **Layout:** same `+0x04/+0x08/+0x0c/+0x10` header; size untouched.
5. **Classification:** worker — same callee set.
6. **Callers (2):** `FUN_0043e970`, `FUN_0043e9e0` — pass **`1`**; gates use `&1` / `>>1`.
7. **Name:** `GuardedVector_GrowBlockMap_Stride2` (Ghidra `FUN_0043ea60`; **Inferred** structural).
8. **Decompile ≡ bytes** for growth CF; **bytes win** on commit tail. Full hex: raw W30-A append.

### Gaps

- Product/PDB English; element POD width residual (parents `new(0x10)` + `>>1`).  
- Parent push units unowned.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0043ea60_GuardedVector_GrowBlockMap_Stride2.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0043ea60_GuardedVector_GrowBlockMap_Stride2.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043ea60_FUN_0043ea60.md` |
| Annotated | `docs/reconstruction/raw/aa_0043ea60_FUN_0043ea60.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_GrowBlockMap_Stride2.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043ea60.cpp` |
| Function | `docs/reconstruction/functions/aa_0043ea60_FUN_0043ea60.md` |
| Function named | `docs/reconstruction/functions/aa_0043ea60_GuardedVector_GrowBlockMap_Stride2.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0043d990` | Closes nested grow residual for `0043d670` / `0043e3d0` family: **thiscall**, `begin>>2`, commit **always** after optional delete. Same algorithm as W28-B `GuardedVector_GrowBlockMap` (EBX); do not mix ABIs. |
| `0043ea60` | Stride-2 map grow for pair/8-byte-style ring: **EBX this**, `begin>>1`. Do not reuse `>>2` helpers without adjusting page math. |

Shared: both fix decompiler **false noreturn** on `operator_delete` — ports must always publish new capacity/slots after free.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + callers/callees. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` structural names only (`GuardedVector_*` family from parent duals W26–W29 / W28-B GrowBlockMap).  
- Avoided bare `undefined4` in clean (used `uint32_t` / explicit header structs).
