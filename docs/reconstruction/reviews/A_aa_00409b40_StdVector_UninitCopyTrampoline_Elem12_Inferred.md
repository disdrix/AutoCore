# Review A (reconstruction fidelity): `aa_00409b40` StdVector_UninitCopyTrampoline_Elem12_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00409b40` |
| **VA** | `0x00409b40`–`0x00409b5a` inclusive (**27 B** / `0x1b`) |
| **Canonical name** | `StdVector_UninitCopyTrampoline_Elem12_Inferred` |
| **Ghidra name** | `FUN_00409b40` |
| **Review date** | `2026-08-05` (R10-008 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00409b40_StdVector_UninitCopyTrampoline_Elem12_Inferred.md` |
| **System** | skills-abilities / MSVC-style vector uninit_copy ABI trampoline (elem 0x0C) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `disassemble_function` + `analyze_function_complete` + `read_memory` + `get_assembly_context` + callers/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Thin **ABI trampoline** into dualed range worker `StdVector_UninitializedCopy_Elem12_Inferred` (`0x0040a590`). Remaps InsertN grow-site layout (`ECX=this`, `EDX=dest`, stack begin/end, **RET 8**) into free-helper layout (`ECX=end`, stack begin+dest). No element loop of its own.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ scaffold CF (call `0040a590`); ABI incomplete |
| Full body hex | 27 B via `read_memory` |
| Assembly listing | `disassemble_function` (not disassemble_bytes) |
| Call sites | `00408413`, `0040843a` in InsertN `004082f0` |
| Target dual | WQ9K-J / WQ-009 `aa_0040a590` |
| Twin trampoline | WQ9K-A `aa_00409ae0` (elem 0x28) |

---

## 3. Signature (sealed)

```c
// ECX=host_unused; EDX=dest; stack begin,end; EAX=dest_end; RET 8
void* __fastcall StdVector_UninitCopyTrampoline_Elem12_Inferred(
    void* host_unused,
    void* dest,
    const void* src_begin,
    const void* src_end);
```

| Formal | Source | Conf |
|---|---|---|
| host / this | ECX (pushed unused by target) | **Confirmed** |
| dest | EDX → push before CALL | **Confirmed** |
| src_begin | `[ESP+4]` | **Confirmed** |
| src_end | `[ESP+8]` → becomes target ECX | **Confirmed** |
| return | EAX from `0040a590` | **Confirmed** (InsertN stores `[EBP-0x1c]`) |
| cleanup | `RET 8` (`C2 08 00`) | **Confirmed** |
| target | `CALL 0x0040a590` + `ADD ESP,0x10` | **Confirmed** |

---

## 4. Control flow (sealed)

| Stage | Match | Conf |
|---|---|---|
| Push begin; push ECX; load end→ECX | bytes | **Confirmed** |
| Push EDX dest; push begin | 4-stack glue | **Confirmed** |
| CALL uninit_copy Elem12 | rel target `+0x0a3b` | **Confirmed** |
| ADD ESP,0x10; RET 8 | epilog | **Confirmed** |
| No local element loop | body size 27 B | **Confirmed** |
| Byte-identical to 00409ae0 except CALL rel | hex compare | **Confirmed** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | wrapper |
| External callers | `FUN_004082f0` only (`xref_count=2`) |
| Site roles | prefix `[begin,where)→new`; suffix `[where,end)→dest` |
| Callees | `FUN_0040a590` only |
| Parent dual | `StdVector_InsertN_Elem12_Inferred` (WQ9H-B) |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| Sole CALL is dualed UninitCopy Elem12 | **Yes** |
| InsertN reallocate consumer | **Yes** |
| Stride inherited from target / InsertN 0x0C | **Yes** |
| Twin trampoline naming pattern (0x28) | **Yes** |
| Product/PDB English for T | **No** |

**Decision:** promote **`StdVector_UninitCopyTrampoline_Elem12_Inferred`**.

---

## 7. Gaps

- Product element type demangle (shared 0x0C family).
- Runtime / bit-exact / differential.
- Non-grow InsertN paths use direct `0040a590` (parent sealed; not this OWN).

---

## 8. Verdict

Fidelity path accepts CF/ABI/caller roles with product residual → **accept-with-gaps**.
