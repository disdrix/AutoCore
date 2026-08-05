# Review B (skeptical / adversarial): `aa_0064de50` hkDefaultSuspension_update

| Field | Value |
|---|---|
| **Stable ID** | `aa_0064de50` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0064de50_hkDefaultSuspension_update.md` |
| **Verdict** | accept-with-gaps |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Performs anti-sink Y raise | Falsified — applyAction owns that |
| 2 | Writes steer angles | Falsified — force only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| +0xB0 length field | High | Wrong spring |
| Contact gate +0x80 | High | Airborne bounce |

---

## 3. Cross-check against raw

```
susp.update:
  for wheels: if contact, spring-damper force from +0xB0/+0xB4.
Clean ≡ raw.
```

---

## 4. Surviving contract for AutoCore

```
Suspension forces only; pair with applyAction anti-sink for penetration.
```

---

## 5. Open questions

1. Match BuildSuspensionDescriptor 0x68 layout.

**Verdict:** accept-with-gaps
