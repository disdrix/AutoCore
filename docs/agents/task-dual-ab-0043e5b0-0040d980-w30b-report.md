# Dual A/B report — W30-B OWN `aa_0043e5b0` + `aa_0040d980`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W30-B  
**Scope:** VAs `0x0043e5b0`, `0x0040d980` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` (+ callers/callees). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** wave30.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0043e5b0` GuardedVector_ContainsFirstEqual | **accept-with-gaps** — EAX/stdcall ABI + CS gate + first-equal page-map scan sealed; product/null-page/runtime residual |
| `aa_0040d980` GuardedVector_PopFront | **accept** — EAX leaf ABI + begin wrap / size-- / empty reset fully sealed |

---

## VA `0x0043e5b0` — sealed facts

1. **Body:** `0x0043e5b0`–`0x0043e62a` (**123 B** / `0x7B`; pad `CC` after last RET).
2. **ABI:** **EAX=container**; stdcall **1** stack formal (`const int* key`); entry `MOV EDI,EAX`; **`RET 0x4`**; return **AL** (0/1).
3. **Semantics:** Optional CS (`+0x2c` flag → Enter/Leave `+0x14`) then linear **first-equal** scan of ring elements in half-open `[begin, begin+size)`.  
   - `page = idx>>2`; if `capacity <= page` → `page -= capacity`; `sub = idx&3`.  
   - Compare `pages[page][sub] == *key`; first hit → AL=1; miss → AL=0.  
   - **No mutate** of pages/begin/size.
4. **Layout:** `+0x04` pages, `+0x08` capacity, `+0x0c` begin, `+0x10` size, `+0x14` CS, `+0x2c` flag (family).
5. **Classification:** worker — callees `EnterCriticalSection`, `LeaveCriticalSection`.
6. **Callers (5 funcs / 6 sites):** `FUN_00423e00`, `FUN_007b65d0`, `FUN_007b75b0`, `FUN_00971640`, `FUN_00971900`.
7. **Name:** `GuardedVector_ContainsFirstEqual` (Ghidra `FUN_0043e5b0`; **Inferred** structural; pairs with W28-C `GuardedVector_EraseFirstEqual`).
8. **Decompile ≡ bytes** for full body (live 2026-07-29 ≡ raw 2026-07-23).  
   Full hex: `51535556578bf8807f2c008d771489742410740756ff15bc619c008b570c8b6f1032db03ea3bff75043bd574378bc2c1e8028d0c85000000008bf18bca2bce8b77083bf077022bc68b77048b04868b0c888b4424183b088b742410740583c201ebc3b301807e1800740756ff15b8619c005f5e5d8ac35b59c20400`

### Gaps

- Product/PDB class English.  
- Element type beyond dword POD.  
- Runtime / bit-exact under multi-caller parents.  
- Null page load residual (bytes do not null-check before load).

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0043e5b0_GuardedVector_ContainsFirstEqual.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0043e5b0_GuardedVector_ContainsFirstEqual.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043e5b0_FUN_0043e5b0.md` |
| Annotated | `docs/reconstruction/raw/aa_0043e5b0_FUN_0043e5b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_ContainsFirstEqual.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043e5b0.cpp` |
| Function | `docs/reconstruction/functions/aa_0043e5b0_FUN_0043e5b0.md` |
| Function named | `docs/reconstruction/functions/aa_0043e5b0_GuardedVector_ContainsFirstEqual.md` |
| Scratch | `docs/reconstruction/tmp/a_0043e5b0.md` |

---

## VA `0x0040d980` — sealed facts

1. **Body:** `0x0040d980`–`0x0040d9b1` (**50 B** / `0x32`; pad `CC`).
2. **ABI:** **EAX=container**; **0** stack formals; plain **`RET`**; void.
3. **Semantics:** Header-only ring **pop_front**.  
   - If `size==0` → no-op.  
   - Else `begin++`; if `capacity*4 <= begin` → `begin=0`; `size--`; if `size==0` → `begin=0`.  
   - **No** element read/write, page free, or CS.
4. **Layout:** `+0x08` capacity (pages), `+0x0c` begin, `+0x10` size (family).
5. **Classification:** **leaf** (0 callees).
6. **Xrefs (6):** `0x0043cc4a`, `0x0043d0e2`, `0x008c41f1`, `0x0090c2da`, `0x008dd784`, `0x008dd902` (insert/grow workers + other parents; Catch sites among callers).
7. **Name:** `GuardedVector_PopFront` (Ghidra `FUN_0040d980`; **Inferred** structural).
8. **Decompile ≡ bytes** for full body (live 2026-07-29 ≡ raw 2026-07-23).  
   Full hex: `8b481085c9742a83400c018b500c578b780803ff03ff3bfa5f7707c7400c0000000083c1ff8948107507c7400c00000000c3`

### Gaps

- Product/PDB English (naming only; CF closed).  
- Caller residual: non-POD dtor/free must happen **outside** this leaf if required.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0040d980_GuardedVector_PopFront.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0040d980_GuardedVector_PopFront.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0040d980_FUN_0040d980.md` |
| Annotated | `docs/reconstruction/raw/aa_0040d980_FUN_0040d980.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_PopFront.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0040d980.cpp` |
| Function | `docs/reconstruction/functions/aa_0040d980_FUN_0040d980.md` |
| Function named | `docs/reconstruction/functions/aa_0040d980_GuardedVector_PopFront.md` |
| Scratch | `docs/reconstruction/tmp/a_0040d980.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0043e5b0` | Membership residual for assManager resolver paths must use **EAX=container**, stack `key*`, **RET 4**, **AL** found; optional own CS when `+0x2c`. Linear page-map first-equal — not `std::find` on a flat vector. Closes find residual referenced from W29-C `AssManager_RemoveResolver` before sealed `EraseFirstEqual`. |
| `0040d980` | Insert/grow Catch and erase residual that drops front must use unlocked header pop: **EAX=container**, wrap `begin` at `capacity*4`, `size--`, empty → `begin=0`. Do not invent value-returning `deque::pop_front` or page free in this leaf. Complements W29-B PushFront/PushBack polarity. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers/callees). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` structural names only (`GuardedVector_*` family from parent duals W26–W29 + `EraseFirstEqual` pair).  
- Avoided bare `undefined4` in clean (used `uint32_t` / explicit header structs).
