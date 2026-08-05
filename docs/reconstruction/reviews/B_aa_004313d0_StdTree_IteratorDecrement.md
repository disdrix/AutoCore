# Review B (skeptical / adversarial): `aa_004313d0` StdTree_IteratorDecrement

| Field | Value |
|---|---|
| **Stable ID** | `aa_004313d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W22-O) |
| **Counterpart** | `reviews/A_aa_004313d0_StdTree_IteratorDecrement.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is iterator **increment** / successor | **Falsified** — left→rightmost + climb-while-**left**; nil→**right** (predecessor) |
| 2 | Returns next node in EAX | **Falsified** — only writes through `[EDX]`; plain void |
| 3 | Mutates tree links / rebalances | **Falsified** — leaf; no stores to node fields other than via iterator |
| 4 | Nil flag at `+0x29` like `004cb270` | **Falsified** — body uses **`+0x2d` only** |
| 5 | First arg in ECX is the iterator | **Falsified** — body starts `mov eax,[edx]`; call sites `lea edx,...` |
| 6 | Clean invents map-key comparisons | **Falsified** — no string/key ops |
| 7 | Domain-specific (combat/UI only) | **Falsified** — shared tree util; string-map insert among callers |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Predecessor vs successor polarity | **High** | Off-by-one on reverse walks / insert side |
| Nil offset `+0x2d` | **High** | Wrong node family port |
| EDX iterator slot | **High** | ABI mismatch |
| Product symbol spelling | Medium | Naming only |

---

## 3. Cross-check against raw + bytes

```
*it = node
if isnil(+0x2d): *it = right; ret
if left not nil: rightmost(left); *it = that; ret
parent-climb while *it == parent.left; *it = parent
```

Clean must **not** implement successor, recolor, or key compare.

Do **not** merge with `aa_004cb270` (different nil offset / direction).

---

## 4. Surviving contract for AutoCore

```csharp
// Port shape (client STL parity only if reverse map walks needed)
void StdTree_IteratorDecrement(ref NodePtr it)
{
    var n = it;
    if (n.IsNil) { it = n.Right; return; } // header → rightmost
    if (!n.Left.IsNil) {
        var x = n.Left;
        while (!x.Right.IsNil) x = x.Right;
        it = x; return;
    }
    var p = n.Parent;
    while (!p.IsNil && it == p.Left) { it = p; p = p.Parent; }
    if (!p.IsNil) it = p;
}
// Node: Left+0 Parent+4 Right+8 IsNil+0x2D
```

---

## 5. Open questions

1. Whether all four callers share the same node size (isnil@2d) — algorithm assumes yes.
2. Server AutoCore typically does not need this client STL helper.

**Verdict:** **accept**
