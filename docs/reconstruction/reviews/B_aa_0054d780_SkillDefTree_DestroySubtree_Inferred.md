# Review B (skeptical / adversarial): `aa_0054d780` SkillDefTree_DestroySubtree

| Field | Value |
|---|---|
| **Stable ID** | `aa_0054d780` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0054d780_SkillDefTree_DestroySubtree_Inferred.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Decompiler = full CF (right-only free) | `read_memory` shows left load + loop `74 DF` after delete | **Falsified decompiler** — **left iterative** after right recursive |
| 2 | Nil at `+0x15` like aux map | Bytes `cmp [edi+0x641],0` | **Falsified** — skill-def scale nil |
| 3 | `cdecl` / no stack cleanup | Epilogue `C2 04 00` | **Falsified** — **`ret 4`** |
| 4 | Frees payload separately then node | Only `operator_delete(node)` after unlinking children | **No separate payload free** |
| 5 | Unused ECX means not thiscall family | ECX saved/restored across recursive call | **ECX preserved**; still one stack arg |
| 6 | Same as `FUN_0054d7c0` | Different VA; 0054a1a0 uses `0054d7c0` | **Distinct helper** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Bytes CF (right-rec + left-iter) | **High** | Leaks half the tree on port |
| Nil `+0x641` | **High** | Wrong early stop / infinite free |
| `ret 4` | **High** | Stack imbalance |
| Decompiler insufficient alone | **High** | Must keep byte note in clean |

---

## 3. Surviving contract for AutoCore

```csharp
// Prefer this over naive recursive both-children if matching retail stack use
void SkillDefTree_DestroySubtree(Node* node)
{
    while (node != null && node->IsNil == 0) // flag at +0x641; 0 = live
    {
        DestroySubtree(node->Right); // +8, recursive
        var left = node->Left;       // +0
        Free(node);
        node = left;
    }
}
```

**Port traps:**

- Trusting Ghidra-only right-child free (leaks left subtrees).
- Using aux-map nil `+0x15`.
- Forgetting `ret 4` / stdcall cleanup.

---

## 4. Residual gaps

1. Exact IsNil polarity product name (0 = live sealed by jnz-to-done).
2. Node allocation size dual.

**Verdict:** **accept** — adversarial review **breaks the decompiler view**; bytes win.
