# Review B (skeptical / adversarial): `aa_0058df60` MapFloatTfid_EraseRange_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0058df60` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0058df60_MapFloatTfid_EraseRange_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Only frees head (`operator_delete` only) | Body frees interior via 0058da00/0058dc30; parent deletes head after | **Falsified head-only** |
| 2 | Dumps / sorts targets | No out-list writes | **Falsified** |
| 3 | Gather-only | Also `FUN_0058cd60`, `FUN_0058e020` | **Falsified** |
| 4 | Always full clear | Partial loop exists when range not full | **Falsified always-full** (even if gather uses full) |
| 5 | Leaves size stale on full clear | Writes `tree+8 = 0` | **Falsified** |
| 6 | Same as `FUN_0058c7a0` | Dump vs erase | **Falsified** |
| 7 | Product clear() sealed | Behavior High; name Inferred | **Hold `_Inferred`** |
| 8 | Safe if first/last inverted | Loop `while first!=last` only — bad iterators residual | **Open misuse** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Full-clear path | **High** | Leak entire sort map |
| Partial erase loop | **High** | Partial port wrong |
| Multi-caller | **High** | Miss non-gather frees |
| Node successor shared | **High** | Skip nodes / UAF |
| Callee free semantics | **Probable** | Double-free if mis-owned |
| Product English | **Inferred** | |

---

## 3. Cross-check against raw

```
if full_range(first,last,head):
  free_subtree(root); reset head; size=0; *out=begin; return
while first != last:
  next = successor(first)
  erase_node(first)   // FUN_0058dc30
  first = next
*out = first
```

Clean ≡ raw. Live decompile matches 2026-07-23 capture.

---

## 4. Surviving contract for AutoCore

```
MapFloatTfid_EraseRange(tree, &out, first, last):
  if [begin,end) == whole tree: clear O(n) free + size=0
  else erase each in [first,last)
Gather sort teardown: erase all then delete head node
Do NOT skip erase and only delete head (interior leak).
Do NOT use for TFID list free (different structure).
```

---

## 5. Open questions

1. Live gather always hits full-clear branch?
2. `FUN_0058da00` vs `FUN_0058dc30` ownership duals.
3. Iterator invalidation rules for AutoCore port (use `std::map` clear instead).

**Verdict:** **accept-with-gaps**
