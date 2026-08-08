# Review A (reconstruction fidelity): `aa_00404360` StdTree_NodeCtor_Val32_Isnil31_EaxThis_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00404360` |
| **VA** | `0x00404360` |
| **Body** | `0x00404360`–`0x0040438C` exclusive (**44** B / `0x2C`) |
| **Canonical name** | `StdTree_NodeCtor_Val32_Isnil31_EaxThis_Inferred` |
| **Ghidra symbol** | `FUN_00404360` |
| **Review date** | `2026-08-05` (R10-021 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00404360_StdTree_NodeCtor_Val32_Isnil31_EaxThis_Inferred.md` |
| **System** | STL / map-set node construct (partition: missions-progression) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra MCP — `decompile_function` + `analyze_function_complete` + `get_function_callers` + `get_function_xrefs` + `read_memory`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

In-place construct of one **isnil@+0x31** tree node with **Val32** payload (links + 8 dwords + color + isnil=0). No allocation. Used by dualed SEH buynode `StdTree_Buynode_Val32_Isnil31_Inferred` (`FUN_00403f30`) after `operator_new(0x38)`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ R10-021 re-verify) | `docs/reconstruction/raw/aa_00404360_FUN_00404360.md` |
| Annotated | `docs/reconstruction/raw/aa_00404360_FUN_00404360.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_NodeCtor_Val32_Isnil31_EaxThis_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_00404360.cpp` |
| Function record | `docs/reconstruction/functions/aa_00404360_StdTree_NodeCtor_Val32_Isnil31_EaxThis_Inferred.md` |
| Live body | `decompile_function` + `read_memory` @ `0x00404360` / epilogue `C2 0C 00` |
| Sole caller | `FUN_00403f30` @ `0x00403f86` (dualed MEGA-048) |
| Parent insert (evidence) | `FUN_00403250` (isnil31 insert; not OWN) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 44 B + `ret 0xc` | **Confirmed** | hex ends `5E C2 0C 00`; length 0x2C |
| EAX = node; ECX = left; EDX = parent; 3 stack args | **Confirmed** | decompile + caller wire from parent raw |
| Val32 @+0x10 (8 dwords); color@+0x30; isnil0@+0x31 | **Confirmed** | decompile ≡ `REP MOVSD` ECX=8 + stores |
| +0x0C not written | **Confirmed** | no store to [EAX+0xC] |
| Leaf (no callees) | **Confirmed** | analyze `callees: []` |
| Sole caller `00403f30` | **Confirmed** | 1 UNCONDITIONAL_CALL / xref_count=1 |
| Family peer of Val24 EAX-this NodeCtor naming | **Confirmed** | same structural role; different layout |
| Product / PDB demangle | **Open** | `_Inferred` |
| Runtime / bit-exact / differential | **Open** | deferred |

---

## 4. Control flow: raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| Store L from ECX | **Yes** |
| Store P from EDX / R from stack | **Yes** |
| Copy 8 dwords from value* → +0x10 | **Yes** |
| color@+0x30; isnil@+0x31=0; RET 0xC | **Yes** |

---

## 5. Naming gate

| Evidence | Present? |
|---|---|
| isnil@+0x31 family | **Yes** |
| Val32 (8 dwords) | **Yes** |
| EAX-this usercall (not thiscall; not buynode) | **Yes** |
| Product/PDB English | **No** |

**Decision:** promote **`StdTree_NodeCtor_Val32_Isnil31_EaxThis_Inferred`** (structural High; English unproven). Reject chain-of-caller Client/NotifyActiveMission scaffold; reject naming as buynode; reject merge with Val24 isnil29 NodeCtor (`00409880`/`004098d0`) or Val16 isnil21 (`004099b0`).

---

## 6. Gaps

1. Product/PDB symbol for value_type (8-dword English).
2. Runtime / bit-exact / image diff.
3. Insert parent `FUN_00403250` residual (not OWN).

**Verdict:** **accept-with-gaps**
