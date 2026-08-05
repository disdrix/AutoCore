# Review B (skeptical / adversarial): `aa_00457cc0` StdTree_IteratorIncrement_Isnil19

| Field | Value |
|---|---|
| **Stable ID** | `aa_00457cc0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (W38-B) |
| **Counterpart** | `reviews/A_aa_00457cc0_StdTree_IteratorIncrement_Isnil19.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` + call-site `get_assembly_context` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is AssPreloader-private only | **Falsified** — 9 distinct callers; shared tree util |
| 2 | This is predecessor / `operator--` | **Falsified** — right then left-min, or climb while **right**-child = **successor** |
| 3 | is_nil is at `+0x29` or `+0x49` like twins | **Falsified** — all guards use displacement **`0x19`** |
| 4 | Iterator in **ECX** like Isnil49 | **Falsified** — entry `MOV EAX,[EDX]`; sites `LEA EDX` |
| 5 | Function takes map container as `this` | **Falsified** — only iterator `node**`; no container fields |
| 6 | Clean invents rebalance / color flips / key compare | **Falsified** — pure link walk; leaf |
| 7 | Returns next node in EAX | **Falsified** — void; only writes `*it` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Successor algorithm | **High** | Wrong walk order on port |
| is_nil offset +0x19 | **High** | Infinite loop / skip nodes / wrong family |
| ABI (iterator in **EDX**) | **High** | Corrupt wrong pointer; ECX twin mismatch |
| Multi-caller shared util | **High** | Mis-scope AssPreloader ownership |
| Product map type names | Medium | Naming only |

---

## 3. Cross-check against raw + bytes

```
node = *it                    // [EDX]
if node.is_nil(+0x19): return
if !right.is_nil:
    *it = leftmost(right)     // +8 then walk +0
    return
// climb while was right-child of parent(+4)
*it = first ancestor not reached as right child (may be nil head)
ret
```

Bytes seal every `+0x19` compare and both `C3` exits. Call-site pattern matches EDX formal exclusively among sampled AssPreloader + container walks.

Do **not** merge with:
- `aa_004cb270` (isnil **+0x29**)
- `aa_00568200` (isnil **+0x49**, **ECX** ABI)
- `aa_004313d0` (predecessor polarity)

---

## 4. Surviving contract for AutoCore

```csharp
// Port shape — shared Val12-family tree helper
void TreeIteratorIncrement_Isnil19(ref Node* it)
{
    var n = it;
    if (n->IsNil) return;          // +0x19
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
// Node: Left+0 Parent+4 Right+8 IsNil+0x19
// ABI note: retail passes it in EDX (not ECX)
```

Do **not** hard-wire to AssPreloader — multi-caller leaf.

---

## 5. Open questions

1. Exhaustive inventory of map value sizes sharing is_nil@+0x19 (Val12 continuum).
2. Whether server AutoCore ports this helper or uses managed/STL maps.

**Verdict:** **accept**
