# Review B (skeptical / adversarial): `aa_004cbe20` StdMap_InsertOrFind_IntKey_Isnil29_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cbe20` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (WQ9F-D) |
| **Counterpart** | `reviews/A_aa_004cbe20_StdMap_InsertOrFind_IntKey_Isnil29_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` + `read_memory` + `analyze_function_complete` (no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Always-insert (no uniqueness) | **Falsified** — equal path `inserted=0` |
| 2 | Hit rewrites mapped dwords | **Falsified** — only writes pair fields |
| 3 | isnil@+0x19 Val12 family | **Falsified** — isnil **@+0x29**; insert max `0xAAAAAA8` worker |
| 4 | Unsigned key | **Falsified** — **SETL** signed |
| 5 | RET 0x10 like insert worker | **Falsified** — shell **RET 8** |
| 6 | GetTargetFromAggro product member | **Narrow** — generic map helper; skill/rebuild callers |
| 7 | Decompiler void/no-arg truth | **Falsified** — thiscall + 2 stack args sealed |
| 8 | Pair-key compare (hi/lo) | **Falsified** — single int key @+0x10 only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| RET 8 thiscall shell | **High** | stack smash |
| Signed key order | **High** | sort bugs |
| Equal-no-write | **High** | silent clobber of cast bindings |
| isnil29 vs Val12 mix-up | **High** | corrupt tree |
| Product English | Medium | naming only |

---

## 3. Cross-check against raw + bytes

```
EDI = ECX map; EBP = value*
walk isnil@+0x29; goLeft = key < node.key (signed SETL)
if goLeft && node==leftmost: insert(1) → out{it,1}; ret 8
if goLeft: predecessor(004cb4f0)
if node.key < key: insert(goLeft) → out{it,1}; ret 8
else: out{node,0}; ret 8
```

Clean must **not** use Val12 insert-or-find templates, unsigned SETB, or pair-key peer `004cbee0` compare.

---

## 4. Surviving contract for AutoCore

```csharp
// Unique insert-or-find; thiscall RET 8
(InsertPair out) InsertOrFind(MapShell map, in ValIntKey value)
{
    // lower_bound walk, SIGNED key at value.Key / node+0x10
    // isnil at +0x29
    if (/* miss */) {
        var n = StdTree_InsertAndRebalance_Isnil29(...);
        return (n, true);
    }
    return (existing, false); // do NOT rewrite existing mapped fields
}
```

Server ports: preserve signed order and no hit rewrite (skill active-cast map depends on this).

---

## 5. Open questions

1. Exact demangled value_type for active-cast map.  
2. Whether `FUN_004c9380` rebuild assumes empty dest map.  
3. Predecessor helper dual (`FUN_004cb4f0`) — residual.
