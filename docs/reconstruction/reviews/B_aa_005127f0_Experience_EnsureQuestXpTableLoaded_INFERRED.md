# Review B (skeptical / adversarial): `aa_005127f0` Experience_EnsureQuestXpTableLoaded_INFERRED

| Field | Value |
|---|---|
| **Stable ID** | `aa_005127f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005127f0_Experience_EnsureQuestXpTableLoaded_INFERRED.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Loads kill creature XP | Falsified — quest lookup |
| 2 | Awards mission XP itself | Falsified — loader only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Quest map load pairing | High | Wrong mission XP fractions |
| Consumer field offsets | Medium | Bad award scale |

---

## 3. Cross-check against raw

```
EnsureQuestXpTableLoaded:
  FUN_007e1d80; Mission_tQuestXPLookup(&map); FUN_007b7df0; fail stop
Clean ≡ raw.
```

---

## 4. Surviving contract for AutoCore

```
Bring-up for mission objective XPIndex → rlLevelXP fractions.
```

---

## 5. Open questions

1. Map XPIndex consumers in mission complete path.

**Verdict:** **accept-with-gaps**
