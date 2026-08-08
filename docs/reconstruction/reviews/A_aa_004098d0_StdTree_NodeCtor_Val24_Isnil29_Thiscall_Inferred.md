# Review A (reconstruction fidelity): `aa_004098d0` StdTree_NodeCtor_Val24_Isnil29_Thiscall_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004098d0` |
| **VA** | `0x004098d0` |
| **Body** | `0x004098d0`–`0x0040991e` inclusive (**79** B / `0x4F`) |
| **Canonical name** | `StdTree_NodeCtor_Val24_Isnil29_Thiscall_Inferred` |
| **Ghidra symbol** | `FUN_004098d0` |
| **Review date** | `2026-08-04` (WQ9J-H OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_004098d0_StdTree_NodeCtor_Val24_Isnil29_Thiscall_Inferred.md` |
| **System** | STL / map-set node construct |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

In-place construct of one **isnil@+0x29** tree node with **Val24** payload (links + 6 dwords + color + isnil=0). No allocation. Sole caller is dualed buynode `StdTree_Buynode_Val24_Isnil29_Inferred` (`0x00407e30`).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ WQ9J-H re-verify) | `docs/reconstruction/raw/aa_004098d0_FUN_004098d0.md` |
| Annotated | `docs/reconstruction/raw/aa_004098d0_FUN_004098d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_NodeCtor_Val24_Isnil29_Thiscall_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_004098d0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004098d0_StdTree_NodeCtor_Val24_Isnil29_Thiscall_Inferred.md` |
| Live body | `disassemble_function` + `read_memory` @ `0x004098d0` / epilogue `C2 14 00` |
| Sole caller | `FUN_00407e30` @ `0x00407e88` (WQ9F-B dualed) |
| Parent insert | dualed `aa_00406c40` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 79 B + `ret 0x14` | **Confirmed** | Ghidra bounds + epilogue bytes `5E C2 14 00` |
| `__thiscall` ECX=this; 5 stack args | **Confirmed** | disasm `MOV EAX,ECX` then stack loads |
| Val24 @+0x10; color@+0x28; isnil0@+0x29 | **Confirmed** | decompile ≡ disasm stores |
| +0x0C not written | **Confirmed** | no store to [this+0xC] |
| Leaf (no callees) | **Confirmed** | analyze |
| Sole caller buynode `00407e30` | **Confirmed** | 1 UNCONDITIONAL_CALL; WQ9F-B |
| Twin of EAX-this `00409880` | **Confirmed** | same store map |
| Product / PDB demangle | **Open** | `_Inferred` |
| Runtime / bit-exact / differential | **Open** | deferred |

---

## 4. Control flow: raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| this = ECX → EAX scratch | **Yes** |
| Store L/P/R from stack | **Yes** |
| Copy 6 dwords from value* → +0x10 | **Yes** |
| color@+0x28; isnil@+0x29=0; RET 0x14 | **Yes** |

---

## 5. Naming gate

| Evidence | Present? |
|---|---|
| isnil@+0x29 family | **Yes** |
| Val24 (6 dwords) | **Yes** |
| thiscall + RET 0x14 | **Yes** |
| Dualed buynode caller | **Yes** |
| Product/PDB English | **No** |

**Decision:** promote **`StdTree_NodeCtor_Val24_Isnil29_Thiscall_Inferred`** (structural High; English unproven). Reject freelist; reject merge with EAX twin; reject chain-of-caller scaffold.

---

## 6. Gaps

1. Product/PDB symbol for value_type.
2. Runtime / bit-exact / image diff.

**Verdict:** **accept-with-gaps**
