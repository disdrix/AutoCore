# Review A (reconstruction fidelity): `aa_00409b80` StdTree_DestroyStringAt0C_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00409b80` |
| **VA** | `0x00409b80`–`0x00409bc0` inclusive (**65 B** / `0x41`) |
| **Canonical name** | `StdTree_DestroyStringAt0C_Inferred` |
| **Ghidra name** | `FUN_00409b80` |
| **Review date** | `2026-08-05` (WQ9K-A OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00409b80_StdTree_DestroyStringAt0C_Inferred.md` |
| **System** | MSVC-style tree node value destroy (`basic_string` @ +0x0c) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` + `disassemble_function` + `analyze_function_complete` + `read_memory` + `get_assembly_context` + callers/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Shared **tree-node string value destroy** for free-subtree twins: under SEH, call `~std::basic_string` at **node+0x0c**, then return. Does **not** free the node — callers `operator_delete` after.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ scaffold (`~basic_string` @ +0x0c + SEH) |
| Full body hex | 65 B via `read_memory` |
| Assembly listing | `disassemble_function` |
| Call sites | `00409942` (isnil131 free), `0040998f` (isnil2d free) |
| Free-subtree duals | WQ9J-I `aa_00409920` / `aa_00409970` |

---

## 3. Signature (sealed)

```c
// stdcall; stack node*; void; RET 4
void __stdcall StdTree_DestroyStringAt0C_Inferred(void* node);
```

| Formal | Source | Conf |
|---|---|---|
| node | `[ESP+4]` after SEH pushes → `[ESP+0x10]` | **Confirmed** |
| string this | `ECX = node + 0x0c` | **Confirmed** |
| dtor | IAT CALL `[0x009c62f4]` thiscall | **Confirmed** |
| cleanup | `ADD ESP,0x0C`; **`RET 4`** | **Confirmed** |
| SEH | `LAB_009bc656` / FS:[0] | **Confirmed** |

---

## 4. Control flow (sealed)

| Stage | Match | Conf |
|---|---|---|
| SEH prolog | PUSH -1 / handler / FS | **Confirmed** |
| ADD ECX,0x0C | string offset | **Confirmed** |
| IAT ~basic_string | decomp + bytes | **Confirmed** |
| SEH epilog + RET 4 | no node free | **Confirmed** |
| No isnil / left / right walk | leaf destroy | **Confirmed** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| External callers | `FUN_00409920`, `FUN_00409970` (`xref_count=2`) |
| Call pattern | `PUSH node; CALL; PUSH node; operator_delete` |
| Callees | `~basic_string` IAT only |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| Decompiler names `~basic_string` | **Yes** |
| Offset +0x0c sealed in bytes | **Yes** |
| Shared free-subtree consumers dualed | **Yes** |
| Product map / key English | **No** |

**Decision:** promote **`StdTree_DestroyStringAt0C_Inferred`** (matches free-subtree `DestroyStr0C` naming).

---

## 7. Gaps

- Product map RTTI / full node layout beyond string @+0x0c.
- Erase-range parents `00407b70` / `00407f90` residual (WQ9K-B).
- Runtime / bit-exact / differential.

---

## 8. Verdict

Fidelity path accepts CF/ABI/string offset with product residual → **accept-with-gaps**.
