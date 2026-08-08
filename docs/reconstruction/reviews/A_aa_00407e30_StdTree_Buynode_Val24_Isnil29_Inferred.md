# Review A (reconstruction fidelity): `aa_00407e30` StdTree_Buynode_Val24_Isnil29_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00407e30` |
| **VA** | `0x00407e30` |
| **Body** | `0x00407e30`–`0x00407eb4` exclusive (**132** B) |
| **Canonical name** | `StdTree_Buynode_Val24_Isnil29_Inferred` |
| **Ghidra symbol** | `FUN_00407e30` |
| **Review date** | `2026-08-04` (WQ9F-B OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00407e30_StdTree_Buynode_Val24_Isnil29_Inferred.md` |
| **System** | STL / map-set buynode |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` / `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` entry/epilogue + callers/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Allocate and construct one **isnil@+0x29** tree node with **Val24** payload for the dualed always-insert path (`0x00406c40`).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ WQ9F-B re-verify) | `docs/reconstruction/raw/aa_00407e30_FUN_00407e30.md` |
| Annotated | `docs/reconstruction/raw/aa_00407e30_FUN_00407e30.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Buynode_Val24_Isnil29_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_00407e30.cpp` |
| Function record | `docs/reconstruction/functions/aa_00407e30_StdTree_Buynode_Val24_Isnil29_Inferred.md` |
| Live body | `disassemble_function` + `read_memory` @ `0x00407e30` / epilogue `C2 14 00` |
| Ctor | `FUN_004098d0` decompile |
| Parent insert | dualed `aa_00406c40` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 132 B + `ret 0x14` | **Confirmed** | Ghidra bounds + epilogue bytes |
| `__stdcall` 5 stack args; EAX return | **Confirmed** | disasm; no ECX this |
| `operator_new(0x30)` | **Confirmed** | `PUSH 0x30` + call |
| Ctor links + 6 dwords + color + isnil0 | **Confirmed** | `FUN_004098d0` decompile |
| Sole caller insert `00406c40` | **Confirmed** | 1 xref |
| SEH frame present | **Confirmed** | FS:[0] prologue |
| Distinct from `005a2de0` (no-SEH twin) | **Confirmed** | decompile contrast |
| Product / PDB demangle | **Open** | `_Inferred` |
| Runtime / bit-exact / differential | **Open** | deferred |

---

## 4. Control flow: raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| SEH setup → new(0x30) | **Yes** |
| null skip / else ctor | **Yes** |
| return node; RET 0x14 | **Yes** |

---

## 5. Naming gate

| Evidence | Present? |
|---|---|
| Node size + isnil@+0x29 family | **Yes** |
| Val24 (6 dwords) from ctor | **Yes** |
| Parent dualed insert | **Yes** |
| Product/PDB English | **No** |

**Decision:** promote **`StdTree_Buynode_Val24_Isnil29_Inferred`** (structural High; English unproven). Reject chain-of-caller VOGClient scaffold; reject Val12 buynode merge.

---

## 6. Gaps

1. Product/PDB symbol.
2. Full dual of ctor `FUN_004098d0` (not OWN).
3. Runtime / bit-exact / image diff.

**Verdict:** **accept-with-gaps**
