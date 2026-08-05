# Dual A/B report — W28-L OWN `aa_004c3c80` + `aa_005cc450`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W28-L  
**Scope:** VAs `0x004c3c80`, `0x005cc450` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `read_memory` (+ `get_function_by_address` / xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave28_partition_map.md`

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004c3c80` Object_SetMode278_SelectFromTFID228_Inferred | **accept** — thiscall/`ret 4` + mode gate + TFID resolve/select CF sealed |
| `aa_005cc450` CVOGHBAI_InvokeVtbl4c_AimOffset_Flag1 | **accept** — 12 B thiscall thunk `vtbl+0x4c(this+0x40,1)` sealed |

---

## VA `0x004c3c80` — sealed facts

1. **Body:** `0x004c3c80`–`0x004c3d17` (**151 B** / `0x97`; pad `CC` after `RET 4`).
2. **ABI:** **thiscall**; ECX = object; stack `char mode`; epilogue `POP EDI; POP ESI; ADD ESP,0x10; RET 4`.
3. **Semantics:** Always `this+0x278 = mode`. If `mode==1`: copy `TFID_16` from `this+0x228`, rebuild resolve manager ECX (`+0xA8`/`+0xE4E8`), `Object_ResolveFromTFID` @ `0x004bb950`; require `resolved+0xA0`; MI self `vtbl+0x298(candidate)`; `Object_SetSelectedTarget` @ `0x005172d0`.
4. **Classification:** worker (2 direct callees + 1 virtual).
5. **Callers:** `FUN_005ccff0` (mode 0 on resolve fail); `CVOGHBAI_ProfileType4_DoLogic_Inferred` (owner, 0); `FUN_00615020` (mode 1 skill-spawn path).
6. **Name:** `Object_SetMode278_SelectFromTFID228_Inferred` (Ghidra `FUN_004c3c80`); `_Inferred` for product mode/TFID English.
7. **Decompile ≡ bytes** for CF; residuals closed: manager ECX omitted on surface; SetSelectedTarget arity is **1** stack formal (not 3).

### Gaps

- Product English for mode values at **+0x278** (AI plates also use 2/3 death/respawn).  
- Product name of TFID block at **+0x228**.  
- Product English for **vtbl+0x298**.  
- Runtime / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004c3c80_Object_SetMode278_SelectFromTFID228_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_004c3c80_Object_SetMode278_SelectFromTFID228_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004c3c80_FUN_004c3c80.md` |
| Annotated | `docs/reconstruction/raw/aa_004c3c80_FUN_004c3c80.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_SetMode278_SelectFromTFID228_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004c3c80.cpp` |
| Function | `docs/reconstruction/functions/aa_004c3c80_FUN_004c3c80.md` |
| Function named | `docs/reconstruction/functions/aa_004c3c80_Object_SetMode278_SelectFromTFID228_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_004c3c80.md` |

---

## VA `0x005cc450` — sealed facts

1. **Body:** `0x005cc450`–`0x005cc45b` (**12 B**; pad `CC` after).
2. **ABI:** **thiscall**; ECX = HBAI; **0** stack formals; plain `RET` (`C3`).
3. **Semantics:** `this->vtbl[+0x4c](this+0x40, 1)`. `this+0x40` = aim-offset vec4 (sibling `CVOGHBAI_UpdateAimOffset_Inferred`).
4. **Classification:** leaf thunk (single indirect CALL).
5. **Callers:** `CVOGHBAIDriver_DoLogic` ×3; ProfileType4 / CreatureBase DoLogic fallthroughs.
6. **Name:** `CVOGHBAI_InvokeVtbl4c_AimOffset_Flag1` (Ghidra `FUN_005cc450`).
7. **Decompile ≡ bytes** for CF + ABI; surface `__fastcall` ≡ ECX this.

### Gaps

- Product English for **vtbl+0x4c**.  
- Semantic of flag **1** vs scalar formals at other call sites of same slot.  
- Runtime / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005cc450_CVOGHBAI_InvokeVtbl4c_AimOffset_Flag1.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_005cc450_CVOGHBAI_InvokeVtbl4c_AimOffset_Flag1.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_005cc450_FUN_005cc450.md` |
| Annotated | `docs/reconstruction/raw/aa_005cc450_FUN_005cc450.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBAI_InvokeVtbl4c_AimOffset_Flag1.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005cc450.cpp` |
| Function | `docs/reconstruction/functions/aa_005cc450_FUN_005cc450.md` |
| Function named | `docs/reconstruction/functions/aa_005cc450_CVOGHBAI_InvokeVtbl4c_AimOffset_Flag1.md` |
| Scratch | `docs/reconstruction/tmp/a_005cc450.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004c3c80` | Mode write is unconditional; target promote only on **mode==1**. Candidate is **`resolved+0xA0`**, not the resolved object. Must pass resolve manager ctx; honor **vtbl+0x298** gate; preserve **`ret 4`**. |
| `005cc450` | Path-mode fallthrough: re-dispatch aim buffer via **vtbl+0x4c** with flag **1**. Do not conflate with scalar destination packing of the same virtual on other DoLogic arms. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory (+ function bounds / xrefs). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names: TFID/mode offsets from bytes; callees from dual-sealed VAs; aim field from sibling dual; `_Inferred` only where product English residual.
