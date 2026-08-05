# Review B (skeptical / adversarial): `aa_0064fc80` TankSteering_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0064fc80` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0064fc80_TankSteering_ctor.md` |
| **Verdict** | accept-with-gaps |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Reimplements descriptor fill | Falsified — parent does all fills |
| 2 | Different object size than default | Falsified — same 0x38 |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Vtable swap only delta | High | Missing tank update |
| Spec type-4 gate external | High | Wrong steer class |

---

## 3. Cross-check against raw

```
tank.ctor: hkDefaultSteering_ctor(desc); *this = TankVtbl; return this;
Clean ≡ raw CF (fresh batch_decompile 2026-07-29).
```

---

## 4. Surviving contract for AutoCore

```
Tank/tracked steering subclass construction over shared descriptor.
```

---

## 5. Open questions

1. Tank update dual if separate VA.

**Verdict:** accept-with-gaps
