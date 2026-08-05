# Dual A/B report — W29-B OWN `aa_0043ce10` + `aa_0043c830`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W29-B  
**Scope:** VAs `0x0043ce10`, `0x0043c830` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` (+ callers/callees). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** wave29.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0043ce10` GuardedVector_PushFront | **accept-with-gaps** — EAX/stdcall ABI + begin wrap/page map/size++ sealed; product/runtime residual |
| `aa_0043c830` GuardedVector_PushBack | **accept-with-gaps** — EAX/stdcall ABI + end write/page wrap/size++ sealed; product/runtime residual |

---

## VA `0x0043ce10` — sealed facts

1. **Body:** `0x0043ce10`–`0x0043ce85` (**118 B** / `0x76`; pad `CC` after last RET).
2. **ABI:** **EAX=container**; stdcall **1** stack formal (`const uint32_t* value`); entry `MOV EBX,EAX`; **`RET 0x4`**.
3. **Semantics:** Ring-deque **push_front** of one dword.  
   - If `(begin & 3)==0` and `capacity <= (size+4)>>2` → `GuardedVector_GrowBlockMap(1)` (EBX this).  
   - If `begin==0` → treat as `capacity*4`.  
   - `new_begin = begin - 1`; map `page = new_begin>>2`, sub `new_begin&3`.  
   - Lazy `operator_new(0x10)` if page null; store `*value`; `size++`; `begin = new_begin`.
4. **Layout:** `+0x04` pages, `+0x08` capacity, `+0x0c` begin, `+0x10` size (family).
5. **Classification:** worker — callees `FUN_0043c9b0`, `operator_new`.
6. **Callers (2 funcs / 6 sites):** `FUN_0043cb00`, `FUN_0043cf40` / GrowAssignRangeCore.
7. **Name:** `GuardedVector_PushFront` (Ghidra `FUN_0043ce10`; **Inferred** structural).
8. **Decompile ≡ bytes** for full body (live 2026-07-29 ≡ raw 2026-07-23).  
   Full hex: `538bd8f6430c035775158b431083c004c1e80239430877076a01e881fbffff8b7b0c85ff75078b7b0803ff03ff8b4b0483ef01568bf7c1ee02833cb10075106a10e83cca04008b530483c4048904b28b43048b14b08bcf83e1038d048a85c05e74088b4c240c8b11891083431001897b0c5f5bc20400`

### Gaps

- Product/PDB class English (retail map overflow says `deque<T> too long`).  
- Element type beyond dword POD.  
- Runtime / bit-exact.  
- Null-`operator_new` still advances size/begin (bytes).

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0043ce10_GuardedVector_PushFront.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0043ce10_GuardedVector_PushFront.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043ce10_FUN_0043ce10.md` |
| Annotated | `docs/reconstruction/raw/aa_0043ce10_FUN_0043ce10.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_PushFront.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043ce10.cpp` |
| Function | `docs/reconstruction/functions/aa_0043ce10_FUN_0043ce10.md` |
| Function named | `docs/reconstruction/functions/aa_0043ce10_GuardedVector_PushFront.md` |
| Scratch | `docs/reconstruction/tmp/a_0043ce10.md` |

---

## VA `0x0043c830` — sealed facts

1. **Body:** `0x0043c830`–`0x0043c8a2` (**115 B** / `0x73`; pad `CC` then `FUN_0043c8c0` EraseRange).
2. **ABI:** **EAX=container**; stdcall **1** stack formal (`const uint32_t* value`); entry `MOV EBX,EAX`; **`RET 0x4`**.
3. **Semantics:** Ring-deque **push_back** of one dword.  
   - If `((begin+size) & 3)==0` and `capacity <= (size+4)>>2` → `GuardedVector_GrowBlockMap(1)`.  
   - `abs = begin + size`; `page = abs>>2`; if `capacity <= page` → `page -= capacity`.  
   - Lazy `operator_new(0x10)` if page null; store `*value`; `size++` only (**begin unchanged**).
4. **Layout:** same family as PushFront / EraseRange / Resize.
5. **Classification:** worker — callees `FUN_0043c9b0`, `operator_new`.
6. **Callers (5 funcs / 10 sites):** `FUN_0043cb00`, `FUN_0043cf40`, `FUN_0043c4f0`, `FUN_007b75b0`, `FUN_009668a0`.
7. **Name:** `GuardedVector_PushBack` (Ghidra `FUN_0043c830`; **Inferred** structural).
8. **Decompile ≡ bytes** for full body (live 2026-07-29 ≡ raw 2026-07-23).  
   Full hex: `538bd88b43108b4b0c03c8f6c103751283c004c1e80239430877076a01e85e0100008b4308568b730c037310578bfec1ef023bc777022bf88b5304833cba0075106a10e81ad004008b4b0483c4048904b98b53048b04ba83e6038d04b085c05f5e74088b4c24088b118910834310015bc20400`

### Gaps

- Product/PDB class English.  
- Element type beyond dword POD.  
- Runtime / bit-exact under multi-caller parents.  
- Null-`operator_new` still advances size (bytes).

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0043c830_GuardedVector_PushBack.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0043c830_GuardedVector_PushBack.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043c830_FUN_0043c830.md` |
| Annotated | `docs/reconstruction/raw/aa_0043c830_FUN_0043c830.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_PushBack.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043c830.cpp` |
| Function | `docs/reconstruction/functions/aa_0043c830_FUN_0043c830.md` |
| Function named | `docs/reconstruction/functions/aa_0043c830_GuardedVector_PushBack.md` |
| Scratch | `docs/reconstruction/tmp/a_0043c830.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0043ce10` | Grow-assign / insert front residual must use page-map push_front: **EAX=container**, stack `value*`, wrap `begin` at 0 through `capacity*4`, commit `begin` after store. Closes front construct polarity residual from W28-B `GuardedVector_GrowAssignRangeCore` (`ce10` arms). Do not invent linear `vector::push_front`. |
| `0043c830` | Grow-assign / insert back residual must use page-map push_back: write at absolute `begin+size` with page wrap; **begin unchanged**. Closes back construct polarity residual from W28-B grow-assign and insert worker `FUN_0043cb00`. Shared map grow is sealed W28-B `GuardedVector_GrowBlockMap`. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers/callees). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` structural names only (`GuardedVector_*` family from parent duals W26-G / W27-C / W28-B / W28-D).  
- Avoided bare `undefined4` in clean (used `uint32_t` / explicit header structs).
