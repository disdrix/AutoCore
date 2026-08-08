# Review B (skeptical / adversarial): `aa_004cbee0` StdMap_InsertOrFind_PairKey_Isnil29_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cbee0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (WQ9F-D) |
| **Counterpart** | `reviews/A_aa_004cbee0_StdMap_InsertOrFind_PairKey_Isnil29_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** decompile + read_memory + analyze (no disassemble_bytes).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Same as int-key `004cbe20` (single dword key) | **Falsified** — hi/lo pair walk |
| 2 | Both dwords signed | **Falsified** — lo uses **unsigned** `JAE` |
| 3 | Both dwords unsigned | **Falsified** — hi uses **signed** `JG`/`JL` |
| 4 | Always-insert | **Falsified** — equal path |
| 5 | Hit rewrites value | **Falsified** |
| 6 | Val12 isnil@+0x19 | **Falsified** — isnil@+0x29 |
| 7 | VOG_DEBUG product member | **Narrow** — generic pair insert-or-find; one caller |
| 8 | Multi-caller shared like int-key peer | **Falsified** — **1** xref only (`004cc220`) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Pair order (hi signed, lo unsigned) | **High** | wrong map order / missed hits |
| RET 8 thiscall | **High** | |
| Equal-no-write | **High** | |
| isnil29 family | **High** | |
| Product pair name | Medium | naming |

---

## 3. Cross-check

```
goRight when node <= key:
  node.hi < key.hi  OR  (node.hi == key.hi AND node.lo <= key.lo unsigned)
insert when node < key (strict lo)
else equal {it,0}
```

Do **not** merge with `004cbe20` int-key shell or Val12 pair maps.

---

## 4. Surviving contract for AutoCore

```csharp
(InsertPair out) InsertOrFind(MapShell map, in ValPairKey value)
{
    // lower_bound: hi signed primary, lo unsigned secondary
    // isnil +0x29; insert via StdTree_InsertAndRebalance_Isnil29
    // hit: no rewrite
}
```

---

## 5. Open questions

1. Is pair a TFID / object-id composite or other product type?  
2. Full dual of hint parent `FUN_004cc220` (WQ9F-E).  
3. Runtime golden.
