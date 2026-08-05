# Review B (skeptical / adversarial): `aa_0064e510` hkDefaultSuspension_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0064e510` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0064e510_hkDefaultSuspension_ctor.md` |
| **Verdict** | accept-with-gaps |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Applies suspension forces | Falsified — ctor only; update 0x64de50 |
| 2 | Leaves arrays uninitialized | Falsified — empty then FUN_0064df10 fills |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Array layout +0x44/+0x50/+0x5c | High | Corrupt susp params |
| Base thiscall | High | Bad hardpoints |

---

## 3. Cross-check against raw

```
susp.ctor: base; vtbl; empty 3 arrays; FUN_0064df10(desc); return this;
Clean ≡ raw CF (fresh batch_decompile 2026-07-29).
```

---

## 4. Surviving contract for AutoCore

```
Default suspension construction for framework wire.
```

---

## 5. Open questions

1. FUN_0064df10 element semantics residual.

**Verdict:** accept-with-gaps
