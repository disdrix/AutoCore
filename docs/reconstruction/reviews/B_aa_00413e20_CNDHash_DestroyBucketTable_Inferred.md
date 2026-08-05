# Review B (skeptical / adversarial): `aa_00413e20` CNDHash_DestroyBucketTable_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00413e20` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00413e20_CNDHash_DestroyBucketTable_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Also frees freelist arena | **Falsified** — nodes returned to freelist; freelist head kept |
| 2 | `free(table)` only | **Falsified** — free slab via `*table`, then `delete[]` table |
| 3 | `__thiscall` | **Falsified** — EAX hash |
| 4 | Zeros mask/log2 | **Falsified** — only count + table; Recreate rewrites size |

## Surviving contract

```text
// EAX = hash with valid +0x10 table (or child must tolerate null — not sealed)
*(hash+0xc) = 0;
CNDHash_ReleaseNodesToFreelist(hash);
if (table) { free(*table); delete[] table; table = 0; }
```

**Verdict:** **accept-with-gaps.** Accept A.
