# Review A (reconstruction fidelity): `aa_00409880` StdTree_NodeCtor_Val24_Isnil29_EaxThis_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00409880` |
| **VA** | `0x00409880` |
| **Body** | `0x00409880`–`0x004098c4` inclusive (**69** B / `0x45`) |
| **Canonical name** | `StdTree_NodeCtor_Val24_Isnil29_EaxThis_Inferred` |
| **Ghidra symbol** | `FUN_00409880` |
| **Review date** | `2026-08-04` (WQ9J-H OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00409880_StdTree_NodeCtor_Val24_Isnil29_EaxThis_Inferred.md` |
| **System** | STL / map-set node construct |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

In-place construct of one **isnil@+0x29** tree node with **Val24** payload (links + 6 dwords + color + isnil=0). No allocation. Used by SEH buynode `FUN_00404180` after `operator_new(0x30)`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ WQ9J-H re-verify) | `docs/reconstruction/raw/aa_00409880_FUN_00409880.md` |
| Annotated | `docs/reconstruction/raw/aa_00409880_FUN_00409880.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_NodeCtor_Val24_Isnil29_EaxThis_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_00409880.cpp` |
| Function record | `docs/reconstruction/functions/aa_00409880_StdTree_NodeCtor_Val24_Isnil29_EaxThis_Inferred.md` |
| Live body | `disassemble_function` + `read_memory` @ `0x00409880` / epilogue `C2 0C 00` |
| Sole caller | `FUN_00404180` @ `0x004041d6` |
| Grandparent insert | `FUN_004069f0` (map/set too long) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 69 B + `ret 0xc` | **Confirmed** | Ghidra bounds + epilogue bytes `5E C2 0C 00` |
| EAX = node; ECX = value*; EDX = left; 3 stack args | **Confirmed** | disasm entry + caller wire |
| Val24 @+0x10 (6 dwords); color@+0x28; isnil0@+0x29 | **Confirmed** | decompile ≡ disasm stores |
| +0x0C not written | **Confirmed** | no store to [EAX+0xC] |
| Leaf (no callees) | **Confirmed** | analyze + xrefs_from empty |
| Sole caller `00404180` | **Confirmed** | 1 UNCONDITIONAL_CALL |
| Twin of thiscall `004098d0` (ABI only) | **Confirmed** | same store map |
| Product / PDB demangle | **Open** | `_Inferred` |
| Runtime / bit-exact / differential | **Open** | deferred |

---

## 4. Control flow: raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| Store L from EDX | **Yes** |
| Store P/R from stack | **Yes** |
| Copy 6 dwords from ECX → +0x10 | **Yes** |
| color@+0x28; isnil@+0x29=0; RET 0xC | **Yes** |

---

## 5. Naming gate

| Evidence | Present? |
|---|---|
| isnil@+0x29 family | **Yes** |
| Val24 (6 dwords) | **Yes** |
| EAX-this usercall (distinct from thiscall twin) | **Yes** |
| Product/PDB English | **No** |

**Decision:** promote **`StdTree_NodeCtor_Val24_Isnil29_EaxThis_Inferred`** (structural High; English unproven). Reject freelist/CNDHash; reject merge with `004098d0`; reject chain-of-caller Client scaffold.

---

## 6. Gaps

1. Product/PDB symbol for value_type.
2. Full dual of parent buynode `FUN_00404180` / insert `FUN_004069f0` (not OWN).
3. Runtime / bit-exact / image diff.

**Verdict:** **accept-with-gaps**
