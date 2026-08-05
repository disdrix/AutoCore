# Review B (skeptical / adversarial): `aa_00538120` CNDHash_ReleaseNodesToFreelist_Owning_009cefd4

| Field | Value |
|---|---|
| **Stable ID** | `aa_00538120` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W17-K) |
| **Counterpart** | `reviews/A_aa_00538120_CNDHash_ReleaseNodesToFreelist_Owning_009cefd4.md` |
| **Verdict** | **accept-with-gaps** |

---

## Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Non-owning reclaim (nodes only) | **Falsified** — `operator_delete` on `node+8` when non-null |
| 2 | Virtual deleting destroy `value->vtbl(1)` | **Falsified** — bare `operator_delete` (POD/value heap free); differs from `aa_00413ea0` twin |
| 3 | Loop is `i < mask` exclusive | **Falsified** — `jbe` vs `hash+8` → inclusive |
| 4 | Frees bucket table itself | **Falsified** — only clears heads; table free is parent `00539090` |
| 5 | Ghidra “does not return” means abort | **Falsified** — false positive; control resumes, freelist push runs |
| 6 | Safe if `hash+0x10` null | **Open / not sealed** — decompile assumes table valid (parent FreeBuckets gates table free, not this entry) |
| 7 | Node next is `+0x10` like other CNDHash twin | **Falsified for this family** — next is `node[3]` = `+0xc` (0x1c node / `009cefd4`) |

## Surviving contract

```text
// ECX = hash*; table and mask valid (caller FreeBuckets precondition)
for i in 0..*(hash+8) inclusive:
  node = table[i].head
  while node:
    next = node.bucket_next   // +0xc
    stamp vtbl 009cefd4
    if node.value: operator_delete(node.value)  // +8
    freelist_push(hash+0x20, node)
    node = next
  table[i].head = 0
```

## Notes vs sibling `aa_00413ea0`

| | `00538120` (this) | `00413ea0` |
|---|---|---|
| Value destroy | bare `operator_delete` | `vtbl(1)` deleting dtor |
| Next offset | `+0xc` | `+0x10` |
| Value offset | `+8` | `+0xc` |
| ABI this | ECX/EBX | EBX unaff (custom) |

**Verdict:** **accept-with-gaps.** Accept A. CF and ownership sealed High; product name + null-table precondition residual.
