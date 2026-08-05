# Dual A/B report — W28-A OWN `aa_0043d390` + `aa_00433ca0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W28-A  
**Scope:** VAs `0x0043d390`, `0x00433ca0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `read_memory` + `analyze_function_complete` (+ callers/callees/xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0043d390` GuardedVector_RingCopyElements | **accept** — cdecl 7-arg ring dword copy leaf; map@+4/cap@+8/4-per-block; multi-caller; closes W27-B/W27-C residual |
| `aa_00433ca0` BitStream_HuffmanAlphabet_CopyRange | **accept** — custom-reg ABI + stride-0xC range copy + exclusive EnsureCapacity parent sealed |

---

## VA `0x0043d390` — sealed facts

1. **Body:** `0x0043d390`–`0x0043d411` (**130 B**; pad `CC` after plain `RET`).
2. **ABI:** **cdecl** — 7 stack formals: `outPair, srcCont, srcIdx, srcEndCont, srcEndIdx, dstCont, dstIdx`; plain `RET` (caller cleans).
3. **Semantics:** While source iterator ≠ end: resolve block=`idx>>2`, slot=`idx%4`, wrap if `block >= capacity`; copy **one dword**; advance both indices; write `*outPair = {dstCont, finalDstIdx}`.
4. **Classification:** **leaf** (0 callees).
5. **Callers:** `FUN_0043ce90` (RingCopyRange), `FUN_0043c8c0` (EraseRange forward), `FUN_0043cb00`, `FUN_0043cf40` — **7** xrefs.
6. **Name:** `GuardedVector_RingCopyElements` (Ghidra `FUN_0043d390`; **Inferred** structural from GuardedVector family + ring math). Reverse sister `FUN_0043d300` not OWN.
7. **Decompile ≡ bytes** for CF (live 2026-07-29 ≡ raw 2026-07-23).

### Gaps

- Product / STL original template English.  
- Full arg packing of non-OWN callers `0043cb00` / `0043cf40`.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0043d390_GuardedVector_RingCopyElements.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0043d390_GuardedVector_RingCopyElements.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043d390_FUN_0043d390.md` |
| Annotated | `docs/reconstruction/raw/aa_0043d390_FUN_0043d390.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_RingCopyElements.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043d390.cpp` |
| Function | `docs/reconstruction/functions/aa_0043d390_FUN_0043d390.md` |
| Function named | `docs/reconstruction/functions/aa_0043d390_GuardedVector_RingCopyElements.md` |
| Scratch | `docs/reconstruction/tmp/a_0043d390.md` |

---

## VA `0x00433ca0` — sealed facts

1. **Body:** `0x00433ca0`–`0x00433cd3` (**52 B**; pad `CC` after plain `RET`).
2. **ABI:** **custom registers** — EDI=container, ESI=src, EAX=endIdx, EDX=startIdx; no stack formals; plain `RET`. Decompiler `__fastcall` formals incomplete (`param_1` unused; `in_EAX` is end).
3. **Semantics:** For `i ∈ [start, end)`: `dest = *(container+8) + i*0xC`; if non-null copy three dwords from `src + i*0xC`.
4. **Classification:** **leaf** (0 callees).
5. **Callers (1):** only `FUN_00433c00` (`BitStream_HuffmanAlphabetEnsureCapacity`) @ `0x00433c36`. Parent sets ESI=old, EAX=size, EDX=0 after installing neu.
6. **Name:** `BitStream_HuffmanAlphabet_CopyRange` (Ghidra `FUN_00433ca0`; **Inferred** from exclusive parent + 0xC stride). Sister tree copy is `FUN_00433c60` (stride 8).
7. **Decompile ≡ bytes** for CF (live 2026-07-29 ≡ raw 2026-07-23).

### Gaps

- Product English / TNL original helper name.  
- Null-dest branch practical reachability.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00433ca0_BitStream_HuffmanAlphabet_CopyRange.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_00433ca0_BitStream_HuffmanAlphabet_CopyRange.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00433ca0_FUN_00433ca0.md` |
| Annotated | `docs/reconstruction/raw/aa_00433ca0_FUN_00433ca0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/BitStream_HuffmanAlphabet_CopyRange.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00433ca0.cpp` |
| Function | `docs/reconstruction/functions/aa_00433ca0_FUN_00433ca0.md` |
| Function named | `docs/reconstruction/functions/aa_00433ca0_BitStream_HuffmanAlphabet_CopyRange.md` |
| Scratch | `docs/reconstruction/tmp/a_00433ca0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0043d390` | GuardedVector assign/erase-forward must use this ring element walk (map@+4, cap@+8, 4 dwords/block, capacity wrap). Do not invent flat `memcpy`. Closes residual left open by W27-B RingCopyRange and W27-C EraseRange duals. |
| `00433ca0` | Huffman alphabet grow must copy **size** elements of **0xC** via this custom-reg helper (or equivalent). Do not `memcpy(capacity)` and do not share with tree stride 8. Closes residual left open by W26-B AlphabetEnsureCapacity dual. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers/callees/xrefs). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` structural names only.  
- Avoided bare `undefined4` in clean (used `uint32_t` / explicit structs).  
- Pattern: `docs/agents/task-dual-ab-00433c60-0043ce90-w27b-report.md`.
