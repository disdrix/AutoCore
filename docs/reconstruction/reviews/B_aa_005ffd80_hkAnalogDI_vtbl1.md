# Review B (skeptical / adversarial): `aa_005ffd80` hkAnalogDI_vtbl1

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ffd80` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005ffd80_hkAnalogDI_vtbl1.md` |
| **Verdict** | accept-with-gaps |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Always updates analog axes | Falsified — gated; may return 0 |
| 2 | No dependency on this+5 | Falsified — sole gate |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Gate polarity bit7 | High | Silent zero output |
| FUN_005ffc90 contract | Medium | Wrong DI math |

---

## 3. Cross-check against raw

```
if (*(byte*)(this+5)&0x80) return FUN_005ffc90(...); return 0;
Clean ≡ raw CF (fresh batch_decompile 2026-07-29).
```

---

## 4. Surviving contract for AutoCore

```
Conditional vtbl dispatch for analog DI; inactive when flag bit7 clear.
```

---

## 5. Open questions

1. Flag writers for this+5.
2. FUN_005ffc90 dual if needed.

**Verdict:** accept-with-gaps
