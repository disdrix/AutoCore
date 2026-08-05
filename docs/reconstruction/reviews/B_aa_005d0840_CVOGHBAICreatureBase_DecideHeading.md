# Review B (skeptical / adversarial): `aa_005d0840` CVOGHBAICreatureBase_DecideHeading

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d0840` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005d0840_CVOGHBAICreatureBase_DecideHeading.md` |
| **Verdict** | **accept-with-gaps** on CF; FPU constants open |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Instant snap heading | **Falsified — dt-limited rotation** |
| 2 | No validation | **Falsified — vtbl+0x214 / +0x6bc** |
| 3 | Finished exact FPU | **Overstated** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| dt turn limit | High | Spin or sluggish |
| Direction zero reuse | Tentative | Stale aim |
| vtbl+0x54 | High | No turn applied |

---

## 3. Cross-check against raw

```
if time since last < threshold: skip;
validate owner; dir delta;
if changed: matrix→acos heading; clamp by dt; vtbl+0x54.
Clean ≡ raw CF.
```

---

## 4. Surviving contract for AutoCore

```
DecideHeading(hbai, dt, dir):
  rate-limited turn toward desired direction
  shared foot/vehicle aim helper
  pair with pursue destination writes; do not double-apply conflicting headings
```

---

## 5. Open questions

1. Seal turn-rate constants from raw floats.
2. Call-graph: who passes pDirection.

**Verdict:** **accept-with-gaps** on CF; FPU constants open
