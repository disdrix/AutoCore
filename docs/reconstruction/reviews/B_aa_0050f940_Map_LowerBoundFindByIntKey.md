# Review B (skeptical / adversarial): `aa_0050f940` Map_LowerBoundFindByIntKey

| Field | Value |
|---|---|
| **Stable ID** | `aa_0050f940` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0050f940_Map_LowerBoundFindByIntKey.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Identical to StdMap_LowerBound +0x1d | Falsified — flag +0x15 |
| 2 | Hash map | Falsified — ordered tree walk |
| 3 | Mutates values | Falsified — find only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| +0x15 vs +0x1d mixup | High | Corrupt walk |
| Iterator out location | High | Miss always |

---

## 3. Cross-check against raw

```
LowerBoundFindByIntKey(map,key): RB walk flag+0x15; key@node[3]; it out.
Sibling layout of StdMap_LowerBound (+0x1d).
```

---

## 4. Surviving contract for AutoCore

```
Shared int-key map find for loot/XP tables. AutoCore must not
  conflate node layouts.
```

---

## 5. Open questions

1. Unit test lower_bound against known map dumps.

**Verdict:** **accept-with-gaps**
