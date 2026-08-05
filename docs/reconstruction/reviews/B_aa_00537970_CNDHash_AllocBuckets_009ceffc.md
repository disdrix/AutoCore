# Review B (skeptical / adversarial): `aa_00537970` CNDHash_AllocBuckets_009ceffc

| Field | Value |
|---|---|
| **Stable ID** | `aa_00537970` |
| **VA** | `0x00537970` |
| **Canonical name** | `CNDHash_AllocBuckets_009ceffc` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00537970_CNDHash_AllocBuckets_009ceffc.md` |
| **Live tools** | batch decompile + twin compare |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Byte-identical to `005378d0` | Sentinel vtbl `009ceffc` vs `009ceff4` | **Falsified** |
| 2 | Different mask policy | Same `N-1` | **Attack fails** |
| 3 | Unused / dead | Called from ctor `0053b1b0` | **Falsified** |

---

## 2. Surviving contract

```
AllocBuckets_009ceffc ≡ AllocBuckets_009ceff4 except sentinel vtbl constant.
Wire only from Ctor_009cfa58 family.
```

**Verdict:** **accept-with-gaps.** Accept A.
