# Review A (reconstruction fidelity): `aa_0050e9f0` StdTree_Lrotate_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0050e9f0` |
| **VA** | `0x0050e9f0` |
| **Body** | `0x0050e9f0`–`0x0050ea3d` inclusive (**78 B** / `0x4E`) |
| **Canonical name** | `StdTree_Lrotate_Isnil21_Inferred` |
| **Ghidra symbol** | `FUN_0050e9f0` |
| **Review date** | `2026-08-05` (R10-030 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_0050e9f0_StdTree_Lrotate_Isnil21_Inferred.md` |
| **System** | MSVC std `_Tree` left-rotate (isnil@+0x21) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `get_function_callers` / `get_xrefs_to` + `read_memory` + `get_assembly_context`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Left-rotate about node `x` in an isnil@+0x21 red-black tree: promote `x->right` to `x`'s former place; hang `x` as the new left child. Leaf pointer-surgery only. Shared by insert rebalance (parent dual `00407200`) and many other isnil21 shells.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ R10-030 re-verify) | `docs/reconstruction/raw/aa_0050e9f0_FUN_0050e9f0.md` |
| Annotated | `docs/reconstruction/raw/aa_0050e9f0_FUN_0050e9f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Lrotate_Isnil21_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_0050e9f0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0050e9f0_StdTree_Lrotate_Isnil21_Inferred.md` |
| Live decompile | ≡ raw CF |
| Live body bytes | `read_memory` @ `0x0050e9f0` length 80 (78 B + `CC` pad) |
| Twin Rrotate | `FUN_005a27f0` (isnil@+0x21; residual, not OWN) |
| Parent dual | `StdTree_InsertAndRebalance_Isnil21_Inferred` `0x00407200` (WQ9I-B) |
| Peer Lrotate | `StdTree_Lrotate_Isnil29` `0x004192a0` (byte-identical except isnil imm) |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden, parent ledgers.

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| Body inclusive end | `0x0050ea3d` (`CC` pad after last `C2 04 00`) |
| Size | **78** B |
| Epilogue | `RET 4` ×3 paths |
| isnil test | `80 7E 21 00` on `y->left` |
| Tree head | `this+4` / root at `head+4` |
| Leaf | 0 callees |
| Xrefs | 30 UNCONDITIONAL_CALL / 14 callers |

Full body hex:

```
8b5424048b4208568b308972088b30807e210075038956048b72048970048b49043b51045e750b8941048910894204c204008b4a043b11750a89018910894204c204008941088910894204c20400
```

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw | **pass** |
| Body size inclusive end | **pass** (`0050ea3d`) |
| `RET 4` / 1 stack arg | **pass** |
| thiscall ECX=tree | **pass** (parent call sites `MOV ECX,EDI`) |
| Lrotate CF (`y = right` @ +8) | **pass** |
| Nil-child parent link | **pass** (isnil@+0x21) |
| Root / left / right reattach | **pass** (3 exits) |
| Clean has no bare `undefined4` | **pass** (`int32_t`) |
| Shared (not skill-only) | **pass** (14 callers / 30 xrefs) |
| Product demangle | **gap** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI | **High** | live ≡ raw; RET 4 sealed |
| Left-rotate identity | **High** | classical algorithm; mirrors isnil29 Lrotate with isnil offset swap |
| isnil@+0x21 layout | **High** | bytes + parent dual color@+0x20 / isnil@+0x21 |
| Name `StdTree_Lrotate_Isnil21_Inferred` | **Inferred** | structural; product English open |
| Runtime / differential | Open | |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| Classical Lrotate CF | **Yes** |
| isnil@+0x21 byte seal | **Yes** |
| Peer dualed Lrotates (29/2D/31) | **Yes** |
| Parent dual seals L role | **Yes** |
| Twin Rrotate opposite CF | **Yes** (evidence only) |
| Product/PDB English | **No** |

**Decision:** promote **`StdTree_Lrotate_Isnil21_Inferred`**. Reject Rrotate merge, skill-specific alias, isnil29/2D/31 family merge.

---

## 7. Gaps

1. Product / MSVC demangle for map instantiations.
2. Full dual of twin Rrotate `005a27f0` (role sealed; residual OWN elsewhere).
3. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
