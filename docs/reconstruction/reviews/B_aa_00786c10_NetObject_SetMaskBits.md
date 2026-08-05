# Review B (skeptical / adversarial): `aa_00786c10` NetObject_SetMaskBits

| Field | Value |
|---|---|
| **Stable ID** | `aa_00786c10` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00786c10_NetObject_SetMaskBits.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Replaces mask instead of OR | Falsified — `|=` |
| 2 | Single 32-bit only | Falsified — lo+hi |
| 3 | Always skips dirty list | Falsified — splices when was clean |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Mask OR semantics | High | Lost dirty bits |
| List splice | High | Missed pack |
| Arg order | Medium | Wrong hi/lo combat bit |

---

## 3. Cross-check against raw

```
SetMaskBits(obj, lo, hi):
  if (+0x18|+0x1c)==0 and head: splice; head=this;
  +0x18|=lo; +0x1c|=hi.
Clean ≡ raw.
```

---

## 4. Surviving contract for AutoCore

```
Canonical ghost dirty API for combat-pool and other masks.
  AutoCore NetObject must OR + dirty-list same way.
```

---

## 5. Open questions

1. Unit-test OR + list link; test HEAT 0x20000000 path with AddHeat.

**Verdict:** **accept-with-gaps**
