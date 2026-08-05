# Review B (skeptical / adversarial): `aa_007e7530` Named_dcCreature_Insert_Open

| Field | Value |
|---|---|
| **Stable ID** | `aa_007e7530` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_007e7530_Named_dcCreature_Insert_Open.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | StepCreatures runtime | Falsified — DB open |
| 2 | DoCreaturePursue | Falsified — load time |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Creature columns | High | Wrong spawn stats |

---

## 3. Cross-check against raw

```
dcCreature_Insert_Open: creature template DB open.
```

---

## 4. Surviving contract for AutoCore

```
Creature defs for combat/spawn. Load with tCloneBase.
```

---

## 5. Open questions

1. Link to tCreatureExperienceLevel keys.

**Verdict:** **accept-with-gaps**
