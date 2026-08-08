# Review A (reconstruction fidelity): `aa_00511950` StdTree_InsertAndRebalance_Node24_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00511950` |
| **VA** | `0x00511950` |
| **Body** | `0x00511950`–`0x00511b3a` inclusive (**491 B** / `0x1EB`) |
| **Canonical name** | `StdTree_InsertAndRebalance_Node24_Isnil21_Inferred` |
| **Ghidra symbol** | `FUN_00511950` |
| **Review date** | `2026-08-05` (R12-014 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00511950_StdTree_InsertAndRebalance_Node24_Isnil21_Inferred.md` |
| **System** | STL / map-set (Node24 isnil@+0x21) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `get_function_callers` / `get_function_xrefs` + `disassemble_function` + `read_memory` + `get_assembly_context`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

MSVC-style **map/set always-insert + red-black rebalance** for the **Node24 / isnil@+0x21** family (node **0x24**, color@**+0x20**, int key @+0x0C). Parent InsertOrFind (`00511b40`) supplies `where`/`addLeft`; this unit allocates, links, rebalances, returns the new node via `*out`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ R12-014 re-verify) | `docs/reconstruction/raw/aa_00511950_FUN_00511950.md` |
| Annotated | `docs/reconstruction/raw/aa_00511950_FUN_00511950.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_InsertAndRebalance_Node24_Isnil21_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_00511950.cpp` |
| Function record | `docs/reconstruction/functions/aa_00511950_StdTree_InsertAndRebalance_Node24_Isnil21_Inferred.md` |
| Live body bytes | `read_memory` @ `0x00511950` / `0x00511b30` (epilogue `C2 10 00`) |
| String | `"map/set<T> too long"` |
| Buynode | residual `FUN_005118b0` (`operator_new(0x24)`) |
| Rotates | dualed L `0050e9f0` / dualed R `005a27f0` (parent dual R11-007); one L path inlined |
| Parent shell | residual InsertOrFind `00511b40` (int key compare @ node+0x0C) |
| Peer | dualed Val16 insert `00407200` (node 0x28 / max 0xFFFFFFE) |

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| Body inclusive end | `0x00511b3a` (`CC` pad before `FUN_00511b40`) |
| Size | **491** B / `0x1EB` |
| Epilogue | `RET 0x10` (`C2 10 00`) |
| Size gate | `81 7F 08 CB CC CC 0C` → throw if `size ≥ 0xCCCCCCB` |
| Color tests | `80 7A 20 00` / writes `+0x20` |
| isnil (inlined L) | `80 7A 21 00` |
| thiscall | `MOV EDI,ECX` at entry; call sites `MOV ECX,EDI` |
| Leaf-of-insert | always-insert (no key compare in body) |
| Xrefs | 2 UNCONDITIONAL_CALL / 1 caller |

Key entry / gate / epilogue hex:

```
64a1000000006aff68f2319a00506489250000000083ec44578bf9817f08cbcccc0c7259
...
83c450c21000cccccccccc
```

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw | **pass** |
| Body size inclusive end | **pass** (`00511b3a`) |
| `RET 0x10` / 4 stack args | **pass** |
| thiscall ECX=map | **pass** (entry + call sites) |
| Always-insert + RB rebalance CF | **pass** |
| color@+0x20 / isnil@+0x21 | **pass** |
| Node24 via buynode `new(0x24)` | **pass** (nested evidence) |
| Distinct from Val16 peer `00407200` | **pass** (max size, node size, buynode VA) |
| Clean has no bare `undefined4` | **pass** (`int32_t` / `uint8_t`) |
| Product demangle | **gap** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI | **High** | live ≡ raw; RET 0x10 sealed |
| Always-insert identity | **High** | classical MSVC `_Insert`; no compare |
| isnil@+0x21 / color@+0x20 / node 0x24 | **High** | bytes + buynode |
| Name `StdTree_InsertAndRebalance_Node24_Isnil21_Inferred` | **Inferred** | structural; product English open |
| Runtime / differential | Open | |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| STL throw string | **Yes** |
| RB insert structure | **Yes** |
| Node24 sealed via buynode | **Yes** |
| Dualed L/R rotates isnil21 | **Yes** |
| Peer Val16 insert dualed (distinct) | **Yes** (`00407200`) |
| Product/PDB English | **No** |

**Decision:** promote **`StdTree_InsertAndRebalance_Node24_Isnil21_Inferred`**. Reject merge with Val16 peer `00407200`, InsertOrFind-merge, isnil29 family merge, skill-only alias.

---

## 7. Gaps

1. Product / MSVC demangle for map value_type (int key + vector of 0x10 elements).
2. Full dual of nested buynode `005118b0` and parent InsertOrFind `00511b40` (not OWN).
3. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
