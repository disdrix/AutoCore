# Review B (skeptical / adversarial): `aa_0064fdf0` hkDefaultChassis_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0064fdf0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0064fdf0_hkDefaultChassis_ctor.md` |
| **Verdict** | accept-with-gaps |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Binds rigid body pointer | Falsified — no RB store in unit |
| 2 | Per-tick chassis integrate | Falsified — construction only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Base CCS init required | High | Missing transform basis |
| Vtable identity | High | Wrong class methods |

---

## 3. Cross-check against raw

```
chassis.ctor: FUN_0065eac0(desc); *this=DefaultChassisVtbl; return this;
Clean ≡ raw CF (fresh batch_decompile 2026-07-29).
```

---

## 4. Surviving contract for AutoCore

```
Default chassis construction for framework (CCS basis + class vtbl).
```

---

## 5. Open questions

1. CCS basis field dual in base helpers.

**Verdict:** accept-with-gaps
