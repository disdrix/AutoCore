# Review A (reconstruction fidelity): `aa_0041c140` StdVector_CopyCtor_Elem0x18_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0041c140` |
| **VA** | `0x0041c140`–`0x0041c1c9` inclusive (**138 B** / `0x8A`) |
| **Canonical name** | `StdVector_CopyCtor_Elem0x18_Inferred` |
| **Ghidra symbol** | `FUN_0041c140` |
| **Prior scaffold** | `FUN_0041c140` / `Named_CalleeOf_…_VOG_DEBUG_ST_0041c140` |
| **Review date** | `2026-08-05` (R13-022 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_0041c140_StdVector_CopyCtor_Elem0x18_Inferred.md` |
| **System** | skills-abilities (partition) / STL vector |
| **Parent dual** | `0x0041ba30` StdTree_InsertAndRebalance_CharKey_Isnil21_Inferred |
| **Dual start** | 2686 |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `get_function_callers` / `get_function_xrefs` + `get_assembly_context` + `read_memory` + callee/buynode decompiles. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

MSVC-style **`std::vector` copy constructor** for **0x18-byte** elements. Destination is assumed unconstructed: residual buy helper zeros the pointer triple then allocates; residual POD Ucopy fills `[begin, end)`; `dest.end` published from Ucopy result. Returns `dest` (EAX = this).

Primary sealed use: char-key tree **buynode** copies the map-value vector sitting at **node+0x10** after the char key @ **+0x0C**.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ R13-022 re-verify) | `docs/reconstruction/raw/aa_0041c140_FUN_0041c140.md` |
| Annotated | `docs/reconstruction/raw/aa_0041c140_FUN_0041c140.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_CopyCtor_Elem0x18_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_0041c140.cpp` |
| Function record | `docs/reconstruction/functions/aa_0041c140_StdVector_CopyCtor_Elem0x18_Inferred.md` |
| Live body bytes | `read_memory` @ `0x0041c140` len 138 — epilogue `C2 04 00` |
| Buy helper | residual `FUN_0041c250` (`operator_new(n*0x18)`, fields +4/+8/+0xC) |
| Ucopy helper | residual `FUN_00422580` (6-dword POD step) |
| Buynode | residual `FUN_0041d860` — `LEA ECX,[ESI+0x10]` |
| Parent dual | R12-011 `0041ba30` always-insert char-key isnil21 |
| Peer (do not merge) | SkillSet Ucopy `0040a600` (cdecl range Ucopy, not copy-ctor) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 138 B + `ret 0x4` | **High** | Ghidra bounds + epilogue `C2 04 00` |
| `__thiscall` ECX=dest; stack src | **High** | `MOV EDI,ECX`; buynode `LEA ECX,[ESI+0x10]` + `PUSH` src |
| Count `(end-begin)/0x18` | **High** | decomp + mul-inverse `0x2AAAAAAB` |
| Buy zeros then alloc | **High** | `FUN_0041c250` decompile |
| Copy-ctor (not assign) | **High** | no free of prior dest; zeros first |
| POD Ucopy 0x18 / 6 dwords | **High** | `FUN_00422580` loop `+6` dwords |
| dest.end ← EAX after Ucopy | **High** | `MOV [EDI+8],EAX` at call site |
| Node vector @ +0x10 | **High** | buynode LEA + color@+0x20 / isnil@+0x21 |
| Product / PDB demangle | **Open** | `_Inferred` |
| Element = NPCSkillSetEntry English | **Open** | size match only; not product-proven here |
| Runtime / bit-exact / differential | **Open** | deferred; **never Runtime Confirmed** this dual |

---

## 4. Control flow: raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| SEH install `LAB_009bce90` | **Yes** |
| count 0 if begin null else /0x18 | **Yes** |
| buy; if fail/empty skip Ucopy | **Yes** |
| Ucopy + store end | **Yes** |
| return this; `RET 4` | **Yes** |

---

## 5. Naming gate

| Evidence | Present? |
|---|---|
| Vector pointer triple + buy + Ucopy | **Yes** |
| Element stride 0x18 sealed | **Yes** |
| Copy-ctor (zero+alloc, no free) | **Yes** |
| Distinct from range-Ucopy `0040a600` | **Yes** (ABI/role) |
| Product/PDB English | **No** |

**Decision:** promote **`StdVector_CopyCtor_Elem0x18_Inferred`** (structural High; English unproven → `_Inferred`). Reject Named_CalleeOf / VOG_DEBUG chain, SkillSet-product-only alias without element proof, assign-operator, freelist, tree-insert merge.

---

## 6. Gaps

1. Product/PDB symbol for `vector<T>` / map `value_type`.
2. Element-type English (0x18 POD; SkillSet-sized only by coincidence until proven).
3. Full dual of buy `0041c250`, Ucopy `00422580`, buynode `0041d860`, callers `0059a940` / `007eaf20`.
4. Runtime / bit-exact / image diff.

**Verdict:** **accept-with-gaps**
