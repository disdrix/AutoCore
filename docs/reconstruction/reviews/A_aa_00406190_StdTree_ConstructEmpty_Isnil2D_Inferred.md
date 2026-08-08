# Review A (reconstruction fidelity): `aa_00406190` StdTree_ConstructEmpty_Isnil2D_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00406190` |
| **VA** | `0x00406190` |
| **Body** | `0x00406190`–`0x004061e9` inclusive (**90** B / `0x5A`) |
| **Canonical name** | `StdTree_ConstructEmpty_Isnil2D_Inferred` |
| **Ghidra symbol** | `FUN_00406190` |
| **Review date** | `2026-08-05` (WQ9K-D OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00406190_StdTree_ConstructEmpty_Isnil2D_Inferred.md` |
| **System** | STL / map-set empty construct |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `disassemble_function` + `read_memory` epilogue + callers/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Finish **empty tree** construction for the **isnil@+0x2d / 0x30** family: buy blank head, install as `_Myhead`, force isnil=1, self-link extremities, zero size.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ WQ9K-D re-verify) | `docs/reconstruction/raw/aa_00406190_FUN_00406190.md` |
| Annotated | `docs/reconstruction/raw/aa_00406190_FUN_00406190.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_ConstructEmpty_Isnil2D_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_00406190.cpp` |
| Function record | `docs/reconstruction/functions/aa_00406190_StdTree_ConstructEmpty_Isnil2D_Inferred.md` |
| Live body | `disassemble_function` + `read_memory` @ epilogue → `83 C4 0C C2 04 00` |
| Head buy | dualed `aa_00409780` / `StdTree_BuyHeadNode_Isnil2D_Inferred` |
| Caller | `FUN_00404e40` @ `0x00404e76` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 90 B + `ret 0x4` | **Confirmed** | disasm + epilogue bytes |
| `__stdcall` 1 stack arg; returns shell* | **Confirmed** | `MOV ESI,[ESP+0x14]`; `MOV EAX,ESI` before ret |
| Calls buyhead `00409780` | **Confirmed** | sole callee |
| isnil@+0x2d = 1 | **Confirmed** | `MOV byte ptr [EAX+0x2d],1` |
| Self-link L/P/R | **Confirmed** | three stores of head to L/P/R |
| size@+8 = 0 | **Confirmed** | `MOV [ESI+8],0` |
| Sole caller host+0x0C subobject | **Confirmed** | 1 xref |
| SEH frame present | **Confirmed** | FS:[0] / `LAB_009bd1a8` |
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
| isnil@+0x2d + buyhead 0x30 dualed | **Yes** |
| Classic empty-tree head install CF | **Yes** |
| Host ctor is host only (not product method name) | **Yes** |
| Product/PDB English | **No** |

**Decision:** promote **`StdTree_ConstructEmpty_Isnil2D_Inferred`**. Reject isnil29/31 empty-construct merge; reject freelist/CNDHash.

---

## 6. Gaps

1. Product key/value type for host+0x0C map/set.
2. Shell+0 allocator/comp identity.
3. Runtime / bit-exact / image diff.

**Verdict:** **accept-with-gaps**
