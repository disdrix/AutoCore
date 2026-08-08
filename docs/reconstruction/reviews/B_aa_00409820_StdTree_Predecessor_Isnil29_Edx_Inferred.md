# Review B (skeptical / adversarial): `aa_00409820` StdTree_Predecessor_Isnil29_Edx_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00409820` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (WQ9J-G) |
| **Counterpart** | `reviews/A_aa_00409820_StdTree_Predecessor_Isnil29_Edx_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` + call-site bytes (no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is **successor** (`operator++`) not predecessor | **Falsified** — left-subtree max + climb while left-child is classic predecessor |
| 2 | isnil@+0x31 / +0x2d family | **Falsified** — all cmps are `… 29 00` |
| 3 | ECX = it (like twin `0x004cb4f0`) | **Falsified** — entry `8B 02` + call site `LEA EDX,…` |
| 4 | Stack args / RET N | **Falsified** — bare `C3` |
| 5 | Mutates color / key / allocates | **Falsified** — stores only through `*it` |
| 6 | Product Named_CalleeOf_Error_Receiv* member | **Narrow** — generic tree helper; scaffold chain rejected |
| 7 | Same node family as co-located BuyHead `00409780` | **Falsified** — that unit is isnil@+0x2d |
| 8 | Decompiler void / dual-arg truth | **Partial** — void OK; real arg is EDX Node** only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EDX Node**; bare RET | **High** | wrong ABI → crash on insert-or-find |
| isnil@+0x29 | **High** | walk off-tree / wrong family |
| Predecessor algebra | **High** | wrong neighbor → corrupt insert side |
| Product English | Medium | naming only |

---

## 3. Cross-check against raw + bytes

```
EDX = it (Node**)
cur = *it
if cur->isnil: *it = cur->right; ret
if cur->left not isnil: *it = rightmost(left); ret
parent = cur->parent
while parent not isnil and *it == parent->left:
  *it = parent; parent = parent->parent
if parent not isnil: *it = parent
ret  ; C3
```

Clean must **not** use isnil15/isnil31 offsets, ECX-only ABI claim as sole convention, successor right-min walk, or insert/rebalance.

---

## 4. Surviving contract for AutoCore

```csharp
// Leaf predecessor; EDX = Node**; bare ret
void StdTree_Predecessor_Isnil29_Edx(ref Node* it)
{
    // isnil @ +0x29; left/parent/right @ 0/4/8
    // three-arm MSVC _Dec; no alloc/rebalance/key
}
```

Port twin of ECX `StdTree_Predecessor_Isnil29` when residual insert-or-find (`FUN_00405bd0`) is dualed.

---

## 5. Open questions

1. Exact demangled node type for sole caller `FUN_00405bd0`.
2. Why a second isnil29 predecessor clone (EDX) exists beside ECX twin `0x004cb4f0`.
3. Runtime empty-tree / header-only cases.

**Verdict:** **accept-with-gaps**
