# Dual A/B report — W29-A OWN `aa_0043cb00` + `aa_0043c660`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W29-A  
**Scope:** VAs `0x0043cb00`, `0x0043c660` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `read_memory` + callers/callees. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave29_partition_map.md`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0043cb00` GuardedVector_InsertN | **accept-with-gaps** — ECX=N / RET 0x10 ABI + 4-arm shorter-side CF sealed; nested construct free (`0043ce10`/`0043c830`) residual |
| `aa_0043c660` GuardedVector_ClearAndSwap | **accept** — ESI/EDI ABI + optional CS + Resize(0) + 4-dword header swap fully sealed |

---

## VA `0x0043cb00` — sealed facts

1. **Body:** `0x0043cb00`–`0x0043cdfe` (**769 B** / `0x301`; pad `CC` then `FUN_0043ce10`).
2. **ABI:** **ECX=N**; stack `(container, seed, insert_at, fill*)`; **`RET 0x10`**. Decompiler `__thiscall` label is misleading.
3. **Semantics:** Insert `N` copies of `*fill` at absolute `insert_at`.  
   - `prefix = insert_at - begin`; `suffix = size - prefix`.  
   - Front-biased (`prefix < suffix`): push_front via `FUN_0043ce10` ± `FUN_0043d390`, then `GuardedVector_RingFillRange`.  
   - Back-biased: push_back via `FUN_0043c830` ± `FUN_0043d300`, then RingFillRange.  
   - SEH cleanup islands: pop_front `FUN_0040d980` / pop_back `FUN_0043df70` + `_CxxThrowException`.
4. **Layout:** `+0x04` slots, `+0x08` capacity, `+0x0c` begin, `+0x10` size.
5. **Classification:** worker — callees ce10/c830/cef0/d300/d390 (+ SEH cleanup).
6. **Callers (1):** `FUN_0043c7e0` / `GuardedVector_Resize` grow — always `insert_at=begin+size` (end-insert; back arm `suffix < N`).
7. **Name:** `GuardedVector_InsertN` (Ghidra `FUN_0043cb00`; **Inferred** structural).
8. **Decompile ≡ bytes** for success CF tree (live 2026-07-29 ≡ raw 2026-07-23). SEH cleanup present in bytes, omitted from decompiler success path.  
   Full hex: see raw append (769 B).

### Gaps

- Product/PDB class English.  
- Nested construct free inside unowned `FUN_0043ce10` / `FUN_0043c830` (W29-B).  
- Front-biased arms not call-site exercised.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0043cb00_GuardedVector_InsertN.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0043cb00_GuardedVector_InsertN.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043cb00_FUN_0043cb00.md` |
| Annotated | `docs/reconstruction/raw/aa_0043cb00_FUN_0043cb00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_InsertN.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043cb00.cpp` |
| Function | `docs/reconstruction/functions/aa_0043cb00_FUN_0043cb00.md` |
| Function named | `docs/reconstruction/functions/aa_0043cb00_GuardedVector_InsertN.md` |
| Scratch | `docs/reconstruction/tmp/a_0043cb00.md` |

---

## VA `0x0043c660` — sealed facts

1. **Body:** `0x0043c660`–`0x0043c6e8` (**137 B** / `0x89`; pad `CC` then next unit).
2. **ABI:** **ESI=A**, **EDI=B**; no stack formals; SEH frame `ADD ESP,0x10; RET`.
3. **Semantics:** Optional CS on B (`[EDI+0x2c]` / `EDI+0x14`) → `GuardedVector_Resize(A, 0)` → swap `+0x04/+0x08/+0x0c/+0x10` between A and B → LeaveCS.
4. **Classification:** worker — callees EnterCS, `FUN_0043c7e0` (Resize), LeaveCS.
5. **Callers (1):** `FUN_0075dae0`.
6. **Name:** `GuardedVector_ClearAndSwap` (Ghidra `FUN_0043c660`; **Inferred** structural).
7. **Decompile ≡ bytes** for full body (live 2026-07-29 ≡ raw 2026-07-23). Clear site: `33 C9 8B C6 E8 …` (ECX=0, EAX=ESI).  
   Full hex: see raw append (137 B).

### Gaps

- Product/PDB English.  
- Parent `FUN_0075dae0` ownership story.  
- Runtime under contended CS.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0043c660_GuardedVector_ClearAndSwap.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0043c660_GuardedVector_ClearAndSwap.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043c660_FUN_0043c660.md` |
| Annotated | `docs/reconstruction/raw/aa_0043c660_FUN_0043c660.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_ClearAndSwap.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043c660.cpp` |
| Function | `docs/reconstruction/functions/aa_0043c660_FUN_0043c660.md` |
| Function named | `docs/reconstruction/functions/aa_0043c660_GuardedVector_ClearAndSwap.md` |
| Scratch | `docs/reconstruction/tmp/a_0043c660.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0043cb00` | Resize grow residual closed at ABI level: **ECX=N**, stack packs container×2 + end index + fill*; end-insert uses **push_back N** then **RingFillRange** — not linear `vector::insert`. Mid-insert arms need W29-B construct free before golden port. |
| `0043c660` | Clear-before-swap under optional CS: clear **ESI** with Resize(0), then swap only ring headers with **EDI**. Do not swap CS fields. Closes residual named in W28-D Resize dual. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + callers/callees. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` structural names only (`GuardedVector_*` family from parent duals W26–W28).  
- Avoided bare `undefined4` in clean (used `uint32_t` / explicit header structs).
