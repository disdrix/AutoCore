# Dual A/B report — W27-B OWN `aa_00433c60` + `aa_0043ce90`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W27-B  
**Scope:** VAs `0x00433c60`, `0x0043ce90` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` (+ callers/callees/xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00433c60` BitStream_HuffmanTree_CopyRange | **accept** — custom-reg ABI + stride-8 range copy + exclusive EnsureCapacity parent sealed |
| `aa_0043ce90` GuardedVector_RingCopyRange | **accept-with-gaps** — reshape+call `FUN_0043d390` + return ESI + exclusive CopyAssign parent sealed; unowned callee formal depth residual |

---

## VA `0x00433c60` — sealed facts

1. **Body:** `0x00433c60`–`0x00433c92` (**51 B**; pad `CC` after plain `RET`).
2. **ABI:** **custom registers** — EBX=container, ESI=src, EDI=endIdx, EDX=startIdx; no stack formals; plain `RET`. Decompiler `__fastcall` formals incomplete (`param_1` unused).
3. **Semantics:** For `i ∈ [start, end)`: `dest = *(container+8) + i*8`; if non-null copy two dwords from `src + i*8`.
4. **Classification:** **leaf** (0 callees).
5. **Callers (1):** only `FUN_00433ba0` (`BitStream_HuffmanTree_EnsureCapacity`) @ `0x00433bdc`. Parent sets ESI=old, EDI=count, EDX=0 after installing neu.
6. **Name:** `BitStream_HuffmanTree_CopyRange` (Ghidra `FUN_00433c60`; **Inferred** from exclusive parent + 8-byte stride). Sister alphabet copy is `FUN_00433ca0` (0xC).
7. **Decompile ≡ bytes** for CF (live 2026-07-29 ≡ raw 2026-07-23).

### Gaps

- Product English / TNL original helper name.  
- Null-dest branch practical reachability.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00433c60_BitStream_HuffmanTree_CopyRange.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_00433c60_BitStream_HuffmanTree_CopyRange.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00433c60_FUN_00433c60.md` |
| Annotated | `docs/reconstruction/raw/aa_00433c60_FUN_00433c60.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/BitStream_HuffmanTree_CopyRange.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00433c60.cpp` |
| Function | `docs/reconstruction/functions/aa_00433c60_FUN_00433c60.md` |
| Function named | `docs/reconstruction/functions/aa_00433c60_BitStream_HuffmanTree_CopyRange.md` |
| Scratch | `docs/reconstruction/tmp/a_00433c60.md` |

---

## VA `0x0043ce90` — sealed facts

1. **Body:** `0x0043ce90`–`0x0043cebe` (**47 B**; pad `CC` after last RET).
2. **ABI:** parent pushes **6** stack args + `ESI` out-pair; this unit reshapes, `CALL FUN_0043d390`, `MOV EAX,ESI`, `ADD ESP,0x24`, plain `RET`. Parent cleans `0x18` after return.
3. **Semantics:** Ring-copy **entry/shim** for unlocked assign — not a full assign by itself; fit/grow residual helpers follow in parent.
4. **Classification:** **worker** — sole callee `FUN_0043d390`.
5. **Callers (2):** only `FUN_0043c730` (`GuardedVector_CopyAssign`) @ `0x0043c76e` (fit) and `0x0043c7aa` (grow).
6. **Name:** `GuardedVector_RingCopyRange` (Ghidra `FUN_0043ce90`; **Inferred** structural; W26-G called this “prep”).
7. **Decompile ≡ bytes** for high-level CF (live 2026-07-29 ≡ raw 2026-07-23 `call FUN_0043d390`).

### Gaps

- Product/PDB English.  
- Full reshape formal map into unowned `FUN_0043d390`.  
- Fit (`0043c8c0`) / grow (`0043cec0`) residual (W27-C partition).  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0043ce90_GuardedVector_RingCopyRange.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0043ce90_GuardedVector_RingCopyRange.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043ce90_FUN_0043ce90.md` |
| Annotated | `docs/reconstruction/raw/aa_0043ce90_FUN_0043ce90.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_RingCopyRange.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043ce90.cpp` |
| Function | `docs/reconstruction/functions/aa_0043ce90_FUN_0043ce90.md` |
| Function named | `docs/reconstruction/functions/aa_0043ce90_GuardedVector_RingCopyRange.md` |
| Scratch | `docs/reconstruction/tmp/a_0043ce90.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00433c60` | Huffman tree grow must copy **count** elements of **8 bytes** via this custom-reg helper (or equivalent). Do not `memcpy(capacity)` and do not share with alphabet stride 0xC. Closes residual left open by W26-C EnsureCapacity dual. |
| `0043ce90` | GuardedVector unlocked assign must invoke this ring-copy entry (→ `FUN_0043d390`) before fit/grow residual helpers. Do not invent flat `memcpy` assign. Closes nested prep residual left open by W26-G CopyAssign dual. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers/callees/xrefs). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` structural names only.  
- Avoided bare `undefined4` in clean (used `uint32_t` / explicit structs).  
- Pattern: `docs/agents/task-dual-ab-00433ba0-0077d440-w26c-report.md`.
