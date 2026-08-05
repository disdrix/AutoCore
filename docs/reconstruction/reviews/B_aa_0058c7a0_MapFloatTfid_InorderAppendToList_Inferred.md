# Review B (skeptical / adversarial): `aa_0058c7a0` MapFloatTfid_InorderAppendToList_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0058c7a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0058c7a0_MapFloatTfid_InorderAppendToList_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Computes distances / sorts in place | Body only walks tree + memcpy payload; sort was insert order | **Falsified** |
| 2 | Validates / filters targets | No `FUN_0058a810` / mode checks | **Falsified** |
| 3 | Always used by gather | Only when `param_14 != 0` | **Falsified always-on** |
| 4 | Writes full node including float key | Copies only `node[6..9]` (payload), not key at `[4]` | **Falsified** |
| 5 | Pre-order / heap walk | Successor is classic inorder (right subtree min / parent climb) | **Falsified preorder** |
| 6 | Multiple skills callers | Sole xref GatherTargetsInArea | **Falsified** |
| 7 | Cap is maxTargets only | Hard stop at **99** independent of countdown | **Falsified single-cap** |
| 8 | Product `std::map` symbol sealed | Shape MSVC-like; name `_Inferred` | **Hold inferred** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Inorder payload dump CF | **High** | Wrong multi-target order |
| Stride 0x10 / cap 99 | **High** | Buffer overrun / short list |
| Sort-flag gated caller | **High** | Always sort or never sort port bug |
| Node +0x18 TFID payload | **High** | Corrupt TFID |
| Return-value exactness | **Probable** | Terminator index wrong if EAX not count |
| STL product identity | **Probable** | Doc naming only |

---

## 3. Cross-check against raw

```
node = leftmost(head)
while node != head:
  out[index] = node.payload_0x10
  index++
  if index==99 or countdown exhausted: return
  node = inorder_successor(node)
```

Clean ≡ raw. Parent: insert path `FUN_0058def0` then this dump; erase/free via `FUN_0058df60` + `operator_delete`.

---

## 4. Surviving contract for AutoCore

```
When gather sortByDistance:
  for each accepted target: map.insert(dist, tfid)   // FUN_0058def0
  MapFloatTfid_InorderAppendToList(out, tree, maxLeft, startCount)
  // yields nearest-first (or non-decreasing float key order)
Do NOT re-sort out-list with qsort; do NOT copy float keys into TFID slots.
```

---

## 5. Open questions

1. Confirm ascending key order with live multi-target skill.
2. EAX return on early exit at 99 vs countdown.
3. Shared tree type vs gather-only specialization.

**Verdict:** **accept-with-gaps**
