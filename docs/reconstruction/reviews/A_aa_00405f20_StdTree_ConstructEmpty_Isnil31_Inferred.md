# Review A (reconstruction fidelity): `aa_00405f20` StdTree_ConstructEmpty_Isnil31_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00405f20` |
| **VA** | `0x00405f20` |
| **Body** | `0x00405f20`–`0x00405f7a` exclusive (**90** B / `0x5A`) |
| **Canonical name** | `StdTree_ConstructEmpty_Isnil31_Inferred` |
| **Ghidra symbol** | `FUN_00405f20` |
| **Review date** | `2026-08-04` (WQ9K-C OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00405f20_StdTree_ConstructEmpty_Isnil31_Inferred.md` |
| **System** | STL / map-set empty construct |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `disassemble_function` + `read_memory` epilogue + callers/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Finish **empty tree** construction for the **isnil@+0x31 / 0x38** family: buy blank head, install as `_Myhead`, force isnil=1, self-link extremities, zero size.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ WQ9K-C re-verify) | `docs/reconstruction/raw/aa_00405f20_FUN_00405f20.md` |
| Annotated | `docs/reconstruction/raw/aa_00405f20_FUN_00405f20.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_ConstructEmpty_Isnil31_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_00405f20.cpp` |
| Function record | `docs/reconstruction/functions/aa_00405f20_StdTree_ConstructEmpty_Isnil31_Inferred.md` |
| Live body | `disassemble_function` + `read_memory` @ `0x00405f74` → `83 C4 0C C2 04 00` |
| Head buy | dualed `aa_00409180` / `StdTree_BuyHeadNode_Isnil31_Size0x38_Inferred` |
| Caller | Client ctor `FUN_009495c0` @ `0x00949d37` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 90 B + `ret 0x4` | **Confirmed** | disasm + epilogue bytes |
| `__stdcall` 1 stack arg; returns shell* | **Confirmed** | `MOV ESI,[ESP+0x14]`; `MOV EAX,ESI` before ret |
| Calls buyhead `00409180` | **Confirmed** | sole callee |
| isnil@+0x31 = 1 | **Confirmed** | `MOV byte ptr [EAX+0x31],1` |
| Self-link L/P/R | **Confirmed** | three stores of head to L/P/R |
| size@+8 = 0 | **Confirmed** | `MOV [ESI+8],0` |
| Sole caller Client ctor subobject | **Confirmed** | 1 xref; `param_1+0x3c5` |
| SEH frame present | **Confirmed** | FS:[0] / `LAB_009bdb18` |
| Product map English | **Open** | `_Inferred` |
| Runtime / bit-exact / differential | **Open** | deferred |

---

## 4. Control flow: raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| SEH setup → buyhead | **Yes** |
| install head / isnil1 / self-link / size0 | **Yes** |
| return shell; RET 0x4 | **Yes** |

---

## 5. Naming gate

| Evidence | Present? |
|---|---|
| isnil@+0x31 + buyhead 0x38 dualed | **Yes** |
| Classic empty-tree head install CF | **Yes** |
| Client ctor is host only (not product method name) | **Yes** |
| Product/PDB English | **No** |

**Decision:** promote **`StdTree_ConstructEmpty_Isnil31_Inferred`**. Reject `Named_CalleeOf_Named_Client_Constructor_*` scaffold; reject claim this *is* Client product method; reject isnil29 head-wrapper merge.

---

## 6. Gaps

1. Product key/value type for Client+0xF14 map/set.
2. Shell+0 allocator/comp identity.
3. Runtime / bit-exact / image diff.

**Verdict:** **accept-with-gaps**
