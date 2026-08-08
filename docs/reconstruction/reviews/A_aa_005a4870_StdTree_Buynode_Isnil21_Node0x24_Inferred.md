# Review A (reconstruction fidelity): `aa_005a4870` StdTree_Buynode_Isnil21_Node0x24_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005a4870` |
| **VA** | `0x005a4870` |
| **Body** | `0x005a4870`–`0x005a48f5` inclusive (**134** B / `0x86`) |
| **Canonical name** | `StdTree_Buynode_Isnil21_Node0x24_Inferred` |
| **Ghidra symbol** | `FUN_005a4870` |
| **Review date** | `2026-08-05` (R13-008 OWN dual; dual start **2686**) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_005a4870_StdTree_Buynode_Isnil21_Node0x24_Inferred.md` |
| **System** | skills-abilities partition; structural STL / map-set buynode |
| **Parent dual** | `0x005a4590` StdTree_EraseAndRebalance_Isnil21_Inferred (R12-032) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_by_address` + `get_function_callers` / `get_function_xrefs` / `get_function_callees` + `read_memory` entry/color/epilogue. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Allocate and construct one **isnil@+0x21 / node 0x24** tree node (u32 key + vector-like dword payload) for dualed always-insert `0x005a4950`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ R13-008 re-verify) | `docs/reconstruction/raw/aa_005a4870_FUN_005a4870.md` |
| Annotated | `docs/reconstruction/raw/aa_005a4870_FUN_005a4870.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Buynode_Isnil21_Node0x24_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_005a4870.cpp` |
| Function record | `docs/reconstruction/functions/aa_005a4870_StdTree_Buynode_Isnil21_Node0x24_Inferred.md` |
| Live body | `disassemble_function` + `read_memory` @ `0x005a4870` / color `0x005a48d7` / epilogue `C2 14 00` |
| Payload ctor | `FUN_005a42d0` decompile (thiscall ECX=node+0x10) |
| Caller insert | dualed `aa_005a4950` (R12-033) |
| Parent erase | dualed `aa_005a4590` (R12-032) — same node family |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 134 B + `ret 0x14` | **High** | Ghidra bounds `005a4870`–`005a48f5` + epilogue bytes |
| `__stdcall` 5 stack args; EAX return | **High** | disasm; no ECX this on entry; `MOV EAX,ESI` |
| `operator_new(0x24)` | **High** | `PUSH 0x24` + call @ `0x00489892` |
| Links + key@+0x0C + color@+0x20 + isnil0@+0x21 | **High** | disasm + `read_memory` |
| Vector-like payload via `005a42d0` @+0x10; heap @+0x14/18/1c | **High** | `LEA ECX,[ESI+0x10]` + callee decompile |
| Sole caller insert `005a4950` | **High** | 1 xref @ `005a49e2` |
| SEH frame present | **High** | FS:[0] / `LAB_009a6321` |
| Distinct from Val16/0x28 and Val24/isnil29 buynodes | **High** | size + isnil offset + construct path |
| Product / PDB demangle | **Open** | `_Inferred` |
| Runtime / bit-exact / differential | **Open** | deferred; **not** Runtime Confirmed |

---

## 4. Control flow: raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| SEH setup → new(0x24) | **Yes** |
| null skip / else links+key+vec+color+isnil0 | **Yes** |
| return node; RET 0x14 | **Yes** |

---

## 5. Naming gate

| Evidence | Present? |
|---|---|
| Node size 0x24 + isnil@+0x21 | **Yes** |
| Color@+0x20; red from insert color=0 | **Yes** |
| u32 key + vector-like (not flat Val16) | **Yes** |
| Parent/sibling erase+insert dualed same family | **Yes** |
| Product/PDB English | **No** |

**Decision:** promote **`StdTree_Buynode_Isnil21_Node0x24_Inferred`** (structural High; English unproven). Reject freelist/CNDHash; reject Val16/0x28 merge; reject Val24/isnil29 merge; reject skill-product exclusive names; reject chain-of-caller scaffold.

---

## 6. Gaps

1. Product/PDB symbol for map value_type.
2. Full dual of payload ctor `FUN_005a42d0` (not OWN).
3. Runtime / bit-exact / image diff.

**Verdict:** **accept-with-gaps**
