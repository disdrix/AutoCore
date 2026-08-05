# Dual A/B report — W34-D OWN `aa_0044a0d0` + `aa_00436ef0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W34-D  
**Scope:** VAs `0x0044a0d0`, `0x00436ef0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** wave34 (W34-D).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0044a0d0` NestedHashBag_Ctor_Inferred | **accept-with-gaps** — stack self* / RET 4 / 98 B twin bag CF sealed; parent product English open |
| `aa_00436ef0` Mem_FillDwordN_FromSrc_EaxEcxEdx | **accept** — EAX/ECX/EDX register fill leaf + null gate sealed (23 B) |

---

## VA `0x0044a0d0` — sealed facts

1. **Body:** `0x0044a0d0`–`0x0044a131` (**98 B** / `0x62`; pad `CC` @ `0x0044a132`).
2. **ABI:** stack **`self*`**; **`RET 4`**; returns **self in EAX**. Decompiler `undefined FUN_*(void)` incomplete — **bytes win**. **Not** ECX-thiscall.
3. **Semantics (placement ctor):**
   - SEH `LAB_009bd46b`.
   - `CircularSentinel_Alloc0x28_Inferred` (`FUN_00423d60`) → store @ **`self+0x08`**.
   - **`self+0x0c = 0`** (size).
   - `PtrVecShell_InitFill_Inferred` (`FUN_004646e0`) at **`self+0x10`**, count **9**, fill = sentinel*.
   - **`self+0x20 = 1`**, **`self+0x24 = 1`**.
   - `+0x00/+0x04` unwritten.
4. **Classification:** worker — callees sentinel alloc + PtrVec shell init.
5. **Callers (1):** `FUN_0074d750` @ `0x0074d786` — nests bag at outer **`+0x0c`** (`param_1+3`).
6. **Twin CF:** ≡ `AssResolverA_NestedHash_Ctor_Inferred` (`0x00423cf0`) / `AssResolverCore_HeadBag_Ctor_Inferred` (`0x00469db0`).
7. **Name:** `NestedHashBag_Ctor_Inferred` (Ghidra `FUN_0044a0d0`; **Inferred** structural). **Reject** scaffold `Named_CalleeOf_*`.
8. **Decompile ≡ bytes** for stores/call order; **bytes win** on RET 4 / stack self.  
   Full hex: `6aff686bd49b0064a100000000506489250000000051568b742418e8709cfdff89460833c089460c8d4c240451894424148b46086a098d56105289442410e8cda501008b4c2408b8010000008946208946248bc65e64890d0000000083c410c20400`

### Gaps

- Product/PDB English for parent `FUN_0074d750` / vtable `PTR_FUN_00aa05cc`.  
- Flag / unwritten-head field meaning.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0044a0d0_NestedHashBag_Ctor_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0044a0d0_NestedHashBag_Ctor_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0044a0d0_FUN_0044a0d0.md` |
| Annotated | `docs/reconstruction/raw/aa_0044a0d0_FUN_0044a0d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NestedHashBag_Ctor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0044a0d0.cpp` |
| Function | `docs/reconstruction/functions/aa_0044a0d0_FUN_0044a0d0.md` |
| Function named | `docs/reconstruction/functions/aa_0044a0d0_NestedHashBag_Ctor_Inferred.md` |

---

## VA `0x00436ef0` — sealed facts

1. **Body:** `0x00436ef0`–`0x00436f06` (**23 B** / `0x17`; pad `CC` @ `0x00436f07`).
2. **ABI:** register **EAX=dest**, **ECX=count**, **EDX=src***; bare **`RET`**. Decompiler `__fastcall (count, src*)` omits dest formal — **bytes + callers win**.
3. **Semantics:** for each of N slots: if dest non-null then `*dest = *src` (re-read `*EDX`); always advance dest by 1 dword; count--. Zero count early-outs.
4. **Classification:** leaf — 0 callees.
5. **Callers (14+ / 18 xrefs):** includes `FUN_004646e0` (PtrVecShell fill path) plus many STL-ish fill sites.
6. **Name:** `Mem_FillDwordN_FromSrc_EaxEcxEdx` (Ghidra `FUN_00436ef0`). **Reject** scaffold `Named_CalleeOf_*`. Related but distinct: `Mem_FillDwordN_ReturnEnd` (`0x004651d0`).
7. **Decompile ≡ bytes** for null gate + loop.  
   Full hex: `85c976125685c074048b32893083c00483e90175f05ec3`

### Gaps

- Product English for non-vector call sites.  
- Whether any caller relies on post-null-path EAX value.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00436ef0_Mem_FillDwordN_FromSrc_EaxEcxEdx.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_00436ef0_Mem_FillDwordN_FromSrc_EaxEcxEdx.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00436ef0_FUN_00436ef0.md` |
| Annotated | `docs/reconstruction/raw/aa_00436ef0_FUN_00436ef0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Mem_FillDwordN_FromSrc_EaxEcxEdx.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00436ef0.cpp` |
| Function | `docs/reconstruction/functions/aa_00436ef0_FUN_00436ef0.md` |
| Function named | `docs/reconstruction/functions/aa_00436ef0_Mem_FillDwordN_FromSrc_EaxEcxEdx.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0044a0d0` | Port as **placement ctor** (stack self*, **RET 4**, return self). Same bag shape as W32-D/W32-E Ass nested ctors: sentinel @+8, size0 @+0xc, 9-slot ptr vec @+0x10 via sealed `PtrVecShell_InitFill`, flags 1/1. Nested under unowned `FUN_0074d750` at outer **+0x0c**. Do **not** invent thiscall or Ass* product plate without parent seal. |
| `00436ef0` | Port as **register ABI leaf fill**: EAX dest / ECX count / EDX src*. Preserve null-safe store + always-advance + re-read `*src`. Do **not** invent stack formals or conflate with `Mem_FillDwordN_ReturnEnd` (EDI/ESI/EDX + end return). Closes W33-B PtrVecShell fill residual. |

Shared: bag ctor path `NestedHashBag_Ctor` → `PtrVecShell_InitFill` → **`Mem_FillDwordN_FromSrc_EaxEcxEdx`** completes the sealed fill chain for the 9-bucket Ass-style bags.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` structural name for bag; pure-mem helper name without overclaiming product English.  
- Rejected scaffold `Named_CalleeOf_*` as product alias.  
- Avoided bare `undefined4` in clean (`uint32_t` / explicit structs).
