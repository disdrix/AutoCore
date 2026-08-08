# Review B (skeptical / adversarial): `aa_00404000` StdTree_IteratorIncrement_Isnil131

| Field | Value |
|---|---|
| **Stable ID** | `aa_00404000` |
| **VA** | `0x00404000`–`0x00404057` inclusive (**88 B** / `0x58`) |
| **Canonical name** | `StdTree_IteratorIncrement_Isnil131` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (WQ9L-A OWN dual) |
| **Counterpart** | `reviews/A_aa_00404000_StdTree_IteratorIncrement_Isnil131.md` |
| **System** | shared `client::stdtree` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `disassemble_function` + `read_memory` + call-site `get_assembly_context` + callers/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is predecessor / `operator--` | **Falsified** — right then left-min, or climb while **right**-child = **successor** |
| 2 | is_nil is at `+0x31` / `+0x19` / `+0x29` / `+0x49` | **Falsified** — all guards use displacement **`0x131`** (`80 xx 31 01 00 00`) |
| 3 | Same binary as dualed isnil31 `0x00408590` | **Falsified** — same CF template, different isnil offset / body size (88 B vs 75 B) |
| 4 | Iterator in **ECX** like Isnil49 | **Falsified** — entry `MOV EAX,[EDX]`; sites `LEA EDX,[ESP+…]` |
| 5 | Function takes map container as `this` | **Falsified** — only iterator `node**`; no container fields |
| 6 | Clean invents rebalance / color flips / key compare | **Falsified** — pure link walk; leaf; no callees |
| 7 | Returns next node in EAX | **Falsified** — void; only writes `*it` (both exits `C3`) |
| 8 | This is erase / free-subtree / range walk body | **Falsified** — no delete, no size, no string dtor; pure successor |
| 9 | Scaffold product-callee plate is role | **Falsified** — multi-path shared util (erase-range + erase + large client helper) |
| 10 | Merge with OWN peer erase `00408ad0` | **Falsified** — erase **calls** this; different ABI (plain RET vs RET 0xC) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Successor algorithm | **High** | Wrong walk order on port |
| is_nil offset +0x131 | **High** | Infinite loop / skip nodes / wrong family |
| ABI (iterator in **EDX**) | **High** | Corrupt wrong pointer; ECX twin mismatch |
| Not erase/rebalance | **High** | Mis-port into erase path |
| Distinct from isnil31 twin | **High** | Layout corruption if offset swapped |
| Product map type names | Medium | Naming only |

---

## 3. Cross-check against raw + bytes

```
node = *it                    // [EDX]
if node.is_nil(+0x131): return
if !right.is_nil:
    *it = leftmost(right)     // +8 then walk +0
    return
// climb while was right-child of parent(+4)
*it = first ancestor not reached as right child (may be nil head)
ret                           // C3
```

Bytes seal every `+0x131` compare and both `C3` exits. Call-site pattern matches EDX formal:

| Site | Pattern |
|---|---|
| `0x00407bc6` in `FUN_00407b70` | `LEA EDX,[ESP+0x14]` → `CALL 00404000` (range loop advance) |
| `0x00408b37` in `FUN_00408ad0` | `LEA EDX,[ESP+0x70]` → `CALL 00404000` (successor capture) |
| `FUN_00957820` ×4 | UNCONDITIONAL_CALL xrefs |

Do **not** merge with:

- `aa_00408590` (isnil **+0x31**)
- `aa_00457cc0` (isnil **+0x19**)
- `aa_004cb270` (isnil **+0x29**)
- `aa_00568200` (isnil **+0x49**, **ECX** ABI)
- `aa_004313d0` (predecessor polarity)
- `aa_00408ad0` (erase+rebalance OWN peer — **caller**, not twin)

---

## 4. Surviving contract for AutoCore

```csharp
// Port shape — shared tree helper (isnil@+0x131 family)
void TreeIteratorIncrement_Isnil131(ref Node* it)
{
    var n = it;
    if (n->IsNil) return;          // +0x131
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
