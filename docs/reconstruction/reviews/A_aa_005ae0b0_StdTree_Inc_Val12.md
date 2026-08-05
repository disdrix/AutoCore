# Review A (reconstruction fidelity): `aa_005ae0b0` StdTree_Inc_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ae0b0` |
| **VA** | `0x005ae0b0`–`0x005ae0fb` (**75 B**) |
| **Canonical name** | `StdTree_Inc_Val12` |
| **Ghidra name** | `FUN_005ae0b0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W28-N) |
| **Counterpart** | `reviews/B_aa_005ae0b0_StdTree_Inc_Val12.md` |
| **System** | std red-black tree / map iterator (Val12) |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (full body hex) + bulk xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept** |

---

## 1. Purpose

MSVC-style **`_Tree::_Inc`** / unchecked iterator++ for **Val12** nodes (isnil @ +0x19). Advances `*it` to the in-order successor. Shared leaf used by multiple Val12 erase helpers (including `StdTree_EraseNode_Val12`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W28-N) | `docs/reconstruction/raw/aa_005ae0b0_FUN_005ae0b0.md` |
| Annotated | `docs/reconstruction/raw/aa_005ae0b0_FUN_005ae0b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Inc_Val12.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_005ae0b0.cpp` |
| Function record | `docs/reconstruction/functions/aa_005ae0b0_StdTree_Inc_Val12.md` |
| Consumer | `aa_005ae990` StdTree_EraseNode_Val12 (W27-T) |
| Live | decompile ≡ bytes for CF; leaf |

---

## 3. Signature (sealed)

```c
// ECX = node**; bare RET; void
void __fastcall StdTree_Inc_Val12(StdTreeNode_Val12 **it);
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
if node.isnil: return
if !node.right.isnil:
  p = node.right
  while !p.left.isnil: p = p.left
  *it = p; return
parent = node.parent
while !parent.isnil && *it == parent.right:
  *it = parent; parent = parent.parent
*it = parent
```

| Stage | Match | Conf |
|---|---|---|
| isnil gate @+0x19 | **Yes** | **High** |
| Right-then-leftmost | **Yes** | **High** |
| Parent walk from right | **Yes** | **High** |
| Leaf (no callees) | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (75 B):
```
8b018078190075428b5008807a1900751c8b028078190075118da424000000008bd08b028078190074f68911c38b40048078190075128b113b5008750b89018b40048078190074ee8901c3
```

| Feature | Encoding |
|---|---|
| isnil compare | `80 78 19 00` / `80 7a 19 00` |
| Epilogue | dual `C3` paths |
| Pad | `CC` after final RET |

**No `disassemble_bytes` used.**

---

## 6. Gaps

- Product/MSVC demangle per map instantiation.
- Runtime differential — open.
- Legacy skill-status seed name is not role authority.

---

## 7. Verdict

**accept** — successor CF, Val12 layout, ABI, and multi-caller shared-helper role sealed.
