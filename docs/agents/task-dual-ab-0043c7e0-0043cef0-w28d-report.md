# Dual A/B report — W28-D OWN `aa_0043c7e0` + `aa_0043cef0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W28-D  
**Scope:** VAs `0x0043c7e0`, `0x0043cef0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` (+ callers/callees). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** wave28.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0043c7e0` GuardedVector_Resize | **accept-with-gaps** — EAX/ECX ABI + grow/shrink/equal CF sealed; nested `FUN_0043cb00` free residual |
| `aa_0043cef0` GuardedVector_RingFillRange | **accept** — leaf page-map fill CF/ABI + body 73 B fully sealed |

---

## VA `0x0043c7e0` — sealed facts

1. **Body:** `0x0043c7e0`–`0x0043c829` (**74 B** / `0x4A`; pad `CC` after last RET).
2. **ABI:** **EAX=container**, **ECX=new_size**; no stack formals; frame `SUB/ADD ESP,8`; plain `RET`.
3. **Semantics:** Resize ring header to absolute size.  
   - `size = [EAX+0x10]`; stack fill seed `= 0`.  
   - If `size < new_size` → grow: set `ECX = new_size - size`, call `FUN_0043cb00` with stack `(container, container, begin+size, &fill0)`.  
   - Else if `new_size < size` → shrink: `FUN_0043c8c0` / `GuardedVector_EraseRange` on `[begin+new_size, begin+size)`.  
   - Else no-op.
4. **Layout:** `+0x0c` begin, `+0x10` size (family slots/cap at `+0x04/+0x08` used by callees).
5. **Classification:** worker — callees `FUN_0043cb00`, `FUN_0043c8c0`.
6. **Callers (1):** `FUN_0043c660` only (xref `0x0043c697`) — always `XOR ECX,ECX` (clear ESI) before swapping headers with EDI.
7. **Name:** `GuardedVector_Resize` (Ghidra `FUN_0043c7e0`; **Inferred** structural).
8. **Decompile ≡ bytes** for trichotomy CF (live 2026-07-29 ≡ raw 2026-07-23). Grow call-arg list: **bytes win** (ECX count omitted by decompiler).  
   Full hex: `83ec08568b70103bcec744240400000000761b8b500c578d7c24085703d652502bce50e8f80200005f5e83c408c373158b500c03f2565003d152508d4c241451e89b0000005e83c408c3`

### Gaps

- Product/PDB class English.  
- Nested grow/insert free inside unowned `FUN_0043cb00`.  
- Runtime / bit-exact.  
- Sole known caller only exercises clear-to-0 (grow arm body-sealed, not call-site exercised).

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0043c7e0_GuardedVector_Resize.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0043c7e0_GuardedVector_Resize.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043c7e0_FUN_0043c7e0.md` |
| Annotated | `docs/reconstruction/raw/aa_0043c7e0_FUN_0043c7e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_Resize.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043c7e0.cpp` |
| Function | `docs/reconstruction/functions/aa_0043c7e0_FUN_0043c7e0.md` |
| Function named | `docs/reconstruction/functions/aa_0043c7e0_GuardedVector_Resize.md` |
| Scratch | `docs/reconstruction/tmp/a_0043c7e0.md` |

---

## VA `0x0043cef0` — sealed facts

1. **Body:** `0x0043cef0`–`0x0043cf38` (**73 B** / `0x49`; pad `CC` then `FUN_0043cf40`).
2. **ABI:** 4 stack formals `(container_from, idx_from, container_to, idx_to)`; **EBX=&fill_dword**; plain `RET` (caller cleans `0x10`).
3. **Semantics:** Leaf ring fill — for each absolute index in half-open dual-iterator range, map `idx→(page=idx>>2, sub=idx%4)`, wrap page by `[container+0x08]`, store `*EBX` at `([container+0x04])[page][sub]`.
4. **Classification:** **leaf** (0 callees).
5. **Callers (1):** `FUN_0043cb00` only — xrefs `0x0043cbdd`, `0x0043cd1c`, `0x0043cde6`.
6. **Name:** `GuardedVector_RingFillRange` (Ghidra `FUN_0043cef0`; **Inferred** structural).
7. **Decompile ≡ bytes** for full body (live 2026-07-29 ≡ raw 2026-07-23).  
   Full hex: `8b542408558b6c241456578b7c2410903b7c241875043bd5742b8bc2c1e8028d0c85000000008bf18bca2bce8b77083bf077022bc68b77048b04868b3389348883c201ebcb5f5e5dc3`

### Gaps

- Product English for element type / class.  
- Runtime golden under full insert parent (unowned `FUN_0043cb00`).

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0043cef0_GuardedVector_RingFillRange.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0043cef0_GuardedVector_RingFillRange.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043cef0_FUN_0043cef0.md` |
| Annotated | `docs/reconstruction/raw/aa_0043cef0_FUN_0043cef0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_RingFillRange.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043cef0.cpp` |
| Function | `docs/reconstruction/functions/aa_0043cef0_FUN_0043cef0.md` |
| Function named | `docs/reconstruction/functions/aa_0043cef0_GuardedVector_RingFillRange.md` |
| Scratch | `docs/reconstruction/tmp/a_0043cef0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0043c7e0` | Unlocked resize body under GuardedVector CS parents: **EAX=container**, **ECX=new_size**; grow with fill-default **0** via insert worker; shrink must call sealed **EraseRange** on `[begin+new, begin+old)`. Do not invent plain `vector::resize` without ring begin/size. Parent `FUN_0043c660` clear-before-swap remains residual. Nested grow free (`FUN_0043cb00`) residual. |
| `0043cef0` | Grow/insert residual fill must use page map (`+0x04` pages, `+0x08` page capacity, 4 dwords/page) and **EBX** fill pointer — not flat `memset` of a linear buffer. Closes fill residual referenced from unowned `FUN_0043cb00` paths used by Resize grow. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers/callees). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` structural names only (`GuardedVector_*` family from parent duals W26-G / W27-B / W27-C).  
- Avoided bare `undefined4` in clean (used `uint32_t` / explicit header structs).
