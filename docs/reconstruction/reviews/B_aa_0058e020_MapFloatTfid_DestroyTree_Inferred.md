# Review B (skeptical / adversarial): `aa_0058e020` MapFloatTfid_DestroyTree_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0058e020` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0058e020_MapFloatTfid_DestroyTree_Inferred.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | operator_delete alone | Always erase-range first | **Falsified bare free** |
| 2 | Frees every node via delete only | Erase helper frees nodes; then head | **Two-step** |
| 3 | No-return true | Decomp warning false for porting | **Ignore noreturn** |
| 4 | Gather-only | Shape is generic dtor helper | **Generic** |

---

## 2. Surviving contract

```
DestroyTree(map):
  EraseRange(begin, end=head)
  delete head
```

**Verdict:** **accept**
