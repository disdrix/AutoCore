# Review B (skeptical / adversarial): `aa_00407060` StdMap_InsertOrFind_PairKey_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00407060` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (WQ9I-C) |
| **Counterpart** | `reviews/A_aa_00407060_StdMap_InsertOrFind_PairKey_Isnil21_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** decompile + read_memory + analyze + disassemble_function (no disassemble_bytes).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Same as isnil29 pair insert-or-find `004cbee0` (merge VA) | **Falsified** — isnil@**+0x21**, insert worker `00407200` not `004cbb60` |
| 2 | Single dword int-key (like `004cbe20`) | **Falsified** — hi/lo pair walk |
| 3 | Both dwords signed | **Falsified** — lo uses **unsigned** `JAE`/`JNC` |
| 4 | Both dwords unsigned | **Falsified** — hi uses **signed** `JG`/`JL` |
| 5 | Always-insert only | **Falsified** — equal path `inserted=0` |
| 6 | Hit rewrites value | **Falsified** — stores only it + flag |
| 7 | RET 0x0c / 4 stack args | **Falsified** — **`RET 0x8`**, two stack args |
| 8 | isnil@+0x29 Val24 family | **Falsified** — `80 78 21 00` |
| 9 | Multi-caller shared library leaf | **Narrow** — **1** xref (`00406560` only) |
| 10 | Product TFID/operator[] name sealed | **Narrow** — structural only; `_Inferred` required |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Pair order (hi signed, lo unsigned) | **High** | wrong map order / missed hits |
| RET 8 thiscall | **High** | ABI break |
| Equal-no-write | **High** | corrupt mapped value |
| isnil21 family | **High** | wrong node layout |
| Product pair name | Medium | naming |

---

## 3. Cross-check

```
goRight when node <= key:
  node.hi < key.hi  OR  (node.hi == key.hi AND node.lo <= key.lo unsigned)
insert when node < key (strict lo)
else equal {it,0}
```

Matches dualed leaf less `00401480` and isnil29 pair shell `004cbee0` compare order; **do not merge** with those VAs or with int-key `004cbe20`.

---

## 4. Surviving contract for AutoCore

```csharp
(InsertPair out) InsertOrFind(MapShell map, in ValPairKey value)
{
    // lower_bound: hi signed primary, lo unsigned secondary
    // isnil +0x21; insert via FUN_00407200; pred FUN_005adff0
    // hit: no rewrite
}
```

---

## 5. Open questions

1. Is pair a TFID / object-id composite or other product type?  
2. Full dual of insert parent `FUN_00407200` (WQ9I-B).  
3. Runtime golden.
