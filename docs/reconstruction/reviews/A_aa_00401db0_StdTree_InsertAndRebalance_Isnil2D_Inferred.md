# Review A (reconstruction fidelity): `aa_00401db0` StdTree_InsertAndRebalance_Isnil2D_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00401db0` |
| **VA** | `0x00401db0` |
| **Body** | `0x00401db0`–`0x00401f31` exclusive (**385** B / `0x181`) |
| **Canonical name** | `StdTree_InsertAndRebalance_Isnil2D_Inferred` |
| **Ghidra symbol** | `FUN_00401db0` |
| **Review date** | `2026-08-05` (MEGA-066 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00401db0_StdTree_InsertAndRebalance_Isnil2D_Inferred.md` |
| **System** | STL / map-set (missions-progression call-chain context only) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_callers` / `get_function_xrefs` + `get_assembly_context` + `read_memory` entry/cmp/epilogue + string. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

MSVC-style **map/set always-insert + red-black rebalance** for the **isnil@+0x2D** node family. Parent insert-or-find (`FUN_00401c50`) supplies hint after string-key lower-bound; this unit allocates, links, rebalances. Partition "Mission null dialog nested" is **xref-chain context only** — body is pure STL.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ MEGA-066 re-verify) | `docs/reconstruction/raw/aa_00401db0_FUN_00401db0.md` |
| Annotated | `docs/reconstruction/raw/aa_00401db0_FUN_00401db0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_InsertAndRebalance_Isnil2D_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_00401db0.cpp` |
| Function record | `docs/reconstruction/functions/aa_00401db0_StdTree_InsertAndRebalance_Isnil2D_Inferred.md` |
| Live body | `disassemble_function` full listing; `read_memory` @ `0x00401dc8` (cmp imm), `0x00401f2f` (`C2 0C 00`) |
| String | `"map/set<T> too long"` @ `0x00a1530c` |
| Buynode | `FUN_00401f40` → `operator_new(0x30)` + `FUN_00401fe0` (isnil=0 @+0x2D, color arg @+0x2C) |
| Rotates | dualed `0044e010` / `0042a840` (isnil2D) |
| Parent | `FUN_00401c50` (string-key insert-or-find; 2 call sites) |
| Clone peer | dualed `StdMap_StringKey_InsertNodeAndRebalance` `0x00430b60` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 385 B + `ret 0x0c` | **Confirmed** | Ghidra bounds + epilogue bytes `C2 0C 00` |
| EDI=map; ECX=where; stack out/addLeft/value | **Confirmed** | no `mov edi,ecx`; `mov esi,ecx`; call-site `MOV EDI,EDX` / `MOV ECX,EBP`; stack reads |
| Max size `> 0x7FFFFFD` → length_error | **Confirmed** | `cmp [edi+8],0x7fffffe` + string + `FUN_00401a40` + `DAT_00acc388` |
| Buynode 0x30 / color red / isnil0 | **Confirmed** | `operator_new(0x30)`; ctor writes `+0x2d=0`, color arg |
| Link empty / left / right + extremum | **Confirmed** | decomp ≡ asm |
| RB while parent red; L/R rotates | **Confirmed** | color@+0x2C; dualed isnil2D rotates |
| Root black before return | **Confirmed** | epilogue `mov byte ptr [root+0x2c],1` |
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
| RET 0x0C | **Yes** |

---

## 5. Naming gate

| Evidence | Present? |
|---|---|
| STL throw string | **Yes** |
| RB insert structure | **Yes** |
| Family rotates dualed isnil2D | **Yes** |
| Product/PDB English | **No** |
| Mission-dialog product string in body | **No** |

**Decision:** promote **`StdTree_InsertAndRebalance_Isnil2D_Inferred`** (structural High; English unproven → `_Inferred`).  
**Reject:** `Named_CalleeOf_*Mission*null*dialog*_00401db0` as product alias.  
**Distinct from:** `StdMap_StringKey_InsertNodeAndRebalance` `0x00430b60` (clone peer; keep VA-specific records).  
**Distinct from:** isnil29 insert `0x00406c40` (color@+0x28 / max `0x0AAAAAA8` / thiscall ECX=map RET 0x10).

---

## 6. Gaps

1. Product/PDB symbol for this MSVC map/set instantiation.
2. Exact mapped-value layout beyond string @+0x0C (peer documents u32 @+0x28; this buynode only string-copies via `FUN_00402040`).
3. Parent `FUN_00401c50` / buynode `FUN_00401f40` residual duals.
4. Runtime / bit-exact / image diff.

**Verdict:** **accept-with-gaps**
