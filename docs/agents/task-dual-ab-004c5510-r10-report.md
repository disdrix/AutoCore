# Dual A/B report — R10-029 OWN `aa_004c5510`

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual residual wave R10-029  
**Scope:** VA `0x004c5510` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledgers; other VAs as write targets.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_by_address` + `get_function_xrefs` + `get_function_callers` + `get_assembly_context` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** residual dual of dualed parent `0x005194f0` (skills-abilities residual label; product is gfx).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004c5510` Object_ApplyPrimaryAndLocalMaterialBanks_Inferred | **accept-with-gaps** — thiscall MI subobject, Path A primary bank apply + Path B local Mat* bind, callees/offsets/adjustor entry sealed; product class / runtime open |

**Terminal:** false (partial — runtime/diff open; not reject).

---

## VA `0x004c5510` — sealed facts

1. **Body:** `0x004c5510`–`0x004c555d` inclusive (**78 B** / `0x4E`; pad `CC×2` then next @ `0x004c5560`). Last insn `RET` (`C3`).
2. **ABI:**  
   - `__thiscall` ECX = MI **subobject** this → ESI.  
   - No stack formals; void; bare `RET`.  
   - Preserves ECX (`PUSH ECX` / `POP ECX`).  
   - Entry via **JMP adjustors** only (`0x004cc9f3`, `0x0053bcf9`) — Ghidra callers empty.
3. **Path A (primary bank):**  
   - `vbptr = *(this-0x4FC)`; `primary = this-0x4FC + *(vbptr+4)`.  
   - `CALL Object_ApplyMaterialBank_Inferred` (`0x0051b310`) with ECX=primary.  
   - Decompiler omits this rewrite — **bytes win**.
4. **Path B (local bank):**  
   - host `*(this-0x27C)`; header `this-0x20C`; begin `*(this-0x208)`; end `*(header+8)`.  
   - count `(end-begin)>>4` (stride `0x10`).  
   - If host && begin && count: `FUN_005194f0(host, header)` cdecl + `ADD ESP,8`.  
   - Binder is dualed `Gfx_BindMatDiffuseAmbientEmissive_Inferred` (MatDiffuse/Ambient/Emissive).
5. **Classification:** worker (virtual MI method).
6. **Name:** `Object_ApplyPrimaryAndLocalMaterialBanks_Inferred` (Ghidra `FUN_004c5510`; **Inferred** from dualed callees + dual-path CF). Reject skill-cast / bare permanent FUN / merge-with-`0051b310`.
7. **Decompile ≡ raw scaffold CF**; **bytes win** on Path A this-adjust and MI entry model.

### Gaps

- Product/RTTI class of MI subobject owning negative offsets.  
- vbtable vs custom base-pointer table at `-0x4FC` (usage matches slot+4 delta).  
- When Path B host/bank populated vs Path A-only.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004c5510_Object_ApplyPrimaryAndLocalMaterialBanks_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004c5510_Object_ApplyPrimaryAndLocalMaterialBanks_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004c5510_FUN_004c5510.md` |
| Annotated | `docs/reconstruction/raw/aa_004c5510_FUN_004c5510.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_ApplyPrimaryAndLocalMaterialBanks_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004c5510.cpp` |
| Function FUN | `docs/reconstruction/functions/aa_004c5510_FUN_004c5510.md` |
| Function named | `docs/reconstruction/functions/aa_004c5510_Object_ApplyPrimaryAndLocalMaterialBanks_Inferred.md` |
| Report | `docs/agents/task-dual-ab-004c5510-r10-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004c5510` | Port as **MI thiscall void** on subobject this: always apply primary material bank after base adjust from `this-0x4FC`; optionally bind local Mat* bank via host `this-0x27C` + header `this-0x20C`. Do **not** treat Ghidra `FUN_0051b310()` as no-adjust call. Do **not** implement as skill cast. Reuse dualed callees `Object_ApplyMaterialBank_Inferred` + `Gfx_BindMatDiffuseAmbientEmissive_Inferred`. |

Shared context (not owned):

| VA | Role |
|---|---|
| `0x0051b310` | `Object_ApplyMaterialBank_Inferred` (Path A) |
| `0x005194f0` | `Gfx_BindMatDiffuseAmbientEmissive_Inferred` (Path B / parent dual) |
| `0x004cc9f0` | vbtable adjustor JMP island |
| `0x0053bcf0` | MI `−0x8A0` + vbtable adjustor JMP island |

Together this seals the residual **caller/orchestrator** of the dualed material-bank apply + Mat* binder under R10-029.

---

## Process

- OWN VA only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze + disassemble_function + read_memory + callers/xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Raw append-only re-verify (no wipe).  
- No invented product plates; `_Inferred` name only.  
- Terminal false.
