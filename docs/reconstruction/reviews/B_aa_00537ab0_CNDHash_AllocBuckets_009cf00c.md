# Review B (skeptical / adversarial): `aa_00537ab0` CNDHash_AllocBuckets_009cf00c

| Field | Value |
|---|---|
| **Stable ID** | `aa_00537ab0` |
| **VA** | `0x00537ab0` |
| **Canonical name** | `CNDHash_AllocBuckets_009cf00c` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00537ab0_CNDHash_AllocBuckets_009cf00c.md` |
| **Live tools** | Independent force decompile + xrefs |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Identical to `00537a10` | Stamp `009cf00c` ≠ `009cf004` | **Falsified** merge |
| 2 | Size left in `+0x08` | Final `N-1` | **Falsified** |
| 3 | Orphan | Xref `00537113` in character ctor | **Falsified** |
| 4 | Must have Recreate twin like siblings | No Recreate CALL found | **Open** — not a CF defect |

---

## 2. Surviving contract

```
AllocBuckets_009cf00c ≡ family CF; sentinel stamp 009cf00c.
Pairs with inline object vtbl 009cfa70 at character construct.
```

**Verdict:** **accept-with-gaps.** Accept A.
