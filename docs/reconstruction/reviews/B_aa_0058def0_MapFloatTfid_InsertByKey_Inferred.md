# Review B (skeptical / adversarial): `aa_0058def0` MapFloatTfid_InsertByKey_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0058def0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0058def0_MapFloatTfid_InsertByKey_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Pure lower_bound (no insert) | Calls `FUN_0058da40` then writes out iterator | **Falsified find-only** |
| 2 | Sorts array / qsort | Tree walk + insert only | **Falsified** |
| 3 | Writes TFID out-list | Payload write is insert helper / later dump | **Falsified this unit** |
| 4 | Many callers | Sole GatherTargetsInArea | **Falsified** |
| 5 | Key is int / TFID | Compare uses `float` at `node[4]` vs `*param_3` | **Falsified** |
| 6 | Always inserts unique | Equal path residual inside `FUN_0058da40` (not sealed here) | **Open on multi equal keys** |
| 7 | Flag byte always means “inserted new” | Body hardcodes `1` after helper — may mean “iterator valid” | **Probable overclaim if “inserted”** |
| 8 | Product std::map::insert sealed | Shape only | **Hold `_Inferred`** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Float lower_bound walk | **High** | Wrong sort order |
| Delegates insert to 0058da40 | **High** | Miss rebalance/alloc |
| Sole gather sort caller | **High** | Miss other inserts |
| Out pair layout | **High** CF | Corrupt iterator consumer |
| Equal-key / flag English | **Probable** | Multi-target ties |
| Full tree rebalance | **out of unit** | Port must own 0058da40 later |

---

## 3. Cross-check against raw

```
node = root; parent = head
while !isnil(node):
  if node.key <= *key: go right else go left
  update hint bool
FUN_0058da40(...); out = { *ret, flag=1 }
```

Clean ≡ raw. Parent stages dist>0 then insert; dump via 0058c7a0.

---

## 4. Surviving contract for AutoCore

```
MapFloatTfid_InsertByKey(tree, &outIt, &distance):
  lower_bound walk on float keys
  insert via FUN_0058da40 (payload supplied by helper/parent framing)
  outIt marks position (flag byte set 1 in this unit)
Gather sort: insert each accepted target's distance → inorder dump later
Do NOT treat this as out-list append.
```

---

## 5. Open questions

1. `FUN_0058da40` payload source (stack TFID vs prior stores).
2. Equal-distance ordering.
3. Whether flag can be 0 on failed insert (body forces 1 — failure may throw/assert in helper).

**Verdict:** **accept-with-gaps**
