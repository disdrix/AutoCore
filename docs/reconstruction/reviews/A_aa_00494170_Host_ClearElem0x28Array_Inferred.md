# Review A (reconstruction fidelity): `aa_00494170` Host_ClearElem0x28Array_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00494170` |
| **VA** | `0x00494170`–`0x004941af` exclusive (**64 B** / `0x40`) |
| **Canonical name** | `Host_ClearElem0x28Array_Inferred` |
| **Ghidra name** | `FUN_00494170` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W30-Q) |
| **Counterpart** | `reviews/B_aa_00494170_Host_ClearElem0x28Array_Inferred.md` |
| **System** | host / cookie-vector free (stride 0x28) |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `get_function_by_address` + `read_memory` (full body). **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Free MSVC cookie-vector of **0x28-byte** elements at `host+0x28` (dtor `FUN_005b8000`), then zero `+0x28/+4/+8`. Standalone free half of the host array pair; rebuild is `0x004941b0`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W30-Q) | `docs/reconstruction/raw/aa_00494170_FUN_00494170.md` |
| Annotated | `docs/reconstruction/raw/aa_00494170_FUN_00494170.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/Host_ClearElem0x28Array_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00494170.cpp` |
| Function records | `functions/aa_00494170_FUN_00494170.md`, `functions/aa_00494170_Host_ClearElem0x28Array_Inferred.md` |
| Element dtor | `Elem0x28_CompleteDtor` (`aa_005b8000`, W29-F) |
| Live | decompile ≡ raw; body 64 B; bare `C3`; zero static xrefs |

---

## 3. Signature (sealed)

```c
// ECX=host; bare RET; void
void __fastcall Host_ClearElem0x28Array_Inferred(void* host);
```

| Formal | Source | Conf |
|---|---|---|
| host | ECX (`8B F1`) | **High** |
| return | void | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
arr = host+0x28
if arr:
  eh_vector_dtor_iter(arr, 0x28, count@arr-4, FUN_005b8000)
  operator_delete[](arr-4)
host+0x28 = 0
host+4 = 0
host+8 = 0
RET
```

| Stage | Match | Conf |
|---|---|---|
| Vector free stride 0x28 | **Yes** | **High** |
| Cookie at arr-4 | **Yes** | **High** |
| Zero triple | **Yes** | **High** |
| Body size / bare RET | **Yes** (`get_function_by_address` 00494170–004941af) | **High** |

---

## 5. Gaps

- Product/PDB host type English.
- No static callers (orphan vs static graph) — usage open.
- Runtime / bit-exact / differential.

---

## 6. Verdict

CF/ABI/stride/zero-triple sealed against live decompile + body bounds. Residual product name + static-use → **accept-with-gaps**.
