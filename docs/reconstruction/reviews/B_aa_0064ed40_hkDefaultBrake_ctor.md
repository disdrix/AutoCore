# Review B (skeptical / adversarial): `aa_0064ed40` hkDefaultBrake_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0064ed40` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0064ed40_hkDefaultBrake_ctor.md` |
| **Verdict** | accept-with-gaps |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Computes brake torque each tick | Falsified — construction; update 0x64e6f0 |
| 2 | Wheel count from desc+4 | Falsified — *desc as signed char count |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Wheel-count grow | High | Wrong array size |
| Handbrake array byte elems | High | Corrupt flags |

---

## 3. Cross-check against raw

```
brake.ctor: base; vtbl; empty arrays; grow to *desc; FUN_0064e840; return;
Clean ≡ raw CF (fresh batch_decompile 2026-07-29).
```

---

## 4. Surviving contract for AutoCore

```
Default brake construction for framework build.
```

---

## 5. Open questions

1. Pair brake update dual present.

**Verdict:** accept-with-gaps
