# Review A (reconstruction fidelity): `aa_005a27f0` StdTree_Rrotate_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005a27f0` |
| **VA** | `0x005a27f0` |
| **Body** | `0x005a27f0`–`0x005a2841` inclusive (**82 B** / `0x52`) |
| **Canonical name** | `StdTree_Rrotate_Isnil21_Inferred` |
| **Ghidra symbol** | `FUN_005a27f0` |
| **Review date** | `2026-08-05` (R11-007 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_005a27f0_StdTree_Rrotate_Isnil21_Inferred.md` |
| **System** | MSVC std `_Tree` right-rotate (isnil@+0x21) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `get_function_callers` / `get_function_xrefs` + `read_memory` + `get_assembly_context`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Right-rotate about node `x` in an isnil@+0x21 red-black tree: promote `x->left` to `x`'s former place; hang `x` as the new right child. Leaf pointer-surgery only. Shared by insert rebalance (parent dual `00407200`) and many other isnil21 shells.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ R11-007 re-verify) | `docs/reconstruction/raw/aa_005a27f0_FUN_005a27f0.md` |
| Annotated | `docs/reconstruction/raw/aa_005a27f0_FUN_005a27f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Rrotate_Isnil21_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_005a27f0.cpp` |
| Function record | `docs/reconstruction/functions/aa_005a27f0_StdTree_Rrotate_Isnil21_Inferred.md` |
| Live decompile | ≡ raw CF |
| Live body bytes | `read_memory` @ `0x005a27f0` length 96 (82 B + `CC` pad) |
| Twin Lrotate | `StdTree_Lrotate_Isnil21_Inferred` `0x0050e9f0` (R10-030 dualed) |
| Parent dual | `StdTree_InsertAndRebalance_Isnil21_Inferred` `0x00407200` (WQ9I-B) |
| Peer Rrotate | `StdTree_Rrotate_Isnil29_Inferred` `0x004192f0` (same CF; isnil imm swap) |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden, parent ledgers.

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| Body inclusive end | `0x005a2841` (`CC` pad after last `C2 04 00`) |
| Size | **82** B |
| Epilogue | `RET 4` ×3 paths |
| isnil test | `80 7E 21 00` on `y->right` |
| Tree head | `this+4` / root at `head+4` |
| Leaf | 0 callees |
| Xrefs | 35 UNCONDITIONAL_CALL / 14 callers |

Full body hex:

```
8b5424048b02568b700889328b7008807e210075038956048b72048970048b49043b51045e750c894104895008894204c204008b4a043b5108750c894108895008894204c204008901895008894204c20400
```

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw | **pass** |
| Body size inclusive end | **pass** (`005a2841`) |
| `RET 4` / 1 stack arg | **pass** |
| thiscall ECX=tree | **pass** (parent call sites `MOV ECX,EDI`) |
| Rrotate CF (`y = left` @ +0) | **pass** |
| Nil-child parent link | **pass** (isnil@+0x21) |
| Root / right / left reattach | **pass** (3 exits; right-of-parent tested first via `parent[2]`) |
| Clean has no bare `undefined4` | **pass** (`int32_t`) |
| Shared (not skill-only) | **pass** (14 callers / 35 xrefs) |
| Product demangle | **gap** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI | **High** | live ≡ raw; RET 4 sealed |
| Right-rotate identity | **High** | classical algorithm; mirrors Lrotate twin with left/right swap |
| isnil@+0x21 layout | **High** | bytes + parent dual color@+0x20 / isnil@+0x21 |
| Name `StdTree_Rrotate_Isnil21_Inferred` | **Inferred** | structural; product English open |
| Runtime / differential | Open | |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| Classical Rrotate CF | **Yes** |
| isnil@+0x21 byte seal | **Yes** |
| Twin dualed Lrotate isnil21 | **Yes** (`0050e9f0`) |
| Peer dualed Rrotates (29/2D/31) | **Yes** |
| Parent dual seals R role | **Yes** |
| Product/PDB English | **No** |

**Decision:** promote **`StdTree_Rrotate_Isnil21_Inferred`**. Reject Lrotate merge, skill-specific alias, isnil29/2D/31 family merge.

---

## 7. Gaps

1. Product / MSVC demangle for map instantiations.
2. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
