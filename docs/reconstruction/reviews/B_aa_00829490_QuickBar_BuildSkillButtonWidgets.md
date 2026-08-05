# Review B (skeptical / adversarial): `aa_00829490` QuickBar_BuildSkillButtonWidgets

| Field | Value |
|---|---|
| **Stable ID** | `aa_00829490` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00829490_QuickBar_BuildSkillButtonWidgets.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Updates gauge fill each frame | Falsified — build; Update* is sibling |
| 2 | Sends cast | Falsified |
| 3 | Finished all offsets | Overstated |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Child widget set | High | Broken QB chrome |
| CD gauge widget exists | High | No CD UI |
| Ptr map | Tentative | Wrong child |

---

## 3. Cross-check against raw

```
create bg/icon/name/value/keynum/cooldown/FX children; attach; store ptrs.
Clean ≡ raw outline.
```

---

## 4. Surviving contract for AutoCore

```
BuildSkillButtonWidgets(button):
  QB skill chrome; pair UpdateSkillSlotCooldownGauge
  AutoCore client quickbar
```

---

## 5. Open questions

1. Seal +0x560 child map.
2. Diff item vs skill button builders.

**Verdict:** **accept-with-gaps**
