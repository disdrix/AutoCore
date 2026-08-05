# Review B (skeptical / adversarial): `aa_0042b270` LinkedListHead_ClearNodes_00a9b1dc_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0042b270` |
| **VA** | `0x0042b270` |
| **Canonical name** | `LinkedListHead_ClearNodes_00a9b1dc_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0042b270_LinkedListHead_ClearNodes_00a9b1dc_Inferred.md` |
| **Live tools** | batch decompile; ctor twin |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | operator_delete each node | Loop only zeros | **Falsified** free |
| 2 | Next link at node+4 | Next is `node[2]` (+8) | **Falsified** |
| 3 | Leaves vtbl untouched | Stores `00a9b1dc` first | **Falsified** |
| 4 | Same as BitStream_BindFromBuffer dtor | No buffer/owns fields | **Falsified** merge |
| 5 | Nulls head after walk | Does not write `this+4` | **Attack fails** on A’s note |

---

## 2. Surviving contract

```
ClearNodes(this):
  this.vtbl = 00a9b1dc
  for n = this.head; n; n = n->next(+8):
    zero n[0], n[1], n[2]
  // head pointer not cleared; no free
```

**Verdict:** **accept-with-gaps.** Accept A.
