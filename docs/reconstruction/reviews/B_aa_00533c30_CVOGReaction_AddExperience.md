# Review B (skeptical / adversarial): `aa_00533c30` CVOGReaction_AddExperience

| Field | Value |
|---|---|
| **Stable ID** | `aa_00533c30` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00533c30_CVOGReaction_AddExperience.md` |
| **Verdict** | **accept-with-gaps** on CF; core contract High for AutoCore XP port |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Always levels on any XP | **Falsified — needs +0x7e and threshold cross** |
| 2 | Kill spree on GiveXP 0x205F | **Falsified — PacketOrNonKill** |
| 3 | Ignores personal XP gain | **Falsified — multiplies +0xc54** |
| 4 | Finished without LevelUp seal | **Overstated** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Personal scalar + soft cap | High | Wrong totals / overcap |
| KillPath spree/bonus | High | Wrong kill economy |
| +0x7e level loop gate | High | Remote entities wrongly level |
| scaled==0 early false | High | False success floater |

---

## 3. Cross-check against raw

```
if KillPath: spree 5s window; optional weapon table scale;
scaled = (int)(amount * personalGain);
max-level clamp unless specialMode;
if scaled==0: return false;
total += scaled;
if local +0x7e: level up/down loops (guard 300).
Clean ≡ raw kernel.
```

---

## 4. Surviving contract for AutoCore

```
AddExperience(char, amount, isKillPath):
  KillPath: spree counter + optional weapon bonus scale
  scaled = (int)(amount * flPersonalXpGain); soft-cap at max level
  if scaled==0 return false; else totalXp += scaled
  level-up/down only for local (+0x7e)
GiveXP/mission use isKillPath=0; kill formula uses 1.
Mirror cap + personal scalar in ExperienceService.GiveXp.
```

---

## 5. Open questions

1. Seal spree bonus table floats from image.
2. LevelUp argument bNotifyUi polarity per caller.
3. Interaction with CharacterLevel absolute snapshot.

**Verdict:** **accept-with-gaps** on CF; core contract High for AutoCore XP port
