# Review B (skeptical / adversarial): `aa_004cbb60` StdTree_InsertAndRebalance_Isnil29_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cbb60` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (WQ9E-E) |
| **Counterpart** | `reviews/A_aa_004cbb60_StdTree_InsertAndRebalance_Isnil29_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` (no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is erase/rebalance (same as twin erase) | **Falsified** — length guard, buynode, size++, insert link path |
| 2 | Val12 insert clone (isnil@+0x19, max `0x15555553`) | **Falsified** — isnil@+0x29; max `0xAAAAAA8`; buynode `005a2de0` not Val12 |
| 3 | Aggro / GetTargetFromAggro product role | **Narrow** — scaffold callee chain; structural insert helper |
| 4 | Uniqueness / key compare inside this unit | **Falsified** — always-insert; parent walks keys |
| 5 | `addLeft==0` means add left | **Falsified** — decompile links **right** when `param_3==0` |
| 6 | RET 4 / 8 like rotates or erase | **Falsified** — **`ret 0x10`** (4 stack args) |
| 7 | Node size 0x1c (Val12) | **Falsified** — `operator_new(0x30)` in buynode |
| 8 | Inlined rotate uses Val12 isnil | **Falsified** — inlined path tests `+0x29` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Always-insert (not find) | **High** | wrong map semantics |
| ABI ret 0x10 thiscall | **High** | stack smash |
| isnil@+0x29 / node 0x30 | **High** | corruption |
| Max size constant | **High** | wrong length throw |
| 11 call sites / 3 callers | **High** | missing parents |
| Product English | Medium | naming only |
| Value field English | Low–Med | type registry only |

---

## 3. Cross-check against raw + bytes

```
if size > 0xAAAAAA8 → throw "map/set<T> too long"
n = buynode(head, where, head, value, red); size++
link left|right|empty extremities
while parent red: uncle recolor or rotate (isnil29 L/R; one L inlined)
root black; *outIt = n; ret 0x10
```

Clean must **not** invent key comparisons, Val12 max size, or isnil@+0x19.

---

## 4. Surviving contract for AutoCore

```csharp
// Always insert at (where, addLeft); parent owns uniqueness walk
void InsertAndRebalance(MapShell map, ref Node outIt, bool addLeft, Node where, Val24 value)
{
    if (map.Size > 0xAAAAAA8) throw new InvalidOperationException("map/set<T> too long");
    var n = BuyNode(map.Head, where, map.Head, value, color: Red);
    map.Size++;
    Link(map, n, where, addLeft);
    RebalanceInsert(map, n); // isnil29 rotates
    outIt = n;
}
```

Pair with erase twin `0x004cb740`. Do not merge with Val12 insert family.

---

## 5. Open questions

1. Demangled map type for `FUN_004cc220` / `004cbee0` / `004cbe20`.  
2. Exact layout of 6-dword value (key width / mapped blob).  
3. Runtime / bit-exact.

**Verdict:** **accept-with-gaps**
