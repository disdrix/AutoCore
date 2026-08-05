# Dual A/B report — W32-F OWN `aa_0043d420` + `aa_0043e080`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W32-F  
**Scope:** VAs `0x0043d420`, `0x0043e080` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` / `batch_decompile` + `read_memory` + callers/callees. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** wave32.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0043d420` GuardedVector_AssignDwordIfNonNull | **accept** — cdecl null-checked dword assign sealed (17 B); product residual only |
| `aa_0043e080` GuardedVector_InsertN_Thiscall | **accept-with-gaps** — ECX thiscall + 4-arm shorter-side insert-N sealed (766 B); nested e910/ebb0/ec50 residual |

---

## VA `0x0043d420` — sealed facts

1. **Body:** `0x0043d420`–`0x0043d430` (**17 B** / `0x11`; pad `CC` after last RET).
2. **ABI:** stack **`dst*`**, **`src*`** (cdecl); plain **`RET`**. No register this.
3. **Semantics:** Null-checked POD dword assign — if `dst != 0` then `*dst = *src`.
4. **Classification:** leaf worker — no callees.
5. **Callers (2):** `FUN_0043d670` / `GuardedVector_PushBack_Thiscall`, `FUN_0043e3d0` / `GuardedVector_PushFront_Thiscall` (W31-I).
6. **Name:** `GuardedVector_AssignDwordIfNonNull` (Ghidra `FUN_0043d420`; **Inferred** structural).
7. **Decompile ≡ bytes** for full CF (live 2026-07-29 ≡ raw 2026-07-23).  
   Full hex: `8b44240485c074088b4c24088b118910c3`

### Gaps

- Product/PDB English.  
- Runtime / bit-exact.  
- Null-check rationale after lazy page alloc.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0043d420_GuardedVector_AssignDwordIfNonNull.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0043d420_GuardedVector_AssignDwordIfNonNull.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043d420_FUN_0043d420.md` |
| Annotated | `docs/reconstruction/raw/aa_0043d420_FUN_0043d420.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_AssignDwordIfNonNull.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043d420.cpp` |
| Function | `docs/reconstruction/functions/aa_0043d420_FUN_0043d420.md` |
| Function named | `docs/reconstruction/functions/aa_0043d420_GuardedVector_AssignDwordIfNonNull.md` |

---

## VA `0x0043e080` — sealed facts

1. **Body:** `0x0043e080`–`0x0043e37d` (**766 B** / `0x2FE`; pad `CC` after last RET).
2. **ABI:** **ECX=container** (`MOV ESI,ECX`); stack **`(seed, insert_at, N, fill*)`**; **`RET 0x10`**. True thiscall entry (unlike W29-A `GuardedVector_InsertN` which puts **N in ECX**).
3. **Semantics:** Ring-deque **insert-N fill** at absolute `insert_at`.  
   - `prefix = insert_at - begin`; `suffix = size - prefix`.  
   - Front-biased: `GuardedVector_PushFront_Thiscall` (`0043e3d0`) ± `FUN_0043ec50` / `FUN_0043e910`.  
   - Back-biased: `GuardedVector_PushBack_Thiscall` (`0043d670`) ± `FUN_0043ebb0` / `FUN_0043e910`.  
   - SEH cleanup islands present in bytes.
4. **Layout:** `+0x04` pages, `+0x08` capacity, `+0x0c` begin, `+0x10` size (family).
5. **Classification:** worker — callees d670 / e3d0 / e910 / ebb0 / ec50 (+ SEH throw).
6. **Callers (1):** `FUN_0043d940` — resize grow always `insert_at = begin+size` (end-insert; back arm `suffix < N`).
7. **Name:** `GuardedVector_InsertN_Thiscall` (Ghidra `FUN_0043e080`; **Inferred** structural twin of W29-A `GuardedVector_InsertN`).
8. **Decompile ≡ bytes** for success CF tree (live 2026-07-29 ≡ raw 2026-07-23). Full hex: raw W32-F append.

### Gaps

- Product/PDB class English.  
- Nested `FUN_0043e910` / `FUN_0043ebb0` / `FUN_0043ec50` free (unowned).  
- Front-biased arms not call-site exercised.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0043e080_GuardedVector_InsertN_Thiscall.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0043e080_GuardedVector_InsertN_Thiscall.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043e080_FUN_0043e080.md` |
| Annotated | `docs/reconstruction/raw/aa_0043e080_FUN_0043e080.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_InsertN_Thiscall.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043e080.cpp` |
| Function | `docs/reconstruction/functions/aa_0043e080_FUN_0043e080.md` |
| Function named | `docs/reconstruction/functions/aa_0043e080_GuardedVector_InsertN_Thiscall.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0043d420` | Element assign leaf for thiscall push: **cdecl** `dst*`, `src*`, plain **RET**. `if (dst) *dst = *src` (one dword). Do not invent thiscall or multi-dword copy. Closes W31-I push assign residual. |
| `0043e080` | Thiscall insert-N: **ECX=container**, stack `(seed, insert_at, N, fill*)`, **RET 0x10**. Uses W31-I thiscall push pair — **not** W29-A EAX push / ECX=N ABI. Sole known caller is resize-grow end-insert. Nested e910/ebb0/ec50 still free for mid-insert golden port. |

Shared: both sit on the thiscall GuardedVector ring family (`+0x04/+0x08/+0x0c/+0x10`) sealed across W29–W31. Do not mix InsertN ABIs (ECX=N vs ECX=container) or push polarities (EAX vs thiscall).

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + callers/callees. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` structural names only (`GuardedVector_*` family from parent duals W29–W31 / W29-A InsertN / W31-I Push pair).  
- Avoided bare `undefined4` in clean (used `uint32_t` / explicit header structs).
