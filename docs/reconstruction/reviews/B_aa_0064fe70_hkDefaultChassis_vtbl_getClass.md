# Review B (skeptical / adversarial): `aa_0064fe70` hkDefaultChassis_vtbl_getClass

| Field | Value |
|---|---|
| **Stable ID** | `aa_0064fe70` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0064fe70_hkDefaultChassis_vtbl_getClass.md` |
| **Verdict** | accept-with-gaps |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Allocates chassis | Falsified — pointer return |
| 2 | Returns this pointer | Falsified — static DAT address |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Static type pointer | High | Wrong RTTI |
| Not lifecycle | High | Misuse as dtor |

---

## 3. Cross-check against raw

```
return &DAT_00d032ac;
Clean ≡ raw CF (fresh batch_decompile 2026-07-29).
```

---

## 4. Surviving contract for AutoCore

```
hkDefaultChassis class/type getter.
```

---

## 5. Open questions

1. Map DAT_00d032ac reflection string.

**Verdict:** accept-with-gaps
