# Review A (reconstruction fidelity): `aa_00573170` StdTree_Lrotate_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_00573170` |
| **VA** | `0x00573170` |
| **Body** | `0x00573170`–`0x005731BE` exclusive (**78** B) |
| **Canonical name** | `StdTree_Lrotate_Val12` (inferred) |
| **Ghidra symbol** | `FUN_00573170` |
| **Review date** | `2026-07-29` (W26-Q OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00573170_StdTree_Lrotate_Val12.md` |
| **System** | MSVC std `_Tree` left-rotate (Val12) |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `analyze_function_complete` (**no** `disassemble_bytes`) |
| **Verdict** | **accept** |

---

## 1. Purpose

Left-rotate about node `x` in a Val12 red-black tree: promote `x->right` to `x`'s former place; hang `x` as the new left child. Leaf pointer-surgery only.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00573170_FUN_00573170.md` (+ W26-Q append) |
| Annotated | `docs/reconstruction/raw/aa_00573170_FUN_00573170.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Lrotate_Val12.cpp` |
| Scaffold twin | `reconstructed-exact/FUN_00573170.cpp` |
| Function record | `docs/reconstruction/functions/aa_00573170_StdTree_Lrotate_Val12.md` |
| Live decompile | ≡ raw |
| Live body bytes | `read_memory` @ `0x00573170` length 78 (+ pad seal @ `0x005731BE`) |
| Buynode dual | `aa_005ae220` StdTree_Buynode_Val12 (W24-I accept) |
| Consumer dual | `aa_0051c1c0` Map_TreeInsertAndRebalance_Val12 (W25-G) |
| Twin rotate | `aa_00418c10` StdTree_Rrotate_Val12 |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| Body exclusive end | `0x005731BE` (`CC` pad after last `C2 04 00`) |
| Size | **78** B |
| Epilogue | `RET 4` ×3 paths |
| isnil test | `80 7E 19 00` / `CMP BYTE PTR [ESI+0x19], 0` |
| Tree head | `MOV ECX, [ECX+4]` then compare root at `[ECX+4]` |
| Leaf | 0 callees (`analyze_function_complete`) |

Full body hex:

```
8b5424048b4208568b308972088b30807e190075038956048b72048970048b49043b51045e750b8941048910894204c204008b4a043b11750a89018910894204c204008941088910894204c20400
```

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw | **pass** |
| Body size exclusive end | **pass** (`005731BE`) |
| `RET 4` / 1 stack arg | **pass** |
| thiscall ECX=tree | **pass** (`param_1` reg ECX; uses `this+4`) |
| Lrotate CF (y = right) | **pass** |
| Nil-child parent link | **pass** (isnil@+0x19) |
| Root / left / right reattach | **pass** (3 exits) |
| Clean has no bare `undefined4` | **pass** (`int32_t`) |
| Shared (not skill-only) | **pass** (13 callers) |
| Product demangle | **gap** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI | **High** | live ≡ raw; RET 4 sealed |
| Left-rotate identity | **High** | classical algorithm |
| Val12 layout | **High** | isnil@+0x19; buynode pair |
| Name `StdTree_Lrotate_Val12` | **Inferred** | structural; not plate |
| Runtime / differential | Open | |

---

## 6. Gaps

1. Product / MSVC demangle for each map type that instantiates this helper.  
2. Bit-exact / differential — open.

**Verdict:** **accept**
