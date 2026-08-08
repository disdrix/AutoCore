# Review B (skeptical / adversarial): `aa_004cb4f0` StdTree_Predecessor_Isnil29_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cb4f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (WQ9G-B) |
| **Counterpart** | `reviews/A_aa_004cb4f0_StdTree_Predecessor_Isnil29_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` + `get_assembly_context` (no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is **successor** (`operator++`) not predecessor | **Falsified** — left-subtree max + climb while left-child is classic predecessor; hint parent uses it as **prev** |
| 2 | isnil@+0x15 family (isnil15 peers) | **Falsified** — all cmps are `… 29 00` |
| 3 | EDX = it (like `Map_Tree_Predecessor_Isnil15_Edx`) | **Falsified** — entry `8B 01` + call sites `LEA ECX,…` |
| 4 | Stack args / RET N | **Falsified** — bare `C3` |
| 5 | Mutates color / key / allocates | **Falsified** — stores only through `*it` |
| 6 | Product VOGClient member | **Narrow** — generic tree helper; multi-domain callers |
| 7 | Decompiler void/no-arg truth | **Partial** — void OK; arg is ECX Node** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX Node**; bare RET | **High** | wrong ABI → crash on hint insert |
| isnil@+0x29 | **High** | walk off-tree / wrong family |
| Predecessor algebra | **High** | wrong neighbor → corrupt insert side |
| Product English | Medium | naming only |

---

## 3. Cross-check against raw + bytes

```
ECX = it (Node**)
cur = *it
if cur->isnil: *it = cur->right; ret
if cur->left not isnil: *it = rightmost(left); ret
parent = cur->parent
while parent not isnil and *it == parent->left:
  *it = parent; parent = parent->parent
if parent not isnil: *it = parent
ret  ; C3
```

Clean must **not** use isnil15 offsets, EDX ABI, successor right-min walk, or insert/rebalance.

---

## 4. Surviving contract for AutoCore

```csharp
// Leaf predecessor; ECX = Node**; bare ret
void StdTree_Predecessor_Isnil29(ref Node* it)
{
    // isnil @ +0x29; left/parent/right @ 0/4/8
    // three-arm MSVC _Dec; no alloc/rebalance/key
}
```

Server ports of isnil29 insert-or-find / insert-hint must call this (or equivalent) for goLeft / prev-neighbor paths.

---

## 5. Open questions

1. Exact demangled node type across all five callers.  
2. Relationship of `FUN_00406040` (possible isnil@+0x21 shell) sharing this pred helper.  
3. Runtime empty-tree / header-only cases.
