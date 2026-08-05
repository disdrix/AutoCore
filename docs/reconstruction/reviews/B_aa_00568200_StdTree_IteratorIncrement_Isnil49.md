# Review B (skeptical / adversarial): `aa_00568200` StdTree_IteratorIncrement_Isnil49

| Field | Value |
|---|---|
| **Stable ID** | `aa_00568200` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W22-B) |
| **Counterpart** | `reviews/A_aa_00568200_StdTree_IteratorIncrement_Isnil49.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This fills journal mission-id vectors | **Falsified** — no push, no write beyond `*it`; pure link walk |
| 2 | This is predecessor / `operator--` | **Falsified** — right then left-min, or climb while **right**-child = **successor** |
| 3 | is_nil is at `+0x29` like `004cb270` | **Falsified** — all guards use displacement **`0x49`** |
| 4 | Function takes map container as `this` | **Falsified** — ECX is iterator (`node**`); no container fields |
| 5 | Clean invents rebalance / color flips | **Falsified** — clean is successor-only; no color stores |
| 6 | Same instantiation as every map | **Open residual** — layout family with is_nil@+0x49 (e.g. 0x50 staging nodes); not all trees |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Successor algorithm | **High** | Wrong walk order on port |
| is_nil offset +0x49 | **High** | Infinite loop / skip nodes |
| ABI (iterator in ECX) | **High** | Corrupt wrong pointer |
| Twin relation to +0x29 unit | **High** | Wrong node size when reusing helpers |
| Product map type names | Medium | Naming only |

---

## 3. Cross-check against raw + bytes

```
node = *it
if node.is_nil(+0x49): return
if !right.is_nil:
    *it = leftmost(right)   // walk left(+0)
    return
// climb while was right-child of parent(+4)
*it = first ancestor not reached as right child (may be nil head)
ret
```

Bytes seal every `+0x49` compare and both `c3` exits. Insert-with-hint caller `FUN_00569560` uses this as **successor** of hint (with predecessor twin `FUN_00537770`).

---

## 4. Surviving contract for AutoCore

```csharp
// Port shape — shared tree helper (client maps/sets)
void TreeIteratorIncrement(ref Node* it)
{
    var n = it;
    if (n->IsNil) return;          // +0x49
    if (!n->Right->IsNil) {
        it = Leftmost(n->Right);   // +8 then walk +0
        return;
    }
    var p = n->Parent;             // +4
    while (!p->IsNil && it == p->Right) {
        it = p;
        p = p->Parent;
    }
    it = p;
}
```

Do **not** treat as journal id collection. Mission journal walk sites call this only to step the tree.

---

## 5. Open questions

1. Exhaustive list of map value sizes sharing is_nil@+0x49.
2. Whether server AutoCore ports this helper or uses STL.

**Verdict:** **accept**
