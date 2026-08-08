# Review A (reconstruction fidelity): `aa_00407200` StdTree_InsertAndRebalance_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00407200` |
| **VA** | `0x00407200` |
| **Body** | `0x00407200`–`0x00407395` inclusive (**406 B** / `0x196`) |
| **Canonical name** | `StdTree_InsertAndRebalance_Isnil21_Inferred` |
| **Ghidra symbol** | `FUN_00407200` |
| **Review date** | `2026-08-05` (WQ9I-B OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00407200_StdTree_InsertAndRebalance_Isnil21_Inferred.md` |
| **System** | STL / map-set |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` / `decompile_function` + `analyze_function_complete` + `read_memory` entry/epilogue + string + callees/callers. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

MSVC-style **map/set always-insert + red-black rebalance** for the **isnil@+0x21** node family (node **0x28**, color@**+0x20**, Val16). Parents InsertHint (`00406560`) / InsertOrFind (`00407060`) supply `where`/`addLeft`; this unit allocates, links, rebalances, returns the new node via `*out`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ WQ9I-B re-verify) | `docs/reconstruction/raw/aa_00407200_FUN_00407200.md` |
| Annotated | `docs/reconstruction/raw/aa_00407200_FUN_00407200.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_InsertAndRebalance_Isnil21_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_00407200.cpp` |
| Function record | `docs/reconstruction/functions/aa_00407200_StdTree_InsertAndRebalance_Isnil21_Inferred.md` |
| Live body bytes | `read_memory` @ `0x00407200` / `0x00407360` (epilogue `C2 10 00`) |
| String | `"map/set<T> too long"` |
| Buynode | dualed `StdTree_Buynode_Val16_Isnil21_Inferred` `0x00408990` |
| Rotates | `FUN_0050e9f0` (L), `FUN_005a27f0` (R) |
| Parents | dualed InsertHint `00406560`; residual InsertOrFind `00407060` |
| Peer | isnil29 always-insert `00406c40` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 406 B + `ret 0x10` | **Confirmed** | Ghidra bounds + epilogue bytes |
| `__thiscall` ECX=map; stack out/addLeft/where/value | **Confirmed** | `mov edi,ecx`; stack slots; parent call shape |
| Max size `≥ 0xFFFFFFE` → length_error | **Confirmed** | `cmp [edi+8],0xFFFFFFFE` + string |
| Buynode 0x28 / color red / isnil0 | **Confirmed** | dualed `00408990` + color arg 0 |
| Link empty / left / right + extremum | **Confirmed** | decomp ≡ raw |
| RB while parent red; L/R rotates | **Confirmed** | callees + color@+0x20 loop |
| Root black before return | **Confirmed** | epilogue `mov [root+0x20],1` |
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
| Family buynode dualed isnil21 | **Yes** |
| Peer CF isnil29 always-insert | **Yes** |
| Product/PDB English | **No** |

**Decision:** promote **`StdTree_InsertAndRebalance_Isnil21_Inferred`** (structural High; English unproven → `_Inferred`). Reject freelist / CNDHash / InsertHint-merge.

---

## 6. Gaps

1. Product/PDB symbol for this MSVC map instantiation.
2. Value-type English for Val16 payload at +0x10.
3. Full dual of rotates `0050e9f0` / `005a27f0` (roles sealed).
4. Full dual of InsertOrFind `00407060` (not OWN).
5. Runtime / bit-exact / image diff.

**Verdict:** **accept-with-gaps**
