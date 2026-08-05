# Dual A/B report — W32-C OWN `aa_0040d700` + `aa_0040d890`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W32-C  
**Scope:** VAs `0x0040d700`, `0x0040d890` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` + xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave32_partition_map.md` (W32-C).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0040d700` StdTree_EraseRange_Val12 | **accept-with-gaps** — full/partial range erase + ABI/RET0C/Val12 successor sealed; product T + value-dtor residual |
| `aa_0040d890` Class_009c7948_CompleteDtor | **accept-with-gaps** — derived vtbl install + base complete chain/SEH/ABI sealed; product class + vtbl[1..2] open |

---

## VA `0x0040d700` — sealed facts

1. **Body:** `0x0040d700`–`0x0040d7b3` (**180 B** / `0xB4`; pad `CC`).
2. **ABI:** **ECX=`map`/tree facade** (`head@+4`, `size@+8`); stack **`out_it*`**, **`first*`**, **`last*`**; **`RET 0x0C`** (`C2 0C 00`) both exits; void.
3. **Semantics:** MSVC-style **`_Tree` range erase** `[first, last)` on Val12 nodes (isnil@`+0x19`):
   - **Full range** (`first == head->left && last == head`): `StdTree_FreeSubtree_Val12(head->parent)` (`FUN_0040d630`); reset head self-links; `size=0`; `*out_it = head->left`.
   - **Partial:** while `first != last`: compute in-order successor; `FUN_004188e0` single erase; advance; `*out_it = first`.
   - Full free path does **not** run value vtbl destroy (clear owns that).
4. **Classification:** worker.
5. **Callers:** `FUN_0040d6d0` @ `0x0040d6e2`; `FUN_0040d7c0` @ `0x0040d7f3` (both full clear then `operator_delete(head)`).
6. **Callees:** `FUN_0040d630` (FreeSubtree), `FUN_004188e0` (single erase).
7. **Name:** `StdTree_EraseRange_Val12` (Ghidra `FUN_0040d700`; **Inferred** structural). Peer of W28-P `StdMap_EraseRange_Val12` @ `0x004e5120` (same CF/size; different free/erase callees).
8. **Decompile ≡ bytes** for CF + dual RET; full hex in raw W32-C append (180 B).

### Gaps

- Product/MSVC demangle for map T.  
- Value dtor policy on full free (none in body).  
- Nested `FUN_004188e0` product English (not owned).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0040d700_StdTree_EraseRange_Val12.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0040d700_StdTree_EraseRange_Val12.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0040d700_FUN_0040d700.md` |
| Annotated | `docs/reconstruction/raw/aa_0040d700_FUN_0040d700.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_EraseRange_Val12.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0040d700.cpp` |
| Function | `docs/reconstruction/functions/aa_0040d700_FUN_0040d700.md` |
| Function named | `docs/reconstruction/functions/aa_0040d700_StdTree_EraseRange_Val12.md` |
| Scratch | `docs/reconstruction/tmp/a_0040d700.md` |

---

## VA `0x0040d890` — sealed facts

1. **Body:** `0x0040d890`–`0x0040d8ca` (**59 B** / `0x3B`; pad `CC`).
2. **ABI:** **ECX=`this`**; SEH `LAB_009be2d8`; EH state **`0xFFFFFFFF`** during base call; epilogue **`ADD ESP,0x10; RET`**. Complete dtor — **does not** free `this`.
3. **Semantics:**
   - Install **`PTR_FUN_009c7948`** at `*this`.
   - **`FUN_0040d820(this)`** — base `StdTreeHost_PtrVal_CompleteDtor` (install `009c7938`, clear, `FUN_0040d7c0(this+4)`).
4. **Classification:** wrapper (thin derived complete over base).
5. **Callers:** `FUN_0040d870` @ `0x0040d873` (scalar-deleting; vtbl[0]).
6. **Callees:** `FUN_0040d820`.
7. **Name:** `Class_009c7948_CompleteDtor` (Ghidra `FUN_0040d890`; **Inferred**).
8. **Vtbl** `0x009c7948`: [0]=`0x0040d870`, [1]=`0x0074d470`, [2]=`0x0074d440` (`read_memory`).  
   Full hex: raw W32-C append (59 B).

### Gaps

- Product/MSVC demangle for derived class.  
- Vtbl slots [1]/[2].  
- Derived members (none in this body).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0040d890_Class_009c7948_CompleteDtor.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0040d890_Class_009c7948_CompleteDtor.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0040d890_FUN_0040d890.md` |
| Annotated | `docs/reconstruction/raw/aa_0040d890_FUN_0040d890.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Class_009c7948_CompleteDtor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0040d890.cpp` |
| Function | `docs/reconstruction/functions/aa_0040d890_FUN_0040d890.md` |
| Function named | `docs/reconstruction/functions/aa_0040d890_Class_009c7948_CompleteDtor.md` |
| Scratch | `docs/reconstruction/tmp/a_0040d890.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0040d700` | Port as **range erase**: full path free-subtree + head reset + size0; partial successor + single erase. **ECX=map**, stack `out/first/last`, **RET 0xC**. Do **not** invent value vtbl destroy on full free. Pair `StdTree_FreeSubtree_Val12` + `FUN_004188e0`. |
| `0040d890` | Port as **derived complete dtor only**. Install `PTR_FUN_009c7948`, then base complete `StdTreeHost_PtrVal_CompleteDtor`. Scalar path is `FUN_0040d870`. |
| Pair with | FreeSubtree `0040d630` (W31-A), base complete `0040d820` (W31-A), clear `0040d5b0` (W30-P), base scalar `0040d590` (W31-E), peer erase-range `004e5120` (W28-P), nested head free `0040d7c0` (W32-B owned). |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; structural `_Inferred` names only.  
- Avoided bare `undefined4` in clean (`uint32_t` / explicit structs).  
- Closes W31-A residual callers of FreeSubtree (`FUN_0040d700`) and derived complete (`FUN_0040d890`) named as high-mention nested callees in wave32 partition.
