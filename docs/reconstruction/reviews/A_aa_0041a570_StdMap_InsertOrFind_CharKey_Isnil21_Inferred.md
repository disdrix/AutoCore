# Review A (reconstruction fidelity): `aa_0041a570` StdMap_InsertOrFind_CharKey_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0041a570` |
| **VA** | `0x0041a570` |
| **Body** | `0x0041a570`–`0x0041a628` exclusive (**184 B** / `0xB8`) |
| **Canonical name** | `StdMap_InsertOrFind_CharKey_Isnil21_Inferred` |
| **Ghidra symbol** | `FUN_0041a570` |
| **Review date** | `2026-08-05` (R13-021 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_0041a570_StdMap_InsertOrFind_CharKey_Isnil21_Inferred.md` |
| **System** | skills-abilities / STL map-set |
| **Parent dual** | `0x0041ba30` StdTree_InsertAndRebalance_CharKey_Isnil21_Inferred |
| **Dual start** | 2686 |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` entry/epilogue + callers/xrefs + `disassemble_function` + `get_assembly_context`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

MSVC-style **map unique insert-or-find** for the **char-key isnil@+0x21** node family (node **0x24**, color@**+0x20**, key char @**+0x0C**). Lower-bound walk with `*key < node.key`; begin-left insert / predecessor / strict `node.key < key` insert; equal hit returns `{it, inserted=0}` without rewriting mapped payload. Insert worker is dualed parent `0041ba30`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ R13-021 re-verify) | `docs/reconstruction/raw/aa_0041a570_FUN_0041a570.md` |
| Annotated | `docs/reconstruction/raw/aa_0041a570_FUN_0041a570.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdMap_InsertOrFind_CharKey_Isnil21_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_0041a570.cpp` |
| Function record | `docs/reconstruction/functions/aa_0041a570_StdMap_InsertOrFind_CharKey_Isnil21_Inferred.md` |
| Live body bytes | `read_memory` @ `0x0041a570` / `0x0041a5d0` (three `C2 08 00`) |
| Insert child | dualed `0041ba30` (R12-011 parent) |
| Pred | residual `005adff0` |
| Peer | pair-key InsertOrFind isnil21 `00407060` (do not merge) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 184 B + `ret 0x8` ×3 | **High** | Ghidra bounds + epilogue `C2 08 00` + pad `CC` |
| `__thiscall` ECX=map; stack out/value | **High** | `mov edi,ecx`; callers `MOV ECX,ESI/EBP` + 2 pushes |
| Char-key walk isnil@+0x21 / key@+0x0C | **High** | `80 78 21 00`; `3A 50 0C` / `SETL` |
| Unique insert-or-find (equal inserted=0) | **High** | three out paths; no value rewrite on hit |
| Insert via dualed `0041ba30` | **High** | 2 CALL sites; parent dual sealed |
| Pred `005adff0` on non-begin left | **High** | CALL after `JNZ` from min-compare |
| Product / PDB demangle | **Open** | `_Inferred` |
| Runtime / bit-exact / differential | **Open** | deferred; **never Runtime Confirmed** this dual |

---

## 4. Control flow: raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| lower-bound walk char key | **Yes** |
| begin-left insert (addLeft=1) | **Yes** |
| pred + strict miss insert | **Yes** |
| equal `{it,0}` | **Yes** |
| RET 0x8 ×3 | **Yes** |

---

## 5. Naming gate

| Evidence | Present? |
|---|---|
| Unique insert-or-find CF (equal path) | **Yes** |
| Char key @+0x0C + isnil@+0x21 | **Yes** |
| Insert child dualed char-key family | **Yes** |
| Distinct from pair-key isnil21 shell | **Yes** (single-byte compare vs hi/lo) |
| Product/PDB English | **No** |

**Decision:** promote **`StdMap_InsertOrFind_CharKey_Isnil21_Inferred`** (structural High; English unproven → `_Inferred`). Reject always-insert-only / freelist / CNDHash / merge-with-`00407060` / merge-with-`0041ba30` / skill-product-name / CVOGReaction chain alias.

---

## 6. Gaps

1. Product/PDB symbol for this MSVC map instantiation / value_type.
2. Full dual of predecessor `005adff0` and host callers `007eaf20` / `0059a940`.
3. Residual value payload layout after char key (via `0041c140` / buynode).
4. Runtime / bit-exact / image diff.

**Verdict:** **accept-with-gaps**
