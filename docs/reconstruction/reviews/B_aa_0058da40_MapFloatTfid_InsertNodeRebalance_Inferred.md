# Review B (skeptical / adversarial): `aa_0058da40` MapFloatTfid_InsertNodeRebalance_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0058da40` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0058da40_MapFloatTfid_InsertNodeRebalance_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Lower_bound only | Allocates node + rebalances | **Falsified find-only** |
| 2 | Array push_back | Tree node colors + rotates | **Falsified** |
| 3 | Many direct callers | Only `FUN_0058def0` | **Sole** |
| 4 | Color at +0x29 | Loop uses **+0x28**; isnil sibling uses +0x29 | **Distinct fields** |
| 5 | Skill filter logic | Pure tree structure | **Falsified skill logic** |

---

## 2. Surviving contract

```
InsertNodeRebalance(tree, &out, side, parent, key):
  throw if size too large
  node = construct; link; RB fixup; *out = node
```

**Verdict:** **accept-with-gaps**
