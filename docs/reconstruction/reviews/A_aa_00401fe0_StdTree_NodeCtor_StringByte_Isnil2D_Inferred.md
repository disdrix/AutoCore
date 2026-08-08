# Review A (reconstruction fidelity): `aa_00401fe0` StdTree_NodeCtor_StringByte_Isnil2D_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00401fe0` |
| **VA** | `0x00401fe0`–`0x0040203a` exclusive (**90** B / `0x5A`) |
| **Canonical name** | `StdTree_NodeCtor_StringByte_Isnil2D_Inferred` |
| **Ghidra symbol** | `FUN_00401fe0` |
| **Prior scaffold** | `FUN_00401fe0` / `Named_CalleeOf_*Nam_00401fe0` |
| **Review date** | `2026-08-05` (R10-004 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00401fe0_StdTree_NodeCtor_StringByte_Isnil2D_Inferred.md` |
| **System** | STL / map-set node construct (partition: missions-progression null dialog) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs/callees. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

In-place construct one **isnil@+0x2d** tree node (**size 0x30**) whose value is **MSVC `basic_string` + 1 mapped byte**, for dualed buynode `FUN_00401f40` after `operator_new(0x30)` (insert/rebalance residual `FUN_00401db0` / string-key insert-or-find `FUN_00401c50` under mission null-dialog partition host).

```text
StdTree_NodeCtor_StringByte_Isnil2D_Inferred(node, parent, right, left, value*, color)
  SEH install (LAB_009bc7ed)
  node->left/parent/right = L/P/R
  FUN_00402040(&node->value @ +0x0c)  // EDI = value* → string + byte
  node->color = color @ +0x2c
  node->isnil = 0 @ +0x2d
  return node  // EAX
  RET 0xC
```

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ R10-004 re-verify) | `docs/reconstruction/raw/aa_00401fe0_FUN_00401fe0.md` |
| Annotated | `docs/reconstruction/raw/aa_00401fe0_FUN_00401fe0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_NodeCtor_StringByte_Isnil2D_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_00401fe0.cpp` |
| Function record | `docs/reconstruction/functions/aa_00401fe0_StdTree_NodeCtor_StringByte_Isnil2D_Inferred.md` |
| Live body | `disassemble_function` + `read_memory` @ `0x00401fe0` / epilogue `C2 0C 00` |
| Value | dualed `FUN_00402040` `BasicStringFlag_CopyCtor_EdiSrc_Inferred` |
| Buynode caller | dualed `FUN_00401f40` call-site @ `0x00401f94` |
| Insert / find | residual `FUN_00401db0` / `FUN_00401c50` (context only) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 90 B + `ret 0xC` | **Confirmed** | disasm ends `RET 0xC`; hex `C2 0C 00` |
| Hybrid ABI: ECX parent, EDX right, EDI value, stack node/left/color | **Confirmed** | body + buynode call site |
| Links L@+0 / P@+4 / R@+8 | **Confirmed** | `MOV [ESI],…` / `+4` / `+8` |
| Value string+byte via `00402040` at +0x0c | **Confirmed** | `LEA [ESI+0xc]; CALL`; dualed value RET 4 |
| color@+0x2c / isnil=0@+0x2d | **Confirmed** | stores; isnil from `XOR EAX,EAX` not color |
| Sole caller buynode `00401f40` | **Confirmed** | 1 xref / 1 caller |
| SEH frame present | **Confirmed** | FS:[0] / `LAB_009bc7ed` |
| Decompiler `__fastcall` incomplete | **Confirmed** | EDI + 3 stack + RET 0xC sealed by asm |
| Product / PDB demangle | **Open** | `_Inferred` |
| Runtime / bit-exact / differential | **Open** | deferred |

---

## 4. Control flow: raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| SEH setup → link stores | **Yes** |
| value copy `00402040` | **Yes** |
| color + isnil0 → return ESI; RET 0xC | **Yes** |

---

## 5. Naming gate

| Evidence | Present? |
|---|---|
| isnil@+0x2d family + 0x30 node | **Yes** |
| Value = string (0x1c) + byte | **Yes** (value helper) |
| Sole caller dualed StringByte buynode | **Yes** |
| Product/PDB English | **No** |

**Decision:** promote **`StdTree_NodeCtor_StringByte_Isnil2D_Inferred`** (structural High; English unproven). Reject chain-of-caller `Named_CalleeOf_*Nam_*` scaffold; reject Val24 isnil29 NodeCtor merge; reject BuyHead merge; reject thiscall-ECX-node.

---

## 6. Gaps

1. Product/PDB symbol for host map (`string→byte`-shaped) under null-dialog chain.
2. Full dual of insert `FUN_00401db0` / insert-or-find `FUN_00401c50` (not OWN).
3. Runtime / bit-exact / image diff.

**Verdict:** **accept-with-gaps**
