# Review B (skeptical / adversarial): `aa_00507d10` CVOGHBList_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00507d10` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00507d10_CVOGHBList_ctor.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on optional global helper |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | No critical section | **Falsified — Init CS spin 4000** |
| 2 | Only one buffer | **Falsified — active + pending** |
| 3 | Zero-capacity forever | **Falsified — grow floors 1000/100** |
| 4 | Finished global helper semantics | **Overstated** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| CS + dual buffers | High | Race / enqueue fail |
| Grow floors | High | Immediate realloc thrash |
| g_dwClientTickMs seed | High | All HB elapsed wrong |
| DAT_00b041c8 branch | Tentative | Missing global service |

---

## 3. Cross-check against raw

```
*this=listVtbl; init active/pending flags; grow active≥1000 pending≥100;
tick=GetTickCount(); InitCS(spin4000); optional global helper; return.
Clean ≡ raw CF.
```

---

## 4. Surviving contract for AutoCore

```
HBList_ctor:
  map owns list; CS-protected Enqueue; Tick promotes pending→active
  seed client tick at construct
  active floor 1000 / pending floor 100 pointer slots
  pair with Enqueue + Tick duals already reviewed
```

---

## 5. Open questions

1. Name FUN_005b3300 / FUN_00507ee0.
2. Publish HBList layout offsets.
3. Confirm DAT_00b041c4 default in retail.

**Verdict:** **accept-with-gaps** on CF; **needs-more-evidence** on optional global helper
