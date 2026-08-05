# Review B (skeptical / adversarial): `aa_00571260` InventoryGrid_CollectPageCellKeys

| Field | Value |
|---|---|
| **Stable ID** | `aa_00571260` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00571260_InventoryGrid_CollectPageCellKeys.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | **Purges** cells not in list | Misread insert polarity | **Falsified** — inserts **missing** cell keys **into list**; grid untouched |
| 2 | Walks **item list** at `grid+0x2c` | FindByCoid pattern | **Falsified** — scans **cell array** `+0x28` |
| 3 | Full-grid scan (all pages) | Ignore page arg | **Falsified** — band `pageW * pageIndex` only |
| 4 | Returns grid this | thiscall habit | **Falsified** — returns **list** (or 0) |
| 5 | Insert on every occupied cell | Skip membership | **Falsified** — insert only when IterateNext finds no match |
| 6 | Empty test is `lo\|hi == -1` | Bitwise OR slip | **Falsified** — uses **AND** `(lo & hi) != 0xFFFFFFFF` as non-empty gate |
| 7 | Callees this = grid | Decompiler silence | **Falsified** — ECX = list for Lock/Iterate/Insert |
| 8 | Mutates grid occupancy | Side-effect inflation | **Falsified** — read cells; write only to list |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Collect-not-purge | **High** | Wrong rebuild data source |
| Page band math | **High** | Off-page widgets / misses |
| Index formula | **High** | Wrong COID → resolve fail |
| Empty AND test | **High** | Phantom/missing keys |
| Sole caller rebuild | **High** | Scope creep |
| Product name | **Med** | Doc |
| `+0x14` English “page count” | **Med–High** | Bound only proven as upper |

---

## 3. Cross-check raw ≡ force + insert

```text
// per non-empty cell key K on page:
TraversalLock(list)
found = any IterateNext_u64 key == K
unlock
if !found: Insert_u64(list, K)   // FUN_00573040 — append node
```

Parent `0x00860700` then walks **the list** (not the grid) to resolve objects and `AddItemWidget`.

---

## 4. Surviving contract

```
list_or_0 = InventoryGrid_CollectPageCellKeys(grid, list, pageIndex)
// list gains unique cell COID keys for that page band
// grid cells unchanged
```

**Port tests:** must not clear cells; must page-scope; must de-dupe via list membership; empty = both halves `0xFFFFFFFF` via AND check as retail.

**Verdict:** **accept-with-gaps** — purge/full-grid/return-grid attacks **fail**.
