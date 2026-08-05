# Review B (skeptical / adversarial): `aa_005fc710` Vehicle_BuildSteeringDescriptor

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fc710` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005fc710_Vehicle_BuildSteeringDescriptor.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Hardcoded 45° | Falsified — clonebase×entity |
| 2 | No per-wheel flags | Falsified — array fill |
| 3 | Transmission builder | Falsified — steering |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| maxSteer scales | High | Over/under steer |
| Per-wheel enable bits | High | Rear wheels steer wrongly |
| tankSteerCount split | High | Tank turn broken |

---

## 3. Cross-check against raw

```
fill wheelCount, maxSteerA/B, per-wheel steer bits.
Clean ≡ raw.
```

---

## 4. Surviving contract for AutoCore

```
BuildSteeringDescriptor(veh, …, out):
  pair Tank|Default steering ctor in framework
  AutoCore steer feel
```

---

## 5. Open questions

1. Sample chassis 0x594/598 values.
2. Confirm A/B axis meaning.

**Verdict:** **accept-with-gaps**
