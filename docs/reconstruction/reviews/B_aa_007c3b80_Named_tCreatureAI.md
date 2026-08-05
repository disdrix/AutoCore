# Review B (skeptical / adversarial): `aa_007c3b80` Named_tCreatureAI

| Field | Value |
|---|---|
| **Stable ID** | `aa_007c3b80` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_007c3b80_Named_tCreatureAI.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Is DoCreaturePursue | Falsified — table load |
| 2 | Player input AI | Falsified — creature AI defs |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| AI row layout | High | Wrong NPC behavior |

---

## 3. Cross-check against raw

```
tCreatureAI: load creature AI definition table.
```

---

## 4. Surviving contract for AutoCore

```
Data for combat AI. Load before map creatures step.
```

---

## 5. Open questions

1. Sample AI row vs pursue distance +0x124.

**Verdict:** **accept-with-gaps**
