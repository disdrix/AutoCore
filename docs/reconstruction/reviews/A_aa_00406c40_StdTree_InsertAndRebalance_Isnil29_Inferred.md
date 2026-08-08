# Review A (reconstruction fidelity): `aa_00406c40` StdTree_InsertAndRebalance_Isnil29_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00406c40` |
| **VA** | `0x00406c40` |
| **Body** | `0x00406c40`–`0x00406dd5` exclusive (**405** B) |
| **Canonical name** | `StdTree_InsertAndRebalance_Isnil29_Inferred` |
| **Ghidra symbol** | `FUN_00406c40` |
| **Review date** | `2026-08-04` (WQ9E-G OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00406c40_StdTree_InsertAndRebalance_Isnil29_Inferred.md` |
| **System** | STL / map-set |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` / `decompile_function` + `analyze_function_complete` + `read_memory` entry/mid/epilogue + string + callees. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

MSVC-style **map/set always-insert + red-black rebalance** for the large-node family used with dualed isnil@+0x29 rotates. Parent insert-or-find (`FUN_00406040`) supplies hint; this unit allocates, links, rebalances.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ WQ9E-G re-verify) | `docs/reconstruction/raw/aa_00406c40_FUN_00406c40.md` |
| Annotated | `docs/reconstruction/raw/aa_00406c40_FUN_00406c40.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_InsertAndRebalance_Isnil29_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_00406c40.cpp` |
| Function record | `docs/reconstruction/functions/aa_00406c40_StdTree_InsertAndRebalance_Isnil29_Inferred.md` |
| Live body bytes | `read_memory` @ `0x00406c40` / `0x00406d40` (epilogue `C2 10 00`) |
| String | `"map/set<T> too long"` @ `0x00a1530c` |
| Buynode | `FUN_00407e30` → `operator_new(0x30)` + `FUN_004098d0` |
| Rotates | dualed `004192a0` / `004192f0` |
| Parent | `FUN_00406040` (uint key @ +0x10) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 405 B + `ret 0x10` | **Confirmed** | Ghidra bounds + epilogue bytes |
| `__thiscall` ECX=map; stack out/addLeft/where/value | **Confirmed** | `mov edi,ecx`; stack slots; parent call shape |
| Max size `> 0x0AAAAAA8` → length_error | **Confirmed** | `cmp [edi+8],0x0AAAAAA9` + string |
| Buynode 0x30 / color red / isnil0 | **Confirmed** | callee decompile + ctor writes +0x29 |
| Link empty / left / right + extremum | **Confirmed** | decomp ≡ raw |
| RB while parent red; L/R rotates | **Confirmed** | callees dualed isnil29 |
| Root black before return | **Confirmed** | epilogue `mov [root+0x28],1` |
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
| RET 0x10 | **Yes** |

---

## 5. Naming gate

| Evidence | Present? |
|---|---|
| STL throw string | **Yes** |
| RB insert structure | **Yes** |
| Family rotates dualed isnil29 | **Yes** |
| Product/PDB English | **No** |

**Decision:** promote **`StdTree_InsertAndRebalance_Isnil29_Inferred`** (structural High; English unproven → `_Inferred`). Reject `Named_CalleeOf_*VOGClient`.

---

## 6. Gaps

1. Product/PDB symbol for this MSVC map instantiation.
2. Value-type English for 0x18 payload at +0x10.
3. Full algebra residual on every rotation case (CF sealed).
4. Runtime / bit-exact / image diff.

**Verdict:** **accept-with-gaps**
