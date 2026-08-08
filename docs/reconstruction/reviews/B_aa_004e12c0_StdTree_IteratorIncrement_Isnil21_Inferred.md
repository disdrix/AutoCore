# Review B (skeptical / adversarial): `aa_004e12c0` StdTree_IteratorIncrement_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e12c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (R13-003 OWN dual start **2686**) |
| **Counterpart** | `reviews/A_aa_004e12c0_StdTree_IteratorIncrement_Isnil21_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context` only. **No** `disassemble_bytes`. No Launcher.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is CNDHash freelist / stamp logic | **Falsified** — pure tree link walk; no freelist/next-stamp |
| 2 | This is predecessor / `operator--` | **Falsified** — right then left-min, or climb while **right**-child = **successor** |
| 3 | is_nil is at `+0x19` / `+0x29` / `+0x31` / `+0x49` / `+0x131` | **Falsified** — all guards use displacement **`0x21`** (`80 xx 21 00`) |
| 4 | Iterator in **EDX** like Isnil31 / Isnil131 | **Falsified** — entry `MOV EAX,[ECX]`; sites `LEA ECX`; stores `MOV [ECX],…` |
| 5 | Function takes map container as `this` | **Falsified** — only iterator `node**`; no container fields |
| 6 | Clean invents rebalance / color flips / key compare | **Falsified** — pure link walk; leaf |
| 7 | Returns next node in EAX | **Falsified** — void; only writes `*it` (analyze warning is noise) |
| 8 | Scaffold `Named_CalleeOf_*` is product role | **Falsified** — call-chain label only; multi-path shared util |
| 9 | Same binary as isnil31 `00408590` | **Falsified** — isnil offset + register formal (ECX vs EDX) differ; body size same 75 B shape only |
| 10 | Skills-abilities product skill UI | **Falsified as unit role** — partition assignment only; structural STL ++ |
| 11 | Runtime Confirmed successor | **Falsified** — static dual only; Terminal **false** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Successor algorithm | **High** | Wrong walk order on port |
| is_nil offset +0x21 | **High** | Infinite loop / skip nodes / wrong family |
| ABI (iterator in **ECX**) | **High** | Corrupt wrong pointer; EDX twin mismatch |
| Leaf / no callees | **High** | Invented helper deps |
| Not freelist / not -- | **High** | Mis-port into wrong path |
| Product map type names | Medium | Naming only |
| Runtime | Open | not claimed |

---

## 3. Cross-check against raw + bytes

```
node = *it                    // [ECX]
if node.is_nil(+0x21): return
if !right.is_nil:
    *it = leftmost(right)     // +8 then walk +0
    return
// climb while was right-child of parent(+4)
*it = first ancestor not reached as right child (may be nil head)
ret
```

Bytes seal every `+0x21` compare and both `C3` exits. Call-site pattern matches ECX formal across all 8 erase/hint parents.

Do **not** merge with:
- `aa_00457cc0` (isnil **+0x19**)
- `aa_004cb270` (isnil **+0x29**)
- `aa_00408590` (isnil **+0x31**, **EDX** ABI)
- `aa_00568200` (isnil **+0x49**)
- `aa_00404000` (isnil **+0x131**, **EDX** ABI)
- `aa_004313d0` (predecessor polarity)
- erase/rotate peers (this unit is **++ only**)

---

## 4. Surviving contract for AutoCore

```csharp
// Port shape — shared tree helper (isnil@+0x21 family)
void TreeIteratorIncrement_Isnil21(ref Node* it)
{
    var n = it;
    if (n->IsNil) return;          // +0x21
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

Port must keep **isnil@+0x21** and **ECX** iterator formal (not EDX isnil31 plate). Pair with isnil21 erase `00405650` / rotate `0050e9f0`/`005a27f0`.

---

## 5. Open questions

1. Exact demangled map type per caller (8 erase/hint hosts).  
2. Whether any non-erase call site exists beyond the 8 UNCONDITIONAL_CALL xrefs.  
3. Runtime / bit-exact.

**Verdict:** **accept-with-gaps** — algorithm/ABI sealed; product English residual; **not** Runtime Confirmed.
