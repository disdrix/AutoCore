# Review B (skeptical / adversarial): `aa_00531e90` CVOGCharacter_ApplyCharacterLevelPacket

| Field | Value |
|---|---|
| **Stable ID** | `aa_00531e90` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00531e90_CVOGCharacter_ApplyCharacterLevelPacket.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on skill-rank packing |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Delta currency/XP | **Falsified — absolute stores** |
| 2 | HP always applied | **Falsified — gated** |
| 3 | Mana gated like HP | **Falsified — mana always** |
| 4 | Partial packet safe | **Dangerous — absolute zeros unspecified fields** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Absolute level/currency/XP | High | Wipe economy/XP |
| HP gate | High | Wrong HUD HP |
| Mana always | High | Mana desync |
| Skill rank loop bounds | Tentative | Corrupt ranks |

---

## 3. Cross-check against raw

```
if level changed: vehicle hook + level-up UI
if HP gates: set max/cur on vehicle
store level, currency, xp, mana, points, ranks; FUN_00531330
Clean matches plate offsets.
```

---

## 4. Surviving contract for AutoCore

```
On CharacterLevel packet:
  apply ABSOLUTE level/currency/XP/points
  HP only when world/vehicle gates pass; mana always
  AutoCore BuildPacket must include Health for HUD
Never send sparse absolute packets that zero currency/XP.
```

---

## 5. Open questions

1. Seal skill-rank packet layout.
2. FUN_00531330 purpose.
3. Runtime capture.

**Verdict:** **accept-with-gaps** on CF; **needs-more-evidence** on skill-rank packing
