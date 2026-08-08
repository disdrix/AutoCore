# Review A (reconstruction fidelity): `aa_004192a0` StdTree_Lrotate_Isnil29

| Field | Value |
|---|---|
| **Stable ID** | `aa_004192a0` |
| **VA** | `0x004192a0` |
| **Body** | `0x004192a0`–`0x004192ed` exclusive (**77** B) |
| **Canonical name** | `StdTree_Lrotate_Isnil29` (inferred) |
| **Ghidra symbol** | `FUN_004192a0` |
| **Review date** | `2026-08-04` (WQ9D-C OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_004192a0_StdTree_Lrotate_Isnil29.md` |
| **System** | MSVC std `_Tree` left-rotate (isnil@+0x29) |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `analyze_function_complete` (**no** `disassemble_bytes`) |
| **Verdict** | **accept** |

---

## 1. Purpose

Left-rotate about node `x` in an isnil@+0x29 red-black tree: promote `x->right` to `x`'s former place; hang `x` as the new left child. Leaf pointer-surgery only.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004192a0_FUN_004192a0.md` (+ WQ9D-C append) |
| Annotated | `docs/reconstruction/raw/aa_004192a0_FUN_004192a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Lrotate_Isnil29.cpp` |
| Scaffold twin | `reconstructed-exact/FUN_004192a0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004192a0_StdTree_Lrotate_Isnil29.md` |
| Live decompile | ≡ raw |
| Live body bytes | `read_memory` @ `0x004192a0` length 80 (77 B + `CC` pad) |
| Twin rotate | `FUN_004192f0` Rrotate (same isnil@+0x29; not OWN) |
| Peer Val12 | `aa_00573170` StdTree_Lrotate_Val12 (isnil@+0x19) |
| Consumer dual | `aa_0051cb40` Map_EraseNode |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden, parent ledgers.

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| Body exclusive end | `0x004192ed` (`CC` pad after last `C2 04 00`) |
| Size | **77** B |
| Epilogue | `RET 4` ×3 paths |
| isnil test | `80 7E 29 00` on `y->left` |
| Tree head | `this+4` / root at `head+4` (same pattern as Val12 Lrotate) |
| Leaf | 0 callees |

Full body hex:

```
8b5424048b4208568b308972088b30807e290075038956048b72048970048b49043b51045e750b8941048910894204c204008b4a043b11750a89018910894204c204008941088910894204c20400
```

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw | **pass** |
| Body size exclusive end | **pass** (`004192ed`) |
| `RET 4` / 1 stack arg | **pass** |
| thiscall ECX=tree | **pass** |
| Lrotate CF (y = right @ +8) | **pass** |
| Nil-child parent link | **pass** (isnil@+0x29) |
| Root / left / right reattach | **pass** (3 exits) |
| Clean has no bare `undefined4` | **pass** (`int32_t`) |
| Shared (not skill-only) | **pass** (10 callers / 21 xrefs) |
| Product demangle | **gap** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI | **High** | live ≡ raw; RET 4 sealed |
| Left-rotate identity | **High** | classical algorithm; mirrors Val12 Lrotate with isnil offset swap |
| isnil@+0x29 layout | **High** | bytes + Map_EraseNode family |
| Name `StdTree_Lrotate_Isnil29` | **Inferred** | structural; not plate |
| Runtime / differential | Open | |

---

## 6. Gaps

1. Product / MSVC demangle for each map type.  
2. Exact payload English between +0x0c and color@+0x28 (per-map).  
3. Bit-exact / differential — open.  
4. Twin Rrotate `004192f0` dual is sibling OWN (not this partition).

**Verdict:** **accept**
