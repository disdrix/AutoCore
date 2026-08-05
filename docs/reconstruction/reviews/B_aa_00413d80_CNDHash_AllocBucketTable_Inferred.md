# Review B (skeptical / adversarial): `aa_00413d80` CNDHash_AllocBucketTable_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00413d80` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00413d80_CNDHash_AllocBucketTable_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Leaves `hash+8` as bucket count | **Falsified** — explicit `--` to mask |
| 2 | log2 can be 0 | **Falsified** — `> 0` and `< 0x11` or throw |
| 3 | Nodes allocated here | **Falsified** — only empty 0xc sentinels; nodes from freelist on Insert |
| 4 | ECX thiscall | **Falsified** — ESI |

## Surviving contract

```text
// ESI=hash; *(+8)=power_of_two_count; *(+0x1c)=log2 in 1..16
alloc table[n], slab n*0x0C sentinels vtbl 00a64760
*(hash+8) = n - 1;  // mask
```

**Verdict:** **accept-with-gaps.** Accept A.
