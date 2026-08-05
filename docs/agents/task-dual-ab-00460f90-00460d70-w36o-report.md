# Dual A/B report — W36-O OWN `aa_00460f90` + `aa_00460d70`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W36-O  
**Scope:** VAs `0x00460f90`, `0x00460d70` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** wave36 W36-O.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00460f90` StdVector_PushBack_RcElem28 | **accept-with-gaps** — EAX=vec / ECX=value* / RET 0 / spare→fill-n(1) else insert-one sealed; product T open |
| `aa_00460d70` RcElem28_Release | **accept-with-gaps** — EAX=elem / `@+0x10` refcount-- / tail JMP vtbl+8 sealed; product shared class open |

---

## VA `0x00460f90` — sealed facts

1. **Body:** `0x00460f90`–`0x00461011` exclusive (**129 B** / `0x81`; pad `CC` then next).
2. **ABI:** **EAX=`vec*`**, **ECX=`value*`**, no stack formals, **`RET 0`**. Prologue `PUSH ECX` saves value* and supplies outIt slot for slow path. Decompiler `__fastcall` + `in_EAX` shape correct; **bytes win** on RET 0 and pointer (not by-value) T.
3. **Semantics:** MSVC-style **`vector::push_back(const T&)`** for non-trivial T size **0x1c**:
   - Size/cap via begin@+4 / end@+8 / cap_end@+0xc; magic `0x92492493` ÷28.
   - **Spare capacity** (`begin && size < cap`): `StdUninitFillN_RcElem28` (`0x00461c90`) at end, count=1; `end += 0x1c`.
   - **Full / null begin:** `StdVector_InsertOne_RebindIt_RcElem28` (`0x004612d0`) at end; rebind outIt discarded.
4. **Classification:** worker — push_back router over sealed fill-n + insert-one.
5. **Callers (1):** `FUN_00965ab0` @ `0x00966449` (mesh/UI residual; EAX=obj+0x68, ECX=stack value*).
6. **Name:** `StdVector_PushBack_RcElem28` (Ghidra `FUN_00460f90`; **Inferred** structural). Reject scaffold `Named_CalleeOf_*gfxDevice*`.
7. **Decompile ≡ bytes** for spare/full CF; **bytes win** on register formals and call targets.  
   Full hex: raw W36-O append (129 B).

### Gaps

- Product/PDB T English (gfx residual only).  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00460f90_StdVector_PushBack_RcElem28.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00460f90_StdVector_PushBack_RcElem28.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00460f90_FUN_00460f90.md` |
| Annotated | `docs/reconstruction/raw/aa_00460f90_FUN_00460f90.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_PushBack_RcElem28.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00460f90.cpp` |
| Function | `docs/reconstruction/functions/aa_00460f90_FUN_00460f90.md` |
| Function named | `docs/reconstruction/functions/aa_00460f90_StdVector_PushBack_RcElem28.md` |

---

## VA `0x00460d70` — sealed facts

1. **Body:** `0x00460d70`–`0x00460d83` exclusive (**19 B** / `0x13`; pad `CC` then next).
2. **ABI:** **EAX=`elem*`**, no stack formals, **`RET 0`** when shared null or refcount stays live; **tail JMP** `[vtbl+8]` when refcount hits 0. Decompiler "call" on indirect is wrong — **bytes win** (`FF 62 08`).
3. **Semantics:** Per-element **Release** for RC-elem28:
   - `shared = *(elem + 0x10)`.
   - If non-null: `--shared->refcount` (`shared+4`).
   - If zero: transfer to **`vtbl[+8]`** (this@ECX = shared).
4. **Classification:** leaf — pure Release helper (no direct FUN_* callees).
5. **Callers (6):** `FUN_00461350` @ `0x00461362`; `FUN_00461720` @ `0x00461753`; `FUN_00461780` (`StdDestroyRange_RcElem28`) @ `0x00461789`; Unwind `@009b2ed1`, `@009be5d0`, `@009be610`.
6. **Name:** `RcElem28_Release` (Ghidra `FUN_00460d70`; **Inferred** structural). Reject scaffold long `Named_CalleeOf_*`.
7. **Decompile ≡ bytes** for null/refcount CF; **bytes win** on tail JMP.  
   Full hex: raw W36-O append (19 B).

### Gaps

- Product/PDB shared-class English / vtbl identity.  
- Exact `vtbl+8` destroy contract not dual-owned.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00460d70_RcElem28_Release.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00460d70_RcElem28_Release.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00460d70_FUN_00460d70.md` |
| Annotated | `docs/reconstruction/raw/aa_00460d70_FUN_00460d70.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/RcElem28_Release.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00460d70.cpp` |
| Function | `docs/reconstruction/functions/aa_00460d70_FUN_00460d70.md` |
| Function named | `docs/reconstruction/functions/aa_00460d70_RcElem28_Release.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00460f90` | Port as **RC-elem28 push_back**: **EAX=vec**, **ECX=value\***, **RET 0**. Spare → uninit-fill-n count=1 at end; full → insert-one at end. Do **not** use thiscall ECX=vec, by-value T, or dword push_back twins. |
| `00460d70` | Port as **per-elem Release**: **EAX=elem**, load **`@+0x10`**, refcount--, **tail** to **vtbl+8** at zero. Do **not** free the element buffer here; do **not** treat as AddRef or full multi-field dtor. |

Shared context (not owned):

| VA | Role |
|---|---|
| `0x00461c90` | `StdUninitFillN_RcElem28` (W35-O) — push_back fast path |
| `0x004612d0` | `StdVector_InsertOne_RebindIt_RcElem28` (W35-Q) — push_back slow path |
| `0x004617a0` | `StdVector_InsertN_RcElem28` (W34-P) — engine under insert-one |
| `0x00461780` | `StdDestroyRange_RcElem28` (W35-O) — primary caller of Release |
| `0x00461720` | erase-range helper (also calls Release) |
| `0x00461350` | vector clear/dtor loop |
| `0x004611e0` | resize sibling (same T family) |
| `0x00965ab0` | sole push_back parent (mesh/UI residual) |

Together they close the **push_back** high-level mutator and the **per-elem Release leaf** for the RcElem28 family — completing the acquire (fill-n AddRef) / release (this leaf) pair named by prior W35 destroy-range work.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; `_Inferred` structural names only (`StdVector_PushBack_RcElem28` / `RcElem28_Release` family from W34-P / W35 vector RC plates).  
- Rejected scaffold `Named_CalleeOf_*gfxDevice*`.  
- Avoided bare `undefined4` in clean (`uint32_t` / explicit structs).
