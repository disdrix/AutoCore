# Review A (reconstruction fidelity): `aa_00418c10` StdTree_Rrotate_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_00418c10` |
| **VA** | `0x00418c10` |
| **Body** | `0x00418c10`–`0x00418c62` exclusive (**82** B) |
| **Canonical name** | `StdTree_Rrotate_Val12` (inferred) |
| **Ghidra symbol** | `FUN_00418c10` |
| **Review date** | `2026-07-29` (W26-Q OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00418c10_StdTree_Rrotate_Val12.md` |
| **System** | MSVC std `_Tree` right-rotate (Val12) |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `analyze_function_complete` (**no** `disassemble_bytes`) |
| **Verdict** | **accept** |

---

## 1. Purpose

Right-rotate about node `x` in a Val12 red-black tree: promote `x->left` to `x`'s former place; hang `x` as the new right child. Leaf pointer-surgery only.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00418c10_FUN_00418c10.md` (+ W26-Q append) |
| Annotated | `docs/reconstruction/raw/aa_00418c10_FUN_00418c10.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Rrotate_Val12.cpp` |
| Scaffold twin | `reconstructed-exact/FUN_00418c10.cpp` |
| Function record | `docs/reconstruction/functions/aa_00418c10_StdTree_Rrotate_Val12.md` |
| Live decompile | ≡ raw |
| Live body bytes | `read_memory` @ `0x00418c10` length 82 (+ pad seal @ `0x00418c62`) |
| Twin rotate | `aa_00573170` StdTree_Lrotate_Val12 |
| Consumer dual | `aa_0051c1c0` Map_TreeInsertAndRebalance_Val12 |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| Body exclusive end | `0x00418c62` (`CC` pad after last `C2 04 00`) |
| Size | **82** B |
| Epilogue | `RET 4` ×3 paths |
| isnil test | `80 7E 19 00` on `y->right` |
| Tree head | same `this+4` / root pattern as Lrotate |
| Leaf | 0 callees |

Full body hex:

```
8b5424048b02568b700889328b7008807e190075038956048b72048970048b49043b51045e750c894104895008894204c204008b4a043b5108750c894108895008894204c204008901895008894204c20400
```

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw | **pass** |
| Body size exclusive end | **pass** (`00418c62`) |
| `RET 4` / 1 stack arg | **pass** |
| thiscall ECX=tree | **pass** |
| Rrotate CF (y = left) | **pass** |
| Nil-child parent link | **pass** (isnil@+0x19) |
| Root / right / left reattach | **pass** (3 exits; right-child test uses `parent+8`) |
| Clean has no bare `undefined4` | **pass** (`int32_t`) |
| Shared (not skill-only) | **pass** (13 callers / 32 xrefs) |
| Product demangle | **gap** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI | **High** | live ≡ raw; RET 4 sealed |
| Right-rotate identity | **High** | classical algorithm |
| Val12 layout | **High** | isnil@+0x19 |
| Name `StdTree_Rrotate_Val12` | **Inferred** | structural; not plate |
| Runtime / differential | Open | |

---

## 6. Gaps

1. Product / MSVC demangle for each map type.  
2. Bit-exact / differential — open.

**Verdict:** **accept**
