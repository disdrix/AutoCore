# Review B (skeptical / adversarial): `aa_005b2c10` StdDeque_GrowMap_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b2c10` |
| **VA** | `0x005b2c10` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005b2c10_StdDeque_GrowMap_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Grows element storage buffer | Grows **map of block pointers** only | **Falsified as element buffer** |
| 2 | Always grows by exactly `param_2` | May raise to `max(mapsize/2, 8)` | **Falsified fixed grow** |
| 3 | Silent capacity failure | Overflow → **`"deque<T> too long"`** throw | **Falsified silent** |
| 4 | Same VA as skill `0051c3b0` | Different VA / throw helper; same algorithm | **Falsified identity** |
| 5 | Vector 1.5× grow (like `004073a0`) | Deque map prefer-half policy | **Falsified vector** |
| 6 | Always returns after `operator_delete` | Decomp marks delete **noreturn** | **Survives as decomp hazard** |
| 7 | Multiple callers | Sole **`005b2d70`** | **Confirmed sole** |
| 8 | Clean invents CF vs live | ≡ live | **Falsified** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| map / mapsize / off layout | **Confirmed** | corrupt deque |
| Prefer-grow policy | **Confirmed** | thrash / OOM |
| String-sealed deque family | **Confirmed** | wrong container port |
| Free-path mapsize update | **Medium** | leak / stale size |
| Element type | **Medium** | naming only |

---

## 3. Surviving contract for AutoCore

```
// Only from FUN_005b2d70 when map capacity tight:
StdDeque_GrowMap(this, 1);
// Implements MSVC-like deque map grow:
//   map[+4], mapsize[+8], rotate around (off[+0xC]>>2)
// Does not push elements (caller does). Does not alloc data blocks (caller may).
// On overflow: throw "deque<T> too long" via FUN_005b2a80.
```

Port rule: treat as twin of skill `aa_0051c3b0`; do not merge VAs; share algorithm tests.

---

## 4. Open questions

1. Disasm epilogue after `operator_delete` for mapsize write.
2. Whether grow is ever called with `param_2 != 1` (today only 1).
3. Promote `_Growmap` only with RTTI/mangling.

**Verdict:** **accept-with-gaps** — adversarial pass keeps deque-map grow; free-path residual only.
