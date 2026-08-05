# Dual A/B report — W33-K OWN `aa_0043e910` + `aa_0043ebb0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W33-K  
**Scope:** VAs `0x0043e910`, `0x0043ebb0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` (+ callers/xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave33_partition_map.md` (W33-K).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0043e910` GuardedVector_RingFillFromPtr | **accept** — stack-arg forward ring fill + self-alias skip sealed (84 B) |
| `aa_0043ebb0` GuardedVector_RingAssignBackwardChecked | **accept** — reverse ring assign + self-alias skip + out pair sealed (148 B) |

---

## VA `0x0043e910` — sealed facts

1. **Body:** `0x0043e910`–`0x0043e963` (**84 B** / `0x54`; pad `CC` then `FUN_0043e970`).
2. **ABI:** 5 stack formals `(start_c, start_i, end_c, end_i, fill*)`; plain **`RET`** (caller cleans **0x14**). Not thiscall / not EBX-fill.
3. **Semantics:** Forward half-open ring fill of dwords:
   - While `(start_c, start_i) != (end_c, end_i)`: map `start_i` via `block=idx>>2` with wrap when `block >= capacity`, lane `idx + block*-4`.
   - If dest element address ≠ fill pointer → `*dest = *fill`.
   - `start_i++`. Addressing always uses **start** container (`+0x04` slots / `+0x08` capacity).
4. **Classification:** leaf worker — no callees.
5. **Callers (1):** `FUN_0043e080` / `GuardedVector_InsertN_Thiscall` @ `0x0043e15e`, `0x0043e2a0`, `0x0043e363` (fill residual after push_front/push_back arms).
6. **Name:** `GuardedVector_RingFillFromPtr` (Ghidra `FUN_0043e910`; **Inferred** structural; family W28-D RingFillRange + W32-F InsertN_Thiscall).
7. **Decompile ≡ raw CF**; **bytes win** on ABI (stack fill*, plain RET, self-guard). Full hex: raw W33-K append.

### Gaps

- Product/PDB English.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0043e910_GuardedVector_RingFillFromPtr.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0043e910_GuardedVector_RingFillFromPtr.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043e910_FUN_0043e910.md` |
| Annotated | `docs/reconstruction/raw/aa_0043e910_FUN_0043e910.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_RingFillFromPtr.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043e910.cpp` |
| Function | `docs/reconstruction/functions/aa_0043e910_FUN_0043e910.md` |
| Function named | `docs/reconstruction/functions/aa_0043e910_GuardedVector_RingFillFromPtr.md` |
| Scratch | `docs/reconstruction/tmp/a_0043e910.md` |

---

## VA `0x0043ebb0` — sealed facts

1. **Body:** `0x0043ebb0`–`0x0043ec43` (**148 B** / `0x94`; pad `CC` then `FUN_0043ec50`).
2. **ABI:** 7 stack formals `(out, stop_c, stop_i, src_c, src_i, dst_c, dst_i)`; plain **`RET`** (caller cleans **0x1c**). Returns **out in EAX** (bytes; decompiler void incomplete).
3. **Semantics:** Reverse ring element-assign (`copy_backward` shape):
   - While `(src_c, src_i) != (stop_c, stop_i)`: `--src_i`, `--dst_i`, map each through capacity-wrapped block table.
   - If `dst_elem != src_elem` → dword `*dst = *src`.
   - Write out iterator `{dst_c, final_dst_i}`.
4. **Layout used:** `+0x04` slots, `+0x08` capacity (does **not** touch begin/size).
5. **Classification:** leaf worker — no callees. Twin of sealed `GuardedVector_RingAssignBackward` (`0x0043d300`) **without** self-guard.
6. **Callers (4):** `FUN_0043e080` @ `0x0043e352`; `FUN_0043df90` @ `0x0043dfee`; `FUN_0044e1c0` / InsertRange @ `0x0044e4bd`; `FUN_005441d0` @ `0x0054454d`.
7. **Name:** `GuardedVector_RingAssignBackwardChecked` (Ghidra `FUN_0043ebb0`; **Inferred** structural).
8. **Decompile ≡ raw CF**; **bytes win** on EAX return + self-guard. Full hex: raw W33-K append.

### Gaps

- Product/PDB English.  
- Runtime / bit-exact.  
- Why MSVC emitted self-guard twin vs `0043d300` (instantiation residual).

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0043ebb0_GuardedVector_RingAssignBackwardChecked.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0043ebb0_GuardedVector_RingAssignBackwardChecked.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043ebb0_FUN_0043ebb0.md` |
| Annotated | `docs/reconstruction/raw/aa_0043ebb0_FUN_0043ebb0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_RingAssignBackwardChecked.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043ebb0.cpp` |
| Function | `docs/reconstruction/functions/aa_0043ebb0_FUN_0043ebb0.md` |
| Function named | `docs/reconstruction/functions/aa_0043ebb0_GuardedVector_RingAssignBackwardChecked.md` |
| Scratch | `docs/reconstruction/tmp/a_0043ebb0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0043e910` | InsertN_Thiscall residual fill must use **stack fill*** + half-open ring map + **address** self-alias skip. Do **not** call EBX-fill `RingFillRange` (`0043cef0`) or invent flat `memset`. |
| `0043ebb0` | Mid-insert / InsertRange reverse packing must reverse-assign dwords through capacity-wrapped blocks with **self-guard**. Do **not** unify with unguarded `0043d300` or forward walkers. **7** stack args, plain RET, **out in EAX**. |

Shared contrast (do not collapse helpers):

| Unit | Direction | Self-guard | Fill/src | Stack | RET |
|------|-----------|------------|----------|-------|-----|
| `0043cef0` RingFillRange | forward | no | **EBX** | 4 | plain |
| `0043e910` RingFillFromPtr | forward | **yes** | **stack** | 5 | plain |
| `0043d300` RingAssignBackward | reverse | no | src cursor | 7 | plain + EAX out |
| `0043ebb0` RingAssignBackwardChecked | reverse | **yes** | src cursor | 7 | plain + EAX out |

Closes W32-F residual on nested `FUN_0043e910` / `FUN_0043ebb0` under `GuardedVector_InsertN_Thiscall`; also seals reverse helper used by InsertRange (`0044e1c0`).

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` structural names only (`GuardedVector_*` family from W28–W32 duals).  
- Avoided bare `undefined4` in clean (used `uint32_t` / explicit header structs).
