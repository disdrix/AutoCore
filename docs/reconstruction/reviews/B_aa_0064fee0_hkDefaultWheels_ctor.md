# Review B (skeptical / adversarial): `aa_0064fee0` hkDefaultWheels_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0064fee0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0064fee0_hkDefaultWheels_ctor.md` |
| **Verdict** | accept-with-gaps |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Per-tick wheel collide | Falsified — construction; collide is separate |
| 2 | Teardown of heap object | Falsified — stack desc teardown is FUN_0064fe40 after return |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Base does all init | High | Empty wheels object |
| Vtable identity | High | Wrong wheel methods |

---

## 3. Cross-check against raw

```
wheels.ctor: FUN_005fbbb0(desc); *this=DefaultWheelsVtbl; return this;
Clean ≡ raw CF (fresh batch_decompile 2026-07-29).
```

---

## 4. Surviving contract for AutoCore

```
Default wheels construction for framework (large 0x390 component).
```

---

## 5. Open questions

1. Wheel element stride dual in base helpers.

**Verdict:** accept-with-gaps
