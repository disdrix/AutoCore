# Review A (reconstruction fidelity): `aa_0041d860` StdTree_Buynode_CharKey_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0041d860` |
| **VA** | `0x0041d860` |
| **Body** | `0x0041d860`–`0x0041d8e5` inclusive (**134** B / `0x86`) |
| **Canonical name** | `StdTree_Buynode_CharKey_Isnil21_Inferred` |
| **Ghidra symbol** | `FUN_0041d860` |
| **Review date** | `2026-08-05` (R13-023 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_0041d860_StdTree_Buynode_CharKey_Isnil21_Inferred.md` |
| **System** | skills-abilities / STL map-set buynode |
| **Parent dual** | `0x0041ba30` StdTree_InsertAndRebalance_CharKey_Isnil21_Inferred (R12-011) |
| **Dual start** | 2686 |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` entry/epilogue + `get_function_callers` / `get_function_xrefs` / `get_xrefs_to` + `get_function_by_address`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Allocate and construct one **isnil@+0x21** tree node with **char key** @+0x0C and residual value body @+0x10 for dualed always-insert `FUN_0041ba30`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ R13-023 re-verify) | `docs/reconstruction/raw/aa_0041d860_FUN_0041d860.md` |
| Annotated | `docs/reconstruction/raw/aa_0041d860_FUN_0041d860.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Buynode_CharKey_Isnil21_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_0041d860.cpp` |
| Function record | `docs/reconstruction/functions/aa_0041d860_StdTree_Buynode_CharKey_Isnil21_Inferred.md` |
| Live body | `disassemble_function` + `read_memory` @ `0x0041d860` / epilogue `C2 14 00` |
| Value residual | `FUN_0041c140` decompile + disasm (`RET 0x4`, thiscall) |
| Parent insert | dualed `FUN_0041ba30` / call site `0x0041ba9d` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 134 B + `ret 0x14` | **High** | Ghidra bounds `0041d860`–`0041d8e5`; epilogue `C2 14 00` |
| `__stdcall` 5 stack args; EAX return | **High** | stack slots `[EBP+8..0x18]`; no ECX this on entry; `MOV EAX,ESI` |
| `operator_new(0x24)` | **High** | `PUSH 0x24` + call |
| Links L/P/R + char@+0x0C + color@+0x20 + isnil0@+0x21 | **High** | disasm stores |
| Value construct thiscall `FUN_0041c140` @ node+0x10 | **High** | `LEA ECX,[ESI+0x10]` (decomp omits ECX) |
| Sole caller insert `0041ba30` | **High** | 1 xref @ `0041ba9d` |
| SEH frame present | **High** | FS:[0] / `LAB_009bd7d1` |
| Distinct from Val16/isnil21 0x28 buynode `00408990` | **High** | size 0x24; char key; residual vector body |
| Product / PDB demangle | **Open** | `_Inferred` |
| Runtime / bit-exact / differential | **Open** | deferred; **never Runtime Confirmed** |

---

## 4. Control flow: raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| SEH setup → new(0x24) | **Yes** |
| null skip / else link+key+value+color+isnil | **Yes** |
| return node; RET 0x14 | **Yes** |

---

## 5. Naming gate

| Evidence | Present? |
|---|---|
| Node size 0x24 + isnil@+0x21 + color@+0x20 | **Yes** |
| Char key @+0x0C | **Yes** |
| Parent always-insert dualed CharKey isnil21 | **Yes** |
| Product/PDB English | **No** |

**Decision:** promote **`StdTree_Buynode_CharKey_Isnil21_Inferred`** (structural High; English unproven). Reject freelist/CNDHash; reject Val16/Val24 merges; reject chain-of-caller scaffold; reject skill-product method name; reject Runtime Confirmed.

---

## 6. Gaps

1. Product/PDB symbol for map instantiation / value_type.
2. Full dual of residual value ctor `FUN_0041c140` (and its callees) — not OWN.
3. Runtime / bit-exact / image diff.

**Verdict:** **accept-with-gaps**
