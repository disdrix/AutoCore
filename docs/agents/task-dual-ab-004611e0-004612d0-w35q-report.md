# Dual A/B report — W35-Q OWN `aa_004611e0` + `aa_004612d0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W35-Q  
**Scope:** VAs `0x004611e0`, `0x004612d0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** wave35 W35-Q.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004611e0` StdVector_Resize_RcElem28 | **accept-with-gaps** — EDI=vec / ECX=n / stack T by-value 0x1c / RET 1C / grow+shrink+Release sealed; product T open |
| `aa_004612d0` StdVector_InsertOne_RebindIt_RcElem28 | **accept-with-gaps** — EDI=vec / stack outIt+where+value / RET C / count=1 rebind sealed; product T open |

---

## VA `0x004611e0` — sealed facts

1. **Body:** `0x004611e0`–`0x004612c5` exclusive (**229 B** / `0xE5`; pad `CC` then `FUN_004612d0`).
2. **ABI:** **EDI=`vec*`**, **ECX=`new_size`**, stack **`RcElem28` by-value (0x1c)**, **`RET 0x1C`**. Decompiler thiscall/ECX=this is wrong — **bytes win**.
3. **Semantics:** MSVC-style **`vector::resize(n, value)`** for non-trivial T size **0x1c**:
   - Size via triad begin@+4 / end@+8; magic `0x92492493` ÷28.
   - **Grow** (`size < n`): `StdVector_InsertN_RcElem28` (`0x004617a0`) at **end**, count `n−size`, value* = stack T.
   - **Shrink** (`n < size`): `FUN_00461720` erase `[begin+n*0x1c, end)`.
   - **Equal:** no-op.
   - Epilogue **Release** stack T resource `@+0x10` (refcount−1 → vtbl+8).
4. **Classification:** worker — resize shell over sealed RC insert-n.
5. **Callers (1):** `FUN_00965ab0` @ `0x00965f47` (gfx/mesh residual).
6. **Name:** `StdVector_Resize_RcElem28` (Ghidra `FUN_004611e0`; **Inferred** structural). Reject scaffold `Named_CalleeOf_*gfxDevice*`.
7. **Decompile ≡ bytes** for grow/shrink CF; **bytes win** on EDI=vec, ECX=n, RET 1C, by-value dtor.  
   Full hex: raw W35-Q append (229 B).

### Gaps

- Product/PDB T English (gfx residual only).  
- Erase helper `FUN_00461720` + parent not dual-owned.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004611e0_StdVector_Resize_RcElem28.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004611e0_StdVector_Resize_RcElem28.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004611e0_FUN_004611e0.md` |
| Annotated | `docs/reconstruction/raw/aa_004611e0_FUN_004611e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_Resize_RcElem28.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004611e0.cpp` |
| Function | `docs/reconstruction/functions/aa_004611e0_FUN_004611e0.md` |
| Function named | `docs/reconstruction/functions/aa_004611e0_StdVector_Resize_RcElem28.md` |

---

## VA `0x004612d0` — sealed facts

1. **Body:** `0x004612d0`–`0x00461342` exclusive (**114 B** / `0x72`; pad `CC` then next @ `0x00461350`).
2. **ABI:** **EDI=`vec*`**, stack **`(outIt*, where, value*)`**, returns **`outIt*`**, **`RET 0xC`**. Decompiler omits value* formal — **bytes win**.
3. **Semantics:** MSVC-style **insert-one + rebind iterator**:
   - Snapshot `index = empty ? 0 : (where−begin)/0x1c`.
   - `StdVector_InsertN_RcElem28(value@ECX, vec, where, count=1)`.
   - `*outIt = begin' + index*0x1c` (survives realloc).
4. **Classification:** worker — thin insert-one wrapper (push_back slow path).
5. **Callers (1):** `FUN_00460f90` @ `0x00461006` (spare-cap → fill-n; else this).
6. **Name:** `StdVector_InsertOne_RebindIt_RcElem28` (Ghidra `FUN_004612d0`; **Inferred**). Reject scaffold long `Named_CalleeOf_*gfxDevice*`.
7. **Decompile ≡ bytes** for index/rebind CF; **bytes win** on third stack formal + RET C.  
   Full hex: raw W35-Q append (114 B).

### Gaps

- Product/PDB T English.  
- Push_back parent `FUN_00460f90` unowned.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004612d0_StdVector_InsertOne_RebindIt_RcElem28.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004612d0_StdVector_InsertOne_RebindIt_RcElem28.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004612d0_FUN_004612d0.md` |
| Annotated | `docs/reconstruction/raw/aa_004612d0_FUN_004612d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_InsertOne_RebindIt_RcElem28.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004612d0.cpp` |
| Function | `docs/reconstruction/functions/aa_004612d0_FUN_004612d0.md` |
| Function named | `docs/reconstruction/functions/aa_004612d0_StdVector_InsertOne_RebindIt_RcElem28.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004611e0` | Port as **RC-elem28 resize**: **EDI=vec**, **ECX=n**, stack **T by-value 0x1c**, **RET 0x1C**. Grow → insert-n at end; shrink → erase-range; always Release value.resource. Do **not** use thiscall ECX=vec or POD memmove. |
| `004612d0` | Port as **insert-one + rebind**: **EDI=vec**, stack **outIt+where+value***, **RET 0xC**. Index before insert; rebind after. Do **not** drop-in for dword thiscall insert-one (`0040dbf0`). |

Shared context (not owned):

| VA | Role |
|---|---|
| `0x004617a0` | `StdVector_InsertN_RcElem28` (W34-P sealed) — both call |
| `0x00461720` | erase-range shrink helper for resize |
| `0x00460f90` | push_back parent of insert-one |
| `0x00461c90` | fill-n (push_back spare-cap path) |
| `0x00965ab0` | sole resize parent (mesh/UI residual) |
| `0x0040dbf0` | dword insert-one rebind twin (different ABI/stride) |

Together they close the **RC-elem28** resize + insert-one parents of the W34-P insert-n engine — completing the high-level vector mutators for this T family.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + xref helpers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; `_Inferred` structural names only (`StdVector_*_RcElem28` family from W34-P).  
- Rejected scaffold `Named_CalleeOf_*gfxDevice*`.  
- Avoided bare `undefined4` in clean (`uint32_t` / explicit structs).
