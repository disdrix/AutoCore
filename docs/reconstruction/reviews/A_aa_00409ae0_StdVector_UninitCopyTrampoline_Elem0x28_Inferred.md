# Review A (reconstruction fidelity): `aa_00409ae0` StdVector_UninitCopyTrampoline_Elem0x28_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00409ae0` |
| **VA** | `0x00409ae0`–`0x00409afa` inclusive (**27 B** / `0x1b`) |
| **Canonical name** | `StdVector_UninitCopyTrampoline_Elem0x28_Inferred` |
| **Ghidra name** | `FUN_00409ae0` |
| **Review date** | `2026-08-05` (WQ9K-A OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00409ae0_StdVector_UninitCopyTrampoline_Elem0x28_Inferred.md` |
| **System** | MSVC-style vector uninit_copy ABI trampoline (elem 0x28) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` + `disassemble_function` + `analyze_function_complete` + `read_memory` + `get_assembly_context` + callers/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Thin **ABI trampoline** into dualed range worker `StdVector_UninitializedCopy_Elem0x28_Inferred` (`0x0040a520`). Remaps InsertN grow-site layout (`ECX=this`, `EDX=dest`, stack begin/end, **RET 8**) into free-helper layout (`ECX=end`, stack begin+dest). No element loop of its own.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ scaffold CF (call `0040a520`); ABI incomplete |
| Full body hex | 27 B via `read_memory` |
| Assembly listing | `disassemble_function` (not disassemble_bytes) |
| Call sites | `00408171`, `00408198` in InsertN `00408050` |
| Target dual | WQ9J-A `aa_0040a520` |

---

## 3. Signature (sealed)

```c
// ECX=host_unused; EDX=dest; stack begin,end; EAX=dest_end; RET 8
void* __fastcall StdVector_UninitCopyTrampoline_Elem0x28_Inferred(
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
| return | EAX from `0040a520` | **Confirmed** |
| cleanup | `RET 8` (`C2 08 00`) | **Confirmed** |
| target | `CALL 0x0040a520` + `ADD ESP,0x10` | **Confirmed** |

---

## 4. Control flow (sealed)

| Stage | Match | Conf |
|---|---|---|
| Push begin; push ECX; load end→ECX | bytes | **Confirmed** |
| Push EDX dest; push begin | 4-stack glue | **Confirmed** |
| CALL uninit_copy 0x28 | rel target | **Confirmed** |
| ADD ESP,0x10; RET 8 | epilog | **Confirmed** |
| No local element loop | body size 27 B | **Confirmed** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | wrapper |
| External callers | `FUN_00408050` only (`xref_count=2`) |
| Site roles | prefix `[begin,where)→new`; suffix `[where,end)→dest` |
| Callees | `FUN_0040a520` only |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| Sole CALL is dualed UninitCopy 0x28 | **Yes** |
| InsertN reallocate consumer | **Yes** |
| Stride inherited from target / InsertN 0x28 | **Yes** |
| Product/PDB English for T | **No** |

**Decision:** promote **`StdVector_UninitCopyTrampoline_Elem0x28_Inferred`**.

---

## 7. Gaps

- Product element type demangle (shared 0x28 family).
- Full dual of parent InsertN `00408050` (role sealed).
- Runtime / bit-exact / differential.

---

## 8. Verdict

Fidelity path accepts CF/ABI/caller roles with product residual → **accept-with-gaps**.
