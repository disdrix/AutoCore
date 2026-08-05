# Review B (skeptical / adversarial): `aa_00413ea0` CNDHash_ReleaseNodesToFreelist_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00413ea0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00413ea0_CNDHash_ReleaseNodesToFreelist_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Only unlinks without destroying values | **Falsified** — `vtbl(1)` on value |
| 2 | Frees node with `free()` | **Falsified** — freelist push to `hash+0x20` |
| 3 | Loop is `i < mask` only | **Falsified** — `i <= *(hash+8)` (mask inclusive) |
| 4 | Safe with null table | **Open / reject as sealed** — decompile assumes `+0x10` valid |

## Surviving contract

```text
// EBX = hash; table and mask valid
for i in 0..mask inclusive:
  node = bucket[i].head
  while node:
    next = node.bucket_next
    if node.value: node.value->vtbl.delete(1)
    freelist_push(hash, node)
    node = next
  bucket[i].head = 0
```

**Verdict:** **accept-with-gaps.** Accept A.
