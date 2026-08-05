# Review B (skeptical / adversarial): `aa_00572ab0` InventoryGrid_AutoMergePartialStacks_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00572ab0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W29-E) |
| **Counterpart** | `reviews/A_aa_00572ab0_InventoryGrid_AutoMergePartialStacks_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Same as `InventoryGrid_MergeStackQty` (`00571830`) | **Falsified** — that unit is COID+delta single merge; this is full-grid multi-item consolidate |
| 2 | Same as `Item_CanAcceptStackQty` | **Falsified** — that is pure predicate; this **mutates** qtys / removes items |
| 3 | Type-4 max is 999999 (`0xF423F`) | **Falsified for effective cap** — uses `0x423F` (16959), same mask quirk as `aa_0040abf0` |
| 4 | Ghidra body end `0x00572e7f` is true | **Falsified** — plate false-noreturn on `operator_delete`; bytes continue to `0x00572ec6` RET with AL=dirty |
| 5 | Returns void / no dirty | **Falsified** — `mov al,[esp+0x1b]` then `C3`; caller `008c2f50` tests AL |
| 6 | Match by COID / template id only | **Falsified** — peer filter is `clonebase+0x34` equality |
| 7 | Multiple callers | **Falsified** — single xref `008c2f72` |
| 8 | Product name without `_Inferred` | **Do not claim** — no RTTI/string plate |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Residual vs full absorb CF | **High** | Wrong stack totals / dup items |
| Max-stack inlined formula | **High** | Over/under fill vs client |
| Match key +0x34 | **High** | Cross-type illegal merges |
| True epilogue AL dirty | **High** | Miss notify path |
| RemoveItem 1000000 + QueueDelete | **High** | Leaked zero-qty items |
| Product English | **Medium** | Naming only |
| 0x204a wire meaning | **Open** | Caller/system |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against related duals

| Unit | Relation |
|---|---|
| `Item_CanAcceptStackQty` | Same max formula; this **inlines** it thrice rather than calling the leaf |
| `Item_IsStackEligible` | Gate before any merge attempt |
| `StdMap_InsertOrFind_Val12_UintKey` | Temp partial map insert (call sites in this body) |
| `StdTree_Erase_Val12` | Remove peer after residual transfer |
| `StdTree_Inc_Val12` | Walk partial map |
| `InventoryGrid_RemoveItem` | End-of-pass purge of zeroed stacks |
| `FUN_008c2f50` | Only consumer; AL gate for `0x204a` send |

---

## 4. Surviving contract for AutoCore

```
// Port as full-grid underfilled stack consolidate:
bool changed = InventoryGrid_AutoMergePartialStacks(grid);
// - walk grid list @ +0x2c under TraversalLock
// - eligible + qty < max only
// - peer key = clonebase+0x34
// - max: type4 → 16959; else def+0x4BA or 200
// - full absorb → RemoveItem+QueueDelete at end
// - set grid+0x21 on change; return dirty
// do NOT substitute MergeStackQty (COID) or CanAcceptStackQty (predicate)
```

---

## 5. Verdict

Adversarial pass **confirms** A’s CF/ABI/formula seals and **rejects** plate-end / 999999 / COID-merge confusions → **accept-with-gaps**.
