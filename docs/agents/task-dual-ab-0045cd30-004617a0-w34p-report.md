# Dual A/B report — W34-P OWN `aa_0045cd30` + `aa_004617a0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W34-P  
**Scope:** VAs `0x0045cd30`, `0x004617a0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave34_partition_map.md` (W34-P).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0045cd30` StdVector_InsertN_Pod28 | **accept-with-gaps** — ECX=count / EDX=vec / stack where+value / RET 8 / POD 0x1c / 1.5× sealed; product T English open |
| `aa_004617a0` StdVector_InsertN_RcElem28 | **accept-with-gaps** — ECX=value / stack vec+where+count / RET C / RC@+0x10 / 1.5× sealed; product class + nested helpers open |

---

## VA `0x0045cd30` — sealed facts

1. **Body:** `0x0045cd30`–`0x0045d01c` exclusive (**748 B** / `0x2EC`; pad `CC` then next). Ghidra end `0045d01b` off-by-one — **bytes win**.
2. **ABI:** **ECX=count**, **EDX=vector\***, stack **`(where, value*)`**, **`RET 0x8`**. Prologue **7× MOVSS** local value load (decompiler omits).
3. **Semantics:** MSVC-style **`vector<T>::_Insert_n`** for **trivially copyable** T size **0x1c**:
   - Triad begin@`+4` / end@`+8` / capEnd@`+0xC`; size/cap via magic `0x92492493`.
   - If `size+count > 0x9249249` → `FUN_004540b0`.
   - Grow: 1.5× (`cap+(cap>>1)`), floor `size+count` via `StdVector_Elem28_Size`; trivial relocate/fill (`FUN_0045f360` / `FUN_0045f150`); delete old.
   - In-place: hole vs mid (`FUN_0045f360` / `FUN_0045f150` / `FUN_0046a240` / `FUN_0045efe0`).
4. **Classification:** worker.
5. **Callers (1):** `FUN_0045c4b0` @ `0x0045c506`.
6. **Name:** `StdVector_InsertN_Pod28` (Ghidra `FUN_0045cd30`; **Inferred** structural). Reject scaffold `Named_CalleeOf_*anmTrackMaster*`.
7. **Decompile ≡ bytes** for CF; **bytes win** on SSE prologue, register ABI, RET 8, false noreturn.  
   Full hex: raw W34-P append (748 B).

### Gaps

- Product/PDB T English (anm-track residual only).  
- Nested trivial helpers + caller not dual-owned.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0045cd30_StdVector_InsertN_Pod28.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0045cd30_StdVector_InsertN_Pod28.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0045cd30_FUN_0045cd30.md` |
| Annotated | `docs/reconstruction/raw/aa_0045cd30_FUN_0045cd30.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_InsertN_Pod28.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0045cd30.cpp` |
| Function | `docs/reconstruction/functions/aa_0045cd30_FUN_0045cd30.md` |
| Function named | `docs/reconstruction/functions/aa_0045cd30_StdVector_InsertN_Pod28.md` |

---

## VA `0x004617a0` — sealed facts

1. **Body:** `0x004617a0`–`0x00461abb` exclusive (**795 B** / `0x31B`; pad `CC` then next). Ghidra end `00461aba` off-by-one — **bytes win**.
2. **ABI:** **ECX=value\*** (copy-ctor source), stack **`(vector*, where, count)`**, **`RET 0xC`**. Local via `FUN_00461ac0`; epilogue **Release** resource.
3. **Semantics:** MSVC-style **`vector<T>::_Insert_n`** for **non-trivial** T size **0x1c** with shared resource **`@+0x10`**:
   - Copy-ctor local with AddRef (vtbl+4 when refcount hits 1); Release at exit (vtbl+8 when 0).
   - Same max / 1.5× / triad / `StdVector_Elem28_Size` family as Pod28.
   - Grow: `FUN_004620b0` uninit-copy, `FUN_00461c90` fill-n, `FUN_00461780` destroy + delete.
   - In-place: hole (`FUN_004620b0` + fill + `FUN_00461b80`) vs mid (`FUN_004620b0` + `FUN_00461ef0` + `FUN_00461b80`).
4. **Element layout:** +0x00..+0x0C dwords; +0x10 shared*; +0x14..+0x16 bytes; +0x18 dword.
5. **Classification:** worker.
6. **Callers (2):** `FUN_004611e0` @ `0x00461255` (resize grow); `FUN_004612d0` @ `0x00461323` (insert-one).
7. **Name:** `StdVector_InsertN_RcElem28` (Ghidra `FUN_004617a0`; **Inferred** structural). Reject scaffold `Named_CalleeOf_*gfxDevice*`.
8. **Decompile ≡ bytes** for CF/Release; **bytes win** on ECX=value formal, RET C, false noreturn.  
   Full hex: raw W34-P append (795 B).

### Gaps

- Product/PDB class English (gfx residual only).  
- Nested RC helpers not dual-owned.  
- Exact AddRef gate semantics residual.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004617a0_StdVector_InsertN_RcElem28.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004617a0_StdVector_InsertN_RcElem28.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004617a0_FUN_004617a0.md` |
| Annotated | `docs/reconstruction/raw/aa_004617a0_FUN_004617a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_InsertN_RcElem28.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004617a0.cpp` |
| Function | `docs/reconstruction/functions/aa_004617a0_FUN_004617a0.md` |
| Function named | `docs/reconstruction/functions/aa_004617a0_StdVector_InsertN_RcElem28.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0045cd30` | Port as **POD insert-n** stride **0x1c**: **ECX=count**, **EDX=vec**, stack **where+value\***, **RET 8**. Honor max `0x9249249`, 1.5× grow, trivial 7-lane relocate/fill. Do **not** use BasicString ABI (ECX=vec RET C) or invent string dtors. |
| `004617a0` | Port as **RC-elem insert-n** stride **0x1c**: **ECX=value\***, stack **vec+where+count**, **RET C**. AddRef/Release resource `@+0x10` on all copy/assign/destroy paths. Do **not** treat as POD memmove or as `basic_string`. |

Shared context (not owned):

| VA | Role |
|---|---|
| `0x00469c50` | `StdVector_Elem28_Size` (W33-J) — size helper both call |
| `0x004540b0` | throw too long |
| `0x004306b0` | `StdVector_InsertN_BasicString` — string sibling, different ABI |
| `0x0045c4b0` | Pod28 sole parent (resize/ensure) |
| `0x004611e0` / `0x004612d0` | RcElem parents (resize / insert-one) |

Together they complete two more **elem-28 insert-n** instantiations in the family sealed across W32–W33 (string + size leaf + these POD/RC variants).

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; `_Inferred` structural names only (`StdVector_InsertN_*` family from W32-B / W33-J).  
- Avoided bare `undefined4` in clean (`uint32_t` / explicit structs).
