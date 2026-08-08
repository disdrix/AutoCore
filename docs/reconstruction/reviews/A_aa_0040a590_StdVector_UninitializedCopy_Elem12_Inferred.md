# Review A (reconstruction fidelity): `aa_0040a590` StdVector_UninitializedCopy_Elem12_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040a590` |
| **VA** | `0x0040a590`–`0x0040a5f4` inclusive (**101 B** / `0x65`) |
| **Canonical name** | `StdVector_UninitializedCopy_Elem12_Inferred` |
| **Ghidra name** | `FUN_0040a590` |
| **Review date** | `2026-08-05` (WQ9K-J OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_0040a590_StdVector_UninitializedCopy_Elem12_Inferred.md` |
| **System** | MSVC-style vector uninitialized_copy (elem 0x0C) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` + `disassemble_function` + `analyze_function_complete` + `read_memory` + `get_assembly_context` + callers/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Range **POD uninitialized_copy**: walk half-open `[src_begin, src_end)` into `dest` with **stride 0x0C**, calling dualed element leaf `StdVector_PodCopyElement_Elem12_Inferred` each step; return advanced destination end. Used by InsertN/reallocate path `FUN_004082f0`.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ raw CF (2026-08-05) |
| Full body hex | 101 B via `read_memory` |
| Assembly listing | `disassemble_function` (not disassemble_bytes) |
| Call sites | `004084ea`, `0040854e` (InsertN); trampoline `00409b50` |
| Element leaf dual | WQ9J-A `aa_00409f50` |
| Twin 0x28 range | WQ9J-A `aa_0040a520` (same skeleton, stride/leaf differ) |

---

## 3. Signature (sealed)

```c
// ECX=src_end; stack src_begin, dest; EAX=dest_end; plain RET
void* StdVector_UninitializedCopy_Elem12_Inferred(
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
| element call | EAX=EDI dest, ECX=ESI src → `00409f50` | **Confirmed** |

---

## 4. Control flow (sealed)

| Stage | Match | Conf |
|---|---|---|
| SEH prolog/epilog | `PUSH 0x9bd0a0` / FS:[0] | **Confirmed** |
| Empty range early out | `CMP ESI,EBX` / `JZ` | **Confirmed** |
| PodCopy + both +0x0C | CALL + two ADDs of 0xC | **Confirmed** |
| Return advanced dest | `MOV EAX,EDI` | **Confirmed** |
| Decomp empty `FUN_00409f50()` | bytes override EAX/ECX setup | **High** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| External callers | `FUN_004082f0` (2 sites), `FUN_00409b40` (`xref_count=3`) |
| Callees | `FUN_00409f50` only |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| Half-open range + stride 0x0C | **Yes** |
| Element leaf dualed PodCopy Elem12 | **Yes** |
| InsertN / relocate consumers | **Yes** |
| Product/PDB English for T | **No** |

**Decision:** promote **`StdVector_UninitializedCopy_Elem12_Inferred`**.

---

## 7. Gaps

- Product element type demangle (shared with 0x0C family).
- Full dual of trampoline `00409b40` and parent InsertN `004082f0`.
- Runtime / bit-exact / differential.

---

## 8. Verdict

CF/ABI/stride/leaf sealed; product + parent residual → **accept-with-gaps**.
