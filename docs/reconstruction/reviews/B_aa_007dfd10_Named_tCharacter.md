# Review B (skeptical / adversarial): `aa_007dfd10` Named_tCharacter

| Field | Value |
|---|---|
| **Stable ID** | `aa_007dfd10` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_007dfd10_Named_tCharacter.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | CreateFromPacket runtime | Falsified — table load |
| 2 | Auth login | Falsified — game DB table |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Column map | High | Wrong char defs |

---

## 3. Cross-check against raw

```
tCharacter: DBReader character table.
```

---

## 4. Surviving contract for AutoCore

```
Character template load before create path.
```

---

## 5. Open questions

1. Ready-flag pairing with Ensure loaders if any.

**Verdict:** **accept-with-gaps**
