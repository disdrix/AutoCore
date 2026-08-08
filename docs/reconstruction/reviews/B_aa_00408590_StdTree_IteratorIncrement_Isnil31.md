# Review B (skeptical / adversarial): `aa_00408590` StdTree_IteratorIncrement_Isnil31

| Field | Value |
|---|---|
| **Stable ID** | `aa_00408590` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (WQ9H-H) |
| **Counterpart** | `reviews/A_aa_00408590_StdTree_IteratorIncrement_Isnil31.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` + call-site `get_assembly_context` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is CNDHash freelist / stamp logic | **Falsified** — pure tree link walk; freelist is next leaf `0x004085e0` only by VA adjacency |
| 2 | This is predecessor / `operator--` | **Falsified** — right then left-min, or climb while **right**-child = **successor** |
| 3 | is_nil is at `+0x19` / `+0x29` / `+0x49` | **Falsified** — all guards use displacement **`0x31`** (`80 xx 31 00`) |
| 4 | Iterator in **ECX** like Isnil49 | **Falsified** — entry `MOV EAX,[EDX]`; sites `LEA EDX` |
| 5 | Function takes map container as `this` | **Falsified** — only iterator `node**`; no container fields |
| 6 | Clean invents rebalance / color flips / key compare | **Falsified** — pure link walk; leaf |
| 7 | Returns next node in EAX | **Falsified** — void; only writes `*it` |
| 8 | Scaffold `Named_CalleeOf_Client_NotifyActiveMissionChanged_*` is role | **Falsified** — call-chain label only; multi-path shared util |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Successor algorithm | **High** | Wrong walk order on port |
| is_nil offset +0x31 | **High** | Infinite loop / skip nodes / wrong family |
| ABI (iterator in **EDX**) | **High** | Corrupt wrong pointer; ECX twin mismatch |
| Not freelist | **High** | Mis-port into CNDHash free path |
| Product map type names | Medium | Naming only |

---

## 3. Cross-check against raw + bytes

```
node = *it                    // [EDX]
if node.is_nil(+0x31): return
if !right.is_nil:
    *it = leftmost(right)     // +8 then walk +0
    return
// climb while was right-child of parent(+4)
*it = first ancestor not reached as right child (may be nil head)
ret
```

Bytes seal every `+0x31` compare and both `C3` exits. Call-site pattern matches EDX formal.

Do **not** merge with:
- `aa_00457cc0` (isnil **+0x19**)
- `aa_004cb270` (isnil **+0x29**)
- `aa_00568200` (isnil **+0x49**, **ECX** ABI)
- `aa_004313d0` (predecessor polarity)
- `FUN_004085e0` (CNDHash freelist walk)

---

## 4. Surviving contract for AutoCore

```csharp
// Port shape — shared tree helper (isnil@+0x31 family)
void TreeIteratorIncrement_Isnil31(ref Node* it)
{
    var n = it;
    if (n->IsNil) return;          // +0x31
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

**Verdict:** **accept**
