# Dual A/B report — W35-N OWN `aa_00461ac0` + `aa_004620b0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W35-N  
**Scope:** VAs `0x00461ac0`, `0x004620b0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `get_function_by_address` + xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave35_partition_map.md` (W35-N).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00461ac0` RcElem28_CopyCtor_EsiEdi | **accept-with-gaps** — ESI/EDI register ABI + 0x1c layout + AddRef@+0x10 sealed; product English open |
| `aa_004620b0` StdVector_UninitializedCopy_RcElem28 | **accept-with-gaps** — ECX/stack uninit-copy + stride 0x1c + plain RET sealed; EH unwind residual; product open |

---

## VA `0x00461ac0` — sealed facts

1. **Body:** `0x00461ac0`–`0x00461b11` exclusive (**81 B** / `0x51`; pad `CC` then next). Ghidra end `00461b10` off-by-one — **bytes win**.
2. **ABI:** **ESI=src\***, **EDI=dst\***, **EAX=dst**, plain **`C3`** (no stack args).
3. **Semantics:** MSVC-style **copy-ctor / placement construct** for non-trivial **T** size **0x1c**:
   - Copy dwords @+0..+0xC.
   - Resource `@+0x10`: if non-null, `++refcount` at obj+4; if count **== 1** after increment → call **vtbl+4**.
   - Copy bytes @+0x14..+0x16 and dword @+0x18.
4. **Classification:** worker / leaf helper.
5. **Callers (1):** `FUN_004617a0` / `StdVector_InsertN_RcElem28` @ `0x004617c9` (local value materialize).
6. **Name:** `RcElem28_CopyCtor_EsiEdi` (Ghidra `FUN_00461ac0`; **Inferred** structural). Reject scaffold `Named_CalleeOf_*gfxDevice*`.
7. **Decompile ≡ bytes** for CF/AddRef; **bytes win** on body exclusive end.  
   Full hex: raw W35-N append (81 B).

### Gaps

- Product/PDB T English (gfx residual only).  
- Exact product semantics of AddRef-when-refcount-becomes-1.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00461ac0_RcElem28_CopyCtor_EsiEdi.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00461ac0_RcElem28_CopyCtor_EsiEdi.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00461ac0_FUN_00461ac0.md` |
| Annotated | `docs/reconstruction/raw/aa_00461ac0_FUN_00461ac0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/RcElem28_CopyCtor_EsiEdi.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00461ac0.cpp` |
| Function | `docs/reconstruction/functions/aa_00461ac0_FUN_00461ac0.md` |
| Function named | `docs/reconstruction/functions/aa_00461ac0_RcElem28_CopyCtor_EsiEdi.md` |

---

## VA `0x004620b0` — sealed facts

1. **Body:** `0x004620b0`–`0x00462194` exclusive (**228 B** / `0xE4`; pad `CC` then next). Ghidra end `00462193` off-by-one — **bytes win**.
2. **ABI:** **ECX=src_begin**, stack **`(src_end, dest)`**, **EAX=dest_end**, plain **`C3`** (caller cleans 8). Ghidra `__thiscall` epilogue **wrong** — **bytes win**.
3. **Semantics:** MSVC-style **`uninitialized_copy`** for refcounted **T** size **0x1c**:
   - SEH `LAB_009be5a1`.
   - Loop: while src ≠ end — if dest non-null, construct element (same layout + AddRef gate as copy-ctor leaf); advance both by **0x1c**.
   - Return advanced dest.
   - EH residual: Release partial dest range (vtbl+8 when refcount hits 0) then rethrow path.
4. **Element layout:** same as parent RcElem28 / copy-ctor leaf.
5. **Classification:** worker.
6. **Callers (4):** all in `FUN_004617a0` @ `0x004618d0`, `0x0046190b`, `0x004619db`, `0x00461a68` (grow/in-place relocate).
7. **Name:** `StdVector_UninitializedCopy_RcElem28` (Ghidra `FUN_004620b0`; **Inferred** structural). Reject scaffold `Named_CalleeOf_*gfxDevice*`.
8. **Decompile ≡ bytes** for happy-path CF; **bytes win** on RET, body end, EH residual.  
   Full hex: raw W35-N append (228 B).

### Gaps

- Product/PDB class English.  
- EH unwind not dual-owned as separate unit (bytes residual).  
- Dest-null advance product intent.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004620b0_StdVector_UninitializedCopy_RcElem28.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004620b0_StdVector_UninitializedCopy_RcElem28.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004620b0_FUN_004620b0.md` |
| Annotated | `docs/reconstruction/raw/aa_004620b0_FUN_004620b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_UninitializedCopy_RcElem28.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004620b0.cpp` |
| Function | `docs/reconstruction/functions/aa_004620b0_FUN_004620b0.md` |
| Function named | `docs/reconstruction/functions/aa_004620b0_StdVector_UninitializedCopy_RcElem28.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00461ac0` | Port as **register copy-ctor**: **ESI=src**, **EDI=dst**, plain RET. Always AddRef resource `@+0x10` with **vtbl+4 when refcount becomes 1**. Do **not** POD-memcpy; do **not** invent dest Release (uninit dest). |
| `004620b0` | Port as **uninit-copy range**: **ECX=src_begin**, stack **end+dest**, **caller-cleaned** stack, return dest_end. Stride **0x1c** + same AddRef. Do **not** use MSVC member thiscall `RET 8`; do **not** treat as POD memmove. Honor SEH/Release on throw paths if porting exceptions. |

Shared context (not owned this dual):

| VA | Role |
|---|---|
| `0x004617a0` | parent `StdVector_InsertN_RcElem28` (W34-P) |
| `0x00461c90` / `0x00461780` | fill-n / destroy (W35-O) |
| `0x00461b80` / `0x00461ef0` | assign fwd/back (W35-P) |
| `0x004611e0` / `0x004612d0` | insert parents (W35-Q) |
| `0x0045cd30` | POD insert-n sibling (no AddRef) |

Together these seal the two nested construct helpers called out as gaps under W34-P RcElem28 insert-n.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; `_Inferred` structural names only (`RcElem28_*` / `StdVector_*` family from W34-P).  
- Avoided bare `undefined4` in clean (`uint32_t` / explicit structs).
