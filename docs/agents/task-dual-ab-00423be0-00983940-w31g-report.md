# Dual A/B report — W31-G OWN `aa_00423be0` + `aa_00983940`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W31-G  
**Scope:** VAs `0x00423be0`, `0x00983940` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `read_memory` + `analyze_function_complete` (no disasm dump). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave31_partition_map.md` (W31-G).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00423be0` AssManager_ResolverA_Ctor_Inferred | **accept-with-gaps** — ABI/layout/vtbl/CS/ready + sole AssManager caller sealed; nested member + product English open |
| `aa_00983940` AssResolverCore_Ctor_Inferred | **accept-with-gaps** — ABI/layout/triple/CS/ready + global clears (WORD@58) + callers sealed; nested member + global product meaning open |

---

## VA `0x00423be0` — sealed facts

1. **Body:** `0x00423be0`–`0x00423c35` (**86 B** / `0x56`; pad `CC` then next @ `0x00423c40`).
2. **ABI:** stack **`this*`** placement ctor; **`RET 0x4`**; returns **`this` in EAX**. Not ECX-thiscall.
3. **Semantics:**
   - Zero `+0x04`; install **`PTR_FUN_00a95acc`** @ `+0x00`.
   - Nested **`FUN_00423cf0(this+0x08)`**.
   - **`InitializeCriticalSection(this+0x30)`** (IAT `0x009c61ec`).
   - Ready **`*(u8*)(this+0x48)=1`**.
4. **Size:** caller `operator_new(0x4c)` → AssManager **resolver A**.
5. **Classification:** worker.
6. **Callers (1):** `FUN_007b75b0` @ `0x007b776c`.
7. **Callees:** `FUN_00423cf0`, `InitializeCriticalSection`.
8. **Name:** `AssManager_ResolverA_Ctor_Inferred` (Ghidra `FUN_00423be0`; **Inferred**). Reject scaffold `Named_CalleeOf_Named_assManager_*`.
9. **Decompile ≡ bytes** (dword indices map correctly to +0x30 / +0x48). Full hex: raw W31-G append.

### Gaps

- Product/PDB class English for `PTR_FUN_00a95acc`.  
- Nested `FUN_00423cf0` product type (not owned).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00423be0_AssManager_ResolverA_Ctor_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00423be0_AssManager_ResolverA_Ctor_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00423be0_FUN_00423be0.md` |
| Annotated | `docs/reconstruction/raw/aa_00423be0_FUN_00423be0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AssManager_ResolverA_Ctor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00423be0.cpp` |
| Function | `docs/reconstruction/functions/aa_00423be0_FUN_00423be0.md` |
| Function named | `docs/reconstruction/functions/aa_00423be0_AssManager_ResolverA_Ctor_Inferred.md` |

---

## VA `0x00983940` — sealed facts

1. **Body:** `0x00983940`–`0x009839af` (**112 B** / `0x70`; next `FUN_009839b0`).
2. **ABI:** stack **`this*`** placement ctor; **`RET 0x4`**; returns **`this` in EAX**. Not ECX-thiscall.
3. **Semantics:**
   - Nested **`FUN_00469db0(this)`** (twin shape of `FUN_00423cf0`).
   - Zero **`+0x2c/+0x30/+0x34`**.
   - **`InitializeCriticalSection(this+0x38)`**; ready **`*(u8*)(this+0x50)=1`**.
   - Clear **`DAT_00d1ef44/48/50/5c`** (DWORD 0); **`DAT_00d1ef58`** (**WORD** 0 — bytes win).
4. **Does not** install vtbl — AssManager B parent sets **`PTR_FUN_00aa1f1c`** @ mem+0 then calls this on **mem+8** after `new(0x5c)`.
5. **Classification:** worker (ctor with process-global side-effects).
6. **Callers (3):** `FUN_007b75b0` @ `0x007b780f`; `FUN_00985010` @ `0x00985051`, `0x0098507b`.
7. **Callees:** `FUN_00469db0`, `InitializeCriticalSection`.
8. **Name:** `AssResolverCore_Ctor_Inferred` (Ghidra `FUN_00983940`; **Inferred**).
9. **Decompile ≡ bytes** for CF; **bytes win** on `DAT_00d1ef58` width. Full hex: raw W31-G append.

### Gaps

- Product English for core / outer shell `00aa1f1c`.  
- Meaning of zeroed globals and triple at +0x2c.  
- Nested `FUN_00469db0` product type.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00983940_AssResolverCore_Ctor_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00983940_AssResolverCore_Ctor_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00983940_FUN_00983940.md` |
| Annotated | `docs/reconstruction/raw/aa_00983940_FUN_00983940.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AssResolverCore_Ctor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00983940.cpp` |
| Function | `docs/reconstruction/functions/aa_00983940_FUN_00983940.md` |
| Function named | `docs/reconstruction/functions/aa_00983940_AssResolverCore_Ctor_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00423be0` | Port as **placement ctor** (stack this, RET 4). Alloc **0x4c**. vtbl `00a95acc`; member @+0x08; CS @+0x30; ready @+0x48. Pair with AssManager ReleaseOwnedResolvers for `self+0x08`. |
| `00983940` | Port as **placement ctor** with **global clears**. AssManager B: outer shell vtbl `00aa1f1c` then ctor(mem+8). Preserve **WORD** store to `DAT_00d1ef58`. Also used by effect-probe path `FUN_00985010`. |
| Pair with | W30-D `AssManager_InitPrecompileAndResolvers`; W29-D `AssManager_ReleaseOwnedResolvers`; nested `FUN_00423cf0` / `FUN_00469db0` residuals; W31-H `FUN_00984ee0`. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; structural `_Inferred` names only.  
- Avoided bare `undefined4` in clean (`uint32_t` / explicit structs).  
- Rejected scaffold `Named_CalleeOf_Named_assManager_*` as product alias.
