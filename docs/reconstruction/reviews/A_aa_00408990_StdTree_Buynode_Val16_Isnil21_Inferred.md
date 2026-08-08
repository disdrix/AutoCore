# Review A (reconstruction fidelity): `aa_00408990` StdTree_Buynode_Val16_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00408990` |
| **VA** | `0x00408990` |
| **Body** | `0x00408990`–`0x00408a13` inclusive (**132** B / `0x84`) |
| **Canonical name** | `StdTree_Buynode_Val16_Isnil21_Inferred` |
| **Ghidra symbol** | `FUN_00408990` |
| **Review date** | `2026-08-04` (WQ9H-J OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00408990_StdTree_Buynode_Val16_Isnil21_Inferred.md` |
| **System** | STL / map-set buynode |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` / `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` entry/epilogue + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Allocate and construct one **isnil@+0x21** tree node with **Val16** payload for insert/rebalance `FUN_00407200`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ WQ9H-J re-verify) | `docs/reconstruction/raw/aa_00408990_FUN_00408990.md` |
| Annotated | `docs/reconstruction/raw/aa_00408990_FUN_00408990.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Buynode_Val16_Isnil21_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_00408990.cpp` |
| Function record | `docs/reconstruction/functions/aa_00408990_StdTree_Buynode_Val16_Isnil21_Inferred.md` |
| Live body | `disassemble_function` + `read_memory` @ `0x00408990` / epilogue `C2 14 00` |
| Ctor | `FUN_004099b0` decompile + `read_memory` (`RET 0x14`) |
| Parent insert | `FUN_00407200` decompile + call site `0x0040726d` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 132 B + `ret 0x14` | **Confirmed** | disasm + `read_memory` epilogue |
| `__stdcall` 5 stack args; EAX return | **Confirmed** | disasm; no ECX this on entry |
| `operator_new(0x28)` | **Confirmed** | `PUSH 0x28` + call |
| Ctor links + 4 dwords + color@+0x20 + isnil0@+0x21 | **Confirmed** | `FUN_004099b0` decompile + bytes |
| Sole caller insert `00407200` | **Confirmed** | 1 xref @ `0040726d` |
| SEH frame present | **Confirmed** | FS:[0] / `LAB_009bc6b1` |
| Distinct from Val24/isnil29 0x30 buynodes | **Confirmed** | size 0x28; isnil@+0x21 |
| Not CNDHash freelist | **Confirmed** | no freelist @+0x20 push; CRT new + tree ctor |
| Product / PDB demangle | **Open** | `_Inferred` |
| Runtime / bit-exact / differential | **Open** | deferred |

---

## 4. Control flow: raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| SEH setup → new(0x28) | **Yes** |
| null skip / else thiscall ctor | **Yes** |
| return node; RET 0x14 | **Yes** |

---

## 5. Naming gate

| Evidence | Present? |
|---|---|
| Node size 0x28 + isnil@+0x21 | **Yes** |
| Val16 (4 dwords) from ctor | **Yes** |
| Parent insert color@+0x20 | **Yes** |
| Product/PDB English | **No** |

**Decision:** promote **`StdTree_Buynode_Val16_Isnil21_Inferred`** (structural High; English unproven). Reject freelist/CNDHash names; reject Val24/isnil29 merge; reject chain-of-caller scaffold.

---

## 6. Gaps

1. Product/PDB symbol.
2. Full dual of ctor `FUN_004099b0` and parent insert `FUN_00407200` (not OWN).
3. Runtime / bit-exact / image diff.

**Verdict:** **accept-with-gaps**
