# Review B (skeptical / adversarial): `aa_00402ea0` CombatFloater_UninitializedFillN_0x38_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00402ea0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00402ea0_CombatFloater_UninitializedFillN_0x38_Inferred.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Relocates existing range | **Falsified** — calls ConstructN (template fill), not UninitializedCopy |
| 2 | Stride 0x18 / skill-set | **Falsified** — `* 0x38` return |
| 3 | Returns count | **Falsified** — returns pointer end |
| 4 | Grows capacity | **Falsified** — no new/delete |
| 5 | XP math | **Falsified** — POD placement only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ConstructN + end return | High | Wrong insert hole end |
| 0x38 stride | High | Misaligned floater buffer |
| Distinct from 004044c0 / 004044e0 | High | Merge wrong helpers |

---

## 3. Cross-check

```
raw: FUN_00404600(...); return param_2 + param_3 * 0x38;
live: identical.
Parent InsertN lists this as fill-n helper.
```

---

## 4. Surviving contract for AutoCore

```
CombatFloater_UninitializedFillN_0x38(dst, n, template) → end:
  ConstructN(dst, n, template)
  return dst + n*0x38
```

---

## 5. Open questions

None blocking for insert path.

**Verdict:** **accept**
