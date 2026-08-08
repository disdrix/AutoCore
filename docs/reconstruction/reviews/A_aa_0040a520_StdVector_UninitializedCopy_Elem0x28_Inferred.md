# Review A (reconstruction fidelity): `aa_0040a520` StdVector_UninitializedCopy_Elem0x28_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040a520` |
| **VA** | `0x0040a520`–`0x0040a584` inclusive (**101 B** / `0x65`) |
| **Canonical name** | `StdVector_UninitializedCopy_Elem0x28_Inferred` |
| **Ghidra name** | `FUN_0040a520` |
| **Review date** | `2026-08-05` (WQ9J-A OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_0040a520_StdVector_UninitializedCopy_Elem0x28_Inferred.md` |
| **System** | MSVC-style vector uninitialized_copy (elem 0x28) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` + `disassemble_function` + `analyze_function_complete` + `read_memory` + `get_assembly_context` + callers/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Range **POD uninitialized_copy**: walk half-open `[src_begin, src_end)` into `dest` with **stride 0x28**, calling dualed element leaf `StdVector_PodCopyElement_0x28_Inferred` each step; return advanced destination end. Used by InsertN/reallocate path `FUN_00408050`.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ raw CF (2026-08-05) |
| Full body hex | 101 B via `read_memory` |
| Assembly listing | `disassemble_function` (not disassemble_bytes) |
| Call sites | `0040824c`, `004082b3` (InsertN); trampoline `00409af0` |
| Element leaf dual | WQ9I-B `aa_00409f30` |

---

## 3. Signature (sealed)

```c
// ECX=src_end; stack src_begin, dest; EAX=dest_end; plain RET
void* StdVector_UninitializedCopy_Elem0x28_Inferred(
    /*ECX*/ const void* src_end,
    /*stack*/ const void* src_begin,
    /*stack*/ void* dest);
```

| Formal | Source | Conf |
|---|---|---|
| src_end | ECX → EBX | **Confirmed** |
| src_begin | `[ebp+8]` → ESI | **Confirmed** |
| dest | `[ebp+0xc]` → EDI | **Confirmed** |
| return | EAX = final EDI | **Confirmed** |
| cleanup | bare `C3` | **Confirmed** |
| element call | EAX=EDI dest, EDX=ESI src → `00409f30` | **Confirmed** |

---

## 4. Control flow (sealed)

| Stage | Match | Conf |
|---|---|---|
| SEH prolog/epilog | `PUSH 0x9bd0b0` / FS:[0] | **Confirmed** |
| Empty range early out | `CMP ESI,EBX` / `JZ` | **Confirmed** |
| PodCopy + both +0x28 | CALL + two ADDs | **Confirmed** |
| Return advanced dest | `MOV EAX,EDI` | **Confirmed** |
| Decomp empty `FUN_00409f30()` | bytes override EAX/EDX setup | **High** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| External callers | `FUN_00408050` (2 sites), `FUN_00409ae0` (`xref_count=3`) |
| Callees | `FUN_00409f30` only |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| Half-open range + stride 0x28 | **Yes** |
| Element leaf dualed PodCopy 0x28 | **Yes** |
| InsertN / relocate consumers | **Yes** |
| Product/PDB English for T | **No** |

**Decision:** promote **`StdVector_UninitializedCopy_Elem0x28_Inferred`**.

---

## 7. Gaps

- Product element type demangle (shared with 0x28 family).
- Full dual of trampoline `00409ae0` and parent InsertN `00408050`.
- Twin Elem12 range `0040a590` residual (not this OWN).
- Runtime / bit-exact / differential.

---

## 8. Verdict

CF/ABI/stride/leaf sealed; product + parent residual → **accept-with-gaps**.
