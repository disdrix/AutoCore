# Review B (skeptical / adversarial): `aa_004e48b0` StdMap_InsertOrFind_PairKey_Isnil21_Via4e37e0_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e48b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (R13-005 OWN-ONLY) |
| **Counterpart** | `reviews/A_aa_004e48b0_StdMap_InsertOrFind_PairKey_Isnil21_Via4e37e0_Inferred.md` |
| **Parent dual** | `0x004e37e0` `StdTree_InsertAndRebalance_Val16_Isnil21_Inferred` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + callers/xrefs + `read_memory` (no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Same VA / merge with peer shell `00407060` | **Falsified** — different body VA; insert worker **`004e37e0`** not `00407200` |
| 2 | Same as isnil29 pair insert-or-find `004cbee0` | **Falsified** — isnil@**+0x21**, not +0x29 |
| 3 | Single dword int-key (like `004cbe20`) | **Falsified** — hi/lo pair walk |
| 4 | Both dwords signed | **Falsified** — lo uses **unsigned** `JAE`/`JNC` |
| 5 | Both dwords unsigned | **Falsified** — hi uses **signed** `JG`/`JL` |
| 6 | Always-insert only (no uniqueness) | **Falsified** — equal path `inserted=0` |
| 7 | Hit rewrites value / mapped payload | **Falsified** — stores only it + flag |
| 8 | `RET 0x10` like insert worker | **Falsified** — **`RET 0x8`** (2 stack args) |
| 9 | isnil@+0x29 / node 0x30 family | **Falsified** — `80 78 21 00` |
| 10 | Sole caller is only repair-station | **Weakened** — **2** callers (`004d38b0` + residual `004da160`) |
| 11 | Product TFID / operator[] name sealed | **Narrow** — structural only; `_Inferred` required |
| 12 | Runtime Confirmed | **Forbidden / Open** — no runtime this wave |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Pair order (hi signed, lo unsigned) | **High** | wrong map order / missed hits |
| RET 8 thiscall | **High** | stack smash |
| Equal-no-write | **High** | corrupt mapped value |
| isnil21 + Val16 insert via `004e37e0` | **High** | wrong specialization / merge |
| Distinct from `00407060` clone | **High** | wrong buynode/insert pairing |
| Product pair name | Medium | naming only |
| Runtime | Open | matrix policy |

---

## 3. Cross-check against raw + bytes

```
lower_bound from root; isnil@+0x21 stop
goRight when node <= key:
  node.hi < key.hi  OR  (node.hi == key.hi AND node.lo <= key.lo unsigned)
if goLeft:
  if where == begin: insert(addLeft=1) via 004e37e0 → {it,1}
  else pred(where) via 005adff0
if node < key: insert(addLeft) via 004e37e0 → {it,1}
else equal {it,0}  // no rewrite
ret 0x8
```

Clean must **not** invent int-key-only compare, isnil@+0x29, merge with `00407060`/`004cbee0`, or value rewrite on hit.

Do **not** put uniqueness inside insert worker `004e37e0` — parent shell owns lower-bound / equal.

---

## 4. Surviving contract for AutoCore

```csharp
// Unique insert-or-find for Val16 / isnil@+0x21 pair-key map
// (clone used under CVOGReaction repair-station + residual FUN_004da160)
// Insert worker: dualed StdTree_InsertAndRebalance_Val16_Isnil21 @ 004e37e0
(InsertPair out) InsertOrFind(MapShell map, in ValPairKey value)
{
    // lower_bound: hi signed primary, lo unsigned secondary
    // isnil +0x21; insert via FUN_004e37e0; pred FUN_005adff0
    // hit: no rewrite
}
```

Server ports must keep this shell for uniqueness; worker alone will duplicate keys.

Keep **separate** from peer shell `00407060` (same CF family, insert `00407200`).

---

## 5. Open questions

1. Exact demangled pair type (TFID lo/hi vs other product composite) for both callers.  
2. Whether residual second caller `004da160` is the same map specialization.  
3. Full dual of residual predecessor `005adff0`.  
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
