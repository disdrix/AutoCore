# Review A (reconstruction fidelity): `aa_00409180` StdTree_BuyHeadNode_Isnil31_Size0x38_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00409180` |
| **VA** | `0x00409180` |
| **Body** | `0x00409180`–`0x00409209` exclusive (**137** B / `0x89`) |
| **Canonical name** | `StdTree_BuyHeadNode_Isnil31_Size0x38_Inferred` |
| **Ghidra symbol** | `FUN_00409180` |
| **Review date** | `2026-08-04` (WQ9J-F OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00409180_StdTree_BuyHeadNode_Isnil31_Size0x38_Inferred.md` |
| **System** | STL / map-set head node |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` / `decompile_function` + `analyze_function_complete` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Allocate a blank **0x38** isnil@+0x31-family node with links zeroed, color black, isnil=0. Tree **ctor wrapper** installs it as head (isnil=1 + self-link + size=0).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ WQ9J-F re-verify) | `docs/reconstruction/raw/aa_00409180_FUN_00409180.md` |
| Annotated | `docs/reconstruction/raw/aa_00409180_FUN_00409180.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_BuyHeadNode_Isnil31_Size0x38_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_00409180.cpp` |
| Function record | `docs/reconstruction/functions/aa_00409180_StdTree_BuyHeadNode_Isnil31_Size0x38_Inferred.md` |
| Live body | `read_memory` @ `0x00409180` / bare `C3` epilogue |
| Caller | `FUN_00405f20` decompile + assembly context @ `0x00405f3a` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 137 B + bare `ret` | **Confirmed** | bounds + bytes |
| No stack args; EAX = node | **Confirmed** | caller `MOV [ESI+4],EAX`; decomp void is false |
| `operator_new(0x38)` | **Confirmed** | `PUSH 0x38` |
| Zero L/P/R; color=1 @+0x30; isnil=0 @+0x31 | **Confirmed** | `MOV [EAX+0x30],BL` / `MOV [EAX+0x31],DL` |
| Sole caller head-install | **Confirmed** | isnil1 + self-link + size0 |
| SEH frame present | **Confirmed** | FS:[0] / `LAB_009bc670` |
| isnil31 / 0x38 family | **Confirmed** | matches iterator++ twin isnil offset |
| Not freelist / not Client ctor product | **Confirmed** | structural only |
| Product / PDB demangle | **Open** | `_Inferred` |
| Runtime / bit-exact / differential | **Open** | deferred |

---

## 4. Control flow: raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| SEH setup → new(0x38) | **Yes** |
| Zero links (MSVC field checks) | **Yes** |
| color black + isnil0 | **Yes** |
| bare RET; EAX node | **Yes** |

---

## 5. Naming gate

| Evidence | Present? |
|---|---|
| 0x38 node + isnil@+0x31 | **Yes** |
| Sole caller is tree-head installer | **Yes** |
| Self-link / isnil1 outside this unit | **Yes** (honest gap) |
| Product/PDB English | **No** |

**Decision:** promote **`StdTree_BuyHeadNode_Isnil31_Size0x38_Inferred`**. Reject `Named_CalleeOf_Named_Client_Constructor_*` scaffold; reject freelist/CNDHash; reject claim that self-link happens inside this VA.

---

## 6. Gaps

1. Product/PDB symbol for host tree types.
2. Dual of ctor wrapper `FUN_00405f20` (not OWN).
3. Val36 payload English type.
4. Runtime / bit-exact / image diff.

**Verdict:** **accept-with-gaps**
