# Review B (skeptical / adversarial): `aa_005dae50` CVOGHBRecreateObject_OnHeartBeat

| Field | Value |
|---|---|
| **Stable ID** | `aa_005dae50` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005dae50_CVOGHBRecreateObject_OnHeartBeat.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Always immediate recreate | Falsified — random delay path |
| 2 | Net unpack ghost | Falsified — local HB recreate |
| 3 | Ignores physics body null | Falsified — early end |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Null body teardown | High | HB leak |
| Delay distribution | Medium | Respawn spam |

---

## 3. Cross-check against raw

```
OnHeartBeat: phys cast; recreate or reschedule with random delay.
Clean ≡ raw; residual delay table.
```

---

## 4. Surviving contract for AutoCore

```
Object recreate HB used after destroy-for-loot / world props.
```

---

## 5. Open questions

1. Find who attaches CVOGHBRecreateObject.

**Verdict:** **accept-with-gaps**
