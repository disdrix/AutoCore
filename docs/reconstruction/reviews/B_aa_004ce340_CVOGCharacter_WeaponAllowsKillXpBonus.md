# Review B (skeptical / adversarial): `aa_004ce340` CVOGCharacter_WeaponAllowsKillXpBonus

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ce340` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_004ce340_CVOGCharacter_WeaponAllowsKillXpBonus.md` |
| **Verdict** | **accept** on CF; naming is documentation-only residual |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Looks up equipped weapon | **Falsified — no load from weapon tables** |
| 2 | Mode 2 enables bonus | **Falsified — mode 2 closes gate** |
| 3 | Always true for players | **Weak — depends on fields** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Field pair gate | High | Wrong kill-spree scale / mission hash |
| Name≠weapon scan | High | Wasted RE on wrong systems |
| Mode enum | Tentative | Mis-map special modes |

---

## 3. Cross-check against raw

```
if (this+0xa0)==0: false;  // LEA form
if byte(+0x100)!=0: false;
if int(+0xac)==2: false;
return true.
Clean matches raw.
```

---

## 4. Surviving contract for AutoCore

```
WeaponAllowsKillXpBonus(obj):
  true only when +0x100==0 and +0xac!=2
  does NOT inspect weapons
  kill-path AddExperience uses it for spree bonus table; mission code reuses as policy switch
Treat retail name as historical.
```

---

## 5. Open questions

1. Seal semantic names for +0x100 / +0xac.
2. Enumerate all call sites for dual use.

**Verdict:** **accept** on CF; naming is documentation-only residual
