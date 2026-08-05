# Review B (skeptical / adversarial): `aa_005128b0` Experience_EnsureLevelTableLoaded_INFERRED

| Field | Value |
|---|---|
| **Stable ID** | `aa_005128b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005128b0_Experience_EnsureLevelTableLoaded_INFERRED.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Parses quest XP table | Falsified — tExperienceLevel only |
| 2 | Returns threshold values | Falsified — loader side-effect only |
| 3 | Is GetCumulativeThreshold | Falsified — distinct VA |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Loader ↔ map global pairing | High | Empty thresholds |
| Ready flag writer | Medium | Repeated reloads / never-ready |

---

## 3. Cross-check against raw

```
EnsureLevelTableLoaded:
  FUN_007e1d80; Mission_tExperienceLevel(&map); FUN_007b7df0; fail→VOG_DEBUG_STOP
Thin ensure; residual FUN names.
```

---

## 4. Surviving contract for AutoCore

```
Must run before cumulative threshold lookups in AutoCore table bring-up.
```

---

## 5. Open questions

1. Link ready-flag write site in loader callee.
2. Diff load error codes vs retail.

**Verdict:** **accept-with-gaps**
