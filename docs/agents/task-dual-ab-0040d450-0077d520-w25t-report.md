# Dual A/B report — W25-T OWN `aa_0040d450` + `aa_0077d520`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W25-T  
**Scope:** VAs `0x0040d450`, `0x0077d520` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` (+ callers/callees). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0040d450` Math_FloatNearlyEqual_AbsRel | **accept** — abs+rel dual-gate CF + cdecl ABI + leaf sealed |
| `aa_0077d520` BitStream_HuffmanBuildTables | **accept** — once-init Huffman builder CF/ABI/strides + exclusive callers sealed |

---

## VA `0x0040d450` — sealed facts

1. **Body:** `0x0040d450`–`0x0040d4ac` (**93 B**; pad `CC` after last RET).
2. **ABI:** **cdecl**; stack `a, b, relTol, absTol` (4×float); **EAX** = 0|1; `PUSH ECX` / `POP ECX; RET` (ECX = scratch, not this).
3. **Semantics:** True if `|a−b| ≤ absTol` **OR** `|a−b| ≤ max(|a|,|b|) × relTol`; false only when both fail.
4. **Classification:** **leaf** (0 callees).
5. **Callers (4 / 13 xrefs):** `FUN_0040d3f0` (vec3), `FUN_00416260` (quat ±double-cover), `FUN_0076e5e0` (skip normalize when `lenSq≈1`, eps bits `0x358637BD` ≈ **1e-6**), `FUN_0076f240`.
6. **Name:** `Math_FloatNearlyEqual_AbsRel` (Ghidra `FUN_0040d450`).
7. **Decompile ≡ bytes** for CF (live 2026-07-29 ≡ raw 2026-07-23).

### Gaps

- Product English / Torque original name.  
- Runtime FPU CW / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0040d450_Math_FloatNearlyEqual_AbsRel.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0040d450_Math_FloatNearlyEqual_AbsRel.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0040d450_FUN_0040d450.md` |
| Annotated | `docs/reconstruction/raw/aa_0040d450_FUN_0040d450.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Math_FloatNearlyEqual_AbsRel.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0040d450.cpp` |
| Function | `docs/reconstruction/functions/aa_0040d450_FUN_0040d450.md` |
| Function named | `docs/reconstruction/functions/aa_0040d450_Math_FloatNearlyEqual_AbsRel.md` |
| Scratch | `docs/reconstruction/tmp/a_0040d450.md` |

---

## VA `0x0077d520` — sealed facts

1. **Body:** `0x0077d520`–`0x0077d952` (**1074 B** exclusive end; frame `SUB/ADD ESP,0x154`).
2. **ABI:** **no formals**; **void**; plain `RET` after callee-saved pops.
3. **Once-init:** stores `DAT_00d17a28 = 1` at entry (`C6 05 28 7A D1 00 01`). Callers gate on `==0`.
4. **Callers (2):** `BitStream_writeString` (`FUN_0077d960`), `BitStream_readString` (`FUN_0077daf0`).
5. **Callees:** `FUN_00433c00`, `FUN_00433ba0`×2, `operator_new[]`, `operator_delete[]`, `malloc`, `free`, `FUN_0077d440`.
6. **Data:**
   - `DAT_00a1ea68` — static `uint32 freq[256]` seed (`read_memory` sampled).
   - `DAT_00d1eabc` — alphabet, stride **0xC** (weight, bitlen@+4, char@+5, code@+8).
   - `DAT_00d1eab0` — tree nodes, stride **8** (weight, left short@+4, right short@+6).
7. **CF stages:** ensure alphabet 0x100 → seed leaves `weight=freq+1` → worklist merge two-lowest → root at tree[0] → `FUN_0077d440` assigns codes → destroy scratch BitStream object.
8. **Name:** `BitStream_HuffmanBuildTables` (Ghidra `FUN_0077d520`; already referenced from W21-C write/read duals).
9. **Decompile ≡ bytes** for CF (live 2026-07-29 ≡ raw 2026-07-23).

### Gaps

- Product English inside TNL.  
- Nested container helpers `FUN_00433ba0` / `FUN_00433c00` (not OWN).  
- Runtime post-build table dump bit-exact — open.  
- Signed leaf-index div edge detail Medium-High residual.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0077d520_BitStream_HuffmanBuildTables.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0077d520_BitStream_HuffmanBuildTables.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0077d520_FUN_0077d520.md` |
| Annotated | `docs/reconstruction/raw/aa_0077d520_FUN_0077d520.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/BitStream_HuffmanBuildTables.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0077d520.cpp` |
| Function | `docs/reconstruction/functions/aa_0077d520_FUN_0077d520.md` |
| Function named | `docs/reconstruction/functions/aa_0077d520_BitStream_HuffmanBuildTables.md` |
| Scratch | `docs/reconstruction/tmp/a_0077d520.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0040d450` | Prefer dual abs+rel nearness for client math parity (vec/quat equality, normalize skip). Do not replace with pure `|a-b|<eps` when both tols matter. Common eps ~**1e-6** (`0x358637BD`). |
| `0077d520` | BitStream string codec requires identical Huffman tables. Port must use same `DAT_00a1ea68` freqs + same build, or hardcode matching alphabet codes. Closes residual left open by W21-C write/read duals. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers/callees).  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.
