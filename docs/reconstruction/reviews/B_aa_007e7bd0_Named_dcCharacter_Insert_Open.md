# Review B (skeptical / adversarial): `aa_007e7bd0` Named_dcCharacter_Insert_Open

| Field | Value |
|---|---|
| **Stable ID** | `aa_007e7bd0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_007e7bd0_Named_dcCharacter_Insert_Open.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Net create unpack | Falsified — DB open |
| 2 | LevelUp runtime | Falsified — template load |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Column map | High | Wrong char templates |

---

## 3. Cross-check against raw

```
dcCharacter_Insert_Open: character template DB open.
```

---

## 4. Surviving contract for AutoCore

```
Character def import for load/create.
```

---

## 5. Open questions

1. Diff vs tCharacter loader 007dfd10.

**Verdict:** **accept-with-gaps**
