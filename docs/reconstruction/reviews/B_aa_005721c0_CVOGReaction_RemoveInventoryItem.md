# Review B (skeptical / adversarial): `aa_005721c0` CVOGReaction_RemoveInventoryItem

| Field | Value |
|---|---|
| **Stable ID** | `aa_005721c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005721c0_CVOGReaction_RemoveInventoryItem.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Always removes exact qty | **Overstated** — returns actual removed; may stop mid-scan after partial |
| 2 | Matches item instance id | **Falsified** — matches clonebase CBID field |
| 3 | Destroys on partial reduce | **Falsified** — partial only adjusts stack via +0x260 |
| 4 | Thread-safe without CS held flag | **Attacked** — depends on +0x54 / lock helpers |
| 5 | `1000000` is item max stack | **Unsealed** — destroy arg, not necessarily max stack |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Match key CBID | High | Wrong items removed |
| Partial vs full | High | Dup / ghost stacks |
| Return = removed count | High | Reaction qty desync |
| Temp list structure | Tentative | Use-after-free in port |

---

## 3. Cross-check against raw

Raw loop structure is the classic decompiler “do forever until iterator end flag.” Clean preserves that. Inventory system map lists this as reaction remove-by-CBID — consistent.

---

## 4. Surviving contract for AutoCore

```
RemoveInventoryItem(inv, cbid, qty) -> removed
  if cbid==-1 or qty<1: return 0
  lock inv; scan stacks with clonebase+0x34==cbid
  partial reduce or queue full remove until need met or end
  unlock; destroy queued; return removed
```

---

## 5. Open questions

1. Which inventories (cargo / personal / station) are passed.
2. Interaction with server inventory authority.
3. Exact destroy helpers.
4. Reaction type arm that calls this.

**Verdict:** Local remove kernel sealed for CF; helpers unnamed.
