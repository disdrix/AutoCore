# Review B (skeptical / adversarial): `aa_00537b50` CNDHash_AllocBuckets_009cf014

| Field | Value |
|---|---|
| **Stable ID** | `aa_00537b50` |
| **VA** | `0x00537b50` |
| **Canonical name** | `CNDHash_AllocBuckets_009cf014` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00537b50_CNDHash_AllocBuckets_009cf014.md` |
| **Live tools** | batch decompile + xrefs + Recreate twin |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Merge with `00537ab0` | Stamp `009cf014` ≠ `009cf00c` | **Falsified** |
| 2 | Size remains in `+0x08` | Store `N-1` | **Falsified** |
| 3 | No product use | Xrefs ctor + Recreate `00539dd0` | **Falsified** |

---

## 2. Surviving contract

```
AllocBuckets_009cf014 ≡ family CF; sentinel 009cf014.
Pairs with object vtbl 009cfa7c + Recreate 00539dd0.
```

**Verdict:** **accept-with-gaps.** Accept A.
