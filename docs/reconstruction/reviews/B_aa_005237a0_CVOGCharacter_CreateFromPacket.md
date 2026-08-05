# Review B (skeptical / adversarial): `aa_005237a0` CVOGCharacter_CreateFromPacket

| Field | Value |
|---|---|
| **Stable ID** | `aa_005237a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005237a0_CVOGCharacter_CreateFromPacket.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on this layout |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Always runs post-create FX path | **Falsified — TFID/param_4 gates** |
| 2 | Always FUN_00521310 | **Falsified — flag skip** |
| 3 | this is plain CVOGCharacter* start | **Weak — negative offsets** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Gated post path | High | Miss FX/bind |
| FUN_005c9120 first | High | Wrong base init |
| this layout | Tentative | Wrong field stamps |

---

## 3. Cross-check against raw

```
FUN_005c9120(...);
if tfid valid && param_4:
  tick; resolve related; optional init/vcall; maybe FUN_00521310
Clean matches.
```

---

## 4. Surviving contract for AutoCore

```
On character CreateFromPacket method:
  base helper then conditional related-object bind / follow-up
  respect flag skip for FUN_00521310
Seal this-adjustment / subobject before offset ports.
```

---

## 5. Open questions

1. Type layout for negative offsets.
2. Callee dual reviews.

**Verdict:** **accept-with-gaps** on CF; **needs-more-evidence** on this layout
