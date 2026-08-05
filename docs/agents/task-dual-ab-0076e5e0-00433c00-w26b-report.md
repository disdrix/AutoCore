# Dual A/B report — W26-B OWN `aa_0076e5e0` + `aa_00433c00`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W26-B  
**Scope:** VAs `0x0076e5e0`, `0x00433c00` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` (+ callers/callees). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave26_partition_map.md`

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0076e5e0` Math_QuatNormalize | **accept** — near-zero + near-unit skip CF, cdecl ABI, constants sealed |
| `aa_00433c00` BitStream_HuffmanAlphabetEnsureCapacity | **accept** — capacity grow CF/ABI/stride 0xC + exclusive HuffmanBuildTables caller sealed |

---

## VA `0x0076e5e0` — sealed facts

1. **Body:** `0x0076e5e0`–`0x0076e6ab` (**203 B**; pad `CC` after last RET).
2. **ABI:** **cdecl**; stack `float *out`, `float *in` (quat ×4); **EAX** = `out`; `PUSH ESI` / `POP ESI; RET`.
3. **Semantics:**
   - `lenSq = in·in` (4 components).
   - If `−1e-6 < lenSq < +1e-6` → return `out` unchanged.
   - Else if `Math_FloatNearlyEqual_AbsRel(lenSq, 1.0f, 1e-6, 1e-6)` → copy `in→out` when pointers differ; else no-op.
   - Else `out[i] *= (1/sqrt(lenSq))` (FPU `fsqrt` + `g_flOne`).
4. **Constants (`read_memory`):** `_DAT_00a240ec` = `0x358637BD` (+1e-6); `DAT_00aaa640` = `0xB58637BD` (−1e-6); tol imm `0x358637BD`; one `0x3F800000` / `g_flOne@0x00a0f2a0`.
5. **Callees:** `FUN_0040d450` only (+ FPU).
6. **Callers (6 / 11 xrefs):** `FUN_004b1100`, `FUN_0076eb00`, `FUN_00833640`, `FUN_0083a880`, `FUN_0088d670`, `FUN_0088e300`.
7. **Name:** `Math_QuatNormalize` (Ghidra `FUN_0076e5e0`).
8. **Decompile ≡ bytes** for CF (live 2026-07-29 ≡ raw 2026-07-23).

### Gaps

- Product English / Torque original name.  
- Runtime FPU CW / bit-exact.  
- Out-of-place non-unit path scales `out` without copy-from-`in` first (callers typically alias).

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0076e5e0_Math_QuatNormalize.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0076e5e0_Math_QuatNormalize.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0076e5e0_FUN_0076e5e0.md` |
| Annotated | `docs/reconstruction/raw/aa_0076e5e0_FUN_0076e5e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Math_QuatNormalize.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0076e5e0.cpp` |
| Function | `docs/reconstruction/functions/aa_0076e5e0_FUN_0076e5e0.md` |
| Function named | `docs/reconstruction/functions/aa_0076e5e0_Math_QuatNormalize.md` |
| Scratch | `docs/reconstruction/tmp/a_0076e5e0.md` |

---

## VA `0x00433c00` — sealed facts

1. **Body:** `0x00433c00`–`0x00433c53` (**83 B**; pad `CC` after last RET).
2. **ABI:** **ECX** = container base; **EAX** = requested min capacity (`in_EAX`); **void**; plain `RET`.
3. **Container @ `0x00d1eab4`:** size@+0 (`DAT_00d1eab4`), capacity@+4, data@+8 (`DAT_00d1eabc`); **elem stride 0xC**.
4. **Growth:** if `capacity < need`: `newCap = need + (0x10 − (need & 0xF))`; `malloc(newCap * 0xC)`; `FUN_00433ca0` copies live elems; `free(old)`; commit data + capacity.
5. **Callers (1):** `BitStream_HuffmanBuildTables` (`FUN_0077d520`) only — `mov eax,0x100; mov ecx,0x00d1eab4`.
6. **Callees:** `malloc`, `free`, `FUN_00433ca0`.
7. **Name:** `BitStream_HuffmanAlphabetEnsureCapacity` (Ghidra `FUN_00433c00`).
8. **Decompile ≡ bytes** for CF (live 2026-07-29 ≡ raw 2026-07-23).

### Gaps

- Product / TNL dynarray template English.  
- Full formal surface of `FUN_00433ca0` (copy sibling; Medium residual).  
- Sibling tree ensure `FUN_00433ba0` is OWN W26-C (not dualed here).  
- `malloc` null not checked (matches binary).

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00433c00_BitStream_HuffmanAlphabetEnsureCapacity.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_00433c00_BitStream_HuffmanAlphabetEnsureCapacity.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00433c00_FUN_00433c00.md` |
| Annotated | `docs/reconstruction/raw/aa_00433c00_FUN_00433c00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/BitStream_HuffmanAlphabetEnsureCapacity.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00433c00.cpp` |
| Function | `docs/reconstruction/functions/aa_00433c00_FUN_00433c00.md` |
| Function named | `docs/reconstruction/functions/aa_00433c00_BitStream_HuffmanAlphabetEnsureCapacity.md` |
| Scratch | `docs/reconstruction/tmp/a_00433c00.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0076e5e0` | Client quat normalize must honor **near-zero** open interval and **abs+rel** near-unit skip (tols **1e-6**, peer `Math_FloatNearlyEqual_AbsRel`). Do not always force `q /= |q|`. Prefer `out==in` aliasing. |
| `00433c00` | Huffman alphabet buffer must be capacity-safe for 256 entries (stride **0xC**). Port may preallocate ≥ **0x110** slots and treat this as no-op, or implement identical grow formula before seeding leaves. Closes W25-T residual on nested `FUN_00433c00`. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers/callees). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Avoided bare `undefined4` in clean (`uint32_t` / typed container).  
- No invented product strings; names are role-evidence inferences.
