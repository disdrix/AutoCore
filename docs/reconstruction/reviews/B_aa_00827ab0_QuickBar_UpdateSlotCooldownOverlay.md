# Review B (skeptical / adversarial): `aa_00827ab0` QuickBar_UpdateSlotCooldownOverlay

| Field | Value |
|---|---|
| **Stable ID** | `aa_00827ab0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00827ab0_QuickBar_UpdateSlotCooldownOverlay.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Skill-only | Falsified — item type 2 path |
| 2 | Server authority CD | Falsified — client overlay |
| 3 | Ignores category CD | Falsified — GetCategoryCooldownRemaining |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Type branch +0x548 | High | Wrong overlay source |
| Item cargo lookup | High | Item CD never shows |
| Gauge field writes | Tentative | Visual glitch |

---

## 3. Cross-check against raw

```
if !gauge return; type2 item CD else type1 skill CD; paint overlay.
Clean ≡ raw.
```

---

## 4. Surviving contract for AutoCore

```
UpdateSlotCooldownOverlay(btn):
  client QB CD chrome; pair UpdateSkillSlotCooldownGauge + GetCategoryCooldownRemaining
  AutoCore: client UX only
```

---

## 5. Open questions

1. Name FUN_005710c0 inventory find.
2. Live-capture skill vs item overlay.

**Verdict:** **accept-with-gaps**
