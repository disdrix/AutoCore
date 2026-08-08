# Review A (reconstruction fidelity): `aa_00403250` StdTree_InsertAndRebalance_Isnil31_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00403250` |
| **VA** | `0x00403250` |
| **Body** | `0x00403250`–`0x004033d1` inclusive (**386** B / `0x182`) |
| **Canonical name** | `StdTree_InsertAndRebalance_Isnil31_Inferred` |
| **Ghidra symbol** | `FUN_00403250` |
| **Review date** | `2026-08-05` (MEGA-047 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00403250_StdTree_InsertAndRebalance_Isnil31_Inferred.md` |
| **System** | STL / map-set (missions-progression nest) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_callers` / `get_function_xrefs` + `get_assembly_context` + `read_memory` entry/epilogue + string + callees. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

MSVC-style **map/set always-insert + red-black rebalance** for the large-node family used with dualed isnil@+0x31 rotates. Parent insert-or-find (`FUN_00402b30`) supplies hint; this unit allocates, links, rebalances.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ MEGA-047 re-verify) | `docs/reconstruction/raw/aa_00403250_FUN_00403250.md` |
| Annotated | `docs/reconstruction/raw/aa_00403250_FUN_00403250.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_InsertAndRebalance_Isnil31_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_00403250.cpp` |
| Function record | `docs/reconstruction/functions/aa_00403250_StdTree_InsertAndRebalance_Isnil31_Inferred.md` |
| Live body bytes | `read_memory` @ `0x00403250` (epilogue `C2 0C 00`) |
| String | `"map/set<T> too long"` @ `0x00a1530c` |
| Buynode | `FUN_00403f30` → `operator_new(0x38)` + `FUN_00404360` |
| Rotates | dualed `00403e90` / residual `00403ee0` |
| Parent | `FUN_00402b30` (uint key @ +0x10; isnil walk @+0x31) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 386 B + `ret 0xc` | **Confirmed** | Ghidra disasm + epilogue bytes `C2 0C 00` |
| EDI=map; ECX=where; stack out/addLeft/value | **Confirmed** | no `mov edi,ecx`; parent keeps EDI=map; call sites `MOV ECX,ESI` + 3 PUSHes |
| Max size `>= 0x7fffffe` → length_error | **Confirmed** | `cmp [edi+8],0x7fffffe` + string |
| Buynode 0x38 / color red / isnil0 | **Confirmed** | callee decompile + ctor writes +0x31 |
| Link empty / left / right + extremum | **Confirmed** | decomp ≡ raw ≡ disasm |
| RB while parent red; L/R rotates | **Confirmed** | callees isnil31 family; `PUSH EDI` + ECX=pivot |
| Root black before return | **Confirmed** | epilogue `mov [root+0x30],1` |
| Always-insert (no key compare) | **Confirmed** | no compare in body; parent does find |
| Product / PDB demangle | **Open** | `_Inferred` |
| Runtime / bit-exact / differential | **Open** | deferred |

---

## 4. Control flow: raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| size gate → throw | **Yes** |
| buynode + size++ | **Yes** |
| link + RB loop + root black + *out | **Yes** |
| RET 0xC | **Yes** |

---

## 5. Naming gate

| Evidence | Present? |
|---|---|
| STL throw string | **Yes** |
| RB insert structure | **Yes** |
| Family rotates isnil31 (L dualed) | **Yes** |
| Product/PDB English | **No** |

**Decision:** promote **`StdTree_InsertAndRebalance_Isnil31_Inferred`** (structural High; English unproven → `_Inferred`). Reject `Named_CalleeOf_*NotifyActiveMissionChanged`.

---

## 6. Gaps

1. Product/PDB symbol for this MSVC map instantiation.
2. Value-type English for 0x20 payload at +0x10 (parent key = first u32).
3. Full dual of residual Rrotate `00403ee0`, buynode `00403f30`, parent `00402b30`.
4. Runtime / bit-exact / image diff.

**Verdict:** **accept-with-gaps**
