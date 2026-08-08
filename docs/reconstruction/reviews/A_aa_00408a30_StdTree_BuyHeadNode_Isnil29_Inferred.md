# Review A (reconstruction fidelity): `aa_00408a30` StdTree_BuyHeadNode_Isnil29_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00408a30` |
| **VA** | `0x00408a30` |
| **Body** | `0x00408a30`–`0x00408ab9` inclusive (**138** B / `0x8A`) |
| **Canonical name** | `StdTree_BuyHeadNode_Isnil29_Inferred` |
| **Ghidra symbol** | `FUN_00408a30` |
| **Review date** | `2026-08-04` (WQ9H-J OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00408a30_StdTree_BuyHeadNode_Isnil29_Inferred.md` |
| **System** | STL / map-set head node |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` / `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Allocate a blank **0x30** isnil@+0x29-family node with links zeroed, color black, isnil=0. Tree **ctor wrappers** install it as head (isnil=1 + self-link + size=0).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ WQ9H-J re-verify) | `docs/reconstruction/raw/aa_00408a30_FUN_00408a30.md` |
| Annotated | `docs/reconstruction/raw/aa_00408a30_FUN_00408a30.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_BuyHeadNode_Isnil29_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_00408a30.cpp` |
| Function record | `docs/reconstruction/functions/aa_00408a30_StdTree_BuyHeadNode_Isnil29_Inferred.md` |
| Live body | `disassemble_function` + `read_memory` @ `0x00408a30` / bare `C3` |
| Callers | `FUN_00405b40`, `FUN_00405e60`, `FUN_00405fb0`, `FUN_004d98f0` + assembly context |
| Sample ctor | `FUN_00405fb0` decompile (head install pattern) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 138 B + bare `ret` | **Confirmed** | disasm + bytes |
| No stack args; EAX = node | **Confirmed** | callers `MOV [host+4],EAX`; decomp void is false |
| `operator_new(0x30)` | **Confirmed** | `PUSH 0x30` |
| Zero L/P/R; color=1 @+0x28; isnil=0 @+0x29 | **Confirmed** | disasm stores |
| Callers set isnil=1 + self-link + size0 | **Confirmed** | all 4 sites identical pattern |
| SEH frame present | **Confirmed** | FS:[0] / `LAB_009bc690` |
| isnil29 / 0x30 family | **Confirmed** | matches Val24 node size peers |
| Not CNDHash freelist / not Val16 buynode | **Confirmed** | no freelist; no stack value args |
| Product / PDB demangle | **Open** | `_Inferred` |
| Runtime / bit-exact / differential | **Open** | deferred |

---

## 4. Control flow: raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| SEH setup → new(0x30) | **Yes** |
| Zero links (MSVC field checks) | **Yes** |
| color black + isnil0 | **Yes** |
| bare RET; EAX node | **Yes** |

---

## 5. Naming gate

| Evidence | Present? |
|---|---|
| 0x30 node + isnil@+0x29 | **Yes** |
| All callers are tree-head installers | **Yes** |
| Self-link / isnil1 outside this unit | **Yes** (honest gap) |
| Product/PDB English | **No** |

**Decision:** promote **`StdTree_BuyHeadNode_Isnil29_Inferred`**. Reject `Named_CalleeOf_Named_Client_Constructor_*` scaffold; reject freelist/CNDHash; reject full `_Buyheadnode` claim that includes self-link inside this VA.

---

## 6. Gaps

1. Product/PDB symbol for host tree types.
2. Full dual of ctor wrappers (not OWN).
3. OOM crash shape if new returned null without throw (preserve odd).
4. Runtime / bit-exact / image diff.

**Verdict:** **accept-with-gaps**
