# Dual A/B report — W27-G OWN `aa_004c4440` + `aa_004c4620`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W27-G  
**Scope:** VAs `0x004c4440`, `0x004c4620` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` (+ xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave27_partition_map.md`

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004c4440` Object_ResolveStoredTFID_Vtbl1dc_Inferred | **accept** — valid-TFID resolve + vtbl+0x1dc CF/ABI sealed |
| `aa_004c4620` Object_PhysModeFromStoredTFID | **accept** — mode leaf 0xB vs 10 CF/ABI sealed |

---

## VA `0x004c4440` — sealed facts

1. **Body:** `0x004c4440`–`0x004c44bc` (**125 B**; pad `CC` after `RET`).
2. **ABI:** **thiscall**; ECX = object; **0** stack formals; **EAX** = 0 \| vtbl+0x1dc result; epilogue `POP EDI; POP ESI; POP EBX; ADD ESP,0x10; RET`.
3. **Semantics:** If TFID at `this+0x108` is **not** invalid (`(lo&hi)==~0 && (char)w2==0`), copy `TFID_16`, rebuild resolve ctx (`+0xA8`/`+0xE4E8`), call `Object_ResolveFromTFID`, then `obj->vtbl[+0x1dc]()`; return nonzero result else 0.
4. **Classification:** worker (1 callee).
5. **Callers:** none static CALL; DATA xrefs `0x009cbf30`, `0x009cfe50`.
6. **Name:** `Object_ResolveStoredTFID_Vtbl1dc_Inferred` (Ghidra `FUN_004c4440`); `_Inferred` for product role of +0x1dc.
7. **Decompile ≡ bytes** for CF (live 2026-07-29 ≡ raw 2026-07-23). Manager ECX rebuild present in bytes (decompiler surface omits — known `Object_ResolveFromTFID` residual).

### Gaps

- Product English for vtbl **+0x1dc** return.  
- Resolve ctx / host product type at `+0xE4E8`.  
- Owning class of DATA vtables.  
- Runtime / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004c4440_Object_ResolveStoredTFID_Vtbl1dc_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_004c4440_Object_ResolveStoredTFID_Vtbl1dc_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004c4440_FUN_004c4440.md` |
| Annotated | `docs/reconstruction/raw/aa_004c4440_FUN_004c4440.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_ResolveStoredTFID_Vtbl1dc_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004c4440.cpp` |
| Function | `docs/reconstruction/functions/aa_004c4440_FUN_004c4440.md` |
| Function named | `docs/reconstruction/functions/aa_004c4440_Object_ResolveStoredTFID_Vtbl1dc_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_004c4440.md` |

---

## VA `0x004c4620` — sealed facts

1. **Body:** `0x004c4620`–`0x004c4658` (**57 B**; pad `CC` after).
2. **ABI:** **thiscall**; ECX = object; **0** stack formals; **EAX** = **0xB** \| **10**; epilogue `MOV EAX,imm; ADD ESP,0x10; RET`.
3. **Semantics:** Invalid TFID → return **0xB**; else return **10**. Leaf (no CALL, no store).
4. **Classification:** leaf.
5. **Callers:** none static CALL; DATA xref `0x009cbe8c`.
6. **Name:** `Object_PhysModeFromStoredTFID` (Ghidra `FUN_004c4620`); predicate family with dual-sealed `Object_SetTFID_ApplyPhysMode_Rebind`.
7. **Decompile ≡ raw** for CF (live 2026-07-29 ≡ 2026-07-23); no residual.

### Gaps

- Product enum names for modes **10** / **0xB**.  
- Owning class of DATA vtable.  
- Runtime / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004c4620_Object_PhysModeFromStoredTFID.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_004c4620_Object_PhysModeFromStoredTFID.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004c4620_FUN_004c4620.md` |
| Annotated | `docs/reconstruction/raw/aa_004c4620_FUN_004c4620.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_PhysModeFromStoredTFID.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004c4620.cpp` |
| Function | `docs/reconstruction/functions/aa_004c4620_FUN_004c4620.md` |
| Function named | `docs/reconstruction/functions/aa_004c4620_Object_PhysModeFromStoredTFID.md` |
| Scratch | `docs/reconstruction/tmp/a_004c4620.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004c4440` | Resolving object identity for a related entity: only when TFID assigned; must pass manager resolve ctx (not just TFID pointer). Return is **vtbl+0x1dc** result, not necessarily the resolved object*. |
| `004c4620` | Phys mode oracle for stored TFID: **0xB** unassigned vs **10** assigned. Keep in lockstep with `Object_SetTFID_ApplyPhysMode_Rebind` when writing `phys+0x28`. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ xrefs).  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names: TFID field names from Ghidra type; resolve name from dual-sealed callee; mode constants from bytes; `_Inferred` only where virtual product English residual.
