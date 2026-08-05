# Dual A/B report — W20-J OWN `aa_00422830` + `aa_0042b980`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W20-J  
**Scope:** VAs `0x00422830`, `0x0042b980` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` (+ callers). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00422830` OleDb_IAccessor_CreateAccessor_FreeBindings_Inferred | **accept-with-gaps** — CreateAccessor + free-loop CF sealed from bytes; product names Probable; decompiler understates body |
| `aa_0042b980` BitStream_writeQuantizedSignedInt | **accept** — sign flag + `(bitCount-1)` magnitude write sealed; ABI EDI/ECX/AL |

---

## VA `0x00422830` — sealed facts

1. **Body:** `0x00422830`–`0x00422879` (74 B to final `RET` @ `0x00422877`).
2. **ABI:** EAX = COM iface*; ECX = cBindings; EDX = bindings base; two stack formals; plain `RET`; return HRESULT in EAX.
3. **CreateAccessor:** `CALL [vtbl+0x10]` with args  
   `(this, flags∈{2,3}, cBindings, bindings, cbRowSize, phAccessor, rgStatus=0)`.
4. **Flags:** `2` if `*(int*)(bindings+0x24)==0`, else `3` (`SETNE` + `LEA ECX,[ECX+ECX+2]`).
5. **Free loop:** if count≠0, for each row: `operator_delete(*(void**)(p+0x14))`, `p += 0x48` (image: `+0x14` then `+0x34`).
6. **Decompiler residual:** collapses args and loop; `operator_delete` noreturn WARNING is **false**.
7. **Callers (2):** `FUN_00421677` @ `0x00421677`, `FUN_004229e0` @ `0x004229e0`.
8. **Name:** `OleDb_IAccessor_CreateAccessor_FreeBindings_Inferred` (Ghidra `FUN_00422830`).

### Gaps

- Product English for flag bit / stack formals / 0x48 binding row typedef.  
- Parent residual arg provenance.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00422830_OleDb_IAccessor_CreateAccessor_FreeBindings_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00422830_OleDb_IAccessor_CreateAccessor_FreeBindings_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00422830_FUN_00422830.md` |
| Annotated | `docs/reconstruction/raw/aa_00422830_FUN_00422830.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/OleDb_IAccessor_CreateAccessor_FreeBindings_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00422830.cpp` |
| Function | `docs/reconstruction/functions/aa_00422830_FUN_00422830.md` |
| Function named | `docs/reconstruction/functions/aa_00422830_OleDb_IAccessor_CreateAccessor_FreeBindings_Inferred.md` |
| Scratch | `tmp/a_00422830.md` |

---

## VA `0x0042b980` — sealed facts

1. **Body:** `0x0042b980`–`0x0042b9cc` (77 B).
2. **ABI:** EDI = BitStream* this; ECX = int value; AL = bitCount; void return.
3. **Algorithm:** `writeFlag(value < 0)`; if neg then `NEG`; `writeBits(bitCount-1, &local)`.
4. **Callees:** `BitStream_writeFlag` @ `0x0042b770`, `BitStream_writeBits` @ `0x0042b4a0` (rel32 sealed).
5. **No write-side magnitude mask** (read sibling `0x0042b9d0` masks).
6. **Sole caller:** `BitStream_writeQuantizedFloat` @ `0x0042b910` (float×max + trunc, then this unit).
7. **Name:** `BitStream_writeQuantizedSignedInt` (Ghidra `FUN_0042b980`).
8. **Decompile ≡ bytes** for control flow; phantoms filled from caller.

### Gaps

- INT_MIN edge documentation only.  
- Live packet differential.  
- Parent `writeQuantizedFloat` dual residual (not owned).

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0042b980_BitStream_writeQuantizedSignedInt.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0042b980_BitStream_writeQuantizedSignedInt.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0042b980_FUN_0042b980.md` |
| Annotated | `docs/reconstruction/raw/aa_0042b980_FUN_0042b980.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/BitStream_writeQuantizedSignedInt.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0042b980.cpp` |
| Function | `docs/reconstruction/functions/aa_0042b980_FUN_0042b980.md` |
| Function named | `docs/reconstruction/functions/aa_0042b980_BitStream_writeQuantizedSignedInt.md` |
| Scratch | `tmp/a_0042b980.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00422830` | Client DB bind helper — only relevant if porting OLE DB client paths; **do not** trust collapsed decompile. Free binding mem always when count≠0. |
| `0042b980` | Network pack path — implement sign bit + `(bitCount-1)` magnitude; keep float quantize in `writeQuantizedFloat` parent; do not mask on write. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory (+ complete analysis / callers).  
- Dual A (fidelity) + B (adversarial) both filed per VA.
