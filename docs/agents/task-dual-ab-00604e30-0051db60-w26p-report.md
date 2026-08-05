# Dual A/B report — W26-P OWN `aa_00604e30` + `aa_0051db60`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W26-P  
**Scope:** VAs `0x00604e30`, `0x0051db60` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` (+ callers/callees). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00604e30` CNDHash_ValueClearOwnedPtrs | **accept-with-gaps** — 4-slot nested value clear CF/ABI + 2 callers sealed |
| `aa_0051db60` CNDHash_Ctor_009ce1a0 | **accept-with-gaps** — vtbl/field init + AllocBucketTable handoff + static caller sealed |

---

## VA `0x00604e30` — sealed facts

1. **Body:** `0x00604e30`–`0x00604e84` (**85 B** / `0x55`; pad `CC` after last RET).
2. **ABI:** MSVC **`__thiscall`** (Ghidra `__fastcall`); ECX = value\*; plain `RET` (`5F 5E C3`).
3. **Semantics:** For offs `+4`, `+8`, `+0xC`, `+0x10`: if ptr non-null → `operator_delete` (cdecl, **returns**); always zero slot. Does **not** free value; does **not** touch `+0`.
4. **Classification:** worker; sole callee `operator_delete` ×4.
5. **Callers (2):** `CNDHash_ReclaimAll_ValueOwning_009ce0a8` (`FUN_0051bfb0`) @ `0x0051bfe4`; `FUN_0051bd90` @ `0x0051bda3`.
6. **Name:** `CNDHash_ValueClearOwnedPtrs` (Ghidra `FUN_00604e30`). Reject Named_CalleeOf VOG chain.
7. **Decompile ≡ bytes** for CF (live 2026-07-29 ≡ raw 2026-07-23). Closes W25-F residual nested matrix.

### Gaps

- Product English / medal value type / four pointee types.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00604e30_CNDHash_ValueClearOwnedPtrs.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00604e30_CNDHash_ValueClearOwnedPtrs.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00604e30_FUN_00604e30.md` |
| Annotated | `docs/reconstruction/raw/aa_00604e30_FUN_00604e30.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDHash_ValueClearOwnedPtrs.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00604e30.cpp` |
| Function | `docs/reconstruction/functions/aa_00604e30_FUN_00604e30.md` |
| Function named | `docs/reconstruction/functions/aa_00604e30_CNDHash_ValueClearOwnedPtrs.md` |
| Scratch | `docs/reconstruction/tmp/a_00604e30.md` |

---

## VA `0x0051db60` — sealed facts

1. **Body:** `0x0051db60`–`0x0051dbd2` (**115 B** / `0x73`; pad `CC` after `RET 4`).
2. **ABI:** MSVC **`__thiscall`**; ECX = this; stack **byte log2** (4-byte slot); returns **this** in EAX; **`RET 4`**. SEH `LAB_009a371b`.
3. **Semantics:** Install vtbl **`009ce1a0`**; zero fields; `+0x08 = 1<<log2` (count); `+0x1C = log2`; **`+0x24` not written**; call **`CNDHash_AllocBucketTable_009ce090`** (count→mask + table/sentinels).
4. **Classification:** worker; sole callee `FUN_0051ba40`.
5. **Callers (1 code xref):** static init `@ 0x009c0b57` — `PUSH 2; MOV ECX,0x00b042e0; CALL` (log2=2 → N=4).
6. **Name:** `CNDHash_Ctor_009ce1a0` (Ghidra `FUN_0051db60`). Closes AllocBucketTable residual “ctor FUN_0051db60”.
7. **Decompile ≡ bytes** for CF (live 2026-07-29 ≡ raw 2026-07-23).

### Gaps

- Product English / full vtbl method matrix at `009ce1a0`.  
- Semantic of unwritten `+0x24`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0051db60_CNDHash_Ctor_009ce1a0.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0051db60_CNDHash_Ctor_009ce1a0.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0051db60_FUN_0051db60.md` |
| Annotated | `docs/reconstruction/raw/aa_0051db60_FUN_0051db60.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDHash_Ctor_009ce1a0.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0051db60.cpp` |
| Function | `docs/reconstruction/functions/aa_0051db60_FUN_0051db60.md` |
| Function named | `docs/reconstruction/functions/aa_0051db60_CNDHash_Ctor_009ce1a0.md` |
| Scratch | `docs/reconstruction/tmp/a_0051db60.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00604e30` | Medal (009ce0a8) hash values need nested free of four owned ptrs before free(value). Port as clear-owned-fields helper; do **not** omit when reclaiming this stamp. Plain owning stamps skip it. |
| `0051db60` | Ctor for medal CNDHash vtbl `009ce1a0`: set count=`1<<log2` + log2 byte, then AllocBucketTable. Port must match field zeros, unwritten `+0x24`, and Alloc post-condition mask=`N-1`. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers/callees).  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.
