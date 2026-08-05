# Review A (reconstruction fidelity): `aa_005ae050` StdTree_Dec_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ae050` |
| **VA** | `0x005ae050`–`0x005ae0a0` (**80 B**) |
| **Canonical name** | `StdTree_Dec_Val12` |
| **Ghidra name** | `FUN_005ae050` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W29-E) |
| **Counterpart** | `reviews/B_aa_005ae050_StdTree_Dec_Val12.md` |
| **System** | std red-black tree / map iterator (Val12) |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (full body hex) + bulk xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept** |

---

## 1. Purpose

MSVC-style **`_Tree::_Dec`** / unchecked iterator-- for **Val12** nodes (isnil @ +0x19). Advances `*it` to the in-order predecessor. Shared leaf used by multiple Val12 unique-insert helpers (including `StdMap_InsertOrFind_Val12_UintKey`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W29-E) | `docs/reconstruction/raw/aa_005ae050_FUN_005ae050.md` |
| Annotated | `docs/reconstruction/raw/aa_005ae050_FUN_005ae050.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Dec_Val12.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_005ae050.cpp` |
| Function record | `docs/reconstruction/functions/aa_005ae050_StdTree_Dec_Val12.md` |
| Twin | `aa_005ae0b0` StdTree_Inc_Val12 (W28-N) |
| Live | decompile ≡ bytes for CF; leaf |

---

## 3. Signature (sealed)

```c
// ECX = node**; bare RET; void
void __fastcall StdTree_Dec_Val12(StdTreeNode_Val12 **it);
```

| Formal | Source | Conf |
|---|---|---|
| it | ECX | **High** |
| return | void | **High** |
| cleanup | bare `C3` | **High** |

---

## 4. Control flow (clean ≡ decompile ≡ bytes)

```
node = *it
if node.isnil:
  *it = node.right; return
if !node.left.isnil:
  p = node.left
  while !p.right.isnil: p = p.right
  *it = p; return
parent = node.parent
if !parent.isnil:
  while !parent.isnil && *it == parent.left:
    *it = parent; parent = parent.parent
  if !parent.isnil: *it = parent
```

| Stage | Match | Conf |
|---|---|---|
| isnil gate @+0x19 | **Yes** | **High** |
| Nil → header.right | **Yes** | **High** |
| Left-then-rightmost | **Yes** | **High** |
| Parent walk from left | **Yes** | **High** |
| Leaf (no callees) | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (80 B):
```
8b018078190074068b40088901c38b10807a190075188b420880781900750c908bd08b42088078190074f58911c38b40048078190075198b113b10750b89018b40048078190074ef8078190075028901c3
```

| Feature | Encoding |
|---|---|
| isnil compare | `80 78 19 00` / `80 7a 19 00` |
| Epilogue | multiple `C3` paths |
| Pad | `CC` after final RET |

**No `disassemble_bytes` used.**

---

## 6. Gaps

- Product/MSVC demangle per map instantiation.
- Runtime differential — open.

---

## 7. Verdict

**accept** — CF, ABI, Val12 layout, and predecessor role fully sealed from decompile + bytes.
