# Dual A/B report — W35-O OWN `aa_00461c90` + `aa_00461780`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W35-O  
**Scope:** VAs `0x00461c90`, `0x00461780` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave35_partition_map.md` (W35-O).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00461c90` StdUninitFillN_RcElem28 | **accept-with-gaps** — ECX=value / EDX=count / stack dest / RET 0 / stride 0x1c / AddRef@+0x10 sealed; product T English open |
| `aa_00461780` StdDestroyRange_RcElem28 | **accept-with-gaps** — EAX=begin / EDI=end / RET 0 / stride 0x1c / FUN_00460d70 sealed; product class + nested Release leaf open |

---

## VA `0x00461c90` — sealed facts

1. **Body:** `0x00461c90`–`0x00461d74` exclusive (**228 B** / `0xE4`; pad `CC` then next). Ghidra end `00461d73` off-by-one — **bytes win**.
2. **ABI:** **ECX=value\***, **EDX=count**, stack **dest\***, **`RET 0`**. Callers often push an extra unused dword and `ADD ESP,8`.
3. **Semantics:** MSVC-style **`_Uninit_fill_n`** for **non-trivial** T size **0x1c** with shared resource **`@+0x10`**:
   - Copy dwords `@+0x00..+0x0C`; AddRef shared (refcount++ then vtbl+4 when hits 1); store shared; copy `@+0x14..+0x16` + `@+0x18`.
   - Advance dest by **0x1c** per iteration.
   - SEH state around each construction; unwind Releases constructed range (vtbl+8).
4. **Classification:** worker (Ghidra “leaf” = no direct FUN_* only).
5. **Callers (3):** `FUN_004617a0` @ `0x004618e5`, `0x00461a0c`; `FUN_00460f90` @ `0x00460fe8` (count=1).
6. **Name:** `StdUninitFillN_RcElem28` (Ghidra `FUN_00461c90`; **Inferred** structural). Reject scaffold `Named_CalleeOf_*gfxDevice*`.
7. **Decompile ≡ bytes** for main fill loop; **bytes win** on EH unwind Release path and RET 0.  
   Full hex: raw W35-O append (228 B).

### Gaps

- Product/PDB T English (gfx residual only).  
- Exact AddRef gate semantics residual.  
- Nested resource vtbl not dual-owned.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00461c90_StdUninitFillN_RcElem28.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00461c90_StdUninitFillN_RcElem28.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00461c90_FUN_00461c90.md` |
| Annotated | `docs/reconstruction/raw/aa_00461c90_FUN_00461c90.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdUninitFillN_RcElem28.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00461c90.cpp` |
| Function | `docs/reconstruction/functions/aa_00461c90_FUN_00461c90.md` |
| Function named | `docs/reconstruction/functions/aa_00461c90_StdUninitFillN_RcElem28.md` |

---

## VA `0x00461780` — sealed facts

1. **Body:** `0x00461780`–`0x00461797` exclusive (**23 B** / `0x17`; pad `CC` then parent InsertN @ `0x004617a0`). Ghidra end `00461796` off-by-one — **bytes win**.
2. **ABI:** **EAX=begin\***, **EDI=end\*** (half-open), no stack formals, **`RET 0`**. ESI cursor (push/pop).
3. **Semantics:** MSVC-style **destroy range** for **non-trivial** T size **0x1c**:
   - For each elem in `[begin,end)`: `FUN_00460d70` Releases shared **`@+0x10`** (refcount-- then vtbl+8 when 0).
   - Stride **0x1c**.
4. **Classification:** worker (thin range walker / Ghidra “wrapper”).
5. **Callers (3):** `FUN_004617a0` @ `0x00461947` (grow: destroy old then delete); `Catch@0046197a` @ `0x00461982`; `Catch@00461a34` @ `0x00461a51`.
6. **Name:** `StdDestroyRange_RcElem28` (Ghidra `FUN_00461780`; **Inferred** structural). Reject scaffold `Named_CalleeOf_*gfxDevice*`.
7. **Decompile ≡ bytes** for loop CF; **bytes win** on register formals (decompiler `in_EAX`/`unaff_EDI`).  
   Full hex: raw W35-O append (23 B).

### Gaps

- Product/PDB class English.  
- Nested `FUN_00460d70` not dual-owned.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00461780_StdDestroyRange_RcElem28.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00461780_StdDestroyRange_RcElem28.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00461780_FUN_00461780.md` |
| Annotated | `docs/reconstruction/raw/aa_00461780_FUN_00461780.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdDestroyRange_RcElem28.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00461780.cpp` |
| Function | `docs/reconstruction/functions/aa_00461780_FUN_00461780.md` |
| Function named | `docs/reconstruction/functions/aa_00461780_StdDestroyRange_RcElem28.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00461c90` | Port as **RC uninit-fill-n** stride **0x1c**: **ECX=value\***, **EDX=count**, stack **dest\***, **RET 0**. AddRef resource `@+0x10` on every construction. Honor SEH/unwind Release on throw paths. Do **not** treat as POD memmove or BasicString fill-n (`RET C` thiscall). |
| `00461780` | Port as **RC destroy-range** stride **0x1c**: **EAX=begin**, **EDI=end**, **RET 0**. Call per-elem Release (`FUN_00460d70` semantics) only — parent owns `operator delete`. Do **not** free the buffer here. |

Shared context (not owned):

| VA | Role |
|---|---|
| `0x004617a0` | `StdVector_InsertN_RcElem28` (W34-P) — parent that names both helpers |
| `0x00461ac0` / `0x004620b0` | RC copy-ctor / uninit-copy (W35-N) |
| `0x00461b80` / `0x00461ef0` | RC assign helpers (W35-P) |
| `0x00460d70` | per-elem Release leaf |
| `0x00460f90` | push_back-style caller of fill-n |
| `0x0045cd30` | POD insert-n sibling (different lifetime) |

Together they close the two high-mention nested callees of RcElem28 insert-n (fill-n + destroy-range) assigned to W35-O.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; `_Inferred` structural names only (`StdUninitFillN_RcElem28` / `StdDestroyRange_RcElem28` family from W34-P parent + W33 BasicString fill-n pattern).  
- Avoided bare `undefined4` in clean (`uint32_t` / explicit structs).
