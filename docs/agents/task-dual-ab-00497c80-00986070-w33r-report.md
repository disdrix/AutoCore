# Dual A/B report — W33-R OWN `aa_00497c80` + `aa_00986070`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W33-R  
**Scope:** VAs `0x00497c80`, `0x00986070` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `read_memory` + xrefs/callers (+ callee decompiles). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave33_partition_map.md` (W33-R).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00497c80` ListTrackedCtx_ClearDestroyAndReset_Inferred | **accept-with-gaps** — thiscall/113 B/loop free-all/bank zero/grid +0xB8 reset/return 1 sealed; product demangle + entry type + flag polarity open |
| `aa_00986070` PoolHost_Acquire0x40_Inferred | **accept-with-gaps** — EBX pool/181 B/pop-or-new(0x40)/track push/sole caller sealed; product demangle + release path + track-vector English open |

---

## VA `0x00497c80` — sealed facts

1. **Body:** `0x00497c80`–`0x00497cf0` inclusive (**113 B** / `0x71`); pad `CC` @ `0x00497cf1+`.
2. **ABI:** **__thiscall**; ECX=self; bare **`C3`**; **AL=1** (`B0 01`).
3. **Semantics:** clear-destroy-reset of **0xC8** ListTracked ctx:
   - While count@`+0x10` ≥ 1: decrement; if bank[`count`] non-null → `FUN_00497900` + `operator_delete`.
   - `FUN_00788db0(this+0x14, 0xA0)` zero bank.
   - `+4=+8=+0xC=0`; `FUN_007874b0(this+0xB8, 0, 0)` free/zero grid; `*this=1`; return 1.
4. **Decompiler bug:** loop `break` + non-return `operator_delete` **wrong** — bytes continue loop after delete.
5. **Classification:** worker (reset).
6. **Callers / xrefs:** **6** — `FUN_0048f2d0`, `FUN_00498260`, `FUN_004982d0`, `FUN_004982f0`, `FUN_004dfcc0`, `FUN_004deb20`.
7. **Callees:** `FUN_00497900`, `operator_delete`, `FUN_00788db0`, `FUN_007874b0`.
8. **Related:** ctor `ListTrackedCtx_Ctor_Inferred` (`0x00497920`, W32-P); ApplyDefaultScalars (`0x0048f2d0`, W32-Q).
9. **Name:** `ListTrackedCtx_ClearDestroyAndReset_Inferred` (Ghidra `FUN_00497c80`; **Inferred** structural). Reject scaffold NDRiver alias.
10. **Decompile ≡ raw CF skeleton**; body hex seals ABI/loop/grid thiscall.

### Gaps

- Product class demangle / entry type English.  
- Flag@+0 polarity.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00497c80_ListTrackedCtx_ClearDestroyAndReset_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00497c80_ListTrackedCtx_ClearDestroyAndReset_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00497c80_FUN_00497c80.md` |
| Annotated | `docs/reconstruction/raw/aa_00497c80_FUN_00497c80.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ListTrackedCtx_ClearDestroyAndReset_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00497c80.cpp` |
| Function | `docs/reconstruction/functions/aa_00497c80_FUN_00497c80.md` |
| Function named | `docs/reconstruction/functions/aa_00497c80_ListTrackedCtx_ClearDestroyAndReset_Inferred.md` |

---

## VA `0x00986070` — sealed facts

1. **Body:** `0x00986070`–`0x00986124` inclusive (**181 B** / `0xB5`); pad `CC` @ `0x00986125+`.
2. **ABI:** no stack formals; **EBX = pool host** (`*DAT_00d1f624`); bare **`C3`**; **EAX = obj\*** (0x40) or 0.
3. **SEH:** `LAB_009af9d3`.
4. **Semantics:** pool acquire:
   - If freelist @`+0x14/+0x18` empty → `operator_new(0x40)` + `FUN_0074e380` (or 0).
   - Else pop last; `FUN_00456780(size-1, host+0x10)` shrink freelist.
   - Always `FUN_004406e0` push result onto track vector @`+4/+8/+0xC`.
5. **Decompiler bug:** both shrink branches shown as `FUN_00456780(0)` — non-empty path uses **size-1**.
6. **Classification:** worker (pool acquire).
7. **Callers / xrefs:** **1** — `FUN_00756320` / `HostBase_EnsureAuxPtrs_Inferred` @ `0x00756352`.
8. **Callees:** `operator_new`, `FUN_0074e380`, `FUN_00456780`, `FUN_004406e0`.
9. **Related:** HostBase ensure (`0x00756320`, W32-Q); 0x40 ctor → `FUN_0043fdf0` → `StdList_AllocSentinel_0xC` (`0x004933f0`).
10. **Name:** `PoolHost_Acquire0x40_Inferred` (Ghidra `FUN_00986070`; **Inferred** structural). Reject scaffold VOG_DEBUG alias.
11. **Decompile ≡ raw CF skeleton**; body hex seals EBX/pop-or-new/push/bounds.

### Gaps

- Product pool/element demangle.  
- Track-vector English role; freelist release path (other VA).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00986070_PoolHost_Acquire0x40_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00986070_PoolHost_Acquire0x40_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00986070_FUN_00986070.md` |
| Annotated | `docs/reconstruction/raw/aa_00986070_FUN_00986070.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/PoolHost_Acquire0x40_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00986070.cpp` |
| Function | `docs/reconstruction/functions/aa_00986070_FUN_00986070.md` |
| Function named | `docs/reconstruction/functions/aa_00986070_PoolHost_Acquire0x40_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00497c80` | Port as **ListTrackedCtx clear-destroy-reset**: free each non-null bank entry (`FUN_00497900` + delete), zero 0xA0 bank, zero +4/+8/+0xC, reset grid@+0xB8 to 0×0, flag=1, return 1. Do **not** free the ctx or clear `DAT_00b035cc`. Do **not** trust decompiler non-return on delete. Callers may re-set capacity/dims after. |
| `00986070` | Port as **pool acquire** on `*DAT_00d1f624`: freelist pop or `new(0x40)+ctor`, always track-push @pool+4, return obj\*. Retail needs **EBX=pool**. Do **not** treat as freelist release. HostBase stores at `+4` only when `(flags & 1)`. |
| Pair with | Ctor `0x00497920` (W32-P); ApplyDefaultScalars `0x0048f2d0` (W32-Q); HostBase ensure `0x00756320` (W32-Q); 0x40 ctor `0x0074e380`; sentinel factory `0x004933f0`. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ xrefs / callers / callee decompiles). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` structural names only.  
- Pattern: ListTrackedCtx clear-reset sibling of W32-P ctor; pool acquire for HostBase aux.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
