# Review B (skeptical / adversarial): `aa_00537bf0` CNDHash_AllocBuckets_009cf01c

| Field | Value |
|---|---|
| **Stable ID** | `aa_00537bf0` |
| **VA** | `0x00537bf0` |
| **Canonical name** | `CNDHash_AllocBuckets_009cf01c` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00537bf0_CNDHash_AllocBuckets_009cf01c.md` |
| **Live tools** | batch decompile + xrefs + Recreate twin |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Merge with other Alloc twins | Unique stamp `009cf01c` | **Falsified** |
| 2 | bits=2 illegal | Range allows 1..16 | **Attack fails** |
| 3 | Orphan | Xrefs ctor + Recreate `00539e30` | **Falsified** |

---

## 2. Surviving contract

```
AllocBuckets_009cf01c ≡ family CF; sentinel 009cf01c.
Pairs with object vtbl 009cfa88 + Recreate 00539e30.
Tiny tables (N=4) still use same alloc path.
```

**Verdict:** **accept-with-gaps.** Accept A.
