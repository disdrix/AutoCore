# Review B (skeptical / adversarial): `aa_004d80b0` CVOGCombat_CalculateAndAwardKillXP

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d80b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_004d80b0_CVOGCombat_CalculateAndAwardKillXP.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on live scalar / server authority |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Always awards non-zero kill XP on client | **Falsified when scalar BSS 0 — formula still multiplies by 0** |
| 2 | Spree uses raw spree byte without −1 | **Falsified — max(0, byte-1)** |
| 3 | Convoy blend when count==0 | **Falsified — only count>0** |
| 4 | Finished exact without LevelDiffBase | **Overstated** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Global scalar product | High | Wrong kill XP economy |
| Participation mult | High | Solo/share wrong |
| Spree 5% stacks | High | Spree over/under |
| Client scalar=0 implication | High | Server must own real award or patch scalar |

---

## 3. Cross-check against raw

```
if victim-player>3: victim=player+3;
base = LevelDiffBase(victim,player,grey);
if convoyCount>0: base = ceil blend 0.1;
raw = ceil(base * globalScalar * participation);
if raw<1: xp=0 else xp=raw+ceil(stacks*raw*0.05);
AddExperience(char,xp,KillPath);
if ok && local: floater type 3.
Clean ≡ raw; notes BSS scalar.
```

---

## 4. Surviving contract for AutoCore

```
CalculateAndAwardKillXP(playerLvl, victimLvl, participation, char, convoyCount):
  clamp victim to player+3; level-diff base; convoy blend if count>0
  raw = ceil(base * GLOBAL_KILL_SCALAR * participation)
  spree stacks from char+0x738 (byte-1); +5% each
  AddExperience KillPath; local type-3 floater
Retail client GLOBAL_KILL_SCALAR is 0 — do not assume client-side kill XP numbers without server or scalar patch.
Participation includes XPPercent × share × convoy product from caller.
```

---

## 5. Open questions

1. Confirm server kill XP path vs client scalar.
2. Seal LevelDiffBaseXp grey branches.
3. Floater local-ctx register binding.

**Verdict:** **accept-with-gaps** on CF; **needs-more-evidence** on live scalar / server authority
