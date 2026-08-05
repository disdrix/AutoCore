# Review B (skeptical / adversarial): `aa_00418c70` SkillDefMap_LowerBoundByIntKey

| Field | Value |
|---|---|
| **Stable ID** | `aa_00418c70` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00418c70_SkillDefMap_LowerBoundByIntKey_Inferred.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Exact find by itself | No equality test; only BST walk | **Falsified** — lower_bound only |
| 2 | Nil at `+0x15` / `+0x1d` like other maps | Bytes `+0x641` | **Falsified** |
| 3 | Key at `node[0]` | `cmp [ecx+0xC], edx` | **Key at +0x0C** |
| 4 | `cdecl` two stack args | `ret 4` + this in ECX | **thiscall + 1 stack** |
| 5 | Same helper as `Map_LowerBoundFindByIntKey` `0x0050f940` | Different nil/key layout | **Distinct family** |
| 6 | Mutates tree | No stores | **Read-only** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Lower_bound semantics | **High** | Wrong ExactFind results |
| Layout nil/key/links | **High** | Corrupt walk / crash |
| ABI ret 4 | **High** | Stack smash |
| Not portable to small maps | **High** | Silent wrong finds |

---

## 3. Surviving contract for AutoCore

```csharp
Node* SkillDefMap_LowerBoundByIntKey(MapHeader* map, int key)
{
    var node = map.Head.Parent; // *( *(map+4) + 4 )
    Node* cand = map.Head;      // as retail keeps prior
    while (!node.IsNil) {       // +0x641
        if (node.Key < key) {   // key +0x0C
            node = node.Right;  // +8
        } else {
            cand = node;
            node = node.Left;   // +0
        }
    }
    return cand;
}
// ExactFind = lower_bound then key equality gate — NOT this unit alone
```

**Port traps:**

- Returning this result as exact hit without parent ≤/== check.
- Using small-map lower_bound helpers.
- Wrong key offset.

---

## 4. Residual gaps

1. Product name.
2. Runtime seal.

**Verdict:** **accept**
