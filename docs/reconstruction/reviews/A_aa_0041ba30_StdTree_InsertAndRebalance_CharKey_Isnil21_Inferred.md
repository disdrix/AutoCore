# Review A (reconstruction fidelity): `aa_0041ba30` StdTree_InsertAndRebalance_CharKey_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0041ba30` |
| **VA** | `0x0041ba30` |
| **Body** | `0x0041ba30`–`0x0041bbc5` inclusive (**406 B** / `0x196`) |
| **Canonical name** | `StdTree_InsertAndRebalance_CharKey_Isnil21_Inferred` |
| **Ghidra symbol** | `FUN_0041ba30` |
| **Review date** | `2026-08-05` (R12-011 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_0041ba30_StdTree_InsertAndRebalance_CharKey_Isnil21_Inferred.md` |
| **System** | skills-abilities / STL map-set |
| **Parent dual** | `0x005a27f0` StdTree_Rrotate_Isnil21_Inferred |
| **Dual start** | 2646 |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` entry/epilogue + string + callees/callers + `get_assembly_context`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

MSVC-style **map/set always-insert + red-black rebalance** for the **char-key isnil@+0x21** node family (node **0x24**, color@**+0x20**, key char @**+0x0C**). Parent `FUN_0041a570` supplies `where`/`addLeft` after char-key lower-bound; this unit allocates, links, rebalances, returns the new node via `*out` (EAX = out).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ R12-011 re-verify) | `docs/reconstruction/raw/aa_0041ba30_FUN_0041ba30.md` |
| Annotated | `docs/reconstruction/raw/aa_0041ba30_FUN_0041ba30.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_InsertAndRebalance_CharKey_Isnil21_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_0041ba30.cpp` |
| Function record | `docs/reconstruction/functions/aa_0041ba30_StdTree_InsertAndRebalance_CharKey_Isnil21_Inferred.md` |
| Live body bytes | `read_memory` @ `0x0041ba30` / `0x0041bbb0` (epilogue `C2 10 00`) |
| String | `"map/set<T> too long"` @ `0x00a1530c` |
| Buynode | residual `FUN_0041d860` (`operator_new(0x24)`, isnil@+0x21) |
| Rotates | dualed L `0050e9f0` (R10-030); dualed R `005a27f0` (R11-007 parent) |
| Parent caller | residual `FUN_0041a570` (char compare @ node+0xC) |
| Peer | Val16 always-insert isnil21 `00407200` (do not merge) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 406 B + `ret 0x10` | **High** | Ghidra bounds + epilogue `C2 10 00` + pad `CC` |
| `__thiscall` ECX=map; stack out/addLeft/where/value | **High** | `mov edi,ecx`; stack slots; parent `MOV ECX,EDI` + 4 pushes |
| Max size `≥ 0x0CCCCCCB` → length_error | **High** | `cmp [edi+8],0x0CCCCCCB` + string |
| Buynode 0x24 / color red / isnil0 | **High** | buynode raw `operator_new(0x24)` + color arg 0 |
| Link empty / left / right + extremum | **High** | decomp ≡ raw |
| RB while parent red; L/R rotates | **High** | callees + color@+0x20 loop |
| Root black before return | **High** | epilogue `mov [root+0x20],1` |
| Always-insert (no key compare) | **High** | no compare in body; parent does find |
| Char-key family (vs Val16 00407200) | **High** | parent char compare; node 0x24; max imm differs |
| Product / PDB demangle | **Open** | `_Inferred` |
| Runtime / bit-exact / differential | **Open** | deferred; **never Runtime Confirmed** this dual |

---

## 4. Control flow: raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| size gate → throw | **Yes** |
| buynode + size++ | **Yes** |
| link + RB loop + root black + *out | **Yes** |
| RET 0x10 | **Yes** |

---

## 5. Naming gate

| Evidence | Present? |
|---|---|
| STL throw string | **Yes** |
| RB insert structure | **Yes** |
| Family rotates dualed isnil21 | **Yes** |
| Char key @+0x0C (caller + buynode) | **Yes** |
| Distinct from Val16 isnil21 always-insert | **Yes** (buynode/max/callers) |
| Product/PDB English | **No** |

**Decision:** promote **`StdTree_InsertAndRebalance_CharKey_Isnil21_Inferred`** (structural High; English unproven → `_Inferred`). Reject freelist / CNDHash / InsertHint-merge / merge-with-`00407200` / skill-only alias / CVOGReaction chain alias.

---

## 6. Gaps

1. Product/PDB symbol for this MSVC map instantiation.
2. Value-type English for residual payload after char key (via `FUN_0041c140` in buynode).
3. Full dual of buynode `0041d860` and parent `0041a570` (roles sealed; not OWN).
4. Runtime / bit-exact / image diff.

**Verdict:** **accept-with-gaps**
