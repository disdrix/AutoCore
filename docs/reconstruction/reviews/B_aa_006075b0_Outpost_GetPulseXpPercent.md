# Review B (skeptical / adversarial): `aa_006075b0` Outpost_GetPulseXpPercent

| Field | Value |
|---|---|
| **Stable ID** | `aa_006075b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_006075b0_Outpost_GetPulseXpPercent.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Single global table only | Falsified — two DAT_* tables |
| 2 | Returns integer percent 0-100 | Falsified — float fraction |
| 3 | Computes final XP amount | Falsified — percent only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Table select +0x220 | High | Wrong pulse rate class |
| Row +0x08 float | High | Wrong percent |
| Stride 0x10 | High | Misaligned rows |

---

## 3. Cross-check against raw

```
GetPulseXpPercent(outpost):
  table = (+0x220)? DAT_00d029e0 : DAT_00d029f0
  i = +0x23c; if in range return row[i].fPercent@+0x08 else 0
Clean ≡ raw.
```

---

## 4. Surviving contract for AutoCore

```
Percent input to pulse XP; AutoCore needs both tables.
```

---

## 5. Open questions

1. Export retail percent tables to fixtures.

**Verdict:** **accept-with-gaps**
