# Review B (skeptical / adversarial): `aa_0065eb00` hkChassisComponent_method

| Field | Value |
|---|---|
| **Stable ID** | `aa_0065eb00` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0065eb00_hkChassisComponent_method.md` |
| **Verdict** | accept-with-gaps |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Fills CCS basis | Falsified — that is FUN_0065e6c0 |
| 2 | Returns instance | Falsified — static DAT |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Static type pointer | High | Wrong RTTI bind |
| Not lifecycle | High | Miswire dtor |

---

## 3. Cross-check against raw

```
return &DAT_00d039b4;
Clean ≡ raw CF (fresh batch_decompile 2026-07-29).
```

---

## 4. Surviving contract for AutoCore

```
hkChassisComponent class/type getter stub.
```

---

## 5. Open questions

1. Map DAT_00d039b4 reflection string.

**Verdict:** accept-with-gaps
